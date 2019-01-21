  //  2017 Copyright Fernando Costa Leite.

#ifndef STRUCTURES_ARRAY_LIST_H
#define STRUCTURES_ARRAY_LIST_H

#include <cstdint>
#include <stdexcept>  // C++ Exceptions

namespace structures {

template<typename T>
/*!
* classe de implementação de Lista
*/
class ArrayList {
 public:
    ArrayList();
/*!
* método construtor com passagem de parâmetro, no caso, tamanho da lista.
*/
    explicit ArrayList(std::size_t max_size);
    ~ArrayList();

/*!
* método para limpar a fila.
*/
    void clear();
/*!
* método que inclui itens no final da fila.
*/
    void push_back(const T& data);
/*!
* método que insere itens no início da fila.
*/
    void push_front(const T& data);
/*!
* método para inserir elementos na fila
*/
    void insert(const T& data, std::size_t index);
/*!
* insere elementos na fila em ordem.
*/
    void insert_sorted(const T& data);
/*!
* retira elementos do indice da fila
*/
    T pop(std::size_t index);
/*!
* retira o último elemento da fila.
*/
    T pop_back();
/*!
* retira o primeiro elemento da fila.
*/
    T pop_front();
/*!
* remove determinado dado da lista.
*/
    void remove(const T& data);
/*!
* verifica se a fila está cheia;
*/
    bool full() const;
/*!
* verifica se a fila está vazia;
*/
    bool empty() const;
/*!
* verifica se a lista contém determinado elemento.
*/
    bool contains(const T& data) const;
/*!
* devolve o índice de determinado elemento da lista.
*/
    std::size_t find(const T& data) const;
/*!
* devolve o tamanho da lista.
*/
    std::size_t size() const;
/*!
* devolve o tamanho máximo da lista.
*/
    std::size_t max_size() const;
/*!
* ????
*/
    T& at(std::size_t index);
/*!
* ???
*/
    T& operator[](std::size_t index);
/*!
* ???
*/
    const T& at(std::size_t index) const;
/*!
* ???
*/
    const T& operator[](std::size_t index) const;

 private:
    T* contents;
    std::size_t size_;
    std::size_t max_size_;

    static const auto DEFAULT_MAX = 10u;
};
    template<typename T>
    ArrayList<T>::ArrayList() {	 	  	 	     	      			    	      	        	 	
        ArrayList(DEFAULT_MAX);
    }
    template<typename T>
    ArrayList<T>:: ArrayList(std::size_t max_size) {
        contents = new T[max_size];
        size_ = -1;
        max_size_ = max_size;
    }
    template<typename T>
    ArrayList<T>::~ArrayList() {
        delete [] contents;
    }

    template<typename T>
    void ArrayList<T>::clear() {
        size_ = -1;
    }
    template<typename T>
    void ArrayList<T>::push_back(const T& data) {
        if (full()) {
            throw std::out_of_range("Erro, lista cheia!");
        } else {
            insert(data, size_+1);
            }
    }
    template<typename T>
    void ArrayList<T>:: push_front(const T& data) {
        if (full()) {
            throw std::out_of_range("Erro, lista cheia!");
        } else {
             insert(data, 0);
            }
    }
    template<typename T>
    void ArrayList<T>::insert(const T& data, std::size_t index) {
         if (full()) {	 	  	 	     	      			    	      	        	 	
            throw std::out_of_range("Erro, lista cheia!");
        } else {
                if (index < 0 || index >= max_size_) {
                    throw std::out_of_range("indice fora dos parametros");
                } else {
                size_ = size_ + 1;
                std::size_t pos = size_;
            while (pos > index) {
                contents[pos] = contents[pos-1];
                pos--;
            }
            contents[index] = data;
            }
            }
    }
    template<typename T>
    void ArrayList<T>::insert_sorted(const T& data) {
        if (full()) {
            throw std::out_of_range("Erro, lista cheia!");
        } else {
            int control = 0;
            while (control <= size_ && data > contents[control]) {
                control = control + 1;
            }
        insert(data, control);
        }
    }
    template<typename T>
    T ArrayList<T>::pop(std::size_t index) {
        if (empty()) {
            throw std::out_of_range("Erro, fila vazia!");
        } else {
            if (index < 0 || index > size_) {
                throw std::out_of_range("Erro, fora da fila!");
            } else {
                T temp = contents[index];
                while (index < size_) {	 	  	 	     	      			    	      	        	 	
                    contents[index] = contents[index+1];
                    index++;
                }
            size_--;
            return temp;
            }
        }
    }
    template<typename T>
    T ArrayList<T>::pop_back() {
        if (empty()) {
            throw std::out_of_range("Erro, fila vazia!");
        } else {
            size_--;
            return contents[size_+1];
        }
    }
    template<typename T>
    T ArrayList<T>::pop_front() {
        if (empty()) {
            throw std::out_of_range("Erro, fila vazia!");
        } else {
            T temp = contents[0];
            for (int i =0; i < size_+1; i++) {
                contents[i] = contents[i+1];
            }
            size_--;
            return temp;
        }
    }
    template<typename T>
    void ArrayList<T>::remove(const T& data) {
        if (empty()) {
            throw std::out_of_range("Erro, fila vazia!");
        } else {
            pop(find(data));
        }	 	  	 	     	      			    	      	        	 	
    }
    template<typename T>
    bool ArrayList<T>::full() const {
        return size_ == max_size_-1;
    }
    template<typename T>
    bool ArrayList<T>::empty() const {
        return size_ == - 1;
    }
    template<typename T>
    bool ArrayList<T>::contains(const T& data) const {
        bool temp = false;
        if (empty()) {
            throw std::out_of_range("Erro, lista vazia!");
        } else {
        for (int i = 0; i < size_+1; i++) {
            if (contents[i] == data) {
                temp = true;
            }
        }
        return temp;
        }
    }
    template<typename T>
    std::size_t ArrayList<T>::find(const T& data) const {
        if (empty()) {
            throw std::out_of_range("Erro, fila vazia!");
        } else {
            if (contains(data)) {
                int i = 0;
                while (i <= size_ && contents[i] != data) {
                    i++;
                }
                return size_t(i);
            } else {
                throw std::out_of_range("Erro, Elemento não encontrado");
            }	 	  	 	     	      			    	      	        	 	
        }
    }
    template<typename T>
    std::size_t ArrayList<T>::size() const {
        return size_+1;
    }
    template<typename T>
    std::size_t ArrayList<T>::max_size() const {
        return max_size_;
    }
    template<typename T>
    T& ArrayList<T>::at(std::size_t index) {
        if (index > 0 && index <= size_) {
            return contents[index];
        } else {
            throw std::out_of_range("Erro, indice invalido!");
        }
    }
    template<typename T>
    T& ArrayList<T>::operator[](std::size_t index) {
         if (index > 0 && index <= size_) {
            return contents[index];
        } else {
            throw std::out_of_range("Erro, indice invalido!");
        }
    }
    template<typename T>
    const T& ArrayList<T>::at(std::size_t index) const {
         if (index > 0 && index <= size_) {
            return contents[index];
        } else {
            throw std::out_of_range("Erro, indice invalido!");
        }
    }
    template<typename T>
    const T& ArrayList<T>::operator[](std::size_t index) const {	 	  	 	     	      			    	      	        	 	
         if (index > 0 && index <= size_) {
            return contents[index];
        } else {
            throw std::out_of_range("Erro, indice invalido!");
        }
    }
}  //  namespace structures.

#endif
