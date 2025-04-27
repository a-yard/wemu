

menuconfig:
	@kconfig-mconf KConfig
	@./KConfig.sh
	
GetColCount:
	@echo "C++ 行数"
	@find . -type f \( -name "*.cpp" -o -name "*.hpp" \) -exec cat {} + | wc -l