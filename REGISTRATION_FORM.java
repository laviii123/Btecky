import java.awt.*;
import java.applet.*;
import java.awt.event.*;

/*<APPLET CODE="Mini_P2_1.class" height="500" width="500"></APPLET>*/

public class Mini_P2_1 extends Applet implements ActionListener,ItemListener
{
	TextField n1,p1;
	CheckboxGroup cbg;
	String msg=" ",v=" ";
	
	public void init()
	{
		Label n=new Label("Enter your full name : ");
		n1=new TextField(20);
		
		Label p=new Label("Enter password: ");
		p1=new TextField(6);
		p1.setEchoChar('*');
		
		Label g=new Label("Select your gender : ");
		cbg=new CheckboxGroup();
		Checkbox m=new Checkbox("Male",cbg,true);
		Checkbox f=new Checkbox("Female",cbg,true);
		
		Label i=new Label("Select your interests : ");
		Checkbox cb1=new Checkbox("Video Games");
		Checkbox cb2=new Checkbox("Football");
		Checkbox cb3=new Checkbox("Swimming");
		
		Label a=new Label("Enter your address : ");
		TextArea address=new TextArea(v,5,15);
		
		Button b=new Button("Submit here");
		
		add(n);
		add(n1);
		add(p);
		add(p1);
		add(g);
		add(m);
		add(f);
		add(i);
		add(cb1);
		add(cb2);
		add(cb3);
		add(a);
		add(address);
		add(b);
		
		n1.addActionListener(this);
		p1.addActionListener(this);
		m.addItemListener(this);
		f.addItemListener(this);
		cb1.addItemListener(this);
		cb2.addItemListener(this);
		cb3.addItemListener(this);
		b.addActionListener(this);
	}
	
	public void actionPerformed(ActionEvent ae)
	{
		String s=ae.getActionCommand();
		if(s.equals("Submit here"))
		{
			msg="Thank you for Registration";
		}
		repaint();
	}
	
	public void itemStateChanged(ItemEvent ie)
	{
		repaint();
	}
	
	public void paint(Graphics g)
	{
		setBackground(Color.YELLOW);
				
		Font f1=new Font("Arial",Font.BOLD,18);
		g.setFont(f1);
		g.drawString(msg,200,300);
	}
}