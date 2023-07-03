TARGET = scalc
INSTALL_DIR = install
QMAKE = qmake
UNAME_S := $(shell uname -s)
FILE_PATH := $(INSTALL_DIR)/scalc

ifeq ($(shell uname), Linux)
	OPEN = ./$(FILE_PATH)
endif
ifeq ($(shell uname), Darwin)
	OPEN = open "$(FILE_PATH).app"
endif

all: install open

install: $(UNAME_S)

clean: $(UNAME_S)_clean

Darwin: mac_install

mac_install:
	@echo "Building and installing for macOS..."
	@mkdir -p $(INSTALL_DIR)
	@cd $(INSTALL_DIR) && $(QMAKE) ../scalc.pro -spec macx-clang CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)

Mac_clean:
	@echo "Cleaning macOS..."
	@$(MAKE) -C $(INSTALL_DIR) clean

Linux: linux_install

linux_install:
	@echo "Building and installing for Linux..."
	@mkdir -p $(INSTALL_DIR)
	@cd $(INSTALL_DIR) && $(QMAKE) ../scalc.pro -spec linux-g++ CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)

open:
	$(OPEN)

Linux_clean:
	@echo "Cleaning Linux..."
	@$(MAKE) -C $(INSTALL_DIR) clean

uninstall:
	@echo "Uninstalling..."
	@rm -rf $(INSTALL_DIR)
	@echo "Uninstallation complete."

dist:
	@echo "Creating distribution archive..."
	@mkdir -p dist
	@cp -r sources dist/
	@cp -r docs dist/
	@cp README.md dist/
	@tar -czvf project_dist.tar.gz dist
	@rm -rf dist
	@echo "Distribution archive created successfully."


.PHONY: install clean mac_install mac_clean linux_install linux_clean open
