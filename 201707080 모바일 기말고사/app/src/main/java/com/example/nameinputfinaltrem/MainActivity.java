package com.example.nameinputfinaltrem;

import android.content.Intent;
import android.graphics.Paint;
import android.graphics.Typeface;
import android.os.Bundle;
import android.text.method.SingleLineTransformationMethod;
import android.view.Menu;
import android.view.MenuItem;
import android.view.SubMenu;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    TextView name ;
    int mi = 0 ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        name = (TextView)findViewById(R.id.text1);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        menu.add(Menu.NONE,1, Menu.NONE, "Input");
        menu.add(Menu.NONE,9, Menu.NONE, "Style").setEnabled(false);




        getMenuInflater().inflate(R.menu.context_item, menu);


        return super.onCreateOptionsMenu(menu);
    }


    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {

        if(name.getText() != "" && mi == 0 ){
            menu.findItem(9).setVisible(false);
            SubMenu subMenu = menu.addSubMenu("Style");
            subMenu.add(2, 3, Menu.NONE, "Normal").setChecked(true);
            subMenu.add(2, 4, Menu.NONE, "Bold");
            subMenu.add(2, 5, Menu.NONE, "Italic");
            subMenu.setGroupCheckable(2,true,true);
            mi = 1;
        }

        return super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        Intent i = new Intent();
        if(item.getItemId() == 1){
            i = new Intent( this,
                    InputActivity.class);
           startActivityForResult(i , 0);
                   }

        else if(item.getItemId() == 3){
            name.setTypeface(null, Typeface.NORMAL);
        }

        else if(item.getItemId() == 4){
            name.setTypeface(null, Typeface.BOLD);
        }

        else if(item.getItemId() == 5){
            name.setTypeface(null, Typeface.ITALIC);
        }

        return super.onOptionsItemSelected(item);
    }

    protected void onActivityResult (int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        switch (requestCode) {
            case 0:
                if (resultCode == RESULT_OK) {
                    name.append(data.getStringExtra("nameOut")+ "\n");
                }
                break;
        }
    }
    }