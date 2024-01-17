add_library(${PROJECT_NAME} STATIC)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(${PROJECT_NAME}
	#PRIVATE ${PROJECT_SOURCES}
	PRIVATE Panel.cpp
	#PRIVATE AnalogBar.cpp
	#PRIVATE Button.cpp
	#PRIVATE ComboBox.cpp
	#PRIVATE Divider.cpp
	#PRIVATE Frame.cpp
	PRIVATE Image.cpp
	#PRIVATE Label.cpp
	PRIVATE Menu.cpp
	#PRIVATE MenuItem.cpp
	#PRIVATE MessageBox.cpp
	PRIVATE ProgressBar.cpp
	#PRIVATE ProgressBox.cpp
	#PRIVATE RadioButton.cpp
	PRIVATE RichText.cpp
	PRIVATE ScrollBar.cpp
	#PRIVATE Slider.cpp
	PRIVATE Splitter.cpp
	#PRIVATE TextImage.cpp
	#PRIVATE ToggleButton.cpp
)