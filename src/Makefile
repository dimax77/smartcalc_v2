TARGET = scalc
INSTALL_DIR = install
QMAKE = qmake
UNAME_S := $(shell uname -s)
FILE_PATH := $(INSTALL_DIR)/scalc
UNIT = unit_test
TESTS_FLAGS = -lgtest

ifeq ($(shell uname), Linux)
	OPEN = ./$(FILE_PATH)
endif
ifeq ($(shell uname), Darwin)
	OPEN = open $(FILE_PATH).app
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

Mac_clean:
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
	@rm -rf $(INSTALL_DIR)
	@echo "Uninstallation complete."

test:
	g++ unit_tests/model/s21test.cc $(TESTS_FLAGS) -o $(UNIT)
	./$(UNIT)

dist:
	@echo "Creating distribution archive..."
	@mkdir -p dist
	@cp -r view controller model main.cpp scalc.pro Makefile dist
	@cd dist && tar -czf ../scalc.tar.gz .
	@rm -rf dist
	@echo "Distribution archive created successfully."

dvi:
	@echo "Creating DVI file..."
	@$(MAKE) -C $(INSTALL_DIR) dvi
	@echo "DVI file created."


.PHONY: install clean mac_install mac_clean linux_install linux_clean open test dvi

