cmake_minimum_required(VERSION 3.16)
project(NetDiskT_orderCli)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

set(SRCS sctpAdd/sctp_addr_to_associd.c sctpAdd/sctp_getnostrm.c sctpAdd/sctp_wrapper.c sctpAdd/error.hpp sctpAdd/error.c sctpAdd/sctpAdd.cpp m_fileprogressbar.cpp m_fileprogressbar.hpp m_fileprogressbar.ui ioLogicModule.cpp ioLogicModule.hpp m_msgqueue.cpp m_msgqueue.hpp m_Msg.hpp)
set(HEADER unp.h sctpAdd/error.hpp)

add_executable(${PROJECT_NAME} main.cpp mainwindow.cpp mainwindow.hpp mainwindow.ui sctpAdd/sctpAdd.hpp ${SRCS})

target_link_libraries(${PROJECT_NAME} /usr/local/lib/libsctp.a)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} -lpthread -lm)
