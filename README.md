(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$ curl http://127.0.0.1:30000/generate \
  -H "Content-Type: application/json" \
  -d '{
    "text": "What is the capital of France?",
    "sampling_params": {"temperature": 0, "max_new_tokens": 128}
  }'
{"text":"kop&_n? (****  /*## 下面 -  部门: 2023 05 - 16 calendar (## 部门: 国家: 全部 部门: 2023年06 - 08 T 国家: 1. 1.2 1:2 2.1 领域: 1. 1.1 领域 领域: 1. 领域 1. 1.1 领域 1. 领域 1. 1.1 领域## 领域 领域 领域 领域 领域 1. 1.1","output_ids":[81641,8,65,80,33,343,666,666,223,15420,372,223,10352,565,223,223,4898,28,223,939,21,223,2642,565,223,926,21730,343,372,223,4898,28,223,3030,28,223,7422,223,4898,28,223,939,21,695,3398,565,223,3019,330,223,3030,28,223,19,16,223,19,16,20,223,19,28,20,223,20,16,19,223,7573,28,223,19,16,223,19,16,19,223,7573,223,7573,28,223,19,16,223,7573,223,19,16,223,19,16,19,223,7573,223,19,16,223,7573,223,19,16,223,19,16,19,223,7573,372,223,7573,223,7573,223,7573,223,7573,223,7573,223,19,16,223,19,16,19],"meta_info":{"id":"af9d727d503145b2b671586d6f3934a2","finish_reason":{"type":"length","length":128},"prompt_tokens":7,"weight_version":"default","num_retractions":0,"reasoning_tokens":0,"completion_tokens":128,"cached_tokens":0,"cached_tokens_details":null,"dp_rank":null,"e2e_latency":4.2531652161851525,"response_sent_to_client_ts":1786095515.4503434}}(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sglang$
