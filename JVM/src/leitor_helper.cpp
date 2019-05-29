#include "leitor_helper.hpp"

void read_attribute(std::ifstream &file, ClassFile *cf,
                    attribute_info *attribute) {
    readt_u2(&attribute->attribute_name_index, file, 1);
    readt_u4(&attribute->attribute_length, file, 1);
    attribute->info = (info_attribute *)malloc(sizeof(info_attribute) *
                                               attribute->attribute_length);
    for (u1 k = 0; k < attribute->attribute_length; k++) {
        read_info_attribute(file, cf, &attribute->info[k]);
    }
}

void read_info_attribute(std::ifstream &file, ClassFile *cf,
                         info_attribute *info) {
    readt_u2(&info->attribute_name_index, file, 1);
    readt_u4(&info->attribute_length, file, 1);

    cp_info cp = cf->constant_pool[correct_index(info->attribute_name_index)];
    int jump;
    switch (get_info_attribute_type(cp.info.utf8_info)) {
        case InfoAttributeType::SourceFile:
            readt_u2(&info->info.sourceFile.sourcefile_index, file, 1);
            break;
        default:
            // Not reconized
            jump = file.tellg() + (long int)info->attribute_length;
            file.seekg(jump);
            break;
    }
}

int get_info_attribute_type(CONSTANT_Utf8_info info) {
    std::string name = std::string((char *)info.bytes);
    if (name == "SourceFile") {
        return InfoAttributeType::SourceFile;
    };
    return InfoAttributeType::NotReconized;
}
