; ModuleID = 'calculator'
declare void @output(i32)

define i32 @main() {
label_entry:
  %op0 = add i32 10, 22
  %op1 = sub i32 %op0, 1
  call void @output(i32 %op1)
  ret i32 0
}
