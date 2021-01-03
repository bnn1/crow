#include <assert.h>
#include <errno.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

struct void_ {};
struct dir;
typedef uint8_t* (*fun_ptr1)(uint8_t*);
struct ctx {
	uint8_t* gctx_ptr;
	uint64_t island_id;
	uint64_t exclusion;
	uint8_t* gc_ctx_ptr;
	uint8_t* exception_ctx_ptr;
	uint8_t* log_ctx;
};
struct mark_ctx {
	uint64_t memory_size_words;
	uint8_t* marks;
	uint64_t* memory_start;
};
struct arr_0 {
	uint64_t size;
	char* data;
};
struct less {
};
struct equal {
};
struct greater {
};
struct fut_0;
struct lock;
struct _atomic_bool {
	uint8_t value;
};
struct fut_state_callbacks_0;
struct fut_callback_node_0;
struct exception {
	struct arr_0 message;
};
struct ok_0 {
	int32_t value;
};
struct err_0 {
	struct exception value;
};
struct none {
};
struct some_0 {
	struct fut_callback_node_0* value;
};
struct fut_state_resolved_0 {
	int32_t value;
};
struct arr_1 {
	uint64_t size;
	struct arr_0* data;
};
struct global_ctx;
struct island;
struct gc;
struct gc_ctx;
struct some_1 {
	struct gc_ctx* value;
};
struct island_gc_root;
struct task_queue;
struct task_queue_node;
struct task;
struct some_2 {
	struct task_queue_node* value;
};
struct mut_list_0;
struct mut_arr_0;
struct arr_2 {
	uint64_t size;
	uint64_t* data;
};
struct logged;
struct info {
};
struct warn {
};
struct thread_safe_counter;
struct arr_3 {
	uint64_t size;
	struct island** data;
};
struct condition;
struct exception_ctx;
struct jmp_buf_tag;
struct bytes64;
struct bytes32;
struct bytes16 {
	uint64_t n0;
	uint64_t n1;
};
struct bytes128;
struct some_3 {
	uint8_t* value;
};
struct log_ctx;
struct thread_local_stuff {
	struct exception_ctx* exception_ctx;
	struct log_ctx* log_ctx;
};
struct arr_4 {
	uint64_t size;
	char** data;
};
struct fut_1;
struct fut_state_callbacks_1;
struct fut_callback_node_1;
struct ok_1 {
	struct void_ value;
};
struct some_4 {
	struct fut_callback_node_1* value;
};
struct fut_state_resolved_1 {
	struct void_ value;
};
struct fun_ref0;
struct island_and_exclusion {
	uint64_t island;
	uint64_t exclusion;
};
struct fun_ref1;
struct then_0__lambda0;
struct forward_to__lambda0 {
	struct fut_0* to;
};
struct call_ref_0__lambda0;
struct call_ref_0__lambda0__lambda0;
struct call_ref_0__lambda0__lambda1 {
	struct fut_0* res;
};
struct then2__lambda0;
struct call_ref_1__lambda0;
struct call_ref_1__lambda0__lambda0;
struct call_ref_1__lambda0__lambda1 {
	struct fut_0* res;
};
struct add_first_task__lambda0;
struct mut_arr_1 {
	struct arr_1 arr;
};
struct map_0__lambda0;
struct thread_args {
	uint64_t thread_id;
	struct global_ctx* gctx;
};
struct cell_0 {
	uint64_t value;
};
struct chosen_task;
struct do_a_gc {
};
struct no_chosen_task;
struct some_5 {
	uint64_t value;
};
struct timespec {
	int64_t tv_sec;
	int64_t tv_nsec;
};
struct cell_1 {
	struct timespec value;
};
struct no_task;
struct cell_2 {
	uint8_t* value;
};
struct test_options {
	uint8_t print_tests__q;
	uint8_t overwrite_output__q;
	uint64_t max_failures;
};
struct some_6 {
	struct test_options value;
};
struct some_7 {
	struct arr_1 value;
};
struct arr_5;
struct parsed_cmd_line_args;
struct dict_0;
struct arr_6 {
	uint64_t size;
	struct arr_1* data;
};
struct mut_dict_0;
struct mut_list_1 {
	struct mut_arr_1 backing;
	uint64_t size;
};
struct mut_list_2;
struct mut_arr_2 {
	struct arr_6 arr;
};
struct some_8 {
	struct arr_0 value;
};
struct mut_list_3;
struct mut_arr_3;
struct fill_mut_arr__lambda0;
struct cell_3 {
	uint8_t value;
};
struct parse_cmd_line_args__lambda0 {
	struct arr_1 t_names;
	struct cell_3* help;
	struct mut_list_3* values;
};
struct index_of__lambda0 {
	struct arr_0 value;
};
struct r_index_of__lambda0 {
	char value;
};
struct mut_arr_4 {
	struct arr_0 arr;
};
struct dict_1 {
	struct arr_1 keys;
	struct arr_1 values;
};
struct mut_dict_1 {
	struct mut_list_1* keys;
	struct mut_list_1* values;
};
struct key_value_pair {
	struct arr_0 key;
	struct arr_0 value;
};
struct failure {
	struct arr_0 path;
	struct arr_0 message;
};
struct arr_7 {
	uint64_t size;
	struct failure** data;
};
struct ok_2 {
	struct arr_0 value;
};
struct err_1 {
	struct arr_7 value;
};
struct first_failures__lambda0;
struct first_failures__lambda0__lambda0 {
	struct arr_0 a_descr;
};
struct stat_t {
	uint64_t st_dev;
	uint32_t pad0;
	uint64_t st_ino_unused;
	uint32_t st_mode;
	uint32_t st_nlink;
	uint64_t st_uid;
	uint64_t st_gid;
	uint64_t st_rdev;
	uint32_t pad1;
	int64_t st_size;
	uint64_t st_blksize;
	uint64_t st_blocks;
	uint64_t st_atime;
	uint64_t st_atime_nsec;
	uint64_t st_mtime;
	uint64_t st_mtime_nsec;
	uint64_t st_ctime;
	uint64_t st_ctime_nsec;
	uint64_t st_ino;
	uint64_t unused;
};
struct some_9 {
	struct stat_t* value;
};
struct dirent;
struct bytes256;
struct cell_4 {
	struct dirent* value;
};
struct copy_to_mut_arr__lambda0 {
	struct arr_1 a;
};
struct each_child_recursive__lambda0;
struct list_tests__lambda1 {
	struct mut_list_1* res;
};
struct mut_list_4;
struct mut_arr_5 {
	struct arr_7 arr;
};
struct flat_map_with_max_size__lambda0;
struct push_all__lambda0 {
	struct mut_list_4* a;
};
struct some_10 {
	struct failure* value;
};
struct run_noze_tests__lambda0 {
	struct arr_0 path_to_noze;
	struct dict_1* env;
	struct test_options options;
};
struct some_11 {
	struct arr_7 value;
};
struct run_single_noze_test__lambda0 {
	struct test_options options;
	struct arr_0 path;
	struct arr_0 path_to_noze;
	struct dict_1* env;
};
struct print_test_result {
	uint8_t should_stop__q;
	struct arr_7 failures;
};
struct process_result {
	int32_t exit_code;
	struct arr_0 stdout;
	struct arr_0 stderr;
};
struct pipes {
	int32_t write_pipe;
	int32_t read_pipe;
};
struct posix_spawn_file_actions_t;
struct cell_5 {
	int32_t value;
};
struct mut_list_5 {
	struct mut_arr_4 backing;
	uint64_t size;
};
struct pollfd {
	int32_t fd;
	int16_t events;
	int16_t revents;
};
struct arr_8 {
	uint64_t size;
	struct pollfd* data;
};
struct handle_revents_result {
	uint8_t had_pollin__q;
	uint8_t hung_up__q;
};
struct mut_arr_6 {
	struct arr_4 arr;
};
struct map_1__lambda0;
struct mut_list_6 {
	struct mut_arr_6 backing;
	uint64_t size;
};
struct convert_environ__lambda0 {
	struct mut_list_6* res;
};
struct do_test__lambda0 {
	struct arr_0 test_path;
	struct arr_0 noze_exe;
	struct dict_1* env;
	struct test_options options;
};
struct do_test__lambda0__lambda0 {
	struct arr_0 test_path;
	struct arr_0 noze_exe;
	struct dict_1* env;
	struct test_options options;
};
struct do_test__lambda1 {
	struct arr_0 noze_path;
	struct test_options options;
};
struct excluded_from_lint__q__lambda0 {
	struct arr_0 name;
};
struct list_lintable_files__lambda1 {
	struct mut_list_1* res;
};
struct lint__lambda0 {
	struct test_options options;
};
struct lines__lambda0 {
	struct mut_list_1* res;
	struct arr_0 s;
	struct cell_0* last_nl;
};
struct lint_file__lambda0 {
	uint8_t err_file__q;
	struct mut_list_4* res;
	struct arr_0 path;
};
struct comparison {
	uint64_t kind;
	union {
		struct less as0;
		struct equal as1;
		struct greater as2;
	};
};
struct fut_state_0;
struct result_0 {
	uint64_t kind;
	union {
		struct ok_0 as0;
		struct err_0 as1;
	};
};
struct fun_act1_0 {
	uint64_t kind;
	union {
		struct forward_to__lambda0* as0;
	};
};
struct opt_0 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_0 as1;
	};
};
struct opt_1 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_1 as1;
	};
};
struct fun_act0_0 {
	uint64_t kind;
	union {
		struct call_ref_0__lambda0__lambda0* as0;
		struct call_ref_0__lambda0* as1;
		struct call_ref_1__lambda0__lambda0* as2;
		struct call_ref_1__lambda0* as3;
	};
};
struct opt_2 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_2 as1;
	};
};
struct fun1_0 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct log_level {
	uint64_t kind;
	union {
		struct info as0;
		struct warn as1;
	};
};
struct fun1_1 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct opt_3 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_3 as1;
	};
};
struct fun2 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fut_state_1;
struct result_1 {
	uint64_t kind;
	union {
		struct ok_1 as0;
		struct err_0 as1;
	};
};
struct fun_act1_1 {
	uint64_t kind;
	union {
		struct then_0__lambda0* as0;
	};
};
struct opt_4 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_4 as1;
	};
};
struct fun_act0_1 {
	uint64_t kind;
	union {
		struct add_first_task__lambda0* as0;
	};
};
struct fun_act1_2 {
	uint64_t kind;
	union {
		struct then2__lambda0* as0;
	};
};
struct fun_act1_3 {
	uint64_t kind;
	union {
		struct call_ref_0__lambda0__lambda1* as0;
		struct call_ref_1__lambda0__lambda1* as1;
	};
};
struct fun_act1_4 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fun_act1_5 {
	uint64_t kind;
	union {
		struct map_0__lambda0* as0;
		struct copy_to_mut_arr__lambda0* as1;
	};
};
struct choose_task_result;
struct task_or_gc;
struct opt_5 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_5 as1;
	};
};
struct choose_task_in_island_result;
struct pop_task_result;
struct opt_6 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_6 as1;
	};
};
struct opt_7 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_7 as1;
	};
};
struct fun1_2 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fun_act1_6 {
	uint64_t kind;
	union {
		struct void_ as0;
		struct void_ as1;
		struct void_ as2;
		struct index_of__lambda0* as3;
		struct void_ as4;
		struct excluded_from_lint__q__lambda0* as5;
		struct void_ as6;
	};
};
struct opt_8 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_8 as1;
	};
};
struct fun_act1_7 {
	uint64_t kind;
	union {
		struct fill_mut_arr__lambda0* as0;
	};
};
struct fun_act2_0 {
	uint64_t kind;
	union {
		struct parse_cmd_line_args__lambda0* as0;
	};
};
struct fun_act1_8 {
	uint64_t kind;
	union {
		struct r_index_of__lambda0* as0;
	};
};
struct result_2 {
	uint64_t kind;
	union {
		struct ok_2 as0;
		struct err_1 as1;
	};
};
struct fun0 {
	uint64_t kind;
	union {
		struct do_test__lambda0__lambda0* as0;
		struct do_test__lambda0* as1;
		struct do_test__lambda1* as2;
	};
};
struct fun_act1_9 {
	uint64_t kind;
	union {
		struct first_failures__lambda0__lambda0* as0;
		struct first_failures__lambda0* as1;
	};
};
struct fun_act1_10 {
	uint64_t kind;
	union {
		struct each_child_recursive__lambda0* as0;
		struct list_tests__lambda1* as1;
		struct flat_map_with_max_size__lambda0* as2;
		struct list_lintable_files__lambda1* as3;
	};
};
struct opt_9 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_9 as1;
	};
};
struct fun_act1_11 {
	uint64_t kind;
	union {
		struct run_noze_tests__lambda0* as0;
		struct lint__lambda0* as1;
	};
};
struct fun_act1_12 {
	uint64_t kind;
	union {
		struct push_all__lambda0* as0;
		struct void_ as1;
	};
};
struct opt_10 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_10 as1;
	};
};
struct opt_11 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_11 as1;
	};
};
struct fun_act1_13 {
	uint64_t kind;
	union {
		struct run_single_noze_test__lambda0* as0;
	};
};
struct fun_act2_1 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fun_act1_14 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fun_act1_15 {
	uint64_t kind;
	union {
		struct map_1__lambda0* as0;
	};
};
struct fun_act2_2 {
	uint64_t kind;
	union {
		struct convert_environ__lambda0* as0;
	};
};
struct fun_act2_3 {
	uint64_t kind;
	union {
		struct lint_file__lambda0* as0;
	};
};
struct fun_act2_4 {
	uint64_t kind;
	union {
		struct lines__lambda0* as0;
	};
};
typedef struct fut_0* (*fun_ptr2)(struct ctx*, struct arr_1);
struct fut_0;
struct lock {
	struct _atomic_bool is_locked;
};
struct fut_state_callbacks_0 {
	struct opt_0 head;
};
struct fut_callback_node_0 {
	struct fun_act1_0 cb;
	struct opt_0 next_node;
};
struct global_ctx;
struct island;
struct gc {
	struct lock lk;
	uint64_t gc_count;
	struct opt_1 context_head;
	uint8_t needs_gc__q;
	uint64_t size_words;
	uint8_t* mark_begin;
	uint8_t* mark_cur;
	uint8_t* mark_end;
	uint64_t* data_begin;
	uint64_t* data_cur;
	uint64_t* data_end;
};
struct gc_ctx {
	struct gc* gc;
	struct opt_1 next_ctx;
};
struct island_gc_root;
struct task_queue;
struct task_queue_node;
struct task {
	uint64_t time;
	uint64_t exclusion;
	struct fun_act0_0 action;
};
struct mut_list_0;
struct mut_arr_0 {
	struct arr_2 arr;
};
struct logged {
	struct log_level level;
	struct arr_0 message;
};
struct thread_safe_counter {
	struct lock lk;
	uint64_t value;
};
struct condition {
	struct lock lk;
	uint64_t value;
};
struct exception_ctx {
	struct jmp_buf_tag* jmp_buf_ptr;
	struct exception thrown_exception;
};
struct jmp_buf_tag;
struct bytes64;
struct bytes32 {
	struct bytes16 n0;
	struct bytes16 n1;
};
struct bytes128;
struct log_ctx {
	struct fun1_1 handler;
};
struct fut_1;
struct fut_state_callbacks_1 {
	struct opt_4 head;
};
struct fut_callback_node_1 {
	struct fun_act1_1 cb;
	struct opt_4 next_node;
};
struct fun_ref0 {
	struct island_and_exclusion island_and_exclusion;
	struct fun_act0_1 fun;
};
struct fun_ref1 {
	struct island_and_exclusion island_and_exclusion;
	struct fun_act1_2 fun;
};
struct then_0__lambda0 {
	struct fun_ref1 cb;
	struct fut_0* res;
};
struct call_ref_0__lambda0 {
	struct fun_ref1 f;
	struct void_ p0;
	struct fut_0* res;
};
struct call_ref_0__lambda0__lambda0 {
	struct fun_ref1 f;
	struct void_ p0;
	struct fut_0* res;
};
struct then2__lambda0 {
	struct fun_ref0 cb;
};
struct call_ref_1__lambda0 {
	struct fun_ref0 f;
	struct fut_0* res;
};
struct call_ref_1__lambda0__lambda0 {
	struct fun_ref0 f;
	struct fut_0* res;
};
struct add_first_task__lambda0 {
	struct arr_4 all_args;
	fun_ptr2 main_ptr;
};
struct map_0__lambda0 {
	struct fun_act1_4 mapper;
	struct arr_4 a;
};
struct chosen_task;
struct no_chosen_task {
	uint8_t no_tasks_and_last_thread_out__q;
	struct opt_5 first_task_time;
};
struct no_task {
	uint8_t any_tasks__q;
	struct opt_5 first_task_time;
};
struct arr_5 {
	uint64_t size;
	struct opt_7* data;
};
struct parsed_cmd_line_args {
	struct arr_1 nameless;
	struct dict_0* named;
	struct arr_1 after;
};
struct dict_0 {
	struct arr_1 keys;
	struct arr_6 values;
};
struct mut_dict_0 {
	struct mut_list_1* keys;
	struct mut_list_2* values;
};
struct mut_list_2 {
	struct mut_arr_2 backing;
	uint64_t size;
};
struct mut_list_3;
struct mut_arr_3 {
	struct arr_5 arr;
};
struct fill_mut_arr__lambda0 {
	struct opt_7 value;
};
struct first_failures__lambda0 {
	struct fun0 b;
};
struct dirent;
struct bytes256;
struct each_child_recursive__lambda0 {
	struct fun_act1_6 filter;
	struct arr_0 path;
	struct fun_act1_10 f;
};
struct mut_list_4 {
	struct mut_arr_5 backing;
	uint64_t size;
};
struct flat_map_with_max_size__lambda0 {
	struct mut_list_4* res;
	uint64_t max_size;
	struct fun_act1_11 mapper;
};
struct posix_spawn_file_actions_t;
struct map_1__lambda0 {
	struct fun_act1_14 mapper;
	struct arr_1 a;
};
struct fut_state_0 {
	uint64_t kind;
	union {
		struct fut_state_callbacks_0 as0;
		struct fut_state_resolved_0 as1;
		struct exception as2;
	};
};
struct fut_state_1 {
	uint64_t kind;
	union {
		struct fut_state_callbacks_1 as0;
		struct fut_state_resolved_1 as1;
		struct exception as2;
	};
};
struct choose_task_result;
struct task_or_gc {
	uint64_t kind;
	union {
		struct task as0;
		struct do_a_gc as1;
	};
};
struct choose_task_in_island_result {
	uint64_t kind;
	union {
		struct task as0;
		struct do_a_gc as1;
		struct no_task as2;
	};
};
struct pop_task_result {
	uint64_t kind;
	union {
		struct task as0;
		struct no_task as1;
	};
};
struct fut_0 {
	struct lock lk;
	struct fut_state_0 state;
};
struct global_ctx {
	struct lock lk;
	struct arr_3 islands;
	uint64_t n_live_threads;
	struct condition may_be_work_to_do;
	uint8_t shut_down__q;
	uint8_t any_unhandled_exceptions__q;
};
struct island;
struct island_gc_root;
struct task_queue;
struct task_queue_node {
	struct task task;
	struct opt_2 next;
};
struct mut_list_0 {
	struct mut_arr_0 backing;
	uint64_t size;
};
struct jmp_buf_tag;
struct bytes64 {
	struct bytes32 n0;
	struct bytes32 n1;
};
struct bytes128 {
	struct bytes64 n0;
	struct bytes64 n1;
};
struct fut_1 {
	struct lock lk;
	struct fut_state_1 state;
};
struct chosen_task {
	struct island* task_island;
	struct task_or_gc task_or_gc;
};
struct mut_list_3 {
	struct mut_arr_3 backing;
	uint64_t size;
};
struct dirent;
struct bytes256 {
	struct bytes128 n0;
	struct bytes128 n1;
};
struct posix_spawn_file_actions_t {
	int32_t allocated;
	int32_t used;
	uint8_t* actions;
	struct bytes64 pad;
};
struct choose_task_result {
	uint64_t kind;
	union {
		struct chosen_task as0;
		struct no_chosen_task as1;
	};
};
struct island;
struct island_gc_root;
struct task_queue {
	struct opt_2 head;
	struct mut_list_0 currently_running_exclusions;
};
struct jmp_buf_tag {
	struct bytes64 jmp_buf;
	int32_t mask_was_saved;
	struct bytes128 saved_mask;
};
struct dirent {
	uint64_t d_ino;
	int64_t d_off;
	uint16_t d_reclen;
	char d_type;
	struct bytes256 d_name;
};
struct island;
struct island_gc_root {
	struct task_queue tasks;
	struct fun1_0 exception_handler;
	struct fun1_1 log_handler;
};
struct island {
	struct global_ctx* gctx;
	uint64_t id;
	struct gc gc;
	struct island_gc_root gc_root;
	struct lock tasks_lock;
	uint64_t n_threads_running;
	struct thread_safe_counter next_exclusion;
};

_Static_assert(sizeof(struct ctx) == 48, "");
_Static_assert(sizeof(struct mark_ctx) == 24, "");
_Static_assert(sizeof(struct arr_0) == 16, "");
_Static_assert(sizeof(struct less) == 0, "");
_Static_assert(sizeof(struct equal) == 0, "");
_Static_assert(sizeof(struct greater) == 0, "");
_Static_assert(sizeof(struct fut_0) == 32, "");
_Static_assert(sizeof(struct lock) == 1, "");
_Static_assert(sizeof(struct _atomic_bool) == 1, "");
_Static_assert(sizeof(struct fut_state_callbacks_0) == 16, "");
_Static_assert(sizeof(struct fut_callback_node_0) == 32, "");
_Static_assert(sizeof(struct exception) == 16, "");
_Static_assert(sizeof(struct ok_0) == 4, "");
_Static_assert(sizeof(struct err_0) == 16, "");
_Static_assert(sizeof(struct none) == 0, "");
_Static_assert(sizeof(struct some_0) == 8, "");
_Static_assert(sizeof(struct fut_state_resolved_0) == 4, "");
_Static_assert(sizeof(struct arr_1) == 16, "");
_Static_assert(sizeof(struct global_ctx) == 56, "");
_Static_assert(sizeof(struct island) == 200, "");
_Static_assert(sizeof(struct gc) == 96, "");
_Static_assert(sizeof(struct gc_ctx) == 24, "");
_Static_assert(sizeof(struct some_1) == 8, "");
_Static_assert(sizeof(struct island_gc_root) == 56, "");
_Static_assert(sizeof(struct task_queue) == 40, "");
_Static_assert(sizeof(struct task_queue_node) == 48, "");
_Static_assert(sizeof(struct task) == 32, "");
_Static_assert(sizeof(struct some_2) == 8, "");
_Static_assert(sizeof(struct mut_list_0) == 24, "");
_Static_assert(sizeof(struct mut_arr_0) == 16, "");
_Static_assert(sizeof(struct arr_2) == 16, "");
_Static_assert(sizeof(struct logged) == 24, "");
_Static_assert(sizeof(struct info) == 0, "");
_Static_assert(sizeof(struct warn) == 0, "");
_Static_assert(sizeof(struct thread_safe_counter) == 16, "");
_Static_assert(sizeof(struct arr_3) == 16, "");
_Static_assert(sizeof(struct condition) == 16, "");
_Static_assert(sizeof(struct exception_ctx) == 24, "");
_Static_assert(sizeof(struct jmp_buf_tag) == 200, "");
_Static_assert(sizeof(struct bytes64) == 64, "");
_Static_assert(sizeof(struct bytes32) == 32, "");
_Static_assert(sizeof(struct bytes16) == 16, "");
_Static_assert(sizeof(struct bytes128) == 128, "");
_Static_assert(sizeof(struct some_3) == 8, "");
_Static_assert(sizeof(struct log_ctx) == 8, "");
_Static_assert(sizeof(struct thread_local_stuff) == 16, "");
_Static_assert(sizeof(struct arr_4) == 16, "");
_Static_assert(sizeof(struct fut_1) == 32, "");
_Static_assert(sizeof(struct fut_state_callbacks_1) == 16, "");
_Static_assert(sizeof(struct fut_callback_node_1) == 32, "");
_Static_assert(sizeof(struct ok_1) == 0, "");
_Static_assert(sizeof(struct some_4) == 8, "");
_Static_assert(sizeof(struct fut_state_resolved_1) == 0, "");
_Static_assert(sizeof(struct fun_ref0) == 32, "");
_Static_assert(sizeof(struct island_and_exclusion) == 16, "");
_Static_assert(sizeof(struct fun_ref1) == 32, "");
_Static_assert(sizeof(struct then_0__lambda0) == 40, "");
_Static_assert(sizeof(struct forward_to__lambda0) == 8, "");
_Static_assert(sizeof(struct call_ref_0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_0__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_0__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct then2__lambda0) == 32, "");
_Static_assert(sizeof(struct call_ref_1__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_1__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_1__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct add_first_task__lambda0) == 24, "");
_Static_assert(sizeof(struct mut_arr_1) == 16, "");
_Static_assert(sizeof(struct map_0__lambda0) == 24, "");
_Static_assert(sizeof(struct thread_args) == 16, "");
_Static_assert(sizeof(struct cell_0) == 8, "");
_Static_assert(sizeof(struct chosen_task) == 48, "");
_Static_assert(sizeof(struct do_a_gc) == 0, "");
_Static_assert(sizeof(struct no_chosen_task) == 24, "");
_Static_assert(sizeof(struct some_5) == 8, "");
_Static_assert(sizeof(struct timespec) == 16, "");
_Static_assert(sizeof(struct cell_1) == 16, "");
_Static_assert(sizeof(struct no_task) == 24, "");
_Static_assert(sizeof(struct cell_2) == 8, "");
_Static_assert(sizeof(struct test_options) == 16, "");
_Static_assert(sizeof(struct some_6) == 16, "");
_Static_assert(sizeof(struct some_7) == 16, "");
_Static_assert(sizeof(struct arr_5) == 16, "");
_Static_assert(sizeof(struct parsed_cmd_line_args) == 40, "");
_Static_assert(sizeof(struct dict_0) == 32, "");
_Static_assert(sizeof(struct arr_6) == 16, "");
_Static_assert(sizeof(struct mut_dict_0) == 16, "");
_Static_assert(sizeof(struct mut_list_1) == 24, "");
_Static_assert(sizeof(struct mut_list_2) == 24, "");
_Static_assert(sizeof(struct mut_arr_2) == 16, "");
_Static_assert(sizeof(struct some_8) == 16, "");
_Static_assert(sizeof(struct mut_list_3) == 24, "");
_Static_assert(sizeof(struct mut_arr_3) == 16, "");
_Static_assert(sizeof(struct fill_mut_arr__lambda0) == 24, "");
_Static_assert(sizeof(struct cell_3) == 1, "");
_Static_assert(sizeof(struct parse_cmd_line_args__lambda0) == 32, "");
_Static_assert(sizeof(struct index_of__lambda0) == 16, "");
_Static_assert(sizeof(struct r_index_of__lambda0) == 1, "");
_Static_assert(sizeof(struct mut_arr_4) == 16, "");
_Static_assert(sizeof(struct dict_1) == 32, "");
_Static_assert(sizeof(struct mut_dict_1) == 16, "");
_Static_assert(sizeof(struct key_value_pair) == 32, "");
_Static_assert(sizeof(struct failure) == 32, "");
_Static_assert(sizeof(struct arr_7) == 16, "");
_Static_assert(sizeof(struct ok_2) == 16, "");
_Static_assert(sizeof(struct err_1) == 16, "");
_Static_assert(sizeof(struct first_failures__lambda0) == 16, "");
_Static_assert(sizeof(struct first_failures__lambda0__lambda0) == 16, "");
_Static_assert(sizeof(struct stat_t) == 152, "");
_Static_assert(sizeof(struct some_9) == 8, "");
_Static_assert(sizeof(struct dirent) == 280, "");
_Static_assert(sizeof(struct bytes256) == 256, "");
_Static_assert(sizeof(struct cell_4) == 8, "");
_Static_assert(sizeof(struct copy_to_mut_arr__lambda0) == 16, "");
_Static_assert(sizeof(struct each_child_recursive__lambda0) == 48, "");
_Static_assert(sizeof(struct list_tests__lambda1) == 8, "");
_Static_assert(sizeof(struct mut_list_4) == 24, "");
_Static_assert(sizeof(struct mut_arr_5) == 16, "");
_Static_assert(sizeof(struct flat_map_with_max_size__lambda0) == 32, "");
_Static_assert(sizeof(struct push_all__lambda0) == 8, "");
_Static_assert(sizeof(struct some_10) == 8, "");
_Static_assert(sizeof(struct run_noze_tests__lambda0) == 40, "");
_Static_assert(sizeof(struct some_11) == 16, "");
_Static_assert(sizeof(struct run_single_noze_test__lambda0) == 56, "");
_Static_assert(sizeof(struct print_test_result) == 24, "");
_Static_assert(sizeof(struct process_result) == 40, "");
_Static_assert(sizeof(struct pipes) == 8, "");
_Static_assert(sizeof(struct posix_spawn_file_actions_t) == 80, "");
_Static_assert(sizeof(struct cell_5) == 4, "");
_Static_assert(sizeof(struct mut_list_5) == 24, "");
_Static_assert(sizeof(struct pollfd) == 8, "");
_Static_assert(sizeof(struct arr_8) == 16, "");
_Static_assert(sizeof(struct handle_revents_result) == 2, "");
_Static_assert(sizeof(struct mut_arr_6) == 16, "");
_Static_assert(sizeof(struct map_1__lambda0) == 24, "");
_Static_assert(sizeof(struct mut_list_6) == 24, "");
_Static_assert(sizeof(struct convert_environ__lambda0) == 8, "");
_Static_assert(sizeof(struct do_test__lambda0) == 56, "");
_Static_assert(sizeof(struct do_test__lambda0__lambda0) == 56, "");
_Static_assert(sizeof(struct do_test__lambda1) == 32, "");
_Static_assert(sizeof(struct excluded_from_lint__q__lambda0) == 16, "");
_Static_assert(sizeof(struct list_lintable_files__lambda1) == 8, "");
_Static_assert(sizeof(struct lint__lambda0) == 16, "");
_Static_assert(sizeof(struct lines__lambda0) == 32, "");
_Static_assert(sizeof(struct lint_file__lambda0) == 32, "");
_Static_assert(sizeof(struct comparison) == 8, "");
_Static_assert(sizeof(struct fut_state_0) == 24, "");
_Static_assert(sizeof(struct result_0) == 24, "");
_Static_assert(sizeof(struct fun_act1_0) == 16, "");
_Static_assert(sizeof(struct opt_0) == 16, "");
_Static_assert(sizeof(struct opt_1) == 16, "");
_Static_assert(sizeof(struct fun_act0_0) == 16, "");
_Static_assert(sizeof(struct opt_2) == 16, "");
_Static_assert(sizeof(struct fun1_0) == 8, "");
_Static_assert(sizeof(struct log_level) == 8, "");
_Static_assert(sizeof(struct fun1_1) == 8, "");
_Static_assert(sizeof(struct opt_3) == 16, "");
_Static_assert(sizeof(struct fun2) == 8, "");
_Static_assert(sizeof(struct fut_state_1) == 24, "");
_Static_assert(sizeof(struct result_1) == 24, "");
_Static_assert(sizeof(struct fun_act1_1) == 16, "");
_Static_assert(sizeof(struct opt_4) == 16, "");
_Static_assert(sizeof(struct fun_act0_1) == 16, "");
_Static_assert(sizeof(struct fun_act1_2) == 16, "");
_Static_assert(sizeof(struct fun_act1_3) == 16, "");
_Static_assert(sizeof(struct fun_act1_4) == 8, "");
_Static_assert(sizeof(struct fun_act1_5) == 16, "");
_Static_assert(sizeof(struct choose_task_result) == 56, "");
_Static_assert(sizeof(struct task_or_gc) == 40, "");
_Static_assert(sizeof(struct opt_5) == 16, "");
_Static_assert(sizeof(struct choose_task_in_island_result) == 40, "");
_Static_assert(sizeof(struct pop_task_result) == 40, "");
_Static_assert(sizeof(struct opt_6) == 24, "");
_Static_assert(sizeof(struct opt_7) == 24, "");
_Static_assert(sizeof(struct fun1_2) == 8, "");
_Static_assert(sizeof(struct fun_act1_6) == 16, "");
_Static_assert(sizeof(struct opt_8) == 24, "");
_Static_assert(sizeof(struct fun_act1_7) == 16, "");
_Static_assert(sizeof(struct fun_act2_0) == 16, "");
_Static_assert(sizeof(struct fun_act1_8) == 16, "");
_Static_assert(sizeof(struct result_2) == 24, "");
_Static_assert(sizeof(struct fun0) == 16, "");
_Static_assert(sizeof(struct fun_act1_9) == 16, "");
_Static_assert(sizeof(struct fun_act1_10) == 16, "");
_Static_assert(sizeof(struct opt_9) == 16, "");
_Static_assert(sizeof(struct fun_act1_11) == 16, "");
_Static_assert(sizeof(struct fun_act1_12) == 16, "");
_Static_assert(sizeof(struct opt_10) == 16, "");
_Static_assert(sizeof(struct opt_11) == 24, "");
_Static_assert(sizeof(struct fun_act1_13) == 16, "");
_Static_assert(sizeof(struct fun_act2_1) == 8, "");
_Static_assert(sizeof(struct fun_act1_14) == 8, "");
_Static_assert(sizeof(struct fun_act1_15) == 16, "");
_Static_assert(sizeof(struct fun_act2_2) == 16, "");
_Static_assert(sizeof(struct fun_act2_3) == 16, "");
_Static_assert(sizeof(struct fun_act2_4) == 16, "");
char constantarr_0_0[17];
char constantarr_0_1[4];
char constantarr_0_2[20];
char constantarr_0_3[1];
char constantarr_0_4[17];
char constantarr_0_5[13];
char constantarr_0_6[13];
char constantarr_0_7[4];
char constantarr_0_8[4];
char constantarr_0_9[2];
char constantarr_0_10[38];
char constantarr_0_11[33];
char constantarr_0_12[40];
char constantarr_0_13[11];
char constantarr_0_14[13];
char constantarr_0_15[11];
char constantarr_0_16[16];
char constantarr_0_17[12];
char constantarr_0_18[2];
char constantarr_0_19[27];
char constantarr_0_20[26];
char constantarr_0_21[4];
char constantarr_0_22[15];
char constantarr_0_23[18];
char constantarr_0_24[8];
char constantarr_0_25[38];
char constantarr_0_26[64];
char constantarr_0_27[1];
char constantarr_0_28[14];
char constantarr_0_29[1];
char constantarr_0_30[3];
char constantarr_0_31[4];
char constantarr_0_32[1];
char constantarr_0_33[2];
char constantarr_0_34[2];
char constantarr_0_35[3];
char constantarr_0_36[5];
char constantarr_0_37[14];
char constantarr_0_38[9];
char constantarr_0_39[11];
char constantarr_0_40[1];
char constantarr_0_41[23];
char constantarr_0_42[31];
char constantarr_0_43[1];
char constantarr_0_44[1];
char constantarr_0_45[1];
char constantarr_0_46[1];
char constantarr_0_47[1];
char constantarr_0_48[1];
char constantarr_0_49[1];
char constantarr_0_50[1];
char constantarr_0_51[1];
char constantarr_0_52[1];
char constantarr_0_53[1];
char constantarr_0_54[12];
char constantarr_0_55[1];
char constantarr_0_56[14];
char constantarr_0_57[5];
char constantarr_0_58[5];
char constantarr_0_59[20];
char constantarr_0_60[31];
char constantarr_0_61[7];
char constantarr_0_62[7];
char constantarr_0_63[12];
char constantarr_0_64[29];
char constantarr_0_65[30];
char constantarr_0_66[4];
char constantarr_0_67[22];
char constantarr_0_68[9];
char constantarr_0_69[3];
char constantarr_0_70[11];
char constantarr_0_71[7];
char constantarr_0_72[8];
char constantarr_0_73[9];
char constantarr_0_74[8];
char constantarr_0_75[4];
char constantarr_0_76[10];
char constantarr_0_77[12];
char constantarr_0_78[14];
char constantarr_0_79[8];
char constantarr_0_80[4];
char constantarr_0_81[4];
char constantarr_0_82[5];
char constantarr_0_83[7];
char constantarr_0_84[7];
char constantarr_0_85[12];
char constantarr_0_86[17];
char constantarr_0_87[1];
char constantarr_0_88[4];
char constantarr_0_89[1];
char constantarr_0_90[3];
char constantarr_0_91[4];
char constantarr_0_92[10];
char constantarr_0_93[5];
char constantarr_0_94[21];
char constantarr_0_95[3];
char constantarr_0_96[2];
char constantarr_0_97[5];
char constantarr_0_98[24];
char constantarr_0_99[4];
char constantarr_0_100[28];
char constantarr_0_101[7];
char constantarr_0_102[6];
char constantarr_0_103[4];
char constantarr_0_104[3];
char constantarr_0_105[15];
char constantarr_0_106[9];
struct arr_0 constantarr_1_0[3];
struct arr_0 constantarr_1_1[4];
struct arr_0 constantarr_1_2[5];
struct arr_0 constantarr_1_3[4];
struct arr_0 constantarr_1_4[6];
char constantarr_0_0[17] = "Assertion failed!";
char constantarr_0_1[4] = "TODO";
char constantarr_0_2[20] = "uncaught exception: ";
char constantarr_0_3[1] = "\n";
char constantarr_0_4[17] = "<<empty message>>";
char constantarr_0_5[13] = "assert failed";
char constantarr_0_6[13] = "forbid failed";
char constantarr_0_7[4] = "info";
char constantarr_0_8[4] = "warn";
char constantarr_0_9[2] = ": ";
char constantarr_0_10[38] = "Couldn't acquire lock after 1000 tries";
char constantarr_0_11[33] = "resolving an already-resolved fut";
char constantarr_0_12[40] = "Did not find the element in the mut-list";
char constantarr_0_13[11] = "unreachable";
char constantarr_0_14[13] = "main failed: ";
char constantarr_0_15[11] = "print-tests";
char constantarr_0_16[16] = "overwrite-output";
char constantarr_0_17[12] = "max-failures";
char constantarr_0_18[2] = "--";
char constantarr_0_19[27] = "tried to force empty option";
char constantarr_0_20[26] = "Should be no nameless args";
char constantarr_0_21[4] = "help";
char constantarr_0_22[15] = "Unexpected arg ";
char constantarr_0_23[18] = "test -- runs tests";
char constantarr_0_24[8] = "options:";
char constantarr_0_25[38] = "\t--print-tests  : print every test run";
char constantarr_0_26[64] = "\t--max-failures : stop after this many failures. Defaults to 10.";
char constantarr_0_27[1] = "\0";
char constantarr_0_28[14] = "/proc/self/exe";
char constantarr_0_29[1] = "/";
char constantarr_0_30[3] = "bin";
char constantarr_0_31[4] = "noze";
char constantarr_0_32[1] = ".";
char constantarr_0_33[2] = "..";
char constantarr_0_34[2] = "nz";
char constantarr_0_35[3] = "ast";
char constantarr_0_36[5] = "model";
char constantarr_0_37[14] = "concrete-model";
char constantarr_0_38[9] = "low-model";
char constantarr_0_39[11] = "noze print ";
char constantarr_0_40[1] = " ";
char constantarr_0_41[23] = "spawn-and-wait-result: ";
char constantarr_0_42[31] = "Process terminated with signal ";
char constantarr_0_43[1] = "0";
char constantarr_0_44[1] = "1";
char constantarr_0_45[1] = "2";
char constantarr_0_46[1] = "3";
char constantarr_0_47[1] = "4";
char constantarr_0_48[1] = "5";
char constantarr_0_49[1] = "6";
char constantarr_0_50[1] = "7";
char constantarr_0_51[1] = "8";
char constantarr_0_52[1] = "9";
char constantarr_0_53[1] = "-";
char constantarr_0_54[12] = "WAIT STOPPED";
char constantarr_0_55[1] = "=";
char constantarr_0_56[14] = " is not a file";
char constantarr_0_57[5] = "print";
char constantarr_0_58[5] = ".tata";
char constantarr_0_59[20] = "failed to open file ";
char constantarr_0_60[31] = "failed to open file for write: ";
char constantarr_0_61[7] = "errno: ";
char constantarr_0_62[7] = "flags: ";
char constantarr_0_63[12] = "permission: ";
char constantarr_0_64[29] = " does not exist. actual was:\n";
char constantarr_0_65[30] = " was not as expected. actual:\n";
char constantarr_0_66[4] = ".err";
char constantarr_0_67[22] = "unexpected exit code: ";
char constantarr_0_68[9] = "noze run ";
char constantarr_0_69[3] = "run";
char constantarr_0_70[11] = "--interpret";
char constantarr_0_71[7] = ".stdout";
char constantarr_0_72[8] = "status: ";
char constantarr_0_73[9] = "\nstdout:\n";
char constantarr_0_74[8] = "stderr:\n";
char constantarr_0_75[4] = "ran ";
char constantarr_0_76[10] = " tests in ";
char constantarr_0_77[12] = "parse-errors";
char constantarr_0_78[14] = "compile-errors";
char constantarr_0_79[8] = "runnable";
char constantarr_0_80[4] = ".bmp";
char constantarr_0_81[4] = ".png";
char constantarr_0_82[5] = ".wasm";
char constantarr_0_83[7] = "dyncall";
char constantarr_0_84[7] = "libfirm";
char constantarr_0_85[12] = "node_modules";
char constantarr_0_86[17] = "package-lock.json";
char constantarr_0_87[1] = "c";
char constantarr_0_88[4] = "data";
char constantarr_0_89[1] = "o";
char constantarr_0_90[3] = "out";
char constantarr_0_91[4] = "tata";
char constantarr_0_92[10] = "tmLanguage";
char constantarr_0_93[5] = "lint ";
char constantarr_0_94[21] = "file does not exist: ";
char constantarr_0_95[3] = "err";
char constantarr_0_96[2] = "  ";
char constantarr_0_97[5] = "line ";
char constantarr_0_98[24] = " contains a double space";
char constantarr_0_99[4] = " is ";
char constantarr_0_100[28] = " columns long, should be <= ";
char constantarr_0_101[7] = "linted ";
char constantarr_0_102[6] = " files";
char constantarr_0_103[4] = "\x1b[1m";
char constantarr_0_104[3] = "\x1b[m";
char constantarr_0_105[15] = "hit maximum of ";
char constantarr_0_106[9] = " failures";
struct arr_0 constantarr_1_0[3] = {{11, constantarr_0_15}, {16, constantarr_0_16}, {12, constantarr_0_17}};
struct arr_0 constantarr_1_1[4] = {{3, constantarr_0_35}, {5, constantarr_0_36}, {14, constantarr_0_37}, {9, constantarr_0_38}};
struct arr_0 constantarr_1_2[5] = {{4, constantarr_0_80}, {4, constantarr_0_66}, {4, constantarr_0_81}, {5, constantarr_0_58}, {5, constantarr_0_82}};
struct arr_0 constantarr_1_3[4] = {{7, constantarr_0_83}, {7, constantarr_0_84}, {12, constantarr_0_85}, {17, constantarr_0_86}};
struct arr_0 constantarr_1_4[6] = {{1, constantarr_0_87}, {4, constantarr_0_88}, {1, constantarr_0_89}, {3, constantarr_0_90}, {4, constantarr_0_91}, {10, constantarr_0_92}};
uint8_t mark(struct mark_ctx* ctx, uint8_t* ptr_any, uint64_t size_bytes);
uint64_t words_of_bytes(uint64_t size_bytes);
uint64_t round_up_to_multiple_of_8(uint64_t n);
struct void_ hard_assert(uint8_t condition);
uint8_t _op_equal_equal_0(uint64_t a, uint64_t b);
struct comparison compare_5(uint64_t a, uint64_t b);
uint64_t _op_minus_0(uint64_t* a, uint64_t* b);
uint8_t _op_less_0(uint64_t a, uint64_t b);
uint8_t _op_less_equal(uint64_t a, uint64_t b);
uint8_t mark_range_recur(uint8_t marked_anything__q, uint8_t* cur, uint8_t* end);
uint8_t* incr_0(uint8_t* p);
uint8_t _op_greater(uint64_t a, uint64_t b);
int32_t rt_main(int32_t argc, char** argv, fun_ptr2 main_ptr);
extern uint64_t get_nprocs(void);
struct lock new_lock(void);
struct _atomic_bool new_atomic_bool(void);
struct arr_3 empty_arr_0(void);
struct condition new_condition(void);
struct island new_island(struct global_ctx* gctx, uint64_t id, uint64_t max_threads);
struct task_queue new_task_queue(uint64_t max_threads);
struct mut_list_0 new_mut_list_by_val_with_capacity_from_unmanaged_memory(uint64_t capacity);
struct mut_arr_0 mut_arr_0(uint64_t size, uint64_t* data);
uint64_t* unmanaged_alloc_zeroed_elements(uint64_t size_elements);
uint64_t* unmanaged_alloc_elements_0(uint64_t size_elements);
uint8_t* unmanaged_alloc_bytes(uint64_t size);
extern uint8_t* malloc(uint64_t size);
struct void_ hard_forbid(uint8_t condition);
uint8_t null__q_0(uint8_t* a);
struct void_ set_zero_range_0(uint64_t* begin, uint64_t size);
extern void memset(uint8_t* begin, uint8_t value, uint64_t size);
struct void_ default_exception_handler(struct ctx* ctx, struct exception e);
struct void_ print_err_no_newline(struct arr_0 s);
struct void_ write_no_newline(int32_t fd, struct arr_0 a);
extern int64_t write(int32_t fd, uint8_t* buf, uint64_t n_bytes);
uint8_t _op_bang_equal_0(int64_t a, int64_t b);
uint8_t _op_equal_equal_1(int64_t a, int64_t b);
struct comparison compare_36(int64_t a, int64_t b);
struct void_ todo_0(void);
int32_t stderr(void);
struct void_ print_err(struct arr_0 s);
uint8_t empty__q_0(struct arr_0 a);
struct global_ctx* get_global_ctx(struct ctx* ctx);
struct void_ new_island__lambda0(struct ctx* ctx, struct void_ _closure, struct exception it);
struct void_ default_log_handler(struct ctx* ctx, struct logged* a);
struct void_ print(struct arr_0 a);
struct void_ print_no_newline(struct arr_0 a);
int32_t stdout(void);
struct arr_0 _op_plus_0(struct ctx* ctx, struct arr_0 a, struct arr_0 b);
uint64_t _op_plus_1(struct ctx* ctx, uint64_t a, uint64_t b);
struct void_ assert_0(struct ctx* ctx, uint8_t condition);
struct void_ assert_1(struct ctx* ctx, uint8_t condition, struct arr_0 message);
struct void_ fail_0(struct ctx* ctx, struct arr_0 reason);
struct void_ throw_0(struct ctx* ctx, struct exception e);
struct exception_ctx* get_exception_ctx(struct ctx* ctx);
uint8_t null__q_1(struct jmp_buf_tag* a);
extern void longjmp(struct jmp_buf_tag* env, int32_t val);
int32_t number_to_throw(struct ctx* ctx);
uint8_t _op_greater_equal(uint64_t a, uint64_t b);
char* uninitialized_data_0(struct ctx* ctx, uint64_t size);
uint8_t* alloc(struct ctx* ctx, uint64_t size);
uint8_t* gc_alloc(struct ctx* ctx, struct gc* gc, uint64_t size);
struct opt_3 try_gc_alloc(struct gc* gc, uint64_t size_bytes);
struct void_ validate_gc(struct gc* gc);
uint8_t ptr_less_eq__q_0(uint8_t* a, uint8_t* b);
uint8_t ptr_less_eq__q_1(uint64_t* a, uint64_t* b);
uint64_t _op_minus_1(uint8_t* a, uint8_t* b);
uint8_t range_free__q(uint8_t* mark, uint8_t* end);
uint64_t* incr_1(uint64_t* p);
uint8_t* todo_1(void);
struct gc* get_gc(struct ctx* ctx);
struct gc_ctx* get_gc_ctx_0(struct ctx* ctx);
struct void_ copy_data_from_0(struct ctx* ctx, char* to, char* from, uint64_t len);
struct void_ copy_data_from_small_0(struct ctx* ctx, char* to, char* from, uint64_t len);
uint8_t _op_bang_equal_1(uint64_t a, uint64_t b);
char* incr_2(char* p);
uint64_t decr(struct ctx* ctx, uint64_t a);
struct void_ forbid_0(struct ctx* ctx, uint8_t condition);
struct void_ forbid_1(struct ctx* ctx, uint8_t condition, struct arr_0 message);
uint64_t wrap_decr(uint64_t a);
uint64_t _op_div(struct ctx* ctx, uint64_t a, uint64_t b);
uint64_t _op_minus_2(struct ctx* ctx, uint64_t a, uint64_t b);
struct arr_0 to_str_0(struct ctx* ctx, struct log_level a);
struct void_ new_island__lambda1(struct ctx* ctx, struct void_ _closure, struct logged* log);
struct gc new_gc(void);
struct thread_safe_counter new_thread_safe_counter_0(void);
struct thread_safe_counter new_thread_safe_counter_1(uint64_t init);
struct fut_0* do_main(struct global_ctx* gctx, struct island* island, int32_t argc, char** argv, fun_ptr2 main_ptr);
struct exception_ctx new_exception_ctx(void);
struct log_ctx new_log_ctx(void);
struct ctx new_ctx(struct global_ctx* gctx, struct thread_local_stuff* tls, struct island* island, uint64_t exclusion);
struct gc_ctx* get_gc_ctx_1(struct gc* gc);
struct void_ acquire_lock(struct lock* a);
struct void_ acquire_lock_recur(struct lock* a, uint64_t n_tries);
uint8_t try_acquire_lock(struct lock* a);
uint8_t try_set(struct _atomic_bool* a);
uint8_t try_change(struct _atomic_bool* a, uint8_t old_value);
struct void_ yield_thread(void);
extern int32_t pthread_yield(void);
uint8_t _op_equal_equal_2(int32_t a, int32_t b);
struct comparison compare_99(int32_t a, int32_t b);
uint64_t noctx_incr(uint64_t n);
uint64_t max_nat(void);
uint64_t wrap_incr(uint64_t a);
struct void_ release_lock(struct lock* l);
struct void_ must_unset(struct _atomic_bool* a);
uint8_t try_unset(struct _atomic_bool* a);
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb);
struct fut_0* then_0(struct ctx* ctx, struct fut_1* f, struct fun_ref1 cb);
struct fut_0* new_unresolved_fut(struct ctx* ctx);
struct void_ then_void_0(struct ctx* ctx, struct fut_1* f, struct fun_act1_1 cb);
struct void_ call_0(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0);
struct void_ call_w_ctx_112(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0);
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to);
struct void_ then_void_1(struct ctx* ctx, struct fut_0* f, struct fun_act1_0 cb);
struct void_ call_1(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0);
struct void_ call_w_ctx_116(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0);
struct void_ resolve_or_reject(struct ctx* ctx, struct fut_0* f, struct result_0 result);
struct void_ resolve_or_reject_recur(struct ctx* ctx, struct opt_0 node, struct result_0 value);
struct void_ drop_0(struct void_ _p0);
struct void_ forward_to__lambda0(struct ctx* ctx, struct forward_to__lambda0* _closure, struct result_0 it);
struct fut_0* call_ref_0(struct ctx* ctx, struct fun_ref1 f, struct void_ p0);
struct island* get_island(struct ctx* ctx, uint64_t island_id);
struct island* at_0(struct ctx* ctx, struct arr_3 a, uint64_t index);
struct island* noctx_at_0(struct arr_3 a, uint64_t index);
struct void_ add_task_0(struct ctx* ctx, struct island* a, uint64_t exclusion, struct fun_act0_0 action);
struct void_ add_task_1(struct ctx* ctx, struct island* a, uint64_t timestamp, uint64_t exclusion, struct fun_act0_0 action);
struct task_queue_node* new_task_queue_node(struct ctx* ctx, struct task task);
struct void_ insert_task(struct task_queue* a, struct task_queue_node* inserted);
uint64_t size_0(struct task_queue* a);
uint64_t size_recur(struct opt_2 node, uint64_t acc);
struct void_ insert_recur(struct task_queue_node* prev, struct task_queue_node* inserted);
struct task_queue* tasks(struct island* a);
struct void_ broadcast(struct condition* c);
uint64_t no_timestamp(void);
struct void_ catch(struct ctx* ctx, struct fun_act0_0 try, struct fun_act1_3 catcher);
struct void_ catch_with_exception_ctx(struct ctx* ctx, struct exception_ctx* ec, struct fun_act0_0 try, struct fun_act1_3 catcher);
struct bytes64 zero_0(void);
struct bytes32 zero_1(void);
struct bytes16 zero_2(void);
struct bytes128 zero_3(void);
extern int32_t setjmp(struct jmp_buf_tag* env);
struct void_ call_2(struct ctx* ctx, struct fun_act0_0 a);
struct void_ call_w_ctx_143(struct fun_act0_0 a, struct ctx* ctx);
struct void_ call_3(struct ctx* ctx, struct fun_act1_3 a, struct exception p0);
struct void_ call_w_ctx_145(struct fun_act1_3 a, struct ctx* ctx, struct exception p0);
struct fut_0* call_4(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0);
struct fut_0* call_w_ctx_147(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0);
struct void_ call_ref_0__lambda0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0__lambda0* _closure);
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e);
struct void_ call_ref_0__lambda0__lambda1(struct ctx* ctx, struct call_ref_0__lambda0__lambda1* _closure, struct exception it);
struct void_ call_ref_0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0* _closure);
struct void_ then_0__lambda0(struct ctx* ctx, struct then_0__lambda0* _closure, struct result_1 result);
struct fut_0* call_ref_1(struct ctx* ctx, struct fun_ref0 f);
struct fut_0* call_5(struct ctx* ctx, struct fun_act0_1 a);
struct fut_0* call_w_ctx_155(struct fun_act0_1 a, struct ctx* ctx);
struct void_ call_ref_1__lambda0__lambda0(struct ctx* ctx, struct call_ref_1__lambda0__lambda0* _closure);
struct void_ call_ref_1__lambda0__lambda1(struct ctx* ctx, struct call_ref_1__lambda0__lambda1* _closure, struct exception it);
struct void_ call_ref_1__lambda0(struct ctx* ctx, struct call_ref_1__lambda0* _closure);
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore);
struct island_and_exclusion cur_island_and_exclusion(struct ctx* ctx);
struct fut_1* delay(struct ctx* ctx);
struct fut_1* resolved_0(struct ctx* ctx, struct void_ value);
struct arr_4 tail_0(struct ctx* ctx, struct arr_4 a);
uint8_t empty__q_1(struct arr_4 a);
struct arr_4 slice_starting_at_0(struct ctx* ctx, struct arr_4 a, uint64_t begin);
struct arr_4 slice_0(struct ctx* ctx, struct arr_4 a, uint64_t begin, uint64_t size);
struct arr_1 map_0(struct ctx* ctx, struct arr_4 a, struct fun_act1_4 mapper);
struct arr_1 make_arr_0(struct ctx* ctx, uint64_t size, struct fun_act1_5 f);
struct arr_1 cast_immutable_0(struct mut_arr_1 a);
struct mut_arr_1 make_mut_arr_0(struct ctx* ctx, uint64_t size, struct fun_act1_5 f);
struct mut_arr_1 new_uninitialized_mut_arr_0(struct ctx* ctx, uint64_t size);
struct mut_arr_1 mut_arr_1(uint64_t size, struct arr_0* data);
struct arr_0* uninitialized_data_1(struct ctx* ctx, uint64_t size);
struct void_ make_mut_arr_worker_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t i, struct fun_act1_5 f);
uint64_t size_1(struct mut_arr_1 a);
struct void_ set_at_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t index, struct arr_0 value);
struct void_ noctx_set_at_0(struct mut_arr_1 a, uint64_t index, struct arr_0 value);
struct arr_0* data_0(struct mut_arr_1 a);
struct arr_0 call_6(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0);
struct arr_0 call_w_ctx_180(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0);
uint64_t incr_3(struct ctx* ctx, uint64_t n);
struct arr_0 call_7(struct ctx* ctx, struct fun_act1_4 a, char* p0);
struct arr_0 call_w_ctx_183(struct fun_act1_4 a, struct ctx* ctx, char* p0);
char* at_1(struct ctx* ctx, struct arr_4 a, uint64_t index);
char* noctx_at_1(struct arr_4 a, uint64_t index);
struct arr_0 map_0__lambda0(struct ctx* ctx, struct map_0__lambda0* _closure, uint64_t i);
struct arr_0 to_str_1(char* a);
struct arr_0 arr_from_begin_end(char* begin, char* end);
uint64_t _op_minus_3(char* a, char* b);
char* find_cstr_end(char* a);
char* find_char_in_cstr(char* a, char c);
uint8_t _op_equal_equal_3(char a, char b);
struct comparison compare_193(char a, char b);
char* todo_2(void);
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it);
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure);
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* call_w_ctx_198(struct fun2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1);
struct void_ run_threads(uint64_t n_threads, struct global_ctx* gctx);
struct thread_args* unmanaged_alloc_elements_1(uint64_t size_elements);
uint64_t noctx_decr(uint64_t n);
struct void_ start_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads, struct thread_args* thread_args_begin, struct global_ctx* gctx);
struct void_ create_one_thread(struct cell_0* tid, uint8_t* thread_arg, fun_ptr1 thread_fun);
extern int32_t pthread_create(struct cell_0* thread, uint8_t* attr, fun_ptr1 start_routine, uint8_t* arg);
uint8_t _op_bang_equal_2(int32_t a, int32_t b);
int32_t eagain(void);
struct cell_0* as_cell(uint64_t* p);
uint8_t* thread_fun(uint8_t* args_ptr);
struct void_ thread_function(uint64_t thread_id, struct global_ctx* gctx);
struct void_ thread_function_recur(uint64_t thread_id, struct global_ctx* gctx, struct thread_local_stuff* tls);
struct void_ assert_islands_are_shut_down(uint64_t i, struct arr_3 islands);
uint8_t empty__q_2(struct task_queue* a);
uint8_t has__q_0(struct opt_2 a);
uint8_t empty__q_3(struct opt_2 a);
uint64_t get_last_checked(struct condition* c);
struct choose_task_result choose_task(struct global_ctx* gctx);
uint64_t get_monotime_nsec(void);
extern int32_t clock_gettime(int32_t clock_it, struct cell_1* tp);
int32_t clock_monotonic(void);
struct timespec get_0(struct cell_1* c);
uint64_t todo_3(void);
struct choose_task_result choose_task_recur(struct arr_3 islands, uint64_t i, uint64_t cur_time, uint8_t any_tasks__q, struct opt_5 first_task_time);
struct choose_task_in_island_result choose_task_in_island(struct island* island, uint64_t cur_time);
struct pop_task_result pop_task(struct task_queue* a, uint64_t cur_time);
uint8_t contains__q_0(struct mut_list_0* a, uint64_t value);
uint8_t contains__q_1(struct arr_2 a, uint64_t value);
uint8_t contains_recur__q_0(struct arr_2 a, uint64_t value, uint64_t i);
uint64_t noctx_at_2(struct arr_2 a, uint64_t index);
struct arr_2 temp_as_arr_0(struct mut_list_0* a);
struct arr_2 temp_as_arr_1(struct mut_arr_0 a);
struct mut_arr_0 temp_as_mut_arr_0(struct mut_list_0* a);
uint64_t* data_1(struct mut_list_0* a);
uint64_t* data_2(struct mut_arr_0 a);
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list_0* exclusions, uint64_t cur_time, struct opt_5 first_task_time);
struct opt_5 to_opt_time(uint64_t a);
struct void_ push_capacity_must_be_sufficient(struct mut_list_0* a, uint64_t value);
uint64_t capacity_0(struct mut_list_0* a);
uint64_t size_2(struct mut_arr_0 a);
struct void_ noctx_set_at_1(struct mut_list_0* a, uint64_t index, uint64_t value);
uint8_t is_no_task__q(struct choose_task_in_island_result a);
struct opt_5 min_time(struct opt_5 a, struct opt_5 b);
uint64_t min(uint64_t a, uint64_t b);
struct void_ do_task(struct global_ctx* gctx, struct thread_local_stuff* tls, struct chosen_task chosen_task);
struct void_ return_task(struct task_queue* a, struct task task);
struct void_ noctx_must_remove_unordered(struct mut_list_0* a, uint64_t value);
struct void_ noctx_must_remove_unordered_recur(struct mut_list_0* a, uint64_t index, uint64_t value);
uint64_t noctx_at_3(struct mut_list_0* a, uint64_t index);
struct void_ drop_1(uint64_t _p0);
uint64_t noctx_remove_unordered_at_index(struct mut_list_0* a, uint64_t index);
uint64_t noctx_last(struct mut_list_0* a);
uint8_t empty__q_4(struct mut_list_0* a);
struct void_ return_ctx(struct ctx* c);
struct void_ return_gc_ctx(struct gc_ctx* gc_ctx);
struct void_ run_garbage_collection(struct gc* gc, struct island_gc_root gc_root);
struct void_ mark_visit_255(struct mark_ctx* mark_ctx, struct island_gc_root value);
struct void_ mark_visit_256(struct mark_ctx* mark_ctx, struct task_queue value);
struct void_ mark_visit_257(struct mark_ctx* mark_ctx, struct opt_2 value);
struct void_ mark_visit_258(struct mark_ctx* mark_ctx, struct some_2 value);
struct void_ mark_visit_259(struct mark_ctx* mark_ctx, struct task_queue_node value);
struct void_ mark_visit_260(struct mark_ctx* mark_ctx, struct task value);
struct void_ mark_visit_261(struct mark_ctx* mark_ctx, struct fun_act0_0 value);
struct void_ mark_visit_262(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0 value);
struct void_ mark_visit_263(struct mark_ctx* mark_ctx, struct fun_ref1 value);
struct void_ mark_visit_264(struct mark_ctx* mark_ctx, struct fun_act1_2 value);
struct void_ mark_visit_265(struct mark_ctx* mark_ctx, struct then2__lambda0 value);
struct void_ mark_visit_266(struct mark_ctx* mark_ctx, struct fun_ref0 value);
struct void_ mark_visit_267(struct mark_ctx* mark_ctx, struct fun_act0_1 value);
struct void_ mark_visit_268(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value);
struct void_ mark_arr_269(struct mark_ctx* mark_ctx, struct arr_4 a);
struct void_ mark_visit_270(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value);
struct void_ mark_visit_271(struct mark_ctx* mark_ctx, struct then2__lambda0* value);
struct void_ mark_visit_272(struct mark_ctx* mark_ctx, struct fut_0 value);
struct void_ mark_visit_273(struct mark_ctx* mark_ctx, struct fut_state_0 value);
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value);
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct opt_0 value);
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct some_0 value);
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value);
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct fun_act1_0 value);
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value);
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct fut_0* value);
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value);
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value);
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct exception value);
struct void_ mark_arr_284(struct mark_ctx* mark_ctx, struct arr_0 a);
struct void_ mark_visit_285(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0* value);
struct void_ mark_visit_286(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0 value);
struct void_ mark_visit_287(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0* value);
struct void_ mark_visit_288(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0 value);
struct void_ mark_visit_289(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0* value);
struct void_ mark_visit_290(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0 value);
struct void_ mark_visit_291(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0* value);
struct void_ mark_visit_292(struct mark_ctx* mark_ctx, struct task_queue_node* value);
struct void_ mark_visit_293(struct mark_ctx* mark_ctx, struct mut_list_0 value);
struct void_ mark_visit_294(struct mark_ctx* mark_ctx, struct mut_arr_0 value);
struct void_ mark_arr_295(struct mark_ctx* mark_ctx, struct arr_2 a);
struct void_ clear_free_mem(uint8_t* mark_ptr, uint8_t* mark_end, uint64_t* data_ptr);
struct void_ wait_on(struct condition* cond, struct opt_5 until_time, uint64_t last_checked);
uint8_t before_time__q(struct opt_5 until_time);
struct void_ join_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads);
struct void_ join_one_thread(uint64_t tid);
extern int32_t pthread_join(uint64_t thread, struct cell_2* thread_return);
int32_t einval(void);
int32_t esrch(void);
uint8_t* get_1(struct cell_2* c);
struct void_ unmanaged_free_0(uint64_t* p);
extern void free(uint8_t* p);
struct void_ unmanaged_free_1(struct thread_args* p);
struct result_0 must_be_resolved(struct fut_0* f);
struct result_0 hard_unreachable_0(void);
struct fut_0* main_0(struct ctx* ctx, struct arr_1 args);
struct opt_6 parse_cmd_line_args(struct ctx* ctx, struct arr_1 args, struct arr_1 t_names, struct fun1_2 make_t);
struct parsed_cmd_line_args* parse_cmd_line_args_dynamic(struct ctx* ctx, struct arr_1 args);
struct opt_5 find_index(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 pred);
struct opt_5 find_index_recur(struct ctx* ctx, struct arr_1 a, uint64_t index, struct fun_act1_6 pred);
uint8_t call_8(struct ctx* ctx, struct fun_act1_6 a, struct arr_0 p0);
uint8_t call_w_ctx_316(struct fun_act1_6 a, struct ctx* ctx, struct arr_0 p0);
struct arr_0 at_2(struct ctx* ctx, struct arr_1 a, uint64_t index);
struct arr_0 noctx_at_4(struct arr_1 a, uint64_t index);
uint8_t starts_with__q(struct ctx* ctx, struct arr_0 a, struct arr_0 start);
uint8_t arr_eq__q(struct ctx* ctx, struct arr_0 a, struct arr_0 b);
char first_0(struct ctx* ctx, struct arr_0 a);
char at_3(struct ctx* ctx, struct arr_0 a, uint64_t index);
char noctx_at_5(struct arr_0 a, uint64_t index);
struct arr_0 tail_1(struct ctx* ctx, struct arr_0 a);
struct arr_0 slice_starting_at_1(struct ctx* ctx, struct arr_0 a, uint64_t begin);
struct arr_0 slice_1(struct ctx* ctx, struct arr_0 a, uint64_t begin, uint64_t size);
uint8_t parse_cmd_line_args_dynamic__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it);
struct dict_0* empty_dict(struct ctx* ctx);
struct arr_1 empty_arr_1(void);
struct arr_6 empty_arr_2(void);
struct arr_1 slice_up_to_0(struct ctx* ctx, struct arr_1 a, uint64_t size);
struct arr_1 slice_2(struct ctx* ctx, struct arr_1 a, uint64_t begin, uint64_t size);
struct arr_1 slice_starting_at_2(struct ctx* ctx, struct arr_1 a, uint64_t begin);
uint8_t _op_equal_equal_4(struct arr_0 a, struct arr_0 b);
struct comparison compare_335(struct arr_0 a, struct arr_0 b);
uint8_t parse_cmd_line_args_dynamic__lambda1(struct ctx* ctx, struct void_ _closure, struct arr_0 it);
struct dict_0* parse_named_args(struct ctx* ctx, struct arr_1 args);
struct mut_dict_0 new_mut_dict_0(struct ctx* ctx);
struct mut_list_1* new_mut_list_0(struct ctx* ctx);
struct mut_arr_1 empty_mut_arr_0(void);
struct mut_list_2* new_mut_list_1(struct ctx* ctx);
struct mut_arr_2 empty_mut_arr_1(void);
struct void_ parse_named_args_recur(struct ctx* ctx, struct arr_1 args, struct mut_dict_0 builder);
struct arr_0 remove_start(struct ctx* ctx, struct arr_0 a, struct arr_0 start);
struct arr_0 force_0(struct ctx* ctx, struct opt_8 a);
struct arr_0 fail_1(struct ctx* ctx, struct arr_0 reason);
struct arr_0 throw_1(struct ctx* ctx, struct exception e);
struct arr_0 todo_4(void);
struct opt_8 try_remove_start(struct ctx* ctx, struct arr_0 a, struct arr_0 start);
struct arr_0 first_1(struct ctx* ctx, struct arr_1 a);
uint8_t empty__q_5(struct arr_1 a);
struct arr_1 tail_2(struct ctx* ctx, struct arr_1 a);
uint8_t parse_named_args_recur__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it);
struct void_ add_0(struct ctx* ctx, struct mut_dict_0 m, struct arr_0 key, struct arr_1 value);
uint8_t has__q_1(struct ctx* ctx, struct mut_dict_0 d, struct arr_0 key);
uint8_t has__q_2(struct ctx* ctx, struct dict_0* d, struct arr_0 key);
uint8_t has__q_3(struct opt_7 a);
uint8_t empty__q_6(struct opt_7 a);
struct opt_7 get_2(struct ctx* ctx, struct dict_0* d, struct arr_0 key);
struct opt_7 get_recursive_0(struct ctx* ctx, struct arr_1 keys, struct arr_6 values, uint64_t idx, struct arr_0 key);
struct arr_1 at_4(struct ctx* ctx, struct arr_6 a, uint64_t index);
struct arr_1 noctx_at_6(struct arr_6 a, uint64_t index);
struct dict_0* temp_as_dict_0(struct ctx* ctx, struct mut_dict_0 m);
struct arr_1 temp_as_arr_2(struct mut_list_1* a);
struct arr_1 temp_as_arr_3(struct mut_arr_1 a);
struct mut_arr_1 temp_as_mut_arr_1(struct mut_list_1* a);
struct arr_0* data_3(struct mut_list_1* a);
struct arr_6 temp_as_arr_4(struct mut_list_2* a);
struct arr_6 temp_as_arr_5(struct mut_arr_2 a);
struct mut_arr_2 temp_as_mut_arr_2(struct mut_list_2* a);
struct arr_1* data_4(struct mut_list_2* a);
struct arr_1* data_5(struct mut_arr_2 a);
struct void_ push_0(struct ctx* ctx, struct mut_list_1* a, struct arr_0 value);
uint64_t capacity_1(struct mut_list_1* a);
struct void_ increase_capacity_to_0(struct ctx* ctx, struct mut_list_1* a, uint64_t new_capacity);
struct void_ copy_data_from_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len);
struct void_ copy_data_from_small_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len);
struct arr_0* incr_4(struct arr_0* p);
struct void_ set_zero_elements_0(struct mut_arr_1 a);
struct void_ set_zero_range_1(struct arr_0* begin, uint64_t size);
struct mut_arr_1 slice_starting_at_3(struct ctx* ctx, struct mut_arr_1 a, uint64_t begin);
struct mut_arr_1 slice_3(struct ctx* ctx, struct mut_arr_1 a, uint64_t begin, uint64_t size);
uint64_t _op_times_0(struct ctx* ctx, uint64_t a, uint64_t b);
struct void_ ensure_capacity_0(struct ctx* ctx, struct mut_list_1* a, uint64_t capacity);
uint64_t round_up_to_power_of_two(struct ctx* ctx, uint64_t n);
uint64_t round_up_to_power_of_two_recur(struct ctx* ctx, uint64_t acc, uint64_t n);
struct void_ push_1(struct ctx* ctx, struct mut_list_2* a, struct arr_1 value);
uint64_t capacity_2(struct mut_list_2* a);
uint64_t size_3(struct mut_arr_2 a);
struct void_ increase_capacity_to_1(struct ctx* ctx, struct mut_list_2* a, uint64_t new_capacity);
struct mut_arr_2 mut_arr_2(uint64_t size, struct arr_1* data);
struct arr_1* uninitialized_data_2(struct ctx* ctx, uint64_t size);
struct void_ copy_data_from_2(struct ctx* ctx, struct arr_1* to, struct arr_1* from, uint64_t len);
struct void_ copy_data_from_small_2(struct ctx* ctx, struct arr_1* to, struct arr_1* from, uint64_t len);
struct arr_1* incr_5(struct arr_1* p);
struct void_ set_zero_elements_1(struct mut_arr_2 a);
struct void_ set_zero_range_2(struct arr_1* begin, uint64_t size);
struct mut_arr_2 slice_starting_at_4(struct ctx* ctx, struct mut_arr_2 a, uint64_t begin);
struct mut_arr_2 slice_4(struct ctx* ctx, struct mut_arr_2 a, uint64_t begin, uint64_t size);
struct void_ ensure_capacity_1(struct ctx* ctx, struct mut_list_2* a, uint64_t capacity);
struct dict_0* move_to_dict_0(struct ctx* ctx, struct mut_dict_0 m);
struct arr_1 move_to_arr_0(struct mut_list_1* a);
struct arr_6 move_to_arr_1(struct mut_list_2* a);
struct arr_1 slice_after_0(struct ctx* ctx, struct arr_1 a, uint64_t before_begin);
struct mut_list_3* fill_mut_list(struct ctx* ctx, uint64_t size, struct opt_7 value);
struct mut_arr_3 fill_mut_arr(struct ctx* ctx, uint64_t size, struct opt_7 value);
struct mut_arr_3 make_mut_arr_1(struct ctx* ctx, uint64_t size, struct fun_act1_7 f);
struct mut_arr_3 new_uninitialized_mut_arr_1(struct ctx* ctx, uint64_t size);
struct mut_arr_3 mut_arr_3(uint64_t size, struct opt_7* data);
struct opt_7* uninitialized_data_3(struct ctx* ctx, uint64_t size);
struct void_ make_mut_arr_worker_1(struct ctx* ctx, struct mut_arr_3 a, uint64_t i, struct fun_act1_7 f);
uint64_t size_4(struct mut_arr_3 a);
struct void_ set_at_1(struct ctx* ctx, struct mut_arr_3 a, uint64_t index, struct opt_7 value);
struct void_ noctx_set_at_2(struct mut_arr_3 a, uint64_t index, struct opt_7 value);
struct opt_7* data_6(struct mut_arr_3 a);
struct opt_7 call_9(struct ctx* ctx, struct fun_act1_7 a, uint64_t p0);
struct opt_7 call_w_ctx_417(struct fun_act1_7 a, struct ctx* ctx, uint64_t p0);
struct opt_7 fill_mut_arr__lambda0(struct ctx* ctx, struct fill_mut_arr__lambda0* _closure, uint64_t ignore);
struct void_ each_0(struct ctx* ctx, struct dict_0* d, struct fun_act2_0 f);
uint8_t empty__q_7(struct ctx* ctx, struct dict_0* d);
struct void_ call_10(struct ctx* ctx, struct fun_act2_0 a, struct arr_0 p0, struct arr_1 p1);
struct void_ call_w_ctx_422(struct fun_act2_0 a, struct ctx* ctx, struct arr_0 p0, struct arr_1 p1);
struct arr_1 first_2(struct ctx* ctx, struct arr_6 a);
uint8_t empty__q_8(struct arr_6 a);
struct arr_6 tail_3(struct ctx* ctx, struct arr_6 a);
struct arr_6 slice_starting_at_5(struct ctx* ctx, struct arr_6 a, uint64_t begin);
struct arr_6 slice_5(struct ctx* ctx, struct arr_6 a, uint64_t begin, uint64_t size);
struct opt_5 index_of(struct ctx* ctx, struct arr_1 a, struct arr_0 value);
uint8_t index_of__lambda0(struct ctx* ctx, struct index_of__lambda0* _closure, struct arr_0 it);
struct void_ set_0(struct cell_3* c, uint8_t v);
struct opt_7 at_5(struct ctx* ctx, struct mut_list_3* a, uint64_t index);
struct opt_7 noctx_at_7(struct mut_list_3* a, uint64_t index);
struct opt_7* data_7(struct mut_list_3* a);
struct void_ set_at_2(struct ctx* ctx, struct mut_list_3* a, uint64_t index, struct opt_7 value);
struct void_ noctx_set_at_3(struct mut_list_3* a, uint64_t index, struct opt_7 value);
struct void_ parse_cmd_line_args__lambda0(struct ctx* ctx, struct parse_cmd_line_args__lambda0* _closure, struct arr_0 key, struct arr_1 value);
uint8_t get_3(struct cell_3* c);
struct test_options call_11(struct ctx* ctx, struct fun1_2 a, struct arr_5 p0);
struct test_options call_w_ctx_439(struct fun1_2 a, struct ctx* ctx, struct arr_5 p0);
struct arr_5 move_to_arr_2(struct mut_list_3* a);
struct mut_arr_3 empty_mut_arr_2(void);
struct arr_5 empty_arr_3(void);
struct opt_7 at_6(struct ctx* ctx, struct arr_5 a, uint64_t index);
struct opt_7 noctx_at_8(struct arr_5 a, uint64_t index);
uint64_t force_1(struct ctx* ctx, struct opt_5 a);
uint64_t fail_2(struct ctx* ctx, struct arr_0 reason);
uint64_t throw_2(struct ctx* ctx, struct exception e);
struct opt_5 parse_nat(struct ctx* ctx, struct arr_0 a);
struct opt_5 parse_nat_recur(struct ctx* ctx, struct arr_0 a, uint64_t accum);
struct opt_5 char_to_nat(struct ctx* ctx, char c);
struct test_options main_0__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_5 values);
struct fut_0* resolved_1(struct ctx* ctx, int32_t value);
struct void_ print_help(struct ctx* ctx);
int32_t do_test(struct ctx* ctx, struct test_options options);
struct arr_0 parent_path(struct ctx* ctx, struct arr_0 a);
struct opt_5 r_index_of(struct ctx* ctx, struct arr_0 a, char value);
struct opt_5 find_rindex(struct ctx* ctx, struct arr_0 a, struct fun_act1_8 pred);
struct opt_5 find_rindex_recur(struct ctx* ctx, struct arr_0 a, uint64_t index, struct fun_act1_8 pred);
uint8_t call_12(struct ctx* ctx, struct fun_act1_8 a, char p0);
uint8_t call_w_ctx_460(struct fun_act1_8 a, struct ctx* ctx, char p0);
uint8_t r_index_of__lambda0(struct ctx* ctx, struct r_index_of__lambda0* _closure, char it);
struct arr_0 slice_up_to_1(struct ctx* ctx, struct arr_0 a, uint64_t size);
struct arr_0 current_executable_path(struct ctx* ctx);
struct arr_0 read_link(struct ctx* ctx, struct arr_0 path);
struct mut_arr_4 new_uninitialized_mut_arr_2(struct ctx* ctx, uint64_t size);
struct mut_arr_4 mut_arr_4(uint64_t size, char* data);
extern int64_t readlink(char* path, char* buf, uint64_t len);
char* to_c_str(struct ctx* ctx, struct arr_0 a);
char* data_8(struct mut_arr_4 a);
uint64_t size_5(struct mut_arr_4 a);
struct void_ check_errno_if_neg_one(struct ctx* ctx, int64_t e);
struct void_ check_posix_error(struct ctx* ctx, int32_t e);
extern int32_t errno;
struct void_ hard_unreachable_1(void);
struct arr_0 cast_immutable_1(struct mut_arr_4 a);
uint64_t to_nat_0(struct ctx* ctx, int64_t i);
uint8_t negative__q(struct ctx* ctx, int64_t i);
uint8_t _op_less_1(int64_t a, int64_t b);
struct arr_0 child_path(struct ctx* ctx, struct arr_0 a, struct arr_0 child_name);
struct dict_1* get_environ(struct ctx* ctx);
struct mut_dict_1 new_mut_dict_1(struct ctx* ctx);
struct void_ get_environ_recur(struct ctx* ctx, char** env, struct mut_dict_1 res);
uint8_t null__q_2(char* a);
struct void_ add_1(struct ctx* ctx, struct mut_dict_1 m, struct key_value_pair* pair);
struct void_ add_2(struct ctx* ctx, struct mut_dict_1 m, struct arr_0 key, struct arr_0 value);
uint8_t has__q_4(struct ctx* ctx, struct mut_dict_1 d, struct arr_0 key);
uint8_t has__q_5(struct ctx* ctx, struct dict_1* d, struct arr_0 key);
uint8_t has__q_6(struct opt_8 a);
uint8_t empty__q_9(struct opt_8 a);
struct opt_8 get_4(struct ctx* ctx, struct dict_1* d, struct arr_0 key);
struct opt_8 get_recursive_1(struct ctx* ctx, struct arr_1 keys, struct arr_1 values, uint64_t idx, struct arr_0 key);
struct dict_1* temp_as_dict_1(struct ctx* ctx, struct mut_dict_1 m);
struct key_value_pair* parse_environ_entry(struct ctx* ctx, char* entry);
char** incr_6(char** p);
extern char** environ;
struct dict_1* move_to_dict_1(struct ctx* ctx, struct mut_dict_1 m);
struct result_2 first_failures(struct ctx* ctx, struct result_2 a, struct fun0 b);
struct result_2 then_1(struct ctx* ctx, struct result_2 a, struct fun_act1_9 f);
struct result_2 call_13(struct ctx* ctx, struct fun_act1_9 a, struct arr_0 p0);
struct result_2 call_w_ctx_500(struct fun_act1_9 a, struct ctx* ctx, struct arr_0 p0);
struct result_2 call_14(struct ctx* ctx, struct fun0 a);
struct result_2 call_w_ctx_502(struct fun0 a, struct ctx* ctx);
struct result_2 first_failures__lambda0__lambda0(struct ctx* ctx, struct first_failures__lambda0__lambda0* _closure, struct arr_0 b_descr);
struct result_2 first_failures__lambda0(struct ctx* ctx, struct first_failures__lambda0* _closure, struct arr_0 a_descr);
struct result_2 run_noze_tests(struct ctx* ctx, struct arr_0 path, struct arr_0 path_to_noze, struct dict_1* env, struct test_options options);
struct arr_1 list_tests(struct ctx* ctx, struct arr_0 path);
uint8_t list_tests__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 s);
struct void_ each_child_recursive(struct ctx* ctx, struct arr_0 path, struct fun_act1_6 filter, struct fun_act1_10 f);
uint8_t is_dir__q_0(struct ctx* ctx, struct arr_0 path);
uint8_t is_dir__q_1(struct ctx* ctx, char* path);
struct opt_9 get_stat(struct ctx* ctx, char* path);
struct stat_t* empty_stat(struct ctx* ctx);
extern int32_t stat(char* path, struct stat_t* buf);
int32_t enoent(void);
struct opt_9 todo_5(void);
uint8_t todo_6(void);
uint8_t _op_equal_equal_5(uint32_t a, uint32_t b);
struct comparison compare_518(uint32_t a, uint32_t b);
uint32_t s_ifmt(struct ctx* ctx);
uint32_t s_ifdir(struct ctx* ctx);
struct void_ each_1(struct ctx* ctx, struct arr_1 a, struct fun_act1_10 f);
struct void_ call_15(struct ctx* ctx, struct fun_act1_10 a, struct arr_0 p0);
struct void_ call_w_ctx_523(struct fun_act1_10 a, struct ctx* ctx, struct arr_0 p0);
struct arr_1 read_dir_0(struct ctx* ctx, struct arr_0 path);
struct arr_1 read_dir_1(struct ctx* ctx, char* path);
extern struct dir* opendir(char* name);
uint8_t null__q_3(uint8_t** a);
struct void_ read_dir_recur(struct ctx* ctx, struct dir* dirp, struct mut_list_1* res);
struct bytes256 zero_4(void);
extern int32_t readdir_r(struct dir* dirp, struct dirent* entry, struct cell_4* result);
struct dirent* get_5(struct cell_4* c);
uint8_t ref_eq__q(struct dirent* a, struct dirent* b);
struct arr_0 get_dirent_name(struct dirent* d);
uint8_t _op_bang_equal_3(struct arr_0 a, struct arr_0 b);
struct arr_1 sort_0(struct ctx* ctx, struct arr_1 a);
struct mut_arr_1 copy_to_mut_arr(struct ctx* ctx, struct arr_1 a);
struct arr_0 copy_to_mut_arr__lambda0(struct ctx* ctx, struct copy_to_mut_arr__lambda0* _closure, uint64_t i);
struct void_ sort_1(struct ctx* ctx, struct mut_arr_1 a);
struct void_ swap_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t x, uint64_t y);
struct arr_0 at_7(struct ctx* ctx, struct mut_arr_1 a, uint64_t index);
uint64_t partition_recur(struct ctx* ctx, struct mut_arr_1 a, struct arr_0 pivot, uint64_t l, uint64_t r);
uint8_t _op_less_2(struct arr_0 a, struct arr_0 b);
struct mut_arr_1 slice_after_1(struct ctx* ctx, struct mut_arr_1 a, uint64_t before_begin);
struct void_ each_child_recursive__lambda0(struct ctx* ctx, struct each_child_recursive__lambda0* _closure, struct arr_0 child_name);
struct opt_8 get_extension(struct ctx* ctx, struct arr_0 name);
struct opt_5 last_index_of(struct ctx* ctx, struct arr_0 s, char c);
char last(struct ctx* ctx, struct arr_0 a);
struct arr_0 rtail(struct ctx* ctx, struct arr_0 a);
struct arr_0 slice_after_2(struct ctx* ctx, struct arr_0 a, uint64_t before_begin);
struct arr_0 base_name(struct ctx* ctx, struct arr_0 path);
struct void_ list_tests__lambda1(struct ctx* ctx, struct list_tests__lambda1* _closure, struct arr_0 child);
struct arr_7 flat_map_with_max_size(struct ctx* ctx, struct arr_1 a, uint64_t max_size, struct fun_act1_11 mapper);
struct mut_list_4* new_mut_list_2(struct ctx* ctx);
struct mut_arr_5 empty_mut_arr_3(void);
struct arr_7 empty_arr_4(void);
struct void_ push_all(struct ctx* ctx, struct mut_list_4* a, struct arr_7 values);
struct void_ each_2(struct ctx* ctx, struct arr_7 a, struct fun_act1_12 f);
uint8_t empty__q_10(struct arr_7 a);
struct void_ call_16(struct ctx* ctx, struct fun_act1_12 a, struct failure* p0);
struct void_ call_w_ctx_560(struct fun_act1_12 a, struct ctx* ctx, struct failure* p0);
struct failure* first_3(struct ctx* ctx, struct arr_7 a);
struct failure* at_8(struct ctx* ctx, struct arr_7 a, uint64_t index);
struct failure* noctx_at_9(struct arr_7 a, uint64_t index);
struct arr_7 tail_4(struct ctx* ctx, struct arr_7 a);
struct arr_7 slice_starting_at_6(struct ctx* ctx, struct arr_7 a, uint64_t begin);
struct arr_7 slice_6(struct ctx* ctx, struct arr_7 a, uint64_t begin, uint64_t size);
struct void_ push_2(struct ctx* ctx, struct mut_list_4* a, struct failure* value);
uint64_t capacity_3(struct mut_list_4* a);
uint64_t size_6(struct mut_arr_5 a);
struct void_ increase_capacity_to_2(struct ctx* ctx, struct mut_list_4* a, uint64_t new_capacity);
struct failure** data_9(struct mut_list_4* a);
struct failure** data_10(struct mut_arr_5 a);
struct mut_arr_5 mut_arr_5(uint64_t size, struct failure** data);
struct failure** uninitialized_data_4(struct ctx* ctx, uint64_t size);
struct void_ copy_data_from_3(struct ctx* ctx, struct failure** to, struct failure** from, uint64_t len);
struct void_ copy_data_from_small_3(struct ctx* ctx, struct failure** to, struct failure** from, uint64_t len);
struct failure** incr_7(struct failure** p);
struct void_ set_zero_elements_2(struct mut_arr_5 a);
struct void_ set_zero_range_3(struct failure** begin, uint64_t size);
struct mut_arr_5 slice_starting_at_7(struct ctx* ctx, struct mut_arr_5 a, uint64_t begin);
struct mut_arr_5 slice_7(struct ctx* ctx, struct mut_arr_5 a, uint64_t begin, uint64_t size);
struct void_ ensure_capacity_2(struct ctx* ctx, struct mut_list_4* a, uint64_t capacity);
struct void_ push_all__lambda0(struct ctx* ctx, struct push_all__lambda0* _closure, struct failure* it);
struct arr_7 call_17(struct ctx* ctx, struct fun_act1_11 a, struct arr_0 p0);
struct arr_7 call_w_ctx_585(struct fun_act1_11 a, struct ctx* ctx, struct arr_0 p0);
struct void_ reduce_size_if_more_than(struct ctx* ctx, struct mut_list_4* a, uint64_t new_size);
struct void_ drop_2(struct opt_10 _p0);
struct opt_10 pop(struct ctx* ctx, struct mut_list_4* a);
uint8_t empty__q_11(struct mut_list_4* a);
struct failure* at_9(struct ctx* ctx, struct mut_list_4* a, uint64_t index);
struct failure* noctx_at_10(struct mut_list_4* a, uint64_t index);
struct void_ set_at_3(struct ctx* ctx, struct mut_list_4* a, uint64_t index, struct failure* value);
struct void_ noctx_set_at_4(struct mut_list_4* a, uint64_t index, struct failure* value);
struct void_ flat_map_with_max_size__lambda0(struct ctx* ctx, struct flat_map_with_max_size__lambda0* _closure, struct arr_0 x);
struct arr_7 move_to_arr_3(struct mut_list_4* a);
struct arr_7 run_single_noze_test(struct ctx* ctx, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, struct test_options options);
struct opt_11 first_some(struct ctx* ctx, struct arr_1 a, struct fun_act1_13 cb);
struct opt_11 call_18(struct ctx* ctx, struct fun_act1_13 a, struct arr_0 p0);
struct opt_11 call_w_ctx_599(struct fun_act1_13 a, struct ctx* ctx, struct arr_0 p0);
struct print_test_result* run_print_test(struct ctx* ctx, struct arr_0 print_kind, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, uint8_t overwrite_output__q);
struct process_result* spawn_and_wait_result_0(struct ctx* ctx, struct arr_0 exe, struct arr_1 args, struct dict_1* environ);
struct arr_0 fold(struct ctx* ctx, struct arr_0 val, struct arr_1 a, struct fun_act2_1 combine);
struct arr_0 call_19(struct ctx* ctx, struct fun_act2_1 a, struct arr_0 p0, struct arr_0 p1);
struct arr_0 call_w_ctx_604(struct fun_act2_1 a, struct ctx* ctx, struct arr_0 p0, struct arr_0 p1);
struct arr_0 spawn_and_wait_result_0__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 a, struct arr_0 b);
uint8_t is_file__q_0(struct ctx* ctx, struct arr_0 path);
uint8_t is_file__q_1(struct ctx* ctx, char* path);
uint32_t s_ifreg(struct ctx* ctx);
struct process_result* spawn_and_wait_result_1(struct ctx* ctx, char* exe, char** args, char** environ);
struct pipes* make_pipes(struct ctx* ctx);
extern int32_t pipe(struct pipes* pipes);
extern int32_t posix_spawn_file_actions_init(struct posix_spawn_file_actions_t* file_actions);
extern int32_t posix_spawn_file_actions_addclose(struct posix_spawn_file_actions_t* file_actions, int32_t fd);
extern int32_t posix_spawn_file_actions_adddup2(struct posix_spawn_file_actions_t* file_actions, int32_t fd, int32_t new_fd);
extern int32_t posix_spawn(struct cell_5* pid, char* executable_path, struct posix_spawn_file_actions_t* file_actions, uint8_t* attrp, char** argv, char** environ);
int32_t get_6(struct cell_5* c);
extern int32_t close(int32_t fd);
struct mut_list_5* new_mut_list_3(struct ctx* ctx);
struct mut_arr_4 empty_mut_arr_4(void);
struct arr_0 empty_arr_5(void);
struct void_ keep_polling(struct ctx* ctx, int32_t stdout_pipe, int32_t stderr_pipe, struct mut_list_5* stdout_builder, struct mut_list_5* stderr_builder);
int16_t pollin(struct ctx* ctx);
struct pollfd* ref_of_val_at(struct ctx* ctx, struct arr_8 a, uint64_t index);
struct pollfd* ref_of_ptr(struct pollfd* p);
extern int32_t poll(struct pollfd* fds, uint64_t n_fds, int32_t timeout);
struct handle_revents_result handle_revents(struct ctx* ctx, struct pollfd* pollfd, struct mut_list_5* builder);
uint8_t has_pollin__q(struct ctx* ctx, int16_t revents);
uint8_t bits_intersect__q(int16_t a, int16_t b);
uint8_t _op_equal_equal_6(int16_t a, int16_t b);
struct comparison compare_630(int16_t a, int16_t b);
struct void_ read_to_buffer_until_eof(struct ctx* ctx, int32_t fd, struct mut_list_5* buffer);
struct void_ ensure_capacity_3(struct ctx* ctx, struct mut_list_5* a, uint64_t capacity);
uint64_t capacity_4(struct mut_list_5* a);
struct void_ increase_capacity_to_3(struct ctx* ctx, struct mut_list_5* a, uint64_t new_capacity);
char* data_11(struct mut_list_5* a);
struct void_ set_zero_elements_3(struct mut_arr_4 a);
struct void_ set_zero_range_4(char* begin, uint64_t size);
struct mut_arr_4 slice_starting_at_8(struct ctx* ctx, struct mut_arr_4 a, uint64_t begin);
struct mut_arr_4 slice_8(struct ctx* ctx, struct mut_arr_4 a, uint64_t begin, uint64_t size);
extern int64_t read(int32_t fd, uint8_t* buff, uint64_t n_bytes);
struct void_ unsafe_increase_size(struct ctx* ctx, struct mut_list_5* a, uint64_t increase_by);
struct void_ unsafe_set_size(struct ctx* ctx, struct mut_list_5* a, uint64_t new_size);
uint8_t has_pollhup__q(struct ctx* ctx, int16_t revents);
int16_t pollhup(struct ctx* ctx);
uint8_t has_pollpri__q(struct ctx* ctx, int16_t revents);
int16_t pollpri(struct ctx* ctx);
uint8_t has_pollout__q(struct ctx* ctx, int16_t revents);
int16_t pollout(struct ctx* ctx);
uint8_t has_pollerr__q(struct ctx* ctx, int16_t revents);
int16_t pollerr(struct ctx* ctx);
uint8_t has_pollnval__q(struct ctx* ctx, int16_t revents);
int16_t pollnval(struct ctx* ctx);
uint64_t to_nat_1(uint8_t b);
uint8_t any__q(struct ctx* ctx, struct handle_revents_result r);
uint64_t to_nat_2(struct ctx* ctx, int32_t i);
int32_t wait_and_get_exit_code(struct ctx* ctx, int32_t pid);
extern int32_t waitpid(int32_t pid, struct cell_5* wait_status, int32_t options);
uint8_t w_if_exited(struct ctx* ctx, int32_t status);
int32_t w_term_sig(struct ctx* ctx, int32_t status);
int32_t w_exit_status(struct ctx* ctx, int32_t status);
int32_t bit_shift_right(int32_t a, int32_t b);
uint8_t _op_less_3(int32_t a, int32_t b);
int32_t todo_7(void);
uint8_t w_if_signaled(struct ctx* ctx, int32_t status);
struct arr_0 to_str_2(struct ctx* ctx, int32_t i);
struct arr_0 to_str_3(struct ctx* ctx, int64_t i);
struct arr_0 to_str_4(struct ctx* ctx, uint64_t n);
uint64_t mod(struct ctx* ctx, uint64_t a, uint64_t b);
uint64_t abs(struct ctx* ctx, int64_t i);
int64_t neg(struct ctx* ctx, int64_t i);
int64_t _op_times_1(struct ctx* ctx, int64_t a, int64_t b);
uint8_t w_if_stopped(struct ctx* ctx, int32_t status);
uint8_t w_if_continued(struct ctx* ctx, int32_t status);
struct arr_0 move_to_arr_4(struct mut_list_5* a);
char** convert_args(struct ctx* ctx, char* exe_c_str, struct arr_1 args);
struct arr_4 prepend(struct ctx* ctx, char* a, struct arr_4 b);
struct arr_4 _op_plus_2(struct ctx* ctx, struct arr_4 a, struct arr_4 b);
char** uninitialized_data_5(struct ctx* ctx, uint64_t size);
struct void_ copy_data_from_4(struct ctx* ctx, char** to, char** from, uint64_t len);
struct void_ copy_data_from_small_4(struct ctx* ctx, char** to, char** from, uint64_t len);
struct arr_4 append(struct ctx* ctx, struct arr_4 a, char* b);
struct arr_4 map_1(struct ctx* ctx, struct arr_1 a, struct fun_act1_14 mapper);
struct arr_4 make_arr_1(struct ctx* ctx, uint64_t size, struct fun_act1_15 f);
struct arr_4 cast_immutable_2(struct mut_arr_6 a);
struct mut_arr_6 make_mut_arr_2(struct ctx* ctx, uint64_t size, struct fun_act1_15 f);
struct mut_arr_6 new_uninitialized_mut_arr_3(struct ctx* ctx, uint64_t size);
struct mut_arr_6 mut_arr_6(uint64_t size, char** data);
struct void_ make_mut_arr_worker_2(struct ctx* ctx, struct mut_arr_6 a, uint64_t i, struct fun_act1_15 f);
uint64_t size_7(struct mut_arr_6 a);
struct void_ set_at_4(struct ctx* ctx, struct mut_arr_6 a, uint64_t index, char* value);
struct void_ noctx_set_at_5(struct mut_arr_6 a, uint64_t index, char* value);
char** data_12(struct mut_arr_6 a);
char* call_20(struct ctx* ctx, struct fun_act1_15 a, uint64_t p0);
char* call_w_ctx_694(struct fun_act1_15 a, struct ctx* ctx, uint64_t p0);
char* call_21(struct ctx* ctx, struct fun_act1_14 a, struct arr_0 p0);
char* call_w_ctx_696(struct fun_act1_14 a, struct ctx* ctx, struct arr_0 p0);
char* map_1__lambda0(struct ctx* ctx, struct map_1__lambda0* _closure, uint64_t i);
char* convert_args__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it);
char** convert_environ(struct ctx* ctx, struct dict_1* environ);
struct mut_list_6* new_mut_list_4(struct ctx* ctx);
struct mut_arr_6 empty_mut_arr_5(void);
struct arr_4 empty_arr_6(void);
struct void_ each_3(struct ctx* ctx, struct dict_1* d, struct fun_act2_2 f);
uint8_t empty__q_12(struct ctx* ctx, struct dict_1* d);
struct void_ call_22(struct ctx* ctx, struct fun_act2_2 a, struct arr_0 p0, struct arr_0 p1);
struct void_ call_w_ctx_706(struct fun_act2_2 a, struct ctx* ctx, struct arr_0 p0, struct arr_0 p1);
struct void_ push_3(struct ctx* ctx, struct mut_list_6* a, char* value);
uint64_t capacity_5(struct mut_list_6* a);
struct void_ increase_capacity_to_4(struct ctx* ctx, struct mut_list_6* a, uint64_t new_capacity);
char** data_13(struct mut_list_6* a);
struct void_ set_zero_elements_4(struct mut_arr_6 a);
struct void_ set_zero_range_5(char** begin, uint64_t size);
struct mut_arr_6 slice_starting_at_9(struct ctx* ctx, struct mut_arr_6 a, uint64_t begin);
struct mut_arr_6 slice_9(struct ctx* ctx, struct mut_arr_6 a, uint64_t begin, uint64_t size);
struct void_ ensure_capacity_4(struct ctx* ctx, struct mut_list_6* a, uint64_t capacity);
struct void_ convert_environ__lambda0(struct ctx* ctx, struct convert_environ__lambda0* _closure, struct arr_0 key, struct arr_0 value);
struct arr_4 move_to_arr_5(struct mut_list_6* a);
struct process_result* fail_3(struct ctx* ctx, struct arr_0 reason);
struct process_result* throw_3(struct ctx* ctx, struct exception e);
struct process_result* todo_8(void);
struct arr_7 handle_output(struct ctx* ctx, struct arr_0 original_path, struct arr_0 output_path, struct arr_0 actual, uint8_t overwrite_output__q);
struct opt_8 try_read_file_0(struct ctx* ctx, struct arr_0 path);
struct opt_8 try_read_file_1(struct ctx* ctx, char* path);
extern int32_t open(char* path, int32_t oflag, uint32_t permission);
int32_t o_rdonly(void);
struct opt_8 todo_9(void);
extern int64_t lseek(int32_t f, int64_t offset, int32_t whence);
int32_t seek_end(struct ctx* ctx);
int32_t seek_set(struct ctx* ctx);
struct void_ write_file_0(struct ctx* ctx, struct arr_0 path, struct arr_0 content);
struct void_ write_file_1(struct ctx* ctx, char* path, struct arr_0 content);
uint32_t bit_shift_left(uint32_t a, uint32_t b);
uint8_t _op_less_4(uint32_t a, uint32_t b);
int32_t o_creat(void);
int32_t o_wronly(void);
int32_t o_trunc(void);
struct arr_0 to_str_5(struct ctx* ctx, uint32_t n);
int64_t to_int(struct ctx* ctx, uint64_t n);
int64_t max_int(void);
struct arr_0 remove_colors(struct ctx* ctx, struct arr_0 s);
struct void_ remove_colors_recur(struct ctx* ctx, struct arr_0 s, struct mut_list_5* out);
struct void_ remove_colors_recur_2(struct ctx* ctx, struct arr_0 s, struct mut_list_5* out);
struct void_ push_4(struct ctx* ctx, struct mut_list_5* a, char value);
struct opt_11 run_single_noze_test__lambda0(struct ctx* ctx, struct run_single_noze_test__lambda0* _closure, struct arr_0 print_kind);
struct arr_7 run_single_runnable_test(struct ctx* ctx, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, uint8_t interpret__q, uint8_t overwrite_output__q);
struct arr_7 run_noze_tests__lambda0(struct ctx* ctx, struct run_noze_tests__lambda0* _closure, struct arr_0 test);
uint8_t has__q_7(struct arr_7 a);
struct result_2 do_test__lambda0__lambda0(struct ctx* ctx, struct do_test__lambda0__lambda0* _closure);
struct result_2 do_test__lambda0(struct ctx* ctx, struct do_test__lambda0* _closure);
struct result_2 lint(struct ctx* ctx, struct arr_0 path, struct test_options options);
struct arr_1 list_lintable_files(struct ctx* ctx, struct arr_0 path);
uint8_t excluded_from_lint__q(struct ctx* ctx, struct arr_0 name);
uint8_t contains__q_2(struct arr_1 a, struct arr_0 value);
uint8_t contains_recur__q_1(struct arr_1 a, struct arr_0 value, uint64_t i);
uint8_t some__q(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 pred);
uint8_t ends_with__q(struct ctx* ctx, struct arr_0 a, struct arr_0 end);
uint8_t excluded_from_lint__q__lambda0(struct ctx* ctx, struct excluded_from_lint__q__lambda0* _closure, struct arr_0 it);
uint8_t list_lintable_files__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it);
uint8_t ignore_extension_of_name__q(struct ctx* ctx, struct arr_0 name);
uint8_t ignore_extension__q(struct ctx* ctx, struct arr_0 ext);
struct arr_1 ignored_extensions(struct ctx* ctx);
struct void_ list_lintable_files__lambda1(struct ctx* ctx, struct list_lintable_files__lambda1* _closure, struct arr_0 child);
struct arr_7 lint_file(struct ctx* ctx, struct arr_0 path);
struct arr_0 read_file(struct ctx* ctx, struct arr_0 path);
struct void_ each_with_index_0(struct ctx* ctx, struct arr_1 a, struct fun_act2_3 f);
struct void_ each_with_index_recur_0(struct ctx* ctx, struct arr_1 a, struct fun_act2_3 f, uint64_t n);
struct void_ call_23(struct ctx* ctx, struct fun_act2_3 a, struct arr_0 p0, uint64_t p1);
struct void_ call_w_ctx_768(struct fun_act2_3 a, struct ctx* ctx, struct arr_0 p0, uint64_t p1);
struct arr_1 lines(struct ctx* ctx, struct arr_0 s);
struct void_ each_with_index_1(struct ctx* ctx, struct arr_0 a, struct fun_act2_4 f);
struct void_ each_with_index_recur_1(struct ctx* ctx, struct arr_0 a, struct fun_act2_4 f, uint64_t n);
struct void_ call_24(struct ctx* ctx, struct fun_act2_4 a, char p0, uint64_t p1);
struct void_ call_w_ctx_773(struct fun_act2_4 a, struct ctx* ctx, char p0, uint64_t p1);
struct arr_0 slice_from_to(struct ctx* ctx, struct arr_0 a, uint64_t begin, uint64_t end);
uint64_t swap_1(struct cell_0* c, uint64_t v);
uint64_t get_7(struct cell_0* c);
struct void_ set_1(struct cell_0* c, uint64_t v);
struct void_ lines__lambda0(struct ctx* ctx, struct lines__lambda0* _closure, char c, uint64_t index);
uint8_t contains_subsequence__q(struct ctx* ctx, struct arr_0 a, struct arr_0 subseq);
uint8_t has__q_8(struct arr_0 a);
struct arr_0 lstrip(struct ctx* ctx, struct arr_0 a);
uint64_t line_len(struct ctx* ctx, struct arr_0 line);
uint64_t n_tabs(struct ctx* ctx, struct arr_0 line);
uint64_t tab_size(struct ctx* ctx);
uint64_t max_line_length(struct ctx* ctx);
struct void_ lint_file__lambda0(struct ctx* ctx, struct lint_file__lambda0* _closure, struct arr_0 line, uint64_t line_num);
struct arr_7 lint__lambda0(struct ctx* ctx, struct lint__lambda0* _closure, struct arr_0 file);
struct result_2 do_test__lambda1(struct ctx* ctx, struct do_test__lambda1* _closure);
int32_t print_failures(struct ctx* ctx, struct result_2 failures, struct test_options options);
struct void_ print_failure(struct ctx* ctx, struct failure* failure);
struct void_ print_bold(struct ctx* ctx);
struct void_ print_reset(struct ctx* ctx);
struct void_ print_failures__lambda0(struct ctx* ctx, struct void_ _closure, struct failure* it);
int32_t to_int32(struct ctx* ctx, uint64_t n);
int32_t max_int32(void);
int32_t main(int32_t argc, char** argv);
/* mark bool(ctx mark-ctx, ptr-any ptr<nat8>, size-bytes nat) */
uint8_t mark(struct mark_ctx* ctx, uint8_t* ptr_any, uint64_t size_bytes) {
	uint64_t size_words0;
	uint64_t _0 = size_bytes;
	size_words0 = words_of_bytes(_0);
	
	uint64_t* ptr1;
	uint8_t* _1 = ptr_any;
	ptr1 = (uint64_t*) _1;
	
	uint64_t* _2 = ptr1;
	uint64_t _3 = (uint64_t) _2;
	uint64_t _4 = 7u;
	uint64_t _5 = _3 & _4;
	uint64_t _6 = 0u;
	uint8_t _7 = _op_equal_equal_0(_5, _6);
	hard_assert(_7);
	uint64_t index2;
	uint64_t* _8 = ptr1;
	struct mark_ctx* _9 = ctx;
	uint64_t* _10 = _9->memory_start;
	index2 = _op_minus_0(_8, _10);
	
	uint8_t gc_memory__q3;
	uint64_t _11 = index2;
	struct mark_ctx* _12 = ctx;
	uint64_t _13 = _12->memory_size_words;
	gc_memory__q3 = _op_less_0(_11, _13);
	
	uint8_t _14 = gc_memory__q3;
	if (_14) {
		uint64_t _15 = index2;
		uint64_t _16 = size_words0;
		uint64_t _17 = _15 + _16;
		struct mark_ctx* _18 = ctx;
		uint64_t _19 = _18->memory_size_words;
		uint8_t _20 = _op_less_equal(_17, _19);
		hard_assert(_20);
		uint8_t* mark_start4;
		struct mark_ctx* _21 = ctx;
		uint8_t* _22 = _21->marks;
		uint64_t _23 = index2;
		mark_start4 = _22 + _23;
		
		uint8_t* mark_end5;
		uint8_t* _24 = mark_start4;
		uint64_t _25 = size_words0;
		mark_end5 = _24 + _25;
		
		uint8_t _26 = 0;
		uint8_t* _27 = mark_start4;
		uint8_t* _28 = mark_end5;
		return mark_range_recur(_26, _27, _28);
	} else {
		uint64_t _29 = index2;
		uint64_t _30 = size_words0;
		uint64_t _31 = _29 + _30;
		struct mark_ctx* _32 = ctx;
		uint64_t _33 = _32->memory_size_words;
		uint8_t _34 = _op_greater(_31, _33);
		hard_assert(_34);
		return 0;
	}
}
/* words-of-bytes nat(size-bytes nat) */
uint64_t words_of_bytes(uint64_t size_bytes) {
	uint64_t _0 = size_bytes;
	uint64_t _1 = round_up_to_multiple_of_8(_0);
	uint64_t _2 = 8u;
	return _1 / _2;
}
/* round-up-to-multiple-of-8 nat(n nat) */
uint64_t round_up_to_multiple_of_8(uint64_t n) {
	uint64_t _0 = n;
	uint64_t _1 = 7u;
	uint64_t _2 = _0 + _1;
	uint64_t _3 = 7u;
	uint64_t _4 = ~_3;
	return _2 & _4;
}
/* hard-assert void(condition bool) */
struct void_ hard_assert(uint8_t condition) {
	uint8_t _0 = condition;
	uint8_t _1 = !_0;
	if (_1) {
		return (assert(0),(struct void_) {});
	} else {
		return (struct void_) {};
	}
}
/* ==<nat> bool(a nat, b nat) */
uint8_t _op_equal_equal_0(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	struct comparison _2 = compare_5(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<nat-64> (generated) (generated) */
struct comparison compare_5(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		uint64_t _4 = b;
		uint64_t _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* -<nat> nat(a ptr<nat>, b ptr<nat>) */
uint64_t _op_minus_0(uint64_t* a, uint64_t* b) {
	uint64_t* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	uint64_t* _2 = b;
	uint64_t _3 = (uint64_t) _2;
	uint64_t _4 = _1 - _3;
	uint64_t _5 = sizeof(uint64_t);
	return _4 / _5;
}
/* <<nat> bool(a nat, b nat) */
uint8_t _op_less_0(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	struct comparison _2 = compare_5(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* <=<nat> bool(a nat, b nat) */
uint8_t _op_less_equal(uint64_t a, uint64_t b) {
	uint64_t _0 = b;
	uint64_t _1 = a;
	uint8_t _2 = _op_less_0(_0, _1);
	return !_2;
}
/* mark-range-recur bool(marked-anything? bool, cur ptr<bool>, end ptr<bool>) */
uint8_t mark_range_recur(uint8_t marked_anything__q, uint8_t* cur, uint8_t* end) {
	top:;
	uint8_t* _0 = cur;
	uint8_t* _1 = end;
	uint8_t _2 = _0 == _1;
	if (_2) {
		return marked_anything__q;
	} else {
		uint8_t new_marked_anything__q0;
		uint8_t _3 = marked_anything__q;
		if (_3) {
			new_marked_anything__q0 = 1;
		} else {
			uint8_t* _4 = cur;
			uint8_t _5 = *_4;
			new_marked_anything__q0 = !_5;
		}
		
		uint8_t* _6 = cur;
		uint8_t _7 = 1;
		*_6 = _7;
		uint8_t _8 = new_marked_anything__q0;
		uint8_t* _9 = cur;
		uint8_t* _10 = incr_0(_9);
		uint8_t* _11 = end;
		marked_anything__q = _8;
		cur = _10;
		end = _11;
		goto top;
	}
}
/* incr<bool> ptr<bool>(p ptr<bool>) */
uint8_t* incr_0(uint8_t* p) {
	uint8_t* _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* ><nat> bool(a nat, b nat) */
uint8_t _op_greater(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	uint8_t _2 = _op_less_equal(_0, _1);
	return !_2;
}
/* rt-main int32(argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
int32_t rt_main(int32_t argc, char** argv, fun_ptr2 main_ptr) {
	uint64_t n_threads0;
	n_threads0 = get_nprocs();
	
	struct global_ctx gctx_by_val1;
	struct lock _0 = new_lock();
	struct arr_3 _1 = empty_arr_0();
	uint64_t _2 = n_threads0;
	struct condition _3 = new_condition();
	uint8_t _4 = 0;
	uint8_t _5 = 0;
	gctx_by_val1 = (struct global_ctx) {_0, _1, _2, _3, _4, _5};
	
	struct global_ctx* gctx2;
	gctx2 = &gctx_by_val1;
	
	struct island island_by_val3;
	struct global_ctx* _6 = gctx2;
	uint64_t _7 = 0u;
	uint64_t _8 = n_threads0;
	island_by_val3 = new_island(_6, _7, _8);
	
	struct island* island4;
	island4 = &island_by_val3;
	
	struct global_ctx* _9 = gctx2;
	uint64_t _10 = 1u;
	struct island** _11 = &island4;
	struct arr_3 _12 = (struct arr_3) {_10, _11};
	_9->islands = _12;
	struct fut_0* main_fut5;
	struct global_ctx* _13 = gctx2;
	struct island* _14 = island4;
	int32_t _15 = argc;
	char** _16 = argv;
	fun_ptr2 _17 = main_ptr;
	main_fut5 = do_main(_13, _14, _15, _16, _17);
	
	uint64_t _18 = n_threads0;
	struct global_ctx* _19 = gctx2;
	run_threads(_18, _19);
	struct fut_0* _20 = main_fut5;
	struct result_0 _21 = must_be_resolved(_20);
	switch (_21.kind) {
		case 0: {
			struct ok_0 o6 = _21.as0;
			
			struct global_ctx* _22 = gctx2;
			uint8_t _23 = _22->any_unhandled_exceptions__q;
			if (_23) {
				return 1;
			} else {
				struct ok_0 _24 = o6;
				return _24.value;
			}
		}
		case 1: {
			struct err_0 e7 = _21.as1;
			
			struct arr_0 _25 = (struct arr_0) {13, constantarr_0_14};
			print_err_no_newline(_25);
			struct err_0 _26 = e7;
			struct exception _27 = _26.value;
			struct arr_0 _28 = _27.message;
			print_err(_28);
			return 1;
		}
		default:
			return (assert(0),0);
	}
}
/* new-lock lock() */
struct lock new_lock(void) {
	struct _atomic_bool _0 = new_atomic_bool();
	return (struct lock) {_0};
}
/* new-atomic-bool atomic-bool() */
struct _atomic_bool new_atomic_bool(void) {
	uint8_t _0 = 0;
	return (struct _atomic_bool) {_0};
}
/* empty-arr<island> arr<island>() */
struct arr_3 empty_arr_0(void) {
	uint64_t _0 = 0u;
	struct island** _1 = NULL;
	return (struct arr_3) {_0, _1};
}
/* new-condition condition() */
struct condition new_condition(void) {
	struct lock _0 = new_lock();
	uint64_t _1 = 0u;
	return (struct condition) {_0, _1};
}
/* new-island island(gctx global-ctx, id nat, max-threads nat) */
struct island new_island(struct global_ctx* gctx, uint64_t id, uint64_t max_threads) {
	struct task_queue q0;
	uint64_t _0 = max_threads;
	q0 = new_task_queue(_0);
	
	struct island_gc_root gc_root1;
	struct task_queue _1 = q0;
	struct void_ _2 = (struct void_) {};
	struct fun1_0 _3 = (struct fun1_0) {0, .as0 = _2};
	struct void_ _4 = (struct void_) {};
	struct fun1_1 _5 = (struct fun1_1) {0, .as0 = _4};
	gc_root1 = (struct island_gc_root) {_1, _3, _5};
	
	struct global_ctx* _6 = gctx;
	uint64_t _7 = id;
	struct gc _8 = new_gc();
	struct island_gc_root _9 = gc_root1;
	struct lock _10 = new_lock();
	uint64_t _11 = 0u;
	struct thread_safe_counter _12 = new_thread_safe_counter_0();
	return (struct island) {_6, _7, _8, _9, _10, _11, _12};
}
/* new-task-queue task-queue(max-threads nat) */
struct task_queue new_task_queue(uint64_t max_threads) {
	struct none _0 = (struct none) {};
	struct opt_2 _1 = (struct opt_2) {0, .as0 = _0};
	uint64_t _2 = max_threads;
	struct mut_list_0 _3 = new_mut_list_by_val_with_capacity_from_unmanaged_memory(_2);
	return (struct task_queue) {_1, _3};
}
/* new-mut-list-by-val-with-capacity-from-unmanaged-memory<nat> mut-list<nat>(capacity nat) */
struct mut_list_0 new_mut_list_by_val_with_capacity_from_unmanaged_memory(uint64_t capacity) {
	struct mut_arr_0 backing0;
	uint64_t _0 = capacity;
	uint64_t _1 = capacity;
	uint64_t* _2 = unmanaged_alloc_zeroed_elements(_1);
	backing0 = mut_arr_0(_0, _2);
	
	struct mut_arr_0 _3 = backing0;
	uint64_t _4 = 0u;
	return (struct mut_list_0) {_3, _4};
}
/* mut-arr<?t> mut-arr<nat>(size nat, data ptr<nat>) */
struct mut_arr_0 mut_arr_0(uint64_t size, uint64_t* data) {
	uint64_t _0 = size;
	uint64_t* _1 = data;
	struct arr_2 _2 = (struct arr_2) {_0, _1};
	return (struct mut_arr_0) {_2};
}
/* unmanaged-alloc-zeroed-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_zeroed_elements(uint64_t size_elements) {
	uint64_t* res0;
	uint64_t _0 = size_elements;
	res0 = unmanaged_alloc_elements_0(_0);
	
	uint64_t* _1 = res0;
	uint64_t _2 = size_elements;
	set_zero_range_0(_1, _2);
	return res0;
}
/* unmanaged-alloc-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_elements_0(uint64_t size_elements) {
	uint8_t* bytes0;
	uint64_t _0 = size_elements;
	uint64_t _1 = sizeof(uint64_t);
	uint64_t _2 = _0 * _1;
	bytes0 = unmanaged_alloc_bytes(_2);
	
	uint8_t* _3 = bytes0;
	return (uint64_t*) _3;
}
/* unmanaged-alloc-bytes ptr<nat8>(size nat) */
uint8_t* unmanaged_alloc_bytes(uint64_t size) {
	uint8_t* res0;
	uint64_t _0 = size;
	res0 = malloc(_0);
	
	uint8_t* _1 = res0;
	uint8_t _2 = null__q_0(_1);
	hard_forbid(_2);
	return res0;
}
/* hard-forbid void(condition bool) */
struct void_ hard_forbid(uint8_t condition) {
	uint8_t _0 = condition;
	uint8_t _1 = !_0;
	return hard_assert(_1);
}
/* null?<nat8> bool(a ptr<nat8>) */
uint8_t null__q_0(uint8_t* a) {
	uint8_t* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	uint8_t* _2 = NULL;
	uint64_t _3 = (uint64_t) _2;
	return _op_equal_equal_0(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<nat>, size nat) */
struct void_ set_zero_range_0(uint64_t* begin, uint64_t size) {
	uint64_t* _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(uint64_t);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* default-exception-handler void(e exception) */
struct void_ default_exception_handler(struct ctx* ctx, struct exception e) {
	struct arr_0 _0 = (struct arr_0) {20, constantarr_0_2};
	print_err_no_newline(_0);
	struct exception _1 = e;
	struct arr_0 _2 = _1.message;
	uint8_t _3 = empty__q_0(_2);struct arr_0 _4;
	
	if (_3) {
		_4 = (struct arr_0) {17, constantarr_0_4};
	} else {
		struct exception _5 = e;
		_4 = _5.message;
	}
	print_err(_4);
	struct ctx* _6 = ctx;
	struct global_ctx* _7 = get_global_ctx(_6);
	uint8_t _8 = 1;
	return (_7->any_unhandled_exceptions__q = _8, (struct void_) {});
}
/* print-err-no-newline void(s arr<char>) */
struct void_ print_err_no_newline(struct arr_0 s) {
	int32_t _0 = stderr();
	struct arr_0 _1 = s;
	return write_no_newline(_0, _1);
}
/* write-no-newline void(fd int32, a arr<char>) */
struct void_ write_no_newline(int32_t fd, struct arr_0 a) {
	uint64_t _0 = sizeof(char);
	uint64_t _1 = sizeof(uint8_t);
	uint8_t _2 = _op_equal_equal_0(_0, _1);
	hard_assert(_2);
	int64_t res0;
	int32_t _3 = fd;
	struct arr_0 _4 = a;
	char* _5 = _4.data;
	uint8_t* _6 = (uint8_t*) _5;
	struct arr_0 _7 = a;
	uint64_t _8 = _7.size;
	res0 = write(_3, _6, _8);
	
	int64_t _9 = res0;
	struct arr_0 _10 = a;
	uint64_t _11 = _10.size;
	int64_t _12 = (int64_t) _11;
	uint8_t _13 = _op_bang_equal_0(_9, _12);
	if (_13) {
		return todo_0();
	} else {
		return (struct void_) {};
	}
}
/* !=<int> bool(a int, b int) */
uint8_t _op_bang_equal_0(int64_t a, int64_t b) {
	int64_t _0 = a;
	int64_t _1 = b;
	uint8_t _2 = _op_equal_equal_1(_0, _1);
	return !_2;
}
/* ==<?t> bool(a int, b int) */
uint8_t _op_equal_equal_1(int64_t a, int64_t b) {
	int64_t _0 = a;
	int64_t _1 = b;
	struct comparison _2 = compare_36(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<int-64> (generated) (generated) */
struct comparison compare_36(int64_t a, int64_t b) {
	int64_t _0 = a;
	int64_t _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		int64_t _4 = b;
		int64_t _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* todo<void> void() */
struct void_ todo_0(void) {
	return (assert(0),(struct void_) {});
}
/* stderr int32() */
int32_t stderr(void) {
	return 2;
}
/* print-err void(s arr<char>) */
struct void_ print_err(struct arr_0 s) {
	struct arr_0 _0 = s;
	print_err_no_newline(_0);
	struct arr_0 _1 = (struct arr_0) {1, constantarr_0_3};
	return print_err_no_newline(_1);
}
/* empty?<char> bool(a arr<char>) */
uint8_t empty__q_0(struct arr_0 a) {
	struct arr_0 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* get-global-ctx global-ctx() */
struct global_ctx* get_global_ctx(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	uint8_t* _1 = _0->gctx_ptr;
	return (struct global_ctx*) _1;
}
/* new-island.lambda0 void(it exception) */
struct void_ new_island__lambda0(struct ctx* ctx, struct void_ _closure, struct exception it) {
	struct ctx* _0 = ctx;
	struct exception _1 = it;
	return default_exception_handler(_0, _1);
}
/* default-log-handler void(a logged) */
struct void_ default_log_handler(struct ctx* ctx, struct logged* a) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct ctx* _2 = ctx;
	struct logged* _3 = a;
	struct log_level _4 = _3->level;
	struct arr_0 _5 = to_str_0(_2, _4);
	struct arr_0 _6 = (struct arr_0) {2, constantarr_0_9};
	struct arr_0 _7 = _op_plus_0(_1, _5, _6);
	struct logged* _8 = a;
	struct arr_0 _9 = _8->message;
	struct arr_0 _10 = _op_plus_0(_0, _7, _9);
	return print(_10);
}
/* print void(a arr<char>) */
struct void_ print(struct arr_0 a) {
	struct arr_0 _0 = a;
	print_no_newline(_0);
	struct arr_0 _1 = (struct arr_0) {1, constantarr_0_3};
	return print_no_newline(_1);
}
/* print-no-newline void(a arr<char>) */
struct void_ print_no_newline(struct arr_0 a) {
	int32_t _0 = stdout();
	struct arr_0 _1 = a;
	return write_no_newline(_0, _1);
}
/* stdout int32() */
int32_t stdout(void) {
	return 1;
}
/* +<char> arr<char>(a arr<char>, b arr<char>) */
struct arr_0 _op_plus_0(struct ctx* ctx, struct arr_0 a, struct arr_0 b) {
	uint64_t res_size0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	uint64_t _2 = _1.size;
	struct arr_0 _3 = b;
	uint64_t _4 = _3.size;
	res_size0 = _op_plus_1(_0, _2, _4);
	
	char* res1;
	struct ctx* _5 = ctx;
	uint64_t _6 = res_size0;
	res1 = uninitialized_data_0(_5, _6);
	
	struct ctx* _7 = ctx;
	char* _8 = res1;
	struct arr_0 _9 = a;
	char* _10 = _9.data;
	struct arr_0 _11 = a;
	uint64_t _12 = _11.size;
	copy_data_from_0(_7, _8, _10, _12);
	struct ctx* _13 = ctx;
	char* _14 = res1;
	struct arr_0 _15 = a;
	uint64_t _16 = _15.size;
	char* _17 = _14 + _16;
	struct arr_0 _18 = b;
	char* _19 = _18.data;
	struct arr_0 _20 = b;
	uint64_t _21 = _20.size;
	copy_data_from_0(_13, _17, _19, _21);
	uint64_t _22 = res_size0;
	char* _23 = res1;
	return (struct arr_0) {_22, _23};
}
/* + nat(a nat, b nat) */
uint64_t _op_plus_1(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint64_t res0;
	uint64_t _0 = a;
	uint64_t _1 = b;
	res0 = _0 + _1;
	
	struct ctx* _2 = ctx;
	uint64_t _3 = res0;
	uint64_t _4 = a;
	uint8_t _5 = _op_greater_equal(_3, _4);uint8_t _6;
	
	if (_5) {
		uint64_t _7 = res0;
		uint64_t _8 = b;
		_6 = _op_greater_equal(_7, _8);
	} else {
		_6 = 0;
	}
	assert_0(_2, _6);
	return res0;
}
/* assert void(condition bool) */
struct void_ assert_0(struct ctx* ctx, uint8_t condition) {
	struct ctx* _0 = ctx;
	uint8_t _1 = condition;
	struct arr_0 _2 = (struct arr_0) {13, constantarr_0_5};
	return assert_1(_0, _1, _2);
}
/* assert void(condition bool, message arr<char>) */
struct void_ assert_1(struct ctx* ctx, uint8_t condition, struct arr_0 message) {
	uint8_t _0 = condition;
	uint8_t _1 = !_0;
	if (_1) {
		struct ctx* _2 = ctx;
		struct arr_0 _3 = message;
		return fail_0(_2, _3);
	} else {
		return (struct void_) {};
	}
}
/* fail<void> void(reason arr<char>) */
struct void_ fail_0(struct ctx* ctx, struct arr_0 reason) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = reason;
	struct exception _2 = (struct exception) {_1};
	return throw_0(_0, _2);
}
/* throw<?t> void(e exception) */
struct void_ throw_0(struct ctx* ctx, struct exception e) {
	struct exception_ctx* exn_ctx0;
	struct ctx* _0 = ctx;
	exn_ctx0 = get_exception_ctx(_0);
	
	struct exception_ctx* _1 = exn_ctx0;
	struct jmp_buf_tag* _2 = _1->jmp_buf_ptr;
	uint8_t _3 = null__q_1(_2);
	hard_forbid(_3);
	struct exception_ctx* _4 = exn_ctx0;
	struct exception _5 = e;
	_4->thrown_exception = _5;
	struct exception_ctx* _6 = exn_ctx0;
	struct jmp_buf_tag* _7 = _6->jmp_buf_ptr;
	struct ctx* _8 = ctx;
	int32_t _9 = number_to_throw(_8);
	(longjmp(_7, _9), (struct void_) {});
	return todo_0();
}
/* get-exception-ctx exception-ctx() */
struct exception_ctx* get_exception_ctx(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	uint8_t* _1 = _0->exception_ctx_ptr;
	return (struct exception_ctx*) _1;
}
/* null?<jmp-buf-tag> bool(a ptr<jmp-buf-tag>) */
uint8_t null__q_1(struct jmp_buf_tag* a) {
	struct jmp_buf_tag* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	struct jmp_buf_tag* _2 = NULL;
	uint64_t _3 = (uint64_t) _2;
	return _op_equal_equal_0(_1, _3);
}
/* number-to-throw int32() */
int32_t number_to_throw(struct ctx* ctx) {
	return 7;
}
/* >=<nat> bool(a nat, b nat) */
uint8_t _op_greater_equal(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	uint8_t _2 = _op_less_0(_0, _1);
	return !_2;
}
/* uninitialized-data<?t> ptr<char>(size nat) */
char* uninitialized_data_0(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(char);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (char*) _4;
}
/* alloc ptr<nat8>(size nat) */
uint8_t* alloc(struct ctx* ctx, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct gc* _2 = get_gc(_1);
	uint64_t _3 = size;
	return gc_alloc(_0, _2, _3);
}
/* gc-alloc ptr<nat8>(gc gc, size nat) */
uint8_t* gc_alloc(struct ctx* ctx, struct gc* gc, uint64_t size) {
	struct gc* _0 = gc;
	uint64_t _1 = size;
	struct opt_3 _2 = try_gc_alloc(_0, _1);
	switch (_2.kind) {
		case 0: {
			return todo_1();
		}
		case 1: {
			struct some_3 s0 = _2.as1;
			
			struct some_3 _3 = s0;
			return _3.value;
		}
		default:
			return (assert(0),NULL);
	}
}
/* try-gc-alloc opt<ptr<nat8>>(gc gc, size-bytes nat) */
struct opt_3 try_gc_alloc(struct gc* gc, uint64_t size_bytes) {
	top:;
	struct gc* _0 = gc;
	validate_gc(_0);
	uint64_t size_words0;
	uint64_t _1 = size_bytes;
	size_words0 = words_of_bytes(_1);
	
	uint64_t* cur1;
	struct gc* _2 = gc;
	cur1 = _2->data_cur;
	
	uint64_t* next2;
	uint64_t* _3 = cur1;
	uint64_t _4 = size_words0;
	next2 = _3 + _4;
	
	uint64_t* _5 = next2;
	struct gc* _6 = gc;
	uint64_t* _7 = _6->data_end;
	uint8_t _8 = _5 < _7;
	if (_8) {
		struct gc* _9 = gc;
		uint8_t* _10 = _9->mark_cur;
		struct gc* _11 = gc;
		uint8_t* _12 = _11->mark_cur;
		uint64_t _13 = size_words0;
		uint8_t* _14 = _12 + _13;
		uint8_t _15 = range_free__q(_10, _14);
		if (_15) {
			struct gc* _16 = gc;
			struct gc* _17 = gc;
			uint8_t* _18 = _17->mark_cur;
			uint64_t _19 = size_words0;
			uint8_t* _20 = _18 + _19;
			_16->mark_cur = _20;
			struct gc* _21 = gc;
			uint64_t* _22 = next2;
			_21->data_cur = _22;
			uint64_t* _23 = cur1;
			uint8_t* _24 = (uint8_t*) _23;
			struct some_3 _25 = (struct some_3) {_24};
			return (struct opt_3) {1, .as1 = _25};
		} else {
			struct gc* _26 = gc;
			struct gc* _27 = gc;
			uint8_t* _28 = _27->mark_cur;
			uint8_t* _29 = incr_0(_28);
			_26->mark_cur = _29;
			struct gc* _30 = gc;
			struct gc* _31 = gc;
			uint64_t* _32 = _31->data_cur;
			uint64_t* _33 = incr_1(_32);
			_30->data_cur = _33;
			struct gc* _34 = gc;
			uint64_t _35 = size_bytes;
			gc = _34;
			size_bytes = _35;
			goto top;
		}
	} else {
		struct none _36 = (struct none) {};
		return (struct opt_3) {0, .as0 = _36};
	}
}
/* validate-gc void(gc gc) */
struct void_ validate_gc(struct gc* gc) {
	struct gc* _0 = gc;
	uint8_t* _1 = _0->mark_begin;
	struct gc* _2 = gc;
	uint8_t* _3 = _2->mark_cur;
	uint8_t _4 = ptr_less_eq__q_0(_1, _3);
	hard_assert(_4);
	struct gc* _5 = gc;
	uint8_t* _6 = _5->mark_cur;
	struct gc* _7 = gc;
	uint8_t* _8 = _7->mark_end;
	uint8_t _9 = ptr_less_eq__q_0(_6, _8);
	hard_assert(_9);
	struct gc* _10 = gc;
	uint64_t* _11 = _10->data_begin;
	struct gc* _12 = gc;
	uint64_t* _13 = _12->data_cur;
	uint8_t _14 = ptr_less_eq__q_1(_11, _13);
	hard_assert(_14);
	struct gc* _15 = gc;
	uint64_t* _16 = _15->data_cur;
	struct gc* _17 = gc;
	uint64_t* _18 = _17->data_end;
	uint8_t _19 = ptr_less_eq__q_1(_16, _18);
	hard_assert(_19);
	uint64_t mark_idx0;
	struct gc* _20 = gc;
	uint8_t* _21 = _20->mark_cur;
	struct gc* _22 = gc;
	uint8_t* _23 = _22->mark_begin;
	mark_idx0 = _op_minus_1(_21, _23);
	
	uint64_t data_idx1;
	struct gc* _24 = gc;
	uint64_t* _25 = _24->data_cur;
	struct gc* _26 = gc;
	uint64_t* _27 = _26->data_begin;
	data_idx1 = _op_minus_0(_25, _27);
	
	struct gc* _28 = gc;
	uint8_t* _29 = _28->mark_end;
	struct gc* _30 = gc;
	uint8_t* _31 = _30->mark_begin;
	uint64_t _32 = _op_minus_1(_29, _31);
	struct gc* _33 = gc;
	uint64_t _34 = _33->size_words;
	uint8_t _35 = _op_equal_equal_0(_32, _34);
	hard_assert(_35);
	struct gc* _36 = gc;
	uint64_t* _37 = _36->data_end;
	struct gc* _38 = gc;
	uint64_t* _39 = _38->data_begin;
	uint64_t _40 = _op_minus_0(_37, _39);
	struct gc* _41 = gc;
	uint64_t _42 = _41->size_words;
	uint8_t _43 = _op_equal_equal_0(_40, _42);
	hard_assert(_43);
	uint64_t _44 = mark_idx0;
	uint64_t _45 = data_idx1;
	uint8_t _46 = _op_equal_equal_0(_44, _45);
	return hard_assert(_46);
}
/* ptr-less-eq?<bool> bool(a ptr<bool>, b ptr<bool>) */
uint8_t ptr_less_eq__q_0(uint8_t* a, uint8_t* b) {
	uint8_t* _0 = a;
	uint8_t* _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		return 1;
	} else {
		uint8_t* _3 = a;
		uint8_t* _4 = b;
		return _3 == _4;
	}
}
/* ptr-less-eq?<nat> bool(a ptr<nat>, b ptr<nat>) */
uint8_t ptr_less_eq__q_1(uint64_t* a, uint64_t* b) {
	uint64_t* _0 = a;
	uint64_t* _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		return 1;
	} else {
		uint64_t* _3 = a;
		uint64_t* _4 = b;
		return _3 == _4;
	}
}
/* -<bool> nat(a ptr<bool>, b ptr<bool>) */
uint64_t _op_minus_1(uint8_t* a, uint8_t* b) {
	uint8_t* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	uint8_t* _2 = b;
	uint64_t _3 = (uint64_t) _2;
	uint64_t _4 = _1 - _3;
	uint64_t _5 = sizeof(uint8_t);
	return _4 / _5;
}
/* range-free? bool(mark ptr<bool>, end ptr<bool>) */
uint8_t range_free__q(uint8_t* mark, uint8_t* end) {
	top:;
	uint8_t* _0 = mark;
	uint8_t* _1 = end;
	uint8_t _2 = _0 == _1;
	if (_2) {
		return 1;
	} else {
		uint8_t* _3 = mark;
		uint8_t _4 = *_3;
		if (_4) {
			return 0;
		} else {
			uint8_t* _5 = mark;
			uint8_t* _6 = incr_0(_5);
			uint8_t* _7 = end;
			mark = _6;
			end = _7;
			goto top;
		}
	}
}
/* incr<nat> ptr<nat>(p ptr<nat>) */
uint64_t* incr_1(uint64_t* p) {
	uint64_t* _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* todo<ptr<nat8>> ptr<nat8>() */
uint8_t* todo_1(void) {
	return (assert(0),NULL);
}
/* get-gc gc() */
struct gc* get_gc(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	struct gc_ctx* _1 = get_gc_ctx_0(_0);
	return _1->gc;
}
/* get-gc-ctx gc-ctx() */
struct gc_ctx* get_gc_ctx_0(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	uint8_t* _1 = _0->gc_ctx_ptr;
	return (struct gc_ctx*) _1;
}
/* copy-data-from<?t> void(to ptr<char>, from ptr<char>, len nat) */
struct void_ copy_data_from_0(struct ctx* ctx, char* to, char* from, uint64_t len) {
	top:;
	uint64_t _0 = len;
	uint64_t _1 = 8u;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		char* _4 = to;
		char* _5 = from;
		uint64_t _6 = len;
		return copy_data_from_small_0(_3, _4, _5, _6);
	} else {
		uint64_t hl0;
		struct ctx* _7 = ctx;
		uint64_t _8 = len;
		uint64_t _9 = 2u;
		hl0 = _op_div(_7, _8, _9);
		
		struct ctx* _10 = ctx;
		char* _11 = to;
		char* _12 = from;
		uint64_t _13 = hl0;
		copy_data_from_0(_10, _11, _12, _13);
		char* _14 = to;
		uint64_t _15 = hl0;
		char* _16 = _14 + _15;
		char* _17 = from;
		uint64_t _18 = hl0;
		char* _19 = _17 + _18;
		struct ctx* _20 = ctx;
		uint64_t _21 = len;
		uint64_t _22 = hl0;
		uint64_t _23 = _op_minus_2(_20, _21, _22);
		to = _16;
		from = _19;
		len = _23;
		goto top;
	}
}
/* copy-data-from-small<?t> void(to ptr<char>, from ptr<char>, len nat) */
struct void_ copy_data_from_small_0(struct ctx* ctx, char* to, char* from, uint64_t len) {
	uint64_t _0 = len;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		char* _3 = to;
		char* _4 = from;
		char _5 = *_4;
		*_3 = _5;
		struct ctx* _6 = ctx;
		char* _7 = to;
		char* _8 = incr_2(_7);
		char* _9 = from;
		char* _10 = incr_2(_9);
		struct ctx* _11 = ctx;
		uint64_t _12 = len;
		uint64_t _13 = decr(_11, _12);
		return copy_data_from_0(_6, _8, _10, _13);
	} else {
		return (struct void_) {};
	}
}
/* !=<nat> bool(a nat, b nat) */
uint8_t _op_bang_equal_1(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	uint8_t _2 = _op_equal_equal_0(_0, _1);
	return !_2;
}
/* incr<?t> ptr<char>(p ptr<char>) */
char* incr_2(char* p) {
	char* _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* decr nat(a nat) */
uint64_t decr(struct ctx* ctx, uint64_t a) {
	struct ctx* _0 = ctx;
	uint64_t _1 = a;
	uint64_t _2 = 0u;
	uint8_t _3 = _op_equal_equal_0(_1, _2);
	forbid_0(_0, _3);
	uint64_t _4 = a;
	return wrap_decr(_4);
}
/* forbid void(condition bool) */
struct void_ forbid_0(struct ctx* ctx, uint8_t condition) {
	struct ctx* _0 = ctx;
	uint8_t _1 = condition;
	struct arr_0 _2 = (struct arr_0) {13, constantarr_0_6};
	return forbid_1(_0, _1, _2);
}
/* forbid void(condition bool, message arr<char>) */
struct void_ forbid_1(struct ctx* ctx, uint8_t condition, struct arr_0 message) {
	uint8_t _0 = condition;
	if (_0) {
		struct ctx* _1 = ctx;
		struct arr_0 _2 = message;
		return fail_0(_1, _2);
	} else {
		return (struct void_) {};
	}
}
/* wrap-decr nat(a nat) */
uint64_t wrap_decr(uint64_t a) {
	uint64_t _0 = a;
	uint64_t _1 = 1u;
	return _0 - _1;
}
/* / nat(a nat, b nat) */
uint64_t _op_div(struct ctx* ctx, uint64_t a, uint64_t b) {
	struct ctx* _0 = ctx;
	uint64_t _1 = b;
	uint64_t _2 = 0u;
	uint8_t _3 = _op_equal_equal_0(_1, _2);
	forbid_0(_0, _3);
	uint64_t _4 = a;
	uint64_t _5 = b;
	return _4 / _5;
}
/* - nat(a nat, b nat) */
uint64_t _op_minus_2(struct ctx* ctx, uint64_t a, uint64_t b) {
	struct ctx* _0 = ctx;
	uint64_t _1 = a;
	uint64_t _2 = b;
	uint8_t _3 = _op_greater_equal(_1, _2);
	assert_0(_0, _3);
	uint64_t _4 = a;
	uint64_t _5 = b;
	return _4 - _5;
}
/* to-str arr<char>(a log-level) */
struct arr_0 to_str_0(struct ctx* ctx, struct log_level a) {
	struct log_level _0 = a;
	switch (_0.kind) {
		case 0: {
			return (struct arr_0) {4, constantarr_0_7};
		}
		case 1: {
			return (struct arr_0) {4, constantarr_0_8};
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* new-island.lambda1 void(log logged) */
struct void_ new_island__lambda1(struct ctx* ctx, struct void_ _closure, struct logged* log) {
	struct ctx* _0 = ctx;
	struct logged* _1 = log;
	return default_log_handler(_0, _1);
}
/* new-gc gc() */
struct gc new_gc(void) {
	uint8_t* mark_begin0;
	uint64_t _0 = 16777216u;
	uint8_t* _1 = malloc(_0);
	mark_begin0 = (uint8_t*) _1;
	
	uint8_t* mark_end1;
	uint8_t* _2 = mark_begin0;
	uint64_t _3 = 16777216u;
	mark_end1 = _2 + _3;
	
	uint64_t* data_begin2;
	uint64_t _4 = 16777216u;
	uint64_t _5 = sizeof(uint64_t);
	uint64_t _6 = _4 * _5;
	uint8_t* _7 = malloc(_6);
	data_begin2 = (uint64_t*) _7;
	
	uint64_t* data_end3;
	uint64_t* _8 = data_begin2;
	uint64_t _9 = 16777216u;
	data_end3 = _8 + _9;
	
	uint8_t* _10 = mark_begin0;
	uint8_t* _11 = (uint8_t*) _10;
	uint8_t _12 = 0u;
	uint64_t _13 = 16777216u;
	(memset(_11, _12, _13), (struct void_) {});
	struct lock _14 = new_lock();
	uint64_t _15 = 0u;
	struct none _16 = (struct none) {};
	struct opt_1 _17 = (struct opt_1) {0, .as0 = _16};
	uint8_t _18 = 0;
	uint64_t _19 = 16777216u;
	uint8_t* _20 = mark_begin0;
	uint8_t* _21 = mark_begin0;
	uint8_t* _22 = mark_end1;
	uint64_t* _23 = data_begin2;
	uint64_t* _24 = data_begin2;
	uint64_t* _25 = data_end3;
	return (struct gc) {_14, _15, _17, _18, _19, _20, _21, _22, _23, _24, _25};
}
/* new-thread-safe-counter thread-safe-counter() */
struct thread_safe_counter new_thread_safe_counter_0(void) {
	uint64_t _0 = 0u;
	return new_thread_safe_counter_1(_0);
}
/* new-thread-safe-counter thread-safe-counter(init nat) */
struct thread_safe_counter new_thread_safe_counter_1(uint64_t init) {
	struct lock _0 = new_lock();
	uint64_t _1 = init;
	return (struct thread_safe_counter) {_0, _1};
}
/* do-main fut<int32>(gctx global-ctx, island island, argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
struct fut_0* do_main(struct global_ctx* gctx, struct island* island, int32_t argc, char** argv, fun_ptr2 main_ptr) {
	struct exception_ctx ectx0;
	ectx0 = new_exception_ctx();
	
	struct log_ctx log_ctx1;
	log_ctx1 = new_log_ctx();
	
	struct thread_local_stuff tls2;
	struct exception_ctx* _0 = &ectx0;
	struct log_ctx* _1 = &log_ctx1;
	tls2 = (struct thread_local_stuff) {_0, _1};
	
	struct ctx ctx_by_val3;
	struct global_ctx* _2 = gctx;
	struct thread_local_stuff* _3 = &tls2;
	struct island* _4 = island;
	uint64_t _5 = 0u;
	ctx_by_val3 = new_ctx(_2, _3, _4, _5);
	
	struct ctx* ctx4;
	ctx4 = &ctx_by_val3;
	
	struct fun2 add5;
	struct void_ _6 = (struct void_) {};
	add5 = (struct fun2) {0, .as0 = _6};
	
	struct arr_4 all_args6;
	int32_t _7 = argc;
	int64_t _8 = (int64_t) _7;
	uint64_t _9 = (uint64_t) _8;
	char** _10 = argv;
	all_args6 = (struct arr_4) {_9, _10};
	
	struct fun2 _11 = add5;
	struct ctx* _12 = ctx4;
	struct arr_4 _13 = all_args6;
	fun_ptr2 _14 = main_ptr;
	return call_w_ctx_198(_11, _12, _13, _14);
}
/* new-exception-ctx exception-ctx() */
struct exception_ctx new_exception_ctx(void) {
	struct jmp_buf_tag* _0 = NULL;
	struct arr_0 _1 = (struct arr_0) {0u, NULL};
	struct exception _2 = (struct exception) {_1};
	return (struct exception_ctx) {_0, _2};
}
/* new-log-ctx log-ctx() */
struct log_ctx new_log_ctx(void) {
	struct fun1_1 _0 = (struct fun1_1) {0};
	return (struct log_ctx) {_0};
}
/* new-ctx ctx(gctx global-ctx, tls thread-local-stuff, island island, exclusion nat) */
struct ctx new_ctx(struct global_ctx* gctx, struct thread_local_stuff* tls, struct island* island, uint64_t exclusion) {
	uint8_t* gc_ctx0;
	struct gc* _0 = &island->gc;
	struct gc_ctx* _1 = get_gc_ctx_1(_0);
	gc_ctx0 = (uint8_t*) _1;
	
	struct exception_ctx* exception_ctx1;
	struct thread_local_stuff* _2 = tls;
	exception_ctx1 = _2->exception_ctx;
	
	struct log_ctx* log_ctx2;
	struct thread_local_stuff* _3 = tls;
	log_ctx2 = _3->log_ctx;
	
	struct log_ctx* _4 = log_ctx2;
	struct island_gc_root* _5 = &island->gc_root;
	struct fun1_1 _6 = _5->log_handler;
	_4->handler = _6;
	struct global_ctx* _7 = gctx;
	uint8_t* _8 = (uint8_t*) _7;
	struct island* _9 = island;
	uint64_t _10 = _9->id;
	uint64_t _11 = exclusion;
	uint8_t* _12 = gc_ctx0;
	struct exception_ctx* _13 = exception_ctx1;
	uint8_t* _14 = (uint8_t*) _13;
	struct log_ctx* _15 = log_ctx2;
	uint8_t* _16 = (uint8_t*) _15;
	return (struct ctx) {_8, _10, _11, _12, _14, _16};
}
/* get-gc-ctx gc-ctx(gc gc) */
struct gc_ctx* get_gc_ctx_1(struct gc* gc) {
	struct lock* _0 = &gc->lk;
	acquire_lock(_0);
	struct gc_ctx* res3;
	struct gc* _1 = gc;
	struct opt_1 _2 = _1->context_head;
	switch (_2.kind) {
		case 0: {
			struct gc_ctx* c0;
			uint64_t _3 = sizeof(struct gc_ctx);
			uint8_t* _4 = malloc(_3);
			c0 = (struct gc_ctx*) _4;
			
			struct gc_ctx* _5 = c0;
			struct gc* _6 = gc;
			_5->gc = _6;
			struct gc_ctx* _7 = c0;
			struct none _8 = (struct none) {};
			struct opt_1 _9 = (struct opt_1) {0, .as0 = _8};
			_7->next_ctx = _9;
			res3 = c0;
			break;
		}
		case 1: {
			struct some_1 s1 = _2.as1;
			
			struct gc_ctx* c2;
			struct some_1 _10 = s1;
			c2 = _10.value;
			
			struct gc* _11 = gc;
			struct gc_ctx* _12 = c2;
			struct opt_1 _13 = _12->next_ctx;
			_11->context_head = _13;
			struct gc_ctx* _14 = c2;
			struct none _15 = (struct none) {};
			struct opt_1 _16 = (struct opt_1) {0, .as0 = _15};
			_14->next_ctx = _16;
			res3 = c2;
			break;
		}
		default:
			(assert(0),NULL);
	}
	
	struct lock* _17 = &gc->lk;
	release_lock(_17);
	return res3;
}
/* acquire-lock void(a lock) */
struct void_ acquire_lock(struct lock* a) {
	struct lock* _0 = a;
	uint64_t _1 = 0u;
	return acquire_lock_recur(_0, _1);
}
/* acquire-lock-recur void(a lock, n-tries nat) */
struct void_ acquire_lock_recur(struct lock* a, uint64_t n_tries) {
	top:;
	struct lock* _0 = a;
	uint8_t _1 = try_acquire_lock(_0);
	uint8_t _2 = !_1;
	if (_2) {
		uint64_t _3 = n_tries;
		uint64_t _4 = 1000u;
		uint8_t _5 = _op_equal_equal_0(_3, _4);
		if (_5) {
			return (assert(0),(struct void_) {});
		} else {
			yield_thread();
			struct lock* _6 = a;
			uint64_t _7 = n_tries;
			uint64_t _8 = noctx_incr(_7);
			a = _6;
			n_tries = _8;
			goto top;
		}
	} else {
		return (struct void_) {};
	}
}
/* try-acquire-lock bool(a lock) */
uint8_t try_acquire_lock(struct lock* a) {
	struct _atomic_bool* _0 = &a->is_locked;
	return try_set(_0);
}
/* try-set bool(a atomic-bool) */
uint8_t try_set(struct _atomic_bool* a) {
	struct _atomic_bool* _0 = a;
	uint8_t _1 = 0;
	return try_change(_0, _1);
}
/* try-change bool(a atomic-bool, old-value bool) */
uint8_t try_change(struct _atomic_bool* a, uint8_t old_value) {
	uint8_t* _0 = &a->value;
	uint8_t* _1 = &old_value;
	uint8_t _2 = old_value;
	uint8_t _3 = !_2;
	return atomic_compare_exchange_strong(_0, _1, _3);
}
/* yield-thread void() */
struct void_ yield_thread(void) {
	int32_t err0;
	err0 = pthread_yield();
	
	int32_t _0 = err0;
	int32_t _1 = 0;
	uint8_t _2 = _op_equal_equal_2(_0, _1);
	return hard_assert(_2);
}
/* ==<int32> bool(a int32, b int32) */
uint8_t _op_equal_equal_2(int32_t a, int32_t b) {
	int32_t _0 = a;
	int32_t _1 = b;
	struct comparison _2 = compare_99(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<int-32> (generated) (generated) */
struct comparison compare_99(int32_t a, int32_t b) {
	int32_t _0 = a;
	int32_t _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		int32_t _4 = b;
		int32_t _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* noctx-incr nat(n nat) */
uint64_t noctx_incr(uint64_t n) {
	uint64_t _0 = n;
	uint64_t _1 = max_nat();
	uint8_t _2 = _op_less_0(_0, _1);
	hard_assert(_2);
	uint64_t _3 = n;
	return wrap_incr(_3);
}
/* max-nat nat() */
uint64_t max_nat(void) {
	return 18446744073709551615u;
}
/* wrap-incr nat(a nat) */
uint64_t wrap_incr(uint64_t a) {
	uint64_t _0 = a;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* release-lock void(l lock) */
struct void_ release_lock(struct lock* l) {
	struct _atomic_bool* _0 = &l->is_locked;
	return must_unset(_0);
}
/* must-unset void(a atomic-bool) */
struct void_ must_unset(struct _atomic_bool* a) {
	uint8_t did_unset0;
	struct _atomic_bool* _0 = a;
	did_unset0 = try_unset(_0);
	
	uint8_t _1 = did_unset0;
	return hard_assert(_1);
}
/* try-unset bool(a atomic-bool) */
uint8_t try_unset(struct _atomic_bool* a) {
	struct _atomic_bool* _0 = a;
	uint8_t _1 = 1;
	return try_change(_0, _1);
}
/* add-first-task fut<int32>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct fut_1* _2 = delay(_1);
	struct ctx* _3 = ctx;
	struct island_and_exclusion _4 = cur_island_and_exclusion(_3);
	struct add_first_task__lambda0* temp0;
	struct ctx* _5 = ctx;
	uint64_t _6 = sizeof(struct add_first_task__lambda0);
	uint8_t* _7 = alloc(_5, _6);
	temp0 = (struct add_first_task__lambda0*) _7;
	
	struct add_first_task__lambda0* _8 = temp0;
	struct arr_4 _9 = all_args;
	fun_ptr2 _10 = main_ptr;
	struct add_first_task__lambda0 _11 = (struct add_first_task__lambda0) {_9, _10};
	*_8 = _11;
	struct add_first_task__lambda0* _12 = temp0;
	struct fun_act0_1 _13 = (struct fun_act0_1) {0, .as0 = _12};
	struct fun_ref0 _14 = (struct fun_ref0) {_4, _13};
	return then2(_0, _2, _14);
}
/* then2<int32> fut<int32>(f fut<void>, cb fun-ref0<int32>) */
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb) {
	struct ctx* _0 = ctx;
	struct fut_1* _1 = f;
	struct ctx* _2 = ctx;
	struct island_and_exclusion _3 = cur_island_and_exclusion(_2);
	struct then2__lambda0* temp0;
	struct ctx* _4 = ctx;
	uint64_t _5 = sizeof(struct then2__lambda0);
	uint8_t* _6 = alloc(_4, _5);
	temp0 = (struct then2__lambda0*) _6;
	
	struct then2__lambda0* _7 = temp0;
	struct fun_ref0 _8 = cb;
	struct then2__lambda0 _9 = (struct then2__lambda0) {_8};
	*_7 = _9;
	struct then2__lambda0* _10 = temp0;
	struct fun_act1_2 _11 = (struct fun_act1_2) {0, .as0 = _10};
	struct fun_ref1 _12 = (struct fun_ref1) {_3, _11};
	return then_0(_0, _1, _12);
}
/* then<?out, void> fut<int32>(f fut<void>, cb fun-ref1<int32, void>) */
struct fut_0* then_0(struct ctx* ctx, struct fut_1* f, struct fun_ref1 cb) {
	struct fut_0* res0;
	struct ctx* _0 = ctx;
	res0 = new_unresolved_fut(_0);
	
	struct ctx* _1 = ctx;
	struct fut_1* _2 = f;
	struct then_0__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct then_0__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct then_0__lambda0*) _5;
	
	struct then_0__lambda0* _6 = temp0;
	struct fun_ref1 _7 = cb;
	struct fut_0* _8 = res0;
	struct then_0__lambda0 _9 = (struct then_0__lambda0) {_7, _8};
	*_6 = _9;
	struct then_0__lambda0* _10 = temp0;
	struct fun_act1_1 _11 = (struct fun_act1_1) {0, .as0 = _10};
	then_void_0(_1, _2, _11);
	return res0;
}
/* new-unresolved-fut<?out> fut<int32>() */
struct fut_0* new_unresolved_fut(struct ctx* ctx) {
	struct fut_0* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct fut_0);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct fut_0*) _2;
	
	struct fut_0* _3 = temp0;
	struct lock _4 = new_lock();
	struct none _5 = (struct none) {};
	struct opt_0 _6 = (struct opt_0) {0, .as0 = _5};
	struct fut_state_callbacks_0 _7 = (struct fut_state_callbacks_0) {_6};
	struct fut_state_0 _8 = (struct fut_state_0) {0, .as0 = _7};
	struct fut_0 _9 = (struct fut_0) {_4, _8};
	*_3 = _9;
	return temp0;
}
/* then-void<?in> void(f fut<void>, cb fun-act1<void, result<void, exception>>) */
struct void_ then_void_0(struct ctx* ctx, struct fut_1* f, struct fun_act1_1 cb) {
	struct lock* _0 = &f->lk;
	acquire_lock(_0);
	struct fut_1* _1 = f;
	struct fut_state_1 _2 = _1->state;
	switch (_2.kind) {
		case 0: {
			struct fut_state_callbacks_1 cbs0 = _2.as0;
			
			struct fut_1* _3 = f;
			struct fut_callback_node_1* temp0;
			struct ctx* _4 = ctx;
			uint64_t _5 = sizeof(struct fut_callback_node_1);
			uint8_t* _6 = alloc(_4, _5);
			temp0 = (struct fut_callback_node_1*) _6;
			
			struct fut_callback_node_1* _7 = temp0;
			struct fun_act1_1 _8 = cb;
			struct fut_state_callbacks_1 _9 = cbs0;
			struct opt_4 _10 = _9.head;
			struct fut_callback_node_1 _11 = (struct fut_callback_node_1) {_8, _10};
			*_7 = _11;
			struct fut_callback_node_1* _12 = temp0;
			struct some_4 _13 = (struct some_4) {_12};
			struct opt_4 _14 = (struct opt_4) {1, .as1 = _13};
			struct fut_state_callbacks_1 _15 = (struct fut_state_callbacks_1) {_14};
			struct fut_state_1 _16 = (struct fut_state_1) {0, .as0 = _15};
			_3->state = _16;
			break;
		}
		case 1: {
			struct fut_state_resolved_1 r1 = _2.as1;
			
			struct ctx* _17 = ctx;
			struct fun_act1_1 _18 = cb;
			struct fut_state_resolved_1 _19 = r1;
			struct void_ _20 = _19.value;
			struct ok_1 _21 = (struct ok_1) {_20};
			struct result_1 _22 = (struct result_1) {0, .as0 = _21};
			call_0(_17, _18, _22);
			break;
		}
		case 2: {
			struct exception e2 = _2.as2;
			
			struct ctx* _23 = ctx;
			struct fun_act1_1 _24 = cb;
			struct exception _25 = e2;
			struct err_0 _26 = (struct err_0) {_25};
			struct result_1 _27 = (struct result_1) {1, .as1 = _26};
			call_0(_23, _24, _27);
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	struct lock* _28 = &f->lk;
	return release_lock(_28);
}
/* call<void, result<?t, exception>> void(a fun-act1<void, result<void, exception>>, p0 result<void, exception>) */
struct void_ call_0(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0) {
	struct fun_act1_1 _0 = a;
	struct ctx* _1 = ctx;
	struct result_1 _2 = p0;
	return call_w_ctx_112(_0, _1, _2);
}
/* call-w-ctx<void, result<void, exception>> (generated) (generated) */
struct void_ call_w_ctx_112(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0) {
	struct fun_act1_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then_0__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct then_0__lambda0* _2 = closure0;
			struct result_1 _3 = p0;
			return then_0__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* forward-to<?out> void(from fut<int32>, to fut<int32>) */
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to) {
	struct ctx* _0 = ctx;
	struct fut_0* _1 = from;
	struct forward_to__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct forward_to__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct forward_to__lambda0*) _4;
	
	struct forward_to__lambda0* _5 = temp0;
	struct fut_0* _6 = to;
	struct forward_to__lambda0 _7 = (struct forward_to__lambda0) {_6};
	*_5 = _7;
	struct forward_to__lambda0* _8 = temp0;
	struct fun_act1_0 _9 = (struct fun_act1_0) {0, .as0 = _8};
	return then_void_1(_0, _1, _9);
}
/* then-void<?t> void(f fut<int32>, cb fun-act1<void, result<int32, exception>>) */
struct void_ then_void_1(struct ctx* ctx, struct fut_0* f, struct fun_act1_0 cb) {
	struct lock* _0 = &f->lk;
	acquire_lock(_0);
	struct fut_0* _1 = f;
	struct fut_state_0 _2 = _1->state;
	switch (_2.kind) {
		case 0: {
			struct fut_state_callbacks_0 cbs0 = _2.as0;
			
			struct fut_0* _3 = f;
			struct fut_callback_node_0* temp0;
			struct ctx* _4 = ctx;
			uint64_t _5 = sizeof(struct fut_callback_node_0);
			uint8_t* _6 = alloc(_4, _5);
			temp0 = (struct fut_callback_node_0*) _6;
			
			struct fut_callback_node_0* _7 = temp0;
			struct fun_act1_0 _8 = cb;
			struct fut_state_callbacks_0 _9 = cbs0;
			struct opt_0 _10 = _9.head;
			struct fut_callback_node_0 _11 = (struct fut_callback_node_0) {_8, _10};
			*_7 = _11;
			struct fut_callback_node_0* _12 = temp0;
			struct some_0 _13 = (struct some_0) {_12};
			struct opt_0 _14 = (struct opt_0) {1, .as1 = _13};
			struct fut_state_callbacks_0 _15 = (struct fut_state_callbacks_0) {_14};
			struct fut_state_0 _16 = (struct fut_state_0) {0, .as0 = _15};
			_3->state = _16;
			break;
		}
		case 1: {
			struct fut_state_resolved_0 r1 = _2.as1;
			
			struct ctx* _17 = ctx;
			struct fun_act1_0 _18 = cb;
			struct fut_state_resolved_0 _19 = r1;
			int32_t _20 = _19.value;
			struct ok_0 _21 = (struct ok_0) {_20};
			struct result_0 _22 = (struct result_0) {0, .as0 = _21};
			call_1(_17, _18, _22);
			break;
		}
		case 2: {
			struct exception e2 = _2.as2;
			
			struct ctx* _23 = ctx;
			struct fun_act1_0 _24 = cb;
			struct exception _25 = e2;
			struct err_0 _26 = (struct err_0) {_25};
			struct result_0 _27 = (struct result_0) {1, .as1 = _26};
			call_1(_23, _24, _27);
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	struct lock* _28 = &f->lk;
	return release_lock(_28);
}
/* call<void, result<?t, exception>> void(a fun-act1<void, result<int32, exception>>, p0 result<int32, exception>) */
struct void_ call_1(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0) {
	struct fun_act1_0 _0 = a;
	struct ctx* _1 = ctx;
	struct result_0 _2 = p0;
	return call_w_ctx_116(_0, _1, _2);
}
/* call-w-ctx<void, result<int32, exception>> (generated) (generated) */
struct void_ call_w_ctx_116(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0) {
	struct fun_act1_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct forward_to__lambda0* _2 = closure0;
			struct result_0 _3 = p0;
			return forward_to__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* resolve-or-reject<?t> void(f fut<int32>, result result<int32, exception>) */
struct void_ resolve_or_reject(struct ctx* ctx, struct fut_0* f, struct result_0 result) {
	struct lock* _0 = &f->lk;
	acquire_lock(_0);
	struct fut_0* _1 = f;
	struct fut_state_0 _2 = _1->state;
	switch (_2.kind) {
		case 0: {
			struct fut_state_callbacks_0 cbs0 = _2.as0;
			
			struct ctx* _3 = ctx;
			struct fut_state_callbacks_0 _4 = cbs0;
			struct opt_0 _5 = _4.head;
			struct result_0 _6 = result;
			resolve_or_reject_recur(_3, _5, _6);
			break;
		}
		case 1: {
			(assert(0),(struct void_) {});
			break;
		}
		case 2: {
			(assert(0),(struct void_) {});
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	struct fut_0* _7 = f;
	struct result_0 _8 = result;struct fut_state_0 _9;
	
	switch (_8.kind) {
		case 0: {
			struct ok_0 o1 = _8.as0;
			
			struct ok_0 _10 = o1;
			int32_t _11 = _10.value;
			struct fut_state_resolved_0 _12 = (struct fut_state_resolved_0) {_11};
			_9 = (struct fut_state_0) {1, .as1 = _12};
			break;
		}
		case 1: {
			struct err_0 e2 = _8.as1;
			
			struct exception ex3;
			struct err_0 _13 = e2;
			ex3 = _13.value;
			
			struct exception _14 = ex3;
			_9 = (struct fut_state_0) {2, .as2 = _14};
			break;
		}
		default:
			(assert(0),(struct fut_state_0) {0});
	}
	_7->state = _9;
	struct lock* _15 = &f->lk;
	return release_lock(_15);
}
/* resolve-or-reject-recur<?t> void(node opt<fut-callback-node<int32>>, value result<int32, exception>) */
struct void_ resolve_or_reject_recur(struct ctx* ctx, struct opt_0 node, struct result_0 value) {
	top:;
	struct opt_0 _0 = node;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_0 s0 = _0.as1;
			
			struct ctx* _1 = ctx;
			struct some_0 _2 = s0;
			struct fut_callback_node_0* _3 = _2.value;
			struct fun_act1_0 _4 = _3->cb;
			struct result_0 _5 = value;
			struct void_ _6 = call_1(_1, _4, _5);
			drop_0(_6);
			struct some_0 _7 = s0;
			struct fut_callback_node_0* _8 = _7.value;
			struct opt_0 _9 = _8->next_node;
			struct result_0 _10 = value;
			node = _9;
			value = _10;
			goto top;
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* drop<void> void(_ void) */
struct void_ drop_0(struct void_ _p0) {
	return (struct void_) {};
}
/* forward-to<?out>.lambda0 void(it result<int32, exception>) */
struct void_ forward_to__lambda0(struct ctx* ctx, struct forward_to__lambda0* _closure, struct result_0 it) {
	struct ctx* _0 = ctx;
	struct forward_to__lambda0* _1 = _closure;
	struct fut_0* _2 = _1->to;
	struct result_0 _3 = it;
	return resolve_or_reject(_0, _2, _3);
}
/* call-ref<?out, ?in> fut<int32>(f fun-ref1<int32, void>, p0 void) */
struct fut_0* call_ref_0(struct ctx* ctx, struct fun_ref1 f, struct void_ p0) {
	struct island* island0;
	struct ctx* _0 = ctx;
	struct fun_ref1 _1 = f;
	struct island_and_exclusion _2 = _1.island_and_exclusion;
	uint64_t _3 = _2.island;
	island0 = get_island(_0, _3);
	
	struct fut_0* res1;
	struct ctx* _4 = ctx;
	res1 = new_unresolved_fut(_4);
	
	struct ctx* _5 = ctx;
	struct island* _6 = island0;
	struct fun_ref1 _7 = f;
	struct island_and_exclusion _8 = _7.island_and_exclusion;
	uint64_t _9 = _8.exclusion;
	struct call_ref_0__lambda0* temp0;
	struct ctx* _10 = ctx;
	uint64_t _11 = sizeof(struct call_ref_0__lambda0);
	uint8_t* _12 = alloc(_10, _11);
	temp0 = (struct call_ref_0__lambda0*) _12;
	
	struct call_ref_0__lambda0* _13 = temp0;
	struct fun_ref1 _14 = f;
	struct void_ _15 = p0;
	struct fut_0* _16 = res1;
	struct call_ref_0__lambda0 _17 = (struct call_ref_0__lambda0) {_14, _15, _16};
	*_13 = _17;
	struct call_ref_0__lambda0* _18 = temp0;
	struct fun_act0_0 _19 = (struct fun_act0_0) {1, .as1 = _18};
	add_task_0(_5, _6, _9, _19);
	return res1;
}
/* get-island island(island-id nat) */
struct island* get_island(struct ctx* ctx, uint64_t island_id) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct global_ctx* _2 = get_global_ctx(_1);
	struct arr_3 _3 = _2->islands;
	uint64_t _4 = island_id;
	return at_0(_0, _3, _4);
}
/* at<island> island(a arr<island>, index nat) */
struct island* at_0(struct ctx* ctx, struct arr_3 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_3 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_3 _5 = a;
	uint64_t _6 = index;
	return noctx_at_0(_5, _6);
}
/* noctx-at<?t> island(a arr<island>, index nat) */
struct island* noctx_at_0(struct arr_3 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_3 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_3 _4 = a;
	struct island** _5 = _4.data;
	uint64_t _6 = index;
	struct island** _7 = _5 + _6;
	return *_7;
}
/* add-task void(a island, exclusion nat, action fun-act0<void>) */
struct void_ add_task_0(struct ctx* ctx, struct island* a, uint64_t exclusion, struct fun_act0_0 action) {
	struct ctx* _0 = ctx;
	struct island* _1 = a;
	uint64_t _2 = no_timestamp();
	uint64_t _3 = exclusion;
	struct fun_act0_0 _4 = action;
	return add_task_1(_0, _1, _2, _3, _4);
}
/* add-task void(a island, timestamp nat, exclusion nat, action fun-act0<void>) */
struct void_ add_task_1(struct ctx* ctx, struct island* a, uint64_t timestamp, uint64_t exclusion, struct fun_act0_0 action) {
	struct task_queue_node* node0;
	struct ctx* _0 = ctx;
	uint64_t _1 = timestamp;
	uint64_t _2 = exclusion;
	struct fun_act0_0 _3 = action;
	struct task _4 = (struct task) {_1, _2, _3};
	node0 = new_task_queue_node(_0, _4);
	
	struct lock* _5 = &a->tasks_lock;
	acquire_lock(_5);
	struct island* _6 = a;
	struct task_queue* _7 = tasks(_6);
	struct task_queue_node* _8 = node0;
	insert_task(_7, _8);
	struct lock* _9 = &a->tasks_lock;
	release_lock(_9);
	struct condition* _10 = &a->gctx->may_be_work_to_do;
	return broadcast(_10);
}
/* new-task-queue-node task-queue-node(task task) */
struct task_queue_node* new_task_queue_node(struct ctx* ctx, struct task task) {
	struct task_queue_node* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct task_queue_node);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct task_queue_node*) _2;
	
	struct task_queue_node* _3 = temp0;
	struct task _4 = task;
	struct none _5 = (struct none) {};
	struct opt_2 _6 = (struct opt_2) {0, .as0 = _5};
	struct task_queue_node _7 = (struct task_queue_node) {_4, _6};
	*_3 = _7;
	return temp0;
}
/* insert-task void(a task-queue, inserted task-queue-node) */
struct void_ insert_task(struct task_queue* a, struct task_queue_node* inserted) {
	uint64_t size_before0;
	struct task_queue* _0 = a;
	size_before0 = size_0(_0);
	
	struct task_queue* _1 = a;
	struct opt_2 _2 = _1->head;
	switch (_2.kind) {
		case 0: {
			struct task_queue* _3 = a;
			struct task_queue_node* _4 = inserted;
			struct some_2 _5 = (struct some_2) {_4};
			struct opt_2 _6 = (struct opt_2) {1, .as1 = _5};
			_3->head = _6;
			break;
		}
		case 1: {
			struct some_2 s1 = _2.as1;
			
			struct task_queue_node* head2;
			struct some_2 _7 = s1;
			head2 = _7.value;
			
			struct task_queue_node* _8 = head2;
			struct task _9 = _8->task;
			uint64_t _10 = _9.time;
			struct task_queue_node* _11 = inserted;
			struct task _12 = _11->task;
			uint64_t _13 = _12.time;
			uint8_t _14 = _op_less_equal(_10, _13);
			if (_14) {
				struct task_queue_node* _15 = head2;
				struct task_queue_node* _16 = inserted;
				insert_recur(_15, _16);
			} else {
				struct task_queue_node* _17 = inserted;
				struct task_queue_node* _18 = head2;
				struct some_2 _19 = (struct some_2) {_18};
				struct opt_2 _20 = (struct opt_2) {1, .as1 = _19};
				_17->next = _20;
				struct task_queue* _21 = a;
				struct task_queue_node* _22 = inserted;
				struct some_2 _23 = (struct some_2) {_22};
				struct opt_2 _24 = (struct opt_2) {1, .as1 = _23};
				_21->head = _24;
			}
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	uint64_t size_after3;
	struct task_queue* _25 = a;
	size_after3 = size_0(_25);
	
	uint64_t _26 = size_before0;
	uint64_t _27 = 1u;
	uint64_t _28 = _26 + _27;
	uint64_t _29 = size_after3;
	uint8_t _30 = _op_equal_equal_0(_28, _29);
	return hard_assert(_30);
}
/* size nat(a task-queue) */
uint64_t size_0(struct task_queue* a) {
	struct task_queue* _0 = a;
	struct opt_2 _1 = _0->head;
	uint64_t _2 = 0u;
	return size_recur(_1, _2);
}
/* size-recur nat(node opt<task-queue-node>, acc nat) */
uint64_t size_recur(struct opt_2 node, uint64_t acc) {
	top:;
	struct opt_2 _0 = node;
	switch (_0.kind) {
		case 0: {
			return acc;
		}
		case 1: {
			struct some_2 s0 = _0.as1;
			
			struct some_2 _1 = s0;
			struct task_queue_node* _2 = _1.value;
			struct opt_2 _3 = _2->next;
			uint64_t _4 = acc;
			uint64_t _5 = 1u;
			uint64_t _6 = _4 + _5;
			node = _3;
			acc = _6;
			goto top;
		}
		default:
			return (assert(0),0);
	}
}
/* insert-recur void(prev task-queue-node, inserted task-queue-node) */
struct void_ insert_recur(struct task_queue_node* prev, struct task_queue_node* inserted) {
	top:;
	struct task_queue_node* _0 = prev;
	struct opt_2 _1 = _0->next;
	switch (_1.kind) {
		case 0: {
			struct task_queue_node* _2 = prev;
			struct task_queue_node* _3 = inserted;
			struct some_2 _4 = (struct some_2) {_3};
			struct opt_2 _5 = (struct opt_2) {1, .as1 = _4};
			return (_2->next = _5, (struct void_) {});
		}
		case 1: {
			struct some_2 s0 = _1.as1;
			
			struct task_queue_node* cur1;
			struct some_2 _6 = s0;
			cur1 = _6.value;
			
			struct task_queue_node* _7 = cur1;
			struct task _8 = _7->task;
			uint64_t _9 = _8.time;
			struct task_queue_node* _10 = inserted;
			struct task _11 = _10->task;
			uint64_t _12 = _11.time;
			uint8_t _13 = _op_less_equal(_9, _12);
			if (_13) {
				struct task_queue_node* _14 = cur1;
				struct task_queue_node* _15 = inserted;
				prev = _14;
				inserted = _15;
				goto top;
			} else {
				struct task_queue_node* _16 = inserted;
				struct task_queue_node* _17 = cur1;
				struct some_2 _18 = (struct some_2) {_17};
				struct opt_2 _19 = (struct opt_2) {1, .as1 = _18};
				_16->next = _19;
				struct task_queue_node* _20 = prev;
				struct task_queue_node* _21 = inserted;
				struct some_2 _22 = (struct some_2) {_21};
				struct opt_2 _23 = (struct opt_2) {1, .as1 = _22};
				return (_20->next = _23, (struct void_) {});
			}
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* tasks task-queue(a island) */
struct task_queue* tasks(struct island* a) {
	return &(&a->gc_root)->tasks;
}
/* broadcast void(c condition) */
struct void_ broadcast(struct condition* c) {
	struct lock* _0 = &c->lk;
	acquire_lock(_0);
	struct condition* _1 = c;
	struct condition* _2 = c;
	uint64_t _3 = _2->value;
	uint64_t _4 = noctx_incr(_3);
	_1->value = _4;
	struct lock* _5 = &c->lk;
	return release_lock(_5);
}
/* no-timestamp nat() */
uint64_t no_timestamp(void) {
	return 0u;
}
/* catch<void> void(try fun-act0<void>, catcher fun-act1<void, exception>) */
struct void_ catch(struct ctx* ctx, struct fun_act0_0 try, struct fun_act1_3 catcher) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct exception_ctx* _2 = get_exception_ctx(_1);
	struct fun_act0_0 _3 = try;
	struct fun_act1_3 _4 = catcher;
	return catch_with_exception_ctx(_0, _2, _3, _4);
}
/* catch-with-exception-ctx<?t> void(ec exception-ctx, try fun-act0<void>, catcher fun-act1<void, exception>) */
struct void_ catch_with_exception_ctx(struct ctx* ctx, struct exception_ctx* ec, struct fun_act0_0 try, struct fun_act1_3 catcher) {
	struct exception old_thrown_exception0;
	struct exception_ctx* _0 = ec;
	old_thrown_exception0 = _0->thrown_exception;
	
	struct jmp_buf_tag* old_jmp_buf1;
	struct exception_ctx* _1 = ec;
	old_jmp_buf1 = _1->jmp_buf_ptr;
	
	struct jmp_buf_tag store2;
	struct bytes64 _2 = zero_0();
	int32_t _3 = 0;
	struct bytes128 _4 = zero_3();
	store2 = (struct jmp_buf_tag) {_2, _3, _4};
	
	struct exception_ctx* _5 = ec;
	struct jmp_buf_tag* _6 = &store2;
	_5->jmp_buf_ptr = _6;
	int32_t setjmp_result3;
	struct exception_ctx* _7 = ec;
	struct jmp_buf_tag* _8 = _7->jmp_buf_ptr;
	setjmp_result3 = setjmp(_8);
	
	int32_t _9 = setjmp_result3;
	int32_t _10 = 0;
	uint8_t _11 = _op_equal_equal_2(_9, _10);
	if (_11) {
		struct void_ res4;
		struct ctx* _12 = ctx;
		struct fun_act0_0 _13 = try;
		res4 = call_2(_12, _13);
		
		struct exception_ctx* _14 = ec;
		struct jmp_buf_tag* _15 = old_jmp_buf1;
		_14->jmp_buf_ptr = _15;
		struct exception_ctx* _16 = ec;
		struct exception _17 = old_thrown_exception0;
		_16->thrown_exception = _17;
		return res4;
	} else {
		struct ctx* _18 = ctx;
		int32_t _19 = setjmp_result3;
		struct ctx* _20 = ctx;
		int32_t _21 = number_to_throw(_20);
		uint8_t _22 = _op_equal_equal_2(_19, _21);
		assert_0(_18, _22);
		struct exception thrown_exception5;
		struct exception_ctx* _23 = ec;
		thrown_exception5 = _23->thrown_exception;
		
		struct exception_ctx* _24 = ec;
		struct jmp_buf_tag* _25 = old_jmp_buf1;
		_24->jmp_buf_ptr = _25;
		struct exception_ctx* _26 = ec;
		struct exception _27 = old_thrown_exception0;
		_26->thrown_exception = _27;
		struct ctx* _28 = ctx;
		struct fun_act1_3 _29 = catcher;
		struct exception _30 = thrown_exception5;
		return call_3(_28, _29, _30);
	}
}
/* zero bytes64() */
struct bytes64 zero_0(void) {
	struct bytes32 _0 = zero_1();
	struct bytes32 _1 = zero_1();
	return (struct bytes64) {_0, _1};
}
/* zero bytes32() */
struct bytes32 zero_1(void) {
	struct bytes16 _0 = zero_2();
	struct bytes16 _1 = zero_2();
	return (struct bytes32) {_0, _1};
}
/* zero bytes16() */
struct bytes16 zero_2(void) {
	uint64_t _0 = 0u;
	uint64_t _1 = 0u;
	return (struct bytes16) {_0, _1};
}
/* zero bytes128() */
struct bytes128 zero_3(void) {
	struct bytes64 _0 = zero_0();
	struct bytes64 _1 = zero_0();
	return (struct bytes128) {_0, _1};
}
/* call<?t> void(a fun-act0<void>) */
struct void_ call_2(struct ctx* ctx, struct fun_act0_0 a) {
	struct fun_act0_0 _0 = a;
	struct ctx* _1 = ctx;
	return call_w_ctx_143(_0, _1);
}
/* call-w-ctx<void> (generated) (generated) */
struct void_ call_w_ctx_143(struct fun_act0_0 a, struct ctx* ctx) {
	struct fun_act0_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct call_ref_0__lambda0__lambda0* _2 = closure0;
			return call_ref_0__lambda0__lambda0(_1, _2);
		}
		case 1: {
			struct call_ref_0__lambda0* closure1 = _0.as1;
			
			struct ctx* _3 = ctx;
			struct call_ref_0__lambda0* _4 = closure1;
			return call_ref_0__lambda0(_3, _4);
		}
		case 2: {
			struct call_ref_1__lambda0__lambda0* closure2 = _0.as2;
			
			struct ctx* _5 = ctx;
			struct call_ref_1__lambda0__lambda0* _6 = closure2;
			return call_ref_1__lambda0__lambda0(_5, _6);
		}
		case 3: {
			struct call_ref_1__lambda0* closure3 = _0.as3;
			
			struct ctx* _7 = ctx;
			struct call_ref_1__lambda0* _8 = closure3;
			return call_ref_1__lambda0(_7, _8);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call<?t, exception> void(a fun-act1<void, exception>, p0 exception) */
struct void_ call_3(struct ctx* ctx, struct fun_act1_3 a, struct exception p0) {
	struct fun_act1_3 _0 = a;
	struct ctx* _1 = ctx;
	struct exception _2 = p0;
	return call_w_ctx_145(_0, _1, _2);
}
/* call-w-ctx<void, exception> (generated) (generated) */
struct void_ call_w_ctx_145(struct fun_act1_3 a, struct ctx* ctx, struct exception p0) {
	struct fun_act1_3 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda1* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct call_ref_0__lambda0__lambda1* _2 = closure0;
			struct exception _3 = p0;
			return call_ref_0__lambda0__lambda1(_1, _2, _3);
		}
		case 1: {
			struct call_ref_1__lambda0__lambda1* closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct call_ref_1__lambda0__lambda1* _5 = closure1;
			struct exception _6 = p0;
			return call_ref_1__lambda0__lambda1(_4, _5, _6);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call<fut<?r>, ?p0> fut<int32>(a fun-act1<fut<int32>, void>, p0 void) */
struct fut_0* call_4(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0) {
	struct fun_act1_2 _0 = a;
	struct ctx* _1 = ctx;
	struct void_ _2 = p0;
	return call_w_ctx_147(_0, _1, _2);
}
/* call-w-ctx<gc-ptr(fut<int32>), void> (generated) (generated) */
struct fut_0* call_w_ctx_147(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0) {
	struct fun_act1_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct then2__lambda0* _2 = closure0;
			struct void_ _3 = p0;
			return then2__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),NULL);
	}
}
/* call-ref<?out, ?in>.lambda0.lambda0 void() */
struct void_ call_ref_0__lambda0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct call_ref_0__lambda0__lambda0* _2 = _closure;
	struct fun_ref1 _3 = _2->f;
	struct fun_act1_2 _4 = _3.fun;
	struct call_ref_0__lambda0__lambda0* _5 = _closure;
	struct void_ _6 = _5->p0;
	struct fut_0* _7 = call_4(_1, _4, _6);
	struct call_ref_0__lambda0__lambda0* _8 = _closure;
	struct fut_0* _9 = _8->res;
	return forward_to(_0, _7, _9);
}
/* reject<?r> void(f fut<int32>, e exception) */
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e) {
	struct ctx* _0 = ctx;
	struct fut_0* _1 = f;
	struct exception _2 = e;
	struct err_0 _3 = (struct err_0) {_2};
	struct result_0 _4 = (struct result_0) {1, .as1 = _3};
	return resolve_or_reject(_0, _1, _4);
}
/* call-ref<?out, ?in>.lambda0.lambda1 void(it exception) */
struct void_ call_ref_0__lambda0__lambda1(struct ctx* ctx, struct call_ref_0__lambda0__lambda1* _closure, struct exception it) {
	struct ctx* _0 = ctx;
	struct call_ref_0__lambda0__lambda1* _1 = _closure;
	struct fut_0* _2 = _1->res;
	struct exception _3 = it;
	return reject(_0, _2, _3);
}
/* call-ref<?out, ?in>.lambda0 void() */
struct void_ call_ref_0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct call_ref_0__lambda0__lambda0* temp0;
	struct ctx* _1 = ctx;
	uint64_t _2 = sizeof(struct call_ref_0__lambda0__lambda0);
	uint8_t* _3 = alloc(_1, _2);
	temp0 = (struct call_ref_0__lambda0__lambda0*) _3;
	
	struct call_ref_0__lambda0__lambda0* _4 = temp0;
	struct call_ref_0__lambda0* _5 = _closure;
	struct fun_ref1 _6 = _5->f;
	struct call_ref_0__lambda0* _7 = _closure;
	struct void_ _8 = _7->p0;
	struct call_ref_0__lambda0* _9 = _closure;
	struct fut_0* _10 = _9->res;
	struct call_ref_0__lambda0__lambda0 _11 = (struct call_ref_0__lambda0__lambda0) {_6, _8, _10};
	*_4 = _11;
	struct call_ref_0__lambda0__lambda0* _12 = temp0;
	struct fun_act0_0 _13 = (struct fun_act0_0) {0, .as0 = _12};
	struct call_ref_0__lambda0__lambda1* temp1;
	struct ctx* _14 = ctx;
	uint64_t _15 = sizeof(struct call_ref_0__lambda0__lambda1);
	uint8_t* _16 = alloc(_14, _15);
	temp1 = (struct call_ref_0__lambda0__lambda1*) _16;
	
	struct call_ref_0__lambda0__lambda1* _17 = temp1;
	struct call_ref_0__lambda0* _18 = _closure;
	struct fut_0* _19 = _18->res;
	struct call_ref_0__lambda0__lambda1 _20 = (struct call_ref_0__lambda0__lambda1) {_19};
	*_17 = _20;
	struct call_ref_0__lambda0__lambda1* _21 = temp1;
	struct fun_act1_3 _22 = (struct fun_act1_3) {0, .as0 = _21};
	return catch(_0, _13, _22);
}
/* then<?out, void>.lambda0 void(result result<void, exception>) */
struct void_ then_0__lambda0(struct ctx* ctx, struct then_0__lambda0* _closure, struct result_1 result) {
	struct result_1 _0 = result;
	switch (_0.kind) {
		case 0: {
			struct ok_1 o0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct ctx* _2 = ctx;
			struct then_0__lambda0* _3 = _closure;
			struct fun_ref1 _4 = _3->cb;
			struct ok_1 _5 = o0;
			struct void_ _6 = _5.value;
			struct fut_0* _7 = call_ref_0(_2, _4, _6);
			struct then_0__lambda0* _8 = _closure;
			struct fut_0* _9 = _8->res;
			return forward_to(_1, _7, _9);
		}
		case 1: {
			struct err_0 e1 = _0.as1;
			
			struct ctx* _10 = ctx;
			struct then_0__lambda0* _11 = _closure;
			struct fut_0* _12 = _11->res;
			struct err_0 _13 = e1;
			struct exception _14 = _13.value;
			return reject(_10, _12, _14);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call-ref<?out> fut<int32>(f fun-ref0<int32>) */
struct fut_0* call_ref_1(struct ctx* ctx, struct fun_ref0 f) {
	struct fut_0* res0;
	struct ctx* _0 = ctx;
	res0 = new_unresolved_fut(_0);
	
	struct ctx* _1 = ctx;
	struct ctx* _2 = ctx;
	struct fun_ref0 _3 = f;
	struct island_and_exclusion _4 = _3.island_and_exclusion;
	uint64_t _5 = _4.island;
	struct island* _6 = get_island(_2, _5);
	struct fun_ref0 _7 = f;
	struct island_and_exclusion _8 = _7.island_and_exclusion;
	uint64_t _9 = _8.exclusion;
	struct call_ref_1__lambda0* temp0;
	struct ctx* _10 = ctx;
	uint64_t _11 = sizeof(struct call_ref_1__lambda0);
	uint8_t* _12 = alloc(_10, _11);
	temp0 = (struct call_ref_1__lambda0*) _12;
	
	struct call_ref_1__lambda0* _13 = temp0;
	struct fun_ref0 _14 = f;
	struct fut_0* _15 = res0;
	struct call_ref_1__lambda0 _16 = (struct call_ref_1__lambda0) {_14, _15};
	*_13 = _16;
	struct call_ref_1__lambda0* _17 = temp0;
	struct fun_act0_0 _18 = (struct fun_act0_0) {3, .as3 = _17};
	add_task_0(_1, _6, _9, _18);
	return res0;
}
/* call<fut<?r>> fut<int32>(a fun-act0<fut<int32>>) */
struct fut_0* call_5(struct ctx* ctx, struct fun_act0_1 a) {
	struct fun_act0_1 _0 = a;
	struct ctx* _1 = ctx;
	return call_w_ctx_155(_0, _1);
}
/* call-w-ctx<gc-ptr(fut<int32>)> (generated) (generated) */
struct fut_0* call_w_ctx_155(struct fun_act0_1 a, struct ctx* ctx) {
	struct fun_act0_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct add_first_task__lambda0* _2 = closure0;
			return add_first_task__lambda0(_1, _2);
		}
		default:
			return (assert(0),NULL);
	}
}
/* call-ref<?out>.lambda0.lambda0 void() */
struct void_ call_ref_1__lambda0__lambda0(struct ctx* ctx, struct call_ref_1__lambda0__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct call_ref_1__lambda0__lambda0* _2 = _closure;
	struct fun_ref0 _3 = _2->f;
	struct fun_act0_1 _4 = _3.fun;
	struct fut_0* _5 = call_5(_1, _4);
	struct call_ref_1__lambda0__lambda0* _6 = _closure;
	struct fut_0* _7 = _6->res;
	return forward_to(_0, _5, _7);
}
/* call-ref<?out>.lambda0.lambda1 void(it exception) */
struct void_ call_ref_1__lambda0__lambda1(struct ctx* ctx, struct call_ref_1__lambda0__lambda1* _closure, struct exception it) {
	struct ctx* _0 = ctx;
	struct call_ref_1__lambda0__lambda1* _1 = _closure;
	struct fut_0* _2 = _1->res;
	struct exception _3 = it;
	return reject(_0, _2, _3);
}
/* call-ref<?out>.lambda0 void() */
struct void_ call_ref_1__lambda0(struct ctx* ctx, struct call_ref_1__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct call_ref_1__lambda0__lambda0* temp0;
	struct ctx* _1 = ctx;
	uint64_t _2 = sizeof(struct call_ref_1__lambda0__lambda0);
	uint8_t* _3 = alloc(_1, _2);
	temp0 = (struct call_ref_1__lambda0__lambda0*) _3;
	
	struct call_ref_1__lambda0__lambda0* _4 = temp0;
	struct call_ref_1__lambda0* _5 = _closure;
	struct fun_ref0 _6 = _5->f;
	struct call_ref_1__lambda0* _7 = _closure;
	struct fut_0* _8 = _7->res;
	struct call_ref_1__lambda0__lambda0 _9 = (struct call_ref_1__lambda0__lambda0) {_6, _8};
	*_4 = _9;
	struct call_ref_1__lambda0__lambda0* _10 = temp0;
	struct fun_act0_0 _11 = (struct fun_act0_0) {2, .as2 = _10};
	struct call_ref_1__lambda0__lambda1* temp1;
	struct ctx* _12 = ctx;
	uint64_t _13 = sizeof(struct call_ref_1__lambda0__lambda1);
	uint8_t* _14 = alloc(_12, _13);
	temp1 = (struct call_ref_1__lambda0__lambda1*) _14;
	
	struct call_ref_1__lambda0__lambda1* _15 = temp1;
	struct call_ref_1__lambda0* _16 = _closure;
	struct fut_0* _17 = _16->res;
	struct call_ref_1__lambda0__lambda1 _18 = (struct call_ref_1__lambda0__lambda1) {_17};
	*_15 = _18;
	struct call_ref_1__lambda0__lambda1* _19 = temp1;
	struct fun_act1_3 _20 = (struct fun_act1_3) {1, .as1 = _19};
	return catch(_0, _11, _20);
}
/* then2<int32>.lambda0 fut<int32>(ignore void) */
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore) {
	struct ctx* _0 = ctx;
	struct then2__lambda0* _1 = _closure;
	struct fun_ref0 _2 = _1->cb;
	return call_ref_1(_0, _2);
}
/* cur-island-and-exclusion island-and-exclusion() */
struct island_and_exclusion cur_island_and_exclusion(struct ctx* ctx) {
	struct ctx* c0;
	c0 = ctx;
	
	struct ctx* _0 = c0;
	uint64_t _1 = _0->island_id;
	struct ctx* _2 = c0;
	uint64_t _3 = _2->exclusion;
	return (struct island_and_exclusion) {_1, _3};
}
/* delay fut<void>() */
struct fut_1* delay(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	struct void_ _1 = (struct void_) {};
	return resolved_0(_0, _1);
}
/* resolved<void> fut<void>(value void) */
struct fut_1* resolved_0(struct ctx* ctx, struct void_ value) {
	struct fut_1* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct fut_1);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct fut_1*) _2;
	
	struct fut_1* _3 = temp0;
	struct lock _4 = new_lock();
	struct void_ _5 = value;
	struct fut_state_resolved_1 _6 = (struct fut_state_resolved_1) {_5};
	struct fut_state_1 _7 = (struct fut_state_1) {1, .as1 = _6};
	struct fut_1 _8 = (struct fut_1) {_4, _7};
	*_3 = _8;
	return temp0;
}
/* tail<ptr<char>> arr<ptr<char>>(a arr<ptr<char>>) */
struct arr_4 tail_0(struct ctx* ctx, struct arr_4 a) {
	struct ctx* _0 = ctx;
	struct arr_4 _1 = a;
	uint8_t _2 = empty__q_1(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_4 _4 = a;
	uint64_t _5 = 1u;
	return slice_starting_at_0(_3, _4, _5);
}
/* empty?<?t> bool(a arr<ptr<char>>) */
uint8_t empty__q_1(struct arr_4 a) {
	struct arr_4 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* slice-starting-at<?t> arr<ptr<char>>(a arr<ptr<char>>, begin nat) */
struct arr_4 slice_starting_at_0(struct ctx* ctx, struct arr_4 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct arr_4 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_4 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct arr_4 _9 = a;
	uint64_t _10 = _9.size;
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_0(_5, _6, _7, _12);
}
/* slice<?t> arr<ptr<char>>(a arr<ptr<char>>, begin nat, size nat) */
struct arr_4 slice_0(struct ctx* ctx, struct arr_4 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct arr_4 _5 = a;
	uint64_t _6 = _5.size;
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct arr_4 _9 = a;
	char** _10 = _9.data;
	uint64_t _11 = begin;
	char** _12 = _10 + _11;
	return (struct arr_4) {_8, _12};
}
/* map<arr<char>, ptr<char>> arr<arr<char>>(a arr<ptr<char>>, mapper fun-act1<arr<char>, ptr<char>>) */
struct arr_1 map_0(struct ctx* ctx, struct arr_4 a, struct fun_act1_4 mapper) {
	struct ctx* _0 = ctx;
	struct arr_4 _1 = a;
	uint64_t _2 = _1.size;
	struct map_0__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct map_0__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct map_0__lambda0*) _5;
	
	struct map_0__lambda0* _6 = temp0;
	struct fun_act1_4 _7 = mapper;
	struct arr_4 _8 = a;
	struct map_0__lambda0 _9 = (struct map_0__lambda0) {_7, _8};
	*_6 = _9;
	struct map_0__lambda0* _10 = temp0;
	struct fun_act1_5 _11 = (struct fun_act1_5) {0, .as0 = _10};
	return make_arr_0(_0, _2, _11);
}
/* make-arr<?out> arr<arr<char>>(size nat, f fun-act1<arr<char>, nat>) */
struct arr_1 make_arr_0(struct ctx* ctx, uint64_t size, struct fun_act1_5 f) {
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct fun_act1_5 _2 = f;
	struct mut_arr_1 _3 = make_mut_arr_0(_0, _1, _2);
	return cast_immutable_0(_3);
}
/* cast-immutable<?t> arr<arr<char>>(a mut-arr<arr<char>>) */
struct arr_1 cast_immutable_0(struct mut_arr_1 a) {
	struct mut_arr_1 _0 = a;
	return _0.arr;
}
/* make-mut-arr<?t> mut-arr<arr<char>>(size nat, f fun-act1<arr<char>, nat>) */
struct mut_arr_1 make_mut_arr_0(struct ctx* ctx, uint64_t size, struct fun_act1_5 f) {
	struct mut_arr_1 res0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	res0 = new_uninitialized_mut_arr_0(_0, _1);
	
	struct ctx* _2 = ctx;
	struct mut_arr_1 _3 = res0;
	uint64_t _4 = 0u;
	struct fun_act1_5 _5 = f;
	make_mut_arr_worker_0(_2, _3, _4, _5);
	return res0;
}
/* new-uninitialized-mut-arr<?t> mut-arr<arr<char>>(size nat) */
struct mut_arr_1 new_uninitialized_mut_arr_0(struct ctx* ctx, uint64_t size) {
	uint64_t _0 = size;
	struct ctx* _1 = ctx;
	uint64_t _2 = size;
	struct arr_0* _3 = uninitialized_data_1(_1, _2);
	return mut_arr_1(_0, _3);
}
/* mut-arr<?t> mut-arr<arr<char>>(size nat, data ptr<arr<char>>) */
struct mut_arr_1 mut_arr_1(uint64_t size, struct arr_0* data) {
	uint64_t _0 = size;
	struct arr_0* _1 = data;
	struct arr_1 _2 = (struct arr_1) {_0, _1};
	return (struct mut_arr_1) {_2};
}
/* uninitialized-data<?t> ptr<arr<char>>(size nat) */
struct arr_0* uninitialized_data_1(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(struct arr_0);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (struct arr_0*) _4;
}
/* make-mut-arr-worker<?t> void(a mut-arr<arr<char>>, i nat, f fun-act1<arr<char>, nat>) */
struct void_ make_mut_arr_worker_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t i, struct fun_act1_5 f) {
	top:;
	uint64_t _0 = i;
	struct mut_arr_1 _1 = a;
	uint64_t _2 = size_1(_1);
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_arr_1 _5 = a;
		uint64_t _6 = i;
		struct ctx* _7 = ctx;
		struct fun_act1_5 _8 = f;
		uint64_t _9 = i;
		struct arr_0 _10 = call_6(_7, _8, _9);
		set_at_0(_4, _5, _6, _10);
		struct mut_arr_1 _11 = a;
		struct ctx* _12 = ctx;
		uint64_t _13 = i;
		uint64_t _14 = incr_3(_12, _13);
		struct fun_act1_5 _15 = f;
		a = _11;
		i = _14;
		f = _15;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* size<?t> nat(a mut-arr<arr<char>>) */
uint64_t size_1(struct mut_arr_1 a) {
	struct mut_arr_1 _0 = a;
	struct arr_1 _1 = _0.arr;
	return _1.size;
}
/* set-at<?t> void(a mut-arr<arr<char>>, index nat, value arr<char>) */
struct void_ set_at_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t index, struct arr_0 value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_arr_1 _2 = a;
	uint64_t _3 = size_1(_2);
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_arr_1 _5 = a;
	uint64_t _6 = index;
	struct arr_0 _7 = value;
	return noctx_set_at_0(_5, _6, _7);
}
/* noctx-set-at<?t> void(a mut-arr<arr<char>>, index nat, value arr<char>) */
struct void_ noctx_set_at_0(struct mut_arr_1 a, uint64_t index, struct arr_0 value) {
	uint64_t _0 = index;
	struct mut_arr_1 _1 = a;
	uint64_t _2 = size_1(_1);
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_arr_1 _4 = a;
	struct arr_0* _5 = data_0(_4);
	uint64_t _6 = index;
	struct arr_0* _7 = _5 + _6;
	struct arr_0 _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* data<?t> ptr<arr<char>>(a mut-arr<arr<char>>) */
struct arr_0* data_0(struct mut_arr_1 a) {
	struct mut_arr_1 _0 = a;
	struct arr_1 _1 = _0.arr;
	return _1.data;
}
/* call<?t, nat> arr<char>(a fun-act1<arr<char>, nat>, p0 nat) */
struct arr_0 call_6(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0) {
	struct fun_act1_5 _0 = a;
	struct ctx* _1 = ctx;
	uint64_t _2 = p0;
	return call_w_ctx_180(_0, _1, _2);
}
/* call-w-ctx<arr<char>, nat-64> (generated) (generated) */
struct arr_0 call_w_ctx_180(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0) {
	struct fun_act1_5 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct map_0__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct map_0__lambda0* _2 = closure0;
			uint64_t _3 = p0;
			return map_0__lambda0(_1, _2, _3);
		}
		case 1: {
			struct copy_to_mut_arr__lambda0* closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct copy_to_mut_arr__lambda0* _5 = closure1;
			uint64_t _6 = p0;
			return copy_to_mut_arr__lambda0(_4, _5, _6);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* incr nat(n nat) */
uint64_t incr_3(struct ctx* ctx, uint64_t n) {
	struct ctx* _0 = ctx;
	uint64_t _1 = n;
	uint64_t _2 = max_nat();
	uint8_t _3 = _op_equal_equal_0(_1, _2);
	forbid_0(_0, _3);
	uint64_t _4 = n;
	uint64_t _5 = 1u;
	return _4 + _5;
}
/* call<?out, ?in> arr<char>(a fun-act1<arr<char>, ptr<char>>, p0 ptr<char>) */
struct arr_0 call_7(struct ctx* ctx, struct fun_act1_4 a, char* p0) {
	struct fun_act1_4 _0 = a;
	struct ctx* _1 = ctx;
	char* _2 = p0;
	return call_w_ctx_183(_0, _1, _2);
}
/* call-w-ctx<arr<char>, raw-ptr(char)> (generated) (generated) */
struct arr_0 call_w_ctx_183(struct fun_act1_4 a, struct ctx* ctx, char* p0) {
	struct fun_act1_4 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			char* _3 = p0;
			return add_first_task__lambda0__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* at<?in> ptr<char>(a arr<ptr<char>>, index nat) */
char* at_1(struct ctx* ctx, struct arr_4 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_4 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_4 _5 = a;
	uint64_t _6 = index;
	return noctx_at_1(_5, _6);
}
/* noctx-at<?t> ptr<char>(a arr<ptr<char>>, index nat) */
char* noctx_at_1(struct arr_4 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_4 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_4 _4 = a;
	char** _5 = _4.data;
	uint64_t _6 = index;
	char** _7 = _5 + _6;
	return *_7;
}
/* map<arr<char>, ptr<char>>.lambda0 arr<char>(i nat) */
struct arr_0 map_0__lambda0(struct ctx* ctx, struct map_0__lambda0* _closure, uint64_t i) {
	struct ctx* _0 = ctx;
	struct map_0__lambda0* _1 = _closure;
	struct fun_act1_4 _2 = _1->mapper;
	struct ctx* _3 = ctx;
	struct map_0__lambda0* _4 = _closure;
	struct arr_4 _5 = _4->a;
	uint64_t _6 = i;
	char* _7 = at_1(_3, _5, _6);
	return call_7(_0, _2, _7);
}
/* to-str arr<char>(a ptr<char>) */
struct arr_0 to_str_1(char* a) {
	char* _0 = a;
	char* _1 = a;
	char* _2 = find_cstr_end(_1);
	return arr_from_begin_end(_0, _2);
}
/* arr-from-begin-end<char> arr<char>(begin ptr<char>, end ptr<char>) */
struct arr_0 arr_from_begin_end(char* begin, char* end) {
	char* _0 = end;
	char* _1 = begin;
	uint64_t _2 = _op_minus_3(_0, _1);
	char* _3 = begin;
	return (struct arr_0) {_2, _3};
}
/* -<?t> nat(a ptr<char>, b ptr<char>) */
uint64_t _op_minus_3(char* a, char* b) {
	char* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	char* _2 = b;
	uint64_t _3 = (uint64_t) _2;
	uint64_t _4 = _1 - _3;
	uint64_t _5 = sizeof(char);
	return _4 / _5;
}
/* find-cstr-end ptr<char>(a ptr<char>) */
char* find_cstr_end(char* a) {
	char* _0 = a;
	char _1 = 0u;
	return find_char_in_cstr(_0, _1);
}
/* find-char-in-cstr ptr<char>(a ptr<char>, c char) */
char* find_char_in_cstr(char* a, char c) {
	top:;
	char* _0 = a;
	char _1 = *_0;
	char _2 = c;
	uint8_t _3 = _op_equal_equal_3(_1, _2);
	if (_3) {
		return a;
	} else {
		char* _4 = a;
		char _5 = *_4;
		char _6 = 0u;
		uint8_t _7 = _op_equal_equal_3(_5, _6);
		if (_7) {
			return todo_2();
		} else {
			char* _8 = a;
			char* _9 = incr_2(_8);
			char _10 = c;
			a = _9;
			c = _10;
			goto top;
		}
	}
}
/* ==<char> bool(a char, b char) */
uint8_t _op_equal_equal_3(char a, char b) {
	char _0 = a;
	char _1 = b;
	struct comparison _2 = compare_193(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<char> (generated) (generated) */
struct comparison compare_193(char a, char b) {
	char _0 = a;
	char _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		char _4 = b;
		char _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* todo<ptr<char>> ptr<char>() */
char* todo_2(void) {
	return (assert(0),NULL);
}
/* add-first-task.lambda0.lambda0 arr<char>(it ptr<char>) */
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it) {
	char* _0 = it;
	return to_str_1(_0);
}
/* add-first-task.lambda0 fut<int32>() */
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure) {
	struct arr_4 args0;
	struct ctx* _0 = ctx;
	struct add_first_task__lambda0* _1 = _closure;
	struct arr_4 _2 = _1->all_args;
	args0 = tail_0(_0, _2);
	
	struct add_first_task__lambda0* _3 = _closure;
	fun_ptr2 _4 = _3->main_ptr;
	struct ctx* _5 = ctx;
	struct ctx* _6 = ctx;
	struct arr_4 _7 = args0;
	struct void_ _8 = (struct void_) {};
	struct fun_act1_4 _9 = (struct fun_act1_4) {0, .as0 = _8};
	struct arr_1 _10 = map_0(_6, _7, _9);
	return _4(_5, _10);
}
/* do-main.lambda0 fut<int32>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr) {
	struct ctx* _0 = ctx;
	struct arr_4 _1 = all_args;
	fun_ptr2 _2 = main_ptr;
	return add_first_task(_0, _1, _2);
}
/* call-w-ctx<gc-ptr(fut<int32>), arr<ptr<char>>, some fun ptr type> (generated) (generated) */
struct fut_0* call_w_ctx_198(struct fun2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1) {
	struct fun2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			struct arr_4 _3 = p0;
			fun_ptr2 _4 = p1;
			return do_main__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),NULL);
	}
}
/* run-threads void(n-threads nat, gctx global-ctx) */
struct void_ run_threads(uint64_t n_threads, struct global_ctx* gctx) {
	uint64_t* threads0;
	uint64_t _0 = n_threads;
	threads0 = unmanaged_alloc_elements_0(_0);
	
	struct thread_args* thread_args1;
	uint64_t _1 = n_threads;
	thread_args1 = unmanaged_alloc_elements_1(_1);
	
	uint64_t actual_n_threads2;
	uint64_t _2 = n_threads;
	actual_n_threads2 = noctx_decr(_2);
	
	uint64_t _3 = 0u;
	uint64_t _4 = actual_n_threads2;
	uint64_t* _5 = threads0;
	struct thread_args* _6 = thread_args1;
	struct global_ctx* _7 = gctx;
	start_threads_recur(_3, _4, _5, _6, _7);
	uint64_t _8 = actual_n_threads2;
	struct global_ctx* _9 = gctx;
	thread_function(_8, _9);
	uint64_t _10 = 0u;
	uint64_t _11 = actual_n_threads2;
	uint64_t* _12 = threads0;
	join_threads_recur(_10, _11, _12);
	uint64_t* _13 = threads0;
	unmanaged_free_0(_13);
	struct thread_args* _14 = thread_args1;
	return unmanaged_free_1(_14);
}
/* unmanaged-alloc-elements<by-val<thread-args>> ptr<thread-args>(size-elements nat) */
struct thread_args* unmanaged_alloc_elements_1(uint64_t size_elements) {
	uint8_t* bytes0;
	uint64_t _0 = size_elements;
	uint64_t _1 = sizeof(struct thread_args);
	uint64_t _2 = _0 * _1;
	bytes0 = unmanaged_alloc_bytes(_2);
	
	uint8_t* _3 = bytes0;
	return (struct thread_args*) _3;
}
/* noctx-decr nat(n nat) */
uint64_t noctx_decr(uint64_t n) {
	uint64_t _0 = n;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_equal_equal_0(_0, _1);
	hard_forbid(_2);
	uint64_t _3 = n;
	uint64_t _4 = 1u;
	return _3 - _4;
}
/* start-threads-recur void(i nat, n-threads nat, threads ptr<nat>, thread-args-begin ptr<thread-args>, gctx global-ctx) */
struct void_ start_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads, struct thread_args* thread_args_begin, struct global_ctx* gctx) {
	top:;
	uint64_t _0 = i;
	uint64_t _1 = n_threads;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		struct thread_args* thread_arg_ptr0;
		struct thread_args* _3 = thread_args_begin;
		uint64_t _4 = i;
		thread_arg_ptr0 = _3 + _4;
		
		struct thread_args* _5 = thread_arg_ptr0;
		uint64_t _6 = i;
		struct global_ctx* _7 = gctx;
		struct thread_args _8 = (struct thread_args) {_6, _7};
		*_5 = _8;
		uint64_t* thread_ptr1;
		uint64_t* _9 = threads;
		uint64_t _10 = i;
		thread_ptr1 = _9 + _10;
		
		uint64_t* _11 = thread_ptr1;
		struct cell_0* _12 = as_cell(_11);
		struct thread_args* _13 = thread_arg_ptr0;
		uint8_t* _14 = (uint8_t*) _13;
		fun_ptr1 _15 = thread_fun;
		create_one_thread(_12, _14, _15);
		uint64_t _16 = i;
		uint64_t _17 = noctx_incr(_16);
		uint64_t _18 = n_threads;
		uint64_t* _19 = threads;
		struct thread_args* _20 = thread_args_begin;
		struct global_ctx* _21 = gctx;
		i = _17;
		n_threads = _18;
		threads = _19;
		thread_args_begin = _20;
		gctx = _21;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* create-one-thread void(tid cell<nat>, thread-arg ptr<nat8>, thread-fun fun-ptr1<ptr<nat8>, ptr<nat8>>) */
struct void_ create_one_thread(struct cell_0* tid, uint8_t* thread_arg, fun_ptr1 thread_fun) {
	int32_t err0;
	struct cell_0* _0 = tid;
	uint8_t* _1 = NULL;
	fun_ptr1 _2 = thread_fun;
	uint8_t* _3 = thread_arg;
	err0 = pthread_create(_0, _1, _2, _3);
	
	int32_t _4 = err0;
	int32_t _5 = 0;
	uint8_t _6 = _op_bang_equal_2(_4, _5);
	if (_6) {
		int32_t _7 = err0;
		int32_t _8 = eagain();
		uint8_t _9 = _op_equal_equal_2(_7, _8);
		if (_9) {
			return todo_0();
		} else {
			return todo_0();
		}
	} else {
		return (struct void_) {};
	}
}
/* !=<int32> bool(a int32, b int32) */
uint8_t _op_bang_equal_2(int32_t a, int32_t b) {
	int32_t _0 = a;
	int32_t _1 = b;
	uint8_t _2 = _op_equal_equal_2(_0, _1);
	return !_2;
}
/* eagain int32() */
int32_t eagain(void) {
	return 11;
}
/* as-cell<nat> cell<nat>(p ptr<nat>) */
struct cell_0* as_cell(uint64_t* p) {
	uint64_t* _0 = p;
	uint8_t* _1 = (uint8_t*) _0;
	return (struct cell_0*) _1;
}
/* thread-fun ptr<nat8>(args-ptr ptr<nat8>) */
uint8_t* thread_fun(uint8_t* args_ptr) {
	struct thread_args* args0;
	uint8_t* _0 = args_ptr;
	args0 = (struct thread_args*) _0;
	
	struct thread_args* _1 = args0;
	uint64_t _2 = _1->thread_id;
	struct thread_args* _3 = args0;
	struct global_ctx* _4 = _3->gctx;
	thread_function(_2, _4);
	return NULL;
}
/* thread-function void(thread-id nat, gctx global-ctx) */
struct void_ thread_function(uint64_t thread_id, struct global_ctx* gctx) {
	struct exception_ctx ectx0;
	ectx0 = new_exception_ctx();
	
	struct log_ctx log_ctx1;
	log_ctx1 = new_log_ctx();
	
	struct thread_local_stuff tls2;
	struct exception_ctx* _0 = &ectx0;
	struct log_ctx* _1 = &log_ctx1;
	tls2 = (struct thread_local_stuff) {_0, _1};
	
	uint64_t _2 = thread_id;
	struct global_ctx* _3 = gctx;
	struct thread_local_stuff* _4 = &tls2;
	return thread_function_recur(_2, _3, _4);
}
/* thread-function-recur void(thread-id nat, gctx global-ctx, tls thread-local-stuff) */
struct void_ thread_function_recur(uint64_t thread_id, struct global_ctx* gctx, struct thread_local_stuff* tls) {
	top:;
	struct global_ctx* _0 = gctx;
	uint8_t _1 = _0->shut_down__q;
	if (_1) {
		struct lock* _2 = &gctx->lk;
		acquire_lock(_2);
		struct global_ctx* _3 = gctx;
		struct global_ctx* _4 = gctx;
		uint64_t _5 = _4->n_live_threads;
		uint64_t _6 = noctx_decr(_5);
		_3->n_live_threads = _6;
		uint64_t _7 = 0u;
		struct global_ctx* _8 = gctx;
		struct arr_3 _9 = _8->islands;
		assert_islands_are_shut_down(_7, _9);
		struct lock* _10 = &gctx->lk;
		return release_lock(_10);
	} else {
		struct global_ctx* _11 = gctx;
		uint64_t _12 = _11->n_live_threads;
		uint64_t _13 = 0u;
		uint8_t _14 = _op_greater(_12, _13);
		hard_assert(_14);
		uint64_t last_checked0;
		struct condition* _15 = &gctx->may_be_work_to_do;
		last_checked0 = get_last_checked(_15);
		
		struct global_ctx* _16 = gctx;
		struct choose_task_result _17 = choose_task(_16);
		switch (_17.kind) {
			case 0: {
				struct chosen_task t1 = _17.as0;
				
				struct global_ctx* _18 = gctx;
				struct thread_local_stuff* _19 = tls;
				struct chosen_task _20 = t1;
				do_task(_18, _19, _20);
				break;
			}
			case 1: {
				struct no_chosen_task n2 = _17.as1;
				
				struct no_chosen_task _21 = n2;
				uint8_t _22 = _21.no_tasks_and_last_thread_out__q;
				if (_22) {
					struct global_ctx* _23 = gctx;
					uint8_t _24 = _23->shut_down__q;
					hard_forbid(_24);
					struct global_ctx* _25 = gctx;
					uint8_t _26 = 1;
					_25->shut_down__q = _26;
					struct condition* _27 = &gctx->may_be_work_to_do;
					broadcast(_27);
				} else {
					struct condition* _28 = &gctx->may_be_work_to_do;
					struct no_chosen_task _29 = n2;
					struct opt_5 _30 = _29.first_task_time;
					uint64_t _31 = last_checked0;
					wait_on(_28, _30, _31);
				}
				struct lock* _32 = &gctx->lk;
				acquire_lock(_32);
				struct global_ctx* _33 = gctx;
				struct global_ctx* _34 = gctx;
				uint64_t _35 = _34->n_live_threads;
				uint64_t _36 = noctx_incr(_35);
				_33->n_live_threads = _36;
				struct lock* _37 = &gctx->lk;
				release_lock(_37);
				break;
			}
			default:
				(assert(0),(struct void_) {});
		}
		uint64_t _38 = thread_id;
		struct global_ctx* _39 = gctx;
		struct thread_local_stuff* _40 = tls;
		thread_id = _38;
		gctx = _39;
		tls = _40;
		goto top;
	}
}
/* assert-islands-are-shut-down void(i nat, islands arr<island>) */
struct void_ assert_islands_are_shut_down(uint64_t i, struct arr_3 islands) {
	top:;
	uint64_t _0 = i;
	struct arr_3 _1 = islands;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct island* island0;
		struct arr_3 _4 = islands;
		uint64_t _5 = i;
		island0 = noctx_at_0(_4, _5);
		
		struct lock* _6 = &island0->tasks_lock;
		acquire_lock(_6);
		struct gc* _7 = &island0->gc;
		uint8_t _8 = _7->needs_gc__q;
		hard_forbid(_8);
		struct island* _9 = island0;
		uint64_t _10 = _9->n_threads_running;
		uint64_t _11 = 0u;
		uint8_t _12 = _op_equal_equal_0(_10, _11);
		hard_assert(_12);
		struct island* _13 = island0;
		struct task_queue* _14 = tasks(_13);
		uint8_t _15 = empty__q_2(_14);
		hard_assert(_15);
		struct lock* _16 = &island0->tasks_lock;
		release_lock(_16);
		uint64_t _17 = i;
		uint64_t _18 = noctx_incr(_17);
		struct arr_3 _19 = islands;
		i = _18;
		islands = _19;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* empty? bool(a task-queue) */
uint8_t empty__q_2(struct task_queue* a) {
	struct task_queue* _0 = a;
	struct opt_2 _1 = _0->head;
	uint8_t _2 = has__q_0(_1);
	return !_2;
}
/* has?<task-queue-node> bool(a opt<task-queue-node>) */
uint8_t has__q_0(struct opt_2 a) {
	struct opt_2 _0 = a;
	uint8_t _1 = empty__q_3(_0);
	return !_1;
}
/* empty?<?t> bool(a opt<task-queue-node>) */
uint8_t empty__q_3(struct opt_2 a) {
	struct opt_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* get-last-checked nat(c condition) */
uint64_t get_last_checked(struct condition* c) {
	struct condition* _0 = c;
	return _0->value;
}
/* choose-task choose-task-result(gctx global-ctx) */
struct choose_task_result choose_task(struct global_ctx* gctx) {
	struct lock* _0 = &gctx->lk;
	acquire_lock(_0);
	uint64_t cur_time0;
	cur_time0 = get_monotime_nsec();
	
	struct choose_task_result res4;
	struct global_ctx* _1 = gctx;
	struct arr_3 _2 = _1->islands;
	uint64_t _3 = 0u;
	uint64_t _4 = cur_time0;
	uint8_t _5 = 0;
	struct none _6 = (struct none) {};
	struct opt_5 _7 = (struct opt_5) {0, .as0 = _6};
	struct choose_task_result _8 = choose_task_recur(_2, _3, _4, _5, _7);
	switch (_8.kind) {
		case 0: {
			struct chosen_task c1 = _8.as0;
			
			struct chosen_task _9 = c1;
			res4 = (struct choose_task_result) {0, .as0 = _9};
			break;
		}
		case 1: {
			struct no_chosen_task n2 = _8.as1;
			
			struct global_ctx* _10 = gctx;
			struct global_ctx* _11 = gctx;
			uint64_t _12 = _11->n_live_threads;
			uint64_t _13 = noctx_decr(_12);
			_10->n_live_threads = _13;
			uint8_t no_task_and_last_thread_out__q3;
			struct no_chosen_task _14 = n2;
			uint8_t _15 = _14.no_tasks_and_last_thread_out__q;
			if (_15) {
				struct global_ctx* _16 = gctx;
				uint64_t _17 = _16->n_live_threads;
				uint64_t _18 = 0u;
				no_task_and_last_thread_out__q3 = _op_equal_equal_0(_17, _18);
			} else {
				no_task_and_last_thread_out__q3 = 0;
			}
			
			uint8_t _19 = no_task_and_last_thread_out__q3;
			struct no_chosen_task _20 = n2;
			struct opt_5 _21 = _20.first_task_time;
			struct no_chosen_task _22 = (struct no_chosen_task) {_19, _21};
			res4 = (struct choose_task_result) {1, .as1 = _22};
			break;
		}
		default:
			(assert(0),(struct choose_task_result) {0});
	}
	
	struct lock* _23 = &gctx->lk;
	release_lock(_23);
	return res4;
}
/* get-monotime-nsec nat() */
uint64_t get_monotime_nsec(void) {
	struct cell_1 time_cell0;
	int64_t _0 = 0;
	int64_t _1 = 0;
	struct timespec _2 = (struct timespec) {_0, _1};
	time_cell0 = (struct cell_1) {_2};
	
	int32_t err1;
	int32_t _3 = clock_monotonic();
	struct cell_1* _4 = &time_cell0;
	err1 = clock_gettime(_3, _4);
	
	int32_t _5 = err1;
	int32_t _6 = 0;
	uint8_t _7 = _op_equal_equal_2(_5, _6);
	if (_7) {
		struct timespec time2;
		struct cell_1* _8 = &time_cell0;
		time2 = get_0(_8);
		
		struct timespec _9 = time2;
		int64_t _10 = _9.tv_sec;
		int64_t _11 = 1000000000;
		int64_t _12 = _10 * _11;
		struct timespec _13 = time2;
		int64_t _14 = _13.tv_nsec;
		int64_t _15 = _12 + _14;
		return (uint64_t) _15;
	} else {
		return todo_3();
	}
}
/* clock-monotonic int32() */
int32_t clock_monotonic(void) {
	return 1;
}
/* get<timespec> timespec(c cell<timespec>) */
struct timespec get_0(struct cell_1* c) {
	struct cell_1* _0 = c;
	return _0->value;
}
/* todo<nat> nat() */
uint64_t todo_3(void) {
	return (assert(0),0);
}
/* choose-task-recur choose-task-result(islands arr<island>, i nat, cur-time nat, any-tasks? bool, first-task-time opt<nat>) */
struct choose_task_result choose_task_recur(struct arr_3 islands, uint64_t i, uint64_t cur_time, uint8_t any_tasks__q, struct opt_5 first_task_time) {
	top:;
	uint64_t _0 = i;
	struct arr_3 _1 = islands;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		uint8_t _4 = any_tasks__q;
		uint8_t _5 = !_4;
		struct opt_5 _6 = first_task_time;
		struct no_chosen_task _7 = (struct no_chosen_task) {_5, _6};
		return (struct choose_task_result) {1, .as1 = _7};
	} else {
		struct island* island0;
		struct arr_3 _8 = islands;
		uint64_t _9 = i;
		island0 = noctx_at_0(_8, _9);
		
		struct island* _10 = island0;
		uint64_t _11 = cur_time;
		struct choose_task_in_island_result _12 = choose_task_in_island(_10, _11);
		switch (_12.kind) {
			case 0: {
				struct task t1 = _12.as0;
				
				struct island* _13 = island0;
				struct task _14 = t1;
				struct task_or_gc _15 = (struct task_or_gc) {0, .as0 = _14};
				struct chosen_task _16 = (struct chosen_task) {_13, _15};
				return (struct choose_task_result) {0, .as0 = _16};
			}
			case 1: {
				struct do_a_gc g2 = _12.as1;
				
				struct island* _17 = island0;
				struct do_a_gc _18 = g2;
				struct task_or_gc _19 = (struct task_or_gc) {1, .as1 = _18};
				struct chosen_task _20 = (struct chosen_task) {_17, _19};
				return (struct choose_task_result) {0, .as0 = _20};
			}
			case 2: {
				struct no_task n3 = _12.as2;
				
				uint8_t new_any_tasks__q4;
				uint8_t _21 = any_tasks__q;
				if (_21) {
					new_any_tasks__q4 = 1;
				} else {
					struct no_task _22 = n3;
					new_any_tasks__q4 = _22.any_tasks__q;
				}
				
				struct opt_5 new_first_task_time5;
				struct opt_5 _23 = first_task_time;
				struct no_task _24 = n3;
				struct opt_5 _25 = _24.first_task_time;
				new_first_task_time5 = min_time(_23, _25);
				
				struct arr_3 _26 = islands;
				uint64_t _27 = i;
				uint64_t _28 = noctx_incr(_27);
				uint64_t _29 = cur_time;
				uint8_t _30 = new_any_tasks__q4;
				struct opt_5 _31 = new_first_task_time5;
				islands = _26;
				i = _28;
				cur_time = _29;
				any_tasks__q = _30;
				first_task_time = _31;
				goto top;
			}
			default:
				return (assert(0),(struct choose_task_result) {0});
		}
	}
}
/* choose-task-in-island choose-task-in-island-result(island island, cur-time nat) */
struct choose_task_in_island_result choose_task_in_island(struct island* island, uint64_t cur_time) {
	struct lock* _0 = &island->tasks_lock;
	acquire_lock(_0);
	struct choose_task_in_island_result res2;
	struct gc* _1 = &island->gc;
	uint8_t _2 = _1->needs_gc__q;
	if (_2) {
		struct island* _3 = island;
		uint64_t _4 = _3->n_threads_running;
		uint64_t _5 = 0u;
		uint8_t _6 = _op_equal_equal_0(_4, _5);
		if (_6) {
			struct do_a_gc _7 = (struct do_a_gc) {};
			res2 = (struct choose_task_in_island_result) {1, .as1 = _7};
		} else {
			uint8_t _8 = 1;
			struct none _9 = (struct none) {};
			struct opt_5 _10 = (struct opt_5) {0, .as0 = _9};
			struct no_task _11 = (struct no_task) {_8, _10};
			res2 = (struct choose_task_in_island_result) {2, .as2 = _11};
		}
	} else {
		struct island* _12 = island;
		struct task_queue* _13 = tasks(_12);
		uint64_t _14 = cur_time;
		struct pop_task_result _15 = pop_task(_13, _14);
		switch (_15.kind) {
			case 0: {
				struct task t0 = _15.as0;
				
				struct task _16 = t0;
				res2 = (struct choose_task_in_island_result) {0, .as0 = _16};
				break;
			}
			case 1: {
				struct no_task n1 = _15.as1;
				
				struct no_task _17 = n1;
				res2 = (struct choose_task_in_island_result) {2, .as2 = _17};
				break;
			}
			default:
				(assert(0),(struct choose_task_in_island_result) {0});
		}
	}
	
	struct choose_task_in_island_result _18 = res2;
	uint8_t _19 = is_no_task__q(_18);
	uint8_t _20 = !_19;
	if (_20) {
		struct island* _21 = island;
		struct island* _22 = island;
		uint64_t _23 = _22->n_threads_running;
		uint64_t _24 = noctx_incr(_23);
		_21->n_threads_running = _24;
	} else {
		(struct void_) {};
	}
	struct lock* _25 = &island->tasks_lock;
	release_lock(_25);
	return res2;
}
/* pop-task pop-task-result(a task-queue, cur-time nat) */
struct pop_task_result pop_task(struct task_queue* a, uint64_t cur_time) {
	struct mut_list_0* exclusions0;
	exclusions0 = &a->currently_running_exclusions;
	
	struct pop_task_result res4;
	struct task_queue* _0 = a;
	struct opt_2 _1 = _0->head;
	switch (_1.kind) {
		case 0: {
			uint8_t _2 = 0;
			struct none _3 = (struct none) {};
			struct opt_5 _4 = (struct opt_5) {0, .as0 = _3};
			struct no_task _5 = (struct no_task) {_2, _4};
			res4 = (struct pop_task_result) {1, .as1 = _5};
			break;
		}
		case 1: {
			struct some_2 s1 = _1.as1;
			
			struct task_queue_node* head2;
			struct some_2 _6 = s1;
			head2 = _6.value;
			
			struct task task3;
			struct task_queue_node* _7 = head2;
			task3 = _7->task;
			
			struct task _8 = task3;
			uint64_t _9 = _8.time;
			uint64_t _10 = cur_time;
			uint8_t _11 = _op_less_equal(_9, _10);
			if (_11) {
				struct mut_list_0* _12 = exclusions0;
				struct task _13 = task3;
				uint64_t _14 = _13.exclusion;
				uint8_t _15 = contains__q_0(_12, _14);
				if (_15) {
					struct task_queue_node* _16 = head2;
					struct mut_list_0* _17 = exclusions0;
					uint64_t _18 = cur_time;
					struct task _19 = task3;
					uint64_t _20 = _19.time;
					struct opt_5 _21 = to_opt_time(_20);
					res4 = pop_recur(_16, _17, _18, _21);
				} else {
					struct task_queue* _22 = a;
					struct task_queue_node* _23 = head2;
					struct opt_2 _24 = _23->next;
					_22->head = _24;
					struct task_queue_node* _25 = head2;
					struct task _26 = _25->task;
					res4 = (struct pop_task_result) {0, .as0 = _26};
				}
			} else {
				uint8_t _27 = 1;
				struct task _28 = task3;
				uint64_t _29 = _28.time;
				struct some_5 _30 = (struct some_5) {_29};
				struct opt_5 _31 = (struct opt_5) {1, .as1 = _30};
				struct no_task _32 = (struct no_task) {_27, _31};
				res4 = (struct pop_task_result) {1, .as1 = _32};
			}
			break;
		}
		default:
			(assert(0),(struct pop_task_result) {0});
	}
	
	struct pop_task_result _33 = res4;
	switch (_33.kind) {
		case 0: {
			struct task t5 = _33.as0;
			
			struct mut_list_0* _34 = exclusions0;
			struct task _35 = t5;
			uint64_t _36 = _35.exclusion;
			push_capacity_must_be_sufficient(_34, _36);
			break;
		}
		case 1: {
			(struct void_) {};
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	return res4;
}
/* contains?<nat> bool(a mut-list<nat>, value nat) */
uint8_t contains__q_0(struct mut_list_0* a, uint64_t value) {
	struct mut_list_0* _0 = a;
	struct arr_2 _1 = temp_as_arr_0(_0);
	uint64_t _2 = value;
	return contains__q_1(_1, _2);
}
/* contains?<?t> bool(a arr<nat>, value nat) */
uint8_t contains__q_1(struct arr_2 a, uint64_t value) {
	struct arr_2 _0 = a;
	uint64_t _1 = value;
	uint64_t _2 = 0u;
	return contains_recur__q_0(_0, _1, _2);
}
/* contains-recur?<?t> bool(a arr<nat>, value nat, i nat) */
uint8_t contains_recur__q_0(struct arr_2 a, uint64_t value, uint64_t i) {
	top:;
	uint64_t _0 = i;
	struct arr_2 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		return 0;
	} else {
		struct arr_2 _4 = a;
		uint64_t _5 = i;
		uint64_t _6 = noctx_at_2(_4, _5);
		uint64_t _7 = value;
		uint8_t _8 = _op_equal_equal_0(_6, _7);
		if (_8) {
			return 1;
		} else {
			struct arr_2 _9 = a;
			uint64_t _10 = value;
			uint64_t _11 = i;
			uint64_t _12 = noctx_incr(_11);
			a = _9;
			value = _10;
			i = _12;
			goto top;
		}
	}
}
/* noctx-at<?t> nat(a arr<nat>, index nat) */
uint64_t noctx_at_2(struct arr_2 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_2 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_2 _4 = a;
	uint64_t* _5 = _4.data;
	uint64_t _6 = index;
	uint64_t* _7 = _5 + _6;
	return *_7;
}
/* temp-as-arr<?t> arr<nat>(a mut-list<nat>) */
struct arr_2 temp_as_arr_0(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	struct mut_arr_0 _1 = temp_as_mut_arr_0(_0);
	return temp_as_arr_1(_1);
}
/* temp-as-arr<?t> arr<nat>(a mut-arr<nat>) */
struct arr_2 temp_as_arr_1(struct mut_arr_0 a) {
	struct mut_arr_0 _0 = a;
	return _0.arr;
}
/* temp-as-mut-arr<?t> mut-arr<nat>(a mut-list<nat>) */
struct mut_arr_0 temp_as_mut_arr_0(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_0* _2 = a;
	uint64_t* _3 = data_1(_2);
	struct arr_2 _4 = (struct arr_2) {_1, _3};
	return (struct mut_arr_0) {_4};
}
/* data<?t> ptr<nat>(a mut-list<nat>) */
uint64_t* data_1(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	struct mut_arr_0 _1 = _0->backing;
	return data_2(_1);
}
/* data<?t> ptr<nat>(a mut-arr<nat>) */
uint64_t* data_2(struct mut_arr_0 a) {
	struct mut_arr_0 _0 = a;
	struct arr_2 _1 = _0.arr;
	return _1.data;
}
/* pop-recur pop-task-result(prev task-queue-node, exclusions mut-list<nat>, cur-time nat, first-task-time opt<nat>) */
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list_0* exclusions, uint64_t cur_time, struct opt_5 first_task_time) {
	top:;
	struct task_queue_node* _0 = prev;
	struct opt_2 _1 = _0->next;
	switch (_1.kind) {
		case 0: {
			uint8_t _2 = 1;
			struct opt_5 _3 = first_task_time;
			struct no_task _4 = (struct no_task) {_2, _3};
			return (struct pop_task_result) {1, .as1 = _4};
		}
		case 1: {
			struct some_2 s0 = _1.as1;
			
			struct task_queue_node* cur1;
			struct some_2 _5 = s0;
			cur1 = _5.value;
			
			struct task task2;
			struct task_queue_node* _6 = cur1;
			task2 = _6->task;
			
			struct task _7 = task2;
			uint64_t _8 = _7.time;
			uint64_t _9 = cur_time;
			uint8_t _10 = _op_less_equal(_8, _9);
			if (_10) {
				struct mut_list_0* _11 = exclusions;
				struct task _12 = task2;
				uint64_t _13 = _12.exclusion;
				uint8_t _14 = contains__q_0(_11, _13);
				if (_14) {
					struct task_queue_node* _15 = cur1;
					struct mut_list_0* _16 = exclusions;
					uint64_t _17 = cur_time;
					struct opt_5 _18 = first_task_time;struct opt_5 _19;
					
					switch (_18.kind) {
						case 0: {
							struct task _20 = task2;
							uint64_t _21 = _20.time;
							_19 = to_opt_time(_21);
							break;
						}
						case 1: {
							_19 = first_task_time;
							break;
						}
						default:
							(assert(0),(struct opt_5) {0});
					}
					prev = _15;
					exclusions = _16;
					cur_time = _17;
					first_task_time = _19;
					goto top;
				} else {
					struct task_queue_node* _22 = prev;
					struct task_queue_node* _23 = cur1;
					struct opt_2 _24 = _23->next;
					_22->next = _24;
					struct mut_list_0* _25 = exclusions;
					struct task _26 = task2;
					uint64_t _27 = _26.exclusion;
					push_capacity_must_be_sufficient(_25, _27);
					struct task _28 = task2;
					return (struct pop_task_result) {0, .as0 = _28};
				}
			} else {
				uint8_t _29 = 1;
				struct task _30 = task2;
				uint64_t _31 = _30.time;
				struct some_5 _32 = (struct some_5) {_31};
				struct opt_5 _33 = (struct opt_5) {1, .as1 = _32};
				struct no_task _34 = (struct no_task) {_29, _33};
				return (struct pop_task_result) {1, .as1 = _34};
			}
		}
		default:
			return (assert(0),(struct pop_task_result) {0});
	}
}
/* to-opt-time opt<nat>(a nat) */
struct opt_5 to_opt_time(uint64_t a) {
	uint64_t _0 = a;
	uint64_t _1 = no_timestamp();
	uint8_t _2 = _op_equal_equal_0(_0, _1);
	if (_2) {
		struct none _3 = (struct none) {};
		return (struct opt_5) {0, .as0 = _3};
	} else {
		uint64_t _4 = a;
		struct some_5 _5 = (struct some_5) {_4};
		return (struct opt_5) {1, .as1 = _5};
	}
}
/* push-capacity-must-be-sufficient<nat> void(a mut-list<nat>, value nat) */
struct void_ push_capacity_must_be_sufficient(struct mut_list_0* a, uint64_t value) {
	struct mut_list_0* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_0* _2 = a;
	uint64_t _3 = capacity_0(_2);
	uint8_t _4 = _op_less_0(_1, _3);
	hard_assert(_4);
	uint64_t old_size0;
	struct mut_list_0* _5 = a;
	old_size0 = _5->size;
	
	struct mut_list_0* _6 = a;
	uint64_t _7 = old_size0;
	uint64_t _8 = noctx_incr(_7);
	_6->size = _8;
	struct mut_list_0* _9 = a;
	uint64_t _10 = old_size0;
	uint64_t _11 = value;
	return noctx_set_at_1(_9, _10, _11);
}
/* capacity<?t> nat(a mut-list<nat>) */
uint64_t capacity_0(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	struct mut_arr_0 _1 = _0->backing;
	return size_2(_1);
}
/* size<?t> nat(a mut-arr<nat>) */
uint64_t size_2(struct mut_arr_0 a) {
	struct mut_arr_0 _0 = a;
	struct arr_2 _1 = _0.arr;
	return _1.size;
}
/* noctx-set-at<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_set_at_1(struct mut_list_0* a, uint64_t index, uint64_t value) {
	uint64_t _0 = index;
	struct mut_list_0* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_0* _4 = a;
	uint64_t* _5 = data_1(_4);
	uint64_t _6 = index;
	uint64_t* _7 = _5 + _6;
	uint64_t _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* is-no-task? bool(a choose-task-in-island-result) */
uint8_t is_no_task__q(struct choose_task_in_island_result a) {
	struct choose_task_in_island_result _0 = a;
	switch (_0.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 1;
		}
		default:
			return (assert(0),0);
	}
}
/* min-time opt<nat>(a opt<nat>, b opt<nat>) */
struct opt_5 min_time(struct opt_5 a, struct opt_5 b) {
	struct opt_5 _0 = a;
	switch (_0.kind) {
		case 0: {
			return b;
		}
		case 1: {
			struct some_5 sa0 = _0.as1;
			
			struct opt_5 _1 = b;
			switch (_1.kind) {
				case 0: {
					return a;
				}
				case 1: {
					struct some_5 sb1 = _1.as1;
					
					struct some_5 _2 = sa0;
					uint64_t _3 = _2.value;
					struct some_5 _4 = sb1;
					uint64_t _5 = _4.value;
					uint64_t _6 = min(_3, _5);
					struct some_5 _7 = (struct some_5) {_6};
					return (struct opt_5) {1, .as1 = _7};
				}
				default:
					return (assert(0),(struct opt_5) {0});
			}
		}
		default:
			return (assert(0),(struct opt_5) {0});
	}
}
/* min<nat> nat(a nat, b nat) */
uint64_t min(uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = b;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		return a;
	} else {
		return b;
	}
}
/* do-task void(gctx global-ctx, tls thread-local-stuff, chosen-task chosen-task) */
struct void_ do_task(struct global_ctx* gctx, struct thread_local_stuff* tls, struct chosen_task chosen_task) {
	struct island* island0;
	struct chosen_task _0 = chosen_task;
	island0 = _0.task_island;
	
	struct chosen_task _1 = chosen_task;
	struct task_or_gc _2 = _1.task_or_gc;
	switch (_2.kind) {
		case 0: {
			struct task task1 = _2.as0;
			
			struct ctx ctx2;
			struct global_ctx* _3 = gctx;
			struct thread_local_stuff* _4 = tls;
			struct island* _5 = island0;
			struct task _6 = task1;
			uint64_t _7 = _6.exclusion;
			ctx2 = new_ctx(_3, _4, _5, _7);
			
			struct task _8 = task1;
			struct fun_act0_0 _9 = _8.action;
			struct ctx* _10 = &ctx2;
			call_w_ctx_143(_9, _10);
			struct lock* _11 = &island0->tasks_lock;
			acquire_lock(_11);
			struct island* _12 = island0;
			struct task_queue* _13 = tasks(_12);
			struct task _14 = task1;
			return_task(_13, _14);
			struct lock* _15 = &island0->tasks_lock;
			release_lock(_15);
			struct ctx* _16 = &ctx2;
			return_ctx(_16);
			break;
		}
		case 1: {
			struct gc* _17 = &island0->gc;
			struct island* _18 = island0;
			struct island_gc_root _19 = _18->gc_root;
			run_garbage_collection(_17, _19);
			struct condition* _20 = &gctx->may_be_work_to_do;
			broadcast(_20);
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	struct lock* _21 = &island0->tasks_lock;
	acquire_lock(_21);
	struct island* _22 = island0;
	struct island* _23 = island0;
	uint64_t _24 = _23->n_threads_running;
	uint64_t _25 = noctx_decr(_24);
	_22->n_threads_running = _25;
	struct lock* _26 = &island0->tasks_lock;
	return release_lock(_26);
}
/* return-task void(a task-queue, task task) */
struct void_ return_task(struct task_queue* a, struct task task) {
	struct mut_list_0* _0 = &a->currently_running_exclusions;
	struct task _1 = task;
	uint64_t _2 = _1.exclusion;
	return noctx_must_remove_unordered(_0, _2);
}
/* noctx-must-remove-unordered<nat> void(a mut-list<nat>, value nat) */
struct void_ noctx_must_remove_unordered(struct mut_list_0* a, uint64_t value) {
	struct mut_list_0* _0 = a;
	uint64_t _1 = 0u;
	uint64_t _2 = value;
	return noctx_must_remove_unordered_recur(_0, _1, _2);
}
/* noctx-must-remove-unordered-recur<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_must_remove_unordered_recur(struct mut_list_0* a, uint64_t index, uint64_t value) {
	top:;
	uint64_t _0 = index;
	struct mut_list_0* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		return (assert(0),(struct void_) {});
	} else {
		struct mut_list_0* _4 = a;
		uint64_t _5 = index;
		uint64_t _6 = noctx_at_3(_4, _5);
		uint64_t _7 = value;
		uint8_t _8 = _op_equal_equal_0(_6, _7);
		if (_8) {
			struct mut_list_0* _9 = a;
			uint64_t _10 = index;
			uint64_t _11 = noctx_remove_unordered_at_index(_9, _10);
			return drop_1(_11);
		} else {
			struct mut_list_0* _12 = a;
			uint64_t _13 = index;
			uint64_t _14 = noctx_incr(_13);
			uint64_t _15 = value;
			a = _12;
			index = _14;
			value = _15;
			goto top;
		}
	}
}
/* noctx-at<?t> nat(a mut-list<nat>, index nat) */
uint64_t noctx_at_3(struct mut_list_0* a, uint64_t index) {
	uint64_t _0 = index;
	struct mut_list_0* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_0* _4 = a;
	uint64_t* _5 = data_1(_4);
	uint64_t _6 = index;
	uint64_t* _7 = _5 + _6;
	return *_7;
}
/* drop<?t> void(_ nat) */
struct void_ drop_1(uint64_t _p0) {
	return (struct void_) {};
}
/* noctx-remove-unordered-at-index<?t> nat(a mut-list<nat>, index nat) */
uint64_t noctx_remove_unordered_at_index(struct mut_list_0* a, uint64_t index) {
	uint64_t res0;
	struct mut_list_0* _0 = a;
	uint64_t _1 = index;
	res0 = noctx_at_3(_0, _1);
	
	struct mut_list_0* _2 = a;
	uint64_t _3 = index;
	struct mut_list_0* _4 = a;
	uint64_t _5 = noctx_last(_4);
	noctx_set_at_1(_2, _3, _5);
	struct mut_list_0* _6 = a;
	struct mut_list_0* _7 = a;
	uint64_t _8 = _7->size;
	uint64_t _9 = noctx_decr(_8);
	_6->size = _9;
	return res0;
}
/* noctx-last<?t> nat(a mut-list<nat>) */
uint64_t noctx_last(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	uint8_t _1 = empty__q_4(_0);
	hard_forbid(_1);
	struct mut_list_0* _2 = a;
	struct mut_list_0* _3 = a;
	uint64_t _4 = _3->size;
	uint64_t _5 = noctx_decr(_4);
	return noctx_at_3(_2, _5);
}
/* empty?<?t> bool(a mut-list<nat>) */
uint8_t empty__q_4(struct mut_list_0* a) {
	struct mut_list_0* _0 = a;
	uint64_t _1 = _0->size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* return-ctx void(c ctx) */
struct void_ return_ctx(struct ctx* c) {
	struct ctx* _0 = c;
	uint8_t* _1 = _0->gc_ctx_ptr;
	struct gc_ctx* _2 = (struct gc_ctx*) _1;
	return return_gc_ctx(_2);
}
/* return-gc-ctx void(gc-ctx gc-ctx) */
struct void_ return_gc_ctx(struct gc_ctx* gc_ctx) {
	struct gc* gc0;
	struct gc_ctx* _0 = gc_ctx;
	gc0 = _0->gc;
	
	struct lock* _1 = &gc0->lk;
	acquire_lock(_1);
	struct gc_ctx* _2 = gc_ctx;
	struct gc* _3 = gc0;
	struct opt_1 _4 = _3->context_head;
	_2->next_ctx = _4;
	struct gc* _5 = gc0;
	struct gc_ctx* _6 = gc_ctx;
	struct some_1 _7 = (struct some_1) {_6};
	struct opt_1 _8 = (struct opt_1) {1, .as1 = _7};
	_5->context_head = _8;
	struct lock* _9 = &gc0->lk;
	return release_lock(_9);
}
/* run-garbage-collection<by-val<island-gc-root>> void(gc gc, gc-root island-gc-root) */
struct void_ run_garbage_collection(struct gc* gc, struct island_gc_root gc_root) {
	struct gc* _0 = gc;
	uint8_t _1 = _0->needs_gc__q;
	hard_assert(_1);
	struct gc* _2 = gc;
	uint8_t _3 = 0;
	_2->needs_gc__q = _3;
	struct gc* _4 = gc;
	struct gc* _5 = gc;
	uint64_t _6 = _5->gc_count;
	uint64_t _7 = wrap_incr(_6);
	_4->gc_count = _7;
	struct gc* _8 = gc;
	uint8_t* _9 = _8->mark_begin;
	uint8_t* _10 = (uint8_t*) _9;
	uint8_t _11 = 0u;
	struct gc* _12 = gc;
	uint64_t _13 = _12->size_words;
	(memset(_10, _11, _13), (struct void_) {});
	struct mark_ctx mark_ctx0;
	struct gc* _14 = gc;
	uint64_t _15 = _14->size_words;
	struct gc* _16 = gc;
	uint8_t* _17 = _16->mark_begin;
	struct gc* _18 = gc;
	uint64_t* _19 = _18->data_begin;
	mark_ctx0 = (struct mark_ctx) {_15, _17, _19};
	
	struct mark_ctx* _20 = &mark_ctx0;
	struct island_gc_root _21 = gc_root;
	mark_visit_255(_20, _21);
	struct gc* _22 = gc;
	struct gc* _23 = gc;
	uint8_t* _24 = _23->mark_begin;
	_22->mark_cur = _24;
	struct gc* _25 = gc;
	struct gc* _26 = gc;
	uint64_t* _27 = _26->data_begin;
	_25->data_cur = _27;
	struct gc* _28 = gc;
	uint8_t* _29 = _28->mark_begin;
	struct gc* _30 = gc;
	uint8_t* _31 = _30->mark_end;
	struct gc* _32 = gc;
	uint64_t* _33 = _32->data_begin;
	clear_free_mem(_29, _31, _33);
	struct gc* _34 = gc;
	return validate_gc(_34);
}
/* mark-visit<island-gc-root> (generated) (generated) */
struct void_ mark_visit_255(struct mark_ctx* mark_ctx, struct island_gc_root value) {
	struct mark_ctx* _0 = mark_ctx;
	struct island_gc_root _1 = value;
	struct task_queue _2 = _1.tasks;
	return mark_visit_256(_0, _2);
}
/* mark-visit<task-queue> (generated) (generated) */
struct void_ mark_visit_256(struct mark_ctx* mark_ctx, struct task_queue value) {
	struct mark_ctx* _0 = mark_ctx;
	struct task_queue _1 = value;
	struct opt_2 _2 = _1.head;
	mark_visit_257(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct task_queue _4 = value;
	struct mut_list_0 _5 = _4.currently_running_exclusions;
	return mark_visit_293(_3, _5);
}
/* mark-visit<opt<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_257(struct mark_ctx* mark_ctx, struct opt_2 value) {
	struct opt_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_2 value1 = _0.as1;
			
			struct mark_ctx* _1 = mark_ctx;
			struct some_2 _2 = value1;
			return mark_visit_258(_1, _2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<some<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_258(struct mark_ctx* mark_ctx, struct some_2 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct some_2 _1 = value;
	struct task_queue_node* _2 = _1.value;
	return mark_visit_292(_0, _2);
}
/* mark-visit<task-queue-node> (generated) (generated) */
struct void_ mark_visit_259(struct mark_ctx* mark_ctx, struct task_queue_node value) {
	struct mark_ctx* _0 = mark_ctx;
	struct task_queue_node _1 = value;
	struct task _2 = _1.task;
	mark_visit_260(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct task_queue_node _4 = value;
	struct opt_2 _5 = _4.next;
	return mark_visit_257(_3, _5);
}
/* mark-visit<task> (generated) (generated) */
struct void_ mark_visit_260(struct mark_ctx* mark_ctx, struct task value) {
	struct mark_ctx* _0 = mark_ctx;
	struct task _1 = value;
	struct fun_act0_0 _2 = _1.action;
	return mark_visit_261(_0, _2);
}
/* mark-visit<fun-act0<void>> (generated) (generated) */
struct void_ mark_visit_261(struct mark_ctx* mark_ctx, struct fun_act0_0 value) {
	struct fun_act0_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda0* value0 = _0.as0;
			
			struct mark_ctx* _1 = mark_ctx;
			struct call_ref_0__lambda0__lambda0* _2 = value0;
			return mark_visit_285(_1, _2);
		}
		case 1: {
			struct call_ref_0__lambda0* value1 = _0.as1;
			
			struct mark_ctx* _3 = mark_ctx;
			struct call_ref_0__lambda0* _4 = value1;
			return mark_visit_287(_3, _4);
		}
		case 2: {
			struct call_ref_1__lambda0__lambda0* value2 = _0.as2;
			
			struct mark_ctx* _5 = mark_ctx;
			struct call_ref_1__lambda0__lambda0* _6 = value2;
			return mark_visit_289(_5, _6);
		}
		case 3: {
			struct call_ref_1__lambda0* value3 = _0.as3;
			
			struct mark_ctx* _7 = mark_ctx;
			struct call_ref_1__lambda0* _8 = value3;
			return mark_visit_291(_7, _8);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<call-ref<?out, ?in>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_262(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_0__lambda0__lambda0 _1 = value;
	struct fun_ref1 _2 = _1.f;
	mark_visit_263(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct call_ref_0__lambda0__lambda0 _4 = value;
	struct fut_0* _5 = _4.res;
	return mark_visit_280(_3, _5);
}
/* mark-visit<fun-ref1<int32, void>> (generated) (generated) */
struct void_ mark_visit_263(struct mark_ctx* mark_ctx, struct fun_ref1 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fun_ref1 _1 = value;
	struct fun_act1_2 _2 = _1.fun;
	return mark_visit_264(_0, _2);
}
/* mark-visit<fun-act1<fut<int32>, void>> (generated) (generated) */
struct void_ mark_visit_264(struct mark_ctx* mark_ctx, struct fun_act1_2 value) {
	struct fun_act1_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* value0 = _0.as0;
			
			struct mark_ctx* _1 = mark_ctx;
			struct then2__lambda0* _2 = value0;
			return mark_visit_271(_1, _2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<then2<int32>.lambda0> (generated) (generated) */
struct void_ mark_visit_265(struct mark_ctx* mark_ctx, struct then2__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct then2__lambda0 _1 = value;
	struct fun_ref0 _2 = _1.cb;
	return mark_visit_266(_0, _2);
}
/* mark-visit<fun-ref0<int32>> (generated) (generated) */
struct void_ mark_visit_266(struct mark_ctx* mark_ctx, struct fun_ref0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fun_ref0 _1 = value;
	struct fun_act0_1 _2 = _1.fun;
	return mark_visit_267(_0, _2);
}
/* mark-visit<fun-act0<fut<int32>>> (generated) (generated) */
struct void_ mark_visit_267(struct mark_ctx* mark_ctx, struct fun_act0_1 value) {
	struct fun_act0_1 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* value0 = _0.as0;
			
			struct mark_ctx* _1 = mark_ctx;
			struct add_first_task__lambda0* _2 = value0;
			return mark_visit_270(_1, _2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<add-first-task.lambda0> (generated) (generated) */
struct void_ mark_visit_268(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct add_first_task__lambda0 _1 = value;
	struct arr_4 _2 = _1.all_args;
	return mark_arr_269(_0, _2);
}
/* mark-arr<raw-ptr(char)> (generated) (generated) */
struct void_ mark_arr_269(struct mark_ctx* mark_ctx, struct arr_4 a) {
	uint8_t dropped0;
	struct mark_ctx* _0 = mark_ctx;
	struct arr_4 _1 = a;
	char** _2 = _1.data;
	uint8_t* _3 = (uint8_t*) _2;
	struct arr_4 _4 = a;
	uint64_t _5 = _4.size;
	uint64_t _6 = sizeof(char*);
	uint64_t _7 = _5 * _6;
	dropped0 = mark(_0, _3, _7);
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(add-first-task.lambda0)> (generated) (generated) */
struct void_ mark_visit_270(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct add_first_task__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct add_first_task__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct add_first_task__lambda0* _6 = value;
		struct add_first_task__lambda0 _7 = *_6;
		return mark_visit_268(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(then2<int32>.lambda0)> (generated) (generated) */
struct void_ mark_visit_271(struct mark_ctx* mark_ctx, struct then2__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct then2__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct then2__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct then2__lambda0* _6 = value;
		struct then2__lambda0 _7 = *_6;
		return mark_visit_265(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<fut<int32>> (generated) (generated) */
struct void_ mark_visit_272(struct mark_ctx* mark_ctx, struct fut_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fut_0 _1 = value;
	struct fut_state_0 _2 = _1.state;
	return mark_visit_273(_0, _2);
}
/* mark-visit<fut-state<int32>> (generated) (generated) */
struct void_ mark_visit_273(struct mark_ctx* mark_ctx, struct fut_state_0 value) {
	struct fut_state_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_0 value0 = _0.as0;
			
			struct mark_ctx* _1 = mark_ctx;
			struct fut_state_callbacks_0 _2 = value0;
			return mark_visit_274(_1, _2);
		}
		case 1: {
			return (struct void_) {};
		}
		case 2: {
			struct exception value2 = _0.as2;
			
			struct mark_ctx* _3 = mark_ctx;
			struct exception _4 = value2;
			return mark_visit_283(_3, _4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<fut-state-callbacks<int32>> (generated) (generated) */
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fut_state_callbacks_0 _1 = value;
	struct opt_0 _2 = _1.head;
	return mark_visit_275(_0, _2);
}
/* mark-visit<opt<fut-callback-node<int32>>> (generated) (generated) */
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct opt_0 value) {
	struct opt_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_0 value1 = _0.as1;
			
			struct mark_ctx* _1 = mark_ctx;
			struct some_0 _2 = value1;
			return mark_visit_276(_1, _2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<some<fut-callback-node<int32>>> (generated) (generated) */
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct some_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct some_0 _1 = value;
	struct fut_callback_node_0* _2 = _1.value;
	return mark_visit_282(_0, _2);
}
/* mark-visit<fut-callback-node<int32>> (generated) (generated) */
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fut_callback_node_0 _1 = value;
	struct fun_act1_0 _2 = _1.cb;
	mark_visit_278(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct fut_callback_node_0 _4 = value;
	struct opt_0 _5 = _4.next_node;
	return mark_visit_275(_3, _5);
}
/* mark-visit<fun-act1<void, result<int32, exception>>> (generated) (generated) */
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct fun_act1_0 value) {
	struct fun_act1_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* value0 = _0.as0;
			
			struct mark_ctx* _1 = mark_ctx;
			struct forward_to__lambda0* _2 = value0;
			return mark_visit_281(_1, _2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<forward-to<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct forward_to__lambda0 _1 = value;
	struct fut_0* _2 = _1.to;
	return mark_visit_280(_0, _2);
}
/* mark-visit<gc-ptr(fut<int32>)> (generated) (generated) */
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct fut_0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fut_0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct fut_0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct fut_0* _6 = value;
		struct fut_0 _7 = *_6;
		return mark_visit_272(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(forward-to<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct forward_to__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct forward_to__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct forward_to__lambda0* _6 = value;
		struct forward_to__lambda0 _7 = *_6;
		return mark_visit_279(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(fut-callback-node<int32>)> (generated) (generated) */
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct fut_callback_node_0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct fut_callback_node_0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct fut_callback_node_0* _6 = value;
		struct fut_callback_node_0 _7 = *_6;
		return mark_visit_277(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<exception> (generated) (generated) */
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct exception value) {
	struct mark_ctx* _0 = mark_ctx;
	struct exception _1 = value;
	struct arr_0 _2 = _1.message;
	return mark_arr_284(_0, _2);
}
/* mark-arr<char> (generated) (generated) */
struct void_ mark_arr_284(struct mark_ctx* mark_ctx, struct arr_0 a) {
	uint8_t dropped0;
	struct mark_ctx* _0 = mark_ctx;
	struct arr_0 _1 = a;
	char* _2 = _1.data;
	uint8_t* _3 = (uint8_t*) _2;
	struct arr_0 _4 = a;
	uint64_t _5 = _4.size;
	uint64_t _6 = sizeof(char);
	uint64_t _7 = _5 * _6;
	dropped0 = mark(_0, _3, _7);
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(call-ref<?out, ?in>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_285(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_0__lambda0__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct call_ref_0__lambda0__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct call_ref_0__lambda0__lambda0* _6 = value;
		struct call_ref_0__lambda0__lambda0 _7 = *_6;
		return mark_visit_262(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out, ?in>.lambda0> (generated) (generated) */
struct void_ mark_visit_286(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_0__lambda0 _1 = value;
	struct fun_ref1 _2 = _1.f;
	mark_visit_263(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct call_ref_0__lambda0 _4 = value;
	struct fut_0* _5 = _4.res;
	return mark_visit_280(_3, _5);
}
/* mark-visit<gc-ptr(call-ref<?out, ?in>.lambda0)> (generated) (generated) */
struct void_ mark_visit_287(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_0__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct call_ref_0__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct call_ref_0__lambda0* _6 = value;
		struct call_ref_0__lambda0 _7 = *_6;
		return mark_visit_286(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_288(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_1__lambda0__lambda0 _1 = value;
	struct fun_ref0 _2 = _1.f;
	mark_visit_266(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct call_ref_1__lambda0__lambda0 _4 = value;
	struct fut_0* _5 = _4.res;
	return mark_visit_280(_3, _5);
}
/* mark-visit<gc-ptr(call-ref<?out>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_289(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_1__lambda0__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct call_ref_1__lambda0__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct call_ref_1__lambda0__lambda0* _6 = value;
		struct call_ref_1__lambda0__lambda0 _7 = *_6;
		return mark_visit_288(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_290(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_1__lambda0 _1 = value;
	struct fun_ref0 _2 = _1.f;
	mark_visit_266(_0, _2);
	struct mark_ctx* _3 = mark_ctx;
	struct call_ref_1__lambda0 _4 = value;
	struct fut_0* _5 = _4.res;
	return mark_visit_280(_3, _5);
}
/* mark-visit<gc-ptr(call-ref<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_291(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct call_ref_1__lambda0* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct call_ref_1__lambda0);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct call_ref_1__lambda0* _6 = value;
		struct call_ref_1__lambda0 _7 = *_6;
		return mark_visit_290(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(task-queue-node)> (generated) (generated) */
struct void_ mark_visit_292(struct mark_ctx* mark_ctx, struct task_queue_node* value) {
	struct mark_ctx* _0 = mark_ctx;
	struct task_queue_node* _1 = value;
	uint8_t* _2 = (uint8_t*) _1;
	uint64_t _3 = sizeof(struct task_queue_node);
	uint8_t _4 = mark(_0, _2, _3);
	if (_4) {
		struct mark_ctx* _5 = mark_ctx;
		struct task_queue_node* _6 = value;
		struct task_queue_node _7 = *_6;
		return mark_visit_259(_5, _7);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<mut-list<nat>> (generated) (generated) */
struct void_ mark_visit_293(struct mark_ctx* mark_ctx, struct mut_list_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct mut_list_0 _1 = value;
	struct mut_arr_0 _2 = _1.backing;
	return mark_visit_294(_0, _2);
}
/* mark-visit<mut-arr<nat>> (generated) (generated) */
struct void_ mark_visit_294(struct mark_ctx* mark_ctx, struct mut_arr_0 value) {
	struct mark_ctx* _0 = mark_ctx;
	struct mut_arr_0 _1 = value;
	struct arr_2 _2 = _1.arr;
	return mark_arr_295(_0, _2);
}
/* mark-arr<nat-64> (generated) (generated) */
struct void_ mark_arr_295(struct mark_ctx* mark_ctx, struct arr_2 a) {
	uint8_t dropped0;
	struct mark_ctx* _0 = mark_ctx;
	struct arr_2 _1 = a;
	uint64_t* _2 = _1.data;
	uint8_t* _3 = (uint8_t*) _2;
	struct arr_2 _4 = a;
	uint64_t _5 = _4.size;
	uint64_t _6 = sizeof(uint64_t);
	uint64_t _7 = _5 * _6;
	dropped0 = mark(_0, _3, _7);
	
	return (struct void_) {};
}
/* clear-free-mem void(mark-ptr ptr<bool>, mark-end ptr<bool>, data-ptr ptr<nat>) */
struct void_ clear_free_mem(uint8_t* mark_ptr, uint8_t* mark_end, uint64_t* data_ptr) {
	top:;
	uint8_t* _0 = mark_ptr;
	uint8_t* _1 = mark_end;
	uint8_t _2 = _0 == _1;
	uint8_t _3 = !_2;
	if (_3) {
		uint8_t* _4 = mark_ptr;
		uint8_t _5 = *_4;
		uint8_t _6 = !_5;
		if (_6) {
			uint64_t* _7 = data_ptr;
			uint64_t _8 = 18077161789910350558u;
			*_7 = _8;
		} else {
			(struct void_) {};
		}
		uint8_t* _9 = mark_ptr;
		uint8_t* _10 = incr_0(_9);
		uint8_t* _11 = mark_end;
		uint64_t* _12 = data_ptr;
		mark_ptr = _10;
		mark_end = _11;
		data_ptr = _12;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* wait-on void(cond condition, until-time opt<nat>, last-checked nat) */
struct void_ wait_on(struct condition* cond, struct opt_5 until_time, uint64_t last_checked) {
	top:;
	struct condition* _0 = cond;
	uint64_t _1 = _0->value;
	uint64_t _2 = last_checked;
	uint8_t _3 = _op_equal_equal_0(_1, _2);
	if (_3) {
		yield_thread();
		struct opt_5 _4 = until_time;
		uint8_t _5 = before_time__q(_4);
		if (_5) {
			struct condition* _6 = cond;
			struct opt_5 _7 = until_time;
			uint64_t _8 = last_checked;
			cond = _6;
			until_time = _7;
			last_checked = _8;
			goto top;
		} else {
			return (struct void_) {};
		}
	} else {
		return (struct void_) {};
	}
}
/* before-time? bool(until-time opt<nat>) */
uint8_t before_time__q(struct opt_5 until_time) {
	struct opt_5 _0 = until_time;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			uint64_t _1 = get_monotime_nsec();
			struct some_5 _2 = s0;
			uint64_t _3 = _2.value;
			return _op_less_0(_1, _3);
		}
		default:
			return (assert(0),0);
	}
}
/* join-threads-recur void(i nat, n-threads nat, threads ptr<nat>) */
struct void_ join_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads) {
	top:;
	uint64_t _0 = i;
	uint64_t _1 = n_threads;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		uint64_t* _3 = threads;
		uint64_t _4 = i;
		uint64_t* _5 = _3 + _4;
		uint64_t _6 = *_5;
		join_one_thread(_6);
		uint64_t _7 = i;
		uint64_t _8 = noctx_incr(_7);
		uint64_t _9 = n_threads;
		uint64_t* _10 = threads;
		i = _8;
		n_threads = _9;
		threads = _10;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* join-one-thread void(tid nat) */
struct void_ join_one_thread(uint64_t tid) {
	struct cell_2 thread_return0;
	uint8_t* _0 = NULL;
	thread_return0 = (struct cell_2) {_0};
	
	int32_t err1;
	uint64_t _1 = tid;
	struct cell_2* _2 = &thread_return0;
	err1 = pthread_join(_1, _2);
	
	int32_t _3 = err1;
	int32_t _4 = 0;
	uint8_t _5 = _op_bang_equal_2(_3, _4);
	if (_5) {
		int32_t _6 = err1;
		int32_t _7 = einval();
		uint8_t _8 = _op_equal_equal_2(_6, _7);
		if (_8) {
			todo_0();
		} else {
			int32_t _9 = err1;
			int32_t _10 = esrch();
			uint8_t _11 = _op_equal_equal_2(_9, _10);
			if (_11) {
				todo_0();
			} else {
				todo_0();
			}
		}
	} else {
		(struct void_) {};
	}
	struct cell_2* _12 = &thread_return0;
	uint8_t* _13 = get_1(_12);
	uint8_t _14 = null__q_0(_13);
	return hard_assert(_14);
}
/* einval int32() */
int32_t einval(void) {
	return 22;
}
/* esrch int32() */
int32_t esrch(void) {
	return 3;
}
/* get<ptr<nat8>> ptr<nat8>(c cell<ptr<nat8>>) */
uint8_t* get_1(struct cell_2* c) {
	struct cell_2* _0 = c;
	return _0->value;
}
/* unmanaged-free<nat> void(p ptr<nat>) */
struct void_ unmanaged_free_0(uint64_t* p) {
	uint64_t* _0 = p;
	uint8_t* _1 = (uint8_t*) _0;
	return (free(_1), (struct void_) {});
}
/* unmanaged-free<by-val<thread-args>> void(p ptr<thread-args>) */
struct void_ unmanaged_free_1(struct thread_args* p) {
	struct thread_args* _0 = p;
	uint8_t* _1 = (uint8_t*) _0;
	return (free(_1), (struct void_) {});
}
/* must-be-resolved<int32> result<int32, exception>(f fut<int32>) */
struct result_0 must_be_resolved(struct fut_0* f) {
	struct fut_0* _0 = f;
	struct fut_state_0 _1 = _0->state;
	switch (_1.kind) {
		case 0: {
			return hard_unreachable_0();
		}
		case 1: {
			struct fut_state_resolved_0 r0 = _1.as1;
			
			struct fut_state_resolved_0 _2 = r0;
			int32_t _3 = _2.value;
			struct ok_0 _4 = (struct ok_0) {_3};
			return (struct result_0) {0, .as0 = _4};
		}
		case 2: {
			struct exception e1 = _1.as2;
			
			struct exception _5 = e1;
			struct err_0 _6 = (struct err_0) {_5};
			return (struct result_0) {1, .as1 = _6};
		}
		default:
			return (assert(0),(struct result_0) {0});
	}
}
/* hard-unreachable<result<?t, exception>> result<int32, exception>() */
struct result_0 hard_unreachable_0(void) {
	return (assert(0),(struct result_0) {0});
}
/* main fut<int32>(args arr<arr<char>>) */
struct fut_0* main_0(struct ctx* ctx, struct arr_1 args) {
	struct opt_6 options0;
	struct ctx* _0 = ctx;
	struct arr_1 _1 = args;
	struct arr_1 _2 = (struct arr_1) {3, constantarr_1_0};
	struct void_ _3 = (struct void_) {};
	struct fun1_2 _4 = (struct fun1_2) {0, .as0 = _3};
	options0 = parse_cmd_line_args(_0, _1, _2, _4);
	
	struct ctx* _5 = ctx;
	struct opt_6 _6 = options0;int32_t _7;
	
	switch (_6.kind) {
		case 0: {
			struct ctx* _8 = ctx;
			print_help(_8);
			_7 = 1;
			break;
		}
		case 1: {
			struct some_6 s1 = _6.as1;
			
			struct ctx* _9 = ctx;
			struct some_6 _10 = s1;
			struct test_options _11 = _10.value;
			_7 = do_test(_9, _11);
			break;
		}
		default:
			(assert(0),0);
	}
	return resolved_1(_5, _7);
}
/* parse-cmd-line-args<test-options> opt<test-options>(args arr<arr<char>>, t-names arr<arr<char>>, make-t fun1<test-options, arr<opt<arr<arr<char>>>>>) */
struct opt_6 parse_cmd_line_args(struct ctx* ctx, struct arr_1 args, struct arr_1 t_names, struct fun1_2 make_t) {
	struct parsed_cmd_line_args* parsed0;
	struct ctx* _0 = ctx;
	struct arr_1 _1 = args;
	parsed0 = parse_cmd_line_args_dynamic(_0, _1);
	
	struct ctx* _2 = ctx;
	struct parsed_cmd_line_args* _3 = parsed0;
	struct arr_1 _4 = _3->nameless;
	uint8_t _5 = empty__q_5(_4);
	struct arr_0 _6 = (struct arr_0) {26, constantarr_0_20};
	assert_1(_2, _5, _6);
	struct ctx* _7 = ctx;
	struct parsed_cmd_line_args* _8 = parsed0;
	struct arr_1 _9 = _8->after;
	uint8_t _10 = empty__q_5(_9);
	assert_0(_7, _10);
	struct mut_list_3* values1;
	struct ctx* _11 = ctx;
	struct arr_1 _12 = t_names;
	uint64_t _13 = _12.size;
	struct none _14 = (struct none) {};
	struct opt_7 _15 = (struct opt_7) {0, .as0 = _14};
	values1 = fill_mut_list(_11, _13, _15);
	
	struct cell_3* help2;
	struct cell_3* temp0;
	struct ctx* _16 = ctx;
	uint64_t _17 = sizeof(struct cell_3);
	uint8_t* _18 = alloc(_16, _17);
	temp0 = (struct cell_3*) _18;
	
	struct cell_3* _19 = temp0;
	uint8_t _20 = 0;
	struct cell_3 _21 = (struct cell_3) {_20};
	*_19 = _21;
	help2 = temp0;
	
	struct ctx* _22 = ctx;
	struct parsed_cmd_line_args* _23 = parsed0;
	struct dict_0* _24 = _23->named;
	struct parse_cmd_line_args__lambda0* temp1;
	struct ctx* _25 = ctx;
	uint64_t _26 = sizeof(struct parse_cmd_line_args__lambda0);
	uint8_t* _27 = alloc(_25, _26);
	temp1 = (struct parse_cmd_line_args__lambda0*) _27;
	
	struct parse_cmd_line_args__lambda0* _28 = temp1;
	struct arr_1 _29 = t_names;
	struct cell_3* _30 = help2;
	struct mut_list_3* _31 = values1;
	struct parse_cmd_line_args__lambda0 _32 = (struct parse_cmd_line_args__lambda0) {_29, _30, _31};
	*_28 = _32;
	struct parse_cmd_line_args__lambda0* _33 = temp1;
	struct fun_act2_0 _34 = (struct fun_act2_0) {0, .as0 = _33};
	each_0(_22, _24, _34);
	struct cell_3* _35 = help2;
	uint8_t _36 = get_3(_35);
	if (_36) {
		struct none _37 = (struct none) {};
		return (struct opt_6) {0, .as0 = _37};
	} else {
		struct ctx* _38 = ctx;
		struct fun1_2 _39 = make_t;
		struct mut_list_3* _40 = values1;
		struct arr_5 _41 = move_to_arr_2(_40);
		struct test_options _42 = call_11(_38, _39, _41);
		struct some_6 _43 = (struct some_6) {_42};
		return (struct opt_6) {1, .as1 = _43};
	}
}
/* parse-cmd-line-args-dynamic parsed-cmd-line-args(args arr<arr<char>>) */
struct parsed_cmd_line_args* parse_cmd_line_args_dynamic(struct ctx* ctx, struct arr_1 args) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = args;
	struct void_ _2 = (struct void_) {};
	struct fun_act1_6 _3 = (struct fun_act1_6) {0, .as0 = _2};
	struct opt_5 _4 = find_index(_0, _1, _3);
	switch (_4.kind) {
		case 0: {
			struct parsed_cmd_line_args* temp0;
			struct ctx* _5 = ctx;
			uint64_t _6 = sizeof(struct parsed_cmd_line_args);
			uint8_t* _7 = alloc(_5, _6);
			temp0 = (struct parsed_cmd_line_args*) _7;
			
			struct parsed_cmd_line_args* _8 = temp0;
			struct arr_1 _9 = args;
			struct ctx* _10 = ctx;
			struct dict_0* _11 = empty_dict(_10);
			struct arr_1 _12 = empty_arr_1();
			struct parsed_cmd_line_args _13 = (struct parsed_cmd_line_args) {_9, _11, _12};
			*_8 = _13;
			return temp0;
		}
		case 1: {
			struct some_5 s0 = _4.as1;
			
			uint64_t first_named_arg_index1;
			struct some_5 _14 = s0;
			first_named_arg_index1 = _14.value;
			
			struct arr_1 nameless2;
			struct ctx* _15 = ctx;
			struct arr_1 _16 = args;
			uint64_t _17 = first_named_arg_index1;
			nameless2 = slice_up_to_0(_15, _16, _17);
			
			struct arr_1 rest3;
			struct ctx* _18 = ctx;
			struct arr_1 _19 = args;
			uint64_t _20 = first_named_arg_index1;
			rest3 = slice_starting_at_2(_18, _19, _20);
			
			struct ctx* _21 = ctx;
			struct arr_1 _22 = rest3;
			struct void_ _23 = (struct void_) {};
			struct fun_act1_6 _24 = (struct fun_act1_6) {1, .as1 = _23};
			struct opt_5 _25 = find_index(_21, _22, _24);
			switch (_25.kind) {
				case 0: {
					struct parsed_cmd_line_args* temp1;
					struct ctx* _26 = ctx;
					uint64_t _27 = sizeof(struct parsed_cmd_line_args);
					uint8_t* _28 = alloc(_26, _27);
					temp1 = (struct parsed_cmd_line_args*) _28;
					
					struct parsed_cmd_line_args* _29 = temp1;
					struct arr_1 _30 = nameless2;
					struct ctx* _31 = ctx;
					struct arr_1 _32 = rest3;
					struct dict_0* _33 = parse_named_args(_31, _32);
					struct arr_1 _34 = empty_arr_1();
					struct parsed_cmd_line_args _35 = (struct parsed_cmd_line_args) {_30, _33, _34};
					*_29 = _35;
					return temp1;
				}
				case 1: {
					struct some_5 s24 = _25.as1;
					
					uint64_t sep_index5;
					struct some_5 _36 = s24;
					sep_index5 = _36.value;
					
					struct dict_0* named_args6;
					struct ctx* _37 = ctx;
					struct ctx* _38 = ctx;
					struct arr_1 _39 = rest3;
					uint64_t _40 = sep_index5;
					struct arr_1 _41 = slice_up_to_0(_38, _39, _40);
					named_args6 = parse_named_args(_37, _41);
					
					struct parsed_cmd_line_args* temp2;
					struct ctx* _42 = ctx;
					uint64_t _43 = sizeof(struct parsed_cmd_line_args);
					uint8_t* _44 = alloc(_42, _43);
					temp2 = (struct parsed_cmd_line_args*) _44;
					
					struct parsed_cmd_line_args* _45 = temp2;
					struct arr_1 _46 = nameless2;
					struct dict_0* _47 = named_args6;
					struct ctx* _48 = ctx;
					struct arr_1 _49 = rest3;
					uint64_t _50 = sep_index5;
					struct arr_1 _51 = slice_after_0(_48, _49, _50);
					struct parsed_cmd_line_args _52 = (struct parsed_cmd_line_args) {_46, _47, _51};
					*_45 = _52;
					return temp2;
				}
				default:
					return (assert(0),NULL);
			}
		}
		default:
			return (assert(0),NULL);
	}
}
/* find-index<arr<char>> opt<nat>(a arr<arr<char>>, pred fun-act1<bool, arr<char>>) */
struct opt_5 find_index(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 pred) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	uint64_t _2 = 0u;
	struct fun_act1_6 _3 = pred;
	return find_index_recur(_0, _1, _2, _3);
}
/* find-index-recur<?t> opt<nat>(a arr<arr<char>>, index nat, pred fun-act1<bool, arr<char>>) */
struct opt_5 find_index_recur(struct ctx* ctx, struct arr_1 a, uint64_t index, struct fun_act1_6 pred) {
	top:;
	uint64_t _0 = index;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		struct none _4 = (struct none) {};
		return (struct opt_5) {0, .as0 = _4};
	} else {
		struct ctx* _5 = ctx;
		struct fun_act1_6 _6 = pred;
		struct ctx* _7 = ctx;
		struct arr_1 _8 = a;
		uint64_t _9 = index;
		struct arr_0 _10 = at_2(_7, _8, _9);
		uint8_t _11 = call_8(_5, _6, _10);
		if (_11) {
			uint64_t _12 = index;
			struct some_5 _13 = (struct some_5) {_12};
			return (struct opt_5) {1, .as1 = _13};
		} else {
			struct arr_1 _14 = a;
			struct ctx* _15 = ctx;
			uint64_t _16 = index;
			uint64_t _17 = incr_3(_15, _16);
			struct fun_act1_6 _18 = pred;
			a = _14;
			index = _17;
			pred = _18;
			goto top;
		}
	}
}
/* call<bool, ?t> bool(a fun-act1<bool, arr<char>>, p0 arr<char>) */
uint8_t call_8(struct ctx* ctx, struct fun_act1_6 a, struct arr_0 p0) {
	struct fun_act1_6 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_316(_0, _1, _2);
}
/* call-w-ctx<bool, arr<char>> (generated) (generated) */
uint8_t call_w_ctx_316(struct fun_act1_6 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_6 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			struct arr_0 _3 = p0;
			return parse_cmd_line_args_dynamic__lambda0(_1, _2, _3);
		}
		case 1: {
			struct void_ closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct void_ _5 = closure1;
			struct arr_0 _6 = p0;
			return parse_cmd_line_args_dynamic__lambda1(_4, _5, _6);
		}
		case 2: {
			struct void_ closure2 = _0.as2;
			
			struct ctx* _7 = ctx;
			struct void_ _8 = closure2;
			struct arr_0 _9 = p0;
			return parse_named_args_recur__lambda0(_7, _8, _9);
		}
		case 3: {
			struct index_of__lambda0* closure3 = _0.as3;
			
			struct ctx* _10 = ctx;
			struct index_of__lambda0* _11 = closure3;
			struct arr_0 _12 = p0;
			return index_of__lambda0(_10, _11, _12);
		}
		case 4: {
			struct void_ closure4 = _0.as4;
			
			struct ctx* _13 = ctx;
			struct void_ _14 = closure4;
			struct arr_0 _15 = p0;
			return list_tests__lambda0(_13, _14, _15);
		}
		case 5: {
			struct excluded_from_lint__q__lambda0* closure5 = _0.as5;
			
			struct ctx* _16 = ctx;
			struct excluded_from_lint__q__lambda0* _17 = closure5;
			struct arr_0 _18 = p0;
			return excluded_from_lint__q__lambda0(_16, _17, _18);
		}
		case 6: {
			struct void_ closure6 = _0.as6;
			
			struct ctx* _19 = ctx;
			struct void_ _20 = closure6;
			struct arr_0 _21 = p0;
			return list_lintable_files__lambda0(_19, _20, _21);
		}
		default:
			return (assert(0),0);
	}
}
/* at<?t> arr<char>(a arr<arr<char>>, index nat) */
struct arr_0 at_2(struct ctx* ctx, struct arr_1 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_1 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_1 _5 = a;
	uint64_t _6 = index;
	return noctx_at_4(_5, _6);
}
/* noctx-at<?t> arr<char>(a arr<arr<char>>, index nat) */
struct arr_0 noctx_at_4(struct arr_1 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_1 _4 = a;
	struct arr_0* _5 = _4.data;
	uint64_t _6 = index;
	struct arr_0* _7 = _5 + _6;
	return *_7;
}
/* starts-with?<char> bool(a arr<char>, start arr<char>) */
uint8_t starts_with__q(struct ctx* ctx, struct arr_0 a, struct arr_0 start) {
	struct arr_0 _0 = a;
	uint64_t _1 = _0.size;
	struct arr_0 _2 = start;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_greater_equal(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct ctx* _6 = ctx;
		struct arr_0 _7 = a;
		uint64_t _8 = 0u;
		struct arr_0 _9 = start;
		uint64_t _10 = _9.size;
		struct arr_0 _11 = slice_1(_6, _7, _8, _10);
		struct arr_0 _12 = start;
		return arr_eq__q(_5, _11, _12);
	} else {
		return 0;
	}
}
/* arr-eq?<?t> bool(a arr<char>, b arr<char>) */
uint8_t arr_eq__q(struct ctx* ctx, struct arr_0 a, struct arr_0 b) {
	top:;
	struct arr_0 _0 = a;
	uint64_t _1 = _0.size;
	struct arr_0 _2 = b;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct arr_0 _5 = a;
		uint8_t _6 = empty__q_0(_5);
		if (_6) {
			return 1;
		} else {
			struct ctx* _7 = ctx;
			struct arr_0 _8 = a;
			char _9 = first_0(_7, _8);
			struct ctx* _10 = ctx;
			struct arr_0 _11 = b;
			char _12 = first_0(_10, _11);
			uint8_t _13 = _op_equal_equal_3(_9, _12);
			if (_13) {
				struct ctx* _14 = ctx;
				struct arr_0 _15 = a;
				struct arr_0 _16 = tail_1(_14, _15);
				struct ctx* _17 = ctx;
				struct arr_0 _18 = b;
				struct arr_0 _19 = tail_1(_17, _18);
				a = _16;
				b = _19;
				goto top;
			} else {
				return 0;
			}
		}
	} else {
		return 0;
	}
}
/* first<?t> char(a arr<char>) */
char first_0(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	uint8_t _2 = empty__q_0(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_0 _4 = a;
	uint64_t _5 = 0u;
	return at_3(_3, _4, _5);
}
/* at<?t> char(a arr<char>, index nat) */
char at_3(struct ctx* ctx, struct arr_0 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_0 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_0 _5 = a;
	uint64_t _6 = index;
	return noctx_at_5(_5, _6);
}
/* noctx-at<?t> char(a arr<char>, index nat) */
char noctx_at_5(struct arr_0 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_0 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_0 _4 = a;
	char* _5 = _4.data;
	uint64_t _6 = index;
	char* _7 = _5 + _6;
	return *_7;
}
/* tail<?t> arr<char>(a arr<char>) */
struct arr_0 tail_1(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	uint8_t _2 = empty__q_0(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_0 _4 = a;
	uint64_t _5 = 1u;
	return slice_starting_at_1(_3, _4, _5);
}
/* slice-starting-at<?t> arr<char>(a arr<char>, begin nat) */
struct arr_0 slice_starting_at_1(struct ctx* ctx, struct arr_0 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct arr_0 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_0 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct arr_0 _9 = a;
	uint64_t _10 = _9.size;
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_1(_5, _6, _7, _12);
}
/* slice<?t> arr<char>(a arr<char>, begin nat, size nat) */
struct arr_0 slice_1(struct ctx* ctx, struct arr_0 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct arr_0 _5 = a;
	uint64_t _6 = _5.size;
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct arr_0 _9 = a;
	char* _10 = _9.data;
	uint64_t _11 = begin;
	char* _12 = _10 + _11;
	return (struct arr_0) {_8, _12};
}
/* parse-cmd-line-args-dynamic.lambda0 bool(it arr<char>) */
uint8_t parse_cmd_line_args_dynamic__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = it;
	struct arr_0 _2 = (struct arr_0) {2, constantarr_0_18};
	return starts_with__q(_0, _1, _2);
}
/* empty-dict<arr<char>, arr<arr<char>>> dict<arr<char>, arr<arr<char>>>() */
struct dict_0* empty_dict(struct ctx* ctx) {
	struct dict_0* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dict_0);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dict_0*) _2;
	
	struct dict_0* _3 = temp0;
	struct arr_1 _4 = empty_arr_1();
	struct arr_6 _5 = empty_arr_2();
	struct dict_0 _6 = (struct dict_0) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-arr<?k> arr<arr<char>>() */
struct arr_1 empty_arr_1(void) {
	uint64_t _0 = 0u;
	struct arr_0* _1 = NULL;
	return (struct arr_1) {_0, _1};
}
/* empty-arr<?v> arr<arr<arr<char>>>() */
struct arr_6 empty_arr_2(void) {
	uint64_t _0 = 0u;
	struct arr_1* _1 = NULL;
	return (struct arr_6) {_0, _1};
}
/* slice-up-to<arr<char>> arr<arr<char>>(a arr<arr<char>>, size nat) */
struct arr_1 slice_up_to_0(struct ctx* ctx, struct arr_1 a, uint64_t size) {
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct arr_1 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_1 _6 = a;
	uint64_t _7 = 0u;
	uint64_t _8 = size;
	return slice_2(_5, _6, _7, _8);
}
/* slice<?t> arr<arr<char>>(a arr<arr<char>>, begin nat, size nat) */
struct arr_1 slice_2(struct ctx* ctx, struct arr_1 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct arr_1 _5 = a;
	uint64_t _6 = _5.size;
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct arr_1 _9 = a;
	struct arr_0* _10 = _9.data;
	uint64_t _11 = begin;
	struct arr_0* _12 = _10 + _11;
	return (struct arr_1) {_8, _12};
}
/* slice-starting-at<arr<char>> arr<arr<char>>(a arr<arr<char>>, begin nat) */
struct arr_1 slice_starting_at_2(struct ctx* ctx, struct arr_1 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct arr_1 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_1 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct arr_1 _9 = a;
	uint64_t _10 = _9.size;
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_2(_5, _6, _7, _12);
}
/* ==<arr<char>> bool(a arr<char>, b arr<char>) */
uint8_t _op_equal_equal_4(struct arr_0 a, struct arr_0 b) {
	struct arr_0 _0 = a;
	struct arr_0 _1 = b;
	struct comparison _2 = compare_335(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<arr<char>> (generated) (generated) */
struct comparison compare_335(struct arr_0 a, struct arr_0 b) {
	top:;
	struct arr_0 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	uint8_t _3 = _1 == _2;
	if (_3) {
		struct arr_0 _4 = b;
		uint64_t _5 = _4.size;
		uint64_t _6 = 0u;
		uint8_t _7 = _5 == _6;
		if (_7) {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		} else {
			struct less _9 = (struct less) {};
			return (struct comparison) {0, .as0 = _9};
		}
	} else {
		struct arr_0 _10 = b;
		uint64_t _11 = _10.size;
		uint64_t _12 = 0u;
		uint8_t _13 = _11 == _12;
		if (_13) {
			struct greater _14 = (struct greater) {};
			return (struct comparison) {2, .as2 = _14};
		} else {
			struct arr_0 _15 = a;
			char* _16 = _15.data;
			char _17 = *_16;
			struct arr_0 _18 = b;
			char* _19 = _18.data;
			char _20 = *_19;
			struct comparison _21 = compare_193(_17, _20);
			switch (_21.kind) {
				case 0: {
					struct less _22 = (struct less) {};
					return (struct comparison) {0, .as0 = _22};
				}
				case 1: {
					struct arr_0 _23 = a;
					uint64_t _24 = _23.size;
					uint64_t _25 = 1u;
					uint64_t _26 = _24 - _25;
					struct arr_0 _27 = a;
					char* _28 = _27.data;
					uint64_t _29 = 1u;
					char* _30 = _28 + _29;
					struct arr_0 _31 = (struct arr_0) {_26, _30};
					struct arr_0 _32 = b;
					uint64_t _33 = _32.size;
					uint64_t _34 = 1u;
					uint64_t _35 = _33 - _34;
					struct arr_0 _36 = b;
					char* _37 = _36.data;
					uint64_t _38 = 1u;
					char* _39 = _37 + _38;
					struct arr_0 _40 = (struct arr_0) {_35, _39};
					a = _31;
					b = _40;
					goto top;
				}
				case 2: {
					struct greater _41 = (struct greater) {};
					return (struct comparison) {2, .as2 = _41};
				}
				default:
					return (assert(0),(struct comparison) {0});
			}
		}
	}
}
/* parse-cmd-line-args-dynamic.lambda1 bool(it arr<char>) */
uint8_t parse_cmd_line_args_dynamic__lambda1(struct ctx* ctx, struct void_ _closure, struct arr_0 it) {
	struct arr_0 _0 = it;
	struct arr_0 _1 = (struct arr_0) {2, constantarr_0_18};
	return _op_equal_equal_4(_0, _1);
}
/* parse-named-args dict<arr<char>, arr<arr<char>>>(args arr<arr<char>>) */
struct dict_0* parse_named_args(struct ctx* ctx, struct arr_1 args) {
	struct mut_dict_0 res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_dict_0(_0);
	
	struct ctx* _1 = ctx;
	struct arr_1 _2 = args;
	struct mut_dict_0 _3 = res0;
	parse_named_args_recur(_1, _2, _3);
	struct ctx* _4 = ctx;
	struct mut_dict_0 _5 = res0;
	return move_to_dict_0(_4, _5);
}
/* new-mut-dict<arr<char>, arr<arr<char>>> mut-dict<arr<char>, arr<arr<char>>>() */
struct mut_dict_0 new_mut_dict_0(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	struct mut_list_1* _1 = new_mut_list_0(_0);
	struct ctx* _2 = ctx;
	struct mut_list_2* _3 = new_mut_list_1(_2);
	return (struct mut_dict_0) {_1, _3};
}
/* new-mut-list<?k> mut-list<arr<char>>() */
struct mut_list_1* new_mut_list_0(struct ctx* ctx) {
	struct mut_list_1* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct mut_list_1);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct mut_list_1*) _2;
	
	struct mut_list_1* _3 = temp0;
	struct mut_arr_1 _4 = empty_mut_arr_0();
	uint64_t _5 = 0u;
	struct mut_list_1 _6 = (struct mut_list_1) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-mut-arr<?t> mut-arr<arr<char>>() */
struct mut_arr_1 empty_mut_arr_0(void) {
	struct arr_1 _0 = empty_arr_1();
	return (struct mut_arr_1) {_0};
}
/* new-mut-list<?v> mut-list<arr<arr<char>>>() */
struct mut_list_2* new_mut_list_1(struct ctx* ctx) {
	struct mut_list_2* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct mut_list_2);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct mut_list_2*) _2;
	
	struct mut_list_2* _3 = temp0;
	struct mut_arr_2 _4 = empty_mut_arr_1();
	uint64_t _5 = 0u;
	struct mut_list_2 _6 = (struct mut_list_2) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-mut-arr<?t> mut-arr<arr<arr<char>>>() */
struct mut_arr_2 empty_mut_arr_1(void) {
	struct arr_6 _0 = empty_arr_2();
	return (struct mut_arr_2) {_0};
}
/* parse-named-args-recur void(args arr<arr<char>>, builder mut-dict<arr<char>, arr<arr<char>>>) */
struct void_ parse_named_args_recur(struct ctx* ctx, struct arr_1 args, struct mut_dict_0 builder) {
	top:;
	struct arr_0 first_name0;
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_1 _2 = args;
	struct arr_0 _3 = first_1(_1, _2);
	struct arr_0 _4 = (struct arr_0) {2, constantarr_0_18};
	first_name0 = remove_start(_0, _3, _4);
	
	struct arr_1 tl1;
	struct ctx* _5 = ctx;
	struct arr_1 _6 = args;
	tl1 = tail_2(_5, _6);
	
	struct ctx* _7 = ctx;
	struct arr_1 _8 = tl1;
	struct void_ _9 = (struct void_) {};
	struct fun_act1_6 _10 = (struct fun_act1_6) {2, .as2 = _9};
	struct opt_5 _11 = find_index(_7, _8, _10);
	switch (_11.kind) {
		case 0: {
			struct ctx* _12 = ctx;
			struct mut_dict_0 _13 = builder;
			struct arr_0 _14 = first_name0;
			struct arr_1 _15 = tl1;
			return add_0(_12, _13, _14, _15);
		}
		case 1: {
			struct some_5 s2 = _11.as1;
			
			uint64_t next_named_arg_index3;
			struct some_5 _16 = s2;
			next_named_arg_index3 = _16.value;
			
			struct ctx* _17 = ctx;
			struct mut_dict_0 _18 = builder;
			struct arr_0 _19 = first_name0;
			struct ctx* _20 = ctx;
			struct arr_1 _21 = tl1;
			uint64_t _22 = next_named_arg_index3;
			struct arr_1 _23 = slice_up_to_0(_20, _21, _22);
			add_0(_17, _18, _19, _23);
			struct ctx* _24 = ctx;
			struct arr_1 _25 = args;
			uint64_t _26 = next_named_arg_index3;
			struct arr_1 _27 = slice_starting_at_2(_24, _25, _26);
			struct mut_dict_0 _28 = builder;
			args = _27;
			builder = _28;
			goto top;
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* remove-start<char> arr<char>(a arr<char>, start arr<char>) */
struct arr_0 remove_start(struct ctx* ctx, struct arr_0 a, struct arr_0 start) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = a;
	struct arr_0 _3 = start;
	struct opt_8 _4 = try_remove_start(_1, _2, _3);
	return force_0(_0, _4);
}
/* force<arr<?t>> arr<char>(a opt<arr<char>>) */
struct arr_0 force_0(struct ctx* ctx, struct opt_8 a) {
	struct opt_8 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct ctx* _1 = ctx;
			struct arr_0 _2 = (struct arr_0) {27, constantarr_0_19};
			return fail_1(_1, _2);
		}
		case 1: {
			struct some_8 s0 = _0.as1;
			
			struct some_8 _3 = s0;
			return _3.value;
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* fail<?t> arr<char>(reason arr<char>) */
struct arr_0 fail_1(struct ctx* ctx, struct arr_0 reason) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = reason;
	struct exception _2 = (struct exception) {_1};
	return throw_1(_0, _2);
}
/* throw<?t> arr<char>(e exception) */
struct arr_0 throw_1(struct ctx* ctx, struct exception e) {
	struct exception_ctx* exn_ctx0;
	struct ctx* _0 = ctx;
	exn_ctx0 = get_exception_ctx(_0);
	
	struct exception_ctx* _1 = exn_ctx0;
	struct jmp_buf_tag* _2 = _1->jmp_buf_ptr;
	uint8_t _3 = null__q_1(_2);
	hard_forbid(_3);
	struct exception_ctx* _4 = exn_ctx0;
	struct exception _5 = e;
	_4->thrown_exception = _5;
	struct exception_ctx* _6 = exn_ctx0;
	struct jmp_buf_tag* _7 = _6->jmp_buf_ptr;
	struct ctx* _8 = ctx;
	int32_t _9 = number_to_throw(_8);
	(longjmp(_7, _9), (struct void_) {});
	return todo_4();
}
/* todo<?t> arr<char>() */
struct arr_0 todo_4(void) {
	return (assert(0),(struct arr_0) {0, NULL});
}
/* try-remove-start<?t> opt<arr<char>>(a arr<char>, start arr<char>) */
struct opt_8 try_remove_start(struct ctx* ctx, struct arr_0 a, struct arr_0 start) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct arr_0 _2 = start;
	uint8_t _3 = starts_with__q(_0, _1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct arr_0 _5 = a;
		struct arr_0 _6 = start;
		uint64_t _7 = _6.size;
		struct arr_0 _8 = slice_starting_at_1(_4, _5, _7);
		struct some_8 _9 = (struct some_8) {_8};
		return (struct opt_8) {1, .as1 = _9};
	} else {
		struct none _10 = (struct none) {};
		return (struct opt_8) {0, .as0 = _10};
	}
}
/* first<arr<char>> arr<char>(a arr<arr<char>>) */
struct arr_0 first_1(struct ctx* ctx, struct arr_1 a) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	uint8_t _2 = empty__q_5(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_1 _4 = a;
	uint64_t _5 = 0u;
	return at_2(_3, _4, _5);
}
/* empty?<?t> bool(a arr<arr<char>>) */
uint8_t empty__q_5(struct arr_1 a) {
	struct arr_1 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* tail<arr<char>> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 tail_2(struct ctx* ctx, struct arr_1 a) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	uint8_t _2 = empty__q_5(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_1 _4 = a;
	uint64_t _5 = 1u;
	return slice_starting_at_2(_3, _4, _5);
}
/* parse-named-args-recur.lambda0 bool(it arr<char>) */
uint8_t parse_named_args_recur__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = it;
	struct arr_0 _2 = (struct arr_0) {2, constantarr_0_18};
	return starts_with__q(_0, _1, _2);
}
/* add<arr<char>, arr<arr<char>>> void(m mut-dict<arr<char>, arr<arr<char>>>, key arr<char>, value arr<arr<char>>) */
struct void_ add_0(struct ctx* ctx, struct mut_dict_0 m, struct arr_0 key, struct arr_1 value) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct mut_dict_0 _2 = m;
	struct arr_0 _3 = key;
	uint8_t _4 = has__q_1(_1, _2, _3);
	forbid_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_dict_0 _6 = m;
	struct mut_list_1* _7 = _6.keys;
	struct arr_0 _8 = key;
	push_0(_5, _7, _8);
	struct ctx* _9 = ctx;
	struct mut_dict_0 _10 = m;
	struct mut_list_2* _11 = _10.values;
	struct arr_1 _12 = value;
	return push_1(_9, _11, _12);
}
/* has?<?k, ?v> bool(d mut-dict<arr<char>, arr<arr<char>>>, key arr<char>) */
uint8_t has__q_1(struct ctx* ctx, struct mut_dict_0 d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct mut_dict_0 _2 = d;
	struct dict_0* _3 = temp_as_dict_0(_1, _2);
	struct arr_0 _4 = key;
	return has__q_2(_0, _3, _4);
}
/* has?<?k, ?v> bool(d dict<arr<char>, arr<arr<char>>>, key arr<char>) */
uint8_t has__q_2(struct ctx* ctx, struct dict_0* d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct dict_0* _1 = d;
	struct arr_0 _2 = key;
	struct opt_7 _3 = get_2(_0, _1, _2);
	return has__q_3(_3);
}
/* has?<?v> bool(a opt<arr<arr<char>>>) */
uint8_t has__q_3(struct opt_7 a) {
	struct opt_7 _0 = a;
	uint8_t _1 = empty__q_6(_0);
	return !_1;
}
/* empty?<?t> bool(a opt<arr<arr<char>>>) */
uint8_t empty__q_6(struct opt_7 a) {
	struct opt_7 _0 = a;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* get<?v, ?k> opt<arr<arr<char>>>(d dict<arr<char>, arr<arr<char>>>, key arr<char>) */
struct opt_7 get_2(struct ctx* ctx, struct dict_0* d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct dict_0* _1 = d;
	struct arr_1 _2 = _1->keys;
	struct dict_0* _3 = d;
	struct arr_6 _4 = _3->values;
	uint64_t _5 = 0u;
	struct arr_0 _6 = key;
	return get_recursive_0(_0, _2, _4, _5, _6);
}
/* get-recursive<?k, ?v> opt<arr<arr<char>>>(keys arr<arr<char>>, values arr<arr<arr<char>>>, idx nat, key arr<char>) */
struct opt_7 get_recursive_0(struct ctx* ctx, struct arr_1 keys, struct arr_6 values, uint64_t idx, struct arr_0 key) {
	top:;
	uint64_t _0 = idx;
	struct arr_1 _1 = keys;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		struct none _4 = (struct none) {};
		return (struct opt_7) {0, .as0 = _4};
	} else {
		struct arr_0 _5 = key;
		struct ctx* _6 = ctx;
		struct arr_1 _7 = keys;
		uint64_t _8 = idx;
		struct arr_0 _9 = at_2(_6, _7, _8);
		uint8_t _10 = _op_equal_equal_4(_5, _9);
		if (_10) {
			struct ctx* _11 = ctx;
			struct arr_6 _12 = values;
			uint64_t _13 = idx;
			struct arr_1 _14 = at_4(_11, _12, _13);
			struct some_7 _15 = (struct some_7) {_14};
			return (struct opt_7) {1, .as1 = _15};
		} else {
			struct arr_1 _16 = keys;
			struct arr_6 _17 = values;
			struct ctx* _18 = ctx;
			uint64_t _19 = idx;
			uint64_t _20 = incr_3(_18, _19);
			struct arr_0 _21 = key;
			keys = _16;
			values = _17;
			idx = _20;
			key = _21;
			goto top;
		}
	}
}
/* at<?v> arr<arr<char>>(a arr<arr<arr<char>>>, index nat) */
struct arr_1 at_4(struct ctx* ctx, struct arr_6 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_6 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_6 _5 = a;
	uint64_t _6 = index;
	return noctx_at_6(_5, _6);
}
/* noctx-at<?t> arr<arr<char>>(a arr<arr<arr<char>>>, index nat) */
struct arr_1 noctx_at_6(struct arr_6 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_6 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_6 _4 = a;
	struct arr_1* _5 = _4.data;
	uint64_t _6 = index;
	struct arr_1* _7 = _5 + _6;
	return *_7;
}
/* temp-as-dict<?k, ?v> dict<arr<char>, arr<arr<char>>>(m mut-dict<arr<char>, arr<arr<char>>>) */
struct dict_0* temp_as_dict_0(struct ctx* ctx, struct mut_dict_0 m) {
	struct dict_0* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dict_0);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dict_0*) _2;
	
	struct dict_0* _3 = temp0;
	struct mut_dict_0 _4 = m;
	struct mut_list_1* _5 = _4.keys;
	struct arr_1 _6 = temp_as_arr_2(_5);
	struct mut_dict_0 _7 = m;
	struct mut_list_2* _8 = _7.values;
	struct arr_6 _9 = temp_as_arr_4(_8);
	struct dict_0 _10 = (struct dict_0) {_6, _9};
	*_3 = _10;
	return temp0;
}
/* temp-as-arr<?k> arr<arr<char>>(a mut-list<arr<char>>) */
struct arr_1 temp_as_arr_2(struct mut_list_1* a) {
	struct mut_list_1* _0 = a;
	struct mut_arr_1 _1 = temp_as_mut_arr_1(_0);
	return temp_as_arr_3(_1);
}
/* temp-as-arr<?t> arr<arr<char>>(a mut-arr<arr<char>>) */
struct arr_1 temp_as_arr_3(struct mut_arr_1 a) {
	struct mut_arr_1 _0 = a;
	return _0.arr;
}
/* temp-as-mut-arr<?t> mut-arr<arr<char>>(a mut-list<arr<char>>) */
struct mut_arr_1 temp_as_mut_arr_1(struct mut_list_1* a) {
	struct mut_list_1* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_1* _2 = a;
	struct arr_0* _3 = data_3(_2);
	struct arr_1 _4 = (struct arr_1) {_1, _3};
	return (struct mut_arr_1) {_4};
}
/* data<?t> ptr<arr<char>>(a mut-list<arr<char>>) */
struct arr_0* data_3(struct mut_list_1* a) {
	struct mut_list_1* _0 = a;
	struct mut_arr_1 _1 = _0->backing;
	return data_0(_1);
}
/* temp-as-arr<?v> arr<arr<arr<char>>>(a mut-list<arr<arr<char>>>) */
struct arr_6 temp_as_arr_4(struct mut_list_2* a) {
	struct mut_list_2* _0 = a;
	struct mut_arr_2 _1 = temp_as_mut_arr_2(_0);
	return temp_as_arr_5(_1);
}
/* temp-as-arr<?t> arr<arr<arr<char>>>(a mut-arr<arr<arr<char>>>) */
struct arr_6 temp_as_arr_5(struct mut_arr_2 a) {
	struct mut_arr_2 _0 = a;
	return _0.arr;
}
/* temp-as-mut-arr<?t> mut-arr<arr<arr<char>>>(a mut-list<arr<arr<char>>>) */
struct mut_arr_2 temp_as_mut_arr_2(struct mut_list_2* a) {
	struct mut_list_2* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_2* _2 = a;
	struct arr_1* _3 = data_4(_2);
	struct arr_6 _4 = (struct arr_6) {_1, _3};
	return (struct mut_arr_2) {_4};
}
/* data<?t> ptr<arr<arr<char>>>(a mut-list<arr<arr<char>>>) */
struct arr_1* data_4(struct mut_list_2* a) {
	struct mut_list_2* _0 = a;
	struct mut_arr_2 _1 = _0->backing;
	return data_5(_1);
}
/* data<?t> ptr<arr<arr<char>>>(a mut-arr<arr<arr<char>>>) */
struct arr_1* data_5(struct mut_arr_2 a) {
	struct mut_arr_2 _0 = a;
	struct arr_6 _1 = _0.arr;
	return _1.data;
}
/* push<?k> void(a mut-list<arr<char>>, value arr<char>) */
struct void_ push_0(struct ctx* ctx, struct mut_list_1* a, struct arr_0 value) {
	struct mut_list_1* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_1* _2 = a;
	uint64_t _3 = capacity_1(_2);
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct mut_list_1* _6 = a;
		struct mut_list_1* _7 = a;
		uint64_t _8 = _7->size;
		uint64_t _9 = 0u;
		uint8_t _10 = _op_equal_equal_0(_8, _9);uint64_t _11;
		
		if (_10) {
			_11 = 4u;
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_1* _13 = a;
			uint64_t _14 = _13->size;
			uint64_t _15 = 2u;
			_11 = _op_times_0(_12, _14, _15);
		}
		increase_capacity_to_0(_5, _6, _11);
	} else {
		(struct void_) {};
	}
	struct ctx* _16 = ctx;
	struct mut_list_1* _17 = a;
	struct ctx* _18 = ctx;
	struct ctx* _19 = ctx;
	struct mut_list_1* _20 = a;
	uint64_t _21 = _20->size;
	uint64_t _22 = incr_3(_19, _21);
	uint64_t _23 = round_up_to_power_of_two(_18, _22);
	ensure_capacity_0(_16, _17, _23);
	struct ctx* _24 = ctx;
	struct mut_list_1* _25 = a;
	uint64_t _26 = _25->size;
	struct mut_list_1* _27 = a;
	uint64_t _28 = capacity_1(_27);
	uint8_t _29 = _op_less_0(_26, _28);
	assert_0(_24, _29);
	struct mut_list_1* _30 = a;
	struct arr_0* _31 = data_3(_30);
	struct mut_list_1* _32 = a;
	uint64_t _33 = _32->size;
	struct arr_0* _34 = _31 + _33;
	struct arr_0 _35 = value;
	*_34 = _35;
	struct mut_list_1* _36 = a;
	struct ctx* _37 = ctx;
	struct mut_list_1* _38 = a;
	uint64_t _39 = _38->size;
	uint64_t _40 = incr_3(_37, _39);
	return (_36->size = _40, (struct void_) {});
}
/* capacity<?t> nat(a mut-list<arr<char>>) */
uint64_t capacity_1(struct mut_list_1* a) {
	struct mut_list_1* _0 = a;
	struct mut_arr_1 _1 = _0->backing;
	return size_1(_1);
}
/* increase-capacity-to<?t> void(a mut-list<arr<char>>, new-capacity nat) */
struct void_ increase_capacity_to_0(struct ctx* ctx, struct mut_list_1* a, uint64_t new_capacity) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_capacity;
	struct mut_list_1* _2 = a;
	uint64_t _3 = capacity_1(_2);
	uint8_t _4 = _op_greater(_1, _3);
	assert_0(_0, _4);
	struct arr_0* old_data0;
	struct mut_list_1* _5 = a;
	old_data0 = data_3(_5);
	
	struct mut_list_1* _6 = a;
	uint64_t _7 = new_capacity;
	struct ctx* _8 = ctx;
	uint64_t _9 = new_capacity;
	struct arr_0* _10 = uninitialized_data_1(_8, _9);
	struct mut_arr_1 _11 = mut_arr_1(_7, _10);
	_6->backing = _11;
	struct ctx* _12 = ctx;
	struct mut_list_1* _13 = a;
	struct arr_0* _14 = data_3(_13);
	struct arr_0* _15 = old_data0;
	struct mut_list_1* _16 = a;
	uint64_t _17 = _16->size;
	copy_data_from_1(_12, _14, _15, _17);
	struct ctx* _18 = ctx;
	struct mut_list_1* _19 = a;
	struct mut_arr_1 _20 = _19->backing;
	struct mut_list_1* _21 = a;
	uint64_t _22 = _21->size;
	struct mut_arr_1 _23 = slice_starting_at_3(_18, _20, _22);
	return set_zero_elements_0(_23);
}
/* copy-data-from<?t> void(to ptr<arr<char>>, from ptr<arr<char>>, len nat) */
struct void_ copy_data_from_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len) {
	top:;
	uint64_t _0 = len;
	uint64_t _1 = 8u;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		struct arr_0* _4 = to;
		struct arr_0* _5 = from;
		uint64_t _6 = len;
		return copy_data_from_small_1(_3, _4, _5, _6);
	} else {
		uint64_t hl0;
		struct ctx* _7 = ctx;
		uint64_t _8 = len;
		uint64_t _9 = 2u;
		hl0 = _op_div(_7, _8, _9);
		
		struct ctx* _10 = ctx;
		struct arr_0* _11 = to;
		struct arr_0* _12 = from;
		uint64_t _13 = hl0;
		copy_data_from_1(_10, _11, _12, _13);
		struct arr_0* _14 = to;
		uint64_t _15 = hl0;
		struct arr_0* _16 = _14 + _15;
		struct arr_0* _17 = from;
		uint64_t _18 = hl0;
		struct arr_0* _19 = _17 + _18;
		struct ctx* _20 = ctx;
		uint64_t _21 = len;
		uint64_t _22 = hl0;
		uint64_t _23 = _op_minus_2(_20, _21, _22);
		to = _16;
		from = _19;
		len = _23;
		goto top;
	}
}
/* copy-data-from-small<?t> void(to ptr<arr<char>>, from ptr<arr<char>>, len nat) */
struct void_ copy_data_from_small_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len) {
	uint64_t _0 = len;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		struct arr_0* _3 = to;
		struct arr_0* _4 = from;
		struct arr_0 _5 = *_4;
		*_3 = _5;
		struct ctx* _6 = ctx;
		struct arr_0* _7 = to;
		struct arr_0* _8 = incr_4(_7);
		struct arr_0* _9 = from;
		struct arr_0* _10 = incr_4(_9);
		struct ctx* _11 = ctx;
		uint64_t _12 = len;
		uint64_t _13 = decr(_11, _12);
		return copy_data_from_1(_6, _8, _10, _13);
	} else {
		return (struct void_) {};
	}
}
/* incr<?t> ptr<arr<char>>(p ptr<arr<char>>) */
struct arr_0* incr_4(struct arr_0* p) {
	struct arr_0* _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* set-zero-elements<?t> void(a mut-arr<arr<char>>) */
struct void_ set_zero_elements_0(struct mut_arr_1 a) {
	struct mut_arr_1 _0 = a;
	struct arr_0* _1 = data_0(_0);
	struct mut_arr_1 _2 = a;
	uint64_t _3 = size_1(_2);
	return set_zero_range_1(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<arr<char>>, size nat) */
struct void_ set_zero_range_1(struct arr_0* begin, uint64_t size) {
	struct arr_0* _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(struct arr_0);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* slice-starting-at<?t> mut-arr<arr<char>>(a mut-arr<arr<char>>, begin nat) */
struct mut_arr_1 slice_starting_at_3(struct ctx* ctx, struct mut_arr_1 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct mut_arr_1 _2 = a;
	uint64_t _3 = size_1(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_arr_1 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct mut_arr_1 _9 = a;
	uint64_t _10 = size_1(_9);
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_3(_5, _6, _7, _12);
}
/* slice<?t> mut-arr<arr<char>>(a mut-arr<arr<char>>, begin nat, size nat) */
struct mut_arr_1 slice_3(struct ctx* ctx, struct mut_arr_1 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct mut_arr_1 _5 = a;
	uint64_t _6 = size_1(_5);
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct mut_arr_1 _9 = a;
	struct arr_0* _10 = data_0(_9);
	uint64_t _11 = begin;
	struct arr_0* _12 = _10 + _11;
	return mut_arr_1(_8, _12);
}
/* * nat(a nat, b nat) */
uint64_t _op_times_0(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint64_t _0 = a;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_equal_equal_0(_0, _1);uint8_t _3;
	
	if (_2) {
		_3 = 1;
	} else {
		uint64_t _4 = b;
		uint64_t _5 = 0u;
		_3 = _op_equal_equal_0(_4, _5);
	}
	if (_3) {
		return 0u;
	} else {
		uint64_t res0;
		uint64_t _6 = a;
		uint64_t _7 = b;
		res0 = _6 * _7;
		
		struct ctx* _8 = ctx;
		struct ctx* _9 = ctx;
		uint64_t _10 = res0;
		uint64_t _11 = b;
		uint64_t _12 = _op_div(_9, _10, _11);
		uint64_t _13 = a;
		uint8_t _14 = _op_equal_equal_0(_12, _13);
		assert_0(_8, _14);
		struct ctx* _15 = ctx;
		struct ctx* _16 = ctx;
		uint64_t _17 = res0;
		uint64_t _18 = a;
		uint64_t _19 = _op_div(_16, _17, _18);
		uint64_t _20 = b;
		uint8_t _21 = _op_equal_equal_0(_19, _20);
		assert_0(_15, _21);
		return res0;
	}
}
/* ensure-capacity<?t> void(a mut-list<arr<char>>, capacity nat) */
struct void_ ensure_capacity_0(struct ctx* ctx, struct mut_list_1* a, uint64_t capacity) {
	struct mut_list_1* _0 = a;
	uint64_t _1 = capacity_1(_0);
	uint64_t _2 = capacity;
	uint8_t _3 = _op_less_0(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_1* _5 = a;
		struct ctx* _6 = ctx;
		uint64_t _7 = capacity;
		uint64_t _8 = round_up_to_power_of_two(_6, _7);
		return increase_capacity_to_0(_4, _5, _8);
	} else {
		return (struct void_) {};
	}
}
/* round-up-to-power-of-two nat(n nat) */
uint64_t round_up_to_power_of_two(struct ctx* ctx, uint64_t n) {
	struct ctx* _0 = ctx;
	uint64_t _1 = 1u;
	uint64_t _2 = n;
	return round_up_to_power_of_two_recur(_0, _1, _2);
}
/* round-up-to-power-of-two-recur nat(acc nat, n nat) */
uint64_t round_up_to_power_of_two_recur(struct ctx* ctx, uint64_t acc, uint64_t n) {
	top:;
	uint64_t _0 = acc;
	uint64_t _1 = n;
	uint8_t _2 = _op_greater_equal(_0, _1);
	if (_2) {
		return acc;
	} else {
		struct ctx* _3 = ctx;
		uint64_t _4 = acc;
		uint64_t _5 = 2u;
		uint64_t _6 = _op_times_0(_3, _4, _5);
		uint64_t _7 = n;
		acc = _6;
		n = _7;
		goto top;
	}
}
/* push<?v> void(a mut-list<arr<arr<char>>>, value arr<arr<char>>) */
struct void_ push_1(struct ctx* ctx, struct mut_list_2* a, struct arr_1 value) {
	struct mut_list_2* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_2* _2 = a;
	uint64_t _3 = capacity_2(_2);
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct mut_list_2* _6 = a;
		struct mut_list_2* _7 = a;
		uint64_t _8 = _7->size;
		uint64_t _9 = 0u;
		uint8_t _10 = _op_equal_equal_0(_8, _9);uint64_t _11;
		
		if (_10) {
			_11 = 4u;
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_2* _13 = a;
			uint64_t _14 = _13->size;
			uint64_t _15 = 2u;
			_11 = _op_times_0(_12, _14, _15);
		}
		increase_capacity_to_1(_5, _6, _11);
	} else {
		(struct void_) {};
	}
	struct ctx* _16 = ctx;
	struct mut_list_2* _17 = a;
	struct ctx* _18 = ctx;
	struct ctx* _19 = ctx;
	struct mut_list_2* _20 = a;
	uint64_t _21 = _20->size;
	uint64_t _22 = incr_3(_19, _21);
	uint64_t _23 = round_up_to_power_of_two(_18, _22);
	ensure_capacity_1(_16, _17, _23);
	struct ctx* _24 = ctx;
	struct mut_list_2* _25 = a;
	uint64_t _26 = _25->size;
	struct mut_list_2* _27 = a;
	uint64_t _28 = capacity_2(_27);
	uint8_t _29 = _op_less_0(_26, _28);
	assert_0(_24, _29);
	struct mut_list_2* _30 = a;
	struct arr_1* _31 = data_4(_30);
	struct mut_list_2* _32 = a;
	uint64_t _33 = _32->size;
	struct arr_1* _34 = _31 + _33;
	struct arr_1 _35 = value;
	*_34 = _35;
	struct mut_list_2* _36 = a;
	struct ctx* _37 = ctx;
	struct mut_list_2* _38 = a;
	uint64_t _39 = _38->size;
	uint64_t _40 = incr_3(_37, _39);
	return (_36->size = _40, (struct void_) {});
}
/* capacity<?t> nat(a mut-list<arr<arr<char>>>) */
uint64_t capacity_2(struct mut_list_2* a) {
	struct mut_list_2* _0 = a;
	struct mut_arr_2 _1 = _0->backing;
	return size_3(_1);
}
/* size<?t> nat(a mut-arr<arr<arr<char>>>) */
uint64_t size_3(struct mut_arr_2 a) {
	struct mut_arr_2 _0 = a;
	struct arr_6 _1 = _0.arr;
	return _1.size;
}
/* increase-capacity-to<?t> void(a mut-list<arr<arr<char>>>, new-capacity nat) */
struct void_ increase_capacity_to_1(struct ctx* ctx, struct mut_list_2* a, uint64_t new_capacity) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_capacity;
	struct mut_list_2* _2 = a;
	uint64_t _3 = capacity_2(_2);
	uint8_t _4 = _op_greater(_1, _3);
	assert_0(_0, _4);
	struct arr_1* old_data0;
	struct mut_list_2* _5 = a;
	old_data0 = data_4(_5);
	
	struct mut_list_2* _6 = a;
	uint64_t _7 = new_capacity;
	struct ctx* _8 = ctx;
	uint64_t _9 = new_capacity;
	struct arr_1* _10 = uninitialized_data_2(_8, _9);
	struct mut_arr_2 _11 = mut_arr_2(_7, _10);
	_6->backing = _11;
	struct ctx* _12 = ctx;
	struct mut_list_2* _13 = a;
	struct arr_1* _14 = data_4(_13);
	struct arr_1* _15 = old_data0;
	struct mut_list_2* _16 = a;
	uint64_t _17 = _16->size;
	copy_data_from_2(_12, _14, _15, _17);
	struct ctx* _18 = ctx;
	struct mut_list_2* _19 = a;
	struct mut_arr_2 _20 = _19->backing;
	struct mut_list_2* _21 = a;
	uint64_t _22 = _21->size;
	struct mut_arr_2 _23 = slice_starting_at_4(_18, _20, _22);
	return set_zero_elements_1(_23);
}
/* mut-arr<?t> mut-arr<arr<arr<char>>>(size nat, data ptr<arr<arr<char>>>) */
struct mut_arr_2 mut_arr_2(uint64_t size, struct arr_1* data) {
	uint64_t _0 = size;
	struct arr_1* _1 = data;
	struct arr_6 _2 = (struct arr_6) {_0, _1};
	return (struct mut_arr_2) {_2};
}
/* uninitialized-data<?t> ptr<arr<arr<char>>>(size nat) */
struct arr_1* uninitialized_data_2(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(struct arr_1);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (struct arr_1*) _4;
}
/* copy-data-from<?t> void(to ptr<arr<arr<char>>>, from ptr<arr<arr<char>>>, len nat) */
struct void_ copy_data_from_2(struct ctx* ctx, struct arr_1* to, struct arr_1* from, uint64_t len) {
	top:;
	uint64_t _0 = len;
	uint64_t _1 = 8u;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		struct arr_1* _4 = to;
		struct arr_1* _5 = from;
		uint64_t _6 = len;
		return copy_data_from_small_2(_3, _4, _5, _6);
	} else {
		uint64_t hl0;
		struct ctx* _7 = ctx;
		uint64_t _8 = len;
		uint64_t _9 = 2u;
		hl0 = _op_div(_7, _8, _9);
		
		struct ctx* _10 = ctx;
		struct arr_1* _11 = to;
		struct arr_1* _12 = from;
		uint64_t _13 = hl0;
		copy_data_from_2(_10, _11, _12, _13);
		struct arr_1* _14 = to;
		uint64_t _15 = hl0;
		struct arr_1* _16 = _14 + _15;
		struct arr_1* _17 = from;
		uint64_t _18 = hl0;
		struct arr_1* _19 = _17 + _18;
		struct ctx* _20 = ctx;
		uint64_t _21 = len;
		uint64_t _22 = hl0;
		uint64_t _23 = _op_minus_2(_20, _21, _22);
		to = _16;
		from = _19;
		len = _23;
		goto top;
	}
}
/* copy-data-from-small<?t> void(to ptr<arr<arr<char>>>, from ptr<arr<arr<char>>>, len nat) */
struct void_ copy_data_from_small_2(struct ctx* ctx, struct arr_1* to, struct arr_1* from, uint64_t len) {
	uint64_t _0 = len;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		struct arr_1* _3 = to;
		struct arr_1* _4 = from;
		struct arr_1 _5 = *_4;
		*_3 = _5;
		struct ctx* _6 = ctx;
		struct arr_1* _7 = to;
		struct arr_1* _8 = incr_5(_7);
		struct arr_1* _9 = from;
		struct arr_1* _10 = incr_5(_9);
		struct ctx* _11 = ctx;
		uint64_t _12 = len;
		uint64_t _13 = decr(_11, _12);
		return copy_data_from_2(_6, _8, _10, _13);
	} else {
		return (struct void_) {};
	}
}
/* incr<?t> ptr<arr<arr<char>>>(p ptr<arr<arr<char>>>) */
struct arr_1* incr_5(struct arr_1* p) {
	struct arr_1* _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* set-zero-elements<?t> void(a mut-arr<arr<arr<char>>>) */
struct void_ set_zero_elements_1(struct mut_arr_2 a) {
	struct mut_arr_2 _0 = a;
	struct arr_1* _1 = data_5(_0);
	struct mut_arr_2 _2 = a;
	uint64_t _3 = size_3(_2);
	return set_zero_range_2(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<arr<arr<char>>>, size nat) */
struct void_ set_zero_range_2(struct arr_1* begin, uint64_t size) {
	struct arr_1* _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(struct arr_1);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* slice-starting-at<?t> mut-arr<arr<arr<char>>>(a mut-arr<arr<arr<char>>>, begin nat) */
struct mut_arr_2 slice_starting_at_4(struct ctx* ctx, struct mut_arr_2 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct mut_arr_2 _2 = a;
	uint64_t _3 = size_3(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_arr_2 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct mut_arr_2 _9 = a;
	uint64_t _10 = size_3(_9);
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_4(_5, _6, _7, _12);
}
/* slice<?t> mut-arr<arr<arr<char>>>(a mut-arr<arr<arr<char>>>, begin nat, size nat) */
struct mut_arr_2 slice_4(struct ctx* ctx, struct mut_arr_2 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct mut_arr_2 _5 = a;
	uint64_t _6 = size_3(_5);
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct mut_arr_2 _9 = a;
	struct arr_1* _10 = data_5(_9);
	uint64_t _11 = begin;
	struct arr_1* _12 = _10 + _11;
	return mut_arr_2(_8, _12);
}
/* ensure-capacity<?t> void(a mut-list<arr<arr<char>>>, capacity nat) */
struct void_ ensure_capacity_1(struct ctx* ctx, struct mut_list_2* a, uint64_t capacity) {
	struct mut_list_2* _0 = a;
	uint64_t _1 = capacity_2(_0);
	uint64_t _2 = capacity;
	uint8_t _3 = _op_less_0(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_2* _5 = a;
		struct ctx* _6 = ctx;
		uint64_t _7 = capacity;
		uint64_t _8 = round_up_to_power_of_two(_6, _7);
		return increase_capacity_to_1(_4, _5, _8);
	} else {
		return (struct void_) {};
	}
}
/* move-to-dict<arr<char>, arr<arr<char>>> dict<arr<char>, arr<arr<char>>>(m mut-dict<arr<char>, arr<arr<char>>>) */
struct dict_0* move_to_dict_0(struct ctx* ctx, struct mut_dict_0 m) {
	struct dict_0* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dict_0);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dict_0*) _2;
	
	struct dict_0* _3 = temp0;
	struct mut_dict_0 _4 = m;
	struct mut_list_1* _5 = _4.keys;
	struct arr_1 _6 = move_to_arr_0(_5);
	struct mut_dict_0 _7 = m;
	struct mut_list_2* _8 = _7.values;
	struct arr_6 _9 = move_to_arr_1(_8);
	struct dict_0 _10 = (struct dict_0) {_6, _9};
	*_3 = _10;
	return temp0;
}
/* move-to-arr<?k> arr<arr<char>>(a mut-list<arr<char>>) */
struct arr_1 move_to_arr_0(struct mut_list_1* a) {
	struct arr_1 res0;
	struct mut_list_1* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_1* _2 = a;
	struct arr_0* _3 = data_3(_2);
	res0 = (struct arr_1) {_1, _3};
	
	struct mut_list_1* _4 = a;
	struct mut_arr_1 _5 = empty_mut_arr_0();
	_4->backing = _5;
	struct mut_list_1* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* move-to-arr<?v> arr<arr<arr<char>>>(a mut-list<arr<arr<char>>>) */
struct arr_6 move_to_arr_1(struct mut_list_2* a) {
	struct arr_6 res0;
	struct mut_list_2* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_2* _2 = a;
	struct arr_1* _3 = data_4(_2);
	res0 = (struct arr_6) {_1, _3};
	
	struct mut_list_2* _4 = a;
	struct mut_arr_2 _5 = empty_mut_arr_1();
	_4->backing = _5;
	struct mut_list_2* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* slice-after<arr<char>> arr<arr<char>>(a arr<arr<char>>, before-begin nat) */
struct arr_1 slice_after_0(struct ctx* ctx, struct arr_1 a, uint64_t before_begin) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	struct ctx* _2 = ctx;
	uint64_t _3 = before_begin;
	uint64_t _4 = incr_3(_2, _3);
	return slice_starting_at_2(_0, _1, _4);
}
/* fill-mut-list<opt<arr<arr<char>>>> mut-list<opt<arr<arr<char>>>>(size nat, value opt<arr<arr<char>>>) */
struct mut_list_3* fill_mut_list(struct ctx* ctx, uint64_t size, struct opt_7 value) {
	struct mut_arr_3 backing0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct opt_7 _2 = value;
	backing0 = fill_mut_arr(_0, _1, _2);
	
	struct mut_list_3* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct mut_list_3);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct mut_list_3*) _5;
	
	struct mut_list_3* _6 = temp0;
	struct mut_arr_3 _7 = backing0;
	uint64_t _8 = size;
	struct mut_list_3 _9 = (struct mut_list_3) {_7, _8};
	*_6 = _9;
	return temp0;
}
/* fill-mut-arr<?t> mut-arr<opt<arr<arr<char>>>>(size nat, value opt<arr<arr<char>>>) */
struct mut_arr_3 fill_mut_arr(struct ctx* ctx, uint64_t size, struct opt_7 value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct fill_mut_arr__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct fill_mut_arr__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct fill_mut_arr__lambda0*) _4;
	
	struct fill_mut_arr__lambda0* _5 = temp0;
	struct opt_7 _6 = value;
	struct fill_mut_arr__lambda0 _7 = (struct fill_mut_arr__lambda0) {_6};
	*_5 = _7;
	struct fill_mut_arr__lambda0* _8 = temp0;
	struct fun_act1_7 _9 = (struct fun_act1_7) {0, .as0 = _8};
	return make_mut_arr_1(_0, _1, _9);
}
/* make-mut-arr<?t> mut-arr<opt<arr<arr<char>>>>(size nat, f fun-act1<opt<arr<arr<char>>>, nat>) */
struct mut_arr_3 make_mut_arr_1(struct ctx* ctx, uint64_t size, struct fun_act1_7 f) {
	struct mut_arr_3 res0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	res0 = new_uninitialized_mut_arr_1(_0, _1);
	
	struct ctx* _2 = ctx;
	struct mut_arr_3 _3 = res0;
	uint64_t _4 = 0u;
	struct fun_act1_7 _5 = f;
	make_mut_arr_worker_1(_2, _3, _4, _5);
	return res0;
}
/* new-uninitialized-mut-arr<?t> mut-arr<opt<arr<arr<char>>>>(size nat) */
struct mut_arr_3 new_uninitialized_mut_arr_1(struct ctx* ctx, uint64_t size) {
	uint64_t _0 = size;
	struct ctx* _1 = ctx;
	uint64_t _2 = size;
	struct opt_7* _3 = uninitialized_data_3(_1, _2);
	return mut_arr_3(_0, _3);
}
/* mut-arr<?t> mut-arr<opt<arr<arr<char>>>>(size nat, data ptr<opt<arr<arr<char>>>>) */
struct mut_arr_3 mut_arr_3(uint64_t size, struct opt_7* data) {
	uint64_t _0 = size;
	struct opt_7* _1 = data;
	struct arr_5 _2 = (struct arr_5) {_0, _1};
	return (struct mut_arr_3) {_2};
}
/* uninitialized-data<?t> ptr<opt<arr<arr<char>>>>(size nat) */
struct opt_7* uninitialized_data_3(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(struct opt_7);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (struct opt_7*) _4;
}
/* make-mut-arr-worker<?t> void(a mut-arr<opt<arr<arr<char>>>>, i nat, f fun-act1<opt<arr<arr<char>>>, nat>) */
struct void_ make_mut_arr_worker_1(struct ctx* ctx, struct mut_arr_3 a, uint64_t i, struct fun_act1_7 f) {
	top:;
	uint64_t _0 = i;
	struct mut_arr_3 _1 = a;
	uint64_t _2 = size_4(_1);
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_arr_3 _5 = a;
		uint64_t _6 = i;
		struct ctx* _7 = ctx;
		struct fun_act1_7 _8 = f;
		uint64_t _9 = i;
		struct opt_7 _10 = call_9(_7, _8, _9);
		set_at_1(_4, _5, _6, _10);
		struct mut_arr_3 _11 = a;
		struct ctx* _12 = ctx;
		uint64_t _13 = i;
		uint64_t _14 = incr_3(_12, _13);
		struct fun_act1_7 _15 = f;
		a = _11;
		i = _14;
		f = _15;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* size<?t> nat(a mut-arr<opt<arr<arr<char>>>>) */
uint64_t size_4(struct mut_arr_3 a) {
	struct mut_arr_3 _0 = a;
	struct arr_5 _1 = _0.arr;
	return _1.size;
}
/* set-at<?t> void(a mut-arr<opt<arr<arr<char>>>>, index nat, value opt<arr<arr<char>>>) */
struct void_ set_at_1(struct ctx* ctx, struct mut_arr_3 a, uint64_t index, struct opt_7 value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_arr_3 _2 = a;
	uint64_t _3 = size_4(_2);
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_arr_3 _5 = a;
	uint64_t _6 = index;
	struct opt_7 _7 = value;
	return noctx_set_at_2(_5, _6, _7);
}
/* noctx-set-at<?t> void(a mut-arr<opt<arr<arr<char>>>>, index nat, value opt<arr<arr<char>>>) */
struct void_ noctx_set_at_2(struct mut_arr_3 a, uint64_t index, struct opt_7 value) {
	uint64_t _0 = index;
	struct mut_arr_3 _1 = a;
	uint64_t _2 = size_4(_1);
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_arr_3 _4 = a;
	struct opt_7* _5 = data_6(_4);
	uint64_t _6 = index;
	struct opt_7* _7 = _5 + _6;
	struct opt_7 _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* data<?t> ptr<opt<arr<arr<char>>>>(a mut-arr<opt<arr<arr<char>>>>) */
struct opt_7* data_6(struct mut_arr_3 a) {
	struct mut_arr_3 _0 = a;
	struct arr_5 _1 = _0.arr;
	return _1.data;
}
/* call<?t, nat> opt<arr<arr<char>>>(a fun-act1<opt<arr<arr<char>>>, nat>, p0 nat) */
struct opt_7 call_9(struct ctx* ctx, struct fun_act1_7 a, uint64_t p0) {
	struct fun_act1_7 _0 = a;
	struct ctx* _1 = ctx;
	uint64_t _2 = p0;
	return call_w_ctx_417(_0, _1, _2);
}
/* call-w-ctx<opt<arr<arr<char>>>, nat-64> (generated) (generated) */
struct opt_7 call_w_ctx_417(struct fun_act1_7 a, struct ctx* ctx, uint64_t p0) {
	struct fun_act1_7 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct fill_mut_arr__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct fill_mut_arr__lambda0* _2 = closure0;
			uint64_t _3 = p0;
			return fill_mut_arr__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct opt_7) {0});
	}
}
/* fill-mut-arr<?t>.lambda0 opt<arr<arr<char>>>(ignore nat) */
struct opt_7 fill_mut_arr__lambda0(struct ctx* ctx, struct fill_mut_arr__lambda0* _closure, uint64_t ignore) {
	struct fill_mut_arr__lambda0* _0 = _closure;
	return _0->value;
}
/* each<arr<char>, arr<arr<char>>> void(d dict<arr<char>, arr<arr<char>>>, f fun-act2<void, arr<char>, arr<arr<char>>>) */
struct void_ each_0(struct ctx* ctx, struct dict_0* d, struct fun_act2_0 f) {
	top:;
	struct ctx* _0 = ctx;
	struct dict_0* _1 = d;
	uint8_t _2 = empty__q_7(_0, _1);
	uint8_t _3 = !_2;
	if (_3) {
		struct ctx* _4 = ctx;
		struct fun_act2_0 _5 = f;
		struct ctx* _6 = ctx;
		struct dict_0* _7 = d;
		struct arr_1 _8 = _7->keys;
		struct arr_0 _9 = first_1(_6, _8);
		struct ctx* _10 = ctx;
		struct dict_0* _11 = d;
		struct arr_6 _12 = _11->values;
		struct arr_1 _13 = first_2(_10, _12);
		call_10(_4, _5, _9, _13);
		struct dict_0* temp0;
		struct ctx* _14 = ctx;
		uint64_t _15 = sizeof(struct dict_0);
		uint8_t* _16 = alloc(_14, _15);
		temp0 = (struct dict_0*) _16;
		
		struct dict_0* _17 = temp0;
		struct ctx* _18 = ctx;
		struct dict_0* _19 = d;
		struct arr_1 _20 = _19->keys;
		struct arr_1 _21 = tail_2(_18, _20);
		struct ctx* _22 = ctx;
		struct dict_0* _23 = d;
		struct arr_6 _24 = _23->values;
		struct arr_6 _25 = tail_3(_22, _24);
		struct dict_0 _26 = (struct dict_0) {_21, _25};
		*_17 = _26;
		struct dict_0* _27 = temp0;
		struct fun_act2_0 _28 = f;
		d = _27;
		f = _28;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* empty?<?k, ?v> bool(d dict<arr<char>, arr<arr<char>>>) */
uint8_t empty__q_7(struct ctx* ctx, struct dict_0* d) {
	struct dict_0* _0 = d;
	struct arr_1 _1 = _0->keys;
	return empty__q_5(_1);
}
/* call<void, ?k, ?v> void(a fun-act2<void, arr<char>, arr<arr<char>>>, p0 arr<char>, p1 arr<arr<char>>) */
struct void_ call_10(struct ctx* ctx, struct fun_act2_0 a, struct arr_0 p0, struct arr_1 p1) {
	struct fun_act2_0 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	struct arr_1 _3 = p1;
	return call_w_ctx_422(_0, _1, _2, _3);
}
/* call-w-ctx<void, arr<char>, arr<arr<char>>> (generated) (generated) */
struct void_ call_w_ctx_422(struct fun_act2_0 a, struct ctx* ctx, struct arr_0 p0, struct arr_1 p1) {
	struct fun_act2_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct parse_cmd_line_args__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct parse_cmd_line_args__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			struct arr_1 _4 = p1;
			return parse_cmd_line_args__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* first<?v> arr<arr<char>>(a arr<arr<arr<char>>>) */
struct arr_1 first_2(struct ctx* ctx, struct arr_6 a) {
	struct ctx* _0 = ctx;
	struct arr_6 _1 = a;
	uint8_t _2 = empty__q_8(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_6 _4 = a;
	uint64_t _5 = 0u;
	return at_4(_3, _4, _5);
}
/* empty?<?t> bool(a arr<arr<arr<char>>>) */
uint8_t empty__q_8(struct arr_6 a) {
	struct arr_6 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* tail<?v> arr<arr<arr<char>>>(a arr<arr<arr<char>>>) */
struct arr_6 tail_3(struct ctx* ctx, struct arr_6 a) {
	struct ctx* _0 = ctx;
	struct arr_6 _1 = a;
	uint8_t _2 = empty__q_8(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_6 _4 = a;
	uint64_t _5 = 1u;
	return slice_starting_at_5(_3, _4, _5);
}
/* slice-starting-at<?t> arr<arr<arr<char>>>(a arr<arr<arr<char>>>, begin nat) */
struct arr_6 slice_starting_at_5(struct ctx* ctx, struct arr_6 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct arr_6 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_6 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct arr_6 _9 = a;
	uint64_t _10 = _9.size;
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_5(_5, _6, _7, _12);
}
/* slice<?t> arr<arr<arr<char>>>(a arr<arr<arr<char>>>, begin nat, size nat) */
struct arr_6 slice_5(struct ctx* ctx, struct arr_6 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct arr_6 _5 = a;
	uint64_t _6 = _5.size;
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct arr_6 _9 = a;
	struct arr_1* _10 = _9.data;
	uint64_t _11 = begin;
	struct arr_1* _12 = _10 + _11;
	return (struct arr_6) {_8, _12};
}
/* index-of<arr<char>> opt<nat>(a arr<arr<char>>, value arr<char>) */
struct opt_5 index_of(struct ctx* ctx, struct arr_1 a, struct arr_0 value) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	struct index_of__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct index_of__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct index_of__lambda0*) _4;
	
	struct index_of__lambda0* _5 = temp0;
	struct arr_0 _6 = value;
	struct index_of__lambda0 _7 = (struct index_of__lambda0) {_6};
	*_5 = _7;
	struct index_of__lambda0* _8 = temp0;
	struct fun_act1_6 _9 = (struct fun_act1_6) {3, .as3 = _8};
	return find_index(_0, _1, _9);
}
/* index-of<arr<char>>.lambda0 bool(it arr<char>) */
uint8_t index_of__lambda0(struct ctx* ctx, struct index_of__lambda0* _closure, struct arr_0 it) {
	struct arr_0 _0 = it;
	struct index_of__lambda0* _1 = _closure;
	struct arr_0 _2 = _1->value;
	return _op_equal_equal_4(_0, _2);
}
/* set<bool> void(c cell<bool>, v bool) */
struct void_ set_0(struct cell_3* c, uint8_t v) {
	struct cell_3* _0 = c;
	uint8_t _1 = v;
	return (_0->value = _1, (struct void_) {});
}
/* at<opt<arr<arr<char>>>> opt<arr<arr<char>>>(a mut-list<opt<arr<arr<char>>>>, index nat) */
struct opt_7 at_5(struct ctx* ctx, struct mut_list_3* a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_list_3* _2 = a;
	uint64_t _3 = _2->size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_list_3* _5 = a;
	uint64_t _6 = index;
	return noctx_at_7(_5, _6);
}
/* noctx-at<?t> opt<arr<arr<char>>>(a mut-list<opt<arr<arr<char>>>>, index nat) */
struct opt_7 noctx_at_7(struct mut_list_3* a, uint64_t index) {
	uint64_t _0 = index;
	struct mut_list_3* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_3* _4 = a;
	struct opt_7* _5 = data_7(_4);
	uint64_t _6 = index;
	struct opt_7* _7 = _5 + _6;
	return *_7;
}
/* data<?t> ptr<opt<arr<arr<char>>>>(a mut-list<opt<arr<arr<char>>>>) */
struct opt_7* data_7(struct mut_list_3* a) {
	struct mut_list_3* _0 = a;
	struct mut_arr_3 _1 = _0->backing;
	return data_6(_1);
}
/* set-at<opt<arr<arr<char>>>> void(a mut-list<opt<arr<arr<char>>>>, index nat, value opt<arr<arr<char>>>) */
struct void_ set_at_2(struct ctx* ctx, struct mut_list_3* a, uint64_t index, struct opt_7 value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_list_3* _2 = a;
	uint64_t _3 = _2->size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_list_3* _5 = a;
	uint64_t _6 = index;
	struct opt_7 _7 = value;
	return noctx_set_at_3(_5, _6, _7);
}
/* noctx-set-at<?t> void(a mut-list<opt<arr<arr<char>>>>, index nat, value opt<arr<arr<char>>>) */
struct void_ noctx_set_at_3(struct mut_list_3* a, uint64_t index, struct opt_7 value) {
	uint64_t _0 = index;
	struct mut_list_3* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_3* _4 = a;
	struct opt_7* _5 = data_7(_4);
	uint64_t _6 = index;
	struct opt_7* _7 = _5 + _6;
	struct opt_7 _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* parse-cmd-line-args<test-options>.lambda0 void(key arr<char>, value arr<arr<char>>) */
struct void_ parse_cmd_line_args__lambda0(struct ctx* ctx, struct parse_cmd_line_args__lambda0* _closure, struct arr_0 key, struct arr_1 value) {
	struct ctx* _0 = ctx;
	struct parse_cmd_line_args__lambda0* _1 = _closure;
	struct arr_1 _2 = _1->t_names;
	struct arr_0 _3 = key;
	struct opt_5 _4 = index_of(_0, _2, _3);
	switch (_4.kind) {
		case 0: {
			struct arr_0 _5 = key;
			struct arr_0 _6 = (struct arr_0) {4, constantarr_0_21};
			uint8_t _7 = _op_equal_equal_4(_5, _6);
			if (_7) {
				struct parse_cmd_line_args__lambda0* _8 = _closure;
				struct cell_3* _9 = _8->help;
				uint8_t _10 = 1;
				return set_0(_9, _10);
			} else {
				struct ctx* _11 = ctx;
				struct ctx* _12 = ctx;
				struct arr_0 _13 = (struct arr_0) {15, constantarr_0_22};
				struct arr_0 _14 = key;
				struct arr_0 _15 = _op_plus_0(_12, _13, _14);
				return fail_0(_11, _15);
			}
		}
		case 1: {
			struct some_5 s0 = _4.as1;
			
			uint64_t idx1;
			struct some_5 _16 = s0;
			idx1 = _16.value;
			
			struct ctx* _17 = ctx;
			struct ctx* _18 = ctx;
			struct parse_cmd_line_args__lambda0* _19 = _closure;
			struct mut_list_3* _20 = _19->values;
			uint64_t _21 = idx1;
			struct opt_7 _22 = at_5(_18, _20, _21);
			uint8_t _23 = has__q_3(_22);
			forbid_0(_17, _23);
			struct ctx* _24 = ctx;
			struct parse_cmd_line_args__lambda0* _25 = _closure;
			struct mut_list_3* _26 = _25->values;
			uint64_t _27 = idx1;
			struct arr_1 _28 = value;
			struct some_7 _29 = (struct some_7) {_28};
			struct opt_7 _30 = (struct opt_7) {1, .as1 = _29};
			return set_at_2(_24, _26, _27, _30);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* get<bool> bool(c cell<bool>) */
uint8_t get_3(struct cell_3* c) {
	struct cell_3* _0 = c;
	return _0->value;
}
/* call<?t, arr<opt<arr<arr<char>>>>> test-options(a fun1<test-options, arr<opt<arr<arr<char>>>>>, p0 arr<opt<arr<arr<char>>>>) */
struct test_options call_11(struct ctx* ctx, struct fun1_2 a, struct arr_5 p0) {
	struct fun1_2 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_5 _2 = p0;
	return call_w_ctx_439(_0, _1, _2);
}
/* call-w-ctx<test-options, arr<opt<arr<arr<char>>>>> (generated) (generated) */
struct test_options call_w_ctx_439(struct fun1_2 a, struct ctx* ctx, struct arr_5 p0) {
	struct fun1_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			struct arr_5 _3 = p0;
			return main_0__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct test_options) {0, 0, 0});
	}
}
/* move-to-arr<opt<arr<arr<char>>>> arr<opt<arr<arr<char>>>>(a mut-list<opt<arr<arr<char>>>>) */
struct arr_5 move_to_arr_2(struct mut_list_3* a) {
	struct arr_5 res0;
	struct mut_list_3* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_3* _2 = a;
	struct opt_7* _3 = data_7(_2);
	res0 = (struct arr_5) {_1, _3};
	
	struct mut_list_3* _4 = a;
	struct mut_arr_3 _5 = empty_mut_arr_2();
	_4->backing = _5;
	struct mut_list_3* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* empty-mut-arr<?t> mut-arr<opt<arr<arr<char>>>>() */
struct mut_arr_3 empty_mut_arr_2(void) {
	struct arr_5 _0 = empty_arr_3();
	return (struct mut_arr_3) {_0};
}
/* empty-arr<?t> arr<opt<arr<arr<char>>>>() */
struct arr_5 empty_arr_3(void) {
	uint64_t _0 = 0u;
	struct opt_7* _1 = NULL;
	return (struct arr_5) {_0, _1};
}
/* at<opt<arr<arr<char>>>> opt<arr<arr<char>>>(a arr<opt<arr<arr<char>>>>, index nat) */
struct opt_7 at_6(struct ctx* ctx, struct arr_5 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_5 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_5 _5 = a;
	uint64_t _6 = index;
	return noctx_at_8(_5, _6);
}
/* noctx-at<?t> opt<arr<arr<char>>>(a arr<opt<arr<arr<char>>>>, index nat) */
struct opt_7 noctx_at_8(struct arr_5 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_5 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_5 _4 = a;
	struct opt_7* _5 = _4.data;
	uint64_t _6 = index;
	struct opt_7* _7 = _5 + _6;
	return *_7;
}
/* force<nat> nat(a opt<nat>) */
uint64_t force_1(struct ctx* ctx, struct opt_5 a) {
	struct opt_5 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct ctx* _1 = ctx;
			struct arr_0 _2 = (struct arr_0) {27, constantarr_0_19};
			return fail_2(_1, _2);
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			struct some_5 _3 = s0;
			return _3.value;
		}
		default:
			return (assert(0),0);
	}
}
/* fail<?t> nat(reason arr<char>) */
uint64_t fail_2(struct ctx* ctx, struct arr_0 reason) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = reason;
	struct exception _2 = (struct exception) {_1};
	return throw_2(_0, _2);
}
/* throw<?t> nat(e exception) */
uint64_t throw_2(struct ctx* ctx, struct exception e) {
	struct exception_ctx* exn_ctx0;
	struct ctx* _0 = ctx;
	exn_ctx0 = get_exception_ctx(_0);
	
	struct exception_ctx* _1 = exn_ctx0;
	struct jmp_buf_tag* _2 = _1->jmp_buf_ptr;
	uint8_t _3 = null__q_1(_2);
	hard_forbid(_3);
	struct exception_ctx* _4 = exn_ctx0;
	struct exception _5 = e;
	_4->thrown_exception = _5;
	struct exception_ctx* _6 = exn_ctx0;
	struct jmp_buf_tag* _7 = _6->jmp_buf_ptr;
	struct ctx* _8 = ctx;
	int32_t _9 = number_to_throw(_8);
	(longjmp(_7, _9), (struct void_) {});
	return todo_3();
}
/* parse-nat opt<nat>(a arr<char>) */
struct opt_5 parse_nat(struct ctx* ctx, struct arr_0 a) {
	struct arr_0 _0 = a;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		struct none _2 = (struct none) {};
		return (struct opt_5) {0, .as0 = _2};
	} else {
		struct ctx* _3 = ctx;
		struct arr_0 _4 = a;
		uint64_t _5 = 0u;
		return parse_nat_recur(_3, _4, _5);
	}
}
/* parse-nat-recur opt<nat>(a arr<char>, accum nat) */
struct opt_5 parse_nat_recur(struct ctx* ctx, struct arr_0 a, uint64_t accum) {
	top:;
	struct arr_0 _0 = a;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		uint64_t _2 = accum;
		struct some_5 _3 = (struct some_5) {_2};
		return (struct opt_5) {1, .as1 = _3};
	} else {
		struct ctx* _4 = ctx;
		struct ctx* _5 = ctx;
		struct arr_0 _6 = a;
		char _7 = first_0(_5, _6);
		struct opt_5 _8 = char_to_nat(_4, _7);
		switch (_8.kind) {
			case 0: {
				struct none _9 = (struct none) {};
				return (struct opt_5) {0, .as0 = _9};
			}
			case 1: {
				struct some_5 s0 = _8.as1;
				
				struct ctx* _10 = ctx;
				struct arr_0 _11 = a;
				struct arr_0 _12 = tail_1(_10, _11);
				struct ctx* _13 = ctx;
				struct ctx* _14 = ctx;
				uint64_t _15 = accum;
				uint64_t _16 = 10u;
				uint64_t _17 = _op_times_0(_14, _15, _16);
				struct some_5 _18 = s0;
				uint64_t _19 = _18.value;
				uint64_t _20 = _op_plus_1(_13, _17, _19);
				a = _12;
				accum = _20;
				goto top;
			}
			default:
				return (assert(0),(struct opt_5) {0});
		}
	}
}
/* char-to-nat opt<nat>(c char) */
struct opt_5 char_to_nat(struct ctx* ctx, char c) {
	char _0 = c;
	char _1 = 48u;
	uint8_t _2 = _op_equal_equal_3(_0, _1);
	if (_2) {
		uint64_t _3 = 0u;
		struct some_5 _4 = (struct some_5) {_3};
		return (struct opt_5) {1, .as1 = _4};
	} else {
		char _5 = c;
		char _6 = 49u;
		uint8_t _7 = _op_equal_equal_3(_5, _6);
		if (_7) {
			uint64_t _8 = 1u;
			struct some_5 _9 = (struct some_5) {_8};
			return (struct opt_5) {1, .as1 = _9};
		} else {
			char _10 = c;
			char _11 = 50u;
			uint8_t _12 = _op_equal_equal_3(_10, _11);
			if (_12) {
				uint64_t _13 = 2u;
				struct some_5 _14 = (struct some_5) {_13};
				return (struct opt_5) {1, .as1 = _14};
			} else {
				char _15 = c;
				char _16 = 51u;
				uint8_t _17 = _op_equal_equal_3(_15, _16);
				if (_17) {
					uint64_t _18 = 3u;
					struct some_5 _19 = (struct some_5) {_18};
					return (struct opt_5) {1, .as1 = _19};
				} else {
					char _20 = c;
					char _21 = 52u;
					uint8_t _22 = _op_equal_equal_3(_20, _21);
					if (_22) {
						uint64_t _23 = 4u;
						struct some_5 _24 = (struct some_5) {_23};
						return (struct opt_5) {1, .as1 = _24};
					} else {
						char _25 = c;
						char _26 = 53u;
						uint8_t _27 = _op_equal_equal_3(_25, _26);
						if (_27) {
							uint64_t _28 = 5u;
							struct some_5 _29 = (struct some_5) {_28};
							return (struct opt_5) {1, .as1 = _29};
						} else {
							char _30 = c;
							char _31 = 54u;
							uint8_t _32 = _op_equal_equal_3(_30, _31);
							if (_32) {
								uint64_t _33 = 6u;
								struct some_5 _34 = (struct some_5) {_33};
								return (struct opt_5) {1, .as1 = _34};
							} else {
								char _35 = c;
								char _36 = 55u;
								uint8_t _37 = _op_equal_equal_3(_35, _36);
								if (_37) {
									uint64_t _38 = 7u;
									struct some_5 _39 = (struct some_5) {_38};
									return (struct opt_5) {1, .as1 = _39};
								} else {
									char _40 = c;
									char _41 = 56u;
									uint8_t _42 = _op_equal_equal_3(_40, _41);
									if (_42) {
										uint64_t _43 = 8u;
										struct some_5 _44 = (struct some_5) {_43};
										return (struct opt_5) {1, .as1 = _44};
									} else {
										char _45 = c;
										char _46 = 57u;
										uint8_t _47 = _op_equal_equal_3(_45, _46);
										if (_47) {
											uint64_t _48 = 9u;
											struct some_5 _49 = (struct some_5) {_48};
											return (struct opt_5) {1, .as1 = _49};
										} else {
											struct none _50 = (struct none) {};
											return (struct opt_5) {0, .as0 = _50};
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
/* main.lambda0 test-options(values arr<opt<arr<arr<char>>>>) */
struct test_options main_0__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_5 values) {
	struct opt_7 print_tests_strs0;
	struct ctx* _0 = ctx;
	struct arr_5 _1 = values;
	uint64_t _2 = 0u;
	print_tests_strs0 = at_6(_0, _1, _2);
	
	struct opt_7 overwrite_output_strs1;
	struct ctx* _3 = ctx;
	struct arr_5 _4 = values;
	uint64_t _5 = 1u;
	overwrite_output_strs1 = at_6(_3, _4, _5);
	
	struct opt_7 max_failures_strs2;
	struct ctx* _6 = ctx;
	struct arr_5 _7 = values;
	uint64_t _8 = 2u;
	max_failures_strs2 = at_6(_6, _7, _8);
	
	uint8_t print_tests__q3;
	struct opt_7 _9 = print_tests_strs0;
	print_tests__q3 = has__q_3(_9);
	
	uint8_t overwrite_output__q5;
	struct opt_7 _10 = overwrite_output_strs1;
	switch (_10.kind) {
		case 0: {
			overwrite_output__q5 = 0;
			break;
		}
		case 1: {
			struct some_7 s4 = _10.as1;
			
			struct ctx* _11 = ctx;
			struct some_7 _12 = s4;
			struct arr_1 _13 = _12.value;
			uint8_t _14 = empty__q_5(_13);
			assert_0(_11, _14);
			overwrite_output__q5 = 1;
			break;
		}
		default:
			(assert(0),0);
	}
	
	uint64_t max_failures8;
	struct opt_7 _15 = max_failures_strs2;
	switch (_15.kind) {
		case 0: {
			max_failures8 = 100u;
			break;
		}
		case 1: {
			struct some_7 s6 = _15.as1;
			
			struct arr_1 strs7;
			struct some_7 _16 = s6;
			strs7 = _16.value;
			
			struct ctx* _17 = ctx;
			struct arr_1 _18 = strs7;
			uint64_t _19 = _18.size;
			uint64_t _20 = 1u;
			uint8_t _21 = _op_equal_equal_0(_19, _20);
			assert_0(_17, _21);
			struct ctx* _22 = ctx;
			struct ctx* _23 = ctx;
			struct ctx* _24 = ctx;
			struct arr_1 _25 = strs7;
			struct arr_0 _26 = first_1(_24, _25);
			struct opt_5 _27 = parse_nat(_23, _26);
			max_failures8 = force_1(_22, _27);
			break;
		}
		default:
			(assert(0),0);
	}
	
	uint8_t _28 = print_tests__q3;
	uint8_t _29 = overwrite_output__q5;
	uint64_t _30 = max_failures8;
	return (struct test_options) {_28, _29, _30};
}
/* resolved<int32> fut<int32>(value int32) */
struct fut_0* resolved_1(struct ctx* ctx, int32_t value) {
	struct fut_0* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct fut_0);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct fut_0*) _2;
	
	struct fut_0* _3 = temp0;
	struct lock _4 = new_lock();
	int32_t _5 = value;
	struct fut_state_resolved_0 _6 = (struct fut_state_resolved_0) {_5};
	struct fut_state_0 _7 = (struct fut_state_0) {1, .as1 = _6};
	struct fut_0 _8 = (struct fut_0) {_4, _7};
	*_3 = _8;
	return temp0;
}
/* print-help void() */
struct void_ print_help(struct ctx* ctx) {
	struct arr_0 _0 = (struct arr_0) {18, constantarr_0_23};
	print(_0);
	struct arr_0 _1 = (struct arr_0) {8, constantarr_0_24};
	print(_1);
	struct arr_0 _2 = (struct arr_0) {38, constantarr_0_25};
	print(_2);
	struct arr_0 _3 = (struct arr_0) {64, constantarr_0_26};
	return print(_3);
}
/* do-test int32(options test-options) */
int32_t do_test(struct ctx* ctx, struct test_options options) {
	struct arr_0 test_path0;
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = current_executable_path(_1);
	test_path0 = parent_path(_0, _2);
	
	struct arr_0 noze_path1;
	struct ctx* _3 = ctx;
	struct arr_0 _4 = test_path0;
	noze_path1 = parent_path(_3, _4);
	
	struct arr_0 noze_exe2;
	struct ctx* _5 = ctx;
	struct ctx* _6 = ctx;
	struct arr_0 _7 = noze_path1;
	struct arr_0 _8 = (struct arr_0) {3, constantarr_0_30};
	struct arr_0 _9 = child_path(_6, _7, _8);
	struct arr_0 _10 = (struct arr_0) {4, constantarr_0_31};
	noze_exe2 = child_path(_5, _9, _10);
	
	struct dict_1* env3;
	struct ctx* _11 = ctx;
	env3 = get_environ(_11);
	
	struct result_2 noze_failures4;
	struct ctx* _12 = ctx;
	struct ctx* _13 = ctx;
	struct ctx* _14 = ctx;
	struct arr_0 _15 = test_path0;
	struct arr_0 _16 = (struct arr_0) {12, constantarr_0_77};
	struct arr_0 _17 = child_path(_14, _15, _16);
	struct arr_0 _18 = noze_exe2;
	struct dict_1* _19 = env3;
	struct test_options _20 = options;
	struct result_2 _21 = run_noze_tests(_13, _17, _18, _19, _20);
	struct do_test__lambda0* temp0;
	struct ctx* _22 = ctx;
	uint64_t _23 = sizeof(struct do_test__lambda0);
	uint8_t* _24 = alloc(_22, _23);
	temp0 = (struct do_test__lambda0*) _24;
	
	struct do_test__lambda0* _25 = temp0;
	struct arr_0 _26 = test_path0;
	struct arr_0 _27 = noze_exe2;
	struct dict_1* _28 = env3;
	struct test_options _29 = options;
	struct do_test__lambda0 _30 = (struct do_test__lambda0) {_26, _27, _28, _29};
	*_25 = _30;
	struct do_test__lambda0* _31 = temp0;
	struct fun0 _32 = (struct fun0) {1, .as1 = _31};
	noze_failures4 = first_failures(_12, _21, _32);
	
	struct result_2 all_failures5;
	struct ctx* _33 = ctx;
	struct result_2 _34 = noze_failures4;
	struct do_test__lambda1* temp1;
	struct ctx* _35 = ctx;
	uint64_t _36 = sizeof(struct do_test__lambda1);
	uint8_t* _37 = alloc(_35, _36);
	temp1 = (struct do_test__lambda1*) _37;
	
	struct do_test__lambda1* _38 = temp1;
	struct arr_0 _39 = noze_path1;
	struct test_options _40 = options;
	struct do_test__lambda1 _41 = (struct do_test__lambda1) {_39, _40};
	*_38 = _41;
	struct do_test__lambda1* _42 = temp1;
	struct fun0 _43 = (struct fun0) {2, .as2 = _42};
	all_failures5 = first_failures(_33, _34, _43);
	
	struct ctx* _44 = ctx;
	struct result_2 _45 = all_failures5;
	struct test_options _46 = options;
	return print_failures(_44, _45, _46);
}
/* parent-path arr<char>(a arr<char>) */
struct arr_0 parent_path(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	char _2 = 47u;
	struct opt_5 _3 = r_index_of(_0, _1, _2);
	switch (_3.kind) {
		case 0: {
			return (struct arr_0) {0u, NULL};
		}
		case 1: {
			struct some_5 s0 = _3.as1;
			
			struct ctx* _4 = ctx;
			struct arr_0 _5 = a;
			struct some_5 _6 = s0;
			uint64_t _7 = _6.value;
			return slice_up_to_1(_4, _5, _7);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* r-index-of<char> opt<nat>(a arr<char>, value char) */
struct opt_5 r_index_of(struct ctx* ctx, struct arr_0 a, char value) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct r_index_of__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct r_index_of__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct r_index_of__lambda0*) _4;
	
	struct r_index_of__lambda0* _5 = temp0;
	char _6 = value;
	struct r_index_of__lambda0 _7 = (struct r_index_of__lambda0) {_6};
	*_5 = _7;
	struct r_index_of__lambda0* _8 = temp0;
	struct fun_act1_8 _9 = (struct fun_act1_8) {0, .as0 = _8};
	return find_rindex(_0, _1, _9);
}
/* find-rindex<?t> opt<nat>(a arr<char>, pred fun-act1<bool, char>) */
struct opt_5 find_rindex(struct ctx* ctx, struct arr_0 a, struct fun_act1_8 pred) {
	struct arr_0 _0 = a;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		struct none _2 = (struct none) {};
		return (struct opt_5) {0, .as0 = _2};
	} else {
		struct ctx* _3 = ctx;
		struct arr_0 _4 = a;
		struct ctx* _5 = ctx;
		struct arr_0 _6 = a;
		uint64_t _7 = _6.size;
		uint64_t _8 = decr(_5, _7);
		struct fun_act1_8 _9 = pred;
		return find_rindex_recur(_3, _4, _8, _9);
	}
}
/* find-rindex-recur<?t> opt<nat>(a arr<char>, index nat, pred fun-act1<bool, char>) */
struct opt_5 find_rindex_recur(struct ctx* ctx, struct arr_0 a, uint64_t index, struct fun_act1_8 pred) {
	top:;
	struct ctx* _0 = ctx;
	struct fun_act1_8 _1 = pred;
	struct ctx* _2 = ctx;
	struct arr_0 _3 = a;
	uint64_t _4 = index;
	char _5 = at_3(_2, _3, _4);
	uint8_t _6 = call_12(_0, _1, _5);
	if (_6) {
		uint64_t _7 = index;
		struct some_5 _8 = (struct some_5) {_7};
		return (struct opt_5) {1, .as1 = _8};
	} else {
		uint64_t _9 = index;
		uint64_t _10 = 0u;
		uint8_t _11 = _op_equal_equal_0(_9, _10);
		if (_11) {
			struct none _12 = (struct none) {};
			return (struct opt_5) {0, .as0 = _12};
		} else {
			struct arr_0 _13 = a;
			struct ctx* _14 = ctx;
			uint64_t _15 = index;
			uint64_t _16 = decr(_14, _15);
			struct fun_act1_8 _17 = pred;
			a = _13;
			index = _16;
			pred = _17;
			goto top;
		}
	}
}
/* call<bool, ?t> bool(a fun-act1<bool, char>, p0 char) */
uint8_t call_12(struct ctx* ctx, struct fun_act1_8 a, char p0) {
	struct fun_act1_8 _0 = a;
	struct ctx* _1 = ctx;
	char _2 = p0;
	return call_w_ctx_460(_0, _1, _2);
}
/* call-w-ctx<bool, char> (generated) (generated) */
uint8_t call_w_ctx_460(struct fun_act1_8 a, struct ctx* ctx, char p0) {
	struct fun_act1_8 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct r_index_of__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct r_index_of__lambda0* _2 = closure0;
			char _3 = p0;
			return r_index_of__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),0);
	}
}
/* r-index-of<char>.lambda0 bool(it char) */
uint8_t r_index_of__lambda0(struct ctx* ctx, struct r_index_of__lambda0* _closure, char it) {
	char _0 = it;
	struct r_index_of__lambda0* _1 = _closure;
	char _2 = _1->value;
	return _op_equal_equal_3(_0, _2);
}
/* slice-up-to<char> arr<char>(a arr<char>, size nat) */
struct arr_0 slice_up_to_1(struct ctx* ctx, struct arr_0 a, uint64_t size) {
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct arr_0 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_0 _6 = a;
	uint64_t _7 = 0u;
	uint64_t _8 = size;
	return slice_1(_5, _6, _7, _8);
}
/* current-executable-path arr<char>() */
struct arr_0 current_executable_path(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = (struct arr_0) {14, constantarr_0_28};
	return read_link(_0, _1);
}
/* read-link arr<char>(path arr<char>) */
struct arr_0 read_link(struct ctx* ctx, struct arr_0 path) {
	struct mut_arr_4 buff0;
	struct ctx* _0 = ctx;
	uint64_t _1 = 1000u;
	buff0 = new_uninitialized_mut_arr_2(_0, _1);
	
	int64_t size1;
	struct ctx* _2 = ctx;
	struct arr_0 _3 = path;
	char* _4 = to_c_str(_2, _3);
	struct mut_arr_4 _5 = buff0;
	char* _6 = data_8(_5);
	struct mut_arr_4 _7 = buff0;
	uint64_t _8 = size_5(_7);
	size1 = readlink(_4, _6, _8);
	
	struct ctx* _9 = ctx;
	int64_t _10 = size1;
	check_errno_if_neg_one(_9, _10);
	struct ctx* _11 = ctx;
	struct mut_arr_4 _12 = buff0;
	struct arr_0 _13 = cast_immutable_1(_12);
	struct ctx* _14 = ctx;
	int64_t _15 = size1;
	uint64_t _16 = to_nat_0(_14, _15);
	return slice_up_to_1(_11, _13, _16);
}
/* new-uninitialized-mut-arr<char> mut-arr<char>(size nat) */
struct mut_arr_4 new_uninitialized_mut_arr_2(struct ctx* ctx, uint64_t size) {
	uint64_t _0 = size;
	struct ctx* _1 = ctx;
	uint64_t _2 = size;
	char* _3 = uninitialized_data_0(_1, _2);
	return mut_arr_4(_0, _3);
}
/* mut-arr<?t> mut-arr<char>(size nat, data ptr<char>) */
struct mut_arr_4 mut_arr_4(uint64_t size, char* data) {
	uint64_t _0 = size;
	char* _1 = data;
	struct arr_0 _2 = (struct arr_0) {_0, _1};
	return (struct mut_arr_4) {_2};
}
/* to-c-str ptr<char>(a arr<char>) */
char* to_c_str(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct arr_0 _2 = (struct arr_0) {1, constantarr_0_27};
	struct arr_0 _3 = _op_plus_0(_0, _1, _2);
	return _3.data;
}
/* data<char> ptr<char>(a mut-arr<char>) */
char* data_8(struct mut_arr_4 a) {
	struct mut_arr_4 _0 = a;
	struct arr_0 _1 = _0.arr;
	return _1.data;
}
/* size<char> nat(a mut-arr<char>) */
uint64_t size_5(struct mut_arr_4 a) {
	struct mut_arr_4 _0 = a;
	struct arr_0 _1 = _0.arr;
	return _1.size;
}
/* check-errno-if-neg-one void(e int) */
struct void_ check_errno_if_neg_one(struct ctx* ctx, int64_t e) {
	int64_t _0 = e;
	int64_t _1 = -1;
	uint8_t _2 = _op_equal_equal_1(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		int32_t _4 = errno;
		check_posix_error(_3, _4);
		return hard_unreachable_1();
	} else {
		return (struct void_) {};
	}
}
/* check-posix-error void(e int32) */
struct void_ check_posix_error(struct ctx* ctx, int32_t e) {
	struct ctx* _0 = ctx;
	int32_t _1 = e;
	int32_t _2 = 0;
	uint8_t _3 = _op_equal_equal_2(_1, _2);
	return assert_0(_0, _3);
}
/* hard-unreachable<void> void() */
struct void_ hard_unreachable_1(void) {
	return (assert(0),(struct void_) {});
}
/* cast-immutable<char> arr<char>(a mut-arr<char>) */
struct arr_0 cast_immutable_1(struct mut_arr_4 a) {
	struct mut_arr_4 _0 = a;
	return _0.arr;
}
/* to-nat nat(i int) */
uint64_t to_nat_0(struct ctx* ctx, int64_t i) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	int64_t _2 = i;
	uint8_t _3 = negative__q(_1, _2);
	forbid_0(_0, _3);
	int64_t _4 = i;
	return (uint64_t) _4;
}
/* negative? bool(i int) */
uint8_t negative__q(struct ctx* ctx, int64_t i) {
	int64_t _0 = i;
	int64_t _1 = 0;
	return _op_less_1(_0, _1);
}
/* <<int> bool(a int, b int) */
uint8_t _op_less_1(int64_t a, int64_t b) {
	int64_t _0 = a;
	int64_t _1 = b;
	struct comparison _2 = compare_36(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* child-path arr<char>(a arr<char>, child-name arr<char>) */
struct arr_0 child_path(struct ctx* ctx, struct arr_0 a, struct arr_0 child_name) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = a;
	struct arr_0 _3 = (struct arr_0) {1, constantarr_0_29};
	struct arr_0 _4 = _op_plus_0(_1, _2, _3);
	struct arr_0 _5 = child_name;
	return _op_plus_0(_0, _4, _5);
}
/* get-environ dict<arr<char>, arr<char>>() */
struct dict_1* get_environ(struct ctx* ctx) {
	struct mut_dict_1 res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_dict_1(_0);
	
	struct ctx* _1 = ctx;
	char** _2 = environ;
	struct mut_dict_1 _3 = res0;
	get_environ_recur(_1, _2, _3);
	struct ctx* _4 = ctx;
	struct mut_dict_1 _5 = res0;
	return move_to_dict_1(_4, _5);
}
/* new-mut-dict<arr<char>, arr<char>> mut-dict<arr<char>, arr<char>>() */
struct mut_dict_1 new_mut_dict_1(struct ctx* ctx) {
	struct ctx* _0 = ctx;
	struct mut_list_1* _1 = new_mut_list_0(_0);
	struct ctx* _2 = ctx;
	struct mut_list_1* _3 = new_mut_list_0(_2);
	return (struct mut_dict_1) {_1, _3};
}
/* get-environ-recur void(env ptr<ptr<char>>, res mut-dict<arr<char>, arr<char>>) */
struct void_ get_environ_recur(struct ctx* ctx, char** env, struct mut_dict_1 res) {
	top:;
	char** _0 = env;
	char* _1 = *_0;
	uint8_t _2 = null__q_2(_1);
	uint8_t _3 = !_2;
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_dict_1 _5 = res;
		struct ctx* _6 = ctx;
		char** _7 = env;
		char* _8 = *_7;
		struct key_value_pair* _9 = parse_environ_entry(_6, _8);
		add_1(_4, _5, _9);
		char** _10 = env;
		char** _11 = incr_6(_10);
		struct mut_dict_1 _12 = res;
		env = _11;
		res = _12;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* null?<char> bool(a ptr<char>) */
uint8_t null__q_2(char* a) {
	char* _0 = a;
	uint64_t _1 = (uint64_t) _0;
	char* _2 = NULL;
	uint64_t _3 = (uint64_t) _2;
	return _op_equal_equal_0(_1, _3);
}
/* add<arr<char>, arr<char>> void(m mut-dict<arr<char>, arr<char>>, pair key-value-pair<arr<char>, arr<char>>) */
struct void_ add_1(struct ctx* ctx, struct mut_dict_1 m, struct key_value_pair* pair) {
	struct ctx* _0 = ctx;
	struct mut_dict_1 _1 = m;
	struct key_value_pair* _2 = pair;
	struct arr_0 _3 = _2->key;
	struct key_value_pair* _4 = pair;
	struct arr_0 _5 = _4->value;
	return add_2(_0, _1, _3, _5);
}
/* add<?k, ?v> void(m mut-dict<arr<char>, arr<char>>, key arr<char>, value arr<char>) */
struct void_ add_2(struct ctx* ctx, struct mut_dict_1 m, struct arr_0 key, struct arr_0 value) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct mut_dict_1 _2 = m;
	struct arr_0 _3 = key;
	uint8_t _4 = has__q_4(_1, _2, _3);
	forbid_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_dict_1 _6 = m;
	struct mut_list_1* _7 = _6.keys;
	struct arr_0 _8 = key;
	push_0(_5, _7, _8);
	struct ctx* _9 = ctx;
	struct mut_dict_1 _10 = m;
	struct mut_list_1* _11 = _10.values;
	struct arr_0 _12 = value;
	return push_0(_9, _11, _12);
}
/* has?<?k, ?v> bool(d mut-dict<arr<char>, arr<char>>, key arr<char>) */
uint8_t has__q_4(struct ctx* ctx, struct mut_dict_1 d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct mut_dict_1 _2 = d;
	struct dict_1* _3 = temp_as_dict_1(_1, _2);
	struct arr_0 _4 = key;
	return has__q_5(_0, _3, _4);
}
/* has?<?k, ?v> bool(d dict<arr<char>, arr<char>>, key arr<char>) */
uint8_t has__q_5(struct ctx* ctx, struct dict_1* d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct dict_1* _1 = d;
	struct arr_0 _2 = key;
	struct opt_8 _3 = get_4(_0, _1, _2);
	return has__q_6(_3);
}
/* has?<?v> bool(a opt<arr<char>>) */
uint8_t has__q_6(struct opt_8 a) {
	struct opt_8 _0 = a;
	uint8_t _1 = empty__q_9(_0);
	return !_1;
}
/* empty?<?t> bool(a opt<arr<char>>) */
uint8_t empty__q_9(struct opt_8 a) {
	struct opt_8 _0 = a;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* get<?v, ?k> opt<arr<char>>(d dict<arr<char>, arr<char>>, key arr<char>) */
struct opt_8 get_4(struct ctx* ctx, struct dict_1* d, struct arr_0 key) {
	struct ctx* _0 = ctx;
	struct dict_1* _1 = d;
	struct arr_1 _2 = _1->keys;
	struct dict_1* _3 = d;
	struct arr_1 _4 = _3->values;
	uint64_t _5 = 0u;
	struct arr_0 _6 = key;
	return get_recursive_1(_0, _2, _4, _5, _6);
}
/* get-recursive<?k, ?v> opt<arr<char>>(keys arr<arr<char>>, values arr<arr<char>>, idx nat, key arr<char>) */
struct opt_8 get_recursive_1(struct ctx* ctx, struct arr_1 keys, struct arr_1 values, uint64_t idx, struct arr_0 key) {
	top:;
	uint64_t _0 = idx;
	struct arr_1 _1 = keys;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		struct none _4 = (struct none) {};
		return (struct opt_8) {0, .as0 = _4};
	} else {
		struct arr_0 _5 = key;
		struct ctx* _6 = ctx;
		struct arr_1 _7 = keys;
		uint64_t _8 = idx;
		struct arr_0 _9 = at_2(_6, _7, _8);
		uint8_t _10 = _op_equal_equal_4(_5, _9);
		if (_10) {
			struct ctx* _11 = ctx;
			struct arr_1 _12 = values;
			uint64_t _13 = idx;
			struct arr_0 _14 = at_2(_11, _12, _13);
			struct some_8 _15 = (struct some_8) {_14};
			return (struct opt_8) {1, .as1 = _15};
		} else {
			struct arr_1 _16 = keys;
			struct arr_1 _17 = values;
			struct ctx* _18 = ctx;
			uint64_t _19 = idx;
			uint64_t _20 = incr_3(_18, _19);
			struct arr_0 _21 = key;
			keys = _16;
			values = _17;
			idx = _20;
			key = _21;
			goto top;
		}
	}
}
/* temp-as-dict<?k, ?v> dict<arr<char>, arr<char>>(m mut-dict<arr<char>, arr<char>>) */
struct dict_1* temp_as_dict_1(struct ctx* ctx, struct mut_dict_1 m) {
	struct dict_1* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dict_1);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dict_1*) _2;
	
	struct dict_1* _3 = temp0;
	struct mut_dict_1 _4 = m;
	struct mut_list_1* _5 = _4.keys;
	struct arr_1 _6 = temp_as_arr_2(_5);
	struct mut_dict_1 _7 = m;
	struct mut_list_1* _8 = _7.values;
	struct arr_1 _9 = temp_as_arr_2(_8);
	struct dict_1 _10 = (struct dict_1) {_6, _9};
	*_3 = _10;
	return temp0;
}
/* parse-environ-entry key-value-pair<arr<char>, arr<char>>(entry ptr<char>) */
struct key_value_pair* parse_environ_entry(struct ctx* ctx, char* entry) {
	char* key_end0;
	char* _0 = entry;
	char _1 = 61u;
	key_end0 = find_char_in_cstr(_0, _1);
	
	struct arr_0 key1;
	char* _2 = entry;
	char* _3 = key_end0;
	key1 = arr_from_begin_end(_2, _3);
	
	char* value_begin2;
	char* _4 = key_end0;
	value_begin2 = incr_2(_4);
	
	char* value_end3;
	char* _5 = value_begin2;
	value_end3 = find_cstr_end(_5);
	
	struct arr_0 value4;
	char* _6 = value_begin2;
	char* _7 = value_end3;
	value4 = arr_from_begin_end(_6, _7);
	
	struct key_value_pair* temp0;
	struct ctx* _8 = ctx;
	uint64_t _9 = sizeof(struct key_value_pair);
	uint8_t* _10 = alloc(_8, _9);
	temp0 = (struct key_value_pair*) _10;
	
	struct key_value_pair* _11 = temp0;
	struct arr_0 _12 = key1;
	struct arr_0 _13 = value4;
	struct key_value_pair _14 = (struct key_value_pair) {_12, _13};
	*_11 = _14;
	return temp0;
}
/* incr<ptr<char>> ptr<ptr<char>>(p ptr<ptr<char>>) */
char** incr_6(char** p) {
	char** _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* move-to-dict<arr<char>, arr<char>> dict<arr<char>, arr<char>>(m mut-dict<arr<char>, arr<char>>) */
struct dict_1* move_to_dict_1(struct ctx* ctx, struct mut_dict_1 m) {
	struct dict_1* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dict_1);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dict_1*) _2;
	
	struct dict_1* _3 = temp0;
	struct mut_dict_1 _4 = m;
	struct mut_list_1* _5 = _4.keys;
	struct arr_1 _6 = move_to_arr_0(_5);
	struct mut_dict_1 _7 = m;
	struct mut_list_1* _8 = _7.values;
	struct arr_1 _9 = move_to_arr_0(_8);
	struct dict_1 _10 = (struct dict_1) {_6, _9};
	*_3 = _10;
	return temp0;
}
/* first-failures result<arr<char>, arr<failure>>(a result<arr<char>, arr<failure>>, b fun0<result<arr<char>, arr<failure>>>) */
struct result_2 first_failures(struct ctx* ctx, struct result_2 a, struct fun0 b) {
	struct ctx* _0 = ctx;
	struct result_2 _1 = a;
	struct first_failures__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct first_failures__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct first_failures__lambda0*) _4;
	
	struct first_failures__lambda0* _5 = temp0;
	struct fun0 _6 = b;
	struct first_failures__lambda0 _7 = (struct first_failures__lambda0) {_6};
	*_5 = _7;
	struct first_failures__lambda0* _8 = temp0;
	struct fun_act1_9 _9 = (struct fun_act1_9) {1, .as1 = _8};
	return then_1(_0, _1, _9);
}
/* then<arr<char>, arr<failure>, arr<char>> result<arr<char>, arr<failure>>(a result<arr<char>, arr<failure>>, f fun-act1<result<arr<char>, arr<failure>>, arr<char>>) */
struct result_2 then_1(struct ctx* ctx, struct result_2 a, struct fun_act1_9 f) {
	struct result_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct ok_2 o0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct fun_act1_9 _2 = f;
			struct ok_2 _3 = o0;
			struct arr_0 _4 = _3.value;
			return call_13(_1, _2, _4);
		}
		case 1: {
			struct err_1 e1 = _0.as1;
			
			struct err_1 _5 = e1;
			return (struct result_2) {1, .as1 = _5};
		}
		default:
			return (assert(0),(struct result_2) {0});
	}
}
/* call<result<?ok-out, ?err>, ?ok-in> result<arr<char>, arr<failure>>(a fun-act1<result<arr<char>, arr<failure>>, arr<char>>, p0 arr<char>) */
struct result_2 call_13(struct ctx* ctx, struct fun_act1_9 a, struct arr_0 p0) {
	struct fun_act1_9 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_500(_0, _1, _2);
}
/* call-w-ctx<result<arr<char>, arr<failure>>, arr<char>> (generated) (generated) */
struct result_2 call_w_ctx_500(struct fun_act1_9 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_9 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct first_failures__lambda0__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct first_failures__lambda0__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			return first_failures__lambda0__lambda0(_1, _2, _3);
		}
		case 1: {
			struct first_failures__lambda0* closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct first_failures__lambda0* _5 = closure1;
			struct arr_0 _6 = p0;
			return first_failures__lambda0(_4, _5, _6);
		}
		default:
			return (assert(0),(struct result_2) {0});
	}
}
/* call<result<arr<char>, arr<failure>>> result<arr<char>, arr<failure>>(a fun0<result<arr<char>, arr<failure>>>) */
struct result_2 call_14(struct ctx* ctx, struct fun0 a) {
	struct fun0 _0 = a;
	struct ctx* _1 = ctx;
	return call_w_ctx_502(_0, _1);
}
/* call-w-ctx<result<arr<char>, arr<failure>>> (generated) (generated) */
struct result_2 call_w_ctx_502(struct fun0 a, struct ctx* ctx) {
	struct fun0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct do_test__lambda0__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct do_test__lambda0__lambda0* _2 = closure0;
			return do_test__lambda0__lambda0(_1, _2);
		}
		case 1: {
			struct do_test__lambda0* closure1 = _0.as1;
			
			struct ctx* _3 = ctx;
			struct do_test__lambda0* _4 = closure1;
			return do_test__lambda0(_3, _4);
		}
		case 2: {
			struct do_test__lambda1* closure2 = _0.as2;
			
			struct ctx* _5 = ctx;
			struct do_test__lambda1* _6 = closure2;
			return do_test__lambda1(_5, _6);
		}
		default:
			return (assert(0),(struct result_2) {0});
	}
}
/* first-failures.lambda0.lambda0 result<arr<char>, arr<failure>>(b-descr arr<char>) */
struct result_2 first_failures__lambda0__lambda0(struct ctx* ctx, struct first_failures__lambda0__lambda0* _closure, struct arr_0 b_descr) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct first_failures__lambda0__lambda0* _2 = _closure;
	struct arr_0 _3 = _2->a_descr;
	struct arr_0 _4 = (struct arr_0) {1, constantarr_0_3};
	struct arr_0 _5 = _op_plus_0(_1, _3, _4);
	struct arr_0 _6 = b_descr;
	struct arr_0 _7 = _op_plus_0(_0, _5, _6);
	struct ok_2 _8 = (struct ok_2) {_7};
	return (struct result_2) {0, .as0 = _8};
}
/* first-failures.lambda0 result<arr<char>, arr<failure>>(a-descr arr<char>) */
struct result_2 first_failures__lambda0(struct ctx* ctx, struct first_failures__lambda0* _closure, struct arr_0 a_descr) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct first_failures__lambda0* _2 = _closure;
	struct fun0 _3 = _2->b;
	struct result_2 _4 = call_14(_1, _3);
	struct first_failures__lambda0__lambda0* temp0;
	struct ctx* _5 = ctx;
	uint64_t _6 = sizeof(struct first_failures__lambda0__lambda0);
	uint8_t* _7 = alloc(_5, _6);
	temp0 = (struct first_failures__lambda0__lambda0*) _7;
	
	struct first_failures__lambda0__lambda0* _8 = temp0;
	struct arr_0 _9 = a_descr;
	struct first_failures__lambda0__lambda0 _10 = (struct first_failures__lambda0__lambda0) {_9};
	*_8 = _10;
	struct first_failures__lambda0__lambda0* _11 = temp0;
	struct fun_act1_9 _12 = (struct fun_act1_9) {0, .as0 = _11};
	return then_1(_0, _4, _12);
}
/* run-noze-tests result<arr<char>, arr<failure>>(path arr<char>, path-to-noze arr<char>, env dict<arr<char>, arr<char>>, options test-options) */
struct result_2 run_noze_tests(struct ctx* ctx, struct arr_0 path, struct arr_0 path_to_noze, struct dict_1* env, struct test_options options) {
	struct arr_1 tests0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	tests0 = list_tests(_0, _1);
	
	struct arr_7 failures1;
	struct ctx* _2 = ctx;
	struct arr_1 _3 = tests0;
	struct test_options _4 = options;
	uint64_t _5 = _4.max_failures;
	struct run_noze_tests__lambda0* temp0;
	struct ctx* _6 = ctx;
	uint64_t _7 = sizeof(struct run_noze_tests__lambda0);
	uint8_t* _8 = alloc(_6, _7);
	temp0 = (struct run_noze_tests__lambda0*) _8;
	
	struct run_noze_tests__lambda0* _9 = temp0;
	struct arr_0 _10 = path_to_noze;
	struct dict_1* _11 = env;
	struct test_options _12 = options;
	struct run_noze_tests__lambda0 _13 = (struct run_noze_tests__lambda0) {_10, _11, _12};
	*_9 = _13;
	struct run_noze_tests__lambda0* _14 = temp0;
	struct fun_act1_11 _15 = (struct fun_act1_11) {0, .as0 = _14};
	failures1 = flat_map_with_max_size(_2, _3, _5, _15);
	
	struct arr_7 _16 = failures1;
	uint8_t _17 = has__q_7(_16);
	if (_17) {
		struct arr_7 _18 = failures1;
		struct err_1 _19 = (struct err_1) {_18};
		return (struct result_2) {1, .as1 = _19};
	} else {
		struct ctx* _20 = ctx;
		struct ctx* _21 = ctx;
		struct ctx* _22 = ctx;
		struct arr_0 _23 = (struct arr_0) {4, constantarr_0_75};
		struct ctx* _24 = ctx;
		struct arr_1 _25 = tests0;
		uint64_t _26 = _25.size;
		struct arr_0 _27 = to_str_4(_24, _26);
		struct arr_0 _28 = _op_plus_0(_22, _23, _27);
		struct arr_0 _29 = (struct arr_0) {10, constantarr_0_76};
		struct arr_0 _30 = _op_plus_0(_21, _28, _29);
		struct arr_0 _31 = path;
		struct arr_0 _32 = _op_plus_0(_20, _30, _31);
		struct ok_2 _33 = (struct ok_2) {_32};
		return (struct result_2) {0, .as0 = _33};
	}
}
/* list-tests arr<arr<char>>(path arr<char>) */
struct arr_1 list_tests(struct ctx* ctx, struct arr_0 path) {
	struct mut_list_1* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_0(_0);
	
	struct fun_act1_6 filter1;
	struct void_ _1 = (struct void_) {};
	filter1 = (struct fun_act1_6) {4, .as4 = _1};
	
	struct ctx* _2 = ctx;
	struct arr_0 _3 = path;
	struct fun_act1_6 _4 = filter1;
	struct list_tests__lambda1* temp0;
	struct ctx* _5 = ctx;
	uint64_t _6 = sizeof(struct list_tests__lambda1);
	uint8_t* _7 = alloc(_5, _6);
	temp0 = (struct list_tests__lambda1*) _7;
	
	struct list_tests__lambda1* _8 = temp0;
	struct mut_list_1* _9 = res0;
	struct list_tests__lambda1 _10 = (struct list_tests__lambda1) {_9};
	*_8 = _10;
	struct list_tests__lambda1* _11 = temp0;
	struct fun_act1_10 _12 = (struct fun_act1_10) {1, .as1 = _11};
	each_child_recursive(_2, _3, _4, _12);
	struct mut_list_1* _13 = res0;
	return move_to_arr_0(_13);
}
/* list-tests.lambda0 bool(s arr<char>) */
uint8_t list_tests__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 s) {
	return 1;
}
/* each-child-recursive void(path arr<char>, filter fun-act1<bool, arr<char>>, f fun-act1<void, arr<char>>) */
struct void_ each_child_recursive(struct ctx* ctx, struct arr_0 path, struct fun_act1_6 filter, struct fun_act1_10 f) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	uint8_t _2 = is_dir__q_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		struct ctx* _4 = ctx;
		struct arr_0 _5 = path;
		struct arr_1 _6 = read_dir_0(_4, _5);
		struct each_child_recursive__lambda0* temp0;
		struct ctx* _7 = ctx;
		uint64_t _8 = sizeof(struct each_child_recursive__lambda0);
		uint8_t* _9 = alloc(_7, _8);
		temp0 = (struct each_child_recursive__lambda0*) _9;
		
		struct each_child_recursive__lambda0* _10 = temp0;
		struct fun_act1_6 _11 = filter;
		struct arr_0 _12 = path;
		struct fun_act1_10 _13 = f;
		struct each_child_recursive__lambda0 _14 = (struct each_child_recursive__lambda0) {_11, _12, _13};
		*_10 = _14;
		struct each_child_recursive__lambda0* _15 = temp0;
		struct fun_act1_10 _16 = (struct fun_act1_10) {0, .as0 = _15};
		return each_1(_3, _6, _16);
	} else {
		struct ctx* _17 = ctx;
		struct fun_act1_10 _18 = f;
		struct arr_0 _19 = path;
		return call_15(_17, _18, _19);
	}
}
/* is-dir? bool(path arr<char>) */
uint8_t is_dir__q_0(struct ctx* ctx, struct arr_0 path) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	char* _3 = to_c_str(_1, _2);
	return is_dir__q_1(_0, _3);
}
/* is-dir? bool(path ptr<char>) */
uint8_t is_dir__q_1(struct ctx* ctx, char* path) {
	struct ctx* _0 = ctx;
	char* _1 = path;
	struct opt_9 _2 = get_stat(_0, _1);
	switch (_2.kind) {
		case 0: {
			return todo_6();
		}
		case 1: {
			struct some_9 s0 = _2.as1;
			
			struct some_9 _3 = s0;
			struct stat_t* _4 = _3.value;
			uint32_t _5 = _4->st_mode;
			struct ctx* _6 = ctx;
			uint32_t _7 = s_ifmt(_6);
			uint32_t _8 = _5 & _7;
			struct ctx* _9 = ctx;
			uint32_t _10 = s_ifdir(_9);
			return _op_equal_equal_5(_8, _10);
		}
		default:
			return (assert(0),0);
	}
}
/* get-stat opt<stat-t>(path ptr<char>) */
struct opt_9 get_stat(struct ctx* ctx, char* path) {
	struct stat_t* s0;
	struct ctx* _0 = ctx;
	s0 = empty_stat(_0);
	
	int32_t err1;
	char* _1 = path;
	struct stat_t* _2 = s0;
	err1 = stat(_1, _2);
	
	int32_t _3 = err1;
	int32_t _4 = 0;
	uint8_t _5 = _op_equal_equal_2(_3, _4);
	if (_5) {
		struct stat_t* _6 = s0;
		struct some_9 _7 = (struct some_9) {_6};
		return (struct opt_9) {1, .as1 = _7};
	} else {
		struct ctx* _8 = ctx;
		int32_t _9 = err1;
		int32_t _10 = -1;
		uint8_t _11 = _op_equal_equal_2(_9, _10);
		assert_0(_8, _11);
		int32_t _12 = errno;
		int32_t _13 = enoent();
		uint8_t _14 = _op_equal_equal_2(_12, _13);
		if (_14) {
			struct none _15 = (struct none) {};
			return (struct opt_9) {0, .as0 = _15};
		} else {
			return todo_5();
		}
	}
}
/* empty-stat stat-t() */
struct stat_t* empty_stat(struct ctx* ctx) {
	struct stat_t* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct stat_t);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct stat_t*) _2;
	
	struct stat_t* _3 = temp0;
	uint64_t _4 = 0u;
	uint32_t _5 = 0u;
	uint64_t _6 = 0u;
	uint32_t _7 = 0u;
	uint32_t _8 = 0u;
	uint64_t _9 = 0u;
	uint64_t _10 = 0u;
	uint64_t _11 = 0u;
	uint32_t _12 = 0u;
	int64_t _13 = 0;
	uint64_t _14 = 0u;
	uint64_t _15 = 0u;
	uint64_t _16 = 0u;
	uint64_t _17 = 0u;
	uint64_t _18 = 0u;
	uint64_t _19 = 0u;
	uint64_t _20 = 0u;
	uint64_t _21 = 0u;
	uint64_t _22 = 0u;
	uint64_t _23 = 0u;
	struct stat_t _24 = (struct stat_t) {_4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23};
	*_3 = _24;
	return temp0;
}
/* enoent int32() */
int32_t enoent(void) {
	return 2;
}
/* todo<opt<stat-t>> opt<stat-t>() */
struct opt_9 todo_5(void) {
	return (assert(0),(struct opt_9) {0});
}
/* todo<bool> bool() */
uint8_t todo_6(void) {
	return (assert(0),0);
}
/* ==<nat32> bool(a nat32, b nat32) */
uint8_t _op_equal_equal_5(uint32_t a, uint32_t b) {
	uint32_t _0 = a;
	uint32_t _1 = b;
	struct comparison _2 = compare_518(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<nat-32> (generated) (generated) */
struct comparison compare_518(uint32_t a, uint32_t b) {
	uint32_t _0 = a;
	uint32_t _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		uint32_t _4 = b;
		uint32_t _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* s-ifmt nat32() */
uint32_t s_ifmt(struct ctx* ctx) {
	return 61440u;
}
/* s-ifdir nat32() */
uint32_t s_ifdir(struct ctx* ctx) {
	return 16384u;
}
/* each<arr<char>> void(a arr<arr<char>>, f fun-act1<void, arr<char>>) */
struct void_ each_1(struct ctx* ctx, struct arr_1 a, struct fun_act1_10 f) {
	top:;
	struct arr_1 _0 = a;
	uint8_t _1 = empty__q_5(_0);
	uint8_t _2 = !_1;
	if (_2) {
		struct ctx* _3 = ctx;
		struct fun_act1_10 _4 = f;
		struct ctx* _5 = ctx;
		struct arr_1 _6 = a;
		struct arr_0 _7 = first_1(_5, _6);
		call_15(_3, _4, _7);
		struct ctx* _8 = ctx;
		struct arr_1 _9 = a;
		struct arr_1 _10 = tail_2(_8, _9);
		struct fun_act1_10 _11 = f;
		a = _10;
		f = _11;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* call<void, ?t> void(a fun-act1<void, arr<char>>, p0 arr<char>) */
struct void_ call_15(struct ctx* ctx, struct fun_act1_10 a, struct arr_0 p0) {
	struct fun_act1_10 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_523(_0, _1, _2);
}
/* call-w-ctx<void, arr<char>> (generated) (generated) */
struct void_ call_w_ctx_523(struct fun_act1_10 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_10 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct each_child_recursive__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct each_child_recursive__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			return each_child_recursive__lambda0(_1, _2, _3);
		}
		case 1: {
			struct list_tests__lambda1* closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct list_tests__lambda1* _5 = closure1;
			struct arr_0 _6 = p0;
			return list_tests__lambda1(_4, _5, _6);
		}
		case 2: {
			struct flat_map_with_max_size__lambda0* closure2 = _0.as2;
			
			struct ctx* _7 = ctx;
			struct flat_map_with_max_size__lambda0* _8 = closure2;
			struct arr_0 _9 = p0;
			return flat_map_with_max_size__lambda0(_7, _8, _9);
		}
		case 3: {
			struct list_lintable_files__lambda1* closure3 = _0.as3;
			
			struct ctx* _10 = ctx;
			struct list_lintable_files__lambda1* _11 = closure3;
			struct arr_0 _12 = p0;
			return list_lintable_files__lambda1(_10, _11, _12);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* read-dir arr<arr<char>>(path arr<char>) */
struct arr_1 read_dir_0(struct ctx* ctx, struct arr_0 path) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	char* _3 = to_c_str(_1, _2);
	return read_dir_1(_0, _3);
}
/* read-dir arr<arr<char>>(path ptr<char>) */
struct arr_1 read_dir_1(struct ctx* ctx, char* path) {
	struct dir* dirp0;
	char* _0 = path;
	dirp0 = opendir(_0);
	
	struct ctx* _1 = ctx;
	struct dir* _2 = dirp0;
	uint8_t** _3 = (uint8_t**) _2;
	uint8_t _4 = null__q_3(_3);
	forbid_0(_1, _4);
	struct mut_list_1* res1;
	struct ctx* _5 = ctx;
	res1 = new_mut_list_0(_5);
	
	struct ctx* _6 = ctx;
	struct dir* _7 = dirp0;
	struct mut_list_1* _8 = res1;
	read_dir_recur(_6, _7, _8);
	struct ctx* _9 = ctx;
	struct mut_list_1* _10 = res1;
	struct arr_1 _11 = move_to_arr_0(_10);
	return sort_0(_9, _11);
}
/* null?<ptr<nat8>> bool(a ptr<ptr<nat8>>) */
uint8_t null__q_3(uint8_t** a) {
	uint8_t** _0 = a;
	uint64_t _1 = (uint64_t) _0;
	uint8_t** _2 = NULL;
	uint64_t _3 = (uint64_t) _2;
	return _op_equal_equal_0(_1, _3);
}
/* read-dir-recur void(dirp dir, res mut-list<arr<char>>) */
struct void_ read_dir_recur(struct ctx* ctx, struct dir* dirp, struct mut_list_1* res) {
	top:;
	struct dirent* entry0;
	struct dirent* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct dirent);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct dirent*) _2;
	
	struct dirent* _3 = temp0;
	uint64_t _4 = 0u;
	int64_t _5 = 0;
	uint16_t _6 = 0u;
	char _7 = 0u;
	struct bytes256 _8 = zero_4();
	struct dirent _9 = (struct dirent) {_4, _5, _6, _7, _8};
	*_3 = _9;
	entry0 = temp0;
	
	struct cell_4* result1;
	struct cell_4* temp1;
	struct ctx* _10 = ctx;
	uint64_t _11 = sizeof(struct cell_4);
	uint8_t* _12 = alloc(_10, _11);
	temp1 = (struct cell_4*) _12;
	
	struct cell_4* _13 = temp1;
	struct dirent* _14 = entry0;
	struct cell_4 _15 = (struct cell_4) {_14};
	*_13 = _15;
	result1 = temp1;
	
	int32_t err2;
	struct dir* _16 = dirp;
	struct dirent* _17 = entry0;
	struct cell_4* _18 = result1;
	err2 = readdir_r(_16, _17, _18);
	
	struct ctx* _19 = ctx;
	int32_t _20 = err2;
	int32_t _21 = 0;
	uint8_t _22 = _op_equal_equal_2(_20, _21);
	assert_0(_19, _22);
	struct cell_4* _23 = result1;
	struct dirent* _24 = get_5(_23);
	uint8_t* _25 = (uint8_t*) _24;
	uint8_t _26 = null__q_0(_25);
	uint8_t _27 = !_26;
	if (_27) {
		struct ctx* _28 = ctx;
		struct cell_4* _29 = result1;
		struct dirent* _30 = get_5(_29);
		struct dirent* _31 = entry0;
		uint8_t _32 = ref_eq__q(_30, _31);
		assert_0(_28, _32);
		struct arr_0 name3;
		struct dirent* _33 = entry0;
		name3 = get_dirent_name(_33);
		
		struct arr_0 _34 = name3;
		struct arr_0 _35 = (struct arr_0) {1, constantarr_0_32};
		uint8_t _36 = _op_bang_equal_3(_34, _35);uint8_t _37;
		
		if (_36) {
			struct arr_0 _38 = name3;
			struct arr_0 _39 = (struct arr_0) {2, constantarr_0_33};
			_37 = _op_bang_equal_3(_38, _39);
		} else {
			_37 = 0;
		}
		if (_37) {
			struct ctx* _40 = ctx;
			struct mut_list_1* _41 = res;
			struct dirent* _42 = entry0;
			struct arr_0 _43 = get_dirent_name(_42);
			push_0(_40, _41, _43);
		} else {
			(struct void_) {};
		}
		struct dir* _44 = dirp;
		struct mut_list_1* _45 = res;
		dirp = _44;
		res = _45;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* zero bytes256() */
struct bytes256 zero_4(void) {
	struct bytes128 _0 = zero_3();
	struct bytes128 _1 = zero_3();
	return (struct bytes256) {_0, _1};
}
/* get<dirent> dirent(c cell<dirent>) */
struct dirent* get_5(struct cell_4* c) {
	struct cell_4* _0 = c;
	return _0->value;
}
/* ref-eq?<dirent> bool(a dirent, b dirent) */
uint8_t ref_eq__q(struct dirent* a, struct dirent* b) {
	struct dirent* _0 = a;
	uint8_t* _1 = (uint8_t*) _0;
	struct dirent* _2 = b;
	uint8_t* _3 = (uint8_t*) _2;
	return _1 == _3;
}
/* get-dirent-name arr<char>(d dirent) */
struct arr_0 get_dirent_name(struct dirent* d) {
	uint64_t name_offset0;
	uint64_t _0 = sizeof(uint64_t);
	uint64_t _1 = sizeof(int64_t);
	uint64_t _2 = _0 + _1;
	uint64_t _3 = sizeof(uint16_t);
	uint64_t _4 = _2 + _3;
	uint64_t _5 = sizeof(char);
	name_offset0 = _4 + _5;
	
	uint8_t* name_ptr1;
	struct dirent* _6 = d;
	uint8_t* _7 = (uint8_t*) _6;
	uint64_t _8 = name_offset0;
	name_ptr1 = _7 + _8;
	
	uint8_t* _9 = name_ptr1;
	char* _10 = (char*) _9;
	return to_str_1(_10);
}
/* !=<arr<char>> bool(a arr<char>, b arr<char>) */
uint8_t _op_bang_equal_3(struct arr_0 a, struct arr_0 b) {
	struct arr_0 _0 = a;
	struct arr_0 _1 = b;
	uint8_t _2 = _op_equal_equal_4(_0, _1);
	return !_2;
}
/* sort<arr<char>> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 sort_0(struct ctx* ctx, struct arr_1 a) {
	struct mut_arr_1 res0;
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	res0 = copy_to_mut_arr(_0, _1);
	
	struct ctx* _2 = ctx;
	struct mut_arr_1 _3 = res0;
	sort_1(_2, _3);
	struct mut_arr_1 _4 = res0;
	return cast_immutable_0(_4);
}
/* copy-to-mut-arr<?t> mut-arr<arr<char>>(a arr<arr<char>>) */
struct mut_arr_1 copy_to_mut_arr(struct ctx* ctx, struct arr_1 a) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	struct copy_to_mut_arr__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct copy_to_mut_arr__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct copy_to_mut_arr__lambda0*) _5;
	
	struct copy_to_mut_arr__lambda0* _6 = temp0;
	struct arr_1 _7 = a;
	struct copy_to_mut_arr__lambda0 _8 = (struct copy_to_mut_arr__lambda0) {_7};
	*_6 = _8;
	struct copy_to_mut_arr__lambda0* _9 = temp0;
	struct fun_act1_5 _10 = (struct fun_act1_5) {1, .as1 = _9};
	return make_mut_arr_0(_0, _2, _10);
}
/* copy-to-mut-arr<?t>.lambda0 arr<char>(i nat) */
struct arr_0 copy_to_mut_arr__lambda0(struct ctx* ctx, struct copy_to_mut_arr__lambda0* _closure, uint64_t i) {
	struct ctx* _0 = ctx;
	struct copy_to_mut_arr__lambda0* _1 = _closure;
	struct arr_1 _2 = _1->a;
	uint64_t _3 = i;
	return at_2(_0, _2, _3);
}
/* sort<?t> void(a mut-arr<arr<char>>) */
struct void_ sort_1(struct ctx* ctx, struct mut_arr_1 a) {
	top:;
	struct mut_arr_1 _0 = a;
	uint64_t _1 = size_1(_0);
	uint64_t _2 = 1u;
	uint8_t _3 = _op_greater(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_arr_1 _5 = a;
		uint64_t _6 = 0u;
		struct ctx* _7 = ctx;
		struct mut_arr_1 _8 = a;
		uint64_t _9 = size_1(_8);
		uint64_t _10 = 2u;
		uint64_t _11 = _op_div(_7, _9, _10);
		swap_0(_4, _5, _6, _11);
		struct arr_0 pivot0;
		struct ctx* _12 = ctx;
		struct mut_arr_1 _13 = a;
		uint64_t _14 = 0u;
		pivot0 = at_7(_12, _13, _14);
		
		uint64_t index_of_first_value_gt_pivot1;
		struct ctx* _15 = ctx;
		struct mut_arr_1 _16 = a;
		struct arr_0 _17 = pivot0;
		uint64_t _18 = 1u;
		struct ctx* _19 = ctx;
		struct mut_arr_1 _20 = a;
		uint64_t _21 = size_1(_20);
		uint64_t _22 = decr(_19, _21);
		index_of_first_value_gt_pivot1 = partition_recur(_15, _16, _17, _18, _22);
		
		uint64_t new_pivot_index2;
		struct ctx* _23 = ctx;
		uint64_t _24 = index_of_first_value_gt_pivot1;
		new_pivot_index2 = decr(_23, _24);
		
		struct ctx* _25 = ctx;
		struct mut_arr_1 _26 = a;
		uint64_t _27 = 0u;
		uint64_t _28 = new_pivot_index2;
		swap_0(_25, _26, _27, _28);
		struct ctx* _29 = ctx;
		struct ctx* _30 = ctx;
		struct mut_arr_1 _31 = a;
		uint64_t _32 = 0u;
		uint64_t _33 = new_pivot_index2;
		struct mut_arr_1 _34 = slice_3(_30, _31, _32, _33);
		sort_1(_29, _34);
		struct ctx* _35 = ctx;
		struct mut_arr_1 _36 = a;
		uint64_t _37 = new_pivot_index2;
		struct mut_arr_1 _38 = slice_after_1(_35, _36, _37);
		a = _38;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* swap<?t> void(a mut-arr<arr<char>>, x nat, y nat) */
struct void_ swap_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t x, uint64_t y) {
	struct arr_0 old_x0;
	struct ctx* _0 = ctx;
	struct mut_arr_1 _1 = a;
	uint64_t _2 = x;
	old_x0 = at_7(_0, _1, _2);
	
	struct ctx* _3 = ctx;
	struct mut_arr_1 _4 = a;
	uint64_t _5 = x;
	struct ctx* _6 = ctx;
	struct mut_arr_1 _7 = a;
	uint64_t _8 = y;
	struct arr_0 _9 = at_7(_6, _7, _8);
	set_at_0(_3, _4, _5, _9);
	struct ctx* _10 = ctx;
	struct mut_arr_1 _11 = a;
	uint64_t _12 = y;
	struct arr_0 _13 = old_x0;
	return set_at_0(_10, _11, _12, _13);
}
/* at<?t> arr<char>(a mut-arr<arr<char>>, index nat) */
struct arr_0 at_7(struct ctx* ctx, struct mut_arr_1 a, uint64_t index) {
	struct ctx* _0 = ctx;
	struct mut_arr_1 _1 = a;
	struct arr_1 _2 = _1.arr;
	uint64_t _3 = index;
	return at_2(_0, _2, _3);
}
/* partition-recur<?t> nat(a mut-arr<arr<char>>, pivot arr<char>, l nat, r nat) */
uint64_t partition_recur(struct ctx* ctx, struct mut_arr_1 a, struct arr_0 pivot, uint64_t l, uint64_t r) {
	top:;
	struct ctx* _0 = ctx;
	uint64_t _1 = l;
	struct mut_arr_1 _2 = a;
	uint64_t _3 = size_1(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	uint64_t _6 = r;
	struct mut_arr_1 _7 = a;
	uint64_t _8 = size_1(_7);
	uint8_t _9 = _op_less_0(_6, _8);
	assert_0(_5, _9);
	uint64_t _10 = l;
	uint64_t _11 = r;
	uint8_t _12 = _op_less_equal(_10, _11);
	if (_12) {
		struct arr_0 em0;
		struct ctx* _13 = ctx;
		struct mut_arr_1 _14 = a;
		uint64_t _15 = l;
		em0 = at_7(_13, _14, _15);
		
		struct arr_0 _16 = em0;
		struct arr_0 _17 = pivot;
		uint8_t _18 = _op_less_2(_16, _17);
		if (_18) {
			struct mut_arr_1 _19 = a;
			struct arr_0 _20 = pivot;
			struct ctx* _21 = ctx;
			uint64_t _22 = l;
			uint64_t _23 = incr_3(_21, _22);
			uint64_t _24 = r;
			a = _19;
			pivot = _20;
			l = _23;
			r = _24;
			goto top;
		} else {
			struct ctx* _25 = ctx;
			struct mut_arr_1 _26 = a;
			uint64_t _27 = l;
			uint64_t _28 = r;
			swap_0(_25, _26, _27, _28);
			struct mut_arr_1 _29 = a;
			struct arr_0 _30 = pivot;
			uint64_t _31 = l;
			struct ctx* _32 = ctx;
			uint64_t _33 = r;
			uint64_t _34 = decr(_32, _33);
			a = _29;
			pivot = _30;
			l = _31;
			r = _34;
			goto top;
		}
	} else {
		return l;
	}
}
/* <<?t> bool(a arr<char>, b arr<char>) */
uint8_t _op_less_2(struct arr_0 a, struct arr_0 b) {
	struct arr_0 _0 = a;
	struct arr_0 _1 = b;
	struct comparison _2 = compare_335(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* slice-after<?t> mut-arr<arr<char>>(a mut-arr<arr<char>>, before-begin nat) */
struct mut_arr_1 slice_after_1(struct ctx* ctx, struct mut_arr_1 a, uint64_t before_begin) {
	struct ctx* _0 = ctx;
	struct mut_arr_1 _1 = a;
	struct ctx* _2 = ctx;
	uint64_t _3 = before_begin;
	uint64_t _4 = incr_3(_2, _3);
	return slice_starting_at_3(_0, _1, _4);
}
/* each-child-recursive.lambda0 void(child-name arr<char>) */
struct void_ each_child_recursive__lambda0(struct ctx* ctx, struct each_child_recursive__lambda0* _closure, struct arr_0 child_name) {
	struct ctx* _0 = ctx;
	struct each_child_recursive__lambda0* _1 = _closure;
	struct fun_act1_6 _2 = _1->filter;
	struct arr_0 _3 = child_name;
	uint8_t _4 = call_8(_0, _2, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct ctx* _6 = ctx;
		struct each_child_recursive__lambda0* _7 = _closure;
		struct arr_0 _8 = _7->path;
		struct arr_0 _9 = child_name;
		struct arr_0 _10 = child_path(_6, _8, _9);
		struct each_child_recursive__lambda0* _11 = _closure;
		struct fun_act1_6 _12 = _11->filter;
		struct each_child_recursive__lambda0* _13 = _closure;
		struct fun_act1_10 _14 = _13->f;
		return each_child_recursive(_5, _10, _12, _14);
	} else {
		return (struct void_) {};
	}
}
/* get-extension opt<arr<char>>(name arr<char>) */
struct opt_8 get_extension(struct ctx* ctx, struct arr_0 name) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = name;
	char _2 = 46u;
	struct opt_5 _3 = last_index_of(_0, _1, _2);
	switch (_3.kind) {
		case 0: {
			struct none _4 = (struct none) {};
			return (struct opt_8) {0, .as0 = _4};
		}
		case 1: {
			struct some_5 s0 = _3.as1;
			
			struct ctx* _5 = ctx;
			struct arr_0 _6 = name;
			struct some_5 _7 = s0;
			uint64_t _8 = _7.value;
			struct arr_0 _9 = slice_after_2(_5, _6, _8);
			struct some_8 _10 = (struct some_8) {_9};
			return (struct opt_8) {1, .as1 = _10};
		}
		default:
			return (assert(0),(struct opt_8) {0});
	}
}
/* last-index-of opt<nat>(s arr<char>, c char) */
struct opt_5 last_index_of(struct ctx* ctx, struct arr_0 s, char c) {
	top:;
	struct arr_0 _0 = s;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		struct none _2 = (struct none) {};
		return (struct opt_5) {0, .as0 = _2};
	} else {
		struct ctx* _3 = ctx;
		struct arr_0 _4 = s;
		char _5 = last(_3, _4);
		char _6 = c;
		uint8_t _7 = _op_equal_equal_3(_5, _6);
		if (_7) {
			struct ctx* _8 = ctx;
			struct arr_0 _9 = s;
			uint64_t _10 = _9.size;
			uint64_t _11 = decr(_8, _10);
			struct some_5 _12 = (struct some_5) {_11};
			return (struct opt_5) {1, .as1 = _12};
		} else {
			struct ctx* _13 = ctx;
			struct arr_0 _14 = s;
			struct arr_0 _15 = rtail(_13, _14);
			char _16 = c;
			s = _15;
			c = _16;
			goto top;
		}
	}
}
/* last<char> char(a arr<char>) */
char last(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	uint8_t _2 = empty__q_0(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_0 _4 = a;
	struct ctx* _5 = ctx;
	struct arr_0 _6 = a;
	uint64_t _7 = _6.size;
	uint64_t _8 = decr(_5, _7);
	return at_3(_3, _4, _8);
}
/* rtail<char> arr<char>(a arr<char>) */
struct arr_0 rtail(struct ctx* ctx, struct arr_0 a) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	uint8_t _2 = empty__q_0(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_0 _4 = a;
	uint64_t _5 = 0u;
	struct ctx* _6 = ctx;
	struct arr_0 _7 = a;
	uint64_t _8 = _7.size;
	uint64_t _9 = decr(_6, _8);
	return slice_1(_3, _4, _5, _9);
}
/* slice-after<char> arr<char>(a arr<char>, before-begin nat) */
struct arr_0 slice_after_2(struct ctx* ctx, struct arr_0 a, uint64_t before_begin) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct ctx* _2 = ctx;
	uint64_t _3 = before_begin;
	uint64_t _4 = incr_3(_2, _3);
	return slice_starting_at_1(_0, _1, _4);
}
/* base-name arr<char>(path arr<char>) */
struct arr_0 base_name(struct ctx* ctx, struct arr_0 path) {
	struct opt_5 i0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	char _2 = 47u;
	i0 = last_index_of(_0, _1, _2);
	
	struct opt_5 _3 = i0;
	switch (_3.kind) {
		case 0: {
			return path;
		}
		case 1: {
			struct some_5 s1 = _3.as1;
			
			struct ctx* _4 = ctx;
			struct arr_0 _5 = path;
			struct some_5 _6 = s1;
			uint64_t _7 = _6.value;
			return slice_after_2(_4, _5, _7);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* list-tests.lambda1 void(child arr<char>) */
struct void_ list_tests__lambda1(struct ctx* ctx, struct list_tests__lambda1* _closure, struct arr_0 child) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = child;
	struct arr_0 _3 = base_name(_1, _2);
	struct opt_8 _4 = get_extension(_0, _3);
	switch (_4.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_8 s0 = _4.as1;
			
			struct some_8 _5 = s0;
			struct arr_0 _6 = _5.value;
			struct arr_0 _7 = (struct arr_0) {2, constantarr_0_34};
			uint8_t _8 = _op_equal_equal_4(_6, _7);
			if (_8) {
				struct ctx* _9 = ctx;
				struct list_tests__lambda1* _10 = _closure;
				struct mut_list_1* _11 = _10->res;
				struct arr_0 _12 = child;
				return push_0(_9, _11, _12);
			} else {
				return (struct void_) {};
			}
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* flat-map-with-max-size<failure, arr<char>> arr<failure>(a arr<arr<char>>, max-size nat, mapper fun-act1<arr<failure>, arr<char>>) */
struct arr_7 flat_map_with_max_size(struct ctx* ctx, struct arr_1 a, uint64_t max_size, struct fun_act1_11 mapper) {
	struct mut_list_4* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_2(_0);
	
	struct ctx* _1 = ctx;
	struct arr_1 _2 = a;
	struct flat_map_with_max_size__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct flat_map_with_max_size__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct flat_map_with_max_size__lambda0*) _5;
	
	struct flat_map_with_max_size__lambda0* _6 = temp0;
	struct mut_list_4* _7 = res0;
	uint64_t _8 = max_size;
	struct fun_act1_11 _9 = mapper;
	struct flat_map_with_max_size__lambda0 _10 = (struct flat_map_with_max_size__lambda0) {_7, _8, _9};
	*_6 = _10;
	struct flat_map_with_max_size__lambda0* _11 = temp0;
	struct fun_act1_10 _12 = (struct fun_act1_10) {2, .as2 = _11};
	each_1(_1, _2, _12);
	struct mut_list_4* _13 = res0;
	return move_to_arr_3(_13);
}
/* new-mut-list<?out> mut-list<failure>() */
struct mut_list_4* new_mut_list_2(struct ctx* ctx) {
	struct mut_list_4* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct mut_list_4);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct mut_list_4*) _2;
	
	struct mut_list_4* _3 = temp0;
	struct mut_arr_5 _4 = empty_mut_arr_3();
	uint64_t _5 = 0u;
	struct mut_list_4 _6 = (struct mut_list_4) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-mut-arr<?t> mut-arr<failure>() */
struct mut_arr_5 empty_mut_arr_3(void) {
	struct arr_7 _0 = empty_arr_4();
	return (struct mut_arr_5) {_0};
}
/* empty-arr<?t> arr<failure>() */
struct arr_7 empty_arr_4(void) {
	uint64_t _0 = 0u;
	struct failure** _1 = NULL;
	return (struct arr_7) {_0, _1};
}
/* push-all<?out> void(a mut-list<failure>, values arr<failure>) */
struct void_ push_all(struct ctx* ctx, struct mut_list_4* a, struct arr_7 values) {
	struct ctx* _0 = ctx;
	struct arr_7 _1 = values;
	struct push_all__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct push_all__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct push_all__lambda0*) _4;
	
	struct push_all__lambda0* _5 = temp0;
	struct mut_list_4* _6 = a;
	struct push_all__lambda0 _7 = (struct push_all__lambda0) {_6};
	*_5 = _7;
	struct push_all__lambda0* _8 = temp0;
	struct fun_act1_12 _9 = (struct fun_act1_12) {0, .as0 = _8};
	return each_2(_0, _1, _9);
}
/* each<?t> void(a arr<failure>, f fun-act1<void, failure>) */
struct void_ each_2(struct ctx* ctx, struct arr_7 a, struct fun_act1_12 f) {
	top:;
	struct arr_7 _0 = a;
	uint8_t _1 = empty__q_10(_0);
	uint8_t _2 = !_1;
	if (_2) {
		struct ctx* _3 = ctx;
		struct fun_act1_12 _4 = f;
		struct ctx* _5 = ctx;
		struct arr_7 _6 = a;
		struct failure* _7 = first_3(_5, _6);
		call_16(_3, _4, _7);
		struct ctx* _8 = ctx;
		struct arr_7 _9 = a;
		struct arr_7 _10 = tail_4(_8, _9);
		struct fun_act1_12 _11 = f;
		a = _10;
		f = _11;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* empty?<?t> bool(a arr<failure>) */
uint8_t empty__q_10(struct arr_7 a) {
	struct arr_7 _0 = a;
	uint64_t _1 = _0.size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* call<void, ?t> void(a fun-act1<void, failure>, p0 failure) */
struct void_ call_16(struct ctx* ctx, struct fun_act1_12 a, struct failure* p0) {
	struct fun_act1_12 _0 = a;
	struct ctx* _1 = ctx;
	struct failure* _2 = p0;
	return call_w_ctx_560(_0, _1, _2);
}
/* call-w-ctx<void, gc-ptr(failure)> (generated) (generated) */
struct void_ call_w_ctx_560(struct fun_act1_12 a, struct ctx* ctx, struct failure* p0) {
	struct fun_act1_12 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct push_all__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct push_all__lambda0* _2 = closure0;
			struct failure* _3 = p0;
			return push_all__lambda0(_1, _2, _3);
		}
		case 1: {
			struct void_ closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct void_ _5 = closure1;
			struct failure* _6 = p0;
			return print_failures__lambda0(_4, _5, _6);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* first<?t> failure(a arr<failure>) */
struct failure* first_3(struct ctx* ctx, struct arr_7 a) {
	struct ctx* _0 = ctx;
	struct arr_7 _1 = a;
	uint8_t _2 = empty__q_10(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_7 _4 = a;
	uint64_t _5 = 0u;
	return at_8(_3, _4, _5);
}
/* at<?t> failure(a arr<failure>, index nat) */
struct failure* at_8(struct ctx* ctx, struct arr_7 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_7 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_7 _5 = a;
	uint64_t _6 = index;
	return noctx_at_9(_5, _6);
}
/* noctx-at<?t> failure(a arr<failure>, index nat) */
struct failure* noctx_at_9(struct arr_7 a, uint64_t index) {
	uint64_t _0 = index;
	struct arr_7 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct arr_7 _4 = a;
	struct failure** _5 = _4.data;
	uint64_t _6 = index;
	struct failure** _7 = _5 + _6;
	return *_7;
}
/* tail<?t> arr<failure>(a arr<failure>) */
struct arr_7 tail_4(struct ctx* ctx, struct arr_7 a) {
	struct ctx* _0 = ctx;
	struct arr_7 _1 = a;
	uint8_t _2 = empty__q_10(_1);
	forbid_0(_0, _2);
	struct ctx* _3 = ctx;
	struct arr_7 _4 = a;
	uint64_t _5 = 1u;
	return slice_starting_at_6(_3, _4, _5);
}
/* slice-starting-at<?t> arr<failure>(a arr<failure>, begin nat) */
struct arr_7 slice_starting_at_6(struct ctx* ctx, struct arr_7 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct arr_7 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct arr_7 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct arr_7 _9 = a;
	uint64_t _10 = _9.size;
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_6(_5, _6, _7, _12);
}
/* slice<?t> arr<failure>(a arr<failure>, begin nat, size nat) */
struct arr_7 slice_6(struct ctx* ctx, struct arr_7 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct arr_7 _5 = a;
	uint64_t _6 = _5.size;
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct arr_7 _9 = a;
	struct failure** _10 = _9.data;
	uint64_t _11 = begin;
	struct failure** _12 = _10 + _11;
	return (struct arr_7) {_8, _12};
}
/* push<?t> void(a mut-list<failure>, value failure) */
struct void_ push_2(struct ctx* ctx, struct mut_list_4* a, struct failure* value) {
	struct mut_list_4* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_4* _2 = a;
	uint64_t _3 = capacity_3(_2);
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct mut_list_4* _6 = a;
		struct mut_list_4* _7 = a;
		uint64_t _8 = _7->size;
		uint64_t _9 = 0u;
		uint8_t _10 = _op_equal_equal_0(_8, _9);uint64_t _11;
		
		if (_10) {
			_11 = 4u;
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_4* _13 = a;
			uint64_t _14 = _13->size;
			uint64_t _15 = 2u;
			_11 = _op_times_0(_12, _14, _15);
		}
		increase_capacity_to_2(_5, _6, _11);
	} else {
		(struct void_) {};
	}
	struct ctx* _16 = ctx;
	struct mut_list_4* _17 = a;
	struct ctx* _18 = ctx;
	struct ctx* _19 = ctx;
	struct mut_list_4* _20 = a;
	uint64_t _21 = _20->size;
	uint64_t _22 = incr_3(_19, _21);
	uint64_t _23 = round_up_to_power_of_two(_18, _22);
	ensure_capacity_2(_16, _17, _23);
	struct ctx* _24 = ctx;
	struct mut_list_4* _25 = a;
	uint64_t _26 = _25->size;
	struct mut_list_4* _27 = a;
	uint64_t _28 = capacity_3(_27);
	uint8_t _29 = _op_less_0(_26, _28);
	assert_0(_24, _29);
	struct mut_list_4* _30 = a;
	struct failure** _31 = data_9(_30);
	struct mut_list_4* _32 = a;
	uint64_t _33 = _32->size;
	struct failure** _34 = _31 + _33;
	struct failure* _35 = value;
	*_34 = _35;
	struct mut_list_4* _36 = a;
	struct ctx* _37 = ctx;
	struct mut_list_4* _38 = a;
	uint64_t _39 = _38->size;
	uint64_t _40 = incr_3(_37, _39);
	return (_36->size = _40, (struct void_) {});
}
/* capacity<?t> nat(a mut-list<failure>) */
uint64_t capacity_3(struct mut_list_4* a) {
	struct mut_list_4* _0 = a;
	struct mut_arr_5 _1 = _0->backing;
	return size_6(_1);
}
/* size<?t> nat(a mut-arr<failure>) */
uint64_t size_6(struct mut_arr_5 a) {
	struct mut_arr_5 _0 = a;
	struct arr_7 _1 = _0.arr;
	return _1.size;
}
/* increase-capacity-to<?t> void(a mut-list<failure>, new-capacity nat) */
struct void_ increase_capacity_to_2(struct ctx* ctx, struct mut_list_4* a, uint64_t new_capacity) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_capacity;
	struct mut_list_4* _2 = a;
	uint64_t _3 = capacity_3(_2);
	uint8_t _4 = _op_greater(_1, _3);
	assert_0(_0, _4);
	struct failure** old_data0;
	struct mut_list_4* _5 = a;
	old_data0 = data_9(_5);
	
	struct mut_list_4* _6 = a;
	uint64_t _7 = new_capacity;
	struct ctx* _8 = ctx;
	uint64_t _9 = new_capacity;
	struct failure** _10 = uninitialized_data_4(_8, _9);
	struct mut_arr_5 _11 = mut_arr_5(_7, _10);
	_6->backing = _11;
	struct ctx* _12 = ctx;
	struct mut_list_4* _13 = a;
	struct failure** _14 = data_9(_13);
	struct failure** _15 = old_data0;
	struct mut_list_4* _16 = a;
	uint64_t _17 = _16->size;
	copy_data_from_3(_12, _14, _15, _17);
	struct ctx* _18 = ctx;
	struct mut_list_4* _19 = a;
	struct mut_arr_5 _20 = _19->backing;
	struct mut_list_4* _21 = a;
	uint64_t _22 = _21->size;
	struct mut_arr_5 _23 = slice_starting_at_7(_18, _20, _22);
	return set_zero_elements_2(_23);
}
/* data<?t> ptr<failure>(a mut-list<failure>) */
struct failure** data_9(struct mut_list_4* a) {
	struct mut_list_4* _0 = a;
	struct mut_arr_5 _1 = _0->backing;
	return data_10(_1);
}
/* data<?t> ptr<failure>(a mut-arr<failure>) */
struct failure** data_10(struct mut_arr_5 a) {
	struct mut_arr_5 _0 = a;
	struct arr_7 _1 = _0.arr;
	return _1.data;
}
/* mut-arr<?t> mut-arr<failure>(size nat, data ptr<failure>) */
struct mut_arr_5 mut_arr_5(uint64_t size, struct failure** data) {
	uint64_t _0 = size;
	struct failure** _1 = data;
	struct arr_7 _2 = (struct arr_7) {_0, _1};
	return (struct mut_arr_5) {_2};
}
/* uninitialized-data<?t> ptr<failure>(size nat) */
struct failure** uninitialized_data_4(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(struct failure*);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (struct failure**) _4;
}
/* copy-data-from<?t> void(to ptr<failure>, from ptr<failure>, len nat) */
struct void_ copy_data_from_3(struct ctx* ctx, struct failure** to, struct failure** from, uint64_t len) {
	top:;
	uint64_t _0 = len;
	uint64_t _1 = 8u;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		struct failure** _4 = to;
		struct failure** _5 = from;
		uint64_t _6 = len;
		return copy_data_from_small_3(_3, _4, _5, _6);
	} else {
		uint64_t hl0;
		struct ctx* _7 = ctx;
		uint64_t _8 = len;
		uint64_t _9 = 2u;
		hl0 = _op_div(_7, _8, _9);
		
		struct ctx* _10 = ctx;
		struct failure** _11 = to;
		struct failure** _12 = from;
		uint64_t _13 = hl0;
		copy_data_from_3(_10, _11, _12, _13);
		struct failure** _14 = to;
		uint64_t _15 = hl0;
		struct failure** _16 = _14 + _15;
		struct failure** _17 = from;
		uint64_t _18 = hl0;
		struct failure** _19 = _17 + _18;
		struct ctx* _20 = ctx;
		uint64_t _21 = len;
		uint64_t _22 = hl0;
		uint64_t _23 = _op_minus_2(_20, _21, _22);
		to = _16;
		from = _19;
		len = _23;
		goto top;
	}
}
/* copy-data-from-small<?t> void(to ptr<failure>, from ptr<failure>, len nat) */
struct void_ copy_data_from_small_3(struct ctx* ctx, struct failure** to, struct failure** from, uint64_t len) {
	uint64_t _0 = len;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		struct failure** _3 = to;
		struct failure** _4 = from;
		struct failure* _5 = *_4;
		*_3 = _5;
		struct ctx* _6 = ctx;
		struct failure** _7 = to;
		struct failure** _8 = incr_7(_7);
		struct failure** _9 = from;
		struct failure** _10 = incr_7(_9);
		struct ctx* _11 = ctx;
		uint64_t _12 = len;
		uint64_t _13 = decr(_11, _12);
		return copy_data_from_3(_6, _8, _10, _13);
	} else {
		return (struct void_) {};
	}
}
/* incr<?t> ptr<failure>(p ptr<failure>) */
struct failure** incr_7(struct failure** p) {
	struct failure** _0 = p;
	uint64_t _1 = 1u;
	return _0 + _1;
}
/* set-zero-elements<?t> void(a mut-arr<failure>) */
struct void_ set_zero_elements_2(struct mut_arr_5 a) {
	struct mut_arr_5 _0 = a;
	struct failure** _1 = data_10(_0);
	struct mut_arr_5 _2 = a;
	uint64_t _3 = size_6(_2);
	return set_zero_range_3(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<failure>, size nat) */
struct void_ set_zero_range_3(struct failure** begin, uint64_t size) {
	struct failure** _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(struct failure*);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* slice-starting-at<?t> mut-arr<failure>(a mut-arr<failure>, begin nat) */
struct mut_arr_5 slice_starting_at_7(struct ctx* ctx, struct mut_arr_5 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct mut_arr_5 _2 = a;
	uint64_t _3 = size_6(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_arr_5 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct mut_arr_5 _9 = a;
	uint64_t _10 = size_6(_9);
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_7(_5, _6, _7, _12);
}
/* slice<?t> mut-arr<failure>(a mut-arr<failure>, begin nat, size nat) */
struct mut_arr_5 slice_7(struct ctx* ctx, struct mut_arr_5 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct mut_arr_5 _5 = a;
	uint64_t _6 = size_6(_5);
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct mut_arr_5 _9 = a;
	struct failure** _10 = data_10(_9);
	uint64_t _11 = begin;
	struct failure** _12 = _10 + _11;
	return mut_arr_5(_8, _12);
}
/* ensure-capacity<?t> void(a mut-list<failure>, capacity nat) */
struct void_ ensure_capacity_2(struct ctx* ctx, struct mut_list_4* a, uint64_t capacity) {
	struct mut_list_4* _0 = a;
	uint64_t _1 = capacity_3(_0);
	uint64_t _2 = capacity;
	uint8_t _3 = _op_less_0(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_4* _5 = a;
		struct ctx* _6 = ctx;
		uint64_t _7 = capacity;
		uint64_t _8 = round_up_to_power_of_two(_6, _7);
		return increase_capacity_to_2(_4, _5, _8);
	} else {
		return (struct void_) {};
	}
}
/* push-all<?out>.lambda0 void(it failure) */
struct void_ push_all__lambda0(struct ctx* ctx, struct push_all__lambda0* _closure, struct failure* it) {
	struct ctx* _0 = ctx;
	struct push_all__lambda0* _1 = _closure;
	struct mut_list_4* _2 = _1->a;
	struct failure* _3 = it;
	return push_2(_0, _2, _3);
}
/* call<arr<?out>, ?in> arr<failure>(a fun-act1<arr<failure>, arr<char>>, p0 arr<char>) */
struct arr_7 call_17(struct ctx* ctx, struct fun_act1_11 a, struct arr_0 p0) {
	struct fun_act1_11 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_585(_0, _1, _2);
}
/* call-w-ctx<arr<failure>, arr<char>> (generated) (generated) */
struct arr_7 call_w_ctx_585(struct fun_act1_11 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_11 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct run_noze_tests__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct run_noze_tests__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			return run_noze_tests__lambda0(_1, _2, _3);
		}
		case 1: {
			struct lint__lambda0* closure1 = _0.as1;
			
			struct ctx* _4 = ctx;
			struct lint__lambda0* _5 = closure1;
			struct arr_0 _6 = p0;
			return lint__lambda0(_4, _5, _6);
		}
		default:
			return (assert(0),(struct arr_7) {0, NULL});
	}
}
/* reduce-size-if-more-than<?out> void(a mut-list<failure>, new-size nat) */
struct void_ reduce_size_if_more_than(struct ctx* ctx, struct mut_list_4* a, uint64_t new_size) {
	top:;
	uint64_t _0 = new_size;
	struct mut_list_4* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_4* _5 = a;
		struct opt_10 _6 = pop(_4, _5);
		drop_2(_6);
		struct mut_list_4* _7 = a;
		uint64_t _8 = new_size;
		a = _7;
		new_size = _8;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* drop<opt<?t>> void(_ opt<failure>) */
struct void_ drop_2(struct opt_10 _p0) {
	return (struct void_) {};
}
/* pop<?t> opt<failure>(a mut-list<failure>) */
struct opt_10 pop(struct ctx* ctx, struct mut_list_4* a) {
	struct mut_list_4* _0 = a;
	uint8_t _1 = empty__q_11(_0);
	if (_1) {
		struct none _2 = (struct none) {};
		return (struct opt_10) {0, .as0 = _2};
	} else {
		uint64_t new_size0;
		struct mut_list_4* _3 = a;
		uint64_t _4 = _3->size;
		new_size0 = noctx_decr(_4);
		
		struct failure* res1;
		struct ctx* _5 = ctx;
		struct mut_list_4* _6 = a;
		uint64_t _7 = new_size0;
		res1 = at_9(_5, _6, _7);
		
		struct ctx* _8 = ctx;
		struct mut_list_4* _9 = a;
		uint64_t _10 = new_size0;
		struct failure* _11 = NULL;
		set_at_3(_8, _9, _10, _11);
		struct mut_list_4* _12 = a;
		uint64_t _13 = new_size0;
		_12->size = _13;
		struct failure* _14 = res1;
		struct some_10 _15 = (struct some_10) {_14};
		return (struct opt_10) {1, .as1 = _15};
	}
}
/* empty?<?t> bool(a mut-list<failure>) */
uint8_t empty__q_11(struct mut_list_4* a) {
	struct mut_list_4* _0 = a;
	uint64_t _1 = _0->size;
	uint64_t _2 = 0u;
	return _op_equal_equal_0(_1, _2);
}
/* at<?t> failure(a mut-list<failure>, index nat) */
struct failure* at_9(struct ctx* ctx, struct mut_list_4* a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_list_4* _2 = a;
	uint64_t _3 = _2->size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_list_4* _5 = a;
	uint64_t _6 = index;
	return noctx_at_10(_5, _6);
}
/* noctx-at<?t> failure(a mut-list<failure>, index nat) */
struct failure* noctx_at_10(struct mut_list_4* a, uint64_t index) {
	uint64_t _0 = index;
	struct mut_list_4* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_4* _4 = a;
	struct failure** _5 = data_9(_4);
	uint64_t _6 = index;
	struct failure** _7 = _5 + _6;
	return *_7;
}
/* set-at<?t> void(a mut-list<failure>, index nat, value failure) */
struct void_ set_at_3(struct ctx* ctx, struct mut_list_4* a, uint64_t index, struct failure* value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_list_4* _2 = a;
	uint64_t _3 = _2->size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_list_4* _5 = a;
	uint64_t _6 = index;
	struct failure* _7 = value;
	return noctx_set_at_4(_5, _6, _7);
}
/* noctx-set-at<?t> void(a mut-list<failure>, index nat, value failure) */
struct void_ noctx_set_at_4(struct mut_list_4* a, uint64_t index, struct failure* value) {
	uint64_t _0 = index;
	struct mut_list_4* _1 = a;
	uint64_t _2 = _1->size;
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_list_4* _4 = a;
	struct failure** _5 = data_9(_4);
	uint64_t _6 = index;
	struct failure** _7 = _5 + _6;
	struct failure* _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* flat-map-with-max-size<failure, arr<char>>.lambda0 void(x arr<char>) */
struct void_ flat_map_with_max_size__lambda0(struct ctx* ctx, struct flat_map_with_max_size__lambda0* _closure, struct arr_0 x) {
	struct flat_map_with_max_size__lambda0* _0 = _closure;
	struct mut_list_4* _1 = _0->res;
	uint64_t _2 = _1->size;
	struct flat_map_with_max_size__lambda0* _3 = _closure;
	uint64_t _4 = _3->max_size;
	uint8_t _5 = _op_less_0(_2, _4);
	if (_5) {
		struct ctx* _6 = ctx;
		struct flat_map_with_max_size__lambda0* _7 = _closure;
		struct mut_list_4* _8 = _7->res;
		struct ctx* _9 = ctx;
		struct flat_map_with_max_size__lambda0* _10 = _closure;
		struct fun_act1_11 _11 = _10->mapper;
		struct arr_0 _12 = x;
		struct arr_7 _13 = call_17(_9, _11, _12);
		push_all(_6, _8, _13);
		struct ctx* _14 = ctx;
		struct flat_map_with_max_size__lambda0* _15 = _closure;
		struct mut_list_4* _16 = _15->res;
		struct flat_map_with_max_size__lambda0* _17 = _closure;
		uint64_t _18 = _17->max_size;
		return reduce_size_if_more_than(_14, _16, _18);
	} else {
		return (struct void_) {};
	}
}
/* move-to-arr<?out> arr<failure>(a mut-list<failure>) */
struct arr_7 move_to_arr_3(struct mut_list_4* a) {
	struct arr_7 res0;
	struct mut_list_4* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_4* _2 = a;
	struct failure** _3 = data_9(_2);
	res0 = (struct arr_7) {_1, _3};
	
	struct mut_list_4* _4 = a;
	struct mut_arr_5 _5 = empty_mut_arr_3();
	_4->backing = _5;
	struct mut_list_4* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* run-single-noze-test arr<failure>(path-to-noze arr<char>, env dict<arr<char>, arr<char>>, path arr<char>, options test-options) */
struct arr_7 run_single_noze_test(struct ctx* ctx, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, struct test_options options) {
	struct opt_11 op0;
	struct ctx* _0 = ctx;
	struct arr_1 _1 = (struct arr_1) {4, constantarr_1_1};
	struct run_single_noze_test__lambda0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct run_single_noze_test__lambda0);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct run_single_noze_test__lambda0*) _4;
	
	struct run_single_noze_test__lambda0* _5 = temp0;
	struct test_options _6 = options;
	struct arr_0 _7 = path;
	struct arr_0 _8 = path_to_noze;
	struct dict_1* _9 = env;
	struct run_single_noze_test__lambda0 _10 = (struct run_single_noze_test__lambda0) {_6, _7, _8, _9};
	*_5 = _10;
	struct run_single_noze_test__lambda0* _11 = temp0;
	struct fun_act1_13 _12 = (struct fun_act1_13) {0, .as0 = _11};
	op0 = first_some(_0, _1, _12);
	
	struct opt_11 _13 = op0;
	switch (_13.kind) {
		case 0: {
			struct test_options _14 = options;
			uint8_t _15 = _14.print_tests__q;
			if (_15) {
				struct ctx* _16 = ctx;
				struct arr_0 _17 = (struct arr_0) {9, constantarr_0_68};
				struct arr_0 _18 = path;
				struct arr_0 _19 = _op_plus_0(_16, _17, _18);
				print(_19);
			} else {
				(struct void_) {};
			}
			struct arr_7 interpret_failures1;
			struct ctx* _20 = ctx;
			struct arr_0 _21 = path_to_noze;
			struct dict_1* _22 = env;
			struct arr_0 _23 = path;
			uint8_t _24 = 1;
			struct test_options _25 = options;
			uint8_t _26 = _25.overwrite_output__q;
			interpret_failures1 = run_single_runnable_test(_20, _21, _22, _23, _24, _26);
			
			struct arr_7 _27 = interpret_failures1;
			uint8_t _28 = empty__q_10(_27);
			if (_28) {
				struct ctx* _29 = ctx;
				struct arr_0 _30 = path_to_noze;
				struct dict_1* _31 = env;
				struct arr_0 _32 = path;
				uint8_t _33 = 0;
				struct test_options _34 = options;
				uint8_t _35 = _34.overwrite_output__q;
				return run_single_runnable_test(_29, _30, _31, _32, _33, _35);
			} else {
				return interpret_failures1;
			}
		}
		case 1: {
			struct some_11 s2 = _13.as1;
			
			struct some_11 _36 = s2;
			return _36.value;
		}
		default:
			return (assert(0),(struct arr_7) {0, NULL});
	}
}
/* first-some<arr<failure>, arr<char>> opt<arr<failure>>(a arr<arr<char>>, cb fun-act1<opt<arr<failure>>, arr<char>>) */
struct opt_11 first_some(struct ctx* ctx, struct arr_1 a, struct fun_act1_13 cb) {
	top:;
	struct arr_1 _0 = a;
	uint8_t _1 = empty__q_5(_0);
	if (_1) {
		struct none _2 = (struct none) {};
		return (struct opt_11) {0, .as0 = _2};
	} else {
		struct ctx* _3 = ctx;
		struct fun_act1_13 _4 = cb;
		struct ctx* _5 = ctx;
		struct arr_1 _6 = a;
		struct arr_0 _7 = first_1(_5, _6);
		struct opt_11 _8 = call_18(_3, _4, _7);
		switch (_8.kind) {
			case 0: {
				struct ctx* _9 = ctx;
				struct arr_1 _10 = a;
				struct arr_1 _11 = tail_2(_9, _10);
				struct fun_act1_13 _12 = cb;
				a = _11;
				cb = _12;
				goto top;
			}
			case 1: {
				struct some_11 s0 = _8.as1;
				
				struct some_11 _13 = s0;
				return (struct opt_11) {1, .as1 = _13};
			}
			default:
				return (assert(0),(struct opt_11) {0});
		}
	}
}
/* call<opt<?out>, ?in> opt<arr<failure>>(a fun-act1<opt<arr<failure>>, arr<char>>, p0 arr<char>) */
struct opt_11 call_18(struct ctx* ctx, struct fun_act1_13 a, struct arr_0 p0) {
	struct fun_act1_13 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_599(_0, _1, _2);
}
/* call-w-ctx<opt<arr<failure>>, arr<char>> (generated) (generated) */
struct opt_11 call_w_ctx_599(struct fun_act1_13 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_13 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct run_single_noze_test__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct run_single_noze_test__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			return run_single_noze_test__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),(struct opt_11) {0});
	}
}
/* run-print-test print-test-result(print-kind arr<char>, path-to-noze arr<char>, env dict<arr<char>, arr<char>>, path arr<char>, overwrite-output? bool) */
struct print_test_result* run_print_test(struct ctx* ctx, struct arr_0 print_kind, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, uint8_t overwrite_output__q) {
	struct process_result* res0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path_to_noze;
	struct arr_0* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct arr_0);
	uint64_t _4 = 3u;
	uint64_t _5 = _3 * _4;
	uint8_t* _6 = alloc(_2, _5);
	temp0 = (struct arr_0*) _6;
	
	struct arr_0* _7 = temp0;
	uint64_t _8 = 0u;
	struct arr_0* _9 = _7 + _8;
	struct arr_0 _10 = (struct arr_0) {5, constantarr_0_57};
	*_9 = _10;
	struct arr_0* _11 = temp0;
	uint64_t _12 = 1u;
	struct arr_0* _13 = _11 + _12;
	struct arr_0 _14 = print_kind;
	*_13 = _14;
	struct arr_0* _15 = temp0;
	uint64_t _16 = 2u;
	struct arr_0* _17 = _15 + _16;
	struct arr_0 _18 = path;
	*_17 = _18;
	uint64_t _19 = 3u;
	struct arr_0* _20 = temp0;
	struct arr_1 _21 = (struct arr_1) {_19, _20};
	struct dict_1* _22 = env;
	res0 = spawn_and_wait_result_0(_0, _1, _21, _22);
	
	struct arr_0 output_path1;
	struct ctx* _23 = ctx;
	struct ctx* _24 = ctx;
	struct ctx* _25 = ctx;
	struct arr_0 _26 = path;
	struct arr_0 _27 = (struct arr_0) {1, constantarr_0_32};
	struct arr_0 _28 = _op_plus_0(_25, _26, _27);
	struct arr_0 _29 = print_kind;
	struct arr_0 _30 = _op_plus_0(_24, _28, _29);
	struct arr_0 _31 = (struct arr_0) {5, constantarr_0_58};
	output_path1 = _op_plus_0(_23, _30, _31);
	
	struct arr_7 output_failures2;
	struct process_result* _32 = res0;
	struct arr_0 _33 = _32->stdout;
	uint8_t _34 = empty__q_0(_33);uint8_t _35;
	
	if (_34) {
		struct process_result* _36 = res0;
		int32_t _37 = _36->exit_code;
		int32_t _38 = 0;
		_35 = _op_bang_equal_2(_37, _38);
	} else {
		_35 = 0;
	}
	if (_35) {
		output_failures2 = empty_arr_4();
	} else {
		struct ctx* _39 = ctx;
		struct arr_0 _40 = path;
		struct arr_0 _41 = output_path1;
		struct process_result* _42 = res0;
		struct arr_0 _43 = _42->stdout;
		uint8_t _44 = overwrite_output__q;
		output_failures2 = handle_output(_39, _40, _41, _43, _44);
	}
	
	struct arr_7 _45 = output_failures2;
	uint8_t _46 = empty__q_10(_45);
	uint8_t _47 = !_46;
	if (_47) {
		struct print_test_result* temp1;
		struct ctx* _48 = ctx;
		uint64_t _49 = sizeof(struct print_test_result);
		uint8_t* _50 = alloc(_48, _49);
		temp1 = (struct print_test_result*) _50;
		
		struct print_test_result* _51 = temp1;
		uint8_t _52 = 1;
		struct arr_7 _53 = output_failures2;
		struct print_test_result _54 = (struct print_test_result) {_52, _53};
		*_51 = _54;
		return temp1;
	} else {
		struct process_result* _55 = res0;
		int32_t _56 = _55->exit_code;
		int32_t _57 = 0;
		uint8_t _58 = _op_equal_equal_2(_56, _57);
		if (_58) {
			struct ctx* _59 = ctx;
			struct process_result* _60 = res0;
			struct arr_0 _61 = _60->stderr;
			struct arr_0 _62 = (struct arr_0) {0u, NULL};
			uint8_t _63 = _op_equal_equal_4(_61, _62);
			assert_0(_59, _63);
			struct print_test_result* temp2;
			struct ctx* _64 = ctx;
			uint64_t _65 = sizeof(struct print_test_result);
			uint8_t* _66 = alloc(_64, _65);
			temp2 = (struct print_test_result*) _66;
			
			struct print_test_result* _67 = temp2;
			uint8_t _68 = 0;
			struct arr_7 _69 = empty_arr_4();
			struct print_test_result _70 = (struct print_test_result) {_68, _69};
			*_67 = _70;
			return temp2;
		} else {
			struct process_result* _71 = res0;
			int32_t _72 = _71->exit_code;
			int32_t _73 = 1;
			uint8_t _74 = _op_equal_equal_2(_72, _73);
			if (_74) {
				struct arr_0 stderr_no_color3;
				struct ctx* _75 = ctx;
				struct process_result* _76 = res0;
				struct arr_0 _77 = _76->stderr;
				stderr_no_color3 = remove_colors(_75, _77);
				
				struct print_test_result* temp3;
				struct ctx* _78 = ctx;
				uint64_t _79 = sizeof(struct print_test_result);
				uint8_t* _80 = alloc(_78, _79);
				temp3 = (struct print_test_result*) _80;
				
				struct print_test_result* _81 = temp3;
				uint8_t _82 = 1;
				struct ctx* _83 = ctx;
				struct arr_0 _84 = path;
				struct ctx* _85 = ctx;
				struct arr_0 _86 = output_path1;
				struct arr_0 _87 = (struct arr_0) {4, constantarr_0_66};
				struct arr_0 _88 = _op_plus_0(_85, _86, _87);
				struct arr_0 _89 = stderr_no_color3;
				uint8_t _90 = overwrite_output__q;
				struct arr_7 _91 = handle_output(_83, _84, _88, _89, _90);
				struct print_test_result _92 = (struct print_test_result) {_82, _91};
				*_81 = _92;
				return temp3;
			} else {
				struct arr_0 message4;
				struct ctx* _93 = ctx;
				struct arr_0 _94 = (struct arr_0) {22, constantarr_0_67};
				struct ctx* _95 = ctx;
				struct process_result* _96 = res0;
				int32_t _97 = _96->exit_code;
				struct arr_0 _98 = to_str_2(_95, _97);
				message4 = _op_plus_0(_93, _94, _98);
				
				struct print_test_result* temp6;
				struct ctx* _99 = ctx;
				uint64_t _100 = sizeof(struct print_test_result);
				uint8_t* _101 = alloc(_99, _100);
				temp6 = (struct print_test_result*) _101;
				
				struct print_test_result* _102 = temp6;
				uint8_t _103 = 1;
				struct failure** temp4;
				struct ctx* _104 = ctx;
				uint64_t _105 = sizeof(struct failure*);
				uint64_t _106 = 1u;
				uint64_t _107 = _105 * _106;
				uint8_t* _108 = alloc(_104, _107);
				temp4 = (struct failure**) _108;
				
				struct failure** _109 = temp4;
				uint64_t _110 = 0u;
				struct failure** _111 = _109 + _110;
				struct failure* temp5;
				struct ctx* _112 = ctx;
				uint64_t _113 = sizeof(struct failure);
				uint8_t* _114 = alloc(_112, _113);
				temp5 = (struct failure*) _114;
				
				struct failure* _115 = temp5;
				struct arr_0 _116 = path;
				struct arr_0 _117 = message4;
				struct failure _118 = (struct failure) {_116, _117};
				*_115 = _118;
				struct failure* _119 = temp5;
				*_111 = _119;
				uint64_t _120 = 1u;
				struct failure** _121 = temp4;
				struct arr_7 _122 = (struct arr_7) {_120, _121};
				struct print_test_result _123 = (struct print_test_result) {_103, _122};
				*_102 = _123;
				return temp6;
			}
		}
	}
}
/* spawn-and-wait-result process-result(exe arr<char>, args arr<arr<char>>, environ dict<arr<char>, arr<char>>) */
struct process_result* spawn_and_wait_result_0(struct ctx* ctx, struct arr_0 exe, struct arr_1 args, struct dict_1* environ) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = (struct arr_0) {23, constantarr_0_41};
	struct arr_0 _3 = exe;
	struct arr_0 _4 = _op_plus_0(_1, _2, _3);
	struct arr_1 _5 = args;
	struct void_ _6 = (struct void_) {};
	struct fun_act2_1 _7 = (struct fun_act2_1) {0, .as0 = _6};
	struct arr_0 _8 = fold(_0, _4, _5, _7);
	print(_8);
	struct ctx* _9 = ctx;
	struct arr_0 _10 = exe;
	uint8_t _11 = is_file__q_0(_9, _10);
	if (_11) {
		char* exe_c_str0;
		struct ctx* _12 = ctx;
		struct arr_0 _13 = exe;
		exe_c_str0 = to_c_str(_12, _13);
		
		struct ctx* _14 = ctx;
		char* _15 = exe_c_str0;
		struct ctx* _16 = ctx;
		char* _17 = exe_c_str0;
		struct arr_1 _18 = args;
		char** _19 = convert_args(_16, _17, _18);
		struct ctx* _20 = ctx;
		struct dict_1* _21 = environ;
		char** _22 = convert_environ(_20, _21);
		return spawn_and_wait_result_1(_14, _15, _19, _22);
	} else {
		struct ctx* _23 = ctx;
		struct ctx* _24 = ctx;
		struct arr_0 _25 = exe;
		struct arr_0 _26 = (struct arr_0) {14, constantarr_0_56};
		struct arr_0 _27 = _op_plus_0(_24, _25, _26);
		return fail_3(_23, _27);
	}
}
/* fold<arr<char>, arr<char>> arr<char>(val arr<char>, a arr<arr<char>>, combine fun-act2<arr<char>, arr<char>, arr<char>>) */
struct arr_0 fold(struct ctx* ctx, struct arr_0 val, struct arr_1 a, struct fun_act2_1 combine) {
	top:;
	struct arr_1 _0 = a;
	uint8_t _1 = empty__q_5(_0);
	if (_1) {
		return val;
	} else {
		struct ctx* _2 = ctx;
		struct fun_act2_1 _3 = combine;
		struct arr_0 _4 = val;
		struct ctx* _5 = ctx;
		struct arr_1 _6 = a;
		struct arr_0 _7 = first_1(_5, _6);
		struct arr_0 _8 = call_19(_2, _3, _4, _7);
		struct ctx* _9 = ctx;
		struct arr_1 _10 = a;
		struct arr_1 _11 = tail_2(_9, _10);
		struct fun_act2_1 _12 = combine;
		val = _8;
		a = _11;
		combine = _12;
		goto top;
	}
}
/* call<?a, ?a, ?b> arr<char>(a fun-act2<arr<char>, arr<char>, arr<char>>, p0 arr<char>, p1 arr<char>) */
struct arr_0 call_19(struct ctx* ctx, struct fun_act2_1 a, struct arr_0 p0, struct arr_0 p1) {
	struct fun_act2_1 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	struct arr_0 _3 = p1;
	return call_w_ctx_604(_0, _1, _2, _3);
}
/* call-w-ctx<arr<char>, arr<char>, arr<char>> (generated) (generated) */
struct arr_0 call_w_ctx_604(struct fun_act2_1 a, struct ctx* ctx, struct arr_0 p0, struct arr_0 p1) {
	struct fun_act2_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			struct arr_0 _3 = p0;
			struct arr_0 _4 = p1;
			return spawn_and_wait_result_0__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* spawn-and-wait-result.lambda0 arr<char>(a arr<char>, b arr<char>) */
struct arr_0 spawn_and_wait_result_0__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 a, struct arr_0 b) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = a;
	struct arr_0 _3 = (struct arr_0) {1, constantarr_0_40};
	struct arr_0 _4 = _op_plus_0(_1, _2, _3);
	struct arr_0 _5 = b;
	return _op_plus_0(_0, _4, _5);
}
/* is-file? bool(path arr<char>) */
uint8_t is_file__q_0(struct ctx* ctx, struct arr_0 path) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	char* _3 = to_c_str(_1, _2);
	return is_file__q_1(_0, _3);
}
/* is-file? bool(path ptr<char>) */
uint8_t is_file__q_1(struct ctx* ctx, char* path) {
	struct ctx* _0 = ctx;
	char* _1 = path;
	struct opt_9 _2 = get_stat(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			struct some_9 s0 = _2.as1;
			
			struct some_9 _3 = s0;
			struct stat_t* _4 = _3.value;
			uint32_t _5 = _4->st_mode;
			struct ctx* _6 = ctx;
			uint32_t _7 = s_ifmt(_6);
			uint32_t _8 = _5 & _7;
			struct ctx* _9 = ctx;
			uint32_t _10 = s_ifreg(_9);
			return _op_equal_equal_5(_8, _10);
		}
		default:
			return (assert(0),0);
	}
}
/* s-ifreg nat32() */
uint32_t s_ifreg(struct ctx* ctx) {
	return 32768u;
}
/* spawn-and-wait-result process-result(exe ptr<char>, args ptr<ptr<char>>, environ ptr<ptr<char>>) */
struct process_result* spawn_and_wait_result_1(struct ctx* ctx, char* exe, char** args, char** environ) {
	struct pipes* stdout_pipes0;
	struct ctx* _0 = ctx;
	stdout_pipes0 = make_pipes(_0);
	
	struct pipes* stderr_pipes1;
	struct ctx* _1 = ctx;
	stderr_pipes1 = make_pipes(_1);
	
	struct posix_spawn_file_actions_t* actions2;
	struct posix_spawn_file_actions_t* temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(struct posix_spawn_file_actions_t);
	uint8_t* _4 = alloc(_2, _3);
	temp0 = (struct posix_spawn_file_actions_t*) _4;
	
	struct posix_spawn_file_actions_t* _5 = temp0;
	int32_t _6 = 0;
	int32_t _7 = 0;
	uint8_t* _8 = NULL;
	struct bytes64 _9 = zero_0();
	struct posix_spawn_file_actions_t _10 = (struct posix_spawn_file_actions_t) {_6, _7, _8, _9};
	*_5 = _10;
	actions2 = temp0;
	
	struct ctx* _11 = ctx;
	struct posix_spawn_file_actions_t* _12 = actions2;
	int32_t _13 = posix_spawn_file_actions_init(_12);
	check_posix_error(_11, _13);
	struct ctx* _14 = ctx;
	struct posix_spawn_file_actions_t* _15 = actions2;
	struct pipes* _16 = stdout_pipes0;
	int32_t _17 = _16->write_pipe;
	int32_t _18 = posix_spawn_file_actions_addclose(_15, _17);
	check_posix_error(_14, _18);
	struct ctx* _19 = ctx;
	struct posix_spawn_file_actions_t* _20 = actions2;
	struct pipes* _21 = stderr_pipes1;
	int32_t _22 = _21->write_pipe;
	int32_t _23 = posix_spawn_file_actions_addclose(_20, _22);
	check_posix_error(_19, _23);
	struct ctx* _24 = ctx;
	struct posix_spawn_file_actions_t* _25 = actions2;
	struct pipes* _26 = stdout_pipes0;
	int32_t _27 = _26->read_pipe;
	int32_t _28 = stdout();
	int32_t _29 = posix_spawn_file_actions_adddup2(_25, _27, _28);
	check_posix_error(_24, _29);
	struct ctx* _30 = ctx;
	struct posix_spawn_file_actions_t* _31 = actions2;
	struct pipes* _32 = stderr_pipes1;
	int32_t _33 = _32->read_pipe;
	int32_t _34 = stderr();
	int32_t _35 = posix_spawn_file_actions_adddup2(_31, _33, _34);
	check_posix_error(_30, _35);
	struct ctx* _36 = ctx;
	struct posix_spawn_file_actions_t* _37 = actions2;
	struct pipes* _38 = stdout_pipes0;
	int32_t _39 = _38->read_pipe;
	int32_t _40 = posix_spawn_file_actions_addclose(_37, _39);
	check_posix_error(_36, _40);
	struct ctx* _41 = ctx;
	struct posix_spawn_file_actions_t* _42 = actions2;
	struct pipes* _43 = stderr_pipes1;
	int32_t _44 = _43->read_pipe;
	int32_t _45 = posix_spawn_file_actions_addclose(_42, _44);
	check_posix_error(_41, _45);
	struct cell_5* pid_cell3;
	struct cell_5* temp1;
	struct ctx* _46 = ctx;
	uint64_t _47 = sizeof(struct cell_5);
	uint8_t* _48 = alloc(_46, _47);
	temp1 = (struct cell_5*) _48;
	
	struct cell_5* _49 = temp1;
	int32_t _50 = 0;
	struct cell_5 _51 = (struct cell_5) {_50};
	*_49 = _51;
	pid_cell3 = temp1;
	
	struct ctx* _52 = ctx;
	struct cell_5* _53 = pid_cell3;
	char* _54 = exe;
	struct posix_spawn_file_actions_t* _55 = actions2;
	uint8_t* _56 = NULL;
	char** _57 = args;
	char** _58 = environ;
	int32_t _59 = posix_spawn(_53, _54, _55, _56, _57, _58);
	check_posix_error(_52, _59);
	int32_t pid4;
	struct cell_5* _60 = pid_cell3;
	pid4 = get_6(_60);
	
	struct ctx* _61 = ctx;
	struct pipes* _62 = stdout_pipes0;
	int32_t _63 = _62->read_pipe;
	int32_t _64 = close(_63);
	check_posix_error(_61, _64);
	struct ctx* _65 = ctx;
	struct pipes* _66 = stderr_pipes1;
	int32_t _67 = _66->read_pipe;
	int32_t _68 = close(_67);
	check_posix_error(_65, _68);
	struct mut_list_5* stdout_builder5;
	struct ctx* _69 = ctx;
	stdout_builder5 = new_mut_list_3(_69);
	
	struct mut_list_5* stderr_builder6;
	struct ctx* _70 = ctx;
	stderr_builder6 = new_mut_list_3(_70);
	
	struct ctx* _71 = ctx;
	struct pipes* _72 = stdout_pipes0;
	int32_t _73 = _72->write_pipe;
	struct pipes* _74 = stderr_pipes1;
	int32_t _75 = _74->write_pipe;
	struct mut_list_5* _76 = stdout_builder5;
	struct mut_list_5* _77 = stderr_builder6;
	keep_polling(_71, _73, _75, _76, _77);
	int32_t exit_code7;
	struct ctx* _78 = ctx;
	int32_t _79 = pid4;
	exit_code7 = wait_and_get_exit_code(_78, _79);
	
	struct process_result* temp2;
	struct ctx* _80 = ctx;
	uint64_t _81 = sizeof(struct process_result);
	uint8_t* _82 = alloc(_80, _81);
	temp2 = (struct process_result*) _82;
	
	struct process_result* _83 = temp2;
	int32_t _84 = exit_code7;
	struct mut_list_5* _85 = stdout_builder5;
	struct arr_0 _86 = move_to_arr_4(_85);
	struct mut_list_5* _87 = stderr_builder6;
	struct arr_0 _88 = move_to_arr_4(_87);
	struct process_result _89 = (struct process_result) {_84, _86, _88};
	*_83 = _89;
	return temp2;
}
/* make-pipes pipes() */
struct pipes* make_pipes(struct ctx* ctx) {
	struct pipes* res0;
	struct pipes* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct pipes);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct pipes*) _2;
	
	struct pipes* _3 = temp0;
	int32_t _4 = 0;
	int32_t _5 = 0;
	struct pipes _6 = (struct pipes) {_4, _5};
	*_3 = _6;
	res0 = temp0;
	
	struct ctx* _7 = ctx;
	struct pipes* _8 = res0;
	int32_t _9 = pipe(_8);
	check_posix_error(_7, _9);
	return res0;
}
/* get<int32> int32(c cell<int32>) */
int32_t get_6(struct cell_5* c) {
	struct cell_5* _0 = c;
	return _0->value;
}
/* new-mut-list<char> mut-list<char>() */
struct mut_list_5* new_mut_list_3(struct ctx* ctx) {
	struct mut_list_5* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct mut_list_5);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct mut_list_5*) _2;
	
	struct mut_list_5* _3 = temp0;
	struct mut_arr_4 _4 = empty_mut_arr_4();
	uint64_t _5 = 0u;
	struct mut_list_5 _6 = (struct mut_list_5) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-mut-arr<?t> mut-arr<char>() */
struct mut_arr_4 empty_mut_arr_4(void) {
	struct arr_0 _0 = empty_arr_5();
	return (struct mut_arr_4) {_0};
}
/* empty-arr<?t> arr<char>() */
struct arr_0 empty_arr_5(void) {
	uint64_t _0 = 0u;
	char* _1 = NULL;
	return (struct arr_0) {_0, _1};
}
/* keep-polling void(stdout-pipe int32, stderr-pipe int32, stdout-builder mut-list<char>, stderr-builder mut-list<char>) */
struct void_ keep_polling(struct ctx* ctx, int32_t stdout_pipe, int32_t stderr_pipe, struct mut_list_5* stdout_builder, struct mut_list_5* stderr_builder) {
	top:;
	struct arr_8 poll_fds0;
	struct pollfd* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct pollfd);
	uint64_t _2 = 2u;
	uint64_t _3 = _1 * _2;
	uint8_t* _4 = alloc(_0, _3);
	temp0 = (struct pollfd*) _4;
	
	struct pollfd* _5 = temp0;
	uint64_t _6 = 0u;
	struct pollfd* _7 = _5 + _6;
	int32_t _8 = stdout_pipe;
	struct ctx* _9 = ctx;
	int16_t _10 = pollin(_9);
	int16_t _11 = 0;
	struct pollfd _12 = (struct pollfd) {_8, _10, _11};
	*_7 = _12;
	struct pollfd* _13 = temp0;
	uint64_t _14 = 1u;
	struct pollfd* _15 = _13 + _14;
	int32_t _16 = stderr_pipe;
	struct ctx* _17 = ctx;
	int16_t _18 = pollin(_17);
	int16_t _19 = 0;
	struct pollfd _20 = (struct pollfd) {_16, _18, _19};
	*_15 = _20;
	uint64_t _21 = 2u;
	struct pollfd* _22 = temp0;
	poll_fds0 = (struct arr_8) {_21, _22};
	
	struct pollfd* stdout_pollfd1;
	struct ctx* _23 = ctx;
	struct arr_8 _24 = poll_fds0;
	uint64_t _25 = 0u;
	stdout_pollfd1 = ref_of_val_at(_23, _24, _25);
	
	struct pollfd* stderr_pollfd2;
	struct ctx* _26 = ctx;
	struct arr_8 _27 = poll_fds0;
	uint64_t _28 = 1u;
	stderr_pollfd2 = ref_of_val_at(_26, _27, _28);
	
	int32_t n_pollfds_with_events3;
	struct arr_8 _29 = poll_fds0;
	struct pollfd* _30 = _29.data;
	struct arr_8 _31 = poll_fds0;
	uint64_t _32 = _31.size;
	int32_t _33 = -1;
	n_pollfds_with_events3 = poll(_30, _32, _33);
	
	int32_t _34 = n_pollfds_with_events3;
	int32_t _35 = 0;
	uint8_t _36 = _op_equal_equal_2(_34, _35);
	if (_36) {
		return (struct void_) {};
	} else {
		struct handle_revents_result a4;
		struct ctx* _37 = ctx;
		struct pollfd* _38 = stdout_pollfd1;
		struct mut_list_5* _39 = stdout_builder;
		a4 = handle_revents(_37, _38, _39);
		
		struct handle_revents_result b5;
		struct ctx* _40 = ctx;
		struct pollfd* _41 = stderr_pollfd2;
		struct mut_list_5* _42 = stderr_builder;
		b5 = handle_revents(_40, _41, _42);
		
		struct ctx* _43 = ctx;
		struct ctx* _44 = ctx;
		struct ctx* _45 = ctx;
		struct handle_revents_result _46 = a4;
		uint8_t _47 = any__q(_45, _46);
		uint64_t _48 = to_nat_1(_47);
		struct ctx* _49 = ctx;
		struct handle_revents_result _50 = b5;
		uint8_t _51 = any__q(_49, _50);
		uint64_t _52 = to_nat_1(_51);
		uint64_t _53 = _op_plus_1(_44, _48, _52);
		struct ctx* _54 = ctx;
		int32_t _55 = n_pollfds_with_events3;
		uint64_t _56 = to_nat_2(_54, _55);
		uint8_t _57 = _op_equal_equal_0(_53, _56);
		assert_0(_43, _57);
		struct handle_revents_result _58 = a4;
		uint8_t _59 = _58.hung_up__q;uint8_t _60;
		
		if (_59) {
			struct handle_revents_result _61 = b5;
			_60 = _61.hung_up__q;
		} else {
			_60 = 0;
		}
		uint8_t _62 = !_60;
		if (_62) {
			int32_t _63 = stdout_pipe;
			int32_t _64 = stderr_pipe;
			struct mut_list_5* _65 = stdout_builder;
			struct mut_list_5* _66 = stderr_builder;
			stdout_pipe = _63;
			stderr_pipe = _64;
			stdout_builder = _65;
			stderr_builder = _66;
			goto top;
		} else {
			return (struct void_) {};
		}
	}
}
/* pollin int16() */
int16_t pollin(struct ctx* ctx) {
	return 1;
}
/* ref-of-val-at<pollfd> pollfd(a arr<pollfd>, index nat) */
struct pollfd* ref_of_val_at(struct ctx* ctx, struct arr_8 a, uint64_t index) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct arr_8 _2 = a;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct arr_8 _5 = a;
	struct pollfd* _6 = _5.data;
	uint64_t _7 = index;
	struct pollfd* _8 = _6 + _7;
	return ref_of_ptr(_8);
}
/* ref-of-ptr<?t> pollfd(p ptr<pollfd>) */
struct pollfd* ref_of_ptr(struct pollfd* p) {
	return &(*p);
}
/* handle-revents handle-revents-result(pollfd pollfd, builder mut-list<char>) */
struct handle_revents_result handle_revents(struct ctx* ctx, struct pollfd* pollfd, struct mut_list_5* builder) {
	int16_t revents0;
	struct pollfd* _0 = pollfd;
	revents0 = _0->revents;
	
	uint8_t had_pollin__q1;
	struct ctx* _1 = ctx;
	int16_t _2 = revents0;
	had_pollin__q1 = has_pollin__q(_1, _2);
	
	uint8_t _3 = had_pollin__q1;
	if (_3) {
		struct ctx* _4 = ctx;
		struct pollfd* _5 = pollfd;
		int32_t _6 = _5->fd;
		struct mut_list_5* _7 = builder;
		read_to_buffer_until_eof(_4, _6, _7);
	} else {
		(struct void_) {};
	}
	uint8_t hung_up__q2;
	struct ctx* _8 = ctx;
	int16_t _9 = revents0;
	hung_up__q2 = has_pollhup__q(_8, _9);
	
	struct ctx* _10 = ctx;
	int16_t _11 = revents0;
	uint8_t _12 = has_pollpri__q(_10, _11);uint8_t _13;
	
	if (_12) {
		_13 = 1;
	} else {
		struct ctx* _14 = ctx;
		int16_t _15 = revents0;
		_13 = has_pollout__q(_14, _15);
	}uint8_t _16;
	
	if (_13) {
		_16 = 1;
	} else {
		struct ctx* _17 = ctx;
		int16_t _18 = revents0;
		_16 = has_pollerr__q(_17, _18);
	}uint8_t _19;
	
	if (_16) {
		_19 = 1;
	} else {
		struct ctx* _20 = ctx;
		int16_t _21 = revents0;
		_19 = has_pollnval__q(_20, _21);
	}
	if (_19) {
		todo_0();
	} else {
		(struct void_) {};
	}
	uint8_t _22 = had_pollin__q1;
	uint8_t _23 = hung_up__q2;
	return (struct handle_revents_result) {_22, _23};
}
/* has-pollin? bool(revents int16) */
uint8_t has_pollin__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollin(_1);
	return bits_intersect__q(_0, _2);
}
/* bits-intersect? bool(a int16, b int16) */
uint8_t bits_intersect__q(int16_t a, int16_t b) {
	int16_t _0 = a;
	int16_t _1 = b;
	int16_t _2 = _0 & _1;
	int16_t _3 = 0;
	uint8_t _4 = _op_equal_equal_6(_2, _3);
	return !_4;
}
/* ==<int16> bool(a int16, b int16) */
uint8_t _op_equal_equal_6(int16_t a, int16_t b) {
	int16_t _0 = a;
	int16_t _1 = b;
	struct comparison _2 = compare_630(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 0;
		}
		case 1: {
			return 1;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* compare<int-16> (generated) (generated) */
struct comparison compare_630(int16_t a, int16_t b) {
	int16_t _0 = a;
	int16_t _1 = b;
	uint8_t _2 = _0 < _1;
	if (_2) {
		struct less _3 = (struct less) {};
		return (struct comparison) {0, .as0 = _3};
	} else {
		int16_t _4 = b;
		int16_t _5 = a;
		uint8_t _6 = _4 < _5;
		if (_6) {
			struct greater _7 = (struct greater) {};
			return (struct comparison) {2, .as2 = _7};
		} else {
			struct equal _8 = (struct equal) {};
			return (struct comparison) {1, .as1 = _8};
		}
	}
}
/* read-to-buffer-until-eof void(fd int32, buffer mut-list<char>) */
struct void_ read_to_buffer_until_eof(struct ctx* ctx, int32_t fd, struct mut_list_5* buffer) {
	top:;
	struct ctx* _0 = ctx;
	struct mut_list_5* _1 = buffer;
	struct ctx* _2 = ctx;
	struct mut_list_5* _3 = buffer;
	uint64_t _4 = _3->size;
	uint64_t _5 = 1024u;
	uint64_t _6 = _op_plus_1(_2, _4, _5);
	ensure_capacity_3(_0, _1, _6);
	char* add_data_to0;
	struct mut_list_5* _7 = buffer;
	char* _8 = data_11(_7);
	struct mut_list_5* _9 = buffer;
	uint64_t _10 = _9->size;
	add_data_to0 = _8 + _10;
	
	int64_t n_bytes_read1;
	int32_t _11 = fd;
	char* _12 = add_data_to0;
	uint8_t* _13 = (uint8_t*) _12;
	uint64_t _14 = 1024u;
	n_bytes_read1 = read(_11, _13, _14);
	
	int64_t _15 = n_bytes_read1;
	int64_t _16 = -1;
	uint8_t _17 = _op_equal_equal_1(_15, _16);
	if (_17) {
		return todo_0();
	} else {
		int64_t _18 = n_bytes_read1;
		int64_t _19 = 0;
		uint8_t _20 = _op_equal_equal_1(_18, _19);
		if (_20) {
			return (struct void_) {};
		} else {
			struct ctx* _21 = ctx;
			struct ctx* _22 = ctx;
			int64_t _23 = n_bytes_read1;
			uint64_t _24 = to_nat_0(_22, _23);
			uint64_t _25 = 1024u;
			uint8_t _26 = _op_less_equal(_24, _25);
			assert_0(_21, _26);
			struct ctx* _27 = ctx;
			struct mut_list_5* _28 = buffer;
			struct ctx* _29 = ctx;
			int64_t _30 = n_bytes_read1;
			uint64_t _31 = to_nat_0(_29, _30);
			unsafe_increase_size(_27, _28, _31);
			int32_t _32 = fd;
			struct mut_list_5* _33 = buffer;
			fd = _32;
			buffer = _33;
			goto top;
		}
	}
}
/* ensure-capacity<char> void(a mut-list<char>, capacity nat) */
struct void_ ensure_capacity_3(struct ctx* ctx, struct mut_list_5* a, uint64_t capacity) {
	struct mut_list_5* _0 = a;
	uint64_t _1 = capacity_4(_0);
	uint64_t _2 = capacity;
	uint8_t _3 = _op_less_0(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_5* _5 = a;
		struct ctx* _6 = ctx;
		uint64_t _7 = capacity;
		uint64_t _8 = round_up_to_power_of_two(_6, _7);
		return increase_capacity_to_3(_4, _5, _8);
	} else {
		return (struct void_) {};
	}
}
/* capacity<?t> nat(a mut-list<char>) */
uint64_t capacity_4(struct mut_list_5* a) {
	struct mut_list_5* _0 = a;
	struct mut_arr_4 _1 = _0->backing;
	return size_5(_1);
}
/* increase-capacity-to<?t> void(a mut-list<char>, new-capacity nat) */
struct void_ increase_capacity_to_3(struct ctx* ctx, struct mut_list_5* a, uint64_t new_capacity) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_capacity;
	struct mut_list_5* _2 = a;
	uint64_t _3 = capacity_4(_2);
	uint8_t _4 = _op_greater(_1, _3);
	assert_0(_0, _4);
	char* old_data0;
	struct mut_list_5* _5 = a;
	old_data0 = data_11(_5);
	
	struct mut_list_5* _6 = a;
	uint64_t _7 = new_capacity;
	struct ctx* _8 = ctx;
	uint64_t _9 = new_capacity;
	char* _10 = uninitialized_data_0(_8, _9);
	struct mut_arr_4 _11 = mut_arr_4(_7, _10);
	_6->backing = _11;
	struct ctx* _12 = ctx;
	struct mut_list_5* _13 = a;
	char* _14 = data_11(_13);
	char* _15 = old_data0;
	struct mut_list_5* _16 = a;
	uint64_t _17 = _16->size;
	copy_data_from_0(_12, _14, _15, _17);
	struct ctx* _18 = ctx;
	struct mut_list_5* _19 = a;
	struct mut_arr_4 _20 = _19->backing;
	struct mut_list_5* _21 = a;
	uint64_t _22 = _21->size;
	struct mut_arr_4 _23 = slice_starting_at_8(_18, _20, _22);
	return set_zero_elements_3(_23);
}
/* data<?t> ptr<char>(a mut-list<char>) */
char* data_11(struct mut_list_5* a) {
	struct mut_list_5* _0 = a;
	struct mut_arr_4 _1 = _0->backing;
	return data_8(_1);
}
/* set-zero-elements<?t> void(a mut-arr<char>) */
struct void_ set_zero_elements_3(struct mut_arr_4 a) {
	struct mut_arr_4 _0 = a;
	char* _1 = data_8(_0);
	struct mut_arr_4 _2 = a;
	uint64_t _3 = size_5(_2);
	return set_zero_range_4(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<char>, size nat) */
struct void_ set_zero_range_4(char* begin, uint64_t size) {
	char* _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(char);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* slice-starting-at<?t> mut-arr<char>(a mut-arr<char>, begin nat) */
struct mut_arr_4 slice_starting_at_8(struct ctx* ctx, struct mut_arr_4 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct mut_arr_4 _2 = a;
	uint64_t _3 = size_5(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_arr_4 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct mut_arr_4 _9 = a;
	uint64_t _10 = size_5(_9);
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_8(_5, _6, _7, _12);
}
/* slice<?t> mut-arr<char>(a mut-arr<char>, begin nat, size nat) */
struct mut_arr_4 slice_8(struct ctx* ctx, struct mut_arr_4 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct mut_arr_4 _5 = a;
	uint64_t _6 = size_5(_5);
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct mut_arr_4 _9 = a;
	char* _10 = data_8(_9);
	uint64_t _11 = begin;
	char* _12 = _10 + _11;
	return mut_arr_4(_8, _12);
}
/* unsafe-increase-size<char> void(a mut-list<char>, increase-by nat) */
struct void_ unsafe_increase_size(struct ctx* ctx, struct mut_list_5* a, uint64_t increase_by) {
	struct ctx* _0 = ctx;
	struct mut_list_5* _1 = a;
	struct ctx* _2 = ctx;
	struct mut_list_5* _3 = a;
	uint64_t _4 = _3->size;
	uint64_t _5 = increase_by;
	uint64_t _6 = _op_plus_1(_2, _4, _5);
	return unsafe_set_size(_0, _1, _6);
}
/* unsafe-set-size<?t> void(a mut-list<char>, new-size nat) */
struct void_ unsafe_set_size(struct ctx* ctx, struct mut_list_5* a, uint64_t new_size) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_size;
	struct mut_list_5* _2 = a;
	uint64_t _3 = capacity_4(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct mut_list_5* _5 = a;
	uint64_t _6 = new_size;
	return (_5->size = _6, (struct void_) {});
}
/* has-pollhup? bool(revents int16) */
uint8_t has_pollhup__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollhup(_1);
	return bits_intersect__q(_0, _2);
}
/* pollhup int16() */
int16_t pollhup(struct ctx* ctx) {
	return 16;
}
/* has-pollpri? bool(revents int16) */
uint8_t has_pollpri__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollpri(_1);
	return bits_intersect__q(_0, _2);
}
/* pollpri int16() */
int16_t pollpri(struct ctx* ctx) {
	return 2;
}
/* has-pollout? bool(revents int16) */
uint8_t has_pollout__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollout(_1);
	return bits_intersect__q(_0, _2);
}
/* pollout int16() */
int16_t pollout(struct ctx* ctx) {
	return 4;
}
/* has-pollerr? bool(revents int16) */
uint8_t has_pollerr__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollerr(_1);
	return bits_intersect__q(_0, _2);
}
/* pollerr int16() */
int16_t pollerr(struct ctx* ctx) {
	return 8;
}
/* has-pollnval? bool(revents int16) */
uint8_t has_pollnval__q(struct ctx* ctx, int16_t revents) {
	int16_t _0 = revents;
	struct ctx* _1 = ctx;
	int16_t _2 = pollnval(_1);
	return bits_intersect__q(_0, _2);
}
/* pollnval int16() */
int16_t pollnval(struct ctx* ctx) {
	return 32;
}
/* to-nat nat(b bool) */
uint64_t to_nat_1(uint8_t b) {
	uint8_t _0 = b;
	if (_0) {
		return 1u;
	} else {
		return 0u;
	}
}
/* any? bool(r handle-revents-result) */
uint8_t any__q(struct ctx* ctx, struct handle_revents_result r) {
	struct handle_revents_result _0 = r;
	uint8_t _1 = _0.had_pollin__q;
	if (_1) {
		return 1;
	} else {
		struct handle_revents_result _2 = r;
		return _2.hung_up__q;
	}
}
/* to-nat nat(i int32) */
uint64_t to_nat_2(struct ctx* ctx, int32_t i) {
	struct ctx* _0 = ctx;
	int32_t _1 = i;
	int64_t _2 = (int64_t) _1;
	return to_nat_0(_0, _2);
}
/* wait-and-get-exit-code int32(pid int32) */
int32_t wait_and_get_exit_code(struct ctx* ctx, int32_t pid) {
	struct cell_5* wait_status_cell0;
	struct cell_5* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct cell_5);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct cell_5*) _2;
	
	struct cell_5* _3 = temp0;
	int32_t _4 = 0;
	struct cell_5 _5 = (struct cell_5) {_4};
	*_3 = _5;
	wait_status_cell0 = temp0;
	
	int32_t res_pid1;
	int32_t _6 = pid;
	struct cell_5* _7 = wait_status_cell0;
	int32_t _8 = 0;
	res_pid1 = waitpid(_6, _7, _8);
	
	int32_t wait_status2;
	struct cell_5* _9 = wait_status_cell0;
	wait_status2 = get_6(_9);
	
	struct ctx* _10 = ctx;
	int32_t _11 = res_pid1;
	int32_t _12 = pid;
	uint8_t _13 = _op_equal_equal_2(_11, _12);
	assert_0(_10, _13);
	struct ctx* _14 = ctx;
	int32_t _15 = wait_status2;
	uint8_t _16 = w_if_exited(_14, _15);
	if (_16) {
		struct ctx* _17 = ctx;
		int32_t _18 = wait_status2;
		return w_exit_status(_17, _18);
	} else {
		struct ctx* _19 = ctx;
		int32_t _20 = wait_status2;
		uint8_t _21 = w_if_signaled(_19, _20);
		if (_21) {
			int32_t signal3;
			struct ctx* _22 = ctx;
			int32_t _23 = wait_status2;
			signal3 = w_term_sig(_22, _23);
			
			struct ctx* _24 = ctx;
			struct arr_0 _25 = (struct arr_0) {31, constantarr_0_42};
			struct ctx* _26 = ctx;
			int32_t _27 = signal3;
			struct arr_0 _28 = to_str_2(_26, _27);
			struct arr_0 _29 = _op_plus_0(_24, _25, _28);
			print(_29);
			return todo_7();
		} else {
			struct ctx* _30 = ctx;
			int32_t _31 = wait_status2;
			uint8_t _32 = w_if_stopped(_30, _31);
			if (_32) {
				struct arr_0 _33 = (struct arr_0) {12, constantarr_0_54};
				print(_33);
				return todo_7();
			} else {
				struct ctx* _34 = ctx;
				int32_t _35 = wait_status2;
				uint8_t _36 = w_if_continued(_34, _35);
				if (_36) {
					return todo_7();
				} else {
					return todo_7();
				}
			}
		}
	}
}
/* w-if-exited bool(status int32) */
uint8_t w_if_exited(struct ctx* ctx, int32_t status) {
	struct ctx* _0 = ctx;
	int32_t _1 = status;
	int32_t _2 = w_term_sig(_0, _1);
	int32_t _3 = 0;
	return _op_equal_equal_2(_2, _3);
}
/* w-term-sig int32(status int32) */
int32_t w_term_sig(struct ctx* ctx, int32_t status) {
	int32_t _0 = status;
	int32_t _1 = 127;
	return _0 & _1;
}
/* w-exit-status int32(status int32) */
int32_t w_exit_status(struct ctx* ctx, int32_t status) {
	int32_t _0 = status;
	int32_t _1 = 65280;
	int32_t _2 = _0 & _1;
	int32_t _3 = 8;
	return bit_shift_right(_2, _3);
}
/* bit-shift-right int32(a int32, b int32) */
int32_t bit_shift_right(int32_t a, int32_t b) {
	int32_t _0 = a;
	int32_t _1 = 0;
	uint8_t _2 = _op_less_3(_0, _1);
	if (_2) {
		return todo_7();
	} else {
		int32_t _3 = b;
		int32_t _4 = 0;
		uint8_t _5 = _op_less_3(_3, _4);
		if (_5) {
			return todo_7();
		} else {
			int32_t _6 = b;
			int32_t _7 = 32;
			uint8_t _8 = _op_less_3(_6, _7);
			if (_8) {
				int32_t _9 = a;
				int64_t _10 = (int64_t) _9;
				uint64_t _11 = (uint64_t) _10;
				int32_t _12 = b;
				int64_t _13 = (int64_t) _12;
				uint64_t _14 = (uint64_t) _13;
				uint64_t _15 = _11 >> _14;
				int64_t _16 = (int64_t) _15;
				return (int32_t) _16;
			} else {
				return todo_7();
			}
		}
	}
}
/* <<int32> bool(a int32, b int32) */
uint8_t _op_less_3(int32_t a, int32_t b) {
	int32_t _0 = a;
	int32_t _1 = b;
	struct comparison _2 = compare_99(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* todo<int32> int32() */
int32_t todo_7(void) {
	return (assert(0),0);
}
/* w-if-signaled bool(status int32) */
uint8_t w_if_signaled(struct ctx* ctx, int32_t status) {
	int32_t ts0;
	struct ctx* _0 = ctx;
	int32_t _1 = status;
	ts0 = w_term_sig(_0, _1);
	
	int32_t _2 = ts0;
	int32_t _3 = 0;
	uint8_t _4 = _op_bang_equal_2(_2, _3);
	if (_4) {
		int32_t _5 = ts0;
		int32_t _6 = 127;
		return _op_bang_equal_2(_5, _6);
	} else {
		return 0;
	}
}
/* to-str arr<char>(i int32) */
struct arr_0 to_str_2(struct ctx* ctx, int32_t i) {
	struct ctx* _0 = ctx;
	int32_t _1 = i;
	int64_t _2 = (int64_t) _1;
	return to_str_3(_0, _2);
}
/* to-str arr<char>(i int) */
struct arr_0 to_str_3(struct ctx* ctx, int64_t i) {
	struct arr_0 a0;
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	int64_t _2 = i;
	uint64_t _3 = abs(_1, _2);
	a0 = to_str_4(_0, _3);
	
	struct ctx* _4 = ctx;
	int64_t _5 = i;
	uint8_t _6 = negative__q(_4, _5);
	if (_6) {
		struct ctx* _7 = ctx;
		struct arr_0 _8 = (struct arr_0) {1, constantarr_0_53};
		struct arr_0 _9 = a0;
		return _op_plus_0(_7, _8, _9);
	} else {
		return a0;
	}
}
/* to-str arr<char>(n nat) */
struct arr_0 to_str_4(struct ctx* ctx, uint64_t n) {
	uint64_t _0 = n;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_equal_equal_0(_0, _1);
	if (_2) {
		return (struct arr_0) {1, constantarr_0_43};
	} else {
		uint64_t _3 = n;
		uint64_t _4 = 1u;
		uint8_t _5 = _op_equal_equal_0(_3, _4);
		if (_5) {
			return (struct arr_0) {1, constantarr_0_44};
		} else {
			uint64_t _6 = n;
			uint64_t _7 = 2u;
			uint8_t _8 = _op_equal_equal_0(_6, _7);
			if (_8) {
				return (struct arr_0) {1, constantarr_0_45};
			} else {
				uint64_t _9 = n;
				uint64_t _10 = 3u;
				uint8_t _11 = _op_equal_equal_0(_9, _10);
				if (_11) {
					return (struct arr_0) {1, constantarr_0_46};
				} else {
					uint64_t _12 = n;
					uint64_t _13 = 4u;
					uint8_t _14 = _op_equal_equal_0(_12, _13);
					if (_14) {
						return (struct arr_0) {1, constantarr_0_47};
					} else {
						uint64_t _15 = n;
						uint64_t _16 = 5u;
						uint8_t _17 = _op_equal_equal_0(_15, _16);
						if (_17) {
							return (struct arr_0) {1, constantarr_0_48};
						} else {
							uint64_t _18 = n;
							uint64_t _19 = 6u;
							uint8_t _20 = _op_equal_equal_0(_18, _19);
							if (_20) {
								return (struct arr_0) {1, constantarr_0_49};
							} else {
								uint64_t _21 = n;
								uint64_t _22 = 7u;
								uint8_t _23 = _op_equal_equal_0(_21, _22);
								if (_23) {
									return (struct arr_0) {1, constantarr_0_50};
								} else {
									uint64_t _24 = n;
									uint64_t _25 = 8u;
									uint8_t _26 = _op_equal_equal_0(_24, _25);
									if (_26) {
										return (struct arr_0) {1, constantarr_0_51};
									} else {
										uint64_t _27 = n;
										uint64_t _28 = 9u;
										uint8_t _29 = _op_equal_equal_0(_27, _28);
										if (_29) {
											return (struct arr_0) {1, constantarr_0_52};
										} else {
											struct arr_0 hi0;
											struct ctx* _30 = ctx;
											struct ctx* _31 = ctx;
											uint64_t _32 = n;
											uint64_t _33 = 10u;
											uint64_t _34 = _op_div(_31, _32, _33);
											hi0 = to_str_4(_30, _34);
											
											struct arr_0 lo1;
											struct ctx* _35 = ctx;
											struct ctx* _36 = ctx;
											uint64_t _37 = n;
											uint64_t _38 = 10u;
											uint64_t _39 = mod(_36, _37, _38);
											lo1 = to_str_4(_35, _39);
											
											struct ctx* _40 = ctx;
											struct arr_0 _41 = hi0;
											struct arr_0 _42 = lo1;
											return _op_plus_0(_40, _41, _42);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
/* mod nat(a nat, b nat) */
uint64_t mod(struct ctx* ctx, uint64_t a, uint64_t b) {
	struct ctx* _0 = ctx;
	uint64_t _1 = b;
	uint64_t _2 = 0u;
	uint8_t _3 = _op_equal_equal_0(_1, _2);
	forbid_0(_0, _3);
	uint64_t _4 = a;
	uint64_t _5 = b;
	return _4 % _5;
}
/* abs nat(i int) */
uint64_t abs(struct ctx* ctx, int64_t i) {
	int64_t i_abs0;
	struct ctx* _0 = ctx;
	int64_t _1 = i;
	uint8_t _2 = negative__q(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		int64_t _4 = i;
		i_abs0 = neg(_3, _4);
	} else {
		i_abs0 = i;
	}
	
	struct ctx* _5 = ctx;
	int64_t _6 = i_abs0;
	return to_nat_0(_5, _6);
}
/* neg int(i int) */
int64_t neg(struct ctx* ctx, int64_t i) {
	struct ctx* _0 = ctx;
	int64_t _1 = i;
	int64_t _2 = -1;
	return _op_times_1(_0, _1, _2);
}
/* * int(a int, b int) */
int64_t _op_times_1(struct ctx* ctx, int64_t a, int64_t b) {
	int64_t _0 = a;
	int64_t _1 = b;
	return _0 * _1;
}
/* w-if-stopped bool(status int32) */
uint8_t w_if_stopped(struct ctx* ctx, int32_t status) {
	int32_t _0 = status;
	int32_t _1 = 255;
	int32_t _2 = _0 & _1;
	int32_t _3 = 127;
	return _op_equal_equal_2(_2, _3);
}
/* w-if-continued bool(status int32) */
uint8_t w_if_continued(struct ctx* ctx, int32_t status) {
	int32_t _0 = status;
	int32_t _1 = 65535;
	return _op_equal_equal_2(_0, _1);
}
/* move-to-arr<char> arr<char>(a mut-list<char>) */
struct arr_0 move_to_arr_4(struct mut_list_5* a) {
	struct arr_0 res0;
	struct mut_list_5* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_5* _2 = a;
	char* _3 = data_11(_2);
	res0 = (struct arr_0) {_1, _3};
	
	struct mut_list_5* _4 = a;
	struct mut_arr_4 _5 = empty_mut_arr_4();
	_4->backing = _5;
	struct mut_list_5* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* convert-args ptr<ptr<char>>(exe-c-str ptr<char>, args arr<arr<char>>) */
char** convert_args(struct ctx* ctx, char* exe_c_str, struct arr_1 args) {
	struct ctx* _0 = ctx;
	char* _1 = exe_c_str;
	struct ctx* _2 = ctx;
	struct ctx* _3 = ctx;
	struct arr_1 _4 = args;
	struct void_ _5 = (struct void_) {};
	struct fun_act1_14 _6 = (struct fun_act1_14) {0, .as0 = _5};
	struct arr_4 _7 = map_1(_3, _4, _6);
	char* _8 = NULL;
	struct arr_4 _9 = append(_2, _7, _8);
	struct arr_4 _10 = prepend(_0, _1, _9);
	return _10.data;
}
/* prepend<ptr<char>> arr<ptr<char>>(a ptr<char>, b arr<ptr<char>>) */
struct arr_4 prepend(struct ctx* ctx, char* a, struct arr_4 b) {
	struct ctx* _0 = ctx;
	char** temp0;
	struct ctx* _1 = ctx;
	uint64_t _2 = sizeof(char*);
	uint64_t _3 = 1u;
	uint64_t _4 = _2 * _3;
	uint8_t* _5 = alloc(_1, _4);
	temp0 = (char**) _5;
	
	char** _6 = temp0;
	uint64_t _7 = 0u;
	char** _8 = _6 + _7;
	char* _9 = a;
	*_8 = _9;
	uint64_t _10 = 1u;
	char** _11 = temp0;
	struct arr_4 _12 = (struct arr_4) {_10, _11};
	struct arr_4 _13 = b;
	return _op_plus_2(_0, _12, _13);
}
/* +<?t> arr<ptr<char>>(a arr<ptr<char>>, b arr<ptr<char>>) */
struct arr_4 _op_plus_2(struct ctx* ctx, struct arr_4 a, struct arr_4 b) {
	uint64_t res_size0;
	struct ctx* _0 = ctx;
	struct arr_4 _1 = a;
	uint64_t _2 = _1.size;
	struct arr_4 _3 = b;
	uint64_t _4 = _3.size;
	res_size0 = _op_plus_1(_0, _2, _4);
	
	char** res1;
	struct ctx* _5 = ctx;
	uint64_t _6 = res_size0;
	res1 = uninitialized_data_5(_5, _6);
	
	struct ctx* _7 = ctx;
	char** _8 = res1;
	struct arr_4 _9 = a;
	char** _10 = _9.data;
	struct arr_4 _11 = a;
	uint64_t _12 = _11.size;
	copy_data_from_4(_7, _8, _10, _12);
	struct ctx* _13 = ctx;
	char** _14 = res1;
	struct arr_4 _15 = a;
	uint64_t _16 = _15.size;
	char** _17 = _14 + _16;
	struct arr_4 _18 = b;
	char** _19 = _18.data;
	struct arr_4 _20 = b;
	uint64_t _21 = _20.size;
	copy_data_from_4(_13, _17, _19, _21);
	uint64_t _22 = res_size0;
	char** _23 = res1;
	return (struct arr_4) {_22, _23};
}
/* uninitialized-data<?t> ptr<ptr<char>>(size nat) */
char** uninitialized_data_5(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	uint64_t _2 = sizeof(char*);
	uint64_t _3 = _1 * _2;
	bptr0 = alloc(_0, _3);
	
	uint8_t* _4 = bptr0;
	return (char**) _4;
}
/* copy-data-from<?t> void(to ptr<ptr<char>>, from ptr<ptr<char>>, len nat) */
struct void_ copy_data_from_4(struct ctx* ctx, char** to, char** from, uint64_t len) {
	top:;
	uint64_t _0 = len;
	uint64_t _1 = 8u;
	uint8_t _2 = _op_less_0(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		char** _4 = to;
		char** _5 = from;
		uint64_t _6 = len;
		return copy_data_from_small_4(_3, _4, _5, _6);
	} else {
		uint64_t hl0;
		struct ctx* _7 = ctx;
		uint64_t _8 = len;
		uint64_t _9 = 2u;
		hl0 = _op_div(_7, _8, _9);
		
		struct ctx* _10 = ctx;
		char** _11 = to;
		char** _12 = from;
		uint64_t _13 = hl0;
		copy_data_from_4(_10, _11, _12, _13);
		char** _14 = to;
		uint64_t _15 = hl0;
		char** _16 = _14 + _15;
		char** _17 = from;
		uint64_t _18 = hl0;
		char** _19 = _17 + _18;
		struct ctx* _20 = ctx;
		uint64_t _21 = len;
		uint64_t _22 = hl0;
		uint64_t _23 = _op_minus_2(_20, _21, _22);
		to = _16;
		from = _19;
		len = _23;
		goto top;
	}
}
/* copy-data-from-small<?t> void(to ptr<ptr<char>>, from ptr<ptr<char>>, len nat) */
struct void_ copy_data_from_small_4(struct ctx* ctx, char** to, char** from, uint64_t len) {
	uint64_t _0 = len;
	uint64_t _1 = 0u;
	uint8_t _2 = _op_bang_equal_1(_0, _1);
	if (_2) {
		char** _3 = to;
		char** _4 = from;
		char* _5 = *_4;
		*_3 = _5;
		struct ctx* _6 = ctx;
		char** _7 = to;
		char** _8 = incr_6(_7);
		char** _9 = from;
		char** _10 = incr_6(_9);
		struct ctx* _11 = ctx;
		uint64_t _12 = len;
		uint64_t _13 = decr(_11, _12);
		return copy_data_from_4(_6, _8, _10, _13);
	} else {
		return (struct void_) {};
	}
}
/* append<ptr<char>> arr<ptr<char>>(a arr<ptr<char>>, b ptr<char>) */
struct arr_4 append(struct ctx* ctx, struct arr_4 a, char* b) {
	struct ctx* _0 = ctx;
	struct arr_4 _1 = a;
	char** temp0;
	struct ctx* _2 = ctx;
	uint64_t _3 = sizeof(char*);
	uint64_t _4 = 1u;
	uint64_t _5 = _3 * _4;
	uint8_t* _6 = alloc(_2, _5);
	temp0 = (char**) _6;
	
	char** _7 = temp0;
	uint64_t _8 = 0u;
	char** _9 = _7 + _8;
	char* _10 = b;
	*_9 = _10;
	uint64_t _11 = 1u;
	char** _12 = temp0;
	struct arr_4 _13 = (struct arr_4) {_11, _12};
	return _op_plus_2(_0, _1, _13);
}
/* map<ptr<char>, arr<char>> arr<ptr<char>>(a arr<arr<char>>, mapper fun-act1<ptr<char>, arr<char>>) */
struct arr_4 map_1(struct ctx* ctx, struct arr_1 a, struct fun_act1_14 mapper) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	struct map_1__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct map_1__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct map_1__lambda0*) _5;
	
	struct map_1__lambda0* _6 = temp0;
	struct fun_act1_14 _7 = mapper;
	struct arr_1 _8 = a;
	struct map_1__lambda0 _9 = (struct map_1__lambda0) {_7, _8};
	*_6 = _9;
	struct map_1__lambda0* _10 = temp0;
	struct fun_act1_15 _11 = (struct fun_act1_15) {0, .as0 = _10};
	return make_arr_1(_0, _2, _11);
}
/* make-arr<?out> arr<ptr<char>>(size nat, f fun-act1<ptr<char>, nat>) */
struct arr_4 make_arr_1(struct ctx* ctx, uint64_t size, struct fun_act1_15 f) {
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	struct fun_act1_15 _2 = f;
	struct mut_arr_6 _3 = make_mut_arr_2(_0, _1, _2);
	return cast_immutable_2(_3);
}
/* cast-immutable<?t> arr<ptr<char>>(a mut-arr<ptr<char>>) */
struct arr_4 cast_immutable_2(struct mut_arr_6 a) {
	struct mut_arr_6 _0 = a;
	return _0.arr;
}
/* make-mut-arr<?t> mut-arr<ptr<char>>(size nat, f fun-act1<ptr<char>, nat>) */
struct mut_arr_6 make_mut_arr_2(struct ctx* ctx, uint64_t size, struct fun_act1_15 f) {
	struct mut_arr_6 res0;
	struct ctx* _0 = ctx;
	uint64_t _1 = size;
	res0 = new_uninitialized_mut_arr_3(_0, _1);
	
	struct ctx* _2 = ctx;
	struct mut_arr_6 _3 = res0;
	uint64_t _4 = 0u;
	struct fun_act1_15 _5 = f;
	make_mut_arr_worker_2(_2, _3, _4, _5);
	return res0;
}
/* new-uninitialized-mut-arr<?t> mut-arr<ptr<char>>(size nat) */
struct mut_arr_6 new_uninitialized_mut_arr_3(struct ctx* ctx, uint64_t size) {
	uint64_t _0 = size;
	struct ctx* _1 = ctx;
	uint64_t _2 = size;
	char** _3 = uninitialized_data_5(_1, _2);
	return mut_arr_6(_0, _3);
}
/* mut-arr<?t> mut-arr<ptr<char>>(size nat, data ptr<ptr<char>>) */
struct mut_arr_6 mut_arr_6(uint64_t size, char** data) {
	uint64_t _0 = size;
	char** _1 = data;
	struct arr_4 _2 = (struct arr_4) {_0, _1};
	return (struct mut_arr_6) {_2};
}
/* make-mut-arr-worker<?t> void(a mut-arr<ptr<char>>, i nat, f fun-act1<ptr<char>, nat>) */
struct void_ make_mut_arr_worker_2(struct ctx* ctx, struct mut_arr_6 a, uint64_t i, struct fun_act1_15 f) {
	top:;
	uint64_t _0 = i;
	struct mut_arr_6 _1 = a;
	uint64_t _2 = size_7(_1);
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_arr_6 _5 = a;
		uint64_t _6 = i;
		struct ctx* _7 = ctx;
		struct fun_act1_15 _8 = f;
		uint64_t _9 = i;
		char* _10 = call_20(_7, _8, _9);
		set_at_4(_4, _5, _6, _10);
		struct mut_arr_6 _11 = a;
		struct ctx* _12 = ctx;
		uint64_t _13 = i;
		uint64_t _14 = incr_3(_12, _13);
		struct fun_act1_15 _15 = f;
		a = _11;
		i = _14;
		f = _15;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* size<?t> nat(a mut-arr<ptr<char>>) */
uint64_t size_7(struct mut_arr_6 a) {
	struct mut_arr_6 _0 = a;
	struct arr_4 _1 = _0.arr;
	return _1.size;
}
/* set-at<?t> void(a mut-arr<ptr<char>>, index nat, value ptr<char>) */
struct void_ set_at_4(struct ctx* ctx, struct mut_arr_6 a, uint64_t index, char* value) {
	struct ctx* _0 = ctx;
	uint64_t _1 = index;
	struct mut_arr_6 _2 = a;
	uint64_t _3 = size_7(_2);
	uint8_t _4 = _op_less_0(_1, _3);
	assert_0(_0, _4);
	struct mut_arr_6 _5 = a;
	uint64_t _6 = index;
	char* _7 = value;
	return noctx_set_at_5(_5, _6, _7);
}
/* noctx-set-at<?t> void(a mut-arr<ptr<char>>, index nat, value ptr<char>) */
struct void_ noctx_set_at_5(struct mut_arr_6 a, uint64_t index, char* value) {
	uint64_t _0 = index;
	struct mut_arr_6 _1 = a;
	uint64_t _2 = size_7(_1);
	uint8_t _3 = _op_less_0(_0, _2);
	hard_assert(_3);
	struct mut_arr_6 _4 = a;
	char** _5 = data_12(_4);
	uint64_t _6 = index;
	char** _7 = _5 + _6;
	char* _8 = value;
	return (*_7 = _8, (struct void_) {});
}
/* data<?t> ptr<ptr<char>>(a mut-arr<ptr<char>>) */
char** data_12(struct mut_arr_6 a) {
	struct mut_arr_6 _0 = a;
	struct arr_4 _1 = _0.arr;
	return _1.data;
}
/* call<?t, nat> ptr<char>(a fun-act1<ptr<char>, nat>, p0 nat) */
char* call_20(struct ctx* ctx, struct fun_act1_15 a, uint64_t p0) {
	struct fun_act1_15 _0 = a;
	struct ctx* _1 = ctx;
	uint64_t _2 = p0;
	return call_w_ctx_694(_0, _1, _2);
}
/* call-w-ctx<raw-ptr(char), nat-64> (generated) (generated) */
char* call_w_ctx_694(struct fun_act1_15 a, struct ctx* ctx, uint64_t p0) {
	struct fun_act1_15 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct map_1__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct map_1__lambda0* _2 = closure0;
			uint64_t _3 = p0;
			return map_1__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),NULL);
	}
}
/* call<?out, ?in> ptr<char>(a fun-act1<ptr<char>, arr<char>>, p0 arr<char>) */
char* call_21(struct ctx* ctx, struct fun_act1_14 a, struct arr_0 p0) {
	struct fun_act1_14 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	return call_w_ctx_696(_0, _1, _2);
}
/* call-w-ctx<raw-ptr(char), arr<char>> (generated) (generated) */
char* call_w_ctx_696(struct fun_act1_14 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_14 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct void_ _2 = closure0;
			struct arr_0 _3 = p0;
			return convert_args__lambda0(_1, _2, _3);
		}
		default:
			return (assert(0),NULL);
	}
}
/* map<ptr<char>, arr<char>>.lambda0 ptr<char>(i nat) */
char* map_1__lambda0(struct ctx* ctx, struct map_1__lambda0* _closure, uint64_t i) {
	struct ctx* _0 = ctx;
	struct map_1__lambda0* _1 = _closure;
	struct fun_act1_14 _2 = _1->mapper;
	struct ctx* _3 = ctx;
	struct map_1__lambda0* _4 = _closure;
	struct arr_1 _5 = _4->a;
	uint64_t _6 = i;
	struct arr_0 _7 = at_2(_3, _5, _6);
	return call_21(_0, _2, _7);
}
/* convert-args.lambda0 ptr<char>(it arr<char>) */
char* convert_args__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = it;
	return to_c_str(_0, _1);
}
/* convert-environ ptr<ptr<char>>(environ dict<arr<char>, arr<char>>) */
char** convert_environ(struct ctx* ctx, struct dict_1* environ) {
	struct mut_list_6* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_4(_0);
	
	struct ctx* _1 = ctx;
	struct dict_1* _2 = environ;
	struct convert_environ__lambda0* temp0;
	struct ctx* _3 = ctx;
	uint64_t _4 = sizeof(struct convert_environ__lambda0);
	uint8_t* _5 = alloc(_3, _4);
	temp0 = (struct convert_environ__lambda0*) _5;
	
	struct convert_environ__lambda0* _6 = temp0;
	struct mut_list_6* _7 = res0;
	struct convert_environ__lambda0 _8 = (struct convert_environ__lambda0) {_7};
	*_6 = _8;
	struct convert_environ__lambda0* _9 = temp0;
	struct fun_act2_2 _10 = (struct fun_act2_2) {0, .as0 = _9};
	each_3(_1, _2, _10);
	struct ctx* _11 = ctx;
	struct mut_list_6* _12 = res0;
	char* _13 = NULL;
	push_3(_11, _12, _13);
	struct mut_list_6* _14 = res0;
	struct arr_4 _15 = move_to_arr_5(_14);
	return _15.data;
}
/* new-mut-list<ptr<char>> mut-list<ptr<char>>() */
struct mut_list_6* new_mut_list_4(struct ctx* ctx) {
	struct mut_list_6* temp0;
	struct ctx* _0 = ctx;
	uint64_t _1 = sizeof(struct mut_list_6);
	uint8_t* _2 = alloc(_0, _1);
	temp0 = (struct mut_list_6*) _2;
	
	struct mut_list_6* _3 = temp0;
	struct mut_arr_6 _4 = empty_mut_arr_5();
	uint64_t _5 = 0u;
	struct mut_list_6 _6 = (struct mut_list_6) {_4, _5};
	*_3 = _6;
	return temp0;
}
/* empty-mut-arr<?t> mut-arr<ptr<char>>() */
struct mut_arr_6 empty_mut_arr_5(void) {
	struct arr_4 _0 = empty_arr_6();
	return (struct mut_arr_6) {_0};
}
/* empty-arr<?t> arr<ptr<char>>() */
struct arr_4 empty_arr_6(void) {
	uint64_t _0 = 0u;
	char** _1 = NULL;
	return (struct arr_4) {_0, _1};
}
/* each<arr<char>, arr<char>> void(d dict<arr<char>, arr<char>>, f fun-act2<void, arr<char>, arr<char>>) */
struct void_ each_3(struct ctx* ctx, struct dict_1* d, struct fun_act2_2 f) {
	top:;
	struct ctx* _0 = ctx;
	struct dict_1* _1 = d;
	uint8_t _2 = empty__q_12(_0, _1);
	uint8_t _3 = !_2;
	if (_3) {
		struct ctx* _4 = ctx;
		struct fun_act2_2 _5 = f;
		struct ctx* _6 = ctx;
		struct dict_1* _7 = d;
		struct arr_1 _8 = _7->keys;
		struct arr_0 _9 = first_1(_6, _8);
		struct ctx* _10 = ctx;
		struct dict_1* _11 = d;
		struct arr_1 _12 = _11->values;
		struct arr_0 _13 = first_1(_10, _12);
		call_22(_4, _5, _9, _13);
		struct dict_1* temp0;
		struct ctx* _14 = ctx;
		uint64_t _15 = sizeof(struct dict_1);
		uint8_t* _16 = alloc(_14, _15);
		temp0 = (struct dict_1*) _16;
		
		struct dict_1* _17 = temp0;
		struct ctx* _18 = ctx;
		struct dict_1* _19 = d;
		struct arr_1 _20 = _19->keys;
		struct arr_1 _21 = tail_2(_18, _20);
		struct ctx* _22 = ctx;
		struct dict_1* _23 = d;
		struct arr_1 _24 = _23->values;
		struct arr_1 _25 = tail_2(_22, _24);
		struct dict_1 _26 = (struct dict_1) {_21, _25};
		*_17 = _26;
		struct dict_1* _27 = temp0;
		struct fun_act2_2 _28 = f;
		d = _27;
		f = _28;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* empty?<?k, ?v> bool(d dict<arr<char>, arr<char>>) */
uint8_t empty__q_12(struct ctx* ctx, struct dict_1* d) {
	struct dict_1* _0 = d;
	struct arr_1 _1 = _0->keys;
	return empty__q_5(_1);
}
/* call<void, ?k, ?v> void(a fun-act2<void, arr<char>, arr<char>>, p0 arr<char>, p1 arr<char>) */
struct void_ call_22(struct ctx* ctx, struct fun_act2_2 a, struct arr_0 p0, struct arr_0 p1) {
	struct fun_act2_2 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	struct arr_0 _3 = p1;
	return call_w_ctx_706(_0, _1, _2, _3);
}
/* call-w-ctx<void, arr<char>, arr<char>> (generated) (generated) */
struct void_ call_w_ctx_706(struct fun_act2_2 a, struct ctx* ctx, struct arr_0 p0, struct arr_0 p1) {
	struct fun_act2_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct convert_environ__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct convert_environ__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			struct arr_0 _4 = p1;
			return convert_environ__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* push<ptr<char>> void(a mut-list<ptr<char>>, value ptr<char>) */
struct void_ push_3(struct ctx* ctx, struct mut_list_6* a, char* value) {
	struct mut_list_6* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_6* _2 = a;
	uint64_t _3 = capacity_5(_2);
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct mut_list_6* _6 = a;
		struct mut_list_6* _7 = a;
		uint64_t _8 = _7->size;
		uint64_t _9 = 0u;
		uint8_t _10 = _op_equal_equal_0(_8, _9);uint64_t _11;
		
		if (_10) {
			_11 = 4u;
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_6* _13 = a;
			uint64_t _14 = _13->size;
			uint64_t _15 = 2u;
			_11 = _op_times_0(_12, _14, _15);
		}
		increase_capacity_to_4(_5, _6, _11);
	} else {
		(struct void_) {};
	}
	struct ctx* _16 = ctx;
	struct mut_list_6* _17 = a;
	struct ctx* _18 = ctx;
	struct ctx* _19 = ctx;
	struct mut_list_6* _20 = a;
	uint64_t _21 = _20->size;
	uint64_t _22 = incr_3(_19, _21);
	uint64_t _23 = round_up_to_power_of_two(_18, _22);
	ensure_capacity_4(_16, _17, _23);
	struct ctx* _24 = ctx;
	struct mut_list_6* _25 = a;
	uint64_t _26 = _25->size;
	struct mut_list_6* _27 = a;
	uint64_t _28 = capacity_5(_27);
	uint8_t _29 = _op_less_0(_26, _28);
	assert_0(_24, _29);
	struct mut_list_6* _30 = a;
	char** _31 = data_13(_30);
	struct mut_list_6* _32 = a;
	uint64_t _33 = _32->size;
	char** _34 = _31 + _33;
	char* _35 = value;
	*_34 = _35;
	struct mut_list_6* _36 = a;
	struct ctx* _37 = ctx;
	struct mut_list_6* _38 = a;
	uint64_t _39 = _38->size;
	uint64_t _40 = incr_3(_37, _39);
	return (_36->size = _40, (struct void_) {});
}
/* capacity<?t> nat(a mut-list<ptr<char>>) */
uint64_t capacity_5(struct mut_list_6* a) {
	struct mut_list_6* _0 = a;
	struct mut_arr_6 _1 = _0->backing;
	return size_7(_1);
}
/* increase-capacity-to<?t> void(a mut-list<ptr<char>>, new-capacity nat) */
struct void_ increase_capacity_to_4(struct ctx* ctx, struct mut_list_6* a, uint64_t new_capacity) {
	struct ctx* _0 = ctx;
	uint64_t _1 = new_capacity;
	struct mut_list_6* _2 = a;
	uint64_t _3 = capacity_5(_2);
	uint8_t _4 = _op_greater(_1, _3);
	assert_0(_0, _4);
	char** old_data0;
	struct mut_list_6* _5 = a;
	old_data0 = data_13(_5);
	
	struct mut_list_6* _6 = a;
	uint64_t _7 = new_capacity;
	struct ctx* _8 = ctx;
	uint64_t _9 = new_capacity;
	char** _10 = uninitialized_data_5(_8, _9);
	struct mut_arr_6 _11 = mut_arr_6(_7, _10);
	_6->backing = _11;
	struct ctx* _12 = ctx;
	struct mut_list_6* _13 = a;
	char** _14 = data_13(_13);
	char** _15 = old_data0;
	struct mut_list_6* _16 = a;
	uint64_t _17 = _16->size;
	copy_data_from_4(_12, _14, _15, _17);
	struct ctx* _18 = ctx;
	struct mut_list_6* _19 = a;
	struct mut_arr_6 _20 = _19->backing;
	struct mut_list_6* _21 = a;
	uint64_t _22 = _21->size;
	struct mut_arr_6 _23 = slice_starting_at_9(_18, _20, _22);
	return set_zero_elements_4(_23);
}
/* data<?t> ptr<ptr<char>>(a mut-list<ptr<char>>) */
char** data_13(struct mut_list_6* a) {
	struct mut_list_6* _0 = a;
	struct mut_arr_6 _1 = _0->backing;
	return data_12(_1);
}
/* set-zero-elements<?t> void(a mut-arr<ptr<char>>) */
struct void_ set_zero_elements_4(struct mut_arr_6 a) {
	struct mut_arr_6 _0 = a;
	char** _1 = data_12(_0);
	struct mut_arr_6 _2 = a;
	uint64_t _3 = size_7(_2);
	return set_zero_range_5(_1, _3);
}
/* set-zero-range<?t> void(begin ptr<ptr<char>>, size nat) */
struct void_ set_zero_range_5(char** begin, uint64_t size) {
	char** _0 = begin;
	uint8_t* _1 = (uint8_t*) _0;
	uint8_t _2 = 0u;
	uint64_t _3 = size;
	uint64_t _4 = sizeof(char*);
	uint64_t _5 = _3 * _4;
	return (memset(_1, _2, _5), (struct void_) {});
}
/* slice-starting-at<?t> mut-arr<ptr<char>>(a mut-arr<ptr<char>>, begin nat) */
struct mut_arr_6 slice_starting_at_9(struct ctx* ctx, struct mut_arr_6 a, uint64_t begin) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	struct mut_arr_6 _2 = a;
	uint64_t _3 = size_7(_2);
	uint8_t _4 = _op_less_equal(_1, _3);
	assert_0(_0, _4);
	struct ctx* _5 = ctx;
	struct mut_arr_6 _6 = a;
	uint64_t _7 = begin;
	struct ctx* _8 = ctx;
	struct mut_arr_6 _9 = a;
	uint64_t _10 = size_7(_9);
	uint64_t _11 = begin;
	uint64_t _12 = _op_minus_2(_8, _10, _11);
	return slice_9(_5, _6, _7, _12);
}
/* slice<?t> mut-arr<ptr<char>>(a mut-arr<ptr<char>>, begin nat, size nat) */
struct mut_arr_6 slice_9(struct ctx* ctx, struct mut_arr_6 a, uint64_t begin, uint64_t size) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = begin;
	uint64_t _3 = size;
	uint64_t _4 = _op_plus_1(_1, _2, _3);
	struct mut_arr_6 _5 = a;
	uint64_t _6 = size_7(_5);
	uint8_t _7 = _op_less_equal(_4, _6);
	assert_0(_0, _7);
	uint64_t _8 = size;
	struct mut_arr_6 _9 = a;
	char** _10 = data_12(_9);
	uint64_t _11 = begin;
	char** _12 = _10 + _11;
	return mut_arr_6(_8, _12);
}
/* ensure-capacity<?t> void(a mut-list<ptr<char>>, capacity nat) */
struct void_ ensure_capacity_4(struct ctx* ctx, struct mut_list_6* a, uint64_t capacity) {
	struct mut_list_6* _0 = a;
	uint64_t _1 = capacity_5(_0);
	uint64_t _2 = capacity;
	uint8_t _3 = _op_less_0(_1, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct mut_list_6* _5 = a;
		struct ctx* _6 = ctx;
		uint64_t _7 = capacity;
		uint64_t _8 = round_up_to_power_of_two(_6, _7);
		return increase_capacity_to_4(_4, _5, _8);
	} else {
		return (struct void_) {};
	}
}
/* convert-environ.lambda0 void(key arr<char>, value arr<char>) */
struct void_ convert_environ__lambda0(struct ctx* ctx, struct convert_environ__lambda0* _closure, struct arr_0 key, struct arr_0 value) {
	struct ctx* _0 = ctx;
	struct convert_environ__lambda0* _1 = _closure;
	struct mut_list_6* _2 = _1->res;
	struct ctx* _3 = ctx;
	struct ctx* _4 = ctx;
	struct ctx* _5 = ctx;
	struct arr_0 _6 = key;
	struct arr_0 _7 = (struct arr_0) {1, constantarr_0_55};
	struct arr_0 _8 = _op_plus_0(_5, _6, _7);
	struct arr_0 _9 = value;
	struct arr_0 _10 = _op_plus_0(_4, _8, _9);
	char* _11 = to_c_str(_3, _10);
	return push_3(_0, _2, _11);
}
/* move-to-arr<ptr<char>> arr<ptr<char>>(a mut-list<ptr<char>>) */
struct arr_4 move_to_arr_5(struct mut_list_6* a) {
	struct arr_4 res0;
	struct mut_list_6* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_6* _2 = a;
	char** _3 = data_13(_2);
	res0 = (struct arr_4) {_1, _3};
	
	struct mut_list_6* _4 = a;
	struct mut_arr_6 _5 = empty_mut_arr_5();
	_4->backing = _5;
	struct mut_list_6* _6 = a;
	uint64_t _7 = 0u;
	_6->size = _7;
	return res0;
}
/* fail<process-result> process-result(reason arr<char>) */
struct process_result* fail_3(struct ctx* ctx, struct arr_0 reason) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = reason;
	struct exception _2 = (struct exception) {_1};
	return throw_3(_0, _2);
}
/* throw<?t> process-result(e exception) */
struct process_result* throw_3(struct ctx* ctx, struct exception e) {
	struct exception_ctx* exn_ctx0;
	struct ctx* _0 = ctx;
	exn_ctx0 = get_exception_ctx(_0);
	
	struct exception_ctx* _1 = exn_ctx0;
	struct jmp_buf_tag* _2 = _1->jmp_buf_ptr;
	uint8_t _3 = null__q_1(_2);
	hard_forbid(_3);
	struct exception_ctx* _4 = exn_ctx0;
	struct exception _5 = e;
	_4->thrown_exception = _5;
	struct exception_ctx* _6 = exn_ctx0;
	struct jmp_buf_tag* _7 = _6->jmp_buf_ptr;
	struct ctx* _8 = ctx;
	int32_t _9 = number_to_throw(_8);
	(longjmp(_7, _9), (struct void_) {});
	return todo_8();
}
/* todo<?t> process-result() */
struct process_result* todo_8(void) {
	return (assert(0),NULL);
}
/* handle-output arr<failure>(original-path arr<char>, output-path arr<char>, actual arr<char>, overwrite-output? bool) */
struct arr_7 handle_output(struct ctx* ctx, struct arr_0 original_path, struct arr_0 output_path, struct arr_0 actual, uint8_t overwrite_output__q) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = output_path;
	struct opt_8 _2 = try_read_file_0(_0, _1);
	switch (_2.kind) {
		case 0: {
			uint8_t _3 = overwrite_output__q;
			if (_3) {
				struct ctx* _4 = ctx;
				struct arr_0 _5 = output_path;
				struct arr_0 _6 = actual;
				write_file_0(_4, _5, _6);
				return empty_arr_4();
			} else {
				struct failure** temp0;
				struct ctx* _7 = ctx;
				uint64_t _8 = sizeof(struct failure*);
				uint64_t _9 = 1u;
				uint64_t _10 = _8 * _9;
				uint8_t* _11 = alloc(_7, _10);
				temp0 = (struct failure**) _11;
				
				struct failure** _12 = temp0;
				uint64_t _13 = 0u;
				struct failure** _14 = _12 + _13;
				struct failure* temp1;
				struct ctx* _15 = ctx;
				uint64_t _16 = sizeof(struct failure);
				uint8_t* _17 = alloc(_15, _16);
				temp1 = (struct failure*) _17;
				
				struct failure* _18 = temp1;
				struct arr_0 _19 = original_path;
				struct ctx* _20 = ctx;
				struct ctx* _21 = ctx;
				struct ctx* _22 = ctx;
				struct arr_0 _23 = output_path;
				struct arr_0 _24 = base_name(_22, _23);
				struct arr_0 _25 = (struct arr_0) {29, constantarr_0_64};
				struct arr_0 _26 = _op_plus_0(_21, _24, _25);
				struct arr_0 _27 = actual;
				struct arr_0 _28 = _op_plus_0(_20, _26, _27);
				struct failure _29 = (struct failure) {_19, _28};
				*_18 = _29;
				struct failure* _30 = temp1;
				*_14 = _30;
				uint64_t _31 = 1u;
				struct failure** _32 = temp0;
				return (struct arr_7) {_31, _32};
			}
		}
		case 1: {
			struct some_8 s0 = _2.as1;
			
			struct some_8 _33 = s0;
			struct arr_0 _34 = _33.value;
			struct arr_0 _35 = actual;
			uint8_t _36 = _op_equal_equal_4(_34, _35);
			if (_36) {
				return empty_arr_4();
			} else {
				uint8_t _37 = overwrite_output__q;
				if (_37) {
					struct ctx* _38 = ctx;
					struct arr_0 _39 = output_path;
					struct arr_0 _40 = actual;
					write_file_0(_38, _39, _40);
					return empty_arr_4();
				} else {
					struct arr_0 message1;
					struct ctx* _41 = ctx;
					struct ctx* _42 = ctx;
					struct ctx* _43 = ctx;
					struct arr_0 _44 = output_path;
					struct arr_0 _45 = base_name(_43, _44);
					struct arr_0 _46 = (struct arr_0) {30, constantarr_0_65};
					struct arr_0 _47 = _op_plus_0(_42, _45, _46);
					struct arr_0 _48 = actual;
					message1 = _op_plus_0(_41, _47, _48);
					
					struct failure** temp2;
					struct ctx* _49 = ctx;
					uint64_t _50 = sizeof(struct failure*);
					uint64_t _51 = 1u;
					uint64_t _52 = _50 * _51;
					uint8_t* _53 = alloc(_49, _52);
					temp2 = (struct failure**) _53;
					
					struct failure** _54 = temp2;
					uint64_t _55 = 0u;
					struct failure** _56 = _54 + _55;
					struct failure* temp3;
					struct ctx* _57 = ctx;
					uint64_t _58 = sizeof(struct failure);
					uint8_t* _59 = alloc(_57, _58);
					temp3 = (struct failure*) _59;
					
					struct failure* _60 = temp3;
					struct arr_0 _61 = original_path;
					struct arr_0 _62 = message1;
					struct failure _63 = (struct failure) {_61, _62};
					*_60 = _63;
					struct failure* _64 = temp3;
					*_56 = _64;
					uint64_t _65 = 1u;
					struct failure** _66 = temp2;
					return (struct arr_7) {_65, _66};
				}
			}
		}
		default:
			return (assert(0),(struct arr_7) {0, NULL});
	}
}
/* try-read-file opt<arr<char>>(path arr<char>) */
struct opt_8 try_read_file_0(struct ctx* ctx, struct arr_0 path) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	char* _3 = to_c_str(_1, _2);
	return try_read_file_1(_0, _3);
}
/* try-read-file opt<arr<char>>(path ptr<char>) */
struct opt_8 try_read_file_1(struct ctx* ctx, char* path) {
	struct ctx* _0 = ctx;
	char* _1 = path;
	uint8_t _2 = is_file__q_1(_0, _1);
	if (_2) {
		int32_t fd0;
		char* _3 = path;
		int32_t _4 = o_rdonly();
		uint32_t _5 = 0u;
		fd0 = open(_3, _4, _5);
		
		int32_t _6 = fd0;
		int32_t _7 = -1;
		uint8_t _8 = _op_equal_equal_2(_6, _7);
		if (_8) {
			int32_t _9 = errno;
			int32_t _10 = enoent();
			uint8_t _11 = _op_equal_equal_2(_9, _10);
			if (_11) {
				struct none _12 = (struct none) {};
				return (struct opt_8) {0, .as0 = _12};
			} else {
				struct ctx* _13 = ctx;
				struct arr_0 _14 = (struct arr_0) {20, constantarr_0_59};
				char* _15 = path;
				struct arr_0 _16 = to_str_1(_15);
				struct arr_0 _17 = _op_plus_0(_13, _14, _16);
				print(_17);
				return todo_9();
			}
		} else {
			int64_t file_size1;
			int32_t _18 = fd0;
			int64_t _19 = 0;
			struct ctx* _20 = ctx;
			int32_t _21 = seek_end(_20);
			file_size1 = lseek(_18, _19, _21);
			
			struct ctx* _22 = ctx;
			int64_t _23 = file_size1;
			int64_t _24 = -1;
			uint8_t _25 = _op_equal_equal_1(_23, _24);
			forbid_0(_22, _25);
			struct ctx* _26 = ctx;
			int64_t _27 = file_size1;
			int64_t _28 = 1000000000;
			uint8_t _29 = _op_less_1(_27, _28);
			assert_0(_26, _29);
			struct ctx* _30 = ctx;
			int64_t _31 = file_size1;
			int64_t _32 = 0;
			uint8_t _33 = _op_equal_equal_1(_31, _32);
			forbid_0(_30, _33);
			int64_t off2;
			int32_t _34 = fd0;
			int64_t _35 = 0;
			struct ctx* _36 = ctx;
			int32_t _37 = seek_set(_36);
			off2 = lseek(_34, _35, _37);
			
			struct ctx* _38 = ctx;
			int64_t _39 = off2;
			int64_t _40 = 0;
			uint8_t _41 = _op_equal_equal_1(_39, _40);
			assert_0(_38, _41);
			uint64_t file_size_nat3;
			struct ctx* _42 = ctx;
			int64_t _43 = file_size1;
			file_size_nat3 = to_nat_0(_42, _43);
			
			struct mut_arr_4 res4;
			struct ctx* _44 = ctx;
			uint64_t _45 = file_size_nat3;
			res4 = new_uninitialized_mut_arr_2(_44, _45);
			
			int64_t n_bytes_read5;
			int32_t _46 = fd0;
			struct mut_arr_4 _47 = res4;
			char* _48 = data_8(_47);
			uint8_t* _49 = (uint8_t*) _48;
			uint64_t _50 = file_size_nat3;
			n_bytes_read5 = read(_46, _49, _50);
			
			struct ctx* _51 = ctx;
			int64_t _52 = n_bytes_read5;
			int64_t _53 = -1;
			uint8_t _54 = _op_equal_equal_1(_52, _53);
			forbid_0(_51, _54);
			struct ctx* _55 = ctx;
			int64_t _56 = n_bytes_read5;
			int64_t _57 = file_size1;
			uint8_t _58 = _op_equal_equal_1(_56, _57);
			assert_0(_55, _58);
			struct ctx* _59 = ctx;
			int32_t _60 = fd0;
			int32_t _61 = close(_60);
			check_posix_error(_59, _61);
			struct mut_arr_4 _62 = res4;
			struct arr_0 _63 = cast_immutable_1(_62);
			struct some_8 _64 = (struct some_8) {_63};
			return (struct opt_8) {1, .as1 = _64};
		}
	} else {
		struct none _65 = (struct none) {};
		return (struct opt_8) {0, .as0 = _65};
	}
}
/* o-rdonly int32() */
int32_t o_rdonly(void) {
	return 0;
}
/* todo<opt<arr<char>>> opt<arr<char>>() */
struct opt_8 todo_9(void) {
	return (assert(0),(struct opt_8) {0});
}
/* seek-end int32() */
int32_t seek_end(struct ctx* ctx) {
	return 2;
}
/* seek-set int32() */
int32_t seek_set(struct ctx* ctx) {
	return 0;
}
/* write-file void(path arr<char>, content arr<char>) */
struct void_ write_file_0(struct ctx* ctx, struct arr_0 path, struct arr_0 content) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	char* _3 = to_c_str(_1, _2);
	struct arr_0 _4 = content;
	return write_file_1(_0, _3, _4);
}
/* write-file void(path ptr<char>, content arr<char>) */
struct void_ write_file_1(struct ctx* ctx, char* path, struct arr_0 content) {
	uint32_t permission_rdwr0;
	permission_rdwr0 = 6u;
	
	uint32_t permission_rd1;
	permission_rd1 = 4u;
	
	uint32_t permission2;
	uint32_t _0 = permission_rdwr0;
	uint32_t _1 = 6u;
	uint32_t _2 = bit_shift_left(_0, _1);
	uint32_t _3 = permission_rd1;
	uint32_t _4 = 3u;
	uint32_t _5 = bit_shift_left(_3, _4);
	uint32_t _6 = _2 | _5;
	uint32_t _7 = permission_rd1;
	permission2 = _6 | _7;
	
	int32_t flags3;
	int32_t _8 = o_creat();
	int32_t _9 = o_wronly();
	int32_t _10 = _8 | _9;
	int32_t _11 = o_trunc();
	flags3 = _10 | _11;
	
	int32_t fd4;
	char* _12 = path;
	int32_t _13 = flags3;
	uint32_t _14 = permission2;
	fd4 = open(_12, _13, _14);
	
	int32_t _15 = fd4;
	int32_t _16 = -1;
	uint8_t _17 = _op_equal_equal_2(_15, _16);
	if (_17) {
		struct ctx* _18 = ctx;
		struct arr_0 _19 = (struct arr_0) {31, constantarr_0_60};
		char* _20 = path;
		struct arr_0 _21 = to_str_1(_20);
		struct arr_0 _22 = _op_plus_0(_18, _19, _21);
		print(_22);
		struct ctx* _23 = ctx;
		struct arr_0 _24 = (struct arr_0) {7, constantarr_0_61};
		struct ctx* _25 = ctx;
		int32_t _26 = errno;
		struct arr_0 _27 = to_str_2(_25, _26);
		struct arr_0 _28 = _op_plus_0(_23, _24, _27);
		print(_28);
		struct ctx* _29 = ctx;
		struct arr_0 _30 = (struct arr_0) {7, constantarr_0_62};
		struct ctx* _31 = ctx;
		int32_t _32 = flags3;
		struct arr_0 _33 = to_str_2(_31, _32);
		struct arr_0 _34 = _op_plus_0(_29, _30, _33);
		print(_34);
		struct ctx* _35 = ctx;
		struct arr_0 _36 = (struct arr_0) {12, constantarr_0_63};
		struct ctx* _37 = ctx;
		uint32_t _38 = permission2;
		struct arr_0 _39 = to_str_5(_37, _38);
		struct arr_0 _40 = _op_plus_0(_35, _36, _39);
		print(_40);
		return todo_0();
	} else {
		int64_t wrote_bytes5;
		int32_t _41 = fd4;
		struct arr_0 _42 = content;
		char* _43 = _42.data;
		uint8_t* _44 = (uint8_t*) _43;
		struct arr_0 _45 = content;
		uint64_t _46 = _45.size;
		wrote_bytes5 = write(_41, _44, _46);
		
		int64_t _47 = wrote_bytes5;
		struct ctx* _48 = ctx;
		struct arr_0 _49 = content;
		uint64_t _50 = _49.size;
		int64_t _51 = to_int(_48, _50);
		uint8_t _52 = _op_bang_equal_0(_47, _51);
		if (_52) {
			int64_t _53 = wrote_bytes5;
			int64_t _54 = -1;
			uint8_t _55 = _op_equal_equal_1(_53, _54);
			if (_55) {
				todo_0();
			} else {
				todo_0();
			}
		} else {
			(struct void_) {};
		}
		int32_t err6;
		int32_t _56 = fd4;
		err6 = close(_56);
		
		int32_t _57 = err6;
		int32_t _58 = 0;
		uint8_t _59 = _op_bang_equal_2(_57, _58);
		if (_59) {
			return todo_0();
		} else {
			return (struct void_) {};
		}
	}
}
/* bit-shift-left nat32(a nat32, b nat32) */
uint32_t bit_shift_left(uint32_t a, uint32_t b) {
	uint32_t _0 = b;
	uint32_t _1 = 32u;
	uint8_t _2 = _op_less_4(_0, _1);
	if (_2) {
		uint32_t _3 = a;
		uint64_t _4 = (uint64_t) _3;
		uint32_t _5 = b;
		uint64_t _6 = (uint64_t) _5;
		uint64_t _7 = _4 << _6;
		return (uint32_t) _7;
	} else {
		return 0u;
	}
}
/* <<nat32> bool(a nat32, b nat32) */
uint8_t _op_less_4(uint32_t a, uint32_t b) {
	uint32_t _0 = a;
	uint32_t _1 = b;
	struct comparison _2 = compare_518(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		case 2: {
			return 0;
		}
		default:
			return (assert(0),0);
	}
}
/* o-creat int32() */
int32_t o_creat(void) {
	return 64;
}
/* o-wronly int32() */
int32_t o_wronly(void) {
	return 1;
}
/* o-trunc int32() */
int32_t o_trunc(void) {
	return 512;
}
/* to-str arr<char>(n nat32) */
struct arr_0 to_str_5(struct ctx* ctx, uint32_t n) {
	struct ctx* _0 = ctx;
	uint32_t _1 = n;
	uint64_t _2 = (uint64_t) _1;
	return to_str_4(_0, _2);
}
/* to-int int(n nat) */
int64_t to_int(struct ctx* ctx, uint64_t n) {
	struct ctx* _0 = ctx;
	uint64_t _1 = n;
	struct ctx* _2 = ctx;
	int64_t _3 = max_int();
	uint64_t _4 = to_nat_0(_2, _3);
	uint8_t _5 = _op_less_0(_1, _4);
	assert_0(_0, _5);
	uint64_t _6 = n;
	return (int64_t) _6;
}
/* max-int int() */
int64_t max_int(void) {
	return 9223372036854775807;
}
/* remove-colors arr<char>(s arr<char>) */
struct arr_0 remove_colors(struct ctx* ctx, struct arr_0 s) {
	struct mut_list_5* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_3(_0);
	
	struct ctx* _1 = ctx;
	struct arr_0 _2 = s;
	struct mut_list_5* _3 = res0;
	remove_colors_recur(_1, _2, _3);
	struct mut_list_5* _4 = res0;
	return move_to_arr_4(_4);
}
/* remove-colors-recur void(s arr<char>, out mut-list<char>) */
struct void_ remove_colors_recur(struct ctx* ctx, struct arr_0 s, struct mut_list_5* out) {
	top:;
	struct arr_0 _0 = s;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		return (struct void_) {};
	} else {
		struct ctx* _2 = ctx;
		struct arr_0 _3 = s;
		char _4 = first_0(_2, _3);
		char _5 = 27u;
		uint8_t _6 = _op_equal_equal_3(_4, _5);
		if (_6) {
			struct ctx* _7 = ctx;
			struct ctx* _8 = ctx;
			struct arr_0 _9 = s;
			struct arr_0 _10 = tail_1(_8, _9);
			struct mut_list_5* _11 = out;
			return remove_colors_recur_2(_7, _10, _11);
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_5* _13 = out;
			struct ctx* _14 = ctx;
			struct arr_0 _15 = s;
			char _16 = first_0(_14, _15);
			push_4(_12, _13, _16);
			struct ctx* _17 = ctx;
			struct arr_0 _18 = s;
			struct arr_0 _19 = tail_1(_17, _18);
			struct mut_list_5* _20 = out;
			s = _19;
			out = _20;
			goto top;
		}
	}
}
/* remove-colors-recur-2 void(s arr<char>, out mut-list<char>) */
struct void_ remove_colors_recur_2(struct ctx* ctx, struct arr_0 s, struct mut_list_5* out) {
	top:;
	struct arr_0 _0 = s;
	uint8_t _1 = empty__q_0(_0);
	if (_1) {
		return (struct void_) {};
	} else {
		struct ctx* _2 = ctx;
		struct arr_0 _3 = s;
		char _4 = first_0(_2, _3);
		char _5 = 109u;
		uint8_t _6 = _op_equal_equal_3(_4, _5);
		if (_6) {
			struct ctx* _7 = ctx;
			struct ctx* _8 = ctx;
			struct arr_0 _9 = s;
			struct arr_0 _10 = tail_1(_8, _9);
			struct mut_list_5* _11 = out;
			return remove_colors_recur(_7, _10, _11);
		} else {
			struct ctx* _12 = ctx;
			struct arr_0 _13 = s;
			struct arr_0 _14 = tail_1(_12, _13);
			struct mut_list_5* _15 = out;
			s = _14;
			out = _15;
			goto top;
		}
	}
}
/* push<char> void(a mut-list<char>, value char) */
struct void_ push_4(struct ctx* ctx, struct mut_list_5* a, char value) {
	struct mut_list_5* _0 = a;
	uint64_t _1 = _0->size;
	struct mut_list_5* _2 = a;
	uint64_t _3 = capacity_4(_2);
	uint8_t _4 = _op_equal_equal_0(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct mut_list_5* _6 = a;
		struct mut_list_5* _7 = a;
		uint64_t _8 = _7->size;
		uint64_t _9 = 0u;
		uint8_t _10 = _op_equal_equal_0(_8, _9);uint64_t _11;
		
		if (_10) {
			_11 = 4u;
		} else {
			struct ctx* _12 = ctx;
			struct mut_list_5* _13 = a;
			uint64_t _14 = _13->size;
			uint64_t _15 = 2u;
			_11 = _op_times_0(_12, _14, _15);
		}
		increase_capacity_to_3(_5, _6, _11);
	} else {
		(struct void_) {};
	}
	struct ctx* _16 = ctx;
	struct mut_list_5* _17 = a;
	struct ctx* _18 = ctx;
	struct ctx* _19 = ctx;
	struct mut_list_5* _20 = a;
	uint64_t _21 = _20->size;
	uint64_t _22 = incr_3(_19, _21);
	uint64_t _23 = round_up_to_power_of_two(_18, _22);
	ensure_capacity_3(_16, _17, _23);
	struct ctx* _24 = ctx;
	struct mut_list_5* _25 = a;
	uint64_t _26 = _25->size;
	struct mut_list_5* _27 = a;
	uint64_t _28 = capacity_4(_27);
	uint8_t _29 = _op_less_0(_26, _28);
	assert_0(_24, _29);
	struct mut_list_5* _30 = a;
	char* _31 = data_11(_30);
	struct mut_list_5* _32 = a;
	uint64_t _33 = _32->size;
	char* _34 = _31 + _33;
	char _35 = value;
	*_34 = _35;
	struct mut_list_5* _36 = a;
	struct ctx* _37 = ctx;
	struct mut_list_5* _38 = a;
	uint64_t _39 = _38->size;
	uint64_t _40 = incr_3(_37, _39);
	return (_36->size = _40, (struct void_) {});
}
/* run-single-noze-test.lambda0 opt<arr<failure>>(print-kind arr<char>) */
struct opt_11 run_single_noze_test__lambda0(struct ctx* ctx, struct run_single_noze_test__lambda0* _closure, struct arr_0 print_kind) {
	struct run_single_noze_test__lambda0* _0 = _closure;
	struct test_options _1 = _0->options;
	uint8_t _2 = _1.print_tests__q;
	if (_2) {
		struct ctx* _3 = ctx;
		struct ctx* _4 = ctx;
		struct ctx* _5 = ctx;
		struct arr_0 _6 = (struct arr_0) {11, constantarr_0_39};
		struct arr_0 _7 = print_kind;
		struct arr_0 _8 = _op_plus_0(_5, _6, _7);
		struct arr_0 _9 = (struct arr_0) {1, constantarr_0_40};
		struct arr_0 _10 = _op_plus_0(_4, _8, _9);
		struct run_single_noze_test__lambda0* _11 = _closure;
		struct arr_0 _12 = _11->path;
		struct arr_0 _13 = _op_plus_0(_3, _10, _12);
		print(_13);
	} else {
		(struct void_) {};
	}
	struct print_test_result* res0;
	struct ctx* _14 = ctx;
	struct arr_0 _15 = print_kind;
	struct run_single_noze_test__lambda0* _16 = _closure;
	struct arr_0 _17 = _16->path_to_noze;
	struct run_single_noze_test__lambda0* _18 = _closure;
	struct dict_1* _19 = _18->env;
	struct run_single_noze_test__lambda0* _20 = _closure;
	struct arr_0 _21 = _20->path;
	struct run_single_noze_test__lambda0* _22 = _closure;
	struct test_options _23 = _22->options;
	uint8_t _24 = _23.overwrite_output__q;
	res0 = run_print_test(_14, _15, _17, _19, _21, _24);
	
	struct print_test_result* _25 = res0;
	uint8_t _26 = _25->should_stop__q;
	if (_26) {
		struct print_test_result* _27 = res0;
		struct arr_7 _28 = _27->failures;
		struct some_11 _29 = (struct some_11) {_28};
		return (struct opt_11) {1, .as1 = _29};
	} else {
		struct none _30 = (struct none) {};
		return (struct opt_11) {0, .as0 = _30};
	}
}
/* run-single-runnable-test arr<failure>(path-to-noze arr<char>, env dict<arr<char>, arr<char>>, path arr<char>, interpret? bool, overwrite-output? bool) */
struct arr_7 run_single_runnable_test(struct ctx* ctx, struct arr_0 path_to_noze, struct dict_1* env, struct arr_0 path, uint8_t interpret__q, uint8_t overwrite_output__q) {
	struct arr_1 args0;
	uint8_t _0 = interpret__q;
	if (_0) {
		struct arr_0* temp0;
		struct ctx* _1 = ctx;
		uint64_t _2 = sizeof(struct arr_0);
		uint64_t _3 = 3u;
		uint64_t _4 = _2 * _3;
		uint8_t* _5 = alloc(_1, _4);
		temp0 = (struct arr_0*) _5;
		
		struct arr_0* _6 = temp0;
		uint64_t _7 = 0u;
		struct arr_0* _8 = _6 + _7;
		struct arr_0 _9 = (struct arr_0) {3, constantarr_0_69};
		*_8 = _9;
		struct arr_0* _10 = temp0;
		uint64_t _11 = 1u;
		struct arr_0* _12 = _10 + _11;
		struct arr_0 _13 = path;
		*_12 = _13;
		struct arr_0* _14 = temp0;
		uint64_t _15 = 2u;
		struct arr_0* _16 = _14 + _15;
		struct arr_0 _17 = (struct arr_0) {11, constantarr_0_70};
		*_16 = _17;
		uint64_t _18 = 3u;
		struct arr_0* _19 = temp0;
		args0 = (struct arr_1) {_18, _19};
	} else {
		struct arr_0* temp1;
		struct ctx* _20 = ctx;
		uint64_t _21 = sizeof(struct arr_0);
		uint64_t _22 = 2u;
		uint64_t _23 = _21 * _22;
		uint8_t* _24 = alloc(_20, _23);
		temp1 = (struct arr_0*) _24;
		
		struct arr_0* _25 = temp1;
		uint64_t _26 = 0u;
		struct arr_0* _27 = _25 + _26;
		struct arr_0 _28 = (struct arr_0) {3, constantarr_0_69};
		*_27 = _28;
		struct arr_0* _29 = temp1;
		uint64_t _30 = 1u;
		struct arr_0* _31 = _29 + _30;
		struct arr_0 _32 = path;
		*_31 = _32;
		uint64_t _33 = 2u;
		struct arr_0* _34 = temp1;
		args0 = (struct arr_1) {_33, _34};
	}
	
	struct process_result* res1;
	struct ctx* _35 = ctx;
	struct arr_0 _36 = path_to_noze;
	struct arr_1 _37 = args0;
	struct dict_1* _38 = env;
	res1 = spawn_and_wait_result_0(_35, _36, _37, _38);
	
	struct process_result* _39 = res1;
	int32_t _40 = _39->exit_code;
	int32_t _41 = 0;
	uint8_t _42 = _op_equal_equal_2(_40, _41);uint8_t _43;
	
	if (_42) {
		struct process_result* _44 = res1;
		struct arr_0 _45 = _44->stderr;
		struct arr_0 _46 = (struct arr_0) {0u, NULL};
		_43 = _op_equal_equal_4(_45, _46);
	} else {
		_43 = 0;
	}
	if (_43) {
		struct ctx* _47 = ctx;
		struct arr_0 _48 = path;
		struct ctx* _49 = ctx;
		struct arr_0 _50 = path;
		struct arr_0 _51 = (struct arr_0) {7, constantarr_0_71};
		struct arr_0 _52 = _op_plus_0(_49, _50, _51);
		struct process_result* _53 = res1;
		struct arr_0 _54 = _53->stdout;
		uint8_t _55 = overwrite_output__q;
		return handle_output(_47, _48, _52, _54, _55);
	} else {
		struct arr_0 message2;
		struct ctx* _56 = ctx;
		struct ctx* _57 = ctx;
		struct ctx* _58 = ctx;
		struct ctx* _59 = ctx;
		struct ctx* _60 = ctx;
		struct arr_0 _61 = (struct arr_0) {8, constantarr_0_72};
		struct ctx* _62 = ctx;
		struct process_result* _63 = res1;
		int32_t _64 = _63->exit_code;
		struct arr_0 _65 = to_str_2(_62, _64);
		struct arr_0 _66 = _op_plus_0(_60, _61, _65);
		struct arr_0 _67 = (struct arr_0) {9, constantarr_0_73};
		struct arr_0 _68 = _op_plus_0(_59, _66, _67);
		struct process_result* _69 = res1;
		struct arr_0 _70 = _69->stdout;
		struct arr_0 _71 = _op_plus_0(_58, _68, _70);
		struct arr_0 _72 = (struct arr_0) {8, constantarr_0_74};
		struct arr_0 _73 = _op_plus_0(_57, _71, _72);
		struct process_result* _74 = res1;
		struct arr_0 _75 = _74->stderr;
		message2 = _op_plus_0(_56, _73, _75);
		
		struct failure** temp2;
		struct ctx* _76 = ctx;
		uint64_t _77 = sizeof(struct failure*);
		uint64_t _78 = 1u;
		uint64_t _79 = _77 * _78;
		uint8_t* _80 = alloc(_76, _79);
		temp2 = (struct failure**) _80;
		
		struct failure** _81 = temp2;
		uint64_t _82 = 0u;
		struct failure** _83 = _81 + _82;
		struct failure* temp3;
		struct ctx* _84 = ctx;
		uint64_t _85 = sizeof(struct failure);
		uint8_t* _86 = alloc(_84, _85);
		temp3 = (struct failure*) _86;
		
		struct failure* _87 = temp3;
		struct arr_0 _88 = path;
		struct arr_0 _89 = message2;
		struct failure _90 = (struct failure) {_88, _89};
		*_87 = _90;
		struct failure* _91 = temp3;
		*_83 = _91;
		uint64_t _92 = 1u;
		struct failure** _93 = temp2;
		return (struct arr_7) {_92, _93};
	}
}
/* run-noze-tests.lambda0 arr<failure>(test arr<char>) */
struct arr_7 run_noze_tests__lambda0(struct ctx* ctx, struct run_noze_tests__lambda0* _closure, struct arr_0 test) {
	struct ctx* _0 = ctx;
	struct run_noze_tests__lambda0* _1 = _closure;
	struct arr_0 _2 = _1->path_to_noze;
	struct run_noze_tests__lambda0* _3 = _closure;
	struct dict_1* _4 = _3->env;
	struct arr_0 _5 = test;
	struct run_noze_tests__lambda0* _6 = _closure;
	struct test_options _7 = _6->options;
	return run_single_noze_test(_0, _2, _4, _5, _7);
}
/* has?<failure> bool(a arr<failure>) */
uint8_t has__q_7(struct arr_7 a) {
	struct arr_7 _0 = a;
	uint8_t _1 = empty__q_10(_0);
	return !_1;
}
/* do-test.lambda0.lambda0 result<arr<char>, arr<failure>>() */
struct result_2 do_test__lambda0__lambda0(struct ctx* ctx, struct do_test__lambda0__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct do_test__lambda0__lambda0* _2 = _closure;
	struct arr_0 _3 = _2->test_path;
	struct arr_0 _4 = (struct arr_0) {8, constantarr_0_79};
	struct arr_0 _5 = child_path(_1, _3, _4);
	struct do_test__lambda0__lambda0* _6 = _closure;
	struct arr_0 _7 = _6->noze_exe;
	struct do_test__lambda0__lambda0* _8 = _closure;
	struct dict_1* _9 = _8->env;
	struct do_test__lambda0__lambda0* _10 = _closure;
	struct test_options _11 = _10->options;
	return run_noze_tests(_0, _5, _7, _9, _11);
}
/* do-test.lambda0 result<arr<char>, arr<failure>>() */
struct result_2 do_test__lambda0(struct ctx* ctx, struct do_test__lambda0* _closure) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct ctx* _2 = ctx;
	struct do_test__lambda0* _3 = _closure;
	struct arr_0 _4 = _3->test_path;
	struct arr_0 _5 = (struct arr_0) {14, constantarr_0_78};
	struct arr_0 _6 = child_path(_2, _4, _5);
	struct do_test__lambda0* _7 = _closure;
	struct arr_0 _8 = _7->noze_exe;
	struct do_test__lambda0* _9 = _closure;
	struct dict_1* _10 = _9->env;
	struct do_test__lambda0* _11 = _closure;
	struct test_options _12 = _11->options;
	struct result_2 _13 = run_noze_tests(_1, _6, _8, _10, _12);
	struct do_test__lambda0__lambda0* temp0;
	struct ctx* _14 = ctx;
	uint64_t _15 = sizeof(struct do_test__lambda0__lambda0);
	uint8_t* _16 = alloc(_14, _15);
	temp0 = (struct do_test__lambda0__lambda0*) _16;
	
	struct do_test__lambda0__lambda0* _17 = temp0;
	struct do_test__lambda0* _18 = _closure;
	struct arr_0 _19 = _18->test_path;
	struct do_test__lambda0* _20 = _closure;
	struct arr_0 _21 = _20->noze_exe;
	struct do_test__lambda0* _22 = _closure;
	struct dict_1* _23 = _22->env;
	struct do_test__lambda0* _24 = _closure;
	struct test_options _25 = _24->options;
	struct do_test__lambda0__lambda0 _26 = (struct do_test__lambda0__lambda0) {_19, _21, _23, _25};
	*_17 = _26;
	struct do_test__lambda0__lambda0* _27 = temp0;
	struct fun0 _28 = (struct fun0) {0, .as0 = _27};
	return first_failures(_0, _13, _28);
}
/* lint result<arr<char>, arr<failure>>(path arr<char>, options test-options) */
struct result_2 lint(struct ctx* ctx, struct arr_0 path, struct test_options options) {
	struct arr_1 files0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	files0 = list_lintable_files(_0, _1);
	
	struct arr_7 failures1;
	struct ctx* _2 = ctx;
	struct arr_1 _3 = files0;
	struct test_options _4 = options;
	uint64_t _5 = _4.max_failures;
	struct lint__lambda0* temp0;
	struct ctx* _6 = ctx;
	uint64_t _7 = sizeof(struct lint__lambda0);
	uint8_t* _8 = alloc(_6, _7);
	temp0 = (struct lint__lambda0*) _8;
	
	struct lint__lambda0* _9 = temp0;
	struct test_options _10 = options;
	struct lint__lambda0 _11 = (struct lint__lambda0) {_10};
	*_9 = _11;
	struct lint__lambda0* _12 = temp0;
	struct fun_act1_11 _13 = (struct fun_act1_11) {1, .as1 = _12};
	failures1 = flat_map_with_max_size(_2, _3, _5, _13);
	
	struct arr_7 _14 = failures1;
	uint8_t _15 = has__q_7(_14);
	if (_15) {
		struct arr_7 _16 = failures1;
		struct err_1 _17 = (struct err_1) {_16};
		return (struct result_2) {1, .as1 = _17};
	} else {
		struct ctx* _18 = ctx;
		struct ctx* _19 = ctx;
		struct arr_0 _20 = (struct arr_0) {7, constantarr_0_101};
		struct ctx* _21 = ctx;
		struct arr_1 _22 = files0;
		uint64_t _23 = _22.size;
		struct arr_0 _24 = to_str_4(_21, _23);
		struct arr_0 _25 = _op_plus_0(_19, _20, _24);
		struct arr_0 _26 = (struct arr_0) {6, constantarr_0_102};
		struct arr_0 _27 = _op_plus_0(_18, _25, _26);
		struct ok_2 _28 = (struct ok_2) {_27};
		return (struct result_2) {0, .as0 = _28};
	}
}
/* list-lintable-files arr<arr<char>>(path arr<char>) */
struct arr_1 list_lintable_files(struct ctx* ctx, struct arr_0 path) {
	struct mut_list_1* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_0(_0);
	
	struct ctx* _1 = ctx;
	struct arr_0 _2 = path;
	struct void_ _3 = (struct void_) {};
	struct fun_act1_6 _4 = (struct fun_act1_6) {6, .as6 = _3};
	struct list_lintable_files__lambda1* temp0;
	struct ctx* _5 = ctx;
	uint64_t _6 = sizeof(struct list_lintable_files__lambda1);
	uint8_t* _7 = alloc(_5, _6);
	temp0 = (struct list_lintable_files__lambda1*) _7;
	
	struct list_lintable_files__lambda1* _8 = temp0;
	struct mut_list_1* _9 = res0;
	struct list_lintable_files__lambda1 _10 = (struct list_lintable_files__lambda1) {_9};
	*_8 = _10;
	struct list_lintable_files__lambda1* _11 = temp0;
	struct fun_act1_10 _12 = (struct fun_act1_10) {3, .as3 = _11};
	each_child_recursive(_1, _2, _4, _12);
	struct mut_list_1* _13 = res0;
	return move_to_arr_0(_13);
}
/* excluded-from-lint? bool(name arr<char>) */
uint8_t excluded_from_lint__q(struct ctx* ctx, struct arr_0 name) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = name;
	char _2 = first_0(_0, _1);
	char _3 = 46u;
	uint8_t _4 = _op_equal_equal_3(_2, _3);
	if (_4) {
		return 1;
	} else {
		struct arr_1 _5 = (struct arr_1) {4, constantarr_1_3};
		struct arr_0 _6 = name;
		uint8_t _7 = contains__q_2(_5, _6);
		if (_7) {
			return 1;
		} else {
			struct ctx* _8 = ctx;
			struct arr_1 _9 = (struct arr_1) {5, constantarr_1_2};
			struct excluded_from_lint__q__lambda0* temp0;
			struct ctx* _10 = ctx;
			uint64_t _11 = sizeof(struct excluded_from_lint__q__lambda0);
			uint8_t* _12 = alloc(_10, _11);
			temp0 = (struct excluded_from_lint__q__lambda0*) _12;
			
			struct excluded_from_lint__q__lambda0* _13 = temp0;
			struct arr_0 _14 = name;
			struct excluded_from_lint__q__lambda0 _15 = (struct excluded_from_lint__q__lambda0) {_14};
			*_13 = _15;
			struct excluded_from_lint__q__lambda0* _16 = temp0;
			struct fun_act1_6 _17 = (struct fun_act1_6) {5, .as5 = _16};
			return some__q(_8, _9, _17);
		}
	}
}
/* contains?<arr<char>> bool(a arr<arr<char>>, value arr<char>) */
uint8_t contains__q_2(struct arr_1 a, struct arr_0 value) {
	struct arr_1 _0 = a;
	struct arr_0 _1 = value;
	uint64_t _2 = 0u;
	return contains_recur__q_1(_0, _1, _2);
}
/* contains-recur?<?t> bool(a arr<arr<char>>, value arr<char>, i nat) */
uint8_t contains_recur__q_1(struct arr_1 a, struct arr_0 value, uint64_t i) {
	top:;
	uint64_t _0 = i;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_equal_equal_0(_0, _2);
	if (_3) {
		return 0;
	} else {
		struct arr_1 _4 = a;
		uint64_t _5 = i;
		struct arr_0 _6 = noctx_at_4(_4, _5);
		struct arr_0 _7 = value;
		uint8_t _8 = _op_equal_equal_4(_6, _7);
		if (_8) {
			return 1;
		} else {
			struct arr_1 _9 = a;
			struct arr_0 _10 = value;
			uint64_t _11 = i;
			uint64_t _12 = noctx_incr(_11);
			a = _9;
			value = _10;
			i = _12;
			goto top;
		}
	}
}
/* some?<arr<char>> bool(a arr<arr<char>>, pred fun-act1<bool, arr<char>>) */
uint8_t some__q(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 pred) {
	top:;
	struct arr_1 _0 = a;
	uint8_t _1 = empty__q_5(_0);
	uint8_t _2 = !_1;
	if (_2) {
		struct ctx* _3 = ctx;
		struct fun_act1_6 _4 = pred;
		struct ctx* _5 = ctx;
		struct arr_1 _6 = a;
		struct arr_0 _7 = first_1(_5, _6);
		uint8_t _8 = call_8(_3, _4, _7);
		if (_8) {
			return 1;
		} else {
			struct ctx* _9 = ctx;
			struct arr_1 _10 = a;
			struct arr_1 _11 = tail_2(_9, _10);
			struct fun_act1_6 _12 = pred;
			a = _11;
			pred = _12;
			goto top;
		}
	} else {
		return 0;
	}
}
/* ends-with?<char> bool(a arr<char>, end arr<char>) */
uint8_t ends_with__q(struct ctx* ctx, struct arr_0 a, struct arr_0 end) {
	struct arr_0 _0 = a;
	uint64_t _1 = _0.size;
	struct arr_0 _2 = end;
	uint64_t _3 = _2.size;
	uint8_t _4 = _op_greater_equal(_1, _3);
	if (_4) {
		struct ctx* _5 = ctx;
		struct ctx* _6 = ctx;
		struct arr_0 _7 = a;
		struct ctx* _8 = ctx;
		struct arr_0 _9 = a;
		uint64_t _10 = _9.size;
		struct arr_0 _11 = end;
		uint64_t _12 = _11.size;
		uint64_t _13 = _op_minus_2(_8, _10, _12);
		struct arr_0 _14 = end;
		uint64_t _15 = _14.size;
		struct arr_0 _16 = slice_1(_6, _7, _13, _15);
		struct arr_0 _17 = end;
		return arr_eq__q(_5, _16, _17);
	} else {
		return 0;
	}
}
/* excluded-from-lint?.lambda0 bool(it arr<char>) */
uint8_t excluded_from_lint__q__lambda0(struct ctx* ctx, struct excluded_from_lint__q__lambda0* _closure, struct arr_0 it) {
	struct ctx* _0 = ctx;
	struct excluded_from_lint__q__lambda0* _1 = _closure;
	struct arr_0 _2 = _1->name;
	struct arr_0 _3 = it;
	return ends_with__q(_0, _2, _3);
}
/* list-lintable-files.lambda0 bool(it arr<char>) */
uint8_t list_lintable_files__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_0 it) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = it;
	uint8_t _2 = excluded_from_lint__q(_0, _1);
	return !_2;
}
/* ignore-extension-of-name? bool(name arr<char>) */
uint8_t ignore_extension_of_name__q(struct ctx* ctx, struct arr_0 name) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = name;
	struct opt_8 _2 = get_extension(_0, _1);
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			struct some_8 s0 = _2.as1;
			
			struct ctx* _3 = ctx;
			struct some_8 _4 = s0;
			struct arr_0 _5 = _4.value;
			return ignore_extension__q(_3, _5);
		}
		default:
			return (assert(0),0);
	}
}
/* ignore-extension? bool(ext arr<char>) */
uint8_t ignore_extension__q(struct ctx* ctx, struct arr_0 ext) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = ignored_extensions(_0);
	struct arr_0 _2 = ext;
	return contains__q_2(_1, _2);
}
/* ignored-extensions arr<arr<char>>() */
struct arr_1 ignored_extensions(struct ctx* ctx) {
	return (struct arr_1) {6, constantarr_1_4};
}
/* list-lintable-files.lambda1 void(child arr<char>) */
struct void_ list_lintable_files__lambda1(struct ctx* ctx, struct list_lintable_files__lambda1* _closure, struct arr_0 child) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = child;
	struct arr_0 _3 = base_name(_1, _2);
	uint8_t _4 = ignore_extension_of_name__q(_0, _3);
	uint8_t _5 = !_4;
	if (_5) {
		struct ctx* _6 = ctx;
		struct list_lintable_files__lambda1* _7 = _closure;
		struct mut_list_1* _8 = _7->res;
		struct arr_0 _9 = child;
		return push_0(_6, _8, _9);
	} else {
		return (struct void_) {};
	}
}
/* lint-file arr<failure>(path arr<char>) */
struct arr_7 lint_file(struct ctx* ctx, struct arr_0 path) {
	struct arr_0 text0;
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	text0 = read_file(_0, _1);
	
	struct mut_list_4* res1;
	struct ctx* _2 = ctx;
	res1 = new_mut_list_2(_2);
	
	uint8_t err_file__q2;
	struct ctx* _3 = ctx;
	struct ctx* _4 = ctx;
	struct arr_0 _5 = path;
	struct opt_8 _6 = get_extension(_4, _5);
	struct arr_0 _7 = force_0(_3, _6);
	struct arr_0 _8 = (struct arr_0) {3, constantarr_0_95};
	err_file__q2 = _op_equal_equal_4(_7, _8);
	
	struct ctx* _9 = ctx;
	struct ctx* _10 = ctx;
	struct arr_0 _11 = text0;
	struct arr_1 _12 = lines(_10, _11);
	struct lint_file__lambda0* temp0;
	struct ctx* _13 = ctx;
	uint64_t _14 = sizeof(struct lint_file__lambda0);
	uint8_t* _15 = alloc(_13, _14);
	temp0 = (struct lint_file__lambda0*) _15;
	
	struct lint_file__lambda0* _16 = temp0;
	uint8_t _17 = err_file__q2;
	struct mut_list_4* _18 = res1;
	struct arr_0 _19 = path;
	struct lint_file__lambda0 _20 = (struct lint_file__lambda0) {_17, _18, _19};
	*_16 = _20;
	struct lint_file__lambda0* _21 = temp0;
	struct fun_act2_3 _22 = (struct fun_act2_3) {0, .as0 = _21};
	each_with_index_0(_9, _12, _22);
	struct mut_list_4* _23 = res1;
	return move_to_arr_3(_23);
}
/* read-file arr<char>(path arr<char>) */
struct arr_0 read_file(struct ctx* ctx, struct arr_0 path) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = path;
	struct opt_8 _2 = try_read_file_0(_0, _1);
	switch (_2.kind) {
		case 0: {
			struct ctx* _3 = ctx;
			struct arr_0 _4 = (struct arr_0) {21, constantarr_0_94};
			struct arr_0 _5 = path;
			struct arr_0 _6 = _op_plus_0(_3, _4, _5);
			print(_6);
			return (struct arr_0) {0u, NULL};
		}
		case 1: {
			struct some_8 s0 = _2.as1;
			
			struct some_8 _7 = s0;
			return _7.value;
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* each-with-index<arr<char>> void(a arr<arr<char>>, f fun-act2<void, arr<char>, nat>) */
struct void_ each_with_index_0(struct ctx* ctx, struct arr_1 a, struct fun_act2_3 f) {
	struct ctx* _0 = ctx;
	struct arr_1 _1 = a;
	struct fun_act2_3 _2 = f;
	uint64_t _3 = 0u;
	return each_with_index_recur_0(_0, _1, _2, _3);
}
/* each-with-index-recur<?t> void(a arr<arr<char>>, f fun-act2<void, arr<char>, nat>, n nat) */
struct void_ each_with_index_recur_0(struct ctx* ctx, struct arr_1 a, struct fun_act2_3 f, uint64_t n) {
	top:;
	uint64_t _0 = n;
	struct arr_1 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct fun_act2_3 _5 = f;
		struct ctx* _6 = ctx;
		struct arr_1 _7 = a;
		uint64_t _8 = n;
		struct arr_0 _9 = at_2(_6, _7, _8);
		uint64_t _10 = n;
		call_23(_4, _5, _9, _10);
		struct arr_1 _11 = a;
		struct fun_act2_3 _12 = f;
		struct ctx* _13 = ctx;
		uint64_t _14 = n;
		uint64_t _15 = incr_3(_13, _14);
		a = _11;
		f = _12;
		n = _15;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* call<void, ?t, nat> void(a fun-act2<void, arr<char>, nat>, p0 arr<char>, p1 nat) */
struct void_ call_23(struct ctx* ctx, struct fun_act2_3 a, struct arr_0 p0, uint64_t p1) {
	struct fun_act2_3 _0 = a;
	struct ctx* _1 = ctx;
	struct arr_0 _2 = p0;
	uint64_t _3 = p1;
	return call_w_ctx_768(_0, _1, _2, _3);
}
/* call-w-ctx<void, arr<char>, nat-64> (generated) (generated) */
struct void_ call_w_ctx_768(struct fun_act2_3 a, struct ctx* ctx, struct arr_0 p0, uint64_t p1) {
	struct fun_act2_3 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct lint_file__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct lint_file__lambda0* _2 = closure0;
			struct arr_0 _3 = p0;
			uint64_t _4 = p1;
			return lint_file__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* lines arr<arr<char>>(s arr<char>) */
struct arr_1 lines(struct ctx* ctx, struct arr_0 s) {
	struct mut_list_1* res0;
	struct ctx* _0 = ctx;
	res0 = new_mut_list_0(_0);
	
	struct cell_0* last_nl1;
	struct cell_0* temp0;
	struct ctx* _1 = ctx;
	uint64_t _2 = sizeof(struct cell_0);
	uint8_t* _3 = alloc(_1, _2);
	temp0 = (struct cell_0*) _3;
	
	struct cell_0* _4 = temp0;
	uint64_t _5 = 0u;
	struct cell_0 _6 = (struct cell_0) {_5};
	*_4 = _6;
	last_nl1 = temp0;
	
	struct ctx* _7 = ctx;
	struct arr_0 _8 = s;
	struct lines__lambda0* temp1;
	struct ctx* _9 = ctx;
	uint64_t _10 = sizeof(struct lines__lambda0);
	uint8_t* _11 = alloc(_9, _10);
	temp1 = (struct lines__lambda0*) _11;
	
	struct lines__lambda0* _12 = temp1;
	struct mut_list_1* _13 = res0;
	struct arr_0 _14 = s;
	struct cell_0* _15 = last_nl1;
	struct lines__lambda0 _16 = (struct lines__lambda0) {_13, _14, _15};
	*_12 = _16;
	struct lines__lambda0* _17 = temp1;
	struct fun_act2_4 _18 = (struct fun_act2_4) {0, .as0 = _17};
	each_with_index_1(_7, _8, _18);
	struct ctx* _19 = ctx;
	struct mut_list_1* _20 = res0;
	struct ctx* _21 = ctx;
	struct arr_0 _22 = s;
	struct cell_0* _23 = last_nl1;
	uint64_t _24 = get_7(_23);
	struct arr_0 _25 = s;
	uint64_t _26 = _25.size;
	struct arr_0 _27 = slice_from_to(_21, _22, _24, _26);
	push_0(_19, _20, _27);
	struct mut_list_1* _28 = res0;
	return move_to_arr_0(_28);
}
/* each-with-index<char> void(a arr<char>, f fun-act2<void, char, nat>) */
struct void_ each_with_index_1(struct ctx* ctx, struct arr_0 a, struct fun_act2_4 f) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct fun_act2_4 _2 = f;
	uint64_t _3 = 0u;
	return each_with_index_recur_1(_0, _1, _2, _3);
}
/* each-with-index-recur<?t> void(a arr<char>, f fun-act2<void, char, nat>, n nat) */
struct void_ each_with_index_recur_1(struct ctx* ctx, struct arr_0 a, struct fun_act2_4 f, uint64_t n) {
	top:;
	uint64_t _0 = n;
	struct arr_0 _1 = a;
	uint64_t _2 = _1.size;
	uint8_t _3 = _op_bang_equal_1(_0, _2);
	if (_3) {
		struct ctx* _4 = ctx;
		struct fun_act2_4 _5 = f;
		struct ctx* _6 = ctx;
		struct arr_0 _7 = a;
		uint64_t _8 = n;
		char _9 = at_3(_6, _7, _8);
		uint64_t _10 = n;
		call_24(_4, _5, _9, _10);
		struct arr_0 _11 = a;
		struct fun_act2_4 _12 = f;
		struct ctx* _13 = ctx;
		uint64_t _14 = n;
		uint64_t _15 = incr_3(_13, _14);
		a = _11;
		f = _12;
		n = _15;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* call<void, ?t, nat> void(a fun-act2<void, char, nat>, p0 char, p1 nat) */
struct void_ call_24(struct ctx* ctx, struct fun_act2_4 a, char p0, uint64_t p1) {
	struct fun_act2_4 _0 = a;
	struct ctx* _1 = ctx;
	char _2 = p0;
	uint64_t _3 = p1;
	return call_w_ctx_773(_0, _1, _2, _3);
}
/* call-w-ctx<void, char, nat-64> (generated) (generated) */
struct void_ call_w_ctx_773(struct fun_act2_4 a, struct ctx* ctx, char p0, uint64_t p1) {
	struct fun_act2_4 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct lines__lambda0* closure0 = _0.as0;
			
			struct ctx* _1 = ctx;
			struct lines__lambda0* _2 = closure0;
			char _3 = p0;
			uint64_t _4 = p1;
			return lines__lambda0(_1, _2, _3, _4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* slice-from-to<char> arr<char>(a arr<char>, begin nat, end nat) */
struct arr_0 slice_from_to(struct ctx* ctx, struct arr_0 a, uint64_t begin, uint64_t end) {
	struct ctx* _0 = ctx;
	uint64_t _1 = begin;
	uint64_t _2 = end;
	uint8_t _3 = _op_less_equal(_1, _2);
	assert_0(_0, _3);
	struct ctx* _4 = ctx;
	struct arr_0 _5 = a;
	uint64_t _6 = begin;
	struct ctx* _7 = ctx;
	uint64_t _8 = end;
	uint64_t _9 = begin;
	uint64_t _10 = _op_minus_2(_7, _8, _9);
	return slice_1(_4, _5, _6, _10);
}
/* swap<nat> nat(c cell<nat>, v nat) */
uint64_t swap_1(struct cell_0* c, uint64_t v) {
	uint64_t res0;
	struct cell_0* _0 = c;
	res0 = get_7(_0);
	
	struct cell_0* _1 = c;
	uint64_t _2 = v;
	set_1(_1, _2);
	return res0;
}
/* get<?t> nat(c cell<nat>) */
uint64_t get_7(struct cell_0* c) {
	struct cell_0* _0 = c;
	return _0->value;
}
/* set<?t> void(c cell<nat>, v nat) */
struct void_ set_1(struct cell_0* c, uint64_t v) {
	struct cell_0* _0 = c;
	uint64_t _1 = v;
	return (_0->value = _1, (struct void_) {});
}
/* lines.lambda0 void(c char, index nat) */
struct void_ lines__lambda0(struct ctx* ctx, struct lines__lambda0* _closure, char c, uint64_t index) {
	char _0 = c;
	char _1 = 10u;
	uint8_t _2 = _op_equal_equal_3(_0, _1);
	if (_2) {
		struct ctx* _3 = ctx;
		struct lines__lambda0* _4 = _closure;
		struct mut_list_1* _5 = _4->res;
		struct ctx* _6 = ctx;
		struct lines__lambda0* _7 = _closure;
		struct arr_0 _8 = _7->s;
		struct lines__lambda0* _9 = _closure;
		struct cell_0* _10 = _9->last_nl;
		struct ctx* _11 = ctx;
		uint64_t _12 = index;
		uint64_t _13 = incr_3(_11, _12);
		uint64_t _14 = swap_1(_10, _13);
		uint64_t _15 = index;
		struct arr_0 _16 = slice_from_to(_6, _8, _14, _15);
		return push_0(_3, _5, _16);
	} else {
		return (struct void_) {};
	}
}
/* contains-subsequence?<char> bool(a arr<char>, subseq arr<char>) */
uint8_t contains_subsequence__q(struct ctx* ctx, struct arr_0 a, struct arr_0 subseq) {
	struct ctx* _0 = ctx;
	struct arr_0 _1 = a;
	struct arr_0 _2 = subseq;
	uint8_t _3 = starts_with__q(_0, _1, _2);
	if (_3) {
		return 1;
	} else {
		struct arr_0 _4 = a;
		uint8_t _5 = has__q_8(_4);
		if (_5) {
			struct ctx* _6 = ctx;
			struct ctx* _7 = ctx;
			struct arr_0 _8 = a;
			struct arr_0 _9 = tail_1(_7, _8);
			struct arr_0 _10 = subseq;
			return starts_with__q(_6, _9, _10);
		} else {
			return 0;
		}
	}
}
/* has?<?t> bool(a arr<char>) */
uint8_t has__q_8(struct arr_0 a) {
	struct arr_0 _0 = a;
	uint8_t _1 = empty__q_0(_0);
	return !_1;
}
/* lstrip arr<char>(a arr<char>) */
struct arr_0 lstrip(struct ctx* ctx, struct arr_0 a) {
	top:;
	struct arr_0 _0 = a;
	uint8_t _1 = has__q_8(_0);uint8_t _2;
	
	if (_1) {
		struct ctx* _3 = ctx;
		struct arr_0 _4 = a;
		char _5 = first_0(_3, _4);
		char _6 = 32u;
		_2 = _op_equal_equal_3(_5, _6);
	} else {
		_2 = 0;
	}
	if (_2) {
		struct ctx* _7 = ctx;
		struct arr_0 _8 = a;
		struct arr_0 _9 = tail_1(_7, _8);
		a = _9;
		goto top;
	} else {
		return a;
	}
}
/* line-len nat(line arr<char>) */
uint64_t line_len(struct ctx* ctx, struct arr_0 line) {
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	struct ctx* _2 = ctx;
	struct arr_0 _3 = line;
	uint64_t _4 = n_tabs(_2, _3);
	struct ctx* _5 = ctx;
	struct ctx* _6 = ctx;
	uint64_t _7 = tab_size(_6);
	uint64_t _8 = 1u;
	uint64_t _9 = _op_minus_2(_5, _7, _8);
	uint64_t _10 = _op_times_0(_1, _4, _9);
	struct arr_0 _11 = line;
	uint64_t _12 = _11.size;
	return _op_plus_1(_0, _10, _12);
}
/* n-tabs nat(line arr<char>) */
uint64_t n_tabs(struct ctx* ctx, struct arr_0 line) {
	struct arr_0 _0 = line;
	uint8_t _1 = empty__q_0(_0);
	uint8_t _2 = !_1;uint8_t _3;
	
	if (_2) {
		struct ctx* _4 = ctx;
		struct arr_0 _5 = line;
		char _6 = first_0(_4, _5);
		char _7 = 9u;
		_3 = _op_equal_equal_3(_6, _7);
	} else {
		_3 = 0;
	}
	if (_3) {
		struct ctx* _8 = ctx;
		struct ctx* _9 = ctx;
		struct ctx* _10 = ctx;
		struct arr_0 _11 = line;
		struct arr_0 _12 = tail_1(_10, _11);
		uint64_t _13 = n_tabs(_9, _12);
		return incr_3(_8, _13);
	} else {
		return 0u;
	}
}
/* tab-size nat() */
uint64_t tab_size(struct ctx* ctx) {
	return 4u;
}
/* max-line-length nat() */
uint64_t max_line_length(struct ctx* ctx) {
	return 120u;
}
/* lint-file.lambda0 void(line arr<char>, line-num nat) */
struct void_ lint_file__lambda0(struct ctx* ctx, struct lint_file__lambda0* _closure, struct arr_0 line, uint64_t line_num) {
	struct arr_0 ln0;
	struct ctx* _0 = ctx;
	struct ctx* _1 = ctx;
	uint64_t _2 = line_num;
	uint64_t _3 = incr_3(_1, _2);
	ln0 = to_str_4(_0, _3);
	
	struct lint_file__lambda0* _4 = _closure;
	uint8_t _5 = _4->err_file__q;
	uint8_t _6 = !_5;uint8_t _7;
	
	if (_6) {
		struct ctx* _8 = ctx;
		struct ctx* _9 = ctx;
		struct arr_0 _10 = line;
		struct arr_0 _11 = lstrip(_9, _10);
		struct arr_0 _12 = (struct arr_0) {2, constantarr_0_96};
		_7 = contains_subsequence__q(_8, _11, _12);
	} else {
		_7 = 0;
	}
	if (_7) {
		struct arr_0 message1;
		struct ctx* _13 = ctx;
		struct ctx* _14 = ctx;
		struct arr_0 _15 = (struct arr_0) {5, constantarr_0_97};
		struct arr_0 _16 = ln0;
		struct arr_0 _17 = _op_plus_0(_14, _15, _16);
		struct arr_0 _18 = (struct arr_0) {24, constantarr_0_98};
		message1 = _op_plus_0(_13, _17, _18);
		
		struct ctx* _19 = ctx;
		struct lint_file__lambda0* _20 = _closure;
		struct mut_list_4* _21 = _20->res;
		struct failure* temp0;
		struct ctx* _22 = ctx;
		uint64_t _23 = sizeof(struct failure);
		uint8_t* _24 = alloc(_22, _23);
		temp0 = (struct failure*) _24;
		
		struct failure* _25 = temp0;
		struct lint_file__lambda0* _26 = _closure;
		struct arr_0 _27 = _26->path;
		struct arr_0 _28 = message1;
		struct failure _29 = (struct failure) {_27, _28};
		*_25 = _29;
		struct failure* _30 = temp0;
		push_2(_19, _21, _30);
	} else {
		(struct void_) {};
	}
	uint64_t width2;
	struct ctx* _31 = ctx;
	struct arr_0 _32 = line;
	width2 = line_len(_31, _32);
	
	uint64_t _33 = width2;
	struct ctx* _34 = ctx;
	uint64_t _35 = max_line_length(_34);
	uint8_t _36 = _op_greater(_33, _35);
	if (_36) {
		struct arr_0 message3;
		struct ctx* _37 = ctx;
		struct ctx* _38 = ctx;
		struct ctx* _39 = ctx;
		struct ctx* _40 = ctx;
		struct ctx* _41 = ctx;
		struct arr_0 _42 = (struct arr_0) {5, constantarr_0_97};
		struct arr_0 _43 = ln0;
		struct arr_0 _44 = _op_plus_0(_41, _42, _43);
		struct arr_0 _45 = (struct arr_0) {4, constantarr_0_99};
		struct arr_0 _46 = _op_plus_0(_40, _44, _45);
		struct ctx* _47 = ctx;
		uint64_t _48 = width2;
		struct arr_0 _49 = to_str_4(_47, _48);
		struct arr_0 _50 = _op_plus_0(_39, _46, _49);
		struct arr_0 _51 = (struct arr_0) {28, constantarr_0_100};
		struct arr_0 _52 = _op_plus_0(_38, _50, _51);
		struct ctx* _53 = ctx;
		struct ctx* _54 = ctx;
		uint64_t _55 = max_line_length(_54);
		struct arr_0 _56 = to_str_4(_53, _55);
		message3 = _op_plus_0(_37, _52, _56);
		
		struct ctx* _57 = ctx;
		struct lint_file__lambda0* _58 = _closure;
		struct mut_list_4* _59 = _58->res;
		struct failure* temp1;
		struct ctx* _60 = ctx;
		uint64_t _61 = sizeof(struct failure);
		uint8_t* _62 = alloc(_60, _61);
		temp1 = (struct failure*) _62;
		
		struct failure* _63 = temp1;
		struct lint_file__lambda0* _64 = _closure;
		struct arr_0 _65 = _64->path;
		struct arr_0 _66 = message3;
		struct failure _67 = (struct failure) {_65, _66};
		*_63 = _67;
		struct failure* _68 = temp1;
		return push_2(_57, _59, _68);
	} else {
		return (struct void_) {};
	}
}
/* lint.lambda0 arr<failure>(file arr<char>) */
struct arr_7 lint__lambda0(struct ctx* ctx, struct lint__lambda0* _closure, struct arr_0 file) {
	struct lint__lambda0* _0 = _closure;
	struct test_options _1 = _0->options;
	uint8_t _2 = _1.print_tests__q;
	if (_2) {
		struct ctx* _3 = ctx;
		struct arr_0 _4 = (struct arr_0) {5, constantarr_0_93};
		struct arr_0 _5 = file;
		struct arr_0 _6 = _op_plus_0(_3, _4, _5);
		print(_6);
	} else {
		(struct void_) {};
	}
	struct ctx* _7 = ctx;
	struct arr_0 _8 = file;
	return lint_file(_7, _8);
}
/* do-test.lambda1 result<arr<char>, arr<failure>>() */
struct result_2 do_test__lambda1(struct ctx* ctx, struct do_test__lambda1* _closure) {
	struct ctx* _0 = ctx;
	struct do_test__lambda1* _1 = _closure;
	struct arr_0 _2 = _1->noze_path;
	struct do_test__lambda1* _3 = _closure;
	struct test_options _4 = _3->options;
	return lint(_0, _2, _4);
}
/* print-failures int32(failures result<arr<char>, arr<failure>>, options test-options) */
int32_t print_failures(struct ctx* ctx, struct result_2 failures, struct test_options options) {
	struct result_2 _0 = failures;
	switch (_0.kind) {
		case 0: {
			struct ok_2 o0 = _0.as0;
			
			struct ok_2 _1 = o0;
			struct arr_0 _2 = _1.value;
			print(_2);
			return 0;
		}
		case 1: {
			struct err_1 e1 = _0.as1;
			
			struct ctx* _3 = ctx;
			struct err_1 _4 = e1;
			struct arr_7 _5 = _4.value;
			struct void_ _6 = (struct void_) {};
			struct fun_act1_12 _7 = (struct fun_act1_12) {1, .as1 = _6};
			each_2(_3, _5, _7);
			uint64_t n_failures2;
			struct err_1 _8 = e1;
			struct arr_7 _9 = _8.value;
			n_failures2 = _9.size;
			
			uint64_t _10 = n_failures2;
			struct test_options _11 = options;
			uint64_t _12 = _11.max_failures;
			uint8_t _13 = _op_equal_equal_0(_10, _12);struct arr_0 _14;
			
			if (_13) {
				struct ctx* _15 = ctx;
				struct ctx* _16 = ctx;
				struct arr_0 _17 = (struct arr_0) {15, constantarr_0_105};
				struct ctx* _18 = ctx;
				struct test_options _19 = options;
				uint64_t _20 = _19.max_failures;
				struct arr_0 _21 = to_str_4(_18, _20);
				struct arr_0 _22 = _op_plus_0(_16, _17, _21);
				struct arr_0 _23 = (struct arr_0) {9, constantarr_0_106};
				_14 = _op_plus_0(_15, _22, _23);
			} else {
				struct ctx* _24 = ctx;
				struct ctx* _25 = ctx;
				uint64_t _26 = n_failures2;
				struct arr_0 _27 = to_str_4(_25, _26);
				struct arr_0 _28 = (struct arr_0) {9, constantarr_0_106};
				_14 = _op_plus_0(_24, _27, _28);
			}
			print(_14);
			struct ctx* _29 = ctx;
			uint64_t _30 = n_failures2;
			return to_int32(_29, _30);
		}
		default:
			return (assert(0),0);
	}
}
/* print-failure void(failure failure) */
struct void_ print_failure(struct ctx* ctx, struct failure* failure) {
	struct ctx* _0 = ctx;
	print_bold(_0);
	struct failure* _1 = failure;
	struct arr_0 _2 = _1->path;
	print_no_newline(_2);
	struct ctx* _3 = ctx;
	print_reset(_3);
	struct arr_0 _4 = (struct arr_0) {1, constantarr_0_40};
	print_no_newline(_4);
	struct failure* _5 = failure;
	struct arr_0 _6 = _5->message;
	return print(_6);
}
/* print-bold void() */
struct void_ print_bold(struct ctx* ctx) {
	struct arr_0 _0 = (struct arr_0) {4, constantarr_0_103};
	return print_no_newline(_0);
}
/* print-reset void() */
struct void_ print_reset(struct ctx* ctx) {
	struct arr_0 _0 = (struct arr_0) {3, constantarr_0_104};
	return print_no_newline(_0);
}
/* print-failures.lambda0 void(it failure) */
struct void_ print_failures__lambda0(struct ctx* ctx, struct void_ _closure, struct failure* it) {
	struct ctx* _0 = ctx;
	struct failure* _1 = it;
	return print_failure(_0, _1);
}
/* to-int32 int32(n nat) */
int32_t to_int32(struct ctx* ctx, uint64_t n) {
	struct ctx* _0 = ctx;
	uint64_t _1 = n;
	struct ctx* _2 = ctx;
	int32_t _3 = max_int32();
	uint64_t _4 = to_nat_2(_2, _3);
	uint8_t _5 = _op_less_0(_1, _4);
	assert_0(_0, _5);
	uint64_t _6 = n;
	int64_t _7 = (int64_t) _6;
	return (int32_t) _7;
}
/* max-int32 int32() */
int32_t max_int32(void) {
	return 2147483647;
}
/* main (generated) (generated) */
int32_t main(int32_t argc, char** argv) {
	int32_t _0 = argc;
	char** _1 = argv;
	fun_ptr2 _2 = main_0;
	return rt_main(_0, _1, _2);
}
