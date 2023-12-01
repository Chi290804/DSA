public class Square extends Rectangle {
    public Square() {}

    public Square(double size) {
        setWidth(size);
        setLength(size);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Square(double size, String color, boolean filled) {
        setWidth(size);
        setLength(size);
        setColor(color);
        setFilled(filled);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Square(Point topLeft, double size, String color, boolean filled) {
        setTopLeft(topLeft);
        setWidth(size);
        setLength(size);
        setColor(color);
        setFilled(filled);
    }

    public double getSide() {
        return getLength();
    }

    public void setSide(double side) {
        setLength(side);
        setWidth(side);
    }

    @Override
    public void setWidth(double side) {
        super.setWidth(side); 
        super.setLength(side);
    }

    @Override
    public void setLength(double side) {
        super.setWidth(side); 
        super.setLength(side);
    }

    @Override
    public double getArea() {
        return getSide() * getSide();
    }

    @Override
    public double getPerimeter() {
        return 4 * getSide();
    }

    /**
     * An especially short bit of Javadoc.
     */
    public boolean equals(Object o) {
        return super.equals(o);
    }
    
    /**
     * An especially short bit of Javadoc.
     */
    public String toString() {
        Point topLeft = super.getTopLeft();
        return ("Square[topLeft=" + topLeft.toString()
                + ",side=" + (double) Math.round(getSide() * 10) / 10
                + ",color=" + this.getColor() + ",filled=" + this.isFilled() + "]");
    }

    
}

