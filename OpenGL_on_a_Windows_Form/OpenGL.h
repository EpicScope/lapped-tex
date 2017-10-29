#pragma once

#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "mesh.h"

using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System;

namespace OpenGLForm 
{
    public ref class COpenGL: public System::Windows::Forms::NativeWindow
    {

        /*-- Variables --*/
    private:
        GLfloat vx;                       /* rotation acceleration on X */
        GLfloat vy;                       /* rotation acceleration on Y */
        GLfloat vz;                       /* rotation acceleration on Z */

    private:
        HDC         m_hDC;
        HGLRC       m_hglrc;
        GLfloat     rtrix;             /* Angle on the X axis */
        GLfloat     rtriy;             /* Angle on the Y axis */
        GLfloat     rtriz;             /* Angle on teh Z axis */   
        GLdouble    zoom;              /* field of view factor, i.e. zoom */

        bool        texturing;         /* texture activation switch */
        bool        light;             /* light switch */     
        bool        ambient;           /* ambient material switch */
        bool        diffuse;           /* diffuse material switch */
        bool        specular;          /* specular material switch */
        bool        emission;          /* emission material switch */
        bool        shininess;         /* shininess material switch */
        bool        tracking;          /* color tracking switch */

        GLfloat*    mat_color;         /* object base color vector */
        GLfloat*    mat_ambient;       /* ambient material color vector */
        GLfloat*    mat_diffuse;       /* diffuse material color vector */
        GLfloat*    mat_specular;      /* specular material color vector */
        GLfloat*    mat_emission;      /* emission material color vector */    
        GLint       mat_shininess;     /* material shininess */

        GLfloat*    light_ambient;     /* ambient light color vector */
        GLfloat*    light_diffuse;     /* diffuse light color vector */
        GLfloat*    light_specular;    /* specular light color vector */
        GLfloat*    light_position;    /* light source coordinates */
        GLfloat*    light_off;         /* color set when no light is emitted */

        GLfloat*    stretch;           /* (x,y,z) stretch factors */

        char*       tex_path;          /* texture path (C-style string) */
        GLubyte*    tex_data;          /* texture data (RGBRGBRGB...) format */
        GLuint      tex_width;         /* texture image width */
        GLuint      tex_height;        /* texture image height */
        GLuint*     tex_name;          /* texture name ID pointer */


    public:

        /*== Parameters set functions ==*/

        /*-- Light and material colors : range from 0.0 to 1.0 --*/

        /* Global Light Color : physical light sources do not have
        different ambient, diffuse and specular lighting colors    */
        void Set_GLC_Red(   float _v ) { light_ambient[0]  = _v/255.0f;
                                         light_diffuse[0]  = _v/255.0f;
                                         light_specular[0] = _v/255.0f;  }
        void Set_GLC_Green( float _v ) { light_ambient[1]  = _v/255.0f;
                                         light_diffuse[1]  = _v/255.0f;
                                         light_specular[1] = _v/255.0f;  }
        void Set_GLC_Blue(  float _v ) { light_ambient[2]  = _v/255.0f;
                                         light_diffuse[2]  = _v/255.0f;
                                         light_specular[2] = _v/255.0f;  }

        /* Ambient Light color */
        void Set_ALC_Red(   float _v ) { light_ambient[0]  = _v/255.0f;  }
        void Set_ALC_Green( float _v ) { light_ambient[1]  = _v/255.0f;  }
        void Set_ALC_Blue(  float _v ) { light_ambient[2]  = _v/255.0f;  }

        /* Diffuse Light Color */
        void Set_DLC_Red(   float _v ) { light_diffuse[0]  = _v/255.0f;  }
        void Set_DLC_Green( float _v ) { light_diffuse[1]  = _v/255.0f;  }
        void Set_DLC_Blue(  float _v ) { light_diffuse[2]  = _v/255.0f;  }

        /* Specular Light Color */                           
        void Set_SLC_Red(   float _v ) { light_specular[0] = _v/255.0f;  }
        void Set_SLC_Green( float _v ) { light_specular[1] = _v/255.0f;  }
        void Set_SLC_Blue(  float _v ) { light_specular[2] = _v/255.0f;  }

        /* Object Base Color */
        void Set_OBC_Red(   float _v ) { mat_color[0]      = _v/255.0f;  }
        void Set_OBC_Green( float _v ) { mat_color[1]      = _v/255.0f;  }
        void Set_OBC_Blue(  float _v ) { mat_color[2]      = _v/255.0f;  }

        /* Ambient Material Color */
        void Set_AMC_Red(   float _v ) { mat_ambient[0]    = _v/255.0f;  }
        void Set_AMC_Green( float _v ) { mat_ambient[1]    = _v/255.0f;  }
        void Set_AMC_Blue(  float _v ) { mat_ambient[2]    = _v/255.0f;  }

        /* Diffuse Material Color */
        void Set_DMC_Red(   float _v ) { mat_diffuse[0]    = _v/255.0f;  }
        void Set_DMC_Green( float _v ) { mat_diffuse[1]    = _v/255.0f;  }
        void Set_DMC_Blue(  float _v ) { mat_diffuse[2]    = _v/255.0f;  }

        /* Specular Material Color */
        void Set_SMC_Red(   float _v ) { mat_specular[0]   = _v/255.0f;  }
        void Set_SMC_Green( float _v ) { mat_specular[1]   = _v/255.0f;  }
        void Set_SMC_Blue(  float _v ) { mat_specular[2]   = _v/255.0f;  }


        /*-- Material parameters --*/

        /* Material Emission Color */
        void Set_MEC_Red(   float _v ) { mat_emission[0]   = _v/255.0f;  }
        void Set_MEC_Green( float _v ) { mat_emission[1]   = _v/255.0f;  }
        void Set_MEC_Blue(  float _v ) { mat_emission[2]   = _v/255.0f;  }

        /* Material Shininess Factor */
        void Set_MSF_f(     int   _v ) { mat_shininess     = _v;         }


        /*-- Light and material switches --*/

        /* Light Position */
        void Set_LP_X(      float _v ) { light_position[0] = _v;         }
        void Set_LP_Y(      float _v ) { light_position[1] = _v;         }  
        void Set_LP_Z(      float _v ) { light_position[2] = _v;         }

        /* Lighting Type */
        void Set_LGT_Ambi(  bool  _b ) { ambient           = _b;         }
        void Set_LGT_Diff(  bool  _b ) { diffuse           = _b;         }
        void Set_LGT_Spec(  bool  _b ) { specular          = _b;         }

        /* Material Properties */
        void Set_MP_Emis(   bool  _b ) { emission          = _b;         }
        void Set_MP_Shin(   bool  _b ) { shininess         = _b;         }
        void Set_MP_Text(   bool  _b ) { texturing         = _b;         }
        void Set_MP_Track(  bool  _b ) { tracking          = _b;         }


        /*-- Viewport parameters --*/

        /* Light Switch */
        void Set_LSW_b(     bool _b ) { light              = _b;         }

        /* Light Type : true=directional=0, false=positional=1*/
        void Set_LT_Dir(    bool  b ) { light_position[3]=(b?0.0f:1.0f); }
        
        /* Object Rotation Factor*/
        void Set_ORF_X(     float _v ) { vx               = _v;          }
        void Set_ORF_Y(     float _v ) { vy               = _v;          }
        void Set_ORF_Z(     float _v ) { vz               = _v;          }

        /* Object Camera Zoom */
        void Set_OCZ_f(     float _v ) { zoom             = _v;          }

        /* Object Stretch Factor */
        void Set_OSF_X(     float _v ) { stretch[0]       = _v;          }
        void Set_OSF_Y(     float _v ) { stretch[1]       = _v;          }
        void Set_OSF_Z(     float _v ) { stretch[2]       = _v;          }


        /*== Texture management functions ==*/

        /*-- Function reads a bitmap texture --*/
        int ReadTexture(char * s)
        {
            String ^systemstring = gcnew String(s);
            Bitmap Bmp(systemstring);
            tex_width  = (GLuint)Bmp.Width;
            tex_height = (GLuint)Bmp.Height;
            tex_data = new GLubyte[3*tex_width*tex_height]; //unsigned bytes (0-255)
            for (unsigned int x = 0 ; x < tex_width ; x++)
                for (unsigned int y = 0 ; y < tex_height ; y++)
                {
                    System::Drawing::Color p = Bmp.GetPixel(x,y);
                    int pos = 3*(x + y*tex_width);
                    tex_data[pos] = (GLubyte)p.R;
                    tex_data[pos+1] = (GLubyte)p.G;
                    tex_data[pos+2] = (GLubyte)p.B;
                }
            delete systemstring;
            return 0;
        }


        /*-- Function loads a new texture in --*/
        int LoadTexture(char * _s) {
            delete[] tex_data;
            tex_width = 0; tex_height = 0;

            tex_path = _s;
            int e = ReadTexture(_s);
            //TODO: warn if size x & y other than 64, 128, 256
            glTexImage2D (
                GL_TEXTURE_2D,          //Type
                0,                      //No mipmap
                3,                      //Color components per pixel
                tex_width,              //Width
                tex_height,             //Height
                0,                      //Border width
                GL_RGB,                 //Format : RGB
                GL_UNSIGNED_BYTE,       //Color type
                tex_data                //Image data
                );
            return e;
        }


        /*-- Viewport Constructor --*/
        COpenGL(System::Windows::Forms::Form ^ parentForm, GLsizei iWidth, GLsizei iHeight, GLsizei iX, GLsizei iY)
        {
            CreateParams^ cp = gcnew CreateParams;

            // Set the position on the form
            cp->X = iX;
            cp->Y = iY;
            cp->Height = iHeight;
            cp->Width = iWidth;

            // Specify the form as the parent.
            cp->Parent = parentForm->Handle;

            // Create as a child of the specified parent and make OpenGL compliant (no clipping)
            cp->Style = WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN;

            // Create the actual window
            this->CreateHandle(cp);

            m_hDC = GetDC((HWND)this->Handle.ToPointer());

            /* parameter variables initialisation */
                              
            vx             = 0.0f;              /* no X rotation by default */
            vy             = 0.0f;              /* no Y rotation by default */
            vz             = 0.0f;              /* no Z rotation by default */
            rtrix          = 0.0f;              /* no X rotation by default */
            rtriy          = 0.0f;              /* no X rotation by default */
            rtriz          = 0.0f;              /* no X rotation by default */
            zoom           = 1.0;               /* zoom factor to 1 by default */

            light          = false; 
            ambient        = false;             /* ambient light is disabled by default */
            diffuse        = false;             /* diffuse light is disabled by default */
            specular       = false;             /* specular light is disabled by default */
            emission       = false;             /* material emission is disabled by default */
            shininess      = true;              /* material shininess is enabled by default */
            texturing      = false;             /* texturing is disabled by default */
            tracking       = false;             /* tracking is disabled by default */

            mat_color      = new GLfloat[4];   /* material vertexes color */
            mat_ambient    = new GLfloat[4];   /* material ambient color */
            mat_diffuse    = new GLfloat[4];   /* material diffuse color */
            mat_specular   = new GLfloat[4];   /* material specular color */ 
            mat_emission   = new GLfloat[4];   /* material emission color */

            light_ambient  = new GLfloat[4];   /* light ambient color */  
            light_diffuse  = new GLfloat[4];   /* light diffuse color */
            light_specular = new GLfloat[4];   /* light specular color */
            light_position = new GLfloat[4];   /* light positioning in space */
            light_off      = new GLfloat[4];   /* light off means no colors */

            stretch        = new GLfloat[3];   /* (x,y,z) stretch factors */

            tex_path = ""  ;                   /* no texture at first */
            tex_name = new GLuint;             /* name ID initialised later */

            if(m_hDC)
            {
                wglMakeCurrent(m_hDC, NULL);
                if (MySetPixelFormat(m_hDC))
                {
                    ReSizeGLScene(iWidth, iHeight);
                    InitGL();
                }
            }
        }


        /*-- Viewport display function --*/
        System::Void Render(Mesh& m)
        {
            VMPoint centre = m.get_gravity(); // retrieves gravity center of the mesh

            /* texture bidinding */
            if ( texturing && !(*tex_name == 0) )      // if texture enabled and name exists (texture id not 0)
            {
                /* GL_MIPMAPS and OpenGL-operated te xturing has been integrated in v1.4 and is not available
                   on Windows environments, since the version used is stuck at v1.1 : use of an extension 
                   such as GLee or GLEW would be needed, which is not the point here */
                glEnable( GL_TEXTURE_2D ); // enable opengl texturing
                glBindTexture( GL_TEXTURE_2D, *tex_name );
                glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR ); /* texture binding model
                                                                                     for magnification */
                glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR  ); /* texture binding model 
                                                                                   for minification */
            }
            else { glDisable( GL_TEXTURE_2D ); }

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* Clear screen and depth buffer */
            glLoadIdentity();                                   /* Reset the current modelview matrix */

            glTranslatef( (float)centre.getx(),
                          (float)centre.gety(),
                          (float)centre.getz()-2 );             /* Move to gravity point as (0,0,0) */

            if (light) { glLightfv( GL_LIGHT0, GL_POSITION, light_position ); } /* set light position */
            /* to achieve a fixed light and a rotating mesh, the light is set before the mesh rotation */

            /* setting the user-defined properties using the switches */
            if (ambient)   { glMaterialfv( GL_FRONT_AND_BACK, GL_AMBIENT  , mat_ambient   ); }
            if (diffuse)   { glMaterialfv( GL_FRONT_AND_BACK, GL_DIFFUSE  , mat_diffuse   ); }
            if (specular)  { glMaterialfv( GL_FRONT_AND_BACK, GL_SPECULAR , mat_specular  ); }
            if (emission)  { glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION , mat_emission  ); }
            else           { glMaterialfv( GL_FRONT_AND_BACK, GL_EMISSION , light_off     ); }
            if (shininess) { glMateriali(  GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess ); }

            if ( tracking ) {
                glColorMaterial( GL_FRONT_AND_BACK, GL_DIFFUSE     ); /* take the object base color
                                               into account for diffuse lighting (takes precedence) */
                glEnable(        GL_COLOR_MATERIAL                 ); /* Enable color tracking : */
            }

            /* rotating the mesh according to user-defined arameters */
            glRotatef(  rtrix,      1.0f,       0.0f, 0.0f );   /* Rotate on the x axis */
            glRotatef(  rtriy,      0.0f,       1.0f, 0.0f );   /* Rotate on the y axis */
            glRotatef(  rtriz,      0.0f,       0.0f, 1.0f );   /* Rotate on the z axis */
            glScalef(   stretch[0], stretch[1], stretch[2] );   /* Object stretching */
            glColor3fv( mat_color );                            /* Object base color */

            VMFacet f;                                          /* loop current facet */
            double X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3;          /* loop current vertexes coordinates */
            GLfloat n[3];                                       /* loop current normal coordinates and length */

            /* drawing the mesh triangles */
            glBegin( GL_TRIANGLES );
                int taille = m.f_count();// loop facet
                for (int i=0; i<m.f_count(); i++) 
                {
                    /* copy of the current facet */
                    f=m.get_facet(i);

                    /* vertexes coordinates */
                    X1 = m.get_point(f.getx()-1).getx();
                    Y1 = m.get_point(f.getx()-1).gety();
                    Z1 = m.get_point(f.getx()-1).getz();
                    X2 = m.get_point(f.gety()-1).getx();
                    Y2 = m.get_point(f.gety()-1).gety();
                    Z2 = m.get_point(f.gety()-1).getz();
                    X3 = m.get_point(f.getz()-1).getx();
                    Y3 = m.get_point(f.getz()-1).gety();
                    Z3 = m.get_point(f.getz()-1).getz();

                    /* normal processing */
                    n[0] = ( (Y1-Y2) *  (Z2-Z3)) - ( (Z1-Z2) *  (Y2-Y3));
                    n[1] = ( (Z1-Z2) *  (X2-X3)) - ( (X1-X2) *  (Z2-Z3));
                    n[2] = ( (X1-X2) *  (Y2-Y3)) - ( (Y1-Y2) *  (X2-X3));

                    /* setting facet normal for light reflection */
                    glNormal3f( n[0], n[1], n[2] );

                    /* setting facet vertexes */
                    if (texturing) {glTexCoord2f((float)Math::Atan(Z1*Z1/(X1*X1+Y1*Y1))+Math::Log(1+X1*X1+Y1*Y1+Z1*Z1),
                                                 (float)Math::Atan(Y2/X2)+Math::Log(1+X1*X1+Y1*Y1+Z1*Z1));}
                    glVertex3d( X1, Y1, Z1 );
                    if (texturing) {glTexCoord2f((float)Math::Atan(Z2*Z2/(X2*X2+Y2*Y2))+Math::Log(1+X2*X2+Y2*Y2+Z2*Z2),
                                                 (float)Math::Atan(Y2/X2)+Math::Log(1+X2*X2+Y2*Y2+Z2*Z2));}
                    glVertex3d( X2, Y2, Z2 );
                    if (texturing) {glTexCoord2f((float)Math::Atan(Z3*Z3/(X3*X3+Y3*Y3))+Math::Log(1+X3*X3+Y3*Y3+Z3*Z3),
                                                 (float)Math::Atan(Y3/X3)+Math::Log(1+X3*X3+Y3*Y3+Z3*Z3));}
                    glVertex3d( X3, Y3, Z3 );

                } // Done drawing the mesh facets
            glEnd(); //GL_TRIANGLES

            rtrix+=vx;     /* Increase the rotation variables for the triangle */
            rtriy+=vy;
            rtriz+=vz;

            /* texture (end) */
            glDisable(GL_TEXTURE_2D);

            /* zooming */
            /* 70 is the human solid angle, viewport ratio is 1 */
            GLfloat r     = 1.0f;                       /* viewport ratio */
            GLint   zNear = +1;                         /* near clipping plane */
            GLint   zFar  = +1000;                      /* far clipping plane */
            glMatrixMode(GL_PROJECTION);              /* change matrix stack to projection (eye) */
            glLoadIdentity();                           /* reset projection matrix */
            gluPerspective(zoom*70, r, zNear, zFar);  /* set perspective projection */
            glMatrixMode(GL_MODELVIEW);               /* change back to object stack */


            /* set the light parameters */
            if (light) 
            {
                glEnable( GL_LIGHT0 );     /* switch light 0 ON */

                if (ambient)  { glLightfv( GL_LIGHT0, GL_AMBIENT,  light_ambient  ); }
                else          { glLightfv( GL_LIGHT0, GL_AMBIENT,  light_off      ); }
                if (diffuse)  { glLightfv( GL_LIGHT0, GL_DIFFUSE,  light_diffuse  ); }
                else          { glLightfv( GL_LIGHT0, GL_DIFFUSE,  light_off      ); }
                if (specular) { glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular ); }
                else          { glLightfv( GL_LIGHT0, GL_SPECULAR, light_off      ); }
                /* light position has been set before rotating the object so as to be fixed */
            }
            else
            {
                glDisable( GL_LIGHT0 );     /* switch light 0 OFF */
            }
        }

        System::Void SwapOpenGLBuffers(System::Void)
        {
            SwapBuffers(m_hDC) ;
        }

        /*-- Destructor --*/
    protected:
        ~COpenGL(System::Void)
        {
            delete[] mat_color;
            delete[] light_diffuse; delete[] light_ambient; delete[] light_specular;
            delete[] mat_diffuse; delete[] mat_ambient;
            delete[] mat_specular; delete[] mat_emission;
            delete[] light_position; delete[] light_off; delete[] stretch;
            delete[] tex_data; delete[] tex_path; delete[] tex_name;
            this->DestroyHandle();
        }

        GLint MySetPixelFormat(HDC hdc)
        {
            static	PIXELFORMATDESCRIPTOR pfd=              // pfd Tells Windows How We Want Things To Be
            {
                sizeof(PIXELFORMATDESCRIPTOR),              // Size Of This Pixel Format Descriptor
                1,                                          // Version Number
                PFD_DRAW_TO_WINDOW |                        // Format Must Support Window
                PFD_SUPPORT_OPENGL |                        // Format Must Support OpenGL
                PFD_DOUBLEBUFFER,                           // Must Support Double Buffering
                PFD_TYPE_RGBA,                              // Request An RGBA Format
                24,                                         // Select Our Color Depth
                0, 0, 0, 0, 0, 0,							// Color Bits Ignored
                0,											// No Alpha Buffer
                0,											// Shift Bit Ignored
                0,											// No Accumulation Buffer
                0, 0, 0, 0,									// Accumulation Bits Ignored
                32,											// 16Bit Z-Buffer (Depth Buffer)  
                0,											// No Stencil Buffer
                0,											// No Auxiliary Buffer
                PFD_MAIN_PLANE,								// Main Drawing Layer
                0,											// Reserved
                0, 0, 0										// Layer Masks Ignored
            };

            GLint  iPixelFormat; 

            // get the device context's best, available pixel format match 
            if((iPixelFormat = ChoosePixelFormat(hdc, &pfd)) == 0)
            {
                MessageBox::Show("ChoosePixelFormat Failed");
                return 0;
            }

            // make that match the device context's current pixel format 
            if(SetPixelFormat(hdc, iPixelFormat, &pfd) == FALSE)
            {
                MessageBox::Show("SetPixelFormat Failed");
                return 0;
            }

            if((m_hglrc = wglCreateContext(m_hDC)) == NULL)
            {
                MessageBox::Show("wglCreateContext Failed");
                return 0;
            }

            if((wglMakeCurrent(m_hDC, m_hglrc)) == NULL)
            {
                MessageBox::Show("wglMakeCurrent Failed");
                return 0;
            }


            return 1;
        }

        bool InitGL(GLvoid)                                           /* All setup for opengl goes here */
        {   
            /* parameters and color matrices intialization */
            float v= 100.0f/256.0f; //initial obc GL
            light_ambient[0]  = v; light_ambient[1]  = v;  light_ambient[2]  = v;  light_ambient[3]  = 1.0;
            light_diffuse[0]  = v; light_diffuse[1]  = v;  light_diffuse[2]  = v;  light_diffuse[3]  = 1.0;
            light_specular[0] = v; light_specular[1] = v;  light_specular[2] = v;  light_specular[3] = 1.0;
            mat_color[0]      = v; mat_color[1]      = v;  mat_color[2]      = v;  mat_color[3]      = 0.5;
            mat_ambient[0]    = v; mat_ambient[1]    = v;  mat_ambient[2]    = v;  mat_ambient[3]    = 1.0;
            mat_diffuse[0]    = v; mat_diffuse[1]    = v;  mat_diffuse[2]    = v;  mat_diffuse[3]    = 1.0;
            mat_specular[0]   = v; mat_specular[1]   = v;  mat_specular[2]   = v;  mat_specular[3]   = 1.0;
            mat_emission[0]   = v; mat_emission[1]   = v;  mat_emission[2]   = v;  mat_emission[3]   = 1.0;
            mat_shininess     = 20;  /* material shininess is taken into account in specular lighting */
            stretch[0]        = 1.0;  stretch[1]        = 1.0f; stretch[2]        = 1.0f;      
            /* light set to directional by default : */
            light_position[0] = 2.0f; light_position[1] = 2.0f; light_position[2] = 2.0f; light_position[3] = 1.0f;
            light_off[0]      = 0.0f; light_off[1]      = 0.0f; light_off[2]      = 0.0f; light_off[3]      = 1.0f;

            tex_data  = NULL; tex_path   = NULL;
            tex_width = 0;    tex_height = 0;
            *tex_name = 0;    //texture ID


            glClearDepth(  1.0f                                );     /* Depth buffer setup */
            glEnable(      GL_DEPTH_TEST                       );     /* Enables depth testing */
            glEnable(      GL_LIGHTING                         );     /* turn ON light power */
            glShadeModel(  GL_SMOOTH                           );     /* Enable smooth shading */
            glClearColor(  0.0f, 0.0f, 0.0f, 0.0f              );     /* Black background */  
            glEnable(      GL_NORMALIZE                        );     /* Normalize facets normals: manual 
                                                normalization should be is less computationally expensive */
            glLightModeli( GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE    );     /* enable twoside lighting */
            glDepthFunc(   GL_LEQUAL                           );     /* The type of depth testing to do */
            glHint(        GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST ); /* Really nice perspective calculations */
            glEnable(      GL_TEXTURE_2D                       );     /* Enable texture for texture loading */
            glGenTextures( 1, tex_name);                              /* Generate 1 texture number */
            glTexEnvf(     GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); /* Mix light color with texture */
            glPixelStorei( GL_UNPACK_ALIGNMENT, 1);                   /* avoid 4-by-4 bytes read */
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT ); /* texture repeating */
            glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );

            //glLightModelfv( GL_LIGHT_MODEL_AMBIENT, ambient_light   );    /* use general model */

            return TRUE;										// Initialisation went ok
        }

        GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize and initialise the gl window
        {
            if (height==0)										// Prevent A Divide By Zero By
            {
                height=1;										// Making Height Equal One
            }

            glViewport(0,0,width,height);						// Reset The Current Viewport

            glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
            glLoadIdentity();									// Reset The Projection Matrix

            // Calculate The Aspect Ratio Of The Window
            gluPerspective( 45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f );

            glMatrixMode( GL_MODELVIEW );							// Select The Modelview Matrix
            glLoadIdentity();									// Reset The Modelview Matrix
        }
    };
}




