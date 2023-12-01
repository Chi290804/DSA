import java.util.Objects;

public class Rectangle extends Shape {
    protected Point topLeft = new Point(0.0, 0.0);
    protected double width;
    protected double length;

    public Rectangle() {}

    public Rectangle(double width, double length) {
        this.width = width;
        this.length = length;
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Rectangle(double width, double length, String color, boolean filled) {
        this.width = width;
        this.length = length;
        setColor(color);
        setFilled(filled);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Rectangle(Point topLeft, double width, double length, String color, boolean filled) {
        this.topLeft = topLeft;
        this.width = width;
        this.length = length;
        setColor(color);
        setFilled(filled);
    }

    public Point getTopLeft() {
        return topLeft;
    }

    public void setTopLeft(Point topLeft) {
        this.topLeft = topLeft;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    @Override
    public double getArea() {
        return length * width;
    }

    @Override
    public double getPerimeter() {
        return 2 * (length + width);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public boolean equals(Object o) {
        if (o instanceof Rectangle) {
            Rectangle newx = (Rectangle) o;
            if (topLeft.equals(newx.topLeft) && (newx.width == width) && (newx.length == length)) {
                return true;
            }
        }
        return false;
    }

    public int hashCode() {
        return Objects.hash(length, width, topLeft);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public String toString() {
        return ("Rectangle[topLeft=" + topLeft.toString()
                + ",width=" + (double) Math.round(getWidth() * 10) / 10
                + ",length=" + (double) Math.round(getLength() * 10) / 10
                + ",color=" + getColor() + ",filled=" + isFilled() + "]");
    }
    public static void main(String[] args) {
        Rectangle s = ,new Rectangle(new Point(10, 5), 8, "RED", true);
        System.out.println(s.toString());
    }
}
