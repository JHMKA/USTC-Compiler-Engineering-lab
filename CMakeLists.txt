curl -s http://127.0.0.1:30000/server_info |
python - <<'PY'
import json
import sys

data = json.load(sys.stdin)

args = data.get("server_args", data)
print("speculative_algorithm:",
      args.get("speculative_algorithm"))
print("speculative_num_steps:",
      args.get("speculative_num_steps"))
print("speculative_num_draft_tokens:",
      args.get("speculative_num_draft_tokens"))

for index, state in enumerate(data.get("internal_states", [])):
    print(
        "rank", index,
        "avg_spec_accept_length =",
        state.get("avg_spec_accept_length"),
    )
PY
