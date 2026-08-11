
[2026-08-11 09:51:52 TP0 EP0] Ignore import error when loading sglang.srt.models.sarashina2_vision: cannot import name 'MultimodalDataItem' from 'sglang.srt.managers.mm_utils' (/home/w00580100/z50065249/sglang/python/sglang/srt/managers/mm_utils.py)
[2026-08-11 09:51:52 TP1 EP1] Ignore import error when loading sglang.srt.models.sarashina2_vision: cannot import name 'MultimodalDataItem' from 'sglang.srt.managers.mm_utils' (/home/w00580100/z50065249/sglang/python/sglang/srt/managers/mm_utils.py)
[2026-08-11 09:51:52 TP3 EP3] Ignore import error when loading sglang.srt.models.sarashina2_vision: cannot import name 'MultimodalDataItem' from 'sglang.srt.managers.mm_utils' (/home/w00580100/z50065249/sglang/python/sglang/srt/managers/mm_utils.py)
[2026-08-11 09:51:52 TP2 EP2] Ignore import error when loading sglang.srt.models.sarashina2_vision: cannot import name 'MultimodalDataItem' from 'sglang.srt.managers.mm_utils' (/home/w00580100/z50065249/sglang/python/sglang/srt/managers/mm_utils.py)
[2026-08-11 09:51:53 TP0 EP0] Load weight begin. avail mem=60.49 GB
[2026-08-11 09:51:53 TP3 EP3] Load weight begin. avail mem=60.54 GB
[2026-08-11 09:51:53 TP1 EP1] Load weight begin. avail mem=60.54 GB
[2026-08-11 09:51:53 TP2 EP2] Load weight begin. avail mem=60.54 GB
[2026-08-11 09:51:53 TP3 EP3] Unsupported Linear modelslim scheme: [''] in layer: model.layers.0.self_attn.wqkv_a
[2026-08-11 09:51:53 TP3 EP3] Using ModelSlimW8A8Int8
[2026-08-11 09:51:53 TP0 EP0] Config does not support fused shared expert(s). Shared experts fusion optimization is disabled.
[2026-08-11 09:51:53 TP0 EP0] Unsupported Linear modelslim scheme: [''] in layer: model.layers.0.self_attn.wqkv_a
[2026-08-11 09:51:53 TP0 EP0] Using ModelSlimW8A8Int8
[2026-08-11 09:51:53 TP3 EP3] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 976, in init_model_worker
    self.init_tp_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 905, in init_tp_model_worker
    self.tp_worker = TpModelWorker(**worker_kwargs)
                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 336, in __init__
    self._init_model_runner()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 453, in _init_model_runner
    self._model_runner = ModelRunner(
                         ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 435, in __init__
    self.initialize()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 630, in initialize
    self.load_model()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1094, in load_model
    loaded = load_model_with_memory_saver(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner_components/load_model_utils.py", line 303, in load_model_with_memory_saver
    model = loader.load_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 820, in load_model
    model = _initialize_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 341, in _initialize_model
    return model_class(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2591, in __init__
    self.model = DeepseekV4Model(
                 ^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2258, in __init__
    self.layers, self.start_layer, self.end_layer = make_layers(
                                                    ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1464, in make_layers
    + get_offloader().wrap_modules(
      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/offloader.py", line 37, in wrap_modules
    return list(all_modules_generator)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1466, in <genexpr>
    layer_fn(idx=idx, prefix=add_prefix(idx, prefix))
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2260, in <lambda>
    lambda idx, prefix: DeepseekV4DecoderLayer(
                        ^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1463, in __init__
    self.self_attn = self._build_self_attn(
                     ^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1525, in _build_self_attn
    return MQALayer(
           ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 688, in __init__
    super().__init__(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 590, in __init__
    assert hasattr(
AssertionError: FP8 quant_config must create weight_scale_inv

[2026-08-11 09:51:53] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 09:51:53] kill_process_tree called: parent_pid=3184598, include_parent=True, pid=3184598
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/train/serialization.py:155: DeprecationWarning: getName() is deprecated, get the name attribute instead
  if thread.getName() == "asyn_save_ckpt":
[2026-08-11 09:51:53 TP0 EP0] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 976, in init_model_worker
    self.init_tp_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 905, in init_tp_model_worker
    self.tp_worker = TpModelWorker(**worker_kwargs)
                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 336, in __init__
    self._init_model_runner()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 453, in _init_model_runner
    self._model_runner = ModelRunner(
                         ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 435, in __init__
    self.initialize()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 630, in initialize
    self.load_model()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1094, in load_model
    loaded = load_model_with_memory_saver(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner_components/load_model_utils.py", line 303, in load_model_with_memory_saver
    model = loader.load_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 820, in load_model
    model = _initialize_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 341, in _initialize_model
    return model_class(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2591, in __init__
    self.model = DeepseekV4Model(
                 ^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2258, in __init__
    self.layers, self.start_layer, self.end_layer = make_layers(
                                                    ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1464, in make_layers
    + get_offloader().wrap_modules(
      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/offloader.py", line 37, in wrap_modules
    return list(all_modules_generator)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1466, in <genexpr>
    layer_fn(idx=idx, prefix=add_prefix(idx, prefix))
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2260, in <lambda>
    lambda idx, prefix: DeepseekV4DecoderLayer(
                        ^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1463, in __init__
    self.self_attn = self._build_self_attn(
                     ^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1525, in _build_self_attn
    return MQALayer(
           ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 688, in __init__
    super().__init__(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 590, in __init__
    assert hasattr(
AssertionError: FP8 quant_config must create weight_scale_inv

/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/train/serialization.py:155: DeprecationWarning: getName() is deprecated, get the name attribute instead
  if thread.getName() == "asyn_save_ckpt":
[2026-08-11 09:51:54] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 09:51:54] kill_process_tree called: parent_pid=3184598, include_parent=True, pid=3184598
[2026-08-11 09:51:54 TP1 EP1] Unsupported Linear modelslim scheme: [''] in layer: model.layers.0.self_attn.wqkv_a
[2026-08-11 09:51:54 TP1 EP1] Using ModelSlimW8A8Int8
[2026-08-11 09:51:54 TP1 EP1] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 976, in init_model_worker
    self.init_tp_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 905, in init_tp_model_worker
    self.tp_worker = TpModelWorker(**worker_kwargs)
                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 336, in __init__
    self._init_model_runner()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 453, in _init_model_runner
    self._model_runner = ModelRunner(
                         ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 435, in __init__
    self.initialize()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 630, in initialize
    self.load_model()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1094, in load_model
    loaded = load_model_with_memory_saver(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner_components/load_model_utils.py", line 303, in load_model_with_memory_saver
    model = loader.load_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 820, in load_model
    model = _initialize_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 341, in _initialize_model
    return model_class(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2591, in __init__
    self.model = DeepseekV4Model(
                 ^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2258, in __init__
    self.layers, self.start_layer, self.end_layer = make_layers(
                                                    ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1464, in make_layers
    + get_offloader().wrap_modules(
      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/offloader.py", line 37, in wrap_modules
    return list(all_modules_generator)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1466, in <genexpr>
    layer_fn(idx=idx, prefix=add_prefix(idx, prefix))
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2260, in <lambda>
    lambda idx, prefix: DeepseekV4DecoderLayer(
                        ^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1463, in __init__
    self.self_attn = self._build_self_attn(
                     ^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1525, in _build_self_attn
    return MQALayer(
           ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 688, in __init__
    super().__init__(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 590, in __init__
    assert hasattr(
AssertionError: FP8 quant_config must create weight_scale_inv

[2026-08-11 09:51:54] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 09:51:54] kill_process_tree called: parent_pid=3184598, include_parent=True, pid=3184598
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/train/serialization.py:155: DeprecationWarning: getName() is deprecated, get the name attribute instead
  if thread.getName() == "asyn_save_ckpt":
[2026-08-11 09:51:54 TP2 EP2] Unsupported Linear modelslim scheme: [''] in layer: model.layers.0.self_attn.wqkv_a
[2026-08-11 09:51:54 TP2 EP2] Using ModelSlimW8A8Int8
[2026-08-11 09:51:54 TP2 EP2] Scheduler hit an exception: Traceback (most recent call last):
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 4986, in run_scheduler_process
    scheduler = Scheduler(
                ^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 505, in __init__
    self.init_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 976, in init_model_worker
    self.init_tp_model_worker()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/scheduler.py", line 905, in init_tp_model_worker
    self.tp_worker = TpModelWorker(**worker_kwargs)
                     ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 336, in __init__
    self._init_model_runner()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/managers/tp_worker.py", line 453, in _init_model_runner
    self._model_runner = ModelRunner(
                         ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 435, in __init__
    self.initialize()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 630, in initialize
    self.load_model()
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner.py", line 1094, in load_model
    loaded = load_model_with_memory_saver(
             ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_executor/model_runner_components/load_model_utils.py", line 303, in load_model_with_memory_saver
    model = loader.load_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 820, in load_model
    model = _initialize_model(
            ^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/model_loader/loader.py", line 341, in _initialize_model
    return model_class(**kwargs)
           ^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2591, in __init__
    self.model = DeepseekV4Model(
                 ^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2258, in __init__
    self.layers, self.start_layer, self.end_layer = make_layers(
                                                    ^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1464, in make_layers
    + get_offloader().wrap_modules(
      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/offloader.py", line 37, in wrap_modules
    return list(all_modules_generator)
           ^^^^^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/utils/common.py", line 1466, in <genexpr>
    layer_fn(idx=idx, prefix=add_prefix(idx, prefix))
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 2260, in <lambda>
    lambda idx, prefix: DeepseekV4DecoderLayer(
                        ^^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1463, in __init__
    self.self_attn = self._build_self_attn(
                     ^^^^^^^^^^^^^^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 1525, in _build_self_attn
    return MQALayer(
           ^^^^^^^^^
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 688, in __init__
    super().__init__(
  File "/home/w00580100/z50065249/sglang/python/sglang/srt/models/deepseek_v4.py", line 590, in __init__
    assert hasattr(
AssertionError: FP8 quant_config must create weight_scale_inv

[2026-08-11 09:51:54] Received sigquit from a child process. It usually means the child failed.
[2026-08-11 09:51:54] kill_process_tree called: parent_pid=3184598, include_parent=True, pid=3184598
/home/w00580100/miniconda3/envs/zpc_py311/lib/python3.11/site-packages/mindspore/train/serialization.py:155: DeprecationWarning: getName() is deprecated, get the name attribute instead
  if thread.getName() == "asyn_save_ckpt":
Killed
