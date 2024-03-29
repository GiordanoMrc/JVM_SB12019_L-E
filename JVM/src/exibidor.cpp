#include "exibidor.hpp"


#define LIST_INSTRUCTIONS(o) \
    o((char*)"aaload",			0,  0x32, 0) \
    o((char*)"aastore" ,		0,  0x53, 0) \
	o((char*)"aconst_null",		0,  0x01, 0) \
	o((char*)"aload",			1,  0x19, 0) \
	o((char*)"aload_0",			0,  0x2a,0) \
	o((char*)"aload_1",			0,  0x2b,0) \
	o((char*)"aload_2",			0,  0x2c,0) \
	o((char*)"aload_3",			0,  0x2d,0) \
	o((char*)"anewarray",		2,  0xbd,0) \
	o((char*)"areturn",			0,  0xb0, 0) \
	o((char*)"arraylength",		0, 0xbe,0 ) \
	o((char*)"astor",			1, 0x3a, 0) \
	o((char*)"astore_0",		0,  0x4b,0) \
	o((char*)"astore_1",		0, 0x4c,0) \
	o((char*)"astore_2",		0, 0x4d,0) \
	o((char*)"astore_3",		0, 0x4e,0) \
	o((char*)"athrow",			0,  0xbf, 0) \
	o((char*)"baload",			0,  0x33, 0) \
	o((char*)"bastore",			0,  0x54, 0) \
	o((char*)"bipush",			1,  0x10,0) \
	o((char*)"caload",			0,  0x34,0) \
	o((char*)"castore",			0,  0x55,0) \
	o((char*)"checkcast",		2,  0xc0,0) \
	o((char*)"d2f",				0, 0x90, 0) \
	o((char*)"d2i",				0, 0x8e, 0) \
	o((char*)"d2l",				0,  0x8f, 0) \
	o((char*)"dadd",			0, 0x63,  0) \
	o((char*)"daload",			0,  0x31,0) \
	o((char*)"dastore",			0, 0x52, 0) \
	o((char*)"dcmpg",			0, 0x98, 0) \
	o((char*)"dcmpl",			0, 0x97, 0) \
	o((char*)"dconst_0",		0,  0x0e,0 ) \
	o((char*)"dconst_1",		0,  0x0f, 0) \
	o((char*)"ddiv",			0,  0x6f, 0) \
	o((char*)"dload",			1,  0x18, 0) \
	o((char*)"dload_0",			0,  0x26 ,0) \
	o((char*)"dload_1",			0,  0x27 ,0) \
	o((char*)"dload_2",			0,  0x28 ,0) \
	o((char*)"dload_3",			0,  0x29 ,0) \
	o((char*)"dmul",			0,  0x6b, 0) \
	o((char*)"dneg",			0,  0x77, 0) \
	o((char*)"drem",			0,  0x73,0 ) \
	o((char*)"dreturn",			0,  0xaf,0 ) \
	o((char*)"dstore",			1,  0x39, 0) \
	o((char*)"dstore_0",		0, 0x47, 0) \
	o((char*)"dstore_1",		0, 0x48, 0) \
	o((char*)"dstore_2",		0, 0x49, 0) \
	o((char*)"dstore_3",		0, 0x4a, 0) \
	o((char*)"dsub",			0,  0x67, 0) \
	o((char*)"dup",				0,  0x59, 0) \
	o((char*)"dup_x1",			0,  0x5a, 0) \
	o((char*)"dup_x2",			0, 0x5b, 0) \
	o((char*)"dup2",			0,  0x5c, 0) \
	o((char*)"dup2_x1",			0,  0x5d,0) \
    o((char*)"dup2_x2",			0,  0x5e,0) \
    o((char*)"f2d",				0,  0x8d,0) \
    o((char*)"f2i",				0,  0x8b,0) \
	o((char*)"f2l",				0,  0x8c,0) \
	o((char*)"fadd",			0,  0x62,0) \
	o((char*)"faload",			0,  0x30,0) \
	o((char*)"fastore",			0,  0x51,0) \
	o((char*)"fcmpg",			0,  0x96,  0) \
	o((char*)"fcmpl>",			0,  0x96, 0) \
	o((char*)"fconst_0",		0,  0x0b,0) \
	o((char*)"fconst_1",		0,  0x0c,0) \
	o((char*)"fconst_2",		0,  0x0d,0) \
	o((char*)"fdiv",			0,  0x6e,0) \
	o((char*)"fload",			1,  0x17,0) \
	o((char*)"fload_0",			0,  0x22,0) \
	o((char*)"fload_1",			0,  0x23,0) \
	o((char*)"fload_2",			0,  0x24, 0) \
	o((char*)"fload_3",			0,  0x25, 0) \
	o((char*)"fmul",			0,  0x6a,0) \
	o((char*)"fneg",			0,  0x76,0) \
	o((char*)"frem",			0,  0x72,0) \
	o((char*)"freturn",			0,  0xae,0) \
	o((char*)"fstore",			1,  0x38,0) \
	o((char*)"fstore_0",		0,  0x43,0) \
	o((char*)"fstore_1",		0,  0x44,0) \
	o((char*)"fstore_2",		0,  0x45,0) \
	o((char*)"fstore_3",		0,  0x46,0) \
	o((char*)"fsub",			0,  0x66, 0) \
	o((char*)"getfield",		2,  0xb4, 0) \
	o((char*)"getstatic",		2,  0xb2, 0) \
	o((char*)"goto",			2,  0xa7, 0) \
    o((char*)"goto_w",			4,  0xc8, 0) \
    o((char*)"i2b",				0, 0x91,0) \
	o((char*)"i2c",				0, 0x92,0) \
	o((char*)"i2d",				0, 0x87,0) \
	o((char*)"i2f",				0, 0x86,0) \
	o((char*)"i2l",				0, 0x85,0) \
	o((char*)"i2s",				0, 0x93,0) \
	o((char*)"iadd",			0, 0x60,0) \
	o((char*)"iaload",			0, 0x2e,0) \
	o((char*)"iand",			0, 0x7e,0) \
	o((char*)"iastore",			0, 0x4f,0) \
	o((char*)"iconst_m1",		0, 0x02,0) \
	o((char*)"iconst_0",		0, 0x03,0) \
	o((char*)"iconst_1",		0, 0x04,0) \
	o((char*)"iconst_2",		0, 0x05,0) \
	o((char*)"iconst_3",		0, 0x06,0) \
	o((char*)"iconst_4",		0, 0x07,0) \
	o((char*)"iconst_5",		0, 0x08,0) \
	o((char*)"idiv",			0, 0x6c,0) \
	o((char*)"if_acmpeq",		2, 0xa5,0) \
	o((char*)"if_acmpne",		2, 0xa6,0) \
	o((char*)"if_icmpeq",		2, 0x9f,0) \
	o((char*)"if_icmpge",		2, 0xa2,0) \
	o((char*)"if_icmpgt",		2, 0xa3,0) \
	o((char*)"if_icmple",		2, 0xa4,0) \
	o((char*)"if_icmplt",		2, 0xa1,0) \
	o((char*)"if_icmpne",		2, 0xa0,0) \
	o((char*)"ifeq",			2, 0x99,0) \
	o((char*)"ifge",			2, 0x9c,0) \
	o((char*)"ifgt",			2, 0x9d,0) \
	o((char*)"ifle",			2, 0x9e,0) \
	o((char*)"iflt",			2, 0x9b,0) \
	o((char*)"ifne",			2, 0x9a,0) \
	o((char*)"ifnonnull",		2, 0xc7,0) \
	o((char*)"ifnull",			2, 0xc6,0) \
	o((char*)"iload",			1, 0x15,0) \
	o((char*)"iload_0",			0, 0x1a,0) \
	o((char*)"iload_1",			0, 0x1b,0) \
	o((char*)"iload_2",			0, 0x1c,0) \
	o((char*)"iload_3",			0, 0x1d,0) \
	o((char*)"imul",			0, 0x68,0) \
	o((char*)"ineg",			0, 0x74,0) \
	o((char*)"instanceof",		2, 0xc1,0) \
	o((char*)"invokedynamic",	4, 0xba,0) \
	o((char*)"invokespecial",	2, 0xb7,0) \
	o((char*)"invokestatic",	2, 0xb8,0) \
	o((char*)"invokevirtual",	2, 0xb6,0) \
	o((char*)"ior",				0, 0x80,0) \
	o((char*)"irem",			0, 0x70,0) \
	o((char*)"ireturn",			0, 0xac,0) \
	o((char*)"ishl",			0, 0x78,0) \
	o((char*)"ishr",			0, 0x7a,0) \
	o((char*)"istore",			1, 0x36,0) \
	o((char*)"istore_0",		0, 0x3b,0) \
	o((char*)"istore_1",		0, 0x3c,0) \
	o((char*)"istore_2",		0, 0x3d,0) \
	o((char*)"istore_3",		0, 0x3e,0) \
	o((char*)"isub",			0, 0x64,0) \
	o((char*)"iushr",			0, 0x7c,0) \
	o((char*)"ixor",			0, 0x82,0) \
	o((char*)"jsr",				2, 0xa8,0) \
	o((char*)"jsr_w",			4, 0xc9,0) \
	o((char*)"l2d",				0, 0x8a,0) \
	o((char*)"l2f",				0, 0x89,0) \
	o((char*)"l2i",				0, 0x88,0) \
	o((char*)"ladd",			0, 0x61,0) \
	o((char*)"laload",			0, 0x2f,0) \
	o((char*)"land",			0, 0x7f,0) \
	o((char*)"lastore",			0, 0x50,0) \
	o((char*)"lcmp",			0, 0x94,0) \
	o((char*)"lconst_0",		0, 0x09,0) \
	o((char*)"lconst_1",		0, 0x0a,0) \
	o((char*)"ldc",				1, 0x12,0) \
	o((char*)"ldc_w",			2, 0x13,0) \
	o((char*)"ldc2_w",			2, 0x14,0) \
	o((char*)"ldiv",			0, 0x6d,0) \
	o((char*)"lload",			1, 0x16,0) \
	o((char*)"lload_0",			0, 0x1e,0) \
	o((char*)"lload_1",			0, 0x1f,0) \
	o((char*)"lload_2",			0, 0x20,0) \
	o((char*)"lload_3",			0, 0x21,0) \
	o((char*)"lmul",			0, 0x69,0) \
	o((char*)"lneg",			0, 0x75,0) \
	o((char*)"new",				2, 0xbb,0) \
	o((char*)"nop",				0, 0x00,0) \
	o((char*)"pop",				0, 0x57,0) \
	o((char*)"lor",				0, 0x81,0) \
	o((char*)"lrem",			0, 0x71,0) \
	o((char*)"lreturn",			0, 0xad,0) \
	o((char*)"lshl",			0, 0x79,0) \
	o((char*)"lshr",			0, 0x7b,0) \
	o("lstore",					1, 0x37,0) \
	o("lstore_0",				0, 0x3f,0) \
	o("lstore_1",				0, 0x40,0) \
	o("lstore_2",				0, 0x41,0) \
	o("lstore_3",				0, 0x42,0) \
	o("lsub",					0, 0x65,0) \
	o("lushr",					0, 0x7d,0) \
	o("lxor",					0, 0x83,0) \
	o("monitorenter",			0, 0xc2,0) \
	o("monitorexit",			0, 0xc3,0) \
	o("putfield",				2, 0xb5,0) \
	o("putstatic",				2, 0xb3,0) \
	o("pop2",					0, 0x58,0) \
	o("ret",					1, 0xa9,0) \
	o("return",					0, 0xb1,0) \
	o("saload",					0, 0x35,0) \
	o("sastore",				0, 0x56,0) \
	o("sipush",					2, 0x11,0) \
	o("swap",					0, 0x5f,0)


void (*screen_print_function[256])(u1*, int*);
void print_attributes(attribute_info* ai, cp_info *cp);
void print_CodeAttribute(attribute_info* ai, cp_info* cp);
void print_ConstantAttribute(attribute_info* ai, cp_info* cp);
void print_ExceptionsAttibute(attribute_info* ai, cp_info* cp);

void Printer::showClassFile(ClassFile cf) {
    Screen_Initialize_screen_print_functions();
    print_magic(cf);
    print_minor_version(cf);
    print_major_version(cf);
    print_cpool_count(cf);
    print_access_flags(cf);
    print_this_class(cf);
    print_super_class(cf);
    print_fields_count(cf);
    print_methods_count(cf);
    print_interfaces_count(cf);
    print_attributes_count(cf);

    print_constant_pool(cf);
    print_interfaces(cf);
    print_fields(cf);
    print_methods(cf);
}

void get_Access_Flag_Field1(u2 flag){

    if(flag&1){
        std::cout << "public ";
    }

    if((flag>>1)&0x0001){
        std::cout << "private ";
    }

    if((flag>>2)&0x0001){
        std::cout << "protected ";
    }

    if((flag>>3)&0x0001){
        std::cout << "static ";
    }

    if((flag>>4)&0x0001){
        std::cout << "final ";
    }

    if((flag>>6)&0x0001){
        std::cout << "volatile ";
    }

    if((flag>>7)&0x0001){
        std::cout << "transient ";
    }

    if((flag>>13)&0x0001){
        std::cout << "synthetic ";
    }

    if((flag>>14)&0x0001){
        std::cout << "enum ";
    }
}

void get_Access_Flag_Field2(u2 flag){
    bool imprimiu = false;


    if(flag&1){
        std::cout << "ACC_PUBLIC";
        imprimiu = true;
    }

    if((flag>>1)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PRIVATE";
        imprimiu = true;
    }

    if((flag>>2)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PROTECTED";
        imprimiu = true;
    }

    if((flag>>3)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STATIC";
        imprimiu = true;
    }

    if((flag>>4)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_FINAL";
        imprimiu = true;
    }

    if((flag>>6)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_VOLATILE";
        imprimiu = true;
    }

    if((flag>>7)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_TRANSIENT";
        imprimiu = true;
    }

    if((flag>>13)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNTHETIC";
        imprimiu = true;
    }

    if((flag>>14)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_ENUM";
        imprimiu = true;
    }
}

void Printer::print_fields(ClassFile cf){
    printf("\n--------------------++>>Fields\n");
    for(int i=0; i<cf.fields_count; i++){
        field_info field = (cf.fields[i]);

        get_Access_Flag_Field1(field.access_flags);
        getIndex_Utf8_Ref(cf.constant_pool, field.name_index);
        std::cout << std::endl;

        std::cout << "     descriptor: ";

        getIndex_Utf8_Ref(cf.constant_pool, field.descriptor_index);
        std::cout << std::endl;


        std::cout << "     flags: ";

        get_Access_Flag_Field2(field.access_flags);
        std::cout << std::endl;


        for (int i = 0; i < field.attributes_count; i++) {
            std::cout << "Attribute " << i+1 << std::endl;

			print_attributes(field.attributes + i, cf.constant_pool);
		}
		std::cout << std::endl;

    }printf("\n--------------------++>>Fields\n");
}
void Printer::print_magic(ClassFile cf) {
    std::cout << "Magic: \t";
    std::cout << std::hex << std::showbase << cf.magic << std::endl;
}

void Printer::print_minor_version(ClassFile cf) {
    std::cout << "Minor Version: \t";
    std::cout << std::dec << cf.minor_version << std::endl;
}

void Printer::print_major_version(ClassFile cf) {
    std::cout << "Major Version: \t";
    std::cout << std::dec << cf.major_version << std::endl;
}

void Printer::print_cpool_count(ClassFile cf) {
    std::cout << "Constant Pool Count: \t";
    std::cout << std::dec << cf.cp_count << std::endl;
}

void Printer::print_access_flags(ClassFile cf) {
    std::cout << "Access Flags: \t";
    std::cout << std::hex << std::showbase << cf.access_flags << " ";
    std::cout << "[";
    if (cf.access_flags & AccessFlags::PUBLIC) {
        std::cout << " public ";
    }
    if (cf.access_flags >> 1 & AccessFlags::FINAL >> 1) {
        std::cout << " final ";
    }
    if (cf.access_flags >> 1 & AccessFlags::SUPER >> 1) {
        std::cout << " super ";
    }
    if (cf.access_flags >> 2 & AccessFlags::INTERFACE >> 2) {
        std::cout << " interface ";
    }
    if (cf.access_flags & AccessFlags::ABSTRACT) {
        std::cout << " abstract ";
    }
    if (cf.access_flags & AccessFlags::SYNTHETIC) {
        std::cout << " synthetic ";
    }
    if (cf.access_flags & AccessFlags::ANNOTATION) {
        std::cout << " annotation ";
    }
    if (cf.access_flags & AccessFlags::ENUM) {
        std::cout << " enum ";
    }
    std::cout << "]";
    std::cout << std::endl;
}

void Printer::print_this_class(ClassFile cf) {
    int cp_info_index = cf.this_class;
    int name_index =
        cf.constant_pool[cp_info_index].info.class_info.name_index - 1;
    char *thisName = (char *)cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "This class: \t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
    std::cout << "<" << thisName << ">" << std::endl;
}

void Printer::print_super_class(ClassFile cf) {
    int cp_info_index = cf.super_class;
    if (cp_info_index == 0) {
        std::cout << "Super class: \t";
        std::cout << "cp_info #-1";
        std::cout << "<Object>" << std::endl;
        return;
    }
    int name_index = cf.constant_pool[cp_info_index].info.class_info.name_index;
    char *thisName = (char *)cf.constant_pool[name_index].info.utf8_info.bytes;
    std::cout << "Super class: \t";
    std::cout << "cp_info #";
    std::cout << std::dec << cp_info_index;
    std::cout << "<" << thisName << ">>" << std::endl;
}

void Printer::print_interfaces_count(ClassFile cf) {
    std::cout << "Interfaces: \t";
    std::cout << std::dec << cf.interfaces_count << std::endl;
}

void Printer::print_interfaces(ClassFile cf) {
    if (cf.interfaces_count > 0) {
        printf("\n--------------------++>>Interfaces:\n");
        for (int i = 0; i < cf.interfaces_count; i++) {
            std::cout << "Interface " << i << ":" << std::endl;
            std::cout << cf.interfaces[i] << std::endl;
            getIndex_Utf8_Ref(cf.constant_pool, *(cf.interfaces+i));
        }
    }
}

void Printer::print_fields_count(ClassFile cf) {
    std::cout << "Fields: \t";
    std::cout << std::dec << cf.fields_count << std::endl;
}

void Printer::print_methods_count(ClassFile cf) {
    std::cout << "Methods: \t";
    std::cout << std::dec << cf.methods_count << std::endl;
}
void get_Access_Flag_Method1(u2 flag){
    bool imprimiu = false;


    if(flag&1){
        std::cout << "ACC_PUBLIC";
        imprimiu = true;
    }

    if((flag>>1)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PRIVATE";
        imprimiu = true;
    }

    if((flag>>2)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_PROTECTED";
        imprimiu = true;
    }

    if((flag>>3)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STATIC";
        imprimiu = true;
    }

    if((flag>>4)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_FINAL";
        imprimiu = true;
    }

    if((flag>>5)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNCHRONIZED";
        imprimiu = true;
    }

    if((flag>>6)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_BRIDGE";
        imprimiu = true;
    }

    if((flag>>7)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_VARARGS";
        imprimiu = true;
    }

    if((flag>>8)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_NATIVE";
        imprimiu = true;
    }

    if((flag>>9)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_ABSTRACT";
        imprimiu = true;
    }

    if((flag>>10)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_STRICT";
        imprimiu = true;
    }

    if((flag>>11)&0x0001){
        if(imprimiu){
            std::cout << ", ";
        }
        std::cout << "ACC_SYNTHETIC";
        imprimiu = true;
    }
}

void get_Access_Flag_Method2(u2 flag){

    if(flag&1){
        std::cout << "public ";
    }

    if((flag>>1)&0x0001){
        std::cout << "private ";
    }

    if((flag>>2)&0x0001){
        std::cout << "protected ";
    }

    if((flag>>3)&0x0001){
        std::cout << "static ";
    }

    if((flag>>4)&0x0001){
        std::cout << "final ";
    }

    if((flag>>5)&0x0001){
        std::cout << "synchronized ";
    }

    if((flag>>6)&0x0001){
        std::cout << "bridge ";
    }

    if((flag>>7)&0x0001){
        std::cout << "varargs ";
    }

    if((flag>>8)&0x0001){
        std::cout << "native ";
    }

    if((flag>>9)&0x0001){
        std::cout << "abstract ";
    }

    if((flag>>10)&0x0001){
        std::cout << "strict ";
    }

    if((flag>>11)&0x0001){
        std::cout << "synthetic ";
    }
}


void Printer::print_methods(ClassFile cf)
{
    printf("\n--------------------++>>Methods\n");
    for(u2 i = 0; i < cf.methods_count; i++)
    {
        method_info method = (cf.methods[i]);

        get_Access_Flag_Method2(method.access_flags);
        getIndex_Utf8_Ref(cf.constant_pool, method.name_index);
        std::cout << std::endl;

        std::cout << "     descriptor: ";

        getIndex_Utf8_Ref(cf.constant_pool, method.descriptor_index);
        std::cout << std::endl;


        std::cout << "     flags: ";

        get_Access_Flag_Method1(method.access_flags);
        std::cout << std::endl;

        for (int i = 0; i < method.attributes_count; i++) {
            print_attributes(method.attributes + i, cf.constant_pool);
        }
    }printf("\n--------------------++>>Methods\n");
}
void Printer::print_attributes_count(ClassFile cf) {
    std::cout << "Attributes: \t";
    std::cout << std::dec << cf.attributes_count << std::endl;
}

void getIndex_Utf8_Ref(cp_info *constant_pool, u2 index) {
    cp_info *cp = constant_pool + index - 1;
    float aux = 0;

    if (cp->tag == 1) {
        std::cout << cp->info.utf8_info.bytes;
    } else {
        switch (cp->tag) {
            case (ConstantPoolTags::CONSTANT_Float):
                memcpy(&aux, &(cp->info.float_info.bytes), sizeof(float));
                std::cout << aux;
                break;
            case (ConstantPoolTags::CONSTANT_Class):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.class_info.name_index);
                break;
            case (ConstantPoolTags::CONSTANT_Fieldref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.fieldref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.fieldref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_Methodref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_NameAndType):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.nameandtype_info.name_index);
                std::cout << ".";
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.nameandtype_info.descriptor_index);
                break;
            case (ConstantPoolTags::CONSTANT_String):
                getIndex_Utf8_Ref(constant_pool,
                                  (u2)cp->info.string_info.string_index);
                break;
            case (ConstantPoolTags::CONSTANT_InterfaceMethodref):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.interfacemethodref_info.class_index);
                std::cout << ".";
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.interfacemethodref_info.name_and_type_index);
                break;
            case (ConstantPoolTags::CONSTANT_MethodHandle):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodhandle_info.reference_index);
                break;
            case (ConstantPoolTags::CONSTANT_MethodType):
                getIndex_Utf8_Ref(constant_pool,
                                  cp->info.methodtype_info.descriptor_index);
                break;
            case (ConstantPoolTags::CONSTANT_InvokeDynamic):
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.invokedynamic_info.bootstrap_method_attr_index);
                getIndex_Utf8_Ref(
                    constant_pool,
                    cp->info.invokedynamic_info.name_and_type_index);
                break;
            default:
                break;
        }
    }
}

void Printer::print_constant_pool(ClassFile cf) {
    printf("\n--------------------++>>CONSTANT POOL\n");
    u1 tag;
    //u8 long_v, double_v;
    for (int i = 0; i < cf.cp_count - 1; i++) {
        tag = cf.constant_pool[i].tag;
        switch (tag) {
            case ConstantPoolTags::CONSTANT_Class:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Class\t"
                          << "name_index: #"
                          << cf.constant_pool[i].info.class_info.name_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.class_info.name_index);
                break;
            case ConstantPoolTags::CONSTANT_Fieldref:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Fieldref\t"
                          << "class_index: #"
                          << cf.constant_pool[i].info.fieldref_info.class_index
                          << "\tname_and_type_index: #"
                          << cf.constant_pool[i]
                                 .info.fieldref_info.name_and_type_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.fieldref_info.class_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.fieldref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_Methodref:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Methodref_info\t"
                          << "class_index: #"
                          << cf.constant_pool[i].info.methodref_info.class_index
                          << "\tname_and_type_index: #"
                          << cf.constant_pool[i]
                                 .info.methodref_info.name_and_type_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.methodref_info.class_index);
                getIndex_Utf8_Ref(cf.constant_pool,
                                  cf.constant_pool[i]
                                      .info.methodref_info.name_and_type_index);
                break;
            case ConstantPoolTags::CONSTANT_InterfaceMethodref:
                std::cout
                    << "{" << i + 1 << "}"
                    << "CONSTANT_InterfaceMethodref_info\t"
                    << "class_index: #"
                    << cf.constant_pool[i]
                           .info.interfacemethodref_info.class_index
                    << "\tname_and_type_index: #"
                    << cf.constant_pool[i]
                           .info.interfacemethodref_info.name_and_type_index
                    << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i]
                        .info.interfacemethodref_info.class_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i]
                        .info.interfacemethodref_info.name_and_type_index);
                break;

            case ConstantPoolTags::CONSTANT_String:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_String_info\t"
                          << "string_index: #"
                          << cf.constant_pool[i].info.string_info.string_index
                          << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.string_info.string_index);
                break;
            case ConstantPoolTags::CONSTANT_Integer:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Integer_info\t"
                          << "bytes: "
                          << (u4)cf.constant_pool[i].info.integer_info.bytes;
                break;
            case ConstantPoolTags::CONSTANT_Float:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Float:\t";

                float aux;
                memcpy(&aux, &(cf.constant_pool[i].info.float_info.bytes), sizeof(float));
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Float:\t"
                          << aux
                          << std::endl;
                //printf("\tbytes: 0x%08x",
                //       cf.constant_pool[i].info.float_info.bytes);
                //printf("\tfloat: %.2f",
                //       *(float *)&cf.constant_pool[i].info.float_info.bytes);
                break;

            case ConstantPoolTags::CONSTANT_Long:
                long auxl;
                memcpy(&auxl, &(cf.constant_pool[i].info.long_info.value), sizeof(long));

                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Long:\t"
                          << auxl
                          << std::endl;
                /**printf("\thigh_bytes: %u",
                       cf.constant_pool[i].info.long_info.high_bytes);
                printf("\tlow_bytes: %u",
                       cf.constant_pool[i].info.long_info.low_bytes);
                long_v =
                    ((u8)cf.constant_pool[i].info.long_info.high_bytes << 32) |
                    cf.constant_pool[i].info.long_info.low_bytes;
                printf("long: %ld", (long)long_v);*/
                break;

            case ConstantPoolTags::CONSTANT_Double:
                double auxd;
                memcpy(&auxd, &(cf.constant_pool[i].info.double_info.value), sizeof(double));
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Double:\t"
                          << auxd
                          << std::endl;


                /*printf("\thigh_bytes: %u",
                       cf.constant_pool[i].info.double_info.high_bytes);
                printf("\tlow_bytes: %u",
                       cf.constant_pool[i].info.double_info.low_bytes);
                double_v = ((u8)cf.constant_pool[i].info.double_info.high_bytes
                            << 32) |
                           cf.constant_pool[i].info.double_info.low_bytes;
                printf("double: %.2f", *(double *)&double_v);*/

                break;

            case ConstantPoolTags::CONSTANT_NameAndType:
                std::cout
                    << "{" << i + 1 << "}"
                    << "CONSTANT_NameAndType\t"
                    << "name_index: "
                    << cf.constant_pool[i].info.nameandtype_info.name_index
                    << "\tdescriptor_index:"
                    << cf.constant_pool[i]
                           .info.nameandtype_info.descriptor_index
                    << " \t//";
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.nameandtype_info.name_index);
                getIndex_Utf8_Ref(
                    cf.constant_pool,
                    cf.constant_pool[i].info.nameandtype_info.descriptor_index);
                break;
            case ConstantPoolTags::CONSTANT_Utf8:
                std::cout << "{" << i + 1 << "}"
                          << "CONSTANT_Utf8\t"
                          << cf.constant_pool[i].info.utf8_info.bytes;
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }
    printf("\n--------------------++>>CONSTANT POOL\n");
}
/*
void Printer::print_attributes(ClassFile cf) {
    std::cout << "########################\n### Class Attributes "
                 "###\n########################"
              << std::endl;
    std::cout << "Count: " << std::dec << cf.attributes_count << std::endl
              << std::endl;
    for (int i = 0; i < cf.attributes_count; i++) {
        print_attribute(cf, cf.attributes[i], i);
    }
}

int get_info_attribute_type(CONSTANT_Utf8_info info) {
    string name = string((char *)info.bytes);
    if (name == "SourceFile") {
        return InfoAttributeType::SourceFile;
    };
    return InfoAttributeType::NotReconized;
}

void print_attribute(ClassFile cf, attribute_info attr, int index) {
    attribute_info info;
    u1 info_attribute_type;
    cp_info cp;
    for (u1 i = 0; i < attr.attribute_length; i++) {
        info = attr.info[i];
        info_attribute_type = get_info_attribute_type(
            cf.constant_pool[info.attribute_name_index].info.utf8_info);
        // Index
        std::cout << "{" << std::dec << (u4)i << "} \t";
        // Info
        switch (info_attribute_type) {
            case InfoAttributeType::SourceFile:
                cp = cf.constant_pool[info.sourceFile_attribute
                                          .sourcefile_index];
                std::cout << "SourceFile" << endl;
                std::cout << "Generic Info:" << endl;
                std::cout << "\tAttribute name index:\t"
                          << "cp_info#" << std::dec << attr.attribute_name_index
                          << endl;
                std::cout << "\tAttribute length:\t" << attr.attribute_length
                          << endl;
                std::cout << "Specific Info:" << endl;
                std::cout << "\tSource File name index: " << std::dec
                          << info.sourceFile_attribute.sourcefile_index;
                std::cout << "<" << cp.info.utf8_info.bytes << ">" << endl;
                break;
            default:
                cout << "Not Reconized" << endl;
                break;
        }
    }
}*/

void print_CodeAttribute(attribute_info *ai, cp_info * cp){
    std::cout << "stack=" << ai->info.code_info.max_stack << ", locals=" << ai->info.code_info.max_locals
              << "\t// Code length: " << ai->info.code_info.code_length << std::endl;

	for (int i = 0; (u4) i < ai->info.code_info.code_length; i++) {
		screen_print_function[ai->info.code_info.code[i]](ai->info.code_info.code, &i);
	}

	std::cout << std::endl << std::endl << "Exception table length: " << ai->info.code_info.exception_table_length << std::endl;
	for (int i = 0; i < ai->info.code_info.exception_table_length; i++) {
        std::cout << "	start_pc: " << (ai->info.code_info.exception_table + i)->start_pc << std::endl;
        std::cout << "	end_pc: " << (ai->info.code_info.exception_table + i)->end_pc << std::endl;
		std::cout << "	handler_pc: " << (ai->info.code_info.exception_table + i)->handler_pc << std::endl;
		std::cout << "	catch_type: " << (ai->info.code_info.exception_table + i)->catch_type << std::endl;
	}

    std::cout << "Attributes count " << ai->info.code_info.attributes_count << std::endl;

	for (int i = 0; i < ai->info.code_info.attributes_count; i++) {
		print_attributes(ai->info.code_info.attributes + i, cp);
	}
}

void print_ConstantAttribute(attribute_info* ai, cp_info* cp) {
    std::cout << "Constant Value: #" << ai->info.constantValue_Info.constantvalue_index;
    switch(cp[ai->info.constantValue_Info.constantvalue_index-1].tag){
        case(8):
            std::cout << cp[ai->info.constantValue_Info.constantvalue_index-1].info.utf8_info.bytes << std::endl;
            break;
        case(3):
            std::cout << "\t\t" << cp[ai->info.constantValue_Info.constantvalue_index-1].info.integer_info.bytes << std::endl;
            break;
        case (4):{
            float aux = 0;
            memcpy(&aux, &((cp + ai->info.constantValue_Info.constantvalue_index - 1)->info.float_info.bytes), sizeof(float));
            std::cout << " "<< aux << std::endl;
            break;
        }
        case(5):
            std::cout << "\t\t\t"<< (cp[ai->info.constantValue_Info.constantvalue_index-1].info.long_info.value) << std::endl;
            break;
        case(6):{
            double aux = 0;
            memcpy(&aux, &(cp[ai->info.constantValue_Info.constantvalue_index-1].info.double_info.value), sizeof(double));
            std::cout << " "<< aux << std::endl;
            break;
        }
    }
}

void print_ExceptionsAttibute(attribute_info* ai, cp_info* cp) {
    std::cout << "Number of Exceptions: " << ai->info.exceptions_info.number_of_exceptions << std::endl;

    for (int i = 0; i < ai->info.exceptions_info.number_of_exceptions; i++)
    {
        std::cout << "	Index: " << ai->info.exceptions_info.exceptions_index_table[i] << std::endl;
	}
}

void print_LineNumberTableAttribute(attribute_info* ai, cp_info* cp){
    std::cout << "  Table length: " << ai->info.lineNumberTable_info.line_number_table_length << std::endl;
    for (int i = 0; i < ai->info.lineNumberTable_info.line_number_table_length; i++)
    {
        std::cout << "     Line " << i << "->\t" << ai->info.lineNumberTable_info.lineTable[i].start_pc << ": "
                  << ai->info.lineNumberTable_info.lineTable[i].line_number << std::endl;
    }
	std::cout << std::endl;
}

void print_LocalVariableTableAttribute(attribute_info* ai, cp_info* cp){
    std::cout << "	Table length: " << ai->info.localVariableTable_info.local_variable_table_length << std::endl;
	std::cout << "N	|	Start_PC	|	Length	|	Name_Index	|	Descriptor_Index	|	Index	|" << std::endl;
    for (int i = 0; i < ai->info.lineNumberTable_info.line_number_table_length; i++)
    {
        std::cout << i << "	|	"
                  << (ai->info.localVariableTable_info.local_table + i)->start_pc << "		|	"
                  << (ai->info.localVariableTable_info.local_table + i)->length << "	|	"
                  << (ai->info.localVariableTable_info.local_table + i)->name_index << "		|	"
                  << (ai->info.localVariableTable_info.local_table + i)->descriptor_index << "			|	"
                  << (ai->info.localVariableTable_info.local_table + i)->index << "	|" << std::endl;
	}
	std::cout << std::endl;
}

void print_InnerClassesAttribute(attribute_info* ai, cp_info* cp){
    std::cout << "	Number of Classes: " << ai->info.innerClasses_attribute_info.number_of_classes << std::endl;
    for (int i = 0; i < ai->info.innerClasses_attribute_info.number_of_classes; i++)
    {
        std::cout << "		" << (ai->info.innerClasses_attribute_info.classes + i)->inner_class_info_index << std::endl;
        std::cout << "		" << (ai->info.innerClasses_attribute_info.classes + i)->outer_class_info_index << std::endl;
		std::cout << "		" << (ai->info.innerClasses_attribute_info.classes + i)->inner_name_index << std::endl;
		std::cout << "		" << (ai->info.innerClasses_attribute_info.classes + i)->inner_class_access_flags << std::endl;
	}
}

void print_SourceFileAttribute(attribute_info* ai, cp_info* cp){
    std::cout << "	SourceFile index: #" << ai->info.sourceFile_attribute.sourcefile_index << " ";

    getIndex_Utf8_Ref(cp, ai->info.sourceFile_attribute.sourcefile_index);
    std::cout << std::endl;

}

void Printer::Screen_Initialize_screen_print_functions(){
	#define o(mnemonic,operands,opcode, todo) \
		screen_print_function[opcode] = [](u1* code, int* index){ \
			int64_t var = 0; \
			int line_number = *index; \
			for(int j = 0; j < operands; j++){ \
				var = (var<<8) | code[++(*index)]; \
			} \
			switch(operands){ \
			case (1): \
				if((var&0x80)>>7 == 1) var|=0xffffffffffffff00; \
				break; \
			case (2): \
				if((var&0x8000)>>15 == 1) var|=0xffffffffffff0000; \
				break; \
			case (4): \
				if((var&0x80000000)>>15 == 1) var|=0xffffffff00000000; \
				break; \
			case (8): \
				break; \
			} \
			std::cout << line_number << ":   " << mnemonic << ", " << var << std::endl; \
		};
		LIST_INSTRUCTIONS(o)
#undef o
	screen_print_function[0x84] = [](u1* code, int* index){
                    u2 codeI = 0;
                    std::cout << *index << ":   iinc, ";
					(*index)++;
					codeI = code[(*index)];
					std::cout << codeI << ", " ;
					(*index)++;
					codeI = code[(*index)];
					std::cout << codeI << " " << std::endl;
				};

	screen_print_function[0xb9] = [](u1* code, int* index = 0){
                    std::cout << *index << ":   invokeinterface, ";

					int16_t indexa = 0;

					(*index)++;
					indexa = code[(*index)]<<8;
					(*index)++;
					indexa += code[(*index)];
					(*index)++;
					u2 codeI = code[(*index)];
					std::cout << indexa << ", " << codeI << std::endl;

                    (*index)++;
				};
	screen_print_function[0xab] = [](u1* code, int* index){
                int line_number = *index;
				while ((*index) % 4 != 0)
					++(*index);
				u4 default_byte = 0;
				(*index)++;
				default_byte = ((code[(*index)]) << 24);
				(*index)++;
                default_byte += ((code[(*index)]) << 16);
                (*index)++;
                default_byte += ((code[(*index)]) << 8);
                (*index)++;
                default_byte += (code[(*index)]);
                (*index)++;

				u4 npairs = 0;
				(*index)++;
				npairs = ((code[(*index)]) << 24);
				(*index)++;
				npairs += ((code[(*index)]) << 16);
				(*index)++;
				npairs += ((code[(*index)]) << 8);
				(*index)++;
				npairs+= (code[(*index)]);

				std::cout <<  line_number << ": lookupswitch, " << default_byte << ", " << npairs << std::endl;


				for (u4 k = 0; k < npairs; k++) {
					u4 key = 0;
					(*index)++;
					key = ((code[(*index)]) << 24);
					(*index)++;
					key += ((code[(*index)]) << 16);
					(*index)++;
					key += ((code[(*index)]) << 8);
					(*index)++;
					key += (code[(*index)]);

					u4 value = 0;
					(*index)++;
					value = ((code[(*index)]) << 24);
					(*index)++;
					value += ((code[(*index)]) << 16);
					(*index)++;
					value += ((code[(*index)]) << 8);
					(*index)++;
					value += (code[(*index)]);

                    std::cout << "(key: " << key << ", value: " << value << ")" << std::endl;

				}
			};
    screen_print_function[0xc5] = [](u1* code, int* index){
                std::cout << *index << ":   multinewarray ";

				u2 indexa = 0;
				u2 codeI = 0;
				(*index)++;
				indexa = ((code[(*index)])<<8);
				(*index)++;
				indexa += (code[(*index)]);
				(*index)++;

				codeI = (code[(*index)]);
				std::cout << indexa << " , " << codeI << std::endl;

	};
	screen_print_function[0xbc] = [](u1* code, int* index){
                std::cout << *index << ":	newarray ";

				(*index)++;
				int8_t type = (code[(*index)]);
				switch (type){
				case 4:
				    std::cout << "T_BOOLEAN" << std::endl;

					break;
				case 5:
				    std::cout << "T_CHAR" << std::endl;

					break;
				case 6:
				    std::cout << "T_FLOAT" << std::endl;

					break;
				case 7:
					std::cout << "T_DOUBLE" << std::endl;

					break;
				case 8:
				    std::cout << "T_BYTE" << std::endl;

					break;
				case 9:
				    std::cout << "T_SHORT" << std::endl;

					break;
				case 10:
				    std::cout << "T_INT" << std::endl;

					break;
				case 11:
				    std::cout << "T_LONG" << std::endl;

					break;
				}
	};

	screen_print_function [0xaa] = [](u1* code, int* index) {
                int line_number = *index;
				while (*index % 4 != 0)
					++(*index);
				u4 default_byte = 0;
				(*index)++;
				default_byte = ((code[(*index)]) << 24);
				(*index)++;
				default_byte += ((code[(*index)]) << 16);
				(*index)++;
				default_byte +=((code[(*index)]) << 8);
				(*index)++;
				default_byte +=(code[(*index)]);

                (*index)++;
				int32_t high = ((code[++(*index)]) << 24);
				(*index)++;
				high += ((code[++(*index)]) << 16);
				(*index)++;
				high += ((code[++(*index)]) << 8);
				(*index)++;
				high += (code[++(*index)]);

                (*index)++;
				int32_t low = ((code[(*index)])<< 24);
				(*index)++;
				low += ((code[(*index)]) << 16);
				(*index)++;
				low += ((code[(*index)]) << 8);
				(*index)++;
				low += (code[(*index)]);

				std::cout << line_number << ":	tableswitch " << default_byte << ", " << high << ", " << low << std::endl;


				for (int k = 0; k < high-low+1; k++) {
                    (*index)++;
					u4 offset = ((code[(*index)])<< 24);
					(*index)++;
					offset += ((code[(*index)]) << 16);
					(*index)++;
					offset += ((code[(*index)]) << 8);
					(*index)++;
					offset += (code[(*index)]);

					std::cout << "offset: " << offset << std::endl;

				}
			};

			screen_print_function[0xc4] = [](u1* code, int* index){
			    std::cout << *index << ": wide ";

				(*index)++;
				u1 op = (code[(*index)]);
				if (op == 0x84) {
                    u2 arg1 = 0, arg2 = 0;
                    (*index)++;
                    arg1 = ((code[(*index)])<< 8);
                    (*index)++;
                    arg1 += ((code[(*index)]));

                    (*index)++;
					arg2 = ((code[(*index)]) << 8);
					(*index)++;
					arg2 += (code[(*index)]);
					std::cout << "iinc " << arg1 << ", " << arg2 << std::endl;

				}
				else {
				    (*index)++;
				    u2 arg1 = ((code[(*index)]) << 8);
				    (*index)++;
                    arg1 += (code[++(*index)])  ;
					std::cout << "opcode " << std::hex << op << std::dec << ", " << arg1 << std::endl;

				}
			};

}
#define screen_print_functionS(printtype) \
printype("ConstantValue", print_ConstantAttribute(ai, cp))\
printype("Code", print_CodeAttribute(ai, cp))\
printype("Exceptions", print_ExceptionsAttibute(ai, cp))\
printype("LineNumberTable", print_LineNumberTableAttribute(ai, cp))\
printype("LocalVariableTable", print_LocalVariableTableAttribute(ai, cp))\
printype("InnerClasses", print_InnerClassesAttribute(ai, cp))\
printype("SourceFile", print_SourceFileAttribute(ai, cp))


void print_attributes(attribute_info* ai, cp_info* cp) {
        char type[100];
        strcpy(type, (char*)cp[ai->attribute_name_index -1].info.utf8_info.bytes);
        std::cout << type << ":\t//Attribute length: " << ai->attribute_length << std::endl;

#define printype(name,function) if(strcmp(name,type)==0) { function; }
	screen_print_functionS(printype)
#undef printype
}
