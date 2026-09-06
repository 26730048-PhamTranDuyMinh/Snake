# Rắn Săn Mồi (Snake) — Bài tập nhóm C++

Game rắn săn mồi chạy trên console, viết bằng C++11, không cần thư viện ngoài.
Chạy được trên Windows, Linux và macOS.

## Cách biên dịch

**Cách nhanh nhất (có `make`):**
```bash
make
./snake          # Windows: snake.exe
```

**Không có make — gõ tay:**
```bash
g++ -std=c++11 -O2 -o snake main.cpp snake.cpp food.cpp render.cpp menu.cpp input.cpp score.cpp
```

**Dev-C++ / Code::Blocks:** tạo project mới kiểu Console Application, thêm cả 7 file
`.cpp` và 6 file `.h` vào project, rồi Build & Run. Nhớ bật chuẩn C++11 trong
Project Options → Compiler.

**Visual Studio:** tạo Empty Project, kéo thả toàn bộ file vào. Nếu báo lỗi
encoding ở phần chú thích tiếng Việt thì thêm cờ `/utf-8` trong
Project Properties → C/C++ → Command Line.

> Game dùng mã màu ANSI. Windows 10/11 hỗ trợ sẵn (code tự bật trong `initConsole()`).
> Nếu chạy trên Windows 7 mà thấy ký tự lạ như `←[32m`, mở bằng Windows Terminal
> thay cho Command Prompt cũ.

## Phân chia file — mỗi người sở hữu phần của mình

Đây là **một repository duy nhất**, không phải ba. Ba người chia theo file,
mỗi người chỉ commit file mình sở hữu.

| Người | File sở hữu | Nội dung |
|---|---|---|
| **Bạn A** | `snake.h/.cpp`, `food.h/.cpp` | Logic con rắn: di chuyển, dài ra, chặn quay đầu 180°, kiểm tra va chạm. Sinh mồi và chướng ngại vật. |
| **Bạn B** | `render.h/.cpp`, `menu.h/.cpp` | Vẽ khung hình chống nhấp nháy, màu sắc. Menu chính, chọn độ khó, hướng dẫn, bảng xếp hạng. |
| **Bạn C** | `main.cpp`, `input.h/.cpp`, `score.h/.cpp` | Đọc bàn phím không chặn, vòng lặp game, máy trạng thái, lưu/đọc kỷ lục ra file. Kiêm người gộp code. |
| Cả nhóm | `common.h` | File "hợp đồng" — chỉ sửa khi cả ba đồng ý. |

**Quy tắc quan trọng:** chỉ bạn C được sửa `main.cpp`. Ai cần thêm hàm mới thì
khai báo trong file `.h` của mình rồi báo cho bạn C gọi.

## Quy trình Git

```bash
git clone <link-repo>
git checkout -b feature/snake-logic    # mỗi người 1 nhánh riêng
# ... code ...
git add snake.cpp snake.h
git commit -m "Them ham kiem tra va cham than ran"
git push origin feature/snake-logic
# Rồi tạo Pull Request, bạn C review và merge vào main
```

Đừng bao giờ `git push` thẳng lên `main`, và đừng commit file `snake.exe`
hay `highscore.txt`.

## Điều khiển trong game

| Phím | Tác dụng |
|---|---|
| Mũi tên hoặc W A S D | Điều khiển rắn |
| P | Tạm dừng / chơi tiếp |
| ESC | Bỏ ván, quay về menu |
| Enter | Xác nhận ở menu |

Ký hiệu: `@@` đầu rắn, `[]` thân rắn, `()` mồi, `##` tường (chỉ có ở mức Khó).

## Cách hoạt động — dùng để viết báo cáo

**Chống nhấp nháy màn hình.** Không dùng `system("cls")`. Hàm `drawGame()` dựng
toàn bộ khung hình thành một chuỗi trong bộ nhớ, đưa con trỏ về góc trái bằng
mã ANSI `\x1b[H`, rồi ghi đè một lần duy nhất bằng `fputs`.

**Chặn lỗi quay đầu 180°.** Nếu rắn đang đi sang phải mà người chơi bấm trái,
rắn sẽ đâm ngay vào thân mình. `Snake` lưu hai biến: `dir_` là hướng hiện tại,
`next_` là hướng đang chờ. Hướng chỉ được chốt vào lúc gọi `move()`, nên bấm
Lên rồi Trái thật nhanh trong cùng một bước cũng không làm rắn quay đầu.

**Sinh mồi không bị lặp vô hạn.** Cách phổ biến là random đại rồi thử lại nếu
trùng thân rắn — khi rắn dài gần kín bản đồ thì vòng lặp đó chạy rất lâu.
`spawnFood()` duyệt hết ô trống, đưa vào một mảng, rồi bốc ngẫu nhiên một ô.
Luôn kết thúc sau đúng W×H bước.

**Tách nhịp game khỏi nhịp đọc phím.** Vòng lặp trong `playOneGame()` đọc bàn
phím liên tục nhưng chỉ cập nhật vị trí rắn khi đủ `tick` mili giây
(dùng `std::chrono`). Nhờ vậy game vẫn ăn phím nhạy dù rắn đi chậm.

**Đọc phím không chặn.** Windows dùng `_kbhit()`/`_getch()` của `<conio.h>`.
Linux/macOS dùng `termios` để tắt chế độ canonical và echo, kết hợp `select()`
để kiểm tra xem có phím đang chờ hay không.

## Gợi ý làm thêm để được điểm cao

- Mồi đặc biệt xuất hiện có thời hạn, ăn được nhiều điểm hơn
- Chế độ tường xuyên qua được (đi hết mép này thì hiện ra mép kia)
- Chế độ 2 người chơi trên cùng bàn phím
- Âm thanh khi ăn mồi (`Beep()` trên Windows)
- Lưu và tải lại ván đang chơi dở
