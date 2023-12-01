import java.util.ArrayList;
import java.util.List;

public class Layer {
    private List<Shape> shapes = new ArrayList<>();

    /**
     * An especially short bit of Javadoc.
     */
    public void addShape(Shape shape) {
        if (shape != null) {
            shapes.add(shape);
        } 
    }

    /**
     * An especially short bit of Javadoc.
     */
    public String getInfo() {
        String info = "Layer of crazy shapes:\n";
        for (Shape it : shapes) {
            info += it.toString() + "\n";
        }
        return info;
    }

    /**
     * An especially short bit of Javadoc.
     */
    public void removeCircles() {
        shapes.removeIf(it -> it instanceof Circle);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public void removeDuplicates() {
        for (int i = 0; i < shapes.size(); i++) {
            for (int j = i+1; j < shapes.size(); j++) {
                if (shapes.get(j).equals(shapes.get(i))) {
                    shapes.remove(j);
                }
            }
        }
    }
}
