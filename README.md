# Hospital Patient Management System

## Giới thiệu

Hệ thống quản lí bệnh nhân trong bệnh viện là chương trình quản lý bệnh nhân trong bệnh viện được xây dựng bằng ngôn ngữ C++. Hệ thống hỗ trợ quản lý hồ sơ bệnh nhân, đăng ký khám bệnh, quản lý hàng đợi khám, xử lý bệnh nhân cấp cứu theo mức độ ưu tiên và lưu trữ dữ liệu bệnh nhân.

---

## Cấu trúc dữ liệu sử dụng

Dự án sử dụng các cấu trúc dữ liệu tự cài đặt:

* LinkedList
* Queue
* PriorityQueue
* HashTable
* BST (Binary Search Tree)
* AVL Tree
* Algorithms

---

## Cấu trúc thư mục

```text
Project
│
├── app/
│   └── main.cpp
│
├── lib/
│   ├── LinkedList.hpp
│   ├── Queue.hpp
│   ├── PriorityQueue.hpp
│   ├── HashTable.hpp
│   ├── AVL.hpp
│   └── ...
│
├── models/
│
├── system/
│
├── patients.txt
│
└── README.md
```

---

## Yêu cầu môi trường

* Hệ điều hành Windows
* Trình biên dịch GCC/G++
* Chuẩn ngôn ngữ C++17

Kiểm tra trình biên dịch:

```bash
g++ --version
```

---

## Hướng dẫn biên dịch

### Biên dịch bằng Terminal

Mở Terminal tại thư mục gốc của dự án và thực hiện:

```bash
g++ -std=c++17 app/main.cpp -o hospital.exe
```

Sau khi biên dịch thành công sẽ tạo ra file:

```text
hospital.exe
```

---

### Biên dịch bằng Makefile (nếu có)

```bash
make
```

hoặc

```bash
mingw32-make
```

---

## Hướng dẫn chạy chương trình

Sau khi biên dịch thành công:

```bash
.\hospital.exe
```

hoặc

```bash
hospital.exe
```

---

## Dữ liệu lưu trữ

Thông tin bệnh nhân được lưu trong file:

```text
patients.txt
```

Khi chương trình khởi động:

* Đọc dữ liệu từ file.
* Tự động nạp danh sách bệnh nhân vào hệ thống.

Khi chương trình kết thúc:

* Tự động lưu dữ liệu trở lại file.
* Bảo toàn dữ liệu cho lần sử dụng tiếp theo.

---

## Chức năng chính

### 1. Quản lý bệnh nhân

* Thêm bệnh nhân.
* Tìm kiếm bệnh nhân theo mã ID.
* Xóa bệnh nhân.
* Hiển thị danh sách bệnh nhân.

### 2. Đăng ký và khám bệnh

* Đăng ký khám bệnh.
* Gọi bệnh nhân khám tiếp theo.
* Xem bệnh nhân đầu hàng đợi.
* Xem số lượng bệnh nhân đang chờ khám.

### 3. Quản lý bệnh nhân cấp cứu

* Thêm bệnh nhân cấp cứu vào hàng đợi ưu tiên.
* Xử lý bệnh nhân có độ ưu tiên cao nhất.
* Xem bệnh nhân ưu tiên cao nhất.
* Xem số lượng bệnh nhân cấp cứu đang chờ.

---

## Thành viên thực hiện

* Lê Thành Đạt
* Bùi Văn Bình

---

## Công nghệ sử dụng

* C++17
* GCC/G++
* Visual Studio Code
* Data Structures & Algorithms (DSA)

## Lưu ý khi sử dụng hệ thống

- Chức năng "Gọi bệnh nhân khám tiếp theo" của nhóm chức năng thứ 2 hoạt động theo nguyên tắc FIFO của Queue.
- Khi bệnh nhân được gọi khám, bệnh nhân đó sẽ tự động bị xóa khỏi hàng đợi khám.
- Điều này cũng khá tương tự với chức năng "Xử lí bệnh nhân có mức độ ưu tiên cao nhất" trong nhóm chức năng thứ 3.
- Do đó số lượng bệnh nhân đang chờ khám sẽ giảm đi 1 và bệnh nhân đầu hàng đợi sẽ thay đổi.
- Đây là hành vi được thiết kế nhằm mô phỏng đúng quy trình hoạt động thực tế của bệnh viện.
