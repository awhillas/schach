# Functions to fetch remote modules.
include(gitModuleRemote)

file(GLOB remotes "*.remote.cmake")
foreach(remote_module ${remotes})
  include(${remote_module})
endforeach()
