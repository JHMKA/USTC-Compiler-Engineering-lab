curl -s http://127.0.0.1:30000/server_info \
  | python -m json.tool \
  | grep -i -E 'speculative|eagle|draft|accept'
