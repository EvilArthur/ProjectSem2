cmake_minimum_required(VERSION 3.15) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произойдёт аварийный выход.

set(PROJECT_NAME Spaceship)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)


add_definitions(-DSFML_STATIC)		 # дефайны

include_directories("ext/SFML/include/")	# добавляем директории
include_directories("inc/")
link_directories("ext/SFML/lib/")	

add_executable("${PROJECT_NAME}" main.cpp
src/barrier.cpp
inc/barrier.h
src/logger.cpp
inc/logger.h
src/gameObject.cpp
inc/gameObject.h
src/Spaceship.cpp
inc/Spaceship.h
)

file(COPY "texture" DESTINATION "/")
											
target_link_libraries("${PROJECT_NAME}" sfml-graphics-s
						  sfml-window-s
						  sfml-system-s
						  opengl32
						  freetype
						  winmm
						  gdi32
						  sfml-audio-s
						  openal32
						  flac
						  vorbisenc
						  vorbisfile
						  vorbis
						  ogg)
