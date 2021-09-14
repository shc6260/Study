
namespace Progress
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.pbStatus = new System.Windows.Forms.ProgressBar();
            this.lblStatus = new System.Windows.Forms.Label();
            this.Timer = new System.Windows.Forms.Timer(this.components);
            this.btnRun = new System.Windows.Forms.Button();
            this.btnReset = new System.Windows.Forms.Button();
            this.speedTxt = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // pbStatus
            // 
            this.pbStatus.Location = new System.Drawing.Point(29, 59);
            this.pbStatus.Name = "pbStatus";
            this.pbStatus.Size = new System.Drawing.Size(536, 34);
            this.pbStatus.TabIndex = 0;
            // 
            // lblStatus
            // 
            this.lblStatus.AutoSize = true;
            this.lblStatus.Location = new System.Drawing.Point(32, 113);
            this.lblStatus.Name = "lblStatus";
            this.lblStatus.Size = new System.Drawing.Size(37, 12);
            this.lblStatus.TabIndex = 1;
            this.lblStatus.Text = "상태 :";
            // 
            // Timer
            // 
            this.Timer.Interval = 1000;
            this.Timer.Tick += new System.EventHandler(this.Timer_Tick);
            // 
            // btnRun
            // 
            this.btnRun.Location = new System.Drawing.Point(378, 109);
            this.btnRun.Name = "btnRun";
            this.btnRun.Size = new System.Drawing.Size(91, 21);
            this.btnRun.TabIndex = 2;
            this.btnRun.Text = "진행";
            this.btnRun.UseVisualStyleBackColor = true;
            this.btnRun.Click += new System.EventHandler(this.btnRun_Click);
            // 
            // btnReset
            // 
            this.btnReset.Location = new System.Drawing.Point(475, 109);
            this.btnReset.Name = "btnReset";
            this.btnReset.Size = new System.Drawing.Size(91, 21);
            this.btnReset.TabIndex = 2;
            this.btnReset.Text = "중지";
            this.btnReset.UseVisualStyleBackColor = true;
            this.btnReset.Click += new System.EventHandler(this.btnReset_Click);
            // 
            // speedTxt
            // 
            this.speedTxt.Location = new System.Drawing.Point(290, 109);
            this.speedTxt.Name = "speedTxt";
            this.speedTxt.Size = new System.Drawing.Size(63, 21);
            this.speedTxt.TabIndex = 3;
            this.speedTxt.Text = "1000";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(246, 114);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(41, 12);
            this.label1.TabIndex = 4;
            this.label1.Text = "속도 : ";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(607, 181);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.speedTxt);
            this.Controls.Add(this.btnReset);
            this.Controls.Add(this.btnRun);
            this.Controls.Add(this.lblStatus);
            this.Controls.Add(this.pbStatus);
            this.Name = "Form1";
            this.Text = "상태 진행";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ProgressBar pbStatus;
        private System.Windows.Forms.Label lblStatus;
        private System.Windows.Forms.Timer Timer;
        private System.Windows.Forms.Button btnRun;
        private System.Windows.Forms.Button btnReset;
        private System.Windows.Forms.TextBox speedTxt;
        private System.Windows.Forms.Label label1;
    }
}

