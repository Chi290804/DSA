public class Square extends Rectangle {
    public Square() {}

    public Square(double size) {
        setLength(size);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Square(double size, String color, boolean filled) {
        setLength(size);
        setColor(color);
        setFilled(filled);
    }

    /**
     * An especially short bit of Javadoc.
     */
    public Square(Point topleft, double size, String color, boolean filled) {
        setTopLeft(topleft);
        setLength(size);
        setColor(color);
        setFilled(filled);
    }

    public double getSide() {
        return getLength();
    }

    public void setSide(double side) {
        setLength(side);
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
