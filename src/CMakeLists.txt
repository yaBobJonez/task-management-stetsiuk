qt_add_executable(TaskManager
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(TaskManager
    PRIVATE
        Qt::Core
        Qt::Widgets
)
