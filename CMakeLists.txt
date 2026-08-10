
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ curl -fsS http://127.0.0.1:30000/server_info |
python -m json.tool |
grep -i -E \
'speculative_algorithm|speculative_num_steps|speculative_num_draft_tokens|avg_spec_accept_length'
    "speculative_algorithm": "EAGLE",
    "speculative_num_steps": 2,
    "speculative_num_draft_tokens": 3,
            "speculative_algorithm": "EAGLE",
            "speculative_num_steps": 2,
            "speculative_num_draft_tokens": 3,
            "max_speculative_num_draft_tokens": 3,
            "avg_spec_accept_length": 1.001219512195122
