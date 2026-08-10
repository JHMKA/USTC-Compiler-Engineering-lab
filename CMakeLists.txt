(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ cd /home/w00580100/z50065249/sglang
sed -n \
sed -n \_draft_extend_for_decode/,/select_index/p' \
  '/def _draft_extend_for_decode/,/select_index/p' \
  python/sglang/srt/speculative/eagle_worker_v2.py |
head -n 50
MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8
MODEL=/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8
python - <<'PY'
python - <<'PY'
import jsonb import Path
from pathlib import Path
model = Path("/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8")
model = Path("/home/w00580100/model/DeepSeek-V4-Flash-0731-w4a8")
config = json.loads((model / "config.json").read_text())
config = json.loads((model / "config.json").read_text())
index = json.loads(_model_weights.safetensors.index.json").read_text()
    (model / "quant_model_weights.safetensors.index.json").read_text()
)
weight_map = index.get("weight_map", {})
weight_map = index.get("weight_map", {})
keys = list(weight_map)
patterns = (
patterns = (ayers.43",
    "model.layers.43",
    "mtp",",
    "nextn",head",
    "shared_head",
    "e_proj",
    "h_proj",
    "enorm",
    "hnorm",
)
print("num_hidden_layers:",
print("num_hidden_layers:",n_layers"))
      config.get("num_hidden_layers"))
print("num_nextn_predict_layers:",t_layers"))
      config.get("num_nextn_predict_layers"))
print("total indexed weights:", len(keys))
matched = [
matched = [ key in keys
    key for key in keysey.lower() for pattern in patterns)
    if any(pattern in key.lower() for pattern in patterns)
]
print("MTP/NextN matched weights:", len(matched))
print("MTP/NextN matched weights:", len(matched))
for key in matched[:100]:ht_map[key])
    print(key, "->", weight_map[key])
PY
export FORCE_DRAFT_MODEL_NON_QUANT=1
export FORCE_DRAFT_MODEL_NON_QUANT=1
python - <<'PY'
python - <<'PY'
import os
print(ORCE_DRAFT_MODEL_NON_QUANT =",
    "FORCE_DRAFT_MODEL_NON_QUANT =",L_NON_QUANT")
    os.environ.get("FORCE_DRAFT_MODEL_NON_QUANT")
)Y
PY
    def _draft_extend_for_decode(
        self, batch: ScheduleBatch, batch_result: GenerationBatchResult
    ):
        # Batch 2: Draft extend
        draft_extend_input = EagleDraftExtendInput(
            hidden_states=batch_result.logits_output.hidden_states,
            # accept_lens includes the bonus token; correct drafts exclude it.
            num_correct_drafts=batch_result.accept_lens - 1,
            num_accept_tokens=batch_result.accept_lens,
            # Draft-extend fills the whole tree width (num_draft_tokens) per req,
            # not num_steps + 1, so DP MLP-sync padding stays consistent for topk > 1.
            num_tokens_per_req=self.speculative_num_draft_tokens,
            num_tokens_for_logprob_per_req=self.speculative_num_draft_tokens,
        )
        select_index = (
num_hidden_layers: 43
num_nextn_predict_layers: 1
total indexed weights: 143179
MTP/NextN matched weights: 9326
mtp.0.attn.attn_sink -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.kv_norm.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.q_norm.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wkv.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wkv.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wkv.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wo_a.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wo_b.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_a.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_a.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_a.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_b.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_b.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn.wq_b.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.attn_norm.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.embed.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.0.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.1.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.10.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.100.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.101.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.102.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w1.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w1.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w1.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w1.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w2.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w2.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w2.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w2.weight_scale -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w3.scale_bias -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w3.weight -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w3.weight_offset -> quant_model_weights-00038-of-00038.safetensors
mtp.0.ffn.experts.103.w3.weight_scale -> quant_model_weights-00038-of-00038.safetensors
FORCE_DRAFT_MODEL_NON_QUANT = 1
