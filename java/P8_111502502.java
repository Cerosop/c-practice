// Practice 8
// Name: 黃詠綺
// ID: 111502502
// Course: 2023-CE1004-B

// package P8_111502502;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;

class User {
    private String name;
    private boolean canEdit;

    public User(String name, boolean canEdit) {
        this.name = name;
        this.canEdit = canEdit;
    }
    public void setEdit(boolean edit){
        canEdit = edit;
    }

    public String getName() {
        return this.name;
    }

    public boolean canEdit() {
        return this.canEdit;
    }
}

class Sheet { //試算表
	private String name;
    private int[][] data;
    private List<User> owners;

    public Sheet(String name, List<User> owners) {
        this.name = name;
        this.data = new int[5][5]; // 初始化sheet的初始值為0
        this.owners = owners;
    }

    public String getName() {
        return this.name;
    }
    public List<User> getOwner() {
        return this.owners;
    }

    public int getValue(int row, int col) {
        return this.data[row][col];
    }

    public void setValue(int row, int col, int value) {
        this.data[col][row] = value;
    }

    public boolean isEditable(User user) {
        for (User owner : owners) {
            if (owner.getName().equals(user.getName())) {
                return owner.canEdit();
            }
        }
        return false;
    }

    public void printSheet() {
    	for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(this.data[i][j] + "\t");
            }
            System.out.println();
        }
    }
}

class Func{

	Scanner s = new Scanner(System.in);
	public static void printMenu() {
        System.out.println("----------Menu----------");
        System.out.println("1. Create a user");
        System.out.println("2. Create a sheet");
        System.out.println("3. Check a sheet");
        System.out.println("4. Change a value in a sheet");
        System.out.println("5. Change a sheet's access right.");
        System.out.println("6. Exit");
        System.out.println("-------------------------");
    }


}

public class P8_111502502 {
	public static void main(String[] args) {
		ArrayList<User> users = new ArrayList<>(); //儲存所有使用者名單的list，並初始化
	    ArrayList<Sheet> sheets = new ArrayList<>();

		Scanner s = new Scanner(System.in);

		while (true) {
            Func.printMenu();

            String input = s.nextLine();
            if (input.equals("1")) {
            	String name = s.nextLine();
            	boolean canEdit = true;
            	User user = new User(name, canEdit);
            	users.add(user);
            	System.out.println("Create a user named \"" + name + "\".\n");
            } 
            else if (input.equals("2")) {
            	String s1 = s.nextLine();
            	String[] tmp = s1.split(" ");

            	String userName = tmp[0];
            	String sheetName = tmp[1];
            	List<User> owners = new ArrayList<>(); //創建此sheet的擁有者名單


            	for (User user : users) { //從所有人的名單裡看
                    if (user.getName().equals(userName)) { //名單有沒有人跟要儲存的這個名字相符
                    	owners.add(user);
                        break;
                    }
                }
            	Sheet sheet = new Sheet(sheetName, owners);
            	sheets.add(sheet);
            	System.out.println("Create a sheet named \"" + sheetName + "\""+" for \""+ userName + "\".\n");
            }
            else if (input.equals("3")) {
            	String s1 = s.nextLine();
            	String[] tmp = s1.split(" ");
            	String userName = tmp[0];
            	String sheetName = tmp[1];

            	for(Sheet sheet: sheets) {
            		if(sheet.getName().equals(sheetName)) {
                        for(User user:sheet.getOwner()){
                            if(user.getName().equals(userName)){
                                for(int i=0;i<5;i++) {
                                    for(int j=0;j<4;j++) {
                                        System.out.print(sheet.getValue(j, i) + ", ");
                                    }
                                    System.out.println(sheet.getValue(4, i) + ",");
                                }
                                break;
                            }
                        }
            			
            		}
            	}
            } 
            else if (input.equals("4")) {
            	String s1 = s.nextLine();
            	String[] tmp = s1.split(" ");
            	String userName = tmp[0];
            	String sheetName = tmp[1];

            	for(Sheet sheet: sheets) {
            		if(sheet.getName().equals(sheetName)) {
                        for(User user:sheet.getOwner()){
                            if(user.getName().equals(userName)){
                                for(int i=0;i<5;i++) {
                                    for(int j=0;j<4;j++) {
                                        System.out.print(sheet.getValue(j, i) + ", ");
                                    }
                                    System.out.println(sheet.getValue(4, i) + ",");
                                }
                                String in = s.nextLine();
                                String[] numbers = in.split(" ");
                                int num1 = Integer.parseInt(numbers[0]); //轉乘數字型態
                                int num2 = Integer.parseInt(numbers[1]);
                                int num3 = Integer.parseInt(numbers[2]);
                                if(user.canEdit()){
                                    sheet.setValue(num1, num2, num3);
                                }
                                else{
                                    System.out.println("This sheet is not accessible.\n");
                                }
                                for(int i=0;i<5;i++) {
                                    for(int j=0;j<4;j++) {
                                        System.out.print(sheet.getValue(j, i) + ", ");
                                    }
                                    System.out.println(sheet.getValue(4, i) + ",");
                                }
                                break;
                            }
                        }
            		}
            	}

            } 
            else if (input.equals("5")) {
                String s1 = s.nextLine();
            	String[] tmp = s1.split(" ");
            	String userName = tmp[0];
            	String sheetName = tmp[1];
                String canEdit = tmp[2];

            	for(Sheet sheet: sheets) {
            		if(sheet.getName().equals(sheetName)) {
                        for(User user:sheet.getOwner()){
                            if(user.getName().equals(userName)){
                                if(canEdit.equals("Editable"))
                                    user.setEdit(true);
                                else    user.setEdit(false);
                                break;
                            }
                        }
            		}
            	}

            }
            else if (input.equals("6")) {
            	break;
            } 



        }
        s.close();

	}

}