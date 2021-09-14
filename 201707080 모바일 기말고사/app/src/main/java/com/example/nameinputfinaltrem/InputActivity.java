package com.example.nameinputfinaltrem;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class InputActivity extends AppCompatActivity {
    Button btOk = null ;
    Button btCancel = null ;
    TextView nameText ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_input);
        btOk = (Button)findViewById(R.id.btnOk);
        btCancel = (Button)findViewById(R.id.btnCan);
        nameText = findViewById(R.id.nameText);

        btOk.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {
                Intent intent = new Intent();
                intent.putExtra("nameOut", nameText.getText().toString());
                setResult(RESULT_OK,intent);
                finish();
            }
        });

        btCancel.setOnClickListener(new View.OnClickListener(){

            @Override
            public void onClick(View view) {
                setResult(RESULT_CANCELED);
                finish();
            }
        });
    }



}