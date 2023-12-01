/*
Giả sửa có 1 đồ thị có V dỉnh, giwuax mỗi hai đỉnh trong đồ thị ta có thể chọn có hoặc không có canh ==> có thể có  2^(V^2) đồ thị
Với mỗi cạnh song song trong đồ thị, ta đều có thể thay thế bằng một cạnh khác không song song. Chứng minh:
-  Chọn hai cạnh song song bất kỳ, ví dụ (u, v) và (x, y).
    Ta có thể thấy rằng hai cạnh này đi từ hai đỉnh khác nhau (u và x) đến một đỉnh chung (v và y).
    Vì hai cạnh này song song, nếu chúng ta xóa hai cạnh này và thêm hai cạnh khác (u, y) và (x, v), ta vẫn có một đồ thị có hướng hợp lệ với cùng số cạnh như ban đầu.
==> Tổng số đồ thị không chứa cạnh song song là 2^(V^2), và điều này chứng minh rằng có tồn tại tất cả 2^(V^2) đồ thị V đỉnh không chứa cạnh song song.
*/