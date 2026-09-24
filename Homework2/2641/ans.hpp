#include <iostream>
#include <optional>
#include <stdexcept>
#include <utility>

class RefCellError : public std::runtime_error {
public:
    explicit RefCellError(const std::string& message) : std::runtime_error(message) {}
    virtual ~RefCellError() = default;
};// Abstract class as base class

//invalidly call an immutable borrow
class BorrowError : public RefCellError {
public:
    explicit BorrowError(const std::string& message) : RefCellError(message) {}
};
//invalidly call a mutable borrow
class BorrowMutError : public RefCellError {
public:
    explicit BorrowMutError(const std::string& message) : RefCellError(message) {}
};
//still has refs when destructed
class DestructionError : public RefCellError {
public:
    explicit DestructionError(const std::string& message) : RefCellError(message) {}
};

template <typename T>
class RefCell {
private:
    T value;
    // TODO(student)
    mutable int borrow_state;

public:
    // Forward declarations
    class Ref;
    class RefMut;

    // Constructor
    explicit RefCell(const T& initial_value): value(initial_value),borrow_state(0){
        // TODO(student)
    }
    explicit RefCell(T && initial_value): value(std::move(initial_value)),borrow_state(0) {
        // TODO(student)
    }

    // Disable copying and moving for simplicity
    RefCell(const RefCell&) = delete;
    RefCell& operator=(const RefCell&) = delete;
    RefCell(RefCell&&) = delete;
    RefCell& operator=(RefCell&&) = delete;

    // Borrow methods
    Ref borrow() const {
        // TODO(student)
        if(this-> borrow_state == -1){
            throw BorrowError("error");
        }

        Ref ref(this);
        return ref;
    }

    std::optional<Ref> try_borrow() const {
        // TODO(student)
        if(this -> borrow_state == -1){
            return std::nullopt;
        }

        Ref ref(this);
        return ref;
    }

    RefMut borrow_mut() {
        // TODO(student)
        if(this -> borrow_state != 0){
            throw BorrowMutError("error");
        }

        RefMut refmut(this);
        return refmut;
    }

    std::optional<RefMut> try_borrow_mut() {
        // TODO(student)
        if(this-> borrow_state != 0){
            return std::nullopt;
        }

        RefMut refmut(this);
        return refmut;
    }

    // Inner classes for borrows
    class Ref {
    private:
        // TODO(student)
        const RefCell<T>* cell;

    public:

        Ref(const RefCell<T>* rc){
            cell = rc;
            cell ->borrow_state ++;
        }


        Ref() {
            // TODO(student)
            this->cell = nullptr;
        }

        ~Ref() {
            // TODO(student)
            if(this->cell != nullptr){
                cell->borrow_state --;
            }
        }

        const T& operator*() const {
            // TODO(student)
            return cell->value;
        }

        const T* operator->() const {
            // TODO(student)
            return &(cell->value);
        }

        // Allow copying
        Ref(const Ref& src) {
            // TODO(student)
            this -> cell = src.cell;
            if(src.cell != nullptr){
                this -> cell ->borrow_state ++;
            }
        }
        Ref& operator=(const Ref& src) {
            // TODO(student)
            if(this == &src){
                return *this;
            }
            if(this->cell != nullptr) this->cell->borrow_state --;
            this -> cell = src.cell;
            if(src.cell != nullptr){
                this->cell -> borrow_state ++;
            }
            return *this;
        }

        // Allow moving
        Ref(Ref&& other) noexcept {
            // TODO(student)
            this->cell = other.cell;
            other.cell = nullptr;

        }

        Ref& operator=(Ref&& other) noexcept {
            // TODO(student)
            if(this == &other){
                return *this;
            }
            if(this->cell != nullptr) this->cell->borrow_state --;
            this -> cell = other.cell;
            other.cell = nullptr;
            return *this;
        }
    };

    class RefMut {
    private:
        // TODO(student)
        RefCell<T>* cell;

    public:

        RefMut(RefCell<T>* o){
            cell = o;
            cell ->borrow_state = -1;
        }

        RefMut() {
        // TODO(student)
            this->cell = nullptr;
        }

        ~RefMut() {
        // TODO(student)
            if(this->cell != nullptr){
                this->cell->borrow_state = 0;
            }
        }

        T& operator*() {
        // TODO(student)
            return cell->value;
        }

        T* operator->() {
        // TODO(student)
            return &(cell->value);
        }

        // Disable copying to ensure correct borrow rules
        RefMut(const RefMut&) = delete;
        RefMut& operator=(const RefMut&) = delete;

        // Allow moving
        RefMut(RefMut&& other) noexcept  {
        // TODO(student)
            this ->cell = other.cell;
            other.cell = nullptr;
        }

        RefMut& operator=(RefMut&& other) noexcept {
        // TODO(student)
            if(this == & other){
                return *this;
            }
            if(this -> cell != nullptr){
                this->cell->borrow_state = 0;
            }
            this -> cell = other.cell;
            other.cell = nullptr;
            return *this;
        }
    };

    // Destructor
    ~RefCell() noexcept(false){
        // TODO(student)
        if(borrow_state != 0){
            throw DestructionError("error");
        }
    }
};