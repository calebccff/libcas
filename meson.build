project('cas', 'c', 'cpp', version: '0.0.1')
cc = meson.get_compiler('c')
fs = import('fs')

cas_include = [
  'cas',
]

cas_headers = [
  'cas/cutils.h',
  'cas/bytearray.h',
  'cas/log.h',
  'cas/timespec.h',
  'cas/misc.h',
]

cas_src = [
  'cutils.c',
  'timespec.c',
  'log.c',
  'bytearray.c',
]

cas_shared = shared_library('cas', cas_src,
  sources: cas_src,
  include_directories: cas_include,
  install: true,
)

cas_static = static_library('cas', cas_src,
  sources: cas_src,
  include_directories: cas_include,
  install: true,
)

install_headers(cas_headers, subdir: 'cas')

# cas_shared_dep = declare_dependency(
#   include_directories: cas_include,
#   link_with: cas_shared,
# )

libcas_dep = declare_dependency(
  include_directories: cas_include,
  link_with: cas_static,
)

