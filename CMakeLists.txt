curl -fsS http://127.0.0.1:30000/server_info |
python -m json.tool |
grep -i -E \
'speculative_algorithm|speculative_num_steps|speculative_num_draft_tokens|avg_spec_accept_length'
