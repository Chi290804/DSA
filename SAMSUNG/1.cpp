/*
Đồ thị : 0-1 0-2 0-3 1-3 1-4 2-5 2-9 3-6 4-7 4-8 5-8 5-9 6-7 6-9 7-8
Ta thấy đồ thị trên có đỉnh 0 bậc 3 là bậc lẻ => không có chu trình Euler
Ta tìm được một chu trình Hamilton sau:
0-2-9-5-8-7-6-3-0-1-4

Đồ thị: 0-1 0-2 0-3 1-3 0-3 2-5 5-6 3-6 4-7 4-8 5-8 5-9 6-7 6-9 8-8
Ta thấy đồ thị trên có đỉnh 0 bậc 3 là bậc lẻ => không có chu trình Euler
Ta tìm được một chu trình Hamilton sau:
3-1-0-2-5-9-6-7-4-8


Đồ thị: 0-1 1-2 1-3 0-3 0-4 2-5 2-9 3-6 4-7 4-8 5-8 5-9 6-7 6-9 7-8
Ta thấy đồ thị trên có đỉnh 0 bậc 3 là bậc lẻ => không có chu trình Euler
Ta tìm được một chu trình Hamilton sau:
0-1-3-6-5-2-5-8-7-4

Đồ thị: 4-1 7-9 6-2 7-3 5-0 0-2 0-8 1-6 3-9 6-3 2-8 1-5 9-8 4-5 4-7
Ta thấy đồ thị trên có đỉnh 4 bậc 3 là bậc lẻ => không có chu trình Euler
Ta tìm được một chu trình Hamilton sau:
1-4-7-9-3-6-2-8-5-0
*/