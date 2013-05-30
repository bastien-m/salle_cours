void charger_image(int* id, const char* fichier)
{
    glGenTextures(1,id);
    glBindTexture(GL_TEXTURE_2D,*id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    gl_texture_t* tex = ReadTGAFile(fichier);
    glTexImage2D(GL_TEXTURE_2D,0,tex->internalFormat,tex->width,tex->height,0,tex->format,GL_UNSIGNED_BYTE,tex->texels);
    free(tex->texels);
    free(tex);
    glBindTexture(GL_TEXTURE_2D,0);
}