
(zpc_py311) w00580100@DevServer-BMS-57764ead:~/z50065249/sgl-kernel-npu$ pip install output/deep_ep*.whl

# Link to the deep_ep_cpp.*.so file
cd "$(pip show deep-ep | grep -E '^Location:' | awk '{print $2}')" && ln -s deep_ep/deep_ep_cpp*.so && cd -

# (Optional) Confirm whether the import can be successful
python -c "import deep_ep; print(deep_ep.__path__)"
WARNING: Requirement 'output/deep_ep*.whl' looks like a filename, but the file does not exist
ERROR: Invalid wheel filename (wrong number of parts): 'deep_ep*'
WARNING: Package(s) not found: deep-ep
ln: failed to create symbolic link './deep_ep_cpp*.so': File exists
Traceback (most recent call last):
  File "<string>", line 1, in <module>
ModuleNotFoundError: No module named 'deep_ep'
