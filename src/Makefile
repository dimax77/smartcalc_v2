TARGET = scalc
INSTALL_DIR = install
QMAKE = qmake
UNAME_S := $(shell uname -s)
FILE_PATH := $(INSTALL_DIR)/scalc
UNIT = unit_test
TESTS_FLAGS = -lgtest
GCOV = --coverage

ifeq ($(shell uname), Linux)
	OPEN = ./$(FILE_PATH)
endif
ifeq ($(shell uname), Darwin)
	OPEN = ./install/scalc.app/Contents/MacOS/scalc
endif

all: install open

install: $(UNAME_S)

clean: $(UNAME_S)_clean

Darwin: Mac_install

Mac_install:
	@echo "Building and installing for macOS..."
	@mkdir -p $(INSTALL_DIR)
	@cd $(INSTALL_DIR) && $(QMAKE) ../scalc.pro -spec macx-clang CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)

Darwin_clean:
	@echo "Cleaning macOS..."
	@$(MAKE) -C $(INSTALL_DIR) clean

Linux: Linux_install

Linux_install:
	@echo "Building and installing for Linux..."
	@mkdir -p $(INSTALL_DIR)
	@cd $(INSTALL_DIR) && $(QMAKE) ../scalc.pro -spec linux-g++ CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)

Linux_clean:
	@echo "Cleaning Linux..."
	@$(MAKE) -C $(INSTALL_DIR) clean

open:
	$(OPEN)

uninstall:
	@echo "Uninstalling..."
	@rm -rf $(INSTALL_DIR) unit_test
	@echo "Uninstallation complete."

test:
	g++ unit_tests/model/s21test.cc $(TESTS_FLAGS) -o $(UNIT)
	./$(UNIT)
	rm -rf $(UNIT)

clang:
	cp ../materials/linters/.clang-format ./model
	clang-format -n model/*.h
	rm model/.clang-format

gcov_report:
	g++ unit_tests/model/s21test.cc $(TESTS_FLAGS) $(GCOV) -o $(UNIT)
	./$(UNIT)
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html

dist:
	@echo "Creating distribution archive..."
	@mkdir -p dist
	@cp -r view controller model main.cpp scalc.pro Makefile dist
	@cd dist && tar -czf ../scalc.tar.gz .
	@rm -rf dist
	@echo "Distribution archive created successfully."

dvi:
	open dvi.html


.PHONY: install clean mac_install mac_clean linux_install linux_clean open test dvi

