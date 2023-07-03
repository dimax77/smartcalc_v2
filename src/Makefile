# Определение переменных
TARGET = scalc
INSTALL_DIR = install

# Путь к утилите qmake
QMAKE = qmake

# Определение целей
all: mac linux

mac:
	@echo "Building for macOS..."
	@mkdir -p $(INSTALL_DIR)/mac
	@cd $(INSTALL_DIR)/mac && $(QMAKE) ../../scalc.pro -spec macx-clang CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)/mac

linux:
	@echo "Building for Linux..."
	@mkdir -p $(INSTALL_DIR)/linux
	@cd $(INSTALL_DIR)/linux && $(QMAKE) ../../scalc.pro -spec linux-g++ CONFIG+=x86_64
	@$(MAKE) -C $(INSTALL_DIR)/linux

clean:
	@echo "Cleaning..."
	@$(MAKE) -C $(INSTALL_DIR)/mac clean
	@$(MAKE) -C $(INSTALL_DIR)/linux clean

.PHONY: all mac linux clean

