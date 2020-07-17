#ifndef PROJECT_KAPPA_INDEX_BUFFER_H
#define PROJECT_KAPPA_INDEX_BUFFER_H


class IndexBuffer {
public:
    IndexBuffer(unsigned int capacity);
    ~IndexBuffer();

    void bind() const;
    void unbind() const;

    unsigned get_count() const { return count_; }
    void set_count(unsigned value) { count_ = value; }

private:
    unsigned renderer_id_;
    unsigned count_;
};


#endif //PROJECT_KAPPA_INDEX_BUFFER_H
