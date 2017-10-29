#ifndef DEF_FORM1
#define DEF_FORM1

#pragma once

#define OPENGL_WIDTH 600 // for the height of the OpenGL container
#define OPENGL_HEIGHT 600 // for the width of the OpenGL container
#define OPENGL_X 12 // for the X position of the OpenGL container
#define OPENGL_Y 17 // for the Y position of the OpenGL container

#include "OpenGL.h"
#include "mesh.h"

using namespace System::Runtime::InteropServices;

Mesh current_mesh; /*creation of the mesh object that will contain the current Mesh*/

namespace OpenGL_on_a_Windows_Form {
    using namespace System;
    using namespace System::Runtime::InteropServices;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace OpenGLForm;

    /// <summary>
    /// Summary for Form1
    ///
    /// WARNING: If you change the name of this class, you will need to change the
    /// 'Resource File Name' property for the managed resource compiler tool
    /// associated with all .resx files this class depends on. Otherwise,
    /// the designers will not be able to interact properly with localized
    /// resources associated with this form.
    /// </summary>
    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
            OpenGL = gcnew COpenGL(this, OPENGL_WIDTH, OPENGL_HEIGHT, OPENGL_X, OPENGL_Y);
        }
    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::ComponentModel::IContainer^  components;
    protected:

    private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
    private: System::Windows::Forms::Timer^  timer1;

    private: System::Windows::Forms::Button^  close_button;
    private: System::Windows::Forms::Label^  state_label;
    private: System::Windows::Forms::Panel^  statusbar_panel;
    private: System::Windows::Forms::Label^  statusbar_label;
    private: System::Windows::Forms::Button^  mesh_button;
    private: System::Windows::Forms::TextBox^  mesh_textbox;
    private: System::Windows::Forms::Button^  texture_button;
    private: System::Windows::Forms::TextBox^  texture_textbox;
    private: System::Windows::Forms::GroupBox^  viewport_gb;

    private: System::Windows::Forms::GroupBox^  lightswitch_gb;
    private: System::Windows::Forms::RadioButton^  light_on_rb;
    private: System::Windows::Forms::RadioButton^  light_off_rb;
    private: System::Windows::Forms::NumericUpDown^  orfz_nud;
    private: System::Windows::Forms::Label^  orfz_label;
    private: System::Windows::Forms::NumericUpDown^  orfy_nud;
    private: System::Windows::Forms::Label^  orfy_label;
    private: System::Windows::Forms::NumericUpDown^  orfx_nud;
    private: System::Windows::Forms::Label^  ocz_label;

    private: System::Windows::Forms::TrackBar^  ocz_tb;

    private: System::Windows::Forms::Label^  camerazoom_label;
    private: System::Windows::Forms::Label^  osfz_zlabel;


    private: System::Windows::Forms::TrackBar^  osfz_tb;

    private: System::Windows::Forms::Label^  osfz_label;
    private: System::Windows::Forms::Label^  osfy_ylabel;



    private: System::Windows::Forms::TrackBar^  osfy_tb;

    private: System::Windows::Forms::Label^  osfy_label;
    private: System::Windows::Forms::Label^  osfx_xlabel;


    private: System::Windows::Forms::TrackBar^  osfx_tb;

    private: System::Windows::Forms::Label^  osfx_label;

    private: System::Windows::Forms::Label^  stretchfactor_label;

    private: System::Windows::Forms::Label^  orfx_label;
    private: System::Windows::Forms::Label^  rotation_label;

    private: System::Windows::Forms::GroupBox^  lightsource_gb;
    private: System::Windows::Forms::RadioButton^  positional_rb;
    private: System::Windows::Forms::RadioButton^  directional_rb;
    private: System::Windows::Forms::Label^  lpz_zlabel;
    private: System::Windows::Forms::TrackBar^  lpz_tb;
    private: System::Windows::Forms::Label^  lpz_label;
    private: System::Windows::Forms::Label^  lpy_ylabel;
    private: System::Windows::Forms::TrackBar^  lpy_tb;
    private: System::Windows::Forms::Label^  lpy_label;
    private: System::Windows::Forms::Label^  lpx_xlabel;
    private: System::Windows::Forms::TrackBar^  lpx_tb;
    private: System::Windows::Forms::Label^  lpx_label;
    private: System::Windows::Forms::Label^  lightposition_label;
    private: System::Windows::Forms::Label^  lcblue_blabel;

    private: System::Windows::Forms::TrackBar^  lcb_tb;
    private: System::Windows::Forms::Label^  lcblue_label;
    private: System::Windows::Forms::Label^  lcgreen_glabel;

    private: System::Windows::Forms::TrackBar^  lcg_tb;
    private: System::Windows::Forms::Label^  lcgreen_label;
    private: System::Windows::Forms::Label^  lcred_rlabel;


    private: System::Windows::Forms::TrackBar^  lcr_tb;
    private: System::Windows::Forms::Label^  lcred_label;



    private: System::Windows::Forms::Label^  lightcolor_label;
    private: System::Windows::Forms::CheckBox^  specular_chb;
    private: System::Windows::Forms::CheckBox^  diffuse_chb;
    private: System::Windows::Forms::CheckBox^  ambient_chb;
    private: System::Windows::Forms::Label^  lightingtype_label;
    private: System::Windows::Forms::Label^  materialproperties_label;
    private: System::Windows::Forms::CheckBox^  emission_chb;
private: System::Windows::Forms::CheckBox^  tracking_chb;

    private: System::Windows::Forms::Label^  obc_label;




    private: System::Windows::Forms::Label^  label26;
    private: System::Windows::Forms::TrackBar^  obcr_tb;
    private: System::Windows::Forms::Label^  obcr_rlabel;


    private: System::Windows::Forms::Label^  label24;
    private: System::Windows::Forms::TrackBar^  obcg_tb;

    private: System::Windows::Forms::Label^  obcg_glabel;


    private: System::Windows::Forms::Label^  label22;
    private: System::Windows::Forms::TrackBar^  obcb_tb;


    private: System::Windows::Forms::Label^  obcb_blabel;
    private: System::Windows::Forms::Label^  shininess_label;
    private: System::Windows::Forms::TrackBar^  msf_tb;



    private: System::Windows::Forms::Label^  msf_label;

    private: System::Windows::Forms::GroupBox^  objectsettings_gb;
    private: System::Windows::Forms::Label^  smcb_blabel;
    private: System::Windows::Forms::TrackBar^  smcb_tb;



    private: System::Windows::Forms::Label^  label33;
    private: System::Windows::Forms::Label^  smcg_glabel;

    private: System::Windows::Forms::TrackBar^  smcg_tb;


    private: System::Windows::Forms::Label^  label35;
    private: System::Windows::Forms::Label^  smcr_rlabel;
    private: System::Windows::Forms::TrackBar^  smcr_tb;


    private: System::Windows::Forms::Label^  label37;
    private: System::Windows::Forms::Label^  matspecular_label;
    private: System::Windows::Forms::Label^  dmcb_blabel;
    private: System::Windows::Forms::TrackBar^  dmcb_tb;



    private: System::Windows::Forms::Label^  label18;
    private: System::Windows::Forms::Label^  dmcg_glabel;
    private: System::Windows::Forms::TrackBar^  dmcg_tb;


    private: System::Windows::Forms::Label^  label20;
    private: System::Windows::Forms::Label^  dmcr_rlabel;
    private: System::Windows::Forms::TrackBar^  dmcr_tb;


    private: System::Windows::Forms::Label^  label30;
    private: System::Windows::Forms::Label^  matdiffuse_label;
    private: System::Windows::Forms::Label^  amcb_blabel;
    private: System::Windows::Forms::TrackBar^  amcb_tb;



    private: System::Windows::Forms::Label^  label11;
    private: System::Windows::Forms::Label^  amcg_glabel;
    private: System::Windows::Forms::TrackBar^  amcg_tb;


    private: System::Windows::Forms::Label^  label13;
    private: System::Windows::Forms::Label^  amcr_rlabel;

    private: System::Windows::Forms::TrackBar^  amcr_tb;


    private: System::Windows::Forms::Label^  label15;
    private: System::Windows::Forms::Label^  label16;
    private: System::Windows::Forms::Label^  mecb_blabel;

    private: System::Windows::Forms::TrackBar^  mecb_tb;

    private: System::Windows::Forms::Label^  label2;
    private: System::Windows::Forms::Label^  mecg_glabel;

    private: System::Windows::Forms::TrackBar^  mecg_tb;

    private: System::Windows::Forms::Label^  label6;
    private: System::Windows::Forms::Label^  mecr_rlabel;

    private: System::Windows::Forms::TrackBar^  mecr_tb;

    private: System::Windows::Forms::Label^  label8;
    private: System::Windows::Forms::Label^  matemission_label;
    private: System::Windows::Forms::Button^  resetall_button;
    private: System::Windows::Forms::Label^  refrate_label;
    private: System::Windows::Forms::TrackBar^  refrate_tb;
    private: System::Windows::Forms::Label^  refreshrate_label;
    private: System::Windows::Forms::Label^  nodataload_label;
    private: System::Windows::Forms::CheckBox^  texturing_chb;
private: System::Windows::Forms::Button^  resetobject_button;
private: System::Windows::Forms::Button^  resetview_button;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;






    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        OpenGLForm::COpenGL ^  OpenGL;
#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->close_button = (gcnew System::Windows::Forms::Button());
            this->mesh_button = (gcnew System::Windows::Forms::Button());
            this->mesh_textbox = (gcnew System::Windows::Forms::TextBox());
            this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->state_label = (gcnew System::Windows::Forms::Label());
            this->statusbar_panel = (gcnew System::Windows::Forms::Panel());
            this->nodataload_label = (gcnew System::Windows::Forms::Label());
            this->statusbar_label = (gcnew System::Windows::Forms::Label());
            this->texture_button = (gcnew System::Windows::Forms::Button());
            this->texture_textbox = (gcnew System::Windows::Forms::TextBox());
            this->viewport_gb = (gcnew System::Windows::Forms::GroupBox());
            this->refrate_label = (gcnew System::Windows::Forms::Label());
            this->refrate_tb = (gcnew System::Windows::Forms::TrackBar());
            this->refreshrate_label = (gcnew System::Windows::Forms::Label());
            this->orfz_nud = (gcnew System::Windows::Forms::NumericUpDown());
            this->orfz_label = (gcnew System::Windows::Forms::Label());
            this->orfy_nud = (gcnew System::Windows::Forms::NumericUpDown());
            this->orfy_label = (gcnew System::Windows::Forms::Label());
            this->orfx_nud = (gcnew System::Windows::Forms::NumericUpDown());
            this->ocz_label = (gcnew System::Windows::Forms::Label());
            this->ocz_tb = (gcnew System::Windows::Forms::TrackBar());
            this->camerazoom_label = (gcnew System::Windows::Forms::Label());
            this->osfz_zlabel = (gcnew System::Windows::Forms::Label());
            this->osfz_tb = (gcnew System::Windows::Forms::TrackBar());
            this->osfz_label = (gcnew System::Windows::Forms::Label());
            this->osfy_ylabel = (gcnew System::Windows::Forms::Label());
            this->osfy_tb = (gcnew System::Windows::Forms::TrackBar());
            this->osfy_label = (gcnew System::Windows::Forms::Label());
            this->osfx_xlabel = (gcnew System::Windows::Forms::Label());
            this->osfx_tb = (gcnew System::Windows::Forms::TrackBar());
            this->osfx_label = (gcnew System::Windows::Forms::Label());
            this->stretchfactor_label = (gcnew System::Windows::Forms::Label());
            this->orfx_label = (gcnew System::Windows::Forms::Label());
            this->rotation_label = (gcnew System::Windows::Forms::Label());
            this->lightsource_gb = (gcnew System::Windows::Forms::GroupBox());
            this->positional_rb = (gcnew System::Windows::Forms::RadioButton());
            this->directional_rb = (gcnew System::Windows::Forms::RadioButton());
            this->lpz_zlabel = (gcnew System::Windows::Forms::Label());
            this->lpz_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lpz_label = (gcnew System::Windows::Forms::Label());
            this->lpy_ylabel = (gcnew System::Windows::Forms::Label());
            this->lpy_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lpy_label = (gcnew System::Windows::Forms::Label());
            this->lpx_xlabel = (gcnew System::Windows::Forms::Label());
            this->lpx_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lpx_label = (gcnew System::Windows::Forms::Label());
            this->lightposition_label = (gcnew System::Windows::Forms::Label());
            this->lcblue_blabel = (gcnew System::Windows::Forms::Label());
            this->lcb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lcblue_label = (gcnew System::Windows::Forms::Label());
            this->lcgreen_glabel = (gcnew System::Windows::Forms::Label());
            this->lcg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lcgreen_label = (gcnew System::Windows::Forms::Label());
            this->lcred_rlabel = (gcnew System::Windows::Forms::Label());
            this->lcr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->lcred_label = (gcnew System::Windows::Forms::Label());
            this->lightcolor_label = (gcnew System::Windows::Forms::Label());
            this->specular_chb = (gcnew System::Windows::Forms::CheckBox());
            this->diffuse_chb = (gcnew System::Windows::Forms::CheckBox());
            this->ambient_chb = (gcnew System::Windows::Forms::CheckBox());
            this->lightingtype_label = (gcnew System::Windows::Forms::Label());
            this->lightswitch_gb = (gcnew System::Windows::Forms::GroupBox());
            this->light_on_rb = (gcnew System::Windows::Forms::RadioButton());
            this->light_off_rb = (gcnew System::Windows::Forms::RadioButton());
            this->materialproperties_label = (gcnew System::Windows::Forms::Label());
            this->emission_chb = (gcnew System::Windows::Forms::CheckBox());
            this->tracking_chb = (gcnew System::Windows::Forms::CheckBox());
            this->obc_label = (gcnew System::Windows::Forms::Label());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->obcr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->obcr_rlabel = (gcnew System::Windows::Forms::Label());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->obcg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->obcg_glabel = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->obcb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->obcb_blabel = (gcnew System::Windows::Forms::Label());
            this->shininess_label = (gcnew System::Windows::Forms::Label());
            this->msf_tb = (gcnew System::Windows::Forms::TrackBar());
            this->msf_label = (gcnew System::Windows::Forms::Label());
            this->objectsettings_gb = (gcnew System::Windows::Forms::GroupBox());
            this->texturing_chb = (gcnew System::Windows::Forms::CheckBox());
            this->smcb_blabel = (gcnew System::Windows::Forms::Label());
            this->smcb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->smcg_glabel = (gcnew System::Windows::Forms::Label());
            this->smcg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->smcr_rlabel = (gcnew System::Windows::Forms::Label());
            this->smcr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->matspecular_label = (gcnew System::Windows::Forms::Label());
            this->dmcb_blabel = (gcnew System::Windows::Forms::Label());
            this->dmcb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->dmcg_glabel = (gcnew System::Windows::Forms::Label());
            this->dmcg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->dmcr_rlabel = (gcnew System::Windows::Forms::Label());
            this->dmcr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->matdiffuse_label = (gcnew System::Windows::Forms::Label());
            this->amcb_blabel = (gcnew System::Windows::Forms::Label());
            this->amcb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->amcg_glabel = (gcnew System::Windows::Forms::Label());
            this->amcg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->amcr_rlabel = (gcnew System::Windows::Forms::Label());
            this->amcr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->mecb_blabel = (gcnew System::Windows::Forms::Label());
            this->mecb_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->mecg_glabel = (gcnew System::Windows::Forms::Label());
            this->mecg_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->mecr_rlabel = (gcnew System::Windows::Forms::Label());
            this->mecr_tb = (gcnew System::Windows::Forms::TrackBar());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->matemission_label = (gcnew System::Windows::Forms::Label());
            this->resetall_button = (gcnew System::Windows::Forms::Button());
            this->resetobject_button = (gcnew System::Windows::Forms::Button());
            this->resetview_button = (gcnew System::Windows::Forms::Button());
            this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
            this->statusbar_panel->SuspendLayout();
            this->viewport_gb->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->refrate_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfz_nud))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfy_nud))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfx_nud))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ocz_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfz_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfy_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfx_tb))->BeginInit();
            this->lightsource_gb->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpz_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpy_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpx_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcr_tb))->BeginInit();
            this->lightswitch_gb->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcr_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->msf_tb))->BeginInit();
            this->objectsettings_gb->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcr_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcr_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcr_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecb_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecg_tb))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecr_tb))->BeginInit();
            this->SuspendLayout();
            // 
            // timer1
            // 
            this->timer1->Enabled = true;
            this->timer1->Interval = 10;
            this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
            // 
            // close_button
            // 
            this->close_button->Location = System::Drawing::Point(1104, 630);
            this->close_button->Name = L"close_button";
            this->close_button->Size = System::Drawing::Size(117, 30);
            this->close_button->TabIndex = 0;
            this->close_button->Text = L"Close";
            this->close_button->UseVisualStyleBackColor = true;
            this->close_button->Click += gcnew System::EventHandler(this, &Form1::close_button_Click);
            // 
            // mesh_button
            // 
            this->mesh_button->Location = System::Drawing::Point(630, 16);
            this->mesh_button->Name = L"mesh_button";
            this->mesh_button->Size = System::Drawing::Size(120, 22);
            this->mesh_button->TabIndex = 3;
            this->mesh_button->Text = L"Select Mesh File...";
            this->mesh_button->UseVisualStyleBackColor = true;
            this->mesh_button->Click += gcnew System::EventHandler(this, &Form1::mesh_button_Click);
            // 
            // mesh_textbox
            // 
            this->mesh_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->mesh_textbox->Location = System::Drawing::Point(756, 16);
            this->mesh_textbox->Name = L"mesh_textbox";
            this->mesh_textbox->Size = System::Drawing::Size(465, 20);
            this->mesh_textbox->TabIndex = 4;
            this->mesh_textbox->Text = L"[Filename]";
            this->mesh_textbox->TextChanged += gcnew System::EventHandler(this, &Form1::mesh_textbox_TextChanged);
            this->mesh_textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Form1::mesh_textbox_KeyPress);
            // 
            // openFileDialog1
            // 
            this->openFileDialog1->DefaultExt = L"bmp";
            this->openFileDialog1->Title = L"Select a file to load the mesh from";
            // 
            // openFileDialog2
            // 
            this->openFileDialog2->DefaultExt = L"bmp";
            this->openFileDialog2->Title = L"Select a file to load the texture from...";
            // 
            // state_label
            // 
            this->state_label->AutoSize = true;
            this->state_label->Location = System::Drawing::Point(64, 6);
            this->state_label->Name = L"state_label";
            this->state_label->Size = System::Drawing::Size(38, 13);
            this->state_label->TabIndex = 7;
            this->state_label->Text = L"Ready";
            // 
            // statusbar_panel
            // 
            this->statusbar_panel->BackColor = System::Drawing::SystemColors::Info;
            this->statusbar_panel->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->statusbar_panel->Controls->Add(this->nodataload_label);
            this->statusbar_panel->Controls->Add(this->statusbar_label);
            this->statusbar_panel->Controls->Add(this->state_label);
            this->statusbar_panel->Location = System::Drawing::Point(12, 631);
            this->statusbar_panel->Name = L"statusbar_panel";
            this->statusbar_panel->Size = System::Drawing::Size(600, 28);
            this->statusbar_panel->TabIndex = 8;
            // 
            // nodataload_label
            // 
            this->nodataload_label->AutoSize = true;
            this->nodataload_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->nodataload_label->ForeColor = System::Drawing::SystemColors::HotTrack;
            this->nodataload_label->Location = System::Drawing::Point(483, 6);
            this->nodataload_label->Name = L"nodataload_label";
            this->nodataload_label->Size = System::Drawing::Size(110, 13);
            this->nodataload_label->TabIndex = 59;
            this->nodataload_label->Text = L"! No data loaded !";
            // 
            // statusbar_label
            // 
            this->statusbar_label->AutoSize = true;
            this->statusbar_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->statusbar_label->Location = System::Drawing::Point(3, 4);
            this->statusbar_label->Name = L"statusbar_label";
            this->statusbar_label->Size = System::Drawing::Size(59, 15);
            this->statusbar_label->TabIndex = 0;
            this->statusbar_label->Text = L"Status : ";
            // 
            // texture_button
            // 
            this->texture_button->Location = System::Drawing::Point(630, 44);
            this->texture_button->Name = L"texture_button";
            this->texture_button->Size = System::Drawing::Size(120, 23);
            this->texture_button->TabIndex = 10;
            this->texture_button->Text = L"Select Texture File...";
            this->texture_button->UseVisualStyleBackColor = true;
            this->texture_button->Click += gcnew System::EventHandler(this, &Form1::texture_button_Click);
            // 
            // texture_textbox
            // 
            this->texture_textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->texture_textbox->Location = System::Drawing::Point(757, 46);
            this->texture_textbox->Name = L"texture_textbox";
            this->texture_textbox->Size = System::Drawing::Size(465, 20);
            this->texture_textbox->TabIndex = 11;
            this->texture_textbox->Text = L"[Filename]";
            // 
            // viewport_gb
            // 
            this->viewport_gb->Controls->Add(this->refrate_label);
            this->viewport_gb->Controls->Add(this->refrate_tb);
            this->viewport_gb->Controls->Add(this->refreshrate_label);
            this->viewport_gb->Controls->Add(this->orfz_nud);
            this->viewport_gb->Controls->Add(this->orfz_label);
            this->viewport_gb->Controls->Add(this->orfy_nud);
            this->viewport_gb->Controls->Add(this->orfy_label);
            this->viewport_gb->Controls->Add(this->orfx_nud);
            this->viewport_gb->Controls->Add(this->ocz_label);
            this->viewport_gb->Controls->Add(this->ocz_tb);
            this->viewport_gb->Controls->Add(this->camerazoom_label);
            this->viewport_gb->Controls->Add(this->osfz_zlabel);
            this->viewport_gb->Controls->Add(this->osfz_tb);
            this->viewport_gb->Controls->Add(this->osfz_label);
            this->viewport_gb->Controls->Add(this->osfy_ylabel);
            this->viewport_gb->Controls->Add(this->osfy_tb);
            this->viewport_gb->Controls->Add(this->osfy_label);
            this->viewport_gb->Controls->Add(this->osfx_xlabel);
            this->viewport_gb->Controls->Add(this->osfx_tb);
            this->viewport_gb->Controls->Add(this->osfx_label);
            this->viewport_gb->Controls->Add(this->stretchfactor_label);
            this->viewport_gb->Controls->Add(this->orfx_label);
            this->viewport_gb->Controls->Add(this->rotation_label);
            this->viewport_gb->Controls->Add(this->lightsource_gb);
            this->viewport_gb->Controls->Add(this->lpz_zlabel);
            this->viewport_gb->Controls->Add(this->lpz_tb);
            this->viewport_gb->Controls->Add(this->lpz_label);
            this->viewport_gb->Controls->Add(this->lpy_ylabel);
            this->viewport_gb->Controls->Add(this->lpy_tb);
            this->viewport_gb->Controls->Add(this->lpy_label);
            this->viewport_gb->Controls->Add(this->lpx_xlabel);
            this->viewport_gb->Controls->Add(this->lpx_tb);
            this->viewport_gb->Controls->Add(this->lpx_label);
            this->viewport_gb->Controls->Add(this->lightposition_label);
            this->viewport_gb->Controls->Add(this->lcblue_blabel);
            this->viewport_gb->Controls->Add(this->lcb_tb);
            this->viewport_gb->Controls->Add(this->lcblue_label);
            this->viewport_gb->Controls->Add(this->lcgreen_glabel);
            this->viewport_gb->Controls->Add(this->lcg_tb);
            this->viewport_gb->Controls->Add(this->lcgreen_label);
            this->viewport_gb->Controls->Add(this->lcred_rlabel);
            this->viewport_gb->Controls->Add(this->lcr_tb);
            this->viewport_gb->Controls->Add(this->lcred_label);
            this->viewport_gb->Controls->Add(this->lightcolor_label);
            this->viewport_gb->Controls->Add(this->specular_chb);
            this->viewport_gb->Controls->Add(this->diffuse_chb);
            this->viewport_gb->Controls->Add(this->ambient_chb);
            this->viewport_gb->Controls->Add(this->lightingtype_label);
            this->viewport_gb->Controls->Add(this->lightswitch_gb);
            this->viewport_gb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->viewport_gb->Location = System::Drawing::Point(630, 360);
            this->viewport_gb->Name = L"viewport_gb";
            this->viewport_gb->Size = System::Drawing::Size(591, 257);
            this->viewport_gb->TabIndex = 12;
            this->viewport_gb->TabStop = false;
            this->viewport_gb->Text = L"Viewport";
            // 
            // refrate_label
            // 
            this->refrate_label->AutoSize = true;
            this->refrate_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->refrate_label->Location = System::Drawing::Point(40, 196);
            this->refrate_label->Name = L"refrate_label";
            this->refrate_label->Size = System::Drawing::Size(41, 13);
            this->refrate_label->TabIndex = 59;
            this->refrate_label->Text = L"100 ms";
            // 
            // refrate_tb
            // 
            this->refrate_tb->LargeChange = 50;
            this->refrate_tb->Location = System::Drawing::Point(6, 210);
            this->refrate_tb->Maximum = 200;
            this->refrate_tb->Minimum = 2;
            this->refrate_tb->Name = L"refrate_tb";
            this->refrate_tb->Size = System::Drawing::Size(104, 42);
            this->refrate_tb->SmallChange = 5;
            this->refrate_tb->TabIndex = 58;
            this->refrate_tb->TickFrequency = 20;
            this->refrate_tb->TickStyle = System::Windows::Forms::TickStyle::Both;
            this->refrate_tb->Value = 20;
            this->refrate_tb->Scroll += gcnew System::EventHandler(this, &Form1::refrate_tb_Scroll);
            this->refrate_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::refrate_tb_Scroll);
            // 
            // refreshrate_label
            // 
            this->refreshrate_label->AutoSize = true;
            this->refreshrate_label->Location = System::Drawing::Point(7, 175);
            this->refreshrate_label->Name = L"refreshrate_label";
            this->refreshrate_label->Size = System::Drawing::Size(96, 13);
            this->refreshrate_label->TabIndex = 57;
            this->refreshrate_label->Text = L"Rendering Rate";
            // 
            // orfz_nud
            // 
            this->orfz_nud->BackColor = System::Drawing::SystemColors::Control;
            this->orfz_nud->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->orfz_nud->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfz_nud->Location = System::Drawing::Point(179, 211);
            this->orfz_nud->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
            this->orfz_nud->Name = L"orfz_nud";
            this->orfz_nud->Size = System::Drawing::Size(47, 16);
            this->orfz_nud->TabIndex = 56;
            this->orfz_nud->ValueChanged += gcnew System::EventHandler(this, &Form1::orfz_nud_ValueChanged);
            // 
            // orfz_label
            // 
            this->orfz_label->AutoSize = true;
            this->orfz_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfz_label->Location = System::Drawing::Point(126, 211);
            this->orfz_label->Name = L"orfz_label";
            this->orfz_label->Size = System::Drawing::Size(44, 13);
            this->orfz_label->TabIndex = 55;
            this->orfz_label->Text = L"Z factor";
            // 
            // orfy_nud
            // 
            this->orfy_nud->BackColor = System::Drawing::SystemColors::Control;
            this->orfy_nud->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->orfy_nud->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfy_nud->Location = System::Drawing::Point(179, 181);
            this->orfy_nud->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
            this->orfy_nud->Name = L"orfy_nud";
            this->orfy_nud->Size = System::Drawing::Size(47, 16);
            this->orfy_nud->TabIndex = 54;
            this->orfy_nud->ValueChanged += gcnew System::EventHandler(this, &Form1::orfy_nud_ValueChanged);
            // 
            // orfy_label
            // 
            this->orfy_label->AutoSize = true;
            this->orfy_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfy_label->Location = System::Drawing::Point(126, 181);
            this->orfy_label->Name = L"orfy_label";
            this->orfy_label->Size = System::Drawing::Size(44, 13);
            this->orfy_label->TabIndex = 53;
            this->orfy_label->Text = L"Y factor";
            // 
            // orfx_nud
            // 
            this->orfx_nud->BackColor = System::Drawing::SystemColors::Control;
            this->orfx_nud->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->orfx_nud->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfx_nud->Location = System::Drawing::Point(179, 152);
            this->orfx_nud->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {100, 0, 0, System::Int32::MinValue});
            this->orfx_nud->Name = L"orfx_nud";
            this->orfx_nud->Size = System::Drawing::Size(47, 16);
            this->orfx_nud->TabIndex = 52;
            this->orfx_nud->ValueChanged += gcnew System::EventHandler(this, &Form1::orfx_nud_ValueChanged);
            // 
            // ocz_label
            // 
            this->ocz_label->AutoSize = true;
            this->ocz_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->ocz_label->Location = System::Drawing::Point(548, 190);
            this->ocz_label->Name = L"ocz_label";
            this->ocz_label->Size = System::Drawing::Size(28, 13);
            this->ocz_label->TabIndex = 51;
            this->ocz_label->Text = L"1.00";
            // 
            // ocz_tb
            // 
            this->ocz_tb->LargeChange = 10;
            this->ocz_tb->Location = System::Drawing::Point(493, 146);
            this->ocz_tb->Maximum = 270;
            this->ocz_tb->Name = L"ocz_tb";
            this->ocz_tb->Orientation = System::Windows::Forms::Orientation::Vertical;
            this->ocz_tb->Size = System::Drawing::Size(42, 104);
            this->ocz_tb->TabIndex = 50;
            this->ocz_tb->TickFrequency = 50;
            this->ocz_tb->TickStyle = System::Windows::Forms::TickStyle::Both;
            this->ocz_tb->Value = 100;
            this->ocz_tb->Scroll += gcnew System::EventHandler(this, &Form1::ocz_tb_Scroll);
            this->ocz_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::ocz_tb_Scroll);
            // 
            // camerazoom_label
            // 
            this->camerazoom_label->AutoSize = true;
            this->camerazoom_label->Location = System::Drawing::Point(463, 133);
            this->camerazoom_label->Name = L"camerazoom_label";
            this->camerazoom_label->Size = System::Drawing::Size(125, 13);
            this->camerazoom_label->TabIndex = 48;
            this->camerazoom_label->Text = L"Object Camera Zoom";
            // 
            // osfz_zlabel
            // 
            this->osfz_zlabel->AutoSize = true;
            this->osfz_zlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfz_zlabel->Location = System::Drawing::Point(438, 209);
            this->osfz_zlabel->Name = L"osfz_zlabel";
            this->osfz_zlabel->Size = System::Drawing::Size(22, 13);
            this->osfz_zlabel->TabIndex = 47;
            this->osfz_zlabel->Text = L"1.0";
            // 
            // osfz_tb
            // 
            this->osfz_tb->LargeChange = 10;
            this->osfz_tb->Location = System::Drawing::Point(258, 209);
            this->osfz_tb->Maximum = 100;
            this->osfz_tb->Name = L"osfz_tb";
            this->osfz_tb->Size = System::Drawing::Size(185, 42);
            this->osfz_tb->TabIndex = 46;
            this->osfz_tb->TickFrequency = 10;
            this->osfz_tb->Value = 10;
            this->osfz_tb->Scroll += gcnew System::EventHandler(this, &Form1::osfz_tb_Scroll);
            this->osfz_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::osfz_tb_Scroll);
            // 
            // osfz_label
            // 
            this->osfz_label->AutoSize = true;
            this->osfz_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfz_label->Location = System::Drawing::Point(246, 211);
            this->osfz_label->Name = L"osfz_label";
            this->osfz_label->Size = System::Drawing::Size(14, 13);
            this->osfz_label->TabIndex = 45;
            this->osfz_label->Text = L"Z";
            // 
            // osfy_ylabel
            // 
            this->osfy_ylabel->AutoSize = true;
            this->osfy_ylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfy_ylabel->Location = System::Drawing::Point(438, 179);
            this->osfy_ylabel->Name = L"osfy_ylabel";
            this->osfy_ylabel->Size = System::Drawing::Size(22, 13);
            this->osfy_ylabel->TabIndex = 44;
            this->osfy_ylabel->Text = L"1.0";
            // 
            // osfy_tb
            // 
            this->osfy_tb->LargeChange = 10;
            this->osfy_tb->Location = System::Drawing::Point(258, 179);
            this->osfy_tb->Maximum = 100;
            this->osfy_tb->Name = L"osfy_tb";
            this->osfy_tb->Size = System::Drawing::Size(185, 42);
            this->osfy_tb->TabIndex = 43;
            this->osfy_tb->TickFrequency = 10;
            this->osfy_tb->Value = 10;
            this->osfy_tb->Scroll += gcnew System::EventHandler(this, &Form1::osfy_tb_Scroll);
            this->osfy_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::osfy_tb_Scroll);
            // 
            // osfy_label
            // 
            this->osfy_label->AutoSize = true;
            this->osfy_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfy_label->Location = System::Drawing::Point(246, 181);
            this->osfy_label->Name = L"osfy_label";
            this->osfy_label->Size = System::Drawing::Size(14, 13);
            this->osfy_label->TabIndex = 42;
            this->osfy_label->Text = L"Y";
            // 
            // osfx_xlabel
            // 
            this->osfx_xlabel->AutoSize = true;
            this->osfx_xlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfx_xlabel->Location = System::Drawing::Point(438, 151);
            this->osfx_xlabel->Name = L"osfx_xlabel";
            this->osfx_xlabel->Size = System::Drawing::Size(22, 13);
            this->osfx_xlabel->TabIndex = 41;
            this->osfx_xlabel->Text = L"1.0";
            // 
            // osfx_tb
            // 
            this->osfx_tb->LargeChange = 10;
            this->osfx_tb->Location = System::Drawing::Point(258, 149);
            this->osfx_tb->Maximum = 100;
            this->osfx_tb->Name = L"osfx_tb";
            this->osfx_tb->Size = System::Drawing::Size(185, 42);
            this->osfx_tb->TabIndex = 40;
            this->osfx_tb->TickFrequency = 10;
            this->osfx_tb->Value = 10;
            this->osfx_tb->Scroll += gcnew System::EventHandler(this, &Form1::osfx_tb_Scroll);
            this->osfx_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::osfx_tb_Scroll);
            // 
            // osfx_label
            // 
            this->osfx_label->AutoSize = true;
            this->osfx_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->osfx_label->Location = System::Drawing::Point(246, 151);
            this->osfx_label->Name = L"osfx_label";
            this->osfx_label->Size = System::Drawing::Size(14, 13);
            this->osfx_label->TabIndex = 39;
            this->osfx_label->Text = L"X";
            // 
            // stretchfactor_label
            // 
            this->stretchfactor_label->AutoSize = true;
            this->stretchfactor_label->Location = System::Drawing::Point(243, 130);
            this->stretchfactor_label->Name = L"stretchfactor_label";
            this->stretchfactor_label->Size = System::Drawing::Size(146, 13);
            this->stretchfactor_label->TabIndex = 38;
            this->stretchfactor_label->Text = L"Object Stretching Factor";
            // 
            // orfx_label
            // 
            this->orfx_label->AutoSize = true;
            this->orfx_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->orfx_label->Location = System::Drawing::Point(126, 152);
            this->orfx_label->Name = L"orfx_label";
            this->orfx_label->Size = System::Drawing::Size(44, 13);
            this->orfx_label->TabIndex = 29;
            this->orfx_label->Text = L"X factor";
            // 
            // rotation_label
            // 
            this->rotation_label->AutoSize = true;
            this->rotation_label->Location = System::Drawing::Point(123, 130);
            this->rotation_label->Name = L"rotation_label";
            this->rotation_label->Size = System::Drawing::Size(96, 13);
            this->rotation_label->TabIndex = 28;
            this->rotation_label->Text = L"Object Rotation";
            // 
            // lightsource_gb
            // 
            this->lightsource_gb->BackColor = System::Drawing::SystemColors::Control;
            this->lightsource_gb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->lightsource_gb->Controls->Add(this->positional_rb);
            this->lightsource_gb->Controls->Add(this->directional_rb);
            this->lightsource_gb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lightsource_gb->Location = System::Drawing::Point(6, 98);
            this->lightsource_gb->Name = L"lightsource_gb";
            this->lightsource_gb->Size = System::Drawing::Size(95, 68);
            this->lightsource_gb->TabIndex = 4;
            this->lightsource_gb->TabStop = false;
            this->lightsource_gb->Text = L"Light Source";
            // 
            // positional_rb
            // 
            this->positional_rb->AutoSize = true;
            this->positional_rb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->positional_rb->Location = System::Drawing::Point(8, 19);
            this->positional_rb->Name = L"positional_rb";
            this->positional_rb->Size = System::Drawing::Size(70, 17);
            this->positional_rb->TabIndex = 1;
            this->positional_rb->TabStop = true;
            this->positional_rb->Text = L"Positional";
            this->positional_rb->UseVisualStyleBackColor = true;
            this->positional_rb->CheckedChanged += gcnew System::EventHandler(this, &Form1::positional_rb_CheckedChanged);
            // 
            // directional_rb
            // 
            this->directional_rb->AutoSize = true;
            this->directional_rb->Checked = true;
            this->directional_rb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->directional_rb->Location = System::Drawing::Point(8, 42);
            this->directional_rb->Name = L"directional_rb";
            this->directional_rb->Size = System::Drawing::Size(75, 17);
            this->directional_rb->TabIndex = 2;
            this->directional_rb->TabStop = true;
            this->directional_rb->Text = L"Directional";
            this->directional_rb->UseVisualStyleBackColor = true;
            this->directional_rb->CheckedChanged += gcnew System::EventHandler(this, &Form1::directional_rb_CheckedChanged);
            // 
            // lpz_zlabel
            // 
            this->lpz_zlabel->AutoSize = true;
            this->lpz_zlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpz_zlabel->Location = System::Drawing::Point(560, 100);
            this->lpz_zlabel->Name = L"lpz_zlabel";
            this->lpz_zlabel->Size = System::Drawing::Size(13, 13);
            this->lpz_zlabel->TabIndex = 27;
            this->lpz_zlabel->Text = L"2";
            // 
            // lpz_tb
            // 
            this->lpz_tb->LargeChange = 200;
            this->lpz_tb->Location = System::Drawing::Point(441, 98);
            this->lpz_tb->Maximum = 1000;
            this->lpz_tb->Minimum = -1000;
            this->lpz_tb->Name = L"lpz_tb";
            this->lpz_tb->Size = System::Drawing::Size(122, 42);
            this->lpz_tb->TabIndex = 26;
            this->lpz_tb->TickFrequency = 200;
            this->lpz_tb->Value = 20;
            this->lpz_tb->Scroll += gcnew System::EventHandler(this, &Form1::lpz_tb_Scroll);
            this->lpz_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lpz_tb_Scroll);
            // 
            // lpz_label
            // 
            this->lpz_label->AutoSize = true;
            this->lpz_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpz_label->Location = System::Drawing::Point(429, 100);
            this->lpz_label->Name = L"lpz_label";
            this->lpz_label->Size = System::Drawing::Size(14, 13);
            this->lpz_label->TabIndex = 25;
            this->lpz_label->Text = L"Z";
            // 
            // lpy_ylabel
            // 
            this->lpy_ylabel->AutoSize = true;
            this->lpy_ylabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpy_ylabel->Location = System::Drawing::Point(560, 70);
            this->lpy_ylabel->Name = L"lpy_ylabel";
            this->lpy_ylabel->Size = System::Drawing::Size(13, 13);
            this->lpy_ylabel->TabIndex = 24;
            this->lpy_ylabel->Text = L"2";
            // 
            // lpy_tb
            // 
            this->lpy_tb->LargeChange = 200;
            this->lpy_tb->Location = System::Drawing::Point(441, 68);
            this->lpy_tb->Maximum = 1000;
            this->lpy_tb->Minimum = -1000;
            this->lpy_tb->Name = L"lpy_tb";
            this->lpy_tb->Size = System::Drawing::Size(122, 42);
            this->lpy_tb->TabIndex = 23;
            this->lpy_tb->TickFrequency = 200;
            this->lpy_tb->Value = 20;
            this->lpy_tb->Scroll += gcnew System::EventHandler(this, &Form1::lpy_tb_Scroll);
            this->lpy_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lpy_tb_Scroll);
            // 
            // lpy_label
            // 
            this->lpy_label->AutoSize = true;
            this->lpy_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpy_label->Location = System::Drawing::Point(429, 70);
            this->lpy_label->Name = L"lpy_label";
            this->lpy_label->Size = System::Drawing::Size(14, 13);
            this->lpy_label->TabIndex = 22;
            this->lpy_label->Text = L"Y";
            // 
            // lpx_xlabel
            // 
            this->lpx_xlabel->AutoSize = true;
            this->lpx_xlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpx_xlabel->Location = System::Drawing::Point(560, 42);
            this->lpx_xlabel->Name = L"lpx_xlabel";
            this->lpx_xlabel->Size = System::Drawing::Size(13, 13);
            this->lpx_xlabel->TabIndex = 21;
            this->lpx_xlabel->Text = L"2";
            // 
            // lpx_tb
            // 
            this->lpx_tb->LargeChange = 200;
            this->lpx_tb->Location = System::Drawing::Point(441, 38);
            this->lpx_tb->Maximum = 1000;
            this->lpx_tb->Minimum = -1000;
            this->lpx_tb->Name = L"lpx_tb";
            this->lpx_tb->Size = System::Drawing::Size(122, 42);
            this->lpx_tb->TabIndex = 20;
            this->lpx_tb->TickFrequency = 200;
            this->lpx_tb->Value = 20;
            this->lpx_tb->Scroll += gcnew System::EventHandler(this, &Form1::lpx_tb_Scroll);
            this->lpx_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lpx_tb_Scroll);
            // 
            // lpx_label
            // 
            this->lpx_label->AutoSize = true;
            this->lpx_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lpx_label->Location = System::Drawing::Point(429, 40);
            this->lpx_label->Name = L"lpx_label";
            this->lpx_label->Size = System::Drawing::Size(14, 13);
            this->lpx_label->TabIndex = 19;
            this->lpx_label->Text = L"X";
            // 
            // lightposition_label
            // 
            this->lightposition_label->AutoSize = true;
            this->lightposition_label->Location = System::Drawing::Point(426, 19);
            this->lightposition_label->Name = L"lightposition_label";
            this->lightposition_label->Size = System::Drawing::Size(83, 13);
            this->lightposition_label->TabIndex = 18;
            this->lightposition_label->Text = L"Light position";
            // 
            // lcblue_blabel
            // 
            this->lcblue_blabel->AutoSize = true;
            this->lcblue_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcblue_blabel->Location = System::Drawing::Point(378, 100);
            this->lcblue_blabel->Name = L"lcblue_blabel";
            this->lcblue_blabel->Size = System::Drawing::Size(25, 13);
            this->lcblue_blabel->TabIndex = 17;
            this->lcblue_blabel->Text = L"100";
            // 
            // lcb_tb
            // 
            this->lcb_tb->LargeChange = 32;
            this->lcb_tb->Location = System::Drawing::Point(258, 98);
            this->lcb_tb->Maximum = 255;
            this->lcb_tb->Name = L"lcb_tb";
            this->lcb_tb->Size = System::Drawing::Size(125, 42);
            this->lcb_tb->TabIndex = 16;
            this->lcb_tb->TickFrequency = 50;
            this->lcb_tb->Value = 100;
            this->lcb_tb->Scroll += gcnew System::EventHandler(this, &Form1::lcb_tb_Scroll);
            this->lcb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lcb_tb_Scroll);
            // 
            // lcblue_label
            // 
            this->lcblue_label->AutoSize = true;
            this->lcblue_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcblue_label->Location = System::Drawing::Point(246, 100);
            this->lcblue_label->Name = L"lcblue_label";
            this->lcblue_label->Size = System::Drawing::Size(14, 13);
            this->lcblue_label->TabIndex = 15;
            this->lcblue_label->Text = L"B";
            // 
            // lcgreen_glabel
            // 
            this->lcgreen_glabel->AutoSize = true;
            this->lcgreen_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcgreen_glabel->Location = System::Drawing::Point(378, 70);
            this->lcgreen_glabel->Name = L"lcgreen_glabel";
            this->lcgreen_glabel->Size = System::Drawing::Size(25, 13);
            this->lcgreen_glabel->TabIndex = 14;
            this->lcgreen_glabel->Text = L"100";
            // 
            // lcg_tb
            // 
            this->lcg_tb->LargeChange = 32;
            this->lcg_tb->Location = System::Drawing::Point(258, 68);
            this->lcg_tb->Maximum = 255;
            this->lcg_tb->Name = L"lcg_tb";
            this->lcg_tb->Size = System::Drawing::Size(125, 42);
            this->lcg_tb->TabIndex = 13;
            this->lcg_tb->TickFrequency = 50;
            this->lcg_tb->Value = 100;
            this->lcg_tb->Scroll += gcnew System::EventHandler(this, &Form1::lcg_tb_Scroll);
            this->lcg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lcg_tb_Scroll);
            // 
            // lcgreen_label
            // 
            this->lcgreen_label->AutoSize = true;
            this->lcgreen_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcgreen_label->Location = System::Drawing::Point(246, 70);
            this->lcgreen_label->Name = L"lcgreen_label";
            this->lcgreen_label->Size = System::Drawing::Size(15, 13);
            this->lcgreen_label->TabIndex = 12;
            this->lcgreen_label->Text = L"G";
            // 
            // lcred_rlabel
            // 
            this->lcred_rlabel->AutoSize = true;
            this->lcred_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcred_rlabel->Location = System::Drawing::Point(378, 42);
            this->lcred_rlabel->Name = L"lcred_rlabel";
            this->lcred_rlabel->Size = System::Drawing::Size(25, 13);
            this->lcred_rlabel->TabIndex = 11;
            this->lcred_rlabel->Text = L"100";
            // 
            // lcr_tb
            // 
            this->lcr_tb->LargeChange = 32;
            this->lcr_tb->Location = System::Drawing::Point(258, 38);
            this->lcr_tb->Maximum = 255;
            this->lcr_tb->Name = L"lcr_tb";
            this->lcr_tb->Size = System::Drawing::Size(125, 42);
            this->lcr_tb->TabIndex = 10;
            this->lcr_tb->TickFrequency = 50;
            this->lcr_tb->Value = 100;
            this->lcr_tb->Scroll += gcnew System::EventHandler(this, &Form1::lcr_tb_Scroll);
            this->lcr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::lcr_tb_Scroll);
            // 
            // lcred_label
            // 
            this->lcred_label->AutoSize = true;
            this->lcred_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lcred_label->Location = System::Drawing::Point(246, 40);
            this->lcred_label->Name = L"lcred_label";
            this->lcred_label->Size = System::Drawing::Size(15, 13);
            this->lcred_label->TabIndex = 9;
            this->lcred_label->Text = L"R";
            // 
            // lightcolor_label
            // 
            this->lightcolor_label->AutoSize = true;
            this->lightcolor_label->Location = System::Drawing::Point(243, 19);
            this->lightcolor_label->Name = L"lightcolor_label";
            this->lightcolor_label->Size = System::Drawing::Size(67, 13);
            this->lightcolor_label->TabIndex = 8;
            this->lightcolor_label->Text = L"Light color";
            // 
            // specular_chb
            // 
            this->specular_chb->AutoSize = true;
            this->specular_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->specular_chb->Location = System::Drawing::Point(124, 90);
            this->specular_chb->Name = L"specular_chb";
            this->specular_chb->Size = System::Drawing::Size(68, 17);
            this->specular_chb->TabIndex = 7;
            this->specular_chb->Text = L"Specular";
            this->specular_chb->UseVisualStyleBackColor = true;
            this->specular_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::specular_chb_CheckedChanged);
            // 
            // diffuse_chb
            // 
            this->diffuse_chb->AutoSize = true;
            this->diffuse_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->diffuse_chb->Location = System::Drawing::Point(124, 67);
            this->diffuse_chb->Name = L"diffuse_chb";
            this->diffuse_chb->Size = System::Drawing::Size(59, 17);
            this->diffuse_chb->TabIndex = 6;
            this->diffuse_chb->Text = L"Diffuse";
            this->diffuse_chb->UseVisualStyleBackColor = true;
            this->diffuse_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::diffuse_chb_CheckedChanged);
            // 
            // ambient_chb
            // 
            this->ambient_chb->AutoSize = true;
            this->ambient_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->ambient_chb->Location = System::Drawing::Point(124, 44);
            this->ambient_chb->Name = L"ambient_chb";
            this->ambient_chb->Size = System::Drawing::Size(64, 17);
            this->ambient_chb->TabIndex = 5;
            this->ambient_chb->Text = L"Ambient";
            this->ambient_chb->UseVisualStyleBackColor = true;
            this->ambient_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::ambient_chb_CheckedChanged);
            // 
            // lightingtype_label
            // 
            this->lightingtype_label->AutoSize = true;
            this->lightingtype_label->Location = System::Drawing::Point(123, 19);
            this->lightingtype_label->Name = L"lightingtype_label";
            this->lightingtype_label->Size = System::Drawing::Size(80, 13);
            this->lightingtype_label->TabIndex = 4;
            this->lightingtype_label->Text = L"Lighting type";
            // 
            // lightswitch_gb
            // 
            this->lightswitch_gb->BackColor = System::Drawing::SystemColors::Control;
            this->lightswitch_gb->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
            this->lightswitch_gb->Controls->Add(this->light_on_rb);
            this->lightswitch_gb->Controls->Add(this->light_off_rb);
            this->lightswitch_gb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->lightswitch_gb->Location = System::Drawing::Point(6, 19);
            this->lightswitch_gb->Name = L"lightswitch_gb";
            this->lightswitch_gb->Size = System::Drawing::Size(95, 73);
            this->lightswitch_gb->TabIndex = 3;
            this->lightswitch_gb->TabStop = false;
            this->lightswitch_gb->Text = L"Light Switch";
            // 
            // light_on_rb
            // 
            this->light_on_rb->AutoSize = true;
            this->light_on_rb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->light_on_rb->Location = System::Drawing::Point(8, 21);
            this->light_on_rb->Name = L"light_on_rb";
            this->light_on_rb->Size = System::Drawing::Size(41, 17);
            this->light_on_rb->TabIndex = 1;
            this->light_on_rb->TabStop = true;
            this->light_on_rb->Text = L"ON";
            this->light_on_rb->UseVisualStyleBackColor = true;
            this->light_on_rb->CheckedChanged += gcnew System::EventHandler(this, &Form1::light_on_rb_CheckedChanged);
            // 
            // light_off_rb
            // 
            this->light_off_rb->AutoSize = true;
            this->light_off_rb->Checked = true;
            this->light_off_rb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->light_off_rb->Location = System::Drawing::Point(8, 44);
            this->light_off_rb->Name = L"light_off_rb";
            this->light_off_rb->Size = System::Drawing::Size(45, 17);
            this->light_off_rb->TabIndex = 2;
            this->light_off_rb->TabStop = true;
            this->light_off_rb->Text = L"OFF";
            this->light_off_rb->UseVisualStyleBackColor = true;
            this->light_off_rb->CheckedChanged += gcnew System::EventHandler(this, &Form1::light_off_rb_CheckedChanged);
            // 
            // materialproperties_label
            // 
            this->materialproperties_label->AutoSize = true;
            this->materialproperties_label->Location = System::Drawing::Point(6, 19);
            this->materialproperties_label->Name = L"materialproperties_label";
            this->materialproperties_label->Size = System::Drawing::Size(113, 13);
            this->materialproperties_label->TabIndex = 4;
            this->materialproperties_label->Text = L"Material Properties";
            // 
            // emission_chb
            // 
            this->emission_chb->AutoSize = true;
            this->emission_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->emission_chb->Location = System::Drawing::Point(17, 64);
            this->emission_chb->Name = L"emission_chb";
            this->emission_chb->Size = System::Drawing::Size(67, 17);
            this->emission_chb->TabIndex = 5;
            this->emission_chb->Text = L"Emission";
            this->emission_chb->UseVisualStyleBackColor = true;
            this->emission_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::emission_chb_CheckedChanged);
            // 
            // tracking_chb
            // 
            this->tracking_chb->AutoSize = true;
            this->tracking_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->tracking_chb->Location = System::Drawing::Point(17, 87);
            this->tracking_chb->Name = L"tracking_chb";
            this->tracking_chb->Size = System::Drawing::Size(95, 17);
            this->tracking_chb->TabIndex = 6;
            this->tracking_chb->Text = L"Color Tracking";
            this->tracking_chb->UseVisualStyleBackColor = true;
            this->tracking_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::tracking_chb_CheckedChanged);
            // 
            // obc_label
            // 
            this->obc_label->AutoSize = true;
            this->obc_label->Location = System::Drawing::Point(138, 19);
            this->obc_label->Name = L"obc_label";
            this->obc_label->Size = System::Drawing::Size(109, 13);
            this->obc_label->TabIndex = 8;
            this->obc_label->Text = L"Object Base Color";
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label26->Location = System::Drawing::Point(141, 40);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(15, 13);
            this->label26->TabIndex = 9;
            this->label26->Text = L"R";
            // 
            // obcr_tb
            // 
            this->obcr_tb->LargeChange = 32;
            this->obcr_tb->Location = System::Drawing::Point(153, 38);
            this->obcr_tb->Maximum = 255;
            this->obcr_tb->Name = L"obcr_tb";
            this->obcr_tb->Size = System::Drawing::Size(188, 42);
            this->obcr_tb->TabIndex = 10;
            this->obcr_tb->TickFrequency = 50;
            this->obcr_tb->Value = 100;
            this->obcr_tb->Scroll += gcnew System::EventHandler(this, &Form1::obcr_tb_Scroll);
            this->obcr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::obcr_tb_Scroll);
            // 
            // obcr_rlabel
            // 
            this->obcr_rlabel->AutoSize = true;
            this->obcr_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->obcr_rlabel->Location = System::Drawing::Point(337, 42);
            this->obcr_rlabel->Name = L"obcr_rlabel";
            this->obcr_rlabel->Size = System::Drawing::Size(25, 13);
            this->obcr_rlabel->TabIndex = 11;
            this->obcr_rlabel->Text = L"100";
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label24->Location = System::Drawing::Point(141, 70);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(15, 13);
            this->label24->TabIndex = 12;
            this->label24->Text = L"G";
            // 
            // obcg_tb
            // 
            this->obcg_tb->LargeChange = 32;
            this->obcg_tb->Location = System::Drawing::Point(153, 68);
            this->obcg_tb->Maximum = 255;
            this->obcg_tb->Name = L"obcg_tb";
            this->obcg_tb->Size = System::Drawing::Size(188, 42);
            this->obcg_tb->TabIndex = 13;
            this->obcg_tb->TickFrequency = 50;
            this->obcg_tb->Value = 100;
            this->obcg_tb->Scroll += gcnew System::EventHandler(this, &Form1::obcg_tb_Scroll);
            this->obcg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::obcg_tb_Scroll);
            // 
            // obcg_glabel
            // 
            this->obcg_glabel->AutoSize = true;
            this->obcg_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->obcg_glabel->Location = System::Drawing::Point(337, 70);
            this->obcg_glabel->Name = L"obcg_glabel";
            this->obcg_glabel->Size = System::Drawing::Size(25, 13);
            this->obcg_glabel->TabIndex = 14;
            this->obcg_glabel->Text = L"100";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label22->Location = System::Drawing::Point(141, 100);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(14, 13);
            this->label22->TabIndex = 15;
            this->label22->Text = L"B";
            // 
            // obcb_tb
            // 
            this->obcb_tb->LargeChange = 32;
            this->obcb_tb->Location = System::Drawing::Point(153, 98);
            this->obcb_tb->Maximum = 255;
            this->obcb_tb->Name = L"obcb_tb";
            this->obcb_tb->Size = System::Drawing::Size(188, 42);
            this->obcb_tb->TabIndex = 16;
            this->obcb_tb->TickFrequency = 50;
            this->obcb_tb->Value = 100;
            this->obcb_tb->Scroll += gcnew System::EventHandler(this, &Form1::obcb_tb_Scroll);
            this->obcb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::obcb_tb_Scroll);
            // 
            // obcb_blabel
            // 
            this->obcb_blabel->AutoSize = true;
            this->obcb_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->obcb_blabel->Location = System::Drawing::Point(337, 100);
            this->obcb_blabel->Name = L"obcb_blabel";
            this->obcb_blabel->Size = System::Drawing::Size(25, 13);
            this->obcb_blabel->TabIndex = 17;
            this->obcb_blabel->Text = L"100";
            // 
            // shininess_label
            // 
            this->shininess_label->AutoSize = true;
            this->shininess_label->Location = System::Drawing::Point(6, 116);
            this->shininess_label->Name = L"shininess_label";
            this->shininess_label->Size = System::Drawing::Size(110, 13);
            this->shininess_label->TabIndex = 48;
            this->shininess_label->Text = L"Material Shininess";
            // 
            // msf_tb
            // 
            this->msf_tb->LargeChange = 10;
            this->msf_tb->Location = System::Drawing::Point(10, 132);
            this->msf_tb->Maximum = 128;
            this->msf_tb->Minimum = 1;
            this->msf_tb->Name = L"msf_tb";
            this->msf_tb->Orientation = System::Windows::Forms::Orientation::Vertical;
            this->msf_tb->Size = System::Drawing::Size(42, 138);
            this->msf_tb->TabIndex = 50;
            this->msf_tb->TickFrequency = 16;
            this->msf_tb->TickStyle = System::Windows::Forms::TickStyle::Both;
            this->msf_tb->Value = 20;
            this->msf_tb->Scroll += gcnew System::EventHandler(this, &Form1::msf_tb_Scroll);
            this->msf_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::msf_tb_Scroll);
            // 
            // msf_label
            // 
            this->msf_label->AutoSize = true;
            this->msf_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->msf_label->Location = System::Drawing::Point(61, 186);
            this->msf_label->Name = L"msf_label";
            this->msf_label->Size = System::Drawing::Size(19, 13);
            this->msf_label->TabIndex = 51;
            this->msf_label->Text = L"20";
            // 
            // objectsettings_gb
            // 
            this->objectsettings_gb->Controls->Add(this->texturing_chb);
            this->objectsettings_gb->Controls->Add(this->smcb_blabel);
            this->objectsettings_gb->Controls->Add(this->smcb_tb);
            this->objectsettings_gb->Controls->Add(this->label33);
            this->objectsettings_gb->Controls->Add(this->smcg_glabel);
            this->objectsettings_gb->Controls->Add(this->smcg_tb);
            this->objectsettings_gb->Controls->Add(this->label35);
            this->objectsettings_gb->Controls->Add(this->smcr_rlabel);
            this->objectsettings_gb->Controls->Add(this->smcr_tb);
            this->objectsettings_gb->Controls->Add(this->label37);
            this->objectsettings_gb->Controls->Add(this->tracking_chb);
            this->objectsettings_gb->Controls->Add(this->matspecular_label);
            this->objectsettings_gb->Controls->Add(this->dmcb_blabel);
            this->objectsettings_gb->Controls->Add(this->dmcb_tb);
            this->objectsettings_gb->Controls->Add(this->label18);
            this->objectsettings_gb->Controls->Add(this->dmcg_glabel);
            this->objectsettings_gb->Controls->Add(this->dmcg_tb);
            this->objectsettings_gb->Controls->Add(this->label20);
            this->objectsettings_gb->Controls->Add(this->dmcr_rlabel);
            this->objectsettings_gb->Controls->Add(this->dmcr_tb);
            this->objectsettings_gb->Controls->Add(this->label30);
            this->objectsettings_gb->Controls->Add(this->matdiffuse_label);
            this->objectsettings_gb->Controls->Add(this->amcb_blabel);
            this->objectsettings_gb->Controls->Add(this->amcb_tb);
            this->objectsettings_gb->Controls->Add(this->label11);
            this->objectsettings_gb->Controls->Add(this->amcg_glabel);
            this->objectsettings_gb->Controls->Add(this->amcg_tb);
            this->objectsettings_gb->Controls->Add(this->label13);
            this->objectsettings_gb->Controls->Add(this->amcr_rlabel);
            this->objectsettings_gb->Controls->Add(this->amcr_tb);
            this->objectsettings_gb->Controls->Add(this->label15);
            this->objectsettings_gb->Controls->Add(this->label16);
            this->objectsettings_gb->Controls->Add(this->mecb_blabel);
            this->objectsettings_gb->Controls->Add(this->mecb_tb);
            this->objectsettings_gb->Controls->Add(this->label2);
            this->objectsettings_gb->Controls->Add(this->mecg_glabel);
            this->objectsettings_gb->Controls->Add(this->mecg_tb);
            this->objectsettings_gb->Controls->Add(this->label6);
            this->objectsettings_gb->Controls->Add(this->mecr_rlabel);
            this->objectsettings_gb->Controls->Add(this->mecr_tb);
            this->objectsettings_gb->Controls->Add(this->label8);
            this->objectsettings_gb->Controls->Add(this->matemission_label);
            this->objectsettings_gb->Controls->Add(this->msf_label);
            this->objectsettings_gb->Controls->Add(this->msf_tb);
            this->objectsettings_gb->Controls->Add(this->shininess_label);
            this->objectsettings_gb->Controls->Add(this->obcb_blabel);
            this->objectsettings_gb->Controls->Add(this->obcb_tb);
            this->objectsettings_gb->Controls->Add(this->label22);
            this->objectsettings_gb->Controls->Add(this->obcg_glabel);
            this->objectsettings_gb->Controls->Add(this->obcg_tb);
            this->objectsettings_gb->Controls->Add(this->label24);
            this->objectsettings_gb->Controls->Add(this->obcr_rlabel);
            this->objectsettings_gb->Controls->Add(this->obcr_tb);
            this->objectsettings_gb->Controls->Add(this->label26);
            this->objectsettings_gb->Controls->Add(this->obc_label);
            this->objectsettings_gb->Controls->Add(this->emission_chb);
            this->objectsettings_gb->Controls->Add(this->materialproperties_label);
            this->objectsettings_gb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->objectsettings_gb->Location = System::Drawing::Point(630, 81);
            this->objectsettings_gb->Name = L"objectsettings_gb";
            this->objectsettings_gb->Size = System::Drawing::Size(591, 273);
            this->objectsettings_gb->TabIndex = 57;
            this->objectsettings_gb->TabStop = false;
            this->objectsettings_gb->Text = L"Object Settings";
            // 
            // texturing_chb
            // 
            this->texturing_chb->AutoSize = true;
            this->texturing_chb->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->texturing_chb->Location = System::Drawing::Point(17, 41);
            this->texturing_chb->Name = L"texturing_chb";
            this->texturing_chb->Size = System::Drawing::Size(70, 17);
            this->texturing_chb->TabIndex = 92;
            this->texturing_chb->Text = L"Texturing";
            this->texturing_chb->UseVisualStyleBackColor = true;
            this->texturing_chb->CheckedChanged += gcnew System::EventHandler(this, &Form1::texturing_chb_CheckedChanged);
            // 
            // smcb_blabel
            // 
            this->smcb_blabel->AutoSize = true;
            this->smcb_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->smcb_blabel->Location = System::Drawing::Point(561, 227);
            this->smcb_blabel->Name = L"smcb_blabel";
            this->smcb_blabel->Size = System::Drawing::Size(25, 13);
            this->smcb_blabel->TabIndex = 91;
            this->smcb_blabel->Text = L"100";
            // 
            // smcb_tb
            // 
            this->smcb_tb->LargeChange = 32;
            this->smcb_tb->Location = System::Drawing::Point(441, 225);
            this->smcb_tb->Maximum = 255;
            this->smcb_tb->Name = L"smcb_tb";
            this->smcb_tb->Size = System::Drawing::Size(125, 42);
            this->smcb_tb->TabIndex = 90;
            this->smcb_tb->TickFrequency = 50;
            this->smcb_tb->Value = 100;
            this->smcb_tb->Scroll += gcnew System::EventHandler(this, &Form1::smcb_tb_Scroll);
            this->smcb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::smcb_tb_Scroll);
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label33->Location = System::Drawing::Point(429, 227);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(14, 13);
            this->label33->TabIndex = 89;
            this->label33->Text = L"B";
            // 
            // smcg_glabel
            // 
            this->smcg_glabel->AutoSize = true;
            this->smcg_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->smcg_glabel->Location = System::Drawing::Point(561, 197);
            this->smcg_glabel->Name = L"smcg_glabel";
            this->smcg_glabel->Size = System::Drawing::Size(25, 13);
            this->smcg_glabel->TabIndex = 88;
            this->smcg_glabel->Text = L"100";
            // 
            // smcg_tb
            // 
            this->smcg_tb->LargeChange = 32;
            this->smcg_tb->Location = System::Drawing::Point(441, 195);
            this->smcg_tb->Maximum = 255;
            this->smcg_tb->Name = L"smcg_tb";
            this->smcg_tb->Size = System::Drawing::Size(125, 42);
            this->smcg_tb->TabIndex = 87;
            this->smcg_tb->TickFrequency = 50;
            this->smcg_tb->Value = 100;
            this->smcg_tb->Scroll += gcnew System::EventHandler(this, &Form1::smcg_tb_Scroll);
            this->smcg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::smcg_tb_Scroll);
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label35->Location = System::Drawing::Point(429, 197);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(15, 13);
            this->label35->TabIndex = 86;
            this->label35->Text = L"G";
            // 
            // smcr_rlabel
            // 
            this->smcr_rlabel->AutoSize = true;
            this->smcr_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->smcr_rlabel->Location = System::Drawing::Point(561, 169);
            this->smcr_rlabel->Name = L"smcr_rlabel";
            this->smcr_rlabel->Size = System::Drawing::Size(25, 13);
            this->smcr_rlabel->TabIndex = 85;
            this->smcr_rlabel->Text = L"100";
            // 
            // smcr_tb
            // 
            this->smcr_tb->LargeChange = 32;
            this->smcr_tb->Location = System::Drawing::Point(441, 165);
            this->smcr_tb->Maximum = 255;
            this->smcr_tb->Name = L"smcr_tb";
            this->smcr_tb->Size = System::Drawing::Size(125, 42);
            this->smcr_tb->TabIndex = 84;
            this->smcr_tb->TickFrequency = 50;
            this->smcr_tb->Value = 100;
            this->smcr_tb->Scroll += gcnew System::EventHandler(this, &Form1::smcr_tb_Scroll);
            this->smcr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::smcr_tb_Scroll);
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label37->Location = System::Drawing::Point(429, 167);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(15, 13);
            this->label37->TabIndex = 83;
            this->label37->Text = L"R";
            // 
            // matspecular_label
            // 
            this->matspecular_label->AutoSize = true;
            this->matspecular_label->Location = System::Drawing::Point(426, 146);
            this->matspecular_label->Name = L"matspecular_label";
            this->matspecular_label->Size = System::Drawing::Size(139, 13);
            this->matspecular_label->TabIndex = 82;
            this->matspecular_label->Text = L"Specular Material Color";
            // 
            // dmcb_blabel
            // 
            this->dmcb_blabel->AutoSize = true;
            this->dmcb_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->dmcb_blabel->Location = System::Drawing::Point(397, 227);
            this->dmcb_blabel->Name = L"dmcb_blabel";
            this->dmcb_blabel->Size = System::Drawing::Size(25, 13);
            this->dmcb_blabel->TabIndex = 81;
            this->dmcb_blabel->Text = L"100";
            // 
            // dmcb_tb
            // 
            this->dmcb_tb->LargeChange = 32;
            this->dmcb_tb->Location = System::Drawing::Point(277, 225);
            this->dmcb_tb->Maximum = 255;
            this->dmcb_tb->Name = L"dmcb_tb";
            this->dmcb_tb->Size = System::Drawing::Size(125, 42);
            this->dmcb_tb->TabIndex = 80;
            this->dmcb_tb->TickFrequency = 50;
            this->dmcb_tb->Value = 100;
            this->dmcb_tb->Scroll += gcnew System::EventHandler(this, &Form1::dmcb_tb_Scroll);
            this->dmcb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::dmcb_tb_Scroll);
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label18->Location = System::Drawing::Point(265, 227);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(14, 13);
            this->label18->TabIndex = 79;
            this->label18->Text = L"B";
            // 
            // dmcg_glabel
            // 
            this->dmcg_glabel->AutoSize = true;
            this->dmcg_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->dmcg_glabel->Location = System::Drawing::Point(397, 197);
            this->dmcg_glabel->Name = L"dmcg_glabel";
            this->dmcg_glabel->Size = System::Drawing::Size(25, 13);
            this->dmcg_glabel->TabIndex = 78;
            this->dmcg_glabel->Text = L"100";
            // 
            // dmcg_tb
            // 
            this->dmcg_tb->LargeChange = 32;
            this->dmcg_tb->Location = System::Drawing::Point(277, 195);
            this->dmcg_tb->Maximum = 255;
            this->dmcg_tb->Name = L"dmcg_tb";
            this->dmcg_tb->Size = System::Drawing::Size(125, 42);
            this->dmcg_tb->TabIndex = 77;
            this->dmcg_tb->TickFrequency = 50;
            this->dmcg_tb->Value = 100;
            this->dmcg_tb->Scroll += gcnew System::EventHandler(this, &Form1::dmcg_tb_Scroll);
            this->dmcg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::dmcg_tb_Scroll);
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label20->Location = System::Drawing::Point(265, 197);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(15, 13);
            this->label20->TabIndex = 76;
            this->label20->Text = L"G";
            // 
            // dmcr_rlabel
            // 
            this->dmcr_rlabel->AutoSize = true;
            this->dmcr_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->dmcr_rlabel->Location = System::Drawing::Point(397, 169);
            this->dmcr_rlabel->Name = L"dmcr_rlabel";
            this->dmcr_rlabel->Size = System::Drawing::Size(25, 13);
            this->dmcr_rlabel->TabIndex = 75;
            this->dmcr_rlabel->Text = L"100";
            // 
            // dmcr_tb
            // 
            this->dmcr_tb->LargeChange = 32;
            this->dmcr_tb->Location = System::Drawing::Point(277, 165);
            this->dmcr_tb->Maximum = 255;
            this->dmcr_tb->Name = L"dmcr_tb";
            this->dmcr_tb->Size = System::Drawing::Size(125, 42);
            this->dmcr_tb->TabIndex = 74;
            this->dmcr_tb->TickFrequency = 50;
            this->dmcr_tb->Value = 100;
            this->dmcr_tb->Scroll += gcnew System::EventHandler(this, &Form1::dmcr_tb_Scroll);
            this->dmcr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::dmcr_tb_Scroll);
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label30->Location = System::Drawing::Point(265, 167);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(15, 13);
            this->label30->TabIndex = 73;
            this->label30->Text = L"R";
            // 
            // matdiffuse_label
            // 
            this->matdiffuse_label->AutoSize = true;
            this->matdiffuse_label->Location = System::Drawing::Point(262, 146);
            this->matdiffuse_label->Name = L"matdiffuse_label";
            this->matdiffuse_label->Size = System::Drawing::Size(129, 13);
            this->matdiffuse_label->TabIndex = 72;
            this->matdiffuse_label->Text = L"Diffuse Material Color";
            // 
            // amcb_blabel
            // 
            this->amcb_blabel->AutoSize = true;
            this->amcb_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->amcb_blabel->Location = System::Drawing::Point(229, 227);
            this->amcb_blabel->Name = L"amcb_blabel";
            this->amcb_blabel->Size = System::Drawing::Size(25, 13);
            this->amcb_blabel->TabIndex = 71;
            this->amcb_blabel->Text = L"100";
            // 
            // amcb_tb
            // 
            this->amcb_tb->LargeChange = 32;
            this->amcb_tb->Location = System::Drawing::Point(109, 225);
            this->amcb_tb->Maximum = 255;
            this->amcb_tb->Name = L"amcb_tb";
            this->amcb_tb->Size = System::Drawing::Size(125, 42);
            this->amcb_tb->TabIndex = 70;
            this->amcb_tb->TickFrequency = 50;
            this->amcb_tb->Value = 100;
            this->amcb_tb->Scroll += gcnew System::EventHandler(this, &Form1::amcb_tb_Scroll);
            this->amcb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::amcb_tb_Scroll);
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label11->Location = System::Drawing::Point(97, 227);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(14, 13);
            this->label11->TabIndex = 69;
            this->label11->Text = L"B";
            // 
            // amcg_glabel
            // 
            this->amcg_glabel->AutoSize = true;
            this->amcg_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->amcg_glabel->Location = System::Drawing::Point(229, 197);
            this->amcg_glabel->Name = L"amcg_glabel";
            this->amcg_glabel->Size = System::Drawing::Size(25, 13);
            this->amcg_glabel->TabIndex = 68;
            this->amcg_glabel->Text = L"100";
            // 
            // amcg_tb
            // 
            this->amcg_tb->LargeChange = 32;
            this->amcg_tb->Location = System::Drawing::Point(109, 195);
            this->amcg_tb->Maximum = 255;
            this->amcg_tb->Name = L"amcg_tb";
            this->amcg_tb->Size = System::Drawing::Size(125, 42);
            this->amcg_tb->TabIndex = 67;
            this->amcg_tb->TickFrequency = 50;
            this->amcg_tb->Value = 100;
            this->amcg_tb->Scroll += gcnew System::EventHandler(this, &Form1::amcg_tb_Scroll);
            this->amcg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::amcg_tb_Scroll);
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label13->Location = System::Drawing::Point(97, 197);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(15, 13);
            this->label13->TabIndex = 66;
            this->label13->Text = L"G";
            // 
            // amcr_rlabel
            // 
            this->amcr_rlabel->AutoSize = true;
            this->amcr_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->amcr_rlabel->Location = System::Drawing::Point(229, 169);
            this->amcr_rlabel->Name = L"amcr_rlabel";
            this->amcr_rlabel->Size = System::Drawing::Size(25, 13);
            this->amcr_rlabel->TabIndex = 65;
            this->amcr_rlabel->Text = L"100";
            // 
            // amcr_tb
            // 
            this->amcr_tb->LargeChange = 32;
            this->amcr_tb->Location = System::Drawing::Point(109, 165);
            this->amcr_tb->Maximum = 255;
            this->amcr_tb->Name = L"amcr_tb";
            this->amcr_tb->Size = System::Drawing::Size(125, 42);
            this->amcr_tb->TabIndex = 64;
            this->amcr_tb->TickFrequency = 50;
            this->amcr_tb->Value = 100;
            this->amcr_tb->Scroll += gcnew System::EventHandler(this, &Form1::amcr_tb_Scroll);
            this->amcr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::amcr_tb_Scroll);
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label15->Location = System::Drawing::Point(97, 167);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(15, 13);
            this->label15->TabIndex = 63;
            this->label15->Text = L"R";
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->Location = System::Drawing::Point(94, 146);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(134, 13);
            this->label16->TabIndex = 62;
            this->label16->Text = L"Ambient Material Color";
            // 
            // mecb_blabel
            // 
            this->mecb_blabel->AutoSize = true;
            this->mecb_blabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->mecb_blabel->Location = System::Drawing::Point(557, 100);
            this->mecb_blabel->Name = L"mecb_blabel";
            this->mecb_blabel->Size = System::Drawing::Size(25, 13);
            this->mecb_blabel->TabIndex = 61;
            this->mecb_blabel->Text = L"100";
            // 
            // mecb_tb
            // 
            this->mecb_tb->LargeChange = 32;
            this->mecb_tb->Location = System::Drawing::Point(393, 98);
            this->mecb_tb->Maximum = 255;
            this->mecb_tb->Name = L"mecb_tb";
            this->mecb_tb->Size = System::Drawing::Size(170, 42);
            this->mecb_tb->TabIndex = 60;
            this->mecb_tb->TickFrequency = 50;
            this->mecb_tb->Value = 100;
            this->mecb_tb->Scroll += gcnew System::EventHandler(this, &Form1::mecb_tb_Scroll);
            this->mecb_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::mecb_tb_Scroll);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(381, 100);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(14, 13);
            this->label2->TabIndex = 59;
            this->label2->Text = L"B";
            // 
            // mecg_glabel
            // 
            this->mecg_glabel->AutoSize = true;
            this->mecg_glabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->mecg_glabel->Location = System::Drawing::Point(557, 70);
            this->mecg_glabel->Name = L"mecg_glabel";
            this->mecg_glabel->Size = System::Drawing::Size(25, 13);
            this->mecg_glabel->TabIndex = 58;
            this->mecg_glabel->Text = L"100";
            // 
            // mecg_tb
            // 
            this->mecg_tb->LargeChange = 32;
            this->mecg_tb->Location = System::Drawing::Point(393, 68);
            this->mecg_tb->Maximum = 255;
            this->mecg_tb->Name = L"mecg_tb";
            this->mecg_tb->Size = System::Drawing::Size(170, 42);
            this->mecg_tb->TabIndex = 57;
            this->mecg_tb->TickFrequency = 50;
            this->mecg_tb->Value = 100;
            this->mecg_tb->Scroll += gcnew System::EventHandler(this, &Form1::mecg_tb_Scroll);
            this->mecg_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::mecg_tb_Scroll);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(381, 70);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(15, 13);
            this->label6->TabIndex = 56;
            this->label6->Text = L"G";
            // 
            // mecr_rlabel
            // 
            this->mecr_rlabel->AutoSize = true;
            this->mecr_rlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->mecr_rlabel->Location = System::Drawing::Point(557, 42);
            this->mecr_rlabel->Name = L"mecr_rlabel";
            this->mecr_rlabel->Size = System::Drawing::Size(25, 13);
            this->mecr_rlabel->TabIndex = 55;
            this->mecr_rlabel->Text = L"100";
            // 
            // mecr_tb
            // 
            this->mecr_tb->LargeChange = 32;
            this->mecr_tb->Location = System::Drawing::Point(393, 38);
            this->mecr_tb->Maximum = 255;
            this->mecr_tb->Name = L"mecr_tb";
            this->mecr_tb->Size = System::Drawing::Size(170, 42);
            this->mecr_tb->TabIndex = 54;
            this->mecr_tb->TickFrequency = 50;
            this->mecr_tb->Value = 100;
            this->mecr_tb->Scroll += gcnew System::EventHandler(this, &Form1::mecr_tb_Scroll);
            this->mecr_tb->ValueChanged += gcnew System::EventHandler(this, &Form1::mecr_tb_Scroll);
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->label8->Location = System::Drawing::Point(381, 40);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(15, 13);
            this->label8->TabIndex = 53;
            this->label8->Text = L"R";
            // 
            // matemission_label
            // 
            this->matemission_label->AutoSize = true;
            this->matemission_label->Location = System::Drawing::Point(378, 19);
            this->matemission_label->Name = L"matemission_label";
            this->matemission_label->Size = System::Drawing::Size(138, 13);
            this->matemission_label->TabIndex = 52;
            this->matemission_label->Text = L"Material Emission Color";
            // 
            // resetall_button
            // 
            this->resetall_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
                static_cast<System::Byte>(0)));
            this->resetall_button->Location = System::Drawing::Point(630, 630);
            this->resetall_button->Name = L"resetall_button";
            this->resetall_button->Size = System::Drawing::Size(117, 30);
            this->resetall_button->TabIndex = 58;
            this->resetall_button->Text = L"Reset all";
            this->resetall_button->UseVisualStyleBackColor = true;
            this->resetall_button->Click += gcnew System::EventHandler(this, &Form1::resetall_button_Click);
            // 
            // resetobject_button
            // 
            this->resetobject_button->Location = System::Drawing::Point(753, 630);
            this->resetobject_button->Name = L"resetobject_button";
            this->resetobject_button->Size = System::Drawing::Size(117, 30);
            this->resetobject_button->TabIndex = 59;
            this->resetobject_button->Text = L"Reset Object";
            this->resetobject_button->UseVisualStyleBackColor = true;
            this->resetobject_button->Click += gcnew System::EventHandler(this, &Form1::resetobject_button_Click);
            // 
            // resetview_button
            // 
            this->resetview_button->Location = System::Drawing::Point(876, 630);
            this->resetview_button->Name = L"resetview_button";
            this->resetview_button->Size = System::Drawing::Size(117, 30);
            this->resetview_button->TabIndex = 60;
            this->resetview_button->Text = L"Reset Viewport";
            this->resetview_button->UseVisualStyleBackColor = true;
            this->resetview_button->Click += gcnew System::EventHandler(this, &Form1::resetview_button_Click);
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1227, 669);
            this->Controls->Add(this->resetview_button);
            this->Controls->Add(this->resetobject_button);
            this->Controls->Add(this->resetall_button);
            this->Controls->Add(this->objectsettings_gb);
            this->Controls->Add(this->close_button);
            this->Controls->Add(this->viewport_gb);
            this->Controls->Add(this->texture_textbox);
            this->Controls->Add(this->texture_button);
            this->Controls->Add(this->statusbar_panel);
            this->Controls->Add(this->mesh_textbox);
            this->Controls->Add(this->mesh_button);
            this->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
            this->Location = System::Drawing::Point(10, 10);
            this->MaximizeBox = false;
            this->MinimumSize = System::Drawing::Size(400, 300);
            this->Name = L"Form1";
            this->Padding = System::Windows::Forms::Padding(1);
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"OpenGL on a Windows Form using MC++ by Vayoush ISBS3 Lap\'top";
            this->statusbar_panel->ResumeLayout(false);
            this->statusbar_panel->PerformLayout();
            this->viewport_gb->ResumeLayout(false);
            this->viewport_gb->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->refrate_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfz_nud))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfy_nud))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->orfx_nud))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ocz_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfz_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfy_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->osfx_tb))->EndInit();
            this->lightsource_gb->ResumeLayout(false);
            this->lightsource_gb->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpz_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpy_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lpx_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcr_tb))->EndInit();
            this->lightswitch_gb->ResumeLayout(false);
            this->lightswitch_gb->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcr_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->obcb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->msf_tb))->EndInit();
            this->objectsettings_gb->ResumeLayout(false);
            this->objectsettings_gb->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->smcr_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dmcr_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->amcr_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecb_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecg_tb))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mecr_tb))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }





#pragma endregion

    private: System::Void render_mesh(System::Object^  sender, System::EventArgs^  e) {
                 state_label->Text = L"Loading..."; state_label->Refresh();
                 char* filename = (char*)(void*)Marshal::StringToHGlobalAnsi(mesh_textbox->Text);
                 current_mesh.reset();

                 int err = current_mesh.read_file(filename);
                 // modification of the state_label to notify the user about the file read
                 switch (err) {
                 case 0 :
                     state_label->Text = L"Mesh has been successfully created from source file.";
                     break;
                 case 1 :
                     state_label->Text = L"ERR01: bad source file read : read operation could not be performed, check file or disk";
                     break;
                 case 2 :
                     state_label->Text = L"ERR02: failed source file read : might be stream corruption or incorrect line formatting, check source file";
                     break;
                 case 3 :
                     state_label->Text = L"ERR03: empty source file : no data, check source file";
                     break;
                 case 4 :
                     state_label->Text = L"ERR04: corrupted source file : adding vertex with negative index(es)";
                     break;
                 case 5:
                     state_label->Text = L"ERR05: corrupted source file : incorrect start-of-line formatting";
                     break;
                 default:
                     state_label->Text = L"ERR: Unknown error occurred (??)";
                 }
                 nodataload_label->Visible = false;
             }
    private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
             {
                 UNREFERENCED_PARAMETER(sender);
                 UNREFERENCED_PARAMETER(e);
                 OpenGL->Render(current_mesh);
                 OpenGL->SwapOpenGLBuffers();
             }
    private: System::Void refrate_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 timer1->Interval = refrate_tb->Value*5;
                 refrate_label->Text = String::Concat( "", refrate_tb->Value*5, " ms" );
                 state_label->Text = L"The viewport render rate has been modified";
             }
    private: System::Void close_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 this->Close();
             }
    private: System::Void resetobject_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 emission_chb->Checked   = false;
                 //shininess_chb->Checked  = true;
                 tracking_chb->Checked   = false;
                 texturing_chb->Checked  = false;
                 obcr_tb->Value = 100; obcg_tb->Value = 100; obcb_tb->Value = 100;
                 mecr_tb->Value = 100; mecg_tb->Value = 100; mecb_tb->Value = 100;
                 amcr_tb->Value = 100; amcg_tb->Value = 100; amcb_tb->Value = 100;
                 dmcr_tb->Value = 100; dmcg_tb->Value = 100; dmcb_tb->Value = 100;
                 smcr_tb->Value = 100; smcg_tb->Value = 100; smcb_tb->Value = 100;
                 msf_tb->Value  = 20;

                 state_label->Text = L"Object parameters have been resetd.";
             }
    private: System::Void resetview_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 light_on_rb->Checked    = false;
                 light_off_rb->Checked   = true;
                 positional_rb->Checked  = false;
                 directional_rb->Checked = true;

                 ambient_chb->Checked    = false;
                 diffuse_chb->Checked    = false;
                 specular_chb->Checked   = false;
                 lcr_tb->Value   = 100; lcg_tb->Value   = 100; lcb_tb->Value   = 100;
                 osfx_tb->Value  = 10;  osfy_tb->Value  = 10;  osfz_tb->Value  = 10;
                 orfx_nud->Value = 0;   orfy_nud->Value = 0;   orfz_nud->Value = 0;
                 lpx_tb->Value   = 20;  lpy_tb->Value   = 20;   lpz_tb->Value  = 20;
                 ocz_tb->Value   = 100;

                 refrate_tb->Value = 20*5;

                 state_label->Text = L"Viewport has been reset.";
             }
    private: System::Void resetall_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 resetobject_button_Click(sender, e);
                 resetview_button_Click(sender, e);

                 current_mesh.reset();
                 nodataload_label->Visible = true;

                 state_label->Text = L"All parameters have been reset, object data has been discarded.";
             }
    private: System::Void mesh_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 openFileDialog1->InitialDirectory = L".";   //%USERPROFILE%
                 openFileDialog1->Filter =
                     L"All text Formats (*.obj)|"
                     L"*.obj";
                 openFileDialog1->FilterIndex = 1;
                 if (System::Windows::Forms::DialogResult::OK == openFileDialog1->ShowDialog()) {}
                 {
                     state_label->Text = L"Loading..."; state_label->Refresh();
                     mesh_textbox->Text=openFileDialog1->FileName;
                     render_mesh(sender,e);
                 }
             }
    private: System::Void mesh_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
             }
    private: System::Void mesh_textbox_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
                 if (e->KeyChar == '\r') //user hits the Enter key
                 {
                     //render_mesh(sender,e);      //hit-enter-key action may be enabled/disabled here
                 }
             }
    private: System::Void texture_button_Click(System::Object^  sender, System::EventArgs^  e) {
                 state_label->Text = L"Loading..."; state_label->Refresh();
                 openFileDialog2->InitialDirectory = L".";
                 openFileDialog2->Filter =
                     L"All image Formats (*.bmp)|"
                     L"*.bmp";
                 openFileDialog2->FilterIndex = 1;
                 if (System::Windows::Forms::DialogResult::OK == openFileDialog2->ShowDialog()) {}
                 {
                     texture_textbox->Text = openFileDialog2->FileName;
                     int e = OpenGL->LoadTexture( (char*)Marshal::StringToHGlobalAnsi(openFileDialog2->FileName).ToPointer() );
                     switch (e) {
                     case 0 : // no error
                         state_label->Text = L"Selected texture has been applied.";
                         break;
                     case 1 :
                         state_label->Text = L"Texture loading error";
                     case 2 : //no new texture, nothing happens
                         break;
                     default :
                         ;
                     }
                 }
             }
    private: System::Void light_on_rb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LSW_b( true );
                 if ( light_on_rb->Checked & 
                      (!diffuse_chb->Checked & !specular_chb->Checked & !ambient_chb->Checked) ) /* if none checked */
                    { ambient_chb->Checked = true; }
                 OpenGL->Set_LGT_Ambi( true );
                 state_label->Text = L"Light has been turned ON.";
             }
    private: System::Void light_off_rb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LSW_b( false );
                 state_label->Text = L"Light has been turned OFF.";
             }

    private: System::Void directional_rb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LT_Dir( true );
                 state_label->Text = L"Light source has been set to Directional.";
             }
    private: System::Void positional_rb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LT_Dir( false );
                 state_label->Text = L"Light source has been set to Positional.";
             }
    private: System::Void ambient_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LGT_Ambi( ambient_chb->Checked );
                 if ( !ambient_chb->Checked & !diffuse_chb->Checked & !specular_chb->Checked )
                    { light_on_rb->Checked  = false;
                      light_off_rb->Checked = true;  }
                 if ( ambient_chb->Checked ) { state_label->Text = L"Ambient lighting has been enabled."; }
                 else { state_label->Text = L"Ambient lighting has been disabled"; }
             }
    private: System::Void diffuse_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LGT_Diff( diffuse_chb->Checked );
                 if ( !ambient_chb->Checked & !specular_chb->Checked )
                    { light_on_rb->Checked  = false;
                      light_off_rb->Checked = true;  }
                 if ( diffuse_chb->Checked ) { state_label->Text = L"Diffuse lighting has been enabled."; }
                 else { state_label->Text = L"Diffuse lighting has been disabled"; }
             }
    private: System::Void specular_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LGT_Spec( specular_chb->Checked );
                 if ( !ambient_chb->Checked & !diffuse_chb->Checked )
                    { light_on_rb->Checked  = false;
                      light_off_rb->Checked = true;  }
                 if ( specular_chb->Checked ) { state_label->Text = L"Specular lighting has been enabled."; }
                 else { state_label->Text = L"Specular lighting has been disabled"; }
             }
    private: System::Void lcr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_GLC_Red( (float)lcr_tb->Value );
                 state_label->Text = L"Light red has been modified";
                 lcred_rlabel->Text = String::Concat( "", lcr_tb->Value );
             }
    private: System::Void lcg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_GLC_Green( (float)lcg_tb->Value );  /* handles the GL value */
                 state_label->Text = L"Light green has been modified";
                 lcgreen_glabel->Text = String::Concat( "", lcg_tb->Value );
             }
    private: System::Void lcb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_GLC_Blue( (float)lcb_tb->Value );  /* handles the GL value */
                 state_label->Text = L"Light blue has been modified";
                 lcblue_blabel->Text = String::Concat( "", lcb_tb->Value );
             }
    private: System::Void lpx_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LP_X( lpx_tb->Value / 10.0f );
                 state_label->Text = L"Light X position has been modified";
                 lpx_xlabel->Text = String::Concat( "", lpx_tb->Value / 10.0f );
             }
    private: System::Void lpy_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LP_Y( lpy_tb->Value / 10.0f );
                 state_label->Text = L"Light Y position has been modified";
                 lpy_ylabel->Text = String::Concat( "", lpy_tb->Value / 10.0f );
             }
    private: System::Void lpz_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_LP_Z( lpz_tb->Value / 10.0f );
                 state_label->Text = L"Light Z position has been modified";
                 lpz_zlabel->Text = String::Concat( "", lpz_tb->Value / 10.0f );
             }
    private: System::Void ocz_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OCZ_f( ocz_tb->Value / 100.0 );     /* handles a double value */
                 state_label->Text = L"Viewport zoom has been modified";
                 ocz_label->Text = String::Concat( "", ocz_tb->Value / 100.0 );
             }
    private: System::Void osfx_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OSF_X( osfx_tb->Value / 10.0f );
                 state_label->Text = L"Stretch factor on X has been modified";
                 osfx_xlabel->Text = String::Concat( "", osfx_tb->Value / 10.0f );
             }
    private: System::Void osfy_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OSF_Y( osfy_tb->Value / 10.0f );
                 state_label->Text = L"Stretch factor on Y has been modified";
                 osfy_ylabel->Text = String::Concat( "", osfy_tb->Value / 10.0f );
             }
    private: System::Void osfz_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OSF_Z( osfz_tb->Value / 10.0f );
                 state_label->Text = L"Stretch factor on Z has been modified";
                 osfz_zlabel->Text = String::Concat( "", osfz_tb->Value / 10.0f );
             }
    private: System::Void orfx_nud_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_ORF_X( (float)orfx_nud->Value );
                 state_label->Text = L"Rotation speed around X has been modified";
             }
    private: System::Void orfy_nud_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_ORF_Y( (float)orfy_nud->Value );
                 state_label->Text = L"Rotation speed around Y has been modified";
             }
    private: System::Void orfz_nud_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_ORF_Z( (float)orfz_nud->Value );
                 state_label->Text = L"Rotation speed around Z has been modified";
             }


    private: System::Void emission_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MP_Emis( emission_chb->Checked );
                 if ( emission_chb->Checked ) { state_label->Text = L"Material emission has been enabled."; }
                 else { state_label->Text = L"Material emission has been disabled."; }
             }
    private: System::Void tracking_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MP_Track( tracking_chb->Checked );
                 if ( tracking_chb->Checked ) { state_label->Text = L"Material base color tracking has been enabled."; }
                 else { state_label->Text = L"Material base color tracking has been disabled."; }
             }
    private: System::Void texturing_chb_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MP_Text( texturing_chb->Checked );
                 if ( texturing_chb->Checked ) { state_label->Text = L"Texturing has been enabled."; }
                 else { state_label->Text = L"Texturing has been disabled."; }
             }
    private: System::Void msf_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MSF_f( msf_tb->Value );
                 state_label->Text = L"Material shininess factor has been modified";
                 msf_label->Text = String::Concat( "", msf_tb->Value );
             }
    private: System::Void mecr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MEC_Red( mecr_tb->Value );
                 state_label->Text = L"Material emission red has been modified";
                 mecr_rlabel->Text = String::Concat( "", mecr_tb->Value );
             }
    private: System::Void mecg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MEC_Green( mecg_tb->Value );
                 state_label->Text = L"Material emission green has been modified";
                 mecg_glabel->Text = String::Concat( "", mecg_tb->Value );
             }
    private: System::Void mecb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_MEC_Blue( mecb_tb->Value );
                 state_label->Text = L"Material emission blue has been modified";
                 mecb_blabel->Text = String::Concat( "", mecb_tb->Value );
             }
    private: System::Void obcr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OBC_Red( obcr_tb->Value );
                 state_label->Text = L"Object base red has been modified";
                 obcr_rlabel->Text = String::Concat( "", obcr_tb->Value );
             }
    private: System::Void obcg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OBC_Green( obcg_tb->Value );
                 state_label->Text = L"Object base green has been modified";
                 obcg_glabel->Text = String::Concat( "", obcg_tb->Value );
             }
    private: System::Void obcb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_OBC_Blue( obcb_tb->Value );
                 state_label->Text = L"Object base blue has been modified";
                 obcb_blabel->Text = String::Concat( "", obcb_tb->Value );
             }
    private: System::Void amcr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_AMC_Red( amcr_tb->Value );
                 state_label->Text = L"Material ambient red has been modified";
                 amcr_rlabel->Text = String::Concat( "", amcr_tb->Value );
             }
    private: System::Void amcg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_AMC_Green( amcg_tb->Value );
                 state_label->Text = L"Material ambient green has been modified";
                 amcg_glabel->Text = String::Concat( "", amcg_tb->Value );
             }
    private: System::Void amcb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_AMC_Blue( amcb_tb->Value );
                 state_label->Text = L"Material ambient blue has been modified";
                 amcb_blabel->Text = String::Concat( "", amcb_tb->Value );
             }
    private: System::Void dmcr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_DMC_Red( dmcr_tb->Value );
                 state_label->Text = L"Material diffuse red has been modified";
                 dmcr_rlabel->Text = String::Concat( "", dmcr_tb->Value );
             }
    private: System::Void dmcg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_DMC_Green( dmcg_tb->Value );
                 state_label->Text = L"Material diffuse green has been modified";
                 dmcg_glabel->Text = String::Concat( "", dmcg_tb->Value );
             }
    private: System::Void dmcb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_DMC_Blue( dmcb_tb->Value );
                 state_label->Text = L"Material diffuse blue has been modified";
                 dmcb_blabel->Text = String::Concat( "", dmcb_tb->Value );
             }
    private: System::Void smcr_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_SMC_Red( smcr_tb->Value );
                 state_label->Text = L"Material specular red has been modified";
                 smcr_rlabel->Text = String::Concat( "", smcr_tb->Value );
             }
    private: System::Void smcg_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_SMC_Green( smcg_tb->Value );
                 state_label->Text = L"Material specular green has been modified";
                 smcg_glabel->Text = String::Concat( "", smcg_tb->Value );
             }
    private: System::Void smcb_tb_Scroll(System::Object^  sender, System::EventArgs^  e) {
                 OpenGL->Set_SMC_Blue( smcb_tb->Value );
                 state_label->Text = L"Material specular blue has been modified";
                 smcb_blabel->Text = String::Concat( "", smcb_tb->Value );
             }
};
}

#endif

