# 編譯器
CC = gcc

# 編譯器旗標
# -Wall -Wextra: 顯示所有常用的警告訊息
# -g:           產生除錯資訊
# -std=c11:     使用 C11 標準
CFLAGS = -Wall -Wextra -g -std=c11

# 連結器旗標 (此專案不需要特別的連結旗標)
LDFLAGS =

# 最終產生的執行檔名稱
TARGET = traffic_sim

# 所有來源 .c 檔案
SRCS = src/main.c src/set_signal.c 


# 從 .c 檔案列表自動產生 .o (object) 檔案列表
OBJS = $(SRCS:.c=.o)

# "all" 是預設的目標，當你只輸入 "make" 時會執行
.PHONY: all
all: $(TARGET)

# 連結所有 object 檔案來產生最終的執行檔
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $(TARGET) $(OBJS)

# 編譯 .c 檔案的通用規則
# $< 代表第一個依賴項 (the .c file)
# $@ 代表目標 (the .o file)
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# "clean" 目標用來清除所有編譯產生的檔案
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS)

