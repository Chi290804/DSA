/*Để chứng minh rằng một đồ thị là đồ thị hai màu (bipartite) khi và chỉ khi nó không chứa chu trình độ dài lẻ, ta sẽ sử dụng phương pháp phản chứng.

Giả sử đồ thị G là một đồ thị hai màu và chứa một chu trình độ dài lẻ. Ta chứng minh dẫn đến mâu thuẫn.

Đồ thị hai màu, được chia thành hai tập đỉnh phân biệt, ký hiệu là U và V. Giả sử đồ thị G có một chu trình độ dài lẻ, nghĩa là một chu trình mà số lượng cạnh là số lẻ.

Khi xét các cạnh trong chu trình này, ta thấy rằng các đỉnh xen kẽ nằm trong tập U và tập V => số lượng cạnh nối từ đỉnh từ tập U sang V bằng số lượng cạnh nối từ đỉnh từ tập V sang U. Nên số lượng cạnh nối sẽ luôn là chẵn nếu xuất hiện 1 cạnh nữa  tạo chu trình thì phải nối cùng tập => cùng màu.

Do đó, đồ thị không thể cùng lúc là đồ thị hai màu và chứa chu trình độ dài lẻ. Điều này chứng minh rằng một đồ thị là đồ thị hai màu khi và chỉ khi nó không chứa chu trình độ dài lẻ.
*/