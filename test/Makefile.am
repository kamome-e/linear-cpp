TESTS = \
	log_file_test.sh \
	log_stderr_test.sh \
	log_function_test.sh \
	log_test.sh \
	log_onoff_test.sh

CXXFLAGS = -g -O0 -Wno-deprecated-declarations

if LINEAR_LOG_DEBUG
CXXFLAGS += -D_LINEAR_LOG_DEBUG_
TESTS += \
	log_macro4file_debug_test.sh \
	log_macro4stderr_debug_test.sh \
	log_macro4function_debug_test.sh
else
TESTS += \
	log_macro4file_nodebug_test.sh \
	log_macro4stderr_nodebug_test.sh \
	log_macro4function_nodebug_test.sh
endif

TESTS += any_test optional_test
TESTS += run_tests

AM_CPPFLAGS = \
	-I$(top_srcdir)/deps/gmock-1.7.0/include \
	-I$(top_srcdir)/deps/gmock-1.7.0/gtest/include \
	-I$(top_srcdir)/deps/msgpack/include \
	-I$(top_srcdir)/include \
	-I$(top_srcdir)/src

LDADD = \
	$(top_srcdir)/src/.libs/liblinear.a \
	$(top_srcdir)/deps/libtv/src/.libs/libtv.a \
	$(top_srcdir)/deps/libtv/deps/libuv/.libs/libuv.a \
	$(top_srcdir)/deps/gmock-1.7.0/gtest/lib/.libs/libgtest.a \
	$(top_srcdir)/deps/gmock-1.7.0/lib/.libs/libgmock.a

check_PROGRAMS = \
	log_file_test \
	log_stderr_test \
	log_function_test \
	log_test \
	log_onoff_test \
	log_macro4stderr_test \
	log_macro4file_test \
	log_macro4function_test \
	any_test \
	optional_test \
	run_tests

log_file_test_SOURCES = \
	log_file_test.cpp

log_stderr_test_SOURCES = \
	log_stderr_test.cpp

log_function_test_SOURCES = \
	log_function_test.cpp

log_test_SOURCES = \
	log_test.cpp

log_onoff_test_SOURCES = \
	log_onoff_test.cpp

log_macro4stderr_test_SOURCES = \
	log_macro4stderr_test.cpp

log_macro4file_test_SOURCES = \
	log_macro4file_test.cpp

log_macro4function_test_SOURCES = \
	log_macro4function_test.cpp

any_test_SOURCES = \
	any_test.cpp

optional_test_SOURCES = \
	optional_test.cpp

run_tests_SOURCES = \
	run_tests.cpp \
	test_common.cpp \
	addrinfo_test.cpp \
	timer_test.cpp \
	tcp_client_server_connection_test.cpp \
	tcp_client_server_send_recv_test.cpp \
	ws_client_server_connection_test.cpp \
	ws_client_server_send_recv_test.cpp


if WITH_SSL
run_tests_SOURCES += \
	ssl_client_server_connection_test.cpp \
	ssl_client_server_send_recv_test.cpp \
	wss_client_server_connection_test.cpp \
	wss_client_server_send_recv_test.cpp
endif

clean-local:
	rm -f *~ *.o *.log *.trs

distclean-local:
	rm -f Makefile Makefile.in

