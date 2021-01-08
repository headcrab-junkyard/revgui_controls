cmake_minimum_required(VERSION 3.14)
project(revgui_controls)

#####################################################################

# Set path to the engine SDK
set(OGS_SDK_PATH ${CMAKE_SOURCE_DIR}/../ogs-sdk/goldsrc
	CACHE PATH
	"Path to the engine SDK"
)

# Set path to VGUI2 library headers
set(VGUI2_HEADERS_PATH ${CMAKE_SOURCE_DIR}/../vgui2-reimp/public
	CACHE PATH
	"Path to VGUI2 library headers"
)

#####################################################################

include_directories(
	${CMAKE_SOURCE_DIR}/include/vgui/controls
	${OGS_SDK_PATH}
	${OGS_SDK_PATH}/public
	${VGUI2_HEADERS_PATH}
)

add_subdirectory(src)