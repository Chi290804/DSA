import java.util.Objects;

public class Circle extends Shape {
    protected Point center = new Point(0.0, 0.0);
    protected double radius;
    
    public Circle() {}

    public Circle(double radius) {
        this.radius = radius;
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Circle(double radius, String color, boolean filled) {
        this.radius = radius;
        setColor(color);
        setFilled(filled);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Circle(Point center, double radius, String color, boolean filled) {
        this.center = center;
        this.radius = radius;
        setColor(color);
        setFilled(filled);
    }

    public Point getCenter() {
        return center;
    }

    public void setCenter(Point center) {
        this.center = center;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }
    
    /**
     * An especially short bit of Javadoc.
     */
    public String toString() {
        return ("Circle[center=(" + (double) Math.round(center.getPointX() * 10) / 10 
                + "," + (double) Math.round(center.getPointY() * 10) / 10 
                + "),radius=" + (double) Math.round(radius * 10) / 10
             + ",color=" + getColor() + ",filled=" + isFilled() + "]");
    }

    /**
     * An especially short bit of Javadoc.
     */
    public boolean equals(Object o) {
        if (o instanceof Circle) {
            Circle newx = (Circle) o;
            if (center.equals(newx.center) && newx.radius == radius) {
                return true;
            }
        }
        return false;
    }

    public int hashCode() {
        return Objects.hash(center, radius);
    }
}
