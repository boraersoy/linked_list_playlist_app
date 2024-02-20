#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char* names[] = {
    // Teoman Songs
    "Paramparca", "Renkli Ruyalar Oteli", "Gemiler", "Papatya", "Kupa Kizi Sinek Valesi",
    // Duman Songs
    "Senden Daha Guzel", "Haberin Yok Oluyorum", "Istanbul", "Belki Alisman Lazim", "Seni Kendime Sakladim",
    // Chet Baker Songs
    "My Funny Valentine", "Let's Get Lost", "I Fall in Love Too Easily", "There Will Never Be Another You", "Time After Time",
    // Sebnem Ferah Songs
    "Yagmurlar", "Benim Adim Orman", "Mayin Tarlasi", "Kor Kuyular", "Kelimeler Yetse",
    // Hayko Cepkin Songs
    "Gormuyorsun", "Gec Kaldim", "Huzunle Karisik", "Yarasi Sakli", "Melekler",
    // Metallica Songs
    "Enter Sandman", "Nothing Else Matters", "Master of Puppets", "One", "The Unforgiven",
    // Radiohead Songs
    "Creep", "Karma Police", "No Surprises", "Paranoid Android", "Fake Plastic Trees",
    // Megadeth Songs
    "Symphony of Destruction", "Hangar 18", "Tornado of Souls", "A Tout le Monde", "Sweating Bullets",
    // Queen Songs
    "Bohemian Rhapsody", "We Will Rock You", "Another One Bites the Dust", "Under Pressure", "Somebody to Love",
    // Sade Songs
    "Smooth Operator", "The Sweetest Taboo", "No Ordinary Love", "Your Love Is King", "By Your Side",
    // Pinhani Songs
    "Ne Guzel Guldun", "Beni Al", "Yitirmeden", "Sevmekten Usanmam", "Zaman Beklemez",
    // Rammstein Songs
    "Du Hast", "Sonne", "Engel", "Ich Will", "Feuer Frei!"
};


typedef struct linked_list_node_t {
    void* data;
    struct linked_list_node_t* next;
} linked_list_node_t;

void create_array_of_linked_list_ptrs(linked_list_node_t*** destination, int size) {
    *destination = (linked_list_node_t**)malloc(size * sizeof(linked_list_node_t*));
    for (int i = 0; i < size; i++) {
        (*destination)[i] = NULL;
    }
}

void get_element_of_array_of_linked_list_ptrs(linked_list_node_t** array, int index, linked_list_node_t** destination) {
    *destination = array[index];
}

void set_element_of_array_of_linked_list_ptrs(linked_list_node_t** array, int index, linked_list_node_t* head) {
    array[index] = head;
}

void destroy_array_of_linked_list_ptrs(linked_list_node_t** array) {
    free(array);
}

void resize_array_of_linked_list_ptrs(linked_list_node_t*** destination, linked_list_node_t** array, int size, int new_size) {
    *destination = (linked_list_node_t**)realloc(array, new_size * sizeof(linked_list_node_t*));
    for (int i = size; i < new_size; i++) {
        (*destination)[i] = NULL;
    }
}

void create_link_list(linked_list_node_t** destination) {
    *destination = NULL;
}

void destroy_linked_list(linked_list_node_t* head) {
    linked_list_node_t* current = head;
    linked_list_node_t* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

linked_list_node_t** head = NULL;

void add_to_linked_list(linked_list_node_t** head, const void* data) {
    linked_list_node_t* new_node = (linked_list_node_t*)malloc(sizeof(linked_list_node_t));
    new_node->data = (void*)data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        linked_list_node_t* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}


void remove_from_linked_list(linked_list_node_t** head, const void* data) {
    linked_list_node_t* current = *head;
    linked_list_node_t* prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

typedef struct song_t {
    const char* name;
    float duration;
} song_t;

void create_song(song_t* destination, const char* name, float duration) {
    destination->name = name;
    destination->duration = duration;
}

linked_list_node_t** array_of_playlist_ptrs = NULL;

int main(void) {
    srand(time(0));

    create_array_of_linked_list_ptrs(&array_of_playlist_ptrs, 5);

    for (int i = 0; i < 5; i++) {
        linked_list_node_t* playlist = NULL;
        create_link_list(&playlist);
        set_element_of_array_of_linked_list_ptrs(array_of_playlist_ptrs, i, playlist);
    }

    resize_array_of_linked_list_ptrs(&array_of_playlist_ptrs, array_of_playlist_ptrs, 5, 10); 


    for (int i = 5; i < 10; i++) {
        linked_list_node_t* playlist = NULL;
        create_link_list(&playlist);
        set_element_of_array_of_linked_list_ptrs(array_of_playlist_ptrs, i, playlist);

    }
  
    for (int i = 0; i < 10; i++) {
        linked_list_node_t* playlist;
        get_element_of_array_of_linked_list_ptrs(array_of_playlist_ptrs, i, &playlist);

        for (int j = 0; j < 4; j++) {
            int size = sizeof(names) / sizeof(names[0]);
             
            song_t* song = (song_t*)malloc(sizeof(song_t));
            create_song(song, strdup(names[rand() % size]), ((float)rand() / RAND_MAX) * 10);
            add_to_linked_list(&playlist, song);
            
        }

        set_element_of_array_of_linked_list_ptrs(array_of_playlist_ptrs,i,playlist);
    
    }
    for (int i = 0; i < 10; i++) {
        linked_list_node_t* playlist;
        get_element_of_array_of_linked_list_ptrs(array_of_playlist_ptrs, i, &playlist);

        if (playlist != NULL && playlist->next != NULL) {
            linked_list_node_t* second_song = playlist->next;
            remove_from_linked_list(&playlist, second_song->data);
        }

        printf("Playlist #%d\n", i + 1);
        if (playlist == NULL) {
            printf("\tEmpty Playlist\n");
        } else {
            linked_list_node_t* current_song = playlist;
            int song_count = 1;

            while (current_song != NULL) {
                song_t* current_song_data = (song_t*)current_song->data;
                printf("\tName: %s, Duration: %f\n", current_song_data->name, current_song_data->duration);
                current_song = current_song->next;
                song_count++;
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        destroy_linked_list(array_of_playlist_ptrs[i]);
    }

    destroy_array_of_linked_list_ptrs(array_of_playlist_ptrs);

    return 0;
}
