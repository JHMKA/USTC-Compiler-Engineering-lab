#include "DeadCode.hpp"
#include "Instruction.hpp"
#include "logging.hpp"
#include "BasicBlock.hpp"
#include <memory>
#include <unordered_set>
#include <stdexcept>
#include <vector>


// 处理流程：两趟处理，mark 标记有用变量，sweep 删除无用指令
void DeadCode::run() {
    bool changed{};
    func_info->run();
    do {
        changed = false;
        for (auto &F : m_->get_functions()) {
                auto func = &F;
                changed |= clear_basic_blocks(func);
                marked.clear();
                mark(func);
                changed |= sweep(func);
        }
        sweep_globally();
    } while (changed);
    LOG_INFO << "dead code pass erased " << ins_count << " instructions";
}

bool DeadCode::clear_basic_blocks(Function *func) {
    bool changed = 0;
    std::vector<BasicBlock *> to_erase;
    for (auto &bb1 : func->get_basic_blocks()) {
        auto bb = &bb1;
        if(bb->get_pre_basic_blocks().empty() && bb != func->get_entry_block()) {
            to_erase.push_back(bb);
            changed = 1;
        }
    }
    for (auto &bb : to_erase) {
        for (auto succ_bb : bb->get_succ_basic_blocks()) {
            succ_bb->remove_pre_basic_block(bb);
        }
        bb->erase_from_parent();
        delete bb;
    }
    return changed;
}

void DeadCode::mark(Function *func) {
    for (auto &bb : func->get_basic_blocks())
     {
        for (auto &instr : bb.get_instructions()) 
        {
            Instruction *ins = &instr;
            if (is_critical(ins)) 
            {
                mark(ins);
            }
        }
    }
}

void DeadCode::mark(Instruction *ins) {
    if (marked.find(ins) != marked.end()) {
        return;
    }
    marked[ins] = true;
    for (auto operand : ins->get_operands()) {
        if (!operand) continue;
        if (auto def_ins = dynamic_cast<Instruction *>(operand)) {
            mark(def_ins);
        }
    }
}


bool DeadCode::sweep(Function *func) {
    bool changed = false;
    // 1. 收集所有未被标记的指令
    for (auto &bb : func->get_basic_blocks()) {
        std::vector<Instruction *> wait_del;

        for (auto &instr : bb.get_instructions()) {
            Instruction *ins = &instr;
            if (marked.find(ins) == marked.end() || !marked[ins]) {
                wait_del.push_back(ins);
            }
        }
        for (auto ins : wait_del) {
            changed = true;
            auto users = ins->get_use_list();
            for (auto &use : users) {
                User *user = use.val_;
                if (auto user_ins = dynamic_cast<Instruction *>(user)) {
                    user_ins->remove_operand(use.arg_no_);
                }
            }
            ins->remove_all_operands();
            bb.remove_instr(ins);
            ins_count++;
            delete ins;
        }
    }
    
    return changed;
}


bool DeadCode::is_critical(Instruction *ins) {
    // TODO: 判断指令是否是无用指令
    if (!ins->get_use_list().empty()) {
        return true;
    }

    if (ins->is_call()) {
        auto call_inst = static_cast<CallInst *>(ins);
        auto callee = call_inst->func_;
        bool is_pure = false;
        try {
            is_pure = func_info->is_pure_function(callee);
        } catch (const std::out_of_range &) {
            is_pure = false;
        }
        return !is_pure;
    }

    if (ins->is_br() || ins->is_ret() || ins->is_store()) {
        return true;
    }

    return false;
}

void DeadCode::sweep_globally() {
    std::vector<Function *> unused_funcs;
    std::vector<GlobalVariable *> unused_globals;
    for (auto &f_r : m_->get_functions()) {
        if (f_r.get_use_list().size() == 0 and f_r.get_name() != "main")
            unused_funcs.push_back(&f_r);
    }
    for (auto &glob_var_r : m_->get_global_variable()) {
        if (glob_var_r.get_use_list().size() == 0)
            unused_globals.push_back(&glob_var_r);
    }
    // changed |= unused_funcs.size() or unused_globals.size();
    for (auto func : unused_funcs)
        m_->get_functions().erase(func);
    for (auto glob : unused_globals)
        m_->get_global_variable().erase(glob);
}
