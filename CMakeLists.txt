
[2026-08-17 11:03:07 DP0 TP0 EP0] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 981, in init_model_worker
    self.init_memory_pools()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 952, in init_memory_pools
    self.init_target_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 948, in init_target_memory_pool
    self.tp_worker.alloc_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 402, in alloc_memory_pool
    self.model_runner.alloc_memory_pool(memory_pool_config)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 808, in alloc_memory_pool
    result = self.kv_cache_configurator.configure(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 255, in configure
    pools = self._init_pools(
            ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 424, in _init_pools
    token_to_kv_pool = self._build_token_to_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 871, in _build_token_to_kv_pool
    token_to_kv_pool = self._build_dsv4_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 1020, in _build_dsv4_kv_pool
    token_to_kv_pool = pool_cls(
                       ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/deepseek_v4_memory_pool.py", line 622, in __init__
    self.c4_kv_pool = self._make_kv_pool(
                      ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/hardware_backend/npu/dsv4/dsv4_memory_pool.py", line 300, in _make_kv_pool
    assert cls is DeepSeekV4SingleKVPool, (
AssertionError: enable_hisparse is not supported on the NPU DSV4 KV pool (got c4 pool class HiSparseC4DevicePool).

[2026-08-17 11:03:07 DP1 TP1 EP1] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 981, in init_model_worker
    self.init_memory_pools()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 952, in init_memory_pools
    self.init_target_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 948, in init_target_memory_pool
    self.tp_worker.alloc_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 402, in alloc_memory_pool
    self.model_runner.alloc_memory_pool(memory_pool_config)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 808, in alloc_memory_pool
    result = self.kv_cache_configurator.configure(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 255, in configure
    pools = self._init_pools(
            ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 424, in _init_pools
    token_to_kv_pool = self._build_token_to_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 871, in _build_token_to_kv_pool
    token_to_kv_pool = self._build_dsv4_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 1020, in _build_dsv4_kv_pool
    token_to_kv_pool = pool_cls(
                       ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/deepseek_v4_memory_pool.py", line 622, in __init__
    self.c4_kv_pool = self._make_kv_pool(
                      ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/hardware_backend/npu/dsv4/dsv4_memory_pool.py", line 300, in _make_kv_pool
    assert cls is DeepSeekV4SingleKVPool, (
AssertionError: enable_hisparse is not supported on the NPU DSV4 KV pool (got c4 pool class HiSparseC4DevicePool).

[2026-08-17 11:03:07 DP3 TP3 EP3] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 981, in init_model_worker
    self.init_memory_pools()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 952, in init_memory_pools
    self.init_target_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 948, in init_target_memory_pool
    self.tp_worker.alloc_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 402, in alloc_memory_pool
    self.model_runner.alloc_memory_pool(memory_pool_config)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 808, in alloc_memory_pool
    result = self.kv_cache_configurator.configure(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 255, in configure
    pools = self._init_pools(
            ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 424, in _init_pools
    token_to_kv_pool = self._build_token_to_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 871, in _build_token_to_kv_pool
    token_to_kv_pool = self._build_dsv4_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 1020, in _build_dsv4_kv_pool
    token_to_kv_pool = pool_cls(
                       ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/deepseek_v4_memory_pool.py", line 622, in __init__
    self.c4_kv_pool = self._make_kv_pool(
                      ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/hardware_backend/npu/dsv4/dsv4_memory_pool.py", line 300, in _make_kv_pool
    assert cls is DeepSeekV4SingleKVPool, (
AssertionError: enable_hisparse is not supported on the NPU DSV4 KV pool (got c4 pool class HiSparseC4DevicePool).

[2026-08-17 11:03:07 DP2 TP2 EP2] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 981, in init_model_worker
    self.init_memory_pools()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 952, in init_memory_pools
    self.init_target_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 948, in init_target_memory_pool
    self.tp_worker.alloc_memory_pool()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 402, in alloc_memory_pool
    self.model_runner.alloc_memory_pool(memory_pool_config)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 808, in alloc_memory_pool
    result = self.kv_cache_configurator.configure(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 255, in configure
    pools = self._init_pools(
            ^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 424, in _init_pools
    token_to_kv_pool = self._build_token_to_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 871, in _build_token_to_kv_pool
    token_to_kv_pool = self._build_dsv4_kv_pool(
                       ^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/kv_cache_configurator.py", line 1020, in _build_dsv4_kv_pool
    token_to_kv_pool = pool_cls(
                       ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/mem_cache/deepseek_v4_memory_pool.py", line 622, in __init__
    self.c4_kv_pool = self._make_kv_pool(
                      ^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/hardware_backend/npu/dsv4/dsv4_memory_pool.py", line 300, in _make_kv_pool
    assert cls is DeepSeekV4SingleKVPool, (
AssertionError: enable_hisparse is not supported on the NPU DSV4 KV pool (got c4 pool class HiSparseC4DevicePool).

[2026-08-17 11:03:08] kill_process_tree called: parent_pid=2293894, include_parent=False, pid=2293894
Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/entrypoints/engine.py", line 1757, in _wait_for_scheduler_ready
    data = scheduler_pipe_readers[i].recv()
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/multiprocessing/connection.py", line 249, in recv
    buf = self._recv_bytes()
          ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/multiprocessing/connection.py", line 413, in _recv_bytes
    buf = self._recv(4)
          ^^^^^^^^^^^^^
  File "/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/multiprocessing/connection.py", line 382, in _recv
    raise EOFError
EOFError

During handling of the above exception, another exception occurred:

Traceback (most recent call last):
  File "<frozen runpy>", line 198, in _run_module_as_main
  File "<frozen runpy>", line 88, in _run_code
  File "/home/w00580100/z50065249/sglang/python/sglang/launch_server.py", line 71, in <module>
    run_server(server_args)
  File "/home/w00580100/z50065249/sglang/python/sglang/launch_server.py", line 52, in run_server
    launch_server(server_args)
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/entrypoints/http_server.py", line 2748, in launch_server
    ) = Engine._launch_subprocesses(
        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/entrypoints/engine.py", line 1197, in _launch_subprocesses
    scheduler_init_result.wait_for_ready()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/entrypoints/engine.py", line 924, in wait_for_ready
    infos = _wait_for_scheduler_ready(scheduler_pipe_readers, scheduler_procs)
            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/entrypoints/engine.py", line 1759, in _wait_for_scheduler_ready
    raise _scheduler_died_error(i, scheduler_procs[i])
RuntimeError: Rank 0 scheduler died during initialization (exit code: -3). If exit code is -9 (SIGKILL), a common cause is the OS OOM killer. Run `dmesg -T | grep -i oom` to check.
[ERROR] 2026-08-17-11:03:09 (PID:2293894, Device:-1, RankID:-1) ERR99999 UNKNOWN applicaiton exception

