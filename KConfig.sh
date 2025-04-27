#!/bin/bash

# 获取脚本所在绝对路径
workDir=$(dirname "$(readlink -f "$0")")



# 初始化命令
cmdline="last"

rm "./Include/auto.h" 

# 读取配置文件（添加安全检测）
config_file="$workDir/.config"
if [ ! -f "$config_file" ]; then
    echo "ERROR! 配置文件 $config_file 不存在" >&2
    exit 1
elif [ ! -r "$config_file" ]; then
    echo "ERROR! 无法读取配置文件 $config_file" >&2
    exit 1
fi
source "$config_file" || exit 1


echo "// Auto Create" > "./Include/auto.h" 

echo "#define MEMORY_SIZE " $CONFIG_SELECT_MEMORY_SIZE >>  "./Include/auto.h" 

echo "#define CONFIG_MBASE " $CONFIG_SELECT_CONFIG_MBASE >>  "./Include/auto.h" 
