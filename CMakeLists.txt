(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ curl -s http://127.0.0.1:30000/server_info |             curl -s http://127.0.0.1:30000/server_info |
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
Traceback (most recent call last):
  File "<stdin>", line 4, in <module>
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/json/__init__.py", line 293, in load
    return loads(fp.read(),
           ^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/json/__init__.py", line 346, in loads
    return _default_decoder.decode(s)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/json/decoder.py", line 337, in decode
    obj, end = self.raw_decode(s, idx=_w(s, 0).end())
               ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/json/decoder.py", line 355, in raw_decode
    raise JSONDecodeError("Expecting value", s, err.value) from None
json.decoder.JSONDecodeError: Expecting value: line 1 column 1 (char 0)
