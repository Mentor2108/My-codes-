public class Testing{
    static int x = 10;
    private int y = 30;
    public void method(int x)
    {
        Testing tt = new Testing();
        this.y = 40;
        System.out.println("This.y: " + this.y);
        // y=49;
        tt.y = 50;
        System.out.println("This.y: " + tt.y);

    }

    public static void main(String args[])
    {
        int miles = 5;
        System.out.printf("""
        The equivalent of %d miles is:
            %,d yards,
            %,d feet, or
            %,d inches
        """, miles, 1760*miles, 5280*miles, 12*5280*miles);
    }
}   