idf_component_register(
  SRCS "loader.c" "unaligned.c"
  INCLUDE_DIRS "."
  REQUIRES esp_mm
)