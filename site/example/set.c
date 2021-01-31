#include <errno.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

struct void_ {};
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
struct exception;
struct arr_0 {
	uint64_t size;
	char* data;
};
struct backtrace;
struct arr_1 {
	uint64_t size;
	struct arr_0* data;
};
struct ok_0 {
	uint64_t value;
};
struct err;
struct none {
};
struct some_0 {
	struct fut_callback_node_0* value;
};
struct fut_state_resolved_0 {
	uint64_t value;
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
struct backtrace_arrs {
	uint8_t** code_ptrs;
	struct arr_0* code_names;
	uint8_t** fun_ptrs;
	struct arr_0* fun_names;
};
struct some_3 {
	struct backtrace_arrs* value;
};
struct some_4 {
	uint8_t** value;
};
struct some_5 {
	uint8_t* value;
};
struct some_6 {
	struct arr_0* value;
};
struct arrow {
	uint64_t from;
	uint64_t to;
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
struct some_7 {
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
struct then__lambda0;
struct forward_to__lambda0 {
	struct fut_0* to;
};
struct subscript_4__lambda0;
struct subscript_4__lambda0__lambda0;
struct subscript_4__lambda0__lambda1 {
	struct fut_0* res;
};
struct then2__lambda0;
struct subscript_9__lambda0;
struct subscript_9__lambda0__lambda0;
struct subscript_9__lambda0__lambda1 {
	struct fut_0* res;
};
struct add_first_task__lambda0;
struct map__lambda0;
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
struct some_8 {
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
struct set {
	struct void_ ignore;
	struct arr_1 values;
};
struct mut_list_1;
struct mut_arr_1 {
	struct void_ ignore;
	struct arr_1 inner;
};
struct unique__e__lambda0 {
	struct mut_list_1* res;
};
struct mut_arr_3__lambda0 {
	struct arr_1 a;
};
struct _concatEquals_1__lambda0 {
	struct mut_list_1* a;
};
struct mut_set {
	struct void_ ignore;
	struct mut_list_1* inner;
};
struct _concatEquals_2__lambda0 {
	struct mut_set a;
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
struct result_0;
struct fun_act1_0 {
	uint64_t kind;
	union {
		struct forward_to__lambda0* as0;
		struct void_ as1;
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
		struct subscript_4__lambda0__lambda0* as0;
		struct subscript_4__lambda0* as1;
		struct subscript_9__lambda0__lambda0* as2;
		struct subscript_9__lambda0* as3;
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
struct opt_4 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_4 as1;
	};
};
struct opt_5 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_5 as1;
	};
};
struct opt_6 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_6 as1;
	};
};
struct fun_act2 {
	uint64_t kind;
	union {
		struct void_ as0;
	};
};
struct fut_state_1;
struct result_1;
struct fun_act1_1 {
	uint64_t kind;
	union {
		struct then__lambda0* as0;
	};
};
struct opt_7 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_7 as1;
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
		struct subscript_4__lambda0__lambda1* as0;
		struct subscript_9__lambda0__lambda1* as1;
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
		struct map__lambda0* as0;
		struct mut_arr_3__lambda0* as1;
	};
};
struct choose_task_result;
struct task_or_gc;
struct opt_8 {
	uint64_t kind;
	union {
		struct none as0;
		struct some_8 as1;
	};
};
struct choose_task_in_island_result;
struct pop_task_result;
struct fun_act1_6 {
	uint64_t kind;
	union {
		struct unique__e__lambda0* as0;
		struct _concatEquals_1__lambda0* as1;
		struct _concatEquals_2__lambda0* as2;
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
struct exception;
struct backtrace {
	struct arr_1 return_stack;
};
struct err;
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
	struct void_ ignore;
	struct arr_2 inner;
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
struct exception_ctx;
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
	struct opt_7 head;
};
struct fut_callback_node_1 {
	struct fun_act1_1 cb;
	struct opt_7 next_node;
};
struct fun_ref0 {
	struct island_and_exclusion island_and_exclusion;
	struct fun_act0_1 fun;
};
struct fun_ref1 {
	struct island_and_exclusion island_and_exclusion;
	struct fun_act1_2 fun;
};
struct then__lambda0 {
	struct fun_ref1 cb;
	struct fut_0* res;
};
struct subscript_4__lambda0 {
	struct fun_ref1 f;
	struct void_ p0;
	struct fut_0* res;
};
struct subscript_4__lambda0__lambda0 {
	struct fun_ref1 f;
	struct void_ p0;
	struct fut_0* res;
};
struct then2__lambda0 {
	struct fun_ref0 cb;
};
struct subscript_9__lambda0 {
	struct fun_ref0 f;
	struct fut_0* res;
};
struct subscript_9__lambda0__lambda0 {
	struct fun_ref0 f;
	struct fut_0* res;
};
struct add_first_task__lambda0 {
	struct arr_4 all_args;
	fun_ptr2 main_ptr;
};
struct map__lambda0 {
	struct fun_act1_4 mapper;
	struct arr_4 a;
};
struct chosen_task;
struct no_chosen_task {
	uint8_t no_tasks_and_last_thread_out__q;
	struct opt_8 first_task_time;
};
struct no_task {
	uint8_t any_tasks__q;
	struct opt_8 first_task_time;
};
struct mut_list_1 {
	struct mut_arr_1 backing;
	uint64_t size;
};
struct fut_state_0;
struct result_0;
struct fut_state_1;
struct result_1;
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
struct fut_0;
struct exception {
	struct arr_0 message;
	struct backtrace backtrace;
};
struct err {
	struct exception value;
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
struct exception_ctx {
	struct jmp_buf_tag* jmp_buf_ptr;
	struct exception thrown_exception;
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
struct fut_1;
struct chosen_task {
	struct island* task_island;
	struct task_or_gc task_or_gc;
};
struct fut_state_0 {
	uint64_t kind;
	union {
		struct fut_state_callbacks_0 as0;
		struct fut_state_resolved_0 as1;
		struct exception as2;
	};
};
struct result_0 {
	uint64_t kind;
	union {
		struct ok_0 as0;
		struct err as1;
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
struct result_1 {
	uint64_t kind;
	union {
		struct ok_1 as0;
		struct err as1;
	};
};
struct choose_task_result {
	uint64_t kind;
	union {
		struct chosen_task as0;
		struct no_chosen_task as1;
	};
};
struct fut_0 {
	struct lock lk;
	struct fut_state_0 state;
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
struct fut_1 {
	struct lock lk;
	struct fut_state_1 state;
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
_Static_assert(sizeof(struct less) == 0, "");
_Static_assert(sizeof(struct equal) == 0, "");
_Static_assert(sizeof(struct greater) == 0, "");
_Static_assert(sizeof(struct fut_0) == 48, "");
_Static_assert(sizeof(struct lock) == 1, "");
_Static_assert(sizeof(struct _atomic_bool) == 1, "");
_Static_assert(sizeof(struct fut_state_callbacks_0) == 16, "");
_Static_assert(sizeof(struct fut_callback_node_0) == 32, "");
_Static_assert(sizeof(struct exception) == 32, "");
_Static_assert(sizeof(struct arr_0) == 16, "");
_Static_assert(sizeof(struct backtrace) == 16, "");
_Static_assert(sizeof(struct arr_1) == 16, "");
_Static_assert(sizeof(struct ok_0) == 8, "");
_Static_assert(sizeof(struct err) == 32, "");
_Static_assert(sizeof(struct none) == 0, "");
_Static_assert(sizeof(struct some_0) == 8, "");
_Static_assert(sizeof(struct fut_state_resolved_0) == 8, "");
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
_Static_assert(sizeof(struct exception_ctx) == 40, "");
_Static_assert(sizeof(struct jmp_buf_tag) == 200, "");
_Static_assert(sizeof(struct bytes64) == 64, "");
_Static_assert(sizeof(struct bytes32) == 32, "");
_Static_assert(sizeof(struct bytes16) == 16, "");
_Static_assert(sizeof(struct bytes128) == 128, "");
_Static_assert(sizeof(struct backtrace_arrs) == 32, "");
_Static_assert(sizeof(struct some_3) == 8, "");
_Static_assert(sizeof(struct some_4) == 8, "");
_Static_assert(sizeof(struct some_5) == 8, "");
_Static_assert(sizeof(struct some_6) == 8, "");
_Static_assert(sizeof(struct arrow) == 16, "");
_Static_assert(sizeof(struct log_ctx) == 8, "");
_Static_assert(sizeof(struct thread_local_stuff) == 16, "");
_Static_assert(sizeof(struct arr_4) == 16, "");
_Static_assert(sizeof(struct fut_1) == 48, "");
_Static_assert(sizeof(struct fut_state_callbacks_1) == 16, "");
_Static_assert(sizeof(struct fut_callback_node_1) == 32, "");
_Static_assert(sizeof(struct ok_1) == 0, "");
_Static_assert(sizeof(struct some_7) == 8, "");
_Static_assert(sizeof(struct fut_state_resolved_1) == 0, "");
_Static_assert(sizeof(struct fun_ref0) == 32, "");
_Static_assert(sizeof(struct island_and_exclusion) == 16, "");
_Static_assert(sizeof(struct fun_ref1) == 32, "");
_Static_assert(sizeof(struct then__lambda0) == 40, "");
_Static_assert(sizeof(struct forward_to__lambda0) == 8, "");
_Static_assert(sizeof(struct subscript_4__lambda0) == 40, "");
_Static_assert(sizeof(struct subscript_4__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct subscript_4__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct then2__lambda0) == 32, "");
_Static_assert(sizeof(struct subscript_9__lambda0) == 40, "");
_Static_assert(sizeof(struct subscript_9__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct subscript_9__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct add_first_task__lambda0) == 24, "");
_Static_assert(sizeof(struct map__lambda0) == 24, "");
_Static_assert(sizeof(struct thread_args) == 16, "");
_Static_assert(sizeof(struct cell_0) == 8, "");
_Static_assert(sizeof(struct chosen_task) == 48, "");
_Static_assert(sizeof(struct do_a_gc) == 0, "");
_Static_assert(sizeof(struct no_chosen_task) == 24, "");
_Static_assert(sizeof(struct some_8) == 8, "");
_Static_assert(sizeof(struct timespec) == 16, "");
_Static_assert(sizeof(struct cell_1) == 16, "");
_Static_assert(sizeof(struct no_task) == 24, "");
_Static_assert(sizeof(struct cell_2) == 8, "");
_Static_assert(sizeof(struct set) == 16, "");
_Static_assert(sizeof(struct mut_list_1) == 24, "");
_Static_assert(sizeof(struct mut_arr_1) == 16, "");
_Static_assert(sizeof(struct unique__e__lambda0) == 8, "");
_Static_assert(sizeof(struct mut_arr_3__lambda0) == 16, "");
_Static_assert(sizeof(struct _concatEquals_1__lambda0) == 8, "");
_Static_assert(sizeof(struct mut_set) == 8, "");
_Static_assert(sizeof(struct _concatEquals_2__lambda0) == 8, "");
_Static_assert(sizeof(struct comparison) == 8, "");
_Static_assert(sizeof(struct fut_state_0) == 40, "");
_Static_assert(sizeof(struct result_0) == 40, "");
_Static_assert(sizeof(struct fun_act1_0) == 16, "");
_Static_assert(sizeof(struct opt_0) == 16, "");
_Static_assert(sizeof(struct opt_1) == 16, "");
_Static_assert(sizeof(struct fun_act0_0) == 16, "");
_Static_assert(sizeof(struct opt_2) == 16, "");
_Static_assert(sizeof(struct fun1_0) == 8, "");
_Static_assert(sizeof(struct log_level) == 8, "");
_Static_assert(sizeof(struct fun1_1) == 8, "");
_Static_assert(sizeof(struct opt_3) == 16, "");
_Static_assert(sizeof(struct opt_4) == 16, "");
_Static_assert(sizeof(struct opt_5) == 16, "");
_Static_assert(sizeof(struct opt_6) == 16, "");
_Static_assert(sizeof(struct fun_act2) == 8, "");
_Static_assert(sizeof(struct fut_state_1) == 40, "");
_Static_assert(sizeof(struct result_1) == 40, "");
_Static_assert(sizeof(struct fun_act1_1) == 16, "");
_Static_assert(sizeof(struct opt_7) == 16, "");
_Static_assert(sizeof(struct fun_act0_1) == 16, "");
_Static_assert(sizeof(struct fun_act1_2) == 16, "");
_Static_assert(sizeof(struct fun_act1_3) == 16, "");
_Static_assert(sizeof(struct fun_act1_4) == 8, "");
_Static_assert(sizeof(struct fun_act1_5) == 16, "");
_Static_assert(sizeof(struct choose_task_result) == 56, "");
_Static_assert(sizeof(struct task_or_gc) == 40, "");
_Static_assert(sizeof(struct opt_8) == 16, "");
_Static_assert(sizeof(struct choose_task_in_island_result) == 40, "");
_Static_assert(sizeof(struct pop_task_result) == 40, "");
_Static_assert(sizeof(struct fun_act1_6) == 16, "");
char constantarr_0_0[20];
char constantarr_0_1[1];
char constantarr_0_2[17];
char constantarr_0_3[11];
char constantarr_0_4[13];
char constantarr_0_5[13];
char constantarr_0_6[5];
char constantarr_0_7[4];
char constantarr_0_8[4];
char constantarr_0_9[2];
char constantarr_0_10[5];
char constantarr_0_11[6];
char constantarr_0_12[5];
char constantarr_0_13[6];
char constantarr_0_14[1];
char constantarr_0_15[1];
char constantarr_0_16[1];
char constantarr_0_17[1];
char constantarr_0_18[1];
char constantarr_0_19[1];
char constantarr_0_20[1];
char constantarr_0_21[1];
char constantarr_0_22[1];
char constantarr_0_23[1];
char constantarr_0_24[12];
char constantarr_0_25[4];
char constantarr_0_26[5];
char constantarr_0_27[12];
char constantarr_0_28[6];
char constantarr_0_29[12];
char constantarr_0_30[7];
char constantarr_0_31[2];
char constantarr_0_32[14];
char constantarr_0_33[12];
char constantarr_0_34[15];
char constantarr_0_35[21];
char constantarr_0_36[5];
char constantarr_0_37[14];
char constantarr_0_38[4];
char constantarr_0_39[14];
char constantarr_0_40[10];
char constantarr_0_41[25];
char constantarr_0_42[8];
char constantarr_0_43[8];
char constantarr_0_44[8];
char constantarr_0_45[12];
char constantarr_0_46[19];
char constantarr_0_47[11];
char constantarr_0_48[3];
char constantarr_0_49[5];
char constantarr_0_50[7];
char constantarr_0_51[7];
char constantarr_0_52[11];
char constantarr_0_53[6];
char constantarr_0_54[8];
char constantarr_0_55[11];
char constantarr_0_56[12];
char constantarr_0_57[6];
char constantarr_0_58[17];
char constantarr_0_59[7];
char constantarr_0_60[7];
char constantarr_0_61[5];
char constantarr_0_62[16];
char constantarr_0_63[13];
char constantarr_0_64[2];
char constantarr_0_65[11];
char constantarr_0_66[9];
char constantarr_0_67[10];
char constantarr_0_68[6];
char constantarr_0_69[7];
char constantarr_0_70[10];
char constantarr_0_71[22];
char constantarr_0_72[10];
char constantarr_0_73[8];
char constantarr_0_74[4];
char constantarr_0_75[15];
char constantarr_0_76[11];
char constantarr_0_77[13];
char constantarr_0_78[9];
char constantarr_0_79[22];
char constantarr_0_80[10];
char constantarr_0_81[14];
char constantarr_0_82[10];
char constantarr_0_83[4];
char constantarr_0_84[60];
char constantarr_0_85[11];
char constantarr_0_86[4];
char constantarr_0_87[7];
char constantarr_0_88[35];
char constantarr_0_89[28];
char constantarr_0_90[21];
char constantarr_0_91[6];
char constantarr_0_92[11];
char constantarr_0_93[11];
char constantarr_0_94[10];
char constantarr_0_95[8];
char constantarr_0_96[8];
char constantarr_0_97[18];
char constantarr_0_98[6];
char constantarr_0_99[19];
char constantarr_0_100[12];
char constantarr_0_101[26];
char constantarr_0_102[14];
char constantarr_0_103[25];
char constantarr_0_104[20];
char constantarr_0_105[16];
char constantarr_0_106[13];
char constantarr_0_107[13];
char constantarr_0_108[5];
char constantarr_0_109[21];
char constantarr_0_110[10];
char constantarr_0_111[10];
char constantarr_0_112[7];
char constantarr_0_113[6];
char constantarr_0_114[13];
char constantarr_0_115[10];
char constantarr_0_116[10];
char constantarr_0_117[6];
char constantarr_0_118[9];
char constantarr_0_119[14];
char constantarr_0_120[12];
char constantarr_0_121[12];
char constantarr_0_122[7];
char constantarr_0_123[10];
char constantarr_0_124[15];
char constantarr_0_125[8];
char constantarr_0_126[18];
char constantarr_0_127[6];
char constantarr_0_128[10];
char constantarr_0_129[9];
char constantarr_0_130[17];
char constantarr_0_131[21];
char constantarr_0_132[17];
char constantarr_0_133[7];
char constantarr_0_134[18];
char constantarr_0_135[11];
char constantarr_0_136[20];
char constantarr_0_137[7];
char constantarr_0_138[15];
char constantarr_0_139[9];
char constantarr_0_140[13];
char constantarr_0_141[24];
char constantarr_0_142[34];
char constantarr_0_143[9];
char constantarr_0_144[12];
char constantarr_0_145[11];
char constantarr_0_146[18];
char constantarr_0_147[13];
char constantarr_0_148[10];
char constantarr_0_149[8];
char constantarr_0_150[8];
char constantarr_0_151[17];
char constantarr_0_152[11];
char constantarr_0_153[10];
char constantarr_0_154[8];
char constantarr_0_155[8];
char constantarr_0_156[7];
char constantarr_0_157[10];
char constantarr_0_158[6];
char constantarr_0_159[11];
char constantarr_0_160[12];
char constantarr_0_161[12];
char constantarr_0_162[15];
char constantarr_0_163[19];
char constantarr_0_164[9];
char constantarr_0_165[6];
char constantarr_0_166[2];
char constantarr_0_167[10];
char constantarr_0_168[14];
char constantarr_0_169[10];
char constantarr_0_170[13];
char constantarr_0_171[18];
char constantarr_0_172[16];
char constantarr_0_173[34];
char constantarr_0_174[10];
char constantarr_0_175[20];
char constantarr_0_176[14];
char constantarr_0_177[21];
char constantarr_0_178[21];
char constantarr_0_179[9];
char constantarr_0_180[18];
char constantarr_0_181[21];
char constantarr_0_182[13];
char constantarr_0_183[6];
char constantarr_0_184[9];
char constantarr_0_185[15];
char constantarr_0_186[14];
char constantarr_0_187[25];
char constantarr_0_188[7];
char constantarr_0_189[14];
char constantarr_0_190[12];
char constantarr_0_191[11];
char constantarr_0_192[14];
char constantarr_0_193[12];
char constantarr_0_194[12];
char constantarr_0_195[10];
char constantarr_0_196[8];
char constantarr_0_197[9];
char constantarr_0_198[13];
char constantarr_0_199[15];
char constantarr_0_200[9];
char constantarr_0_201[15];
char constantarr_0_202[24];
char constantarr_0_203[15];
char constantarr_0_204[10];
char constantarr_0_205[10];
char constantarr_0_206[21];
char constantarr_0_207[20];
char constantarr_0_208[15];
char constantarr_0_209[15];
char constantarr_0_210[14];
char constantarr_0_211[12];
char constantarr_0_212[8];
char constantarr_0_213[5];
char constantarr_0_214[1];
char constantarr_0_215[3];
char constantarr_0_216[7];
char constantarr_0_217[23];
char constantarr_0_218[5];
char constantarr_0_219[8];
char constantarr_0_220[15];
char constantarr_0_221[18];
char constantarr_0_222[6];
char constantarr_0_223[5];
char constantarr_0_224[13];
char constantarr_0_225[6];
char constantarr_0_226[13];
char constantarr_0_227[14];
char constantarr_0_228[12];
char constantarr_0_229[1];
char constantarr_0_230[12];
char constantarr_0_231[13];
char constantarr_0_232[12];
char constantarr_0_233[29];
char constantarr_0_234[14];
char constantarr_0_235[18];
char constantarr_0_236[8];
char constantarr_0_237[18];
char constantarr_0_238[19];
char constantarr_0_239[5];
char constantarr_0_240[16];
char constantarr_0_241[6];
char constantarr_0_242[6];
char constantarr_0_243[5];
char constantarr_0_244[18];
char constantarr_0_245[6];
char constantarr_0_246[6];
char constantarr_0_247[20];
char constantarr_0_248[21];
char constantarr_0_249[23];
char constantarr_0_250[19];
char constantarr_0_251[18];
char constantarr_0_252[11];
char constantarr_0_253[11];
char constantarr_0_254[14];
char constantarr_0_255[7];
char constantarr_0_256[17];
char constantarr_0_257[13];
char constantarr_0_258[11];
char constantarr_0_259[7];
char constantarr_0_260[26];
char constantarr_0_261[30];
char constantarr_0_262[18];
char constantarr_0_263[25];
char constantarr_0_264[19];
char constantarr_0_265[7];
char constantarr_0_266[18];
char constantarr_0_267[12];
char constantarr_0_268[18];
char constantarr_0_269[16];
char constantarr_0_270[7];
char constantarr_0_271[10];
char constantarr_0_272[23];
char constantarr_0_273[12];
char constantarr_0_274[5];
char constantarr_0_275[23];
char constantarr_0_276[9];
char constantarr_0_277[12];
char constantarr_0_278[13];
char constantarr_0_279[9];
char constantarr_0_280[16];
char constantarr_0_281[2];
char constantarr_0_282[12];
char constantarr_0_283[23];
char constantarr_0_284[6];
char constantarr_0_285[12];
char constantarr_0_286[13];
char constantarr_0_287[16];
char constantarr_0_288[8];
char constantarr_0_289[12];
char constantarr_0_290[10];
char constantarr_0_291[9];
char constantarr_0_292[14];
char constantarr_0_293[11];
char constantarr_0_294[11];
char constantarr_0_295[26];
char constantarr_0_296[7];
char constantarr_0_297[3];
char constantarr_0_298[22];
char constantarr_0_299[2];
char constantarr_0_300[25];
char constantarr_0_301[19];
char constantarr_0_302[30];
char constantarr_0_303[15];
char constantarr_0_304[79];
char constantarr_0_305[14];
char constantarr_0_306[10];
char constantarr_0_307[16];
char constantarr_0_308[24];
char constantarr_0_309[7];
char constantarr_0_310[23];
char constantarr_0_311[14];
char constantarr_0_312[6];
char constantarr_0_313[9];
char constantarr_0_314[13];
char constantarr_0_315[27];
char constantarr_0_316[21];
char constantarr_0_317[8];
char constantarr_0_318[38];
char constantarr_0_319[22];
char constantarr_0_320[6];
char constantarr_0_321[9];
char constantarr_0_322[14];
char constantarr_0_323[16];
char constantarr_0_324[13];
char constantarr_0_325[21];
char constantarr_0_326[27];
char constantarr_0_327[10];
char constantarr_0_328[6];
char constantarr_0_329[28];
char constantarr_0_330[13];
char constantarr_0_331[22];
char constantarr_0_332[16];
char constantarr_0_333[24];
char constantarr_0_334[20];
char constantarr_0_335[10];
char constantarr_0_336[17];
char constantarr_0_337[7];
char constantarr_0_338[29];
char constantarr_0_339[8];
char constantarr_0_340[19];
char constantarr_0_341[15];
char constantarr_0_342[4];
char constantarr_0_343[10];
char constantarr_0_344[11];
char constantarr_0_345[4];
char constantarr_0_346[10];
char constantarr_0_347[4];
char constantarr_0_348[22];
char constantarr_0_349[4];
char constantarr_0_350[8];
char constantarr_0_351[21];
char constantarr_0_352[4];
char constantarr_0_353[12];
char constantarr_0_354[8];
char constantarr_0_355[5];
char constantarr_0_356[22];
char constantarr_0_357[9];
char constantarr_0_358[9];
char constantarr_0_359[21];
char constantarr_0_360[17];
char constantarr_0_361[4];
char constantarr_0_362[12];
char constantarr_0_363[9];
char constantarr_0_364[11];
char constantarr_0_365[28];
char constantarr_0_366[16];
char constantarr_0_367[11];
char constantarr_0_368[4];
char constantarr_0_369[7];
char constantarr_0_370[7];
char constantarr_0_371[7];
char constantarr_0_372[8];
char constantarr_0_373[15];
char constantarr_0_374[19];
char constantarr_0_375[6];
char constantarr_0_376[17];
char constantarr_0_377[24];
char constantarr_0_378[23];
char constantarr_0_379[12];
char constantarr_0_380[36];
char constantarr_0_381[10];
char constantarr_0_382[36];
char constantarr_0_383[28];
char constantarr_0_384[10];
char constantarr_0_385[24];
char constantarr_0_386[15];
char constantarr_0_387[24];
char constantarr_0_388[18];
char constantarr_0_389[7];
char constantarr_0_390[31];
char constantarr_0_391[31];
char constantarr_0_392[23];
char constantarr_0_393[18];
char constantarr_0_394[24];
char constantarr_0_395[20];
char constantarr_0_396[9];
char constantarr_0_397[5];
char constantarr_0_398[14];
char constantarr_0_399[15];
char constantarr_0_400[10];
char constantarr_0_401[40];
char constantarr_0_402[25];
char constantarr_0_403[14];
char constantarr_0_404[18];
char constantarr_0_405[24];
char constantarr_0_406[18];
char constantarr_0_407[14];
char constantarr_0_408[33];
char constantarr_0_409[24];
char constantarr_0_410[5];
char constantarr_0_411[13];
char constantarr_0_412[17];
char constantarr_0_413[8];
char constantarr_0_414[11];
char constantarr_0_415[15];
char constantarr_0_416[10];
char constantarr_0_417[30];
char constantarr_0_418[22];
char constantarr_0_419[22];
char constantarr_0_420[26];
char constantarr_0_421[17];
char constantarr_0_422[14];
char constantarr_0_423[30];
char constantarr_0_424[15];
char constantarr_0_425[80];
char constantarr_0_426[11];
char constantarr_0_427[45];
char constantarr_0_428[19];
char constantarr_0_429[22];
char constantarr_0_430[24];
char constantarr_0_431[11];
char constantarr_0_432[17];
char constantarr_0_433[14];
char constantarr_0_434[9];
char constantarr_0_435[6];
char constantarr_0_436[12];
char constantarr_0_437[16];
char constantarr_0_438[36];
char constantarr_0_439[10];
char constantarr_0_440[19];
char constantarr_0_441[15];
char constantarr_0_442[21];
char constantarr_0_443[10];
char constantarr_0_444[18];
char constantarr_0_445[14];
char constantarr_0_446[28];
char constantarr_0_447[9];
char constantarr_0_448[17];
char constantarr_0_449[6];
char constantarr_0_450[21];
char constantarr_0_451[16];
char constantarr_0_452[11];
char constantarr_0_453[17];
char constantarr_0_454[26];
char constantarr_0_455[14];
char constantarr_0_456[8];
char constantarr_0_457[13];
char constantarr_0_458[15];
char constantarr_0_459[26];
char constantarr_0_460[13];
char constantarr_0_461[6];
char constantarr_0_462[7];
char constantarr_0_463[9];
char constantarr_0_464[22];
char constantarr_0_465[17];
char constantarr_0_466[14];
char constantarr_0_467[21];
char constantarr_0_468[32];
char constantarr_0_469[7];
char constantarr_0_470[7];
char constantarr_0_471[8];
char constantarr_0_472[25];
char constantarr_0_473[28];
char constantarr_0_474[19];
char constantarr_0_475[14];
char constantarr_0_476[13];
char constantarr_0_477[19];
char constantarr_0_478[15];
char constantarr_0_479[9];
char constantarr_0_480[19];
char constantarr_0_481[11];
char constantarr_0_482[9];
char constantarr_0_483[11];
char constantarr_0_484[9];
char constantarr_0_485[38];
char constantarr_0_486[12];
char constantarr_0_487[12];
char constantarr_0_488[17];
char constantarr_0_489[7];
char constantarr_0_490[11];
char constantarr_0_491[21];
char constantarr_0_492[11];
char constantarr_0_493[10];
char constantarr_0_494[8];
char constantarr_0_495[8];
char constantarr_0_496[5];
char constantarr_0_497[10];
char constantarr_0_498[15];
char constantarr_0_499[29];
char constantarr_0_500[7];
char constantarr_0_501[11];
char constantarr_0_502[10];
char constantarr_0_503[6];
char constantarr_0_504[11];
char constantarr_0_505[33];
char constantarr_0_506[38];
char constantarr_0_507[8];
char constantarr_0_508[30];
char constantarr_0_509[14];
char constantarr_0_510[10];
char constantarr_0_511[13];
char constantarr_0_512[12];
char constantarr_0_513[46];
char constantarr_0_514[13];
char constantarr_0_515[12];
char constantarr_0_516[8];
char constantarr_0_517[20];
char constantarr_0_518[8];
char constantarr_0_519[14];
char constantarr_0_520[20];
char constantarr_0_521[14];
char constantarr_0_522[14];
char constantarr_0_523[7];
char constantarr_0_524[12];
char constantarr_0_525[9];
char constantarr_0_526[18];
char constantarr_0_527[15];
char constantarr_0_528[27];
char constantarr_0_529[15];
char constantarr_0_530[12];
char constantarr_0_531[27];
char constantarr_0_532[6];
char constantarr_0_533[5];
char constantarr_0_534[14];
char constantarr_0_535[19];
char constantarr_0_536[4];
char constantarr_0_537[35];
char constantarr_0_538[18];
char constantarr_0_539[8];
char constantarr_0_540[25];
char constantarr_0_541[4];
char constantarr_0_542[15];
char constantarr_0_543[11];
char constantarr_0_544[8];
char constantarr_0_545[19];
char constantarr_0_546[9];
char constantarr_0_547[6];
char constantarr_0_548[8];
char constantarr_0_549[6];
char constantarr_0_550[18];
char constantarr_0_551[19];
char constantarr_0_552[25];
char constantarr_0_553[15];
char constantarr_0_554[21];
char constantarr_0_555[24];
char constantarr_0_556[30];
char constantarr_0_557[1];
char constantarr_0_558[1];
char constantarr_0_559[4];
char constantarr_0_560[7];
char constantarr_0_561[19];
char constantarr_0_562[16];
char constantarr_0_563[8];
char constantarr_0_564[16];
char constantarr_0_565[29];
char constantarr_0_566[19];
char constantarr_0_567[9];
char constantarr_0_568[8];
char constantarr_0_569[17];
char constantarr_0_570[16];
char constantarr_0_571[19];
char constantarr_0_572[5];
char constantarr_0_573[18];
char constantarr_0_574[3];
char constantarr_0_575[10];
char constantarr_0_576[15];
char constantarr_0_577[10];
char constantarr_0_578[20];
char constantarr_0_579[8];
char constantarr_0_580[12];
char constantarr_0_581[10];
char constantarr_0_582[20];
char constantarr_0_583[14];
char constantarr_0_584[12];
char constantarr_0_585[13];
char constantarr_0_586[14];
char constantarr_0_587[18];
char constantarr_0_588[11];
char constantarr_0_589[18];
char constantarr_0_590[11];
char constantarr_0_591[14];
char constantarr_0_592[7];
char constantarr_0_593[13];
char constantarr_0_594[10];
char constantarr_0_595[8];
char constantarr_0_596[14];
char constantarr_0_597[21];
char constantarr_0_598[23];
char constantarr_0_599[13];
struct arr_0 constantarr_1_0[4];
struct arr_0 constantarr_1_1[3];
struct arr_0 constantarr_1_2[3];
struct arr_0 constantarr_1_3[2];
char constantarr_0_0[20] = "uncaught exception: ";
char constantarr_0_1[1] = "\n";
char constantarr_0_2[17] = "<<empty message>>";
char constantarr_0_3[11] = "<<UNKNOWN>>";
char constantarr_0_4[13] = "assert failed";
char constantarr_0_5[13] = "forbid failed";
char constantarr_0_6[5] = "\n\tat ";
char constantarr_0_7[4] = "info";
char constantarr_0_8[4] = "warn";
char constantarr_0_9[2] = ": ";
char constantarr_0_10[5] = "beans";
char constantarr_0_11[6] = "pepper";
char constantarr_0_12[5] = "onion";
char constantarr_0_13[6] = "size: ";
char constantarr_0_14[1] = "0";
char constantarr_0_15[1] = "1";
char constantarr_0_16[1] = "2";
char constantarr_0_17[1] = "3";
char constantarr_0_18[1] = "4";
char constantarr_0_19[1] = "5";
char constantarr_0_20[1] = "6";
char constantarr_0_21[1] = "7";
char constantarr_0_22[1] = "8";
char constantarr_0_23[1] = "9";
char constantarr_0_24[12] = "has pepper? ";
char constantarr_0_25[4] = "true";
char constantarr_0_26[5] = "false";
char constantarr_0_27[12] = "has potato? ";
char constantarr_0_28[6] = "potato";
char constantarr_0_29[12] = "spray bottle";
char constantarr_0_30[7] = "union: ";
char constantarr_0_31[2] = ", ";
char constantarr_0_32[14] = "intersection: ";
char constantarr_0_33[12] = "difference: ";
char constantarr_0_34[15] = "remove pepper? ";
char constantarr_0_35[21] = "remove pepper again? ";
char constantarr_0_36[5] = "cumin";
char constantarr_0_37[14] = "after concat: ";
char constantarr_0_38[4] = "mark";
char constantarr_0_39[14] = "words-of-bytes";
char constantarr_0_40[10] = "unsafe-div";
char constantarr_0_41[25] = "round-up-to-multiple-of-8";
char constantarr_0_42[8] = "bits-and";
char constantarr_0_43[8] = "wrap-add";
char constantarr_0_44[8] = "bits-not";
char constantarr_0_45[12] = "as<ptr<nat>>";
char constantarr_0_46[19] = "ptr-cast<nat, nat8>";
char constantarr_0_47[11] = "hard-assert";
char constantarr_0_48[3] = "not";
char constantarr_0_49[5] = "abort";
char constantarr_0_50[7] = "==<nat>";
char constantarr_0_51[7] = "<=><?t>";
char constantarr_0_52[11] = "to-nat<nat>";
char constantarr_0_53[6] = "-<nat>";
char constantarr_0_54[8] = "wrap-sub";
char constantarr_0_55[11] = "size-of<?t>";
char constantarr_0_56[12] = "memory-start";
char constantarr_0_57[6] = "<<nat>";
char constantarr_0_58[17] = "memory-size-words";
char constantarr_0_59[7] = "<=<nat>";
char constantarr_0_60[7] = "+<bool>";
char constantarr_0_61[5] = "marks";
char constantarr_0_62[16] = "mark-range-recur";
char constantarr_0_63[13] = "ptr-eq?<bool>";
char constantarr_0_64[2] = "or";
char constantarr_0_65[11] = "deref<bool>";
char constantarr_0_66[9] = "set<bool>";
char constantarr_0_67[10] = "incr<bool>";
char constantarr_0_68[6] = "><nat>";
char constantarr_0_69[7] = "rt-main";
char constantarr_0_70[10] = "get-nprocs";
char constantarr_0_71[22] = "as<by-val<global-ctx>>";
char constantarr_0_72[10] = "global-ctx";
char constantarr_0_73[8] = "new-lock";
char constantarr_0_74[4] = "lock";
char constantarr_0_75[15] = "new-atomic-bool";
char constantarr_0_76[11] = "atomic-bool";
char constantarr_0_77[13] = "new-condition";
char constantarr_0_78[9] = "condition";
char constantarr_0_79[22] = "ref-of-val<global-ctx>";
char constantarr_0_80[10] = "new-island";
char constantarr_0_81[14] = "new-task-queue";
char constantarr_0_82[10] = "task-queue";
char constantarr_0_83[4] = "none";
char constantarr_0_84[60] = "new-mut-list-by-val-with-capacity-from-unmanaged-memory<nat>";
char constantarr_0_85[11] = "mut-arr<?t>";
char constantarr_0_86[4] = "void";
char constantarr_0_87[7] = "arr<?t>";
char constantarr_0_88[35] = "unmanaged-alloc-zeroed-elements<?t>";
char constantarr_0_89[28] = "unmanaged-alloc-elements<?t>";
char constantarr_0_90[21] = "unmanaged-alloc-bytes";
char constantarr_0_91[6] = "malloc";
char constantarr_0_92[11] = "hard-forbid";
char constantarr_0_93[11] = "null?<nat8>";
char constantarr_0_94[10] = "to-nat<?t>";
char constantarr_0_95[8] = "null<?t>";
char constantarr_0_96[8] = "wrap-mul";
char constantarr_0_97[18] = "set-zero-range<?t>";
char constantarr_0_98[6] = "memset";
char constantarr_0_99[19] = "as-any-ptr<ptr<?t>>";
char constantarr_0_100[12] = "mut-list<?t>";
char constantarr_0_101[26] = "as<by-val<island-gc-root>>";
char constantarr_0_102[14] = "island-gc-root";
char constantarr_0_103[25] = "default-exception-handler";
char constantarr_0_104[20] = "print-err-no-newline";
char constantarr_0_105[16] = "write-no-newline";
char constantarr_0_106[13] = "size-of<char>";
char constantarr_0_107[13] = "size-of<nat8>";
char constantarr_0_108[5] = "write";
char constantarr_0_109[21] = "as-any-ptr<ptr<char>>";
char constantarr_0_110[10] = "data<char>";
char constantarr_0_111[10] = "size<char>";
char constantarr_0_112[7] = "!=<int>";
char constantarr_0_113[6] = "==<?t>";
char constantarr_0_114[13] = "unsafe-to-int";
char constantarr_0_115[10] = "todo<void>";
char constantarr_0_116[10] = "zeroed<?t>";
char constantarr_0_117[6] = "stderr";
char constantarr_0_118[9] = "print-err";
char constantarr_0_119[14] = "show-exception";
char constantarr_0_120[12] = "?<arr<char>>";
char constantarr_0_121[12] = "empty?<char>";
char constantarr_0_122[7] = "message";
char constantarr_0_123[10] = "join<char>";
char constantarr_0_124[15] = "empty?<arr<?t>>";
char constantarr_0_125[8] = "size<?t>";
char constantarr_0_126[18] = "subscript<arr<?t>>";
char constantarr_0_127[6] = "assert";
char constantarr_0_128[10] = "fail<void>";
char constantarr_0_129[9] = "throw<?t>";
char constantarr_0_130[17] = "get-exception-ctx";
char constantarr_0_131[21] = "as-ref<exception-ctx>";
char constantarr_0_132[17] = "exception-ctx-ptr";
char constantarr_0_133[7] = "get-ctx";
char constantarr_0_134[18] = "null?<jmp-buf-tag>";
char constantarr_0_135[11] = "jmp-buf-ptr";
char constantarr_0_136[20] = "set-thrown-exception";
char constantarr_0_137[7] = "longjmp";
char constantarr_0_138[15] = "number-to-throw";
char constantarr_0_139[9] = "exception";
char constantarr_0_140[13] = "get-backtrace";
char constantarr_0_141[24] = "try-alloc-backtrace-arrs";
char constantarr_0_142[34] = "try-alloc-uninitialized<ptr<nat8>>";
char constantarr_0_143[9] = "try-alloc";
char constantarr_0_144[12] = "try-gc-alloc";
char constantarr_0_145[11] = "validate-gc";
char constantarr_0_146[18] = "ptr-less-eq?<bool>";
char constantarr_0_147[13] = "ptr-less?<?t>";
char constantarr_0_148[10] = "mark-begin";
char constantarr_0_149[8] = "mark-cur";
char constantarr_0_150[8] = "mark-end";
char constantarr_0_151[17] = "ptr-less-eq?<nat>";
char constantarr_0_152[11] = "ptr-eq?<?t>";
char constantarr_0_153[10] = "data-begin";
char constantarr_0_154[8] = "data-cur";
char constantarr_0_155[8] = "data-end";
char constantarr_0_156[7] = "-<bool>";
char constantarr_0_157[10] = "size-words";
char constantarr_0_158[6] = "+<nat>";
char constantarr_0_159[11] = "range-free?";
char constantarr_0_160[12] = "set-mark-cur";
char constantarr_0_161[12] = "set-data-cur";
char constantarr_0_162[15] = "some<ptr<nat8>>";
char constantarr_0_163[19] = "ptr-cast<nat8, nat>";
char constantarr_0_164[9] = "incr<nat>";
char constantarr_0_165[6] = "get-gc";
char constantarr_0_166[2] = "gc";
char constantarr_0_167[10] = "get-gc-ctx";
char constantarr_0_168[14] = "as-ref<gc-ctx>";
char constantarr_0_169[10] = "gc-ctx-ptr";
char constantarr_0_170[13] = "some<ptr<?t>>";
char constantarr_0_171[18] = "ptr-cast<?t, nat8>";
char constantarr_0_172[16] = "value<ptr<nat8>>";
char constantarr_0_173[34] = "try-alloc-uninitialized<arr<char>>";
char constantarr_0_174[10] = "funs-count";
char constantarr_0_175[20] = "some<backtrace-arrs>";
char constantarr_0_176[14] = "backtrace-arrs";
char constantarr_0_177[21] = "value<ptr<ptr<nat8>>>";
char constantarr_0_178[21] = "value<ptr<arr<char>>>";
char constantarr_0_179[9] = "backtrace";
char constantarr_0_180[18] = "as<arr<arr<char>>>";
char constantarr_0_181[21] = "value<backtrace-arrs>";
char constantarr_0_182[13] = "unsafe-to-nat";
char constantarr_0_183[6] = "to-int";
char constantarr_0_184[9] = "code-ptrs";
char constantarr_0_185[15] = "unsafe-to-int32";
char constantarr_0_186[14] = "code-ptrs-size";
char constantarr_0_187[25] = "fill-fun-ptrs-names-recur";
char constantarr_0_188[7] = "!=<nat>";
char constantarr_0_189[14] = "set<ptr<nat8>>";
char constantarr_0_190[12] = "+<ptr<nat8>>";
char constantarr_0_191[11] = "get-fun-ptr";
char constantarr_0_192[14] = "set<arr<char>>";
char constantarr_0_193[12] = "+<arr<char>>";
char constantarr_0_194[12] = "get-fun-name";
char constantarr_0_195[10] = "noctx-incr";
char constantarr_0_196[8] = "fun-ptrs";
char constantarr_0_197[9] = "fun-names";
char constantarr_0_198[13] = "sort-together";
char constantarr_0_199[15] = "swap<ptr<nat8>>";
char constantarr_0_200[9] = "deref<?t>";
char constantarr_0_201[15] = "swap<arr<char>>";
char constantarr_0_202[24] = "partition-recur-together";
char constantarr_0_203[15] = "ptr-less?<nat8>";
char constantarr_0_204[10] = "noctx-decr";
char constantarr_0_205[10] = "code-names";
char constantarr_0_206[21] = "fill-code-names-recur";
char constantarr_0_207[20] = "ptr-less?<arr<char>>";
char constantarr_0_208[15] = "incr<ptr<nat8>>";
char constantarr_0_209[15] = "incr<arr<char>>";
char constantarr_0_210[14] = "arr<arr<char>>";
char constantarr_0_211[12] = "noctx-at<?t>";
char constantarr_0_212[8] = "data<?t>";
char constantarr_0_213[5] = "~<?t>";
char constantarr_0_214[1] = "+";
char constantarr_0_215[3] = "and";
char constantarr_0_216[7] = ">=<nat>";
char constantarr_0_217[23] = "alloc-uninitialized<?t>";
char constantarr_0_218[5] = "alloc";
char constantarr_0_219[8] = "gc-alloc";
char constantarr_0_220[15] = "todo<ptr<nat8>>";
char constantarr_0_221[18] = "copy-data-from<?t>";
char constantarr_0_222[6] = "memcpy";
char constantarr_0_223[5] = "+<?t>";
char constantarr_0_224[13] = "tail<arr<?t>>";
char constantarr_0_225[6] = "forbid";
char constantarr_0_226[13] = "subscript<?t>";
char constantarr_0_227[14] = "from<nat, nat>";
char constantarr_0_228[12] = "to<nat, nat>";
char constantarr_0_229[1] = "-";
char constantarr_0_230[12] = "-><nat, nat>";
char constantarr_0_231[13] = "arrow<?a, ?b>";
char constantarr_0_232[12] = "return-stack";
char constantarr_0_233[29] = "set-any-unhandled-exceptions?";
char constantarr_0_234[14] = "get-global-ctx";
char constantarr_0_235[18] = "as-ref<global-ctx>";
char constantarr_0_236[8] = "gctx-ptr";
char constantarr_0_237[18] = "new-island.lambda0";
char constantarr_0_238[19] = "default-log-handler";
char constantarr_0_239[5] = "print";
char constantarr_0_240[16] = "print-no-newline";
char constantarr_0_241[6] = "stdout";
char constantarr_0_242[6] = "to-str";
char constantarr_0_243[5] = "level";
char constantarr_0_244[18] = "new-island.lambda1";
char constantarr_0_245[6] = "island";
char constantarr_0_246[6] = "new-gc";
char constantarr_0_247[20] = "ptr-cast<bool, nat8>";
char constantarr_0_248[21] = "as-any-ptr<ptr<bool>>";
char constantarr_0_249[23] = "new-thread-safe-counter";
char constantarr_0_250[19] = "thread-safe-counter";
char constantarr_0_251[18] = "ref-of-val<island>";
char constantarr_0_252[11] = "set-islands";
char constantarr_0_253[11] = "arr<island>";
char constantarr_0_254[14] = "ptr-to<island>";
char constantarr_0_255[7] = "do-main";
char constantarr_0_256[17] = "new-exception-ctx";
char constantarr_0_257[13] = "exception-ctx";
char constantarr_0_258[11] = "new-log-ctx";
char constantarr_0_259[7] = "log-ctx";
char constantarr_0_260[26] = "zeroed<fun1<void, logged>>";
char constantarr_0_261[30] = "as<by-val<thread-local-stuff>>";
char constantarr_0_262[18] = "thread-local-stuff";
char constantarr_0_263[25] = "ref-of-val<exception-ctx>";
char constantarr_0_264[19] = "ref-of-val<log-ctx>";
char constantarr_0_265[7] = "new-ctx";
char constantarr_0_266[18] = "as-any-ptr<gc-ctx>";
char constantarr_0_267[12] = "acquire-lock";
char constantarr_0_268[18] = "acquire-lock-recur";
char constantarr_0_269[16] = "try-acquire-lock";
char constantarr_0_270[7] = "try-set";
char constantarr_0_271[10] = "try-change";
char constantarr_0_272[23] = "compare-exchange-strong";
char constantarr_0_273[12] = "ptr-to<bool>";
char constantarr_0_274[5] = "value";
char constantarr_0_275[23] = "ref-of-val<atomic-bool>";
char constantarr_0_276[9] = "is-locked";
char constantarr_0_277[12] = "yield-thread";
char constantarr_0_278[13] = "pthread-yield";
char constantarr_0_279[9] = "==<int32>";
char constantarr_0_280[16] = "ref-of-val<lock>";
char constantarr_0_281[2] = "lk";
char constantarr_0_282[12] = "context-head";
char constantarr_0_283[23] = "size-of<by-val<gc-ctx>>";
char constantarr_0_284[6] = "set-gc";
char constantarr_0_285[12] = "set-next-ctx";
char constantarr_0_286[13] = "value<gc-ctx>";
char constantarr_0_287[16] = "set-context-head";
char constantarr_0_288[8] = "next-ctx";
char constantarr_0_289[12] = "release-lock";
char constantarr_0_290[10] = "must-unset";
char constantarr_0_291[9] = "try-unset";
char constantarr_0_292[14] = "ref-of-val<gc>";
char constantarr_0_293[11] = "set-handler";
char constantarr_0_294[11] = "log-handler";
char constantarr_0_295[26] = "ref-of-val<island-gc-root>";
char constantarr_0_296[7] = "gc-root";
char constantarr_0_297[3] = "ctx";
char constantarr_0_298[22] = "as-any-ptr<global-ctx>";
char constantarr_0_299[2] = "id";
char constantarr_0_300[25] = "as-any-ptr<exception-ctx>";
char constantarr_0_301[19] = "as-any-ptr<log-ctx>";
char constantarr_0_302[30] = "ref-of-val<thread-local-stuff>";
char constantarr_0_303[15] = "ref-of-val<ctx>";
char constantarr_0_304[79] = "as<fun-act2<fut<nat>, arr<ptr<char>>, fun-ptr2<fut<nat>, ctx, arr<arr<char>>>>>";
char constantarr_0_305[14] = "add-first-task";
char constantarr_0_306[10] = "then2<nat>";
char constantarr_0_307[16] = "then<?out, void>";
char constantarr_0_308[24] = "new-unresolved-fut<?out>";
char constantarr_0_309[7] = "fut<?t>";
char constantarr_0_310[23] = "fut-state-callbacks<?t>";
char constantarr_0_311[14] = "then-void<?in>";
char constantarr_0_312[6] = "lk<?t>";
char constantarr_0_313[9] = "state<?t>";
char constantarr_0_314[13] = "set-state<?t>";
char constantarr_0_315[27] = "some<fut-callback-node<?t>>";
char constantarr_0_316[21] = "fut-callback-node<?t>";
char constantarr_0_317[8] = "head<?t>";
char constantarr_0_318[38] = "subscript<void, result<?t, exception>>";
char constantarr_0_319[22] = "call-with-ctx<?r, ?p0>";
char constantarr_0_320[6] = "ok<?t>";
char constantarr_0_321[9] = "value<?t>";
char constantarr_0_322[14] = "err<exception>";
char constantarr_0_323[16] = "forward-to<?out>";
char constantarr_0_324[13] = "then-void<?t>";
char constantarr_0_325[21] = "resolve-or-reject<?t>";
char constantarr_0_326[27] = "resolve-or-reject-recur<?t>";
char constantarr_0_327[10] = "drop<void>";
char constantarr_0_328[6] = "cb<?t>";
char constantarr_0_329[28] = "value<fut-callback-node<?t>>";
char constantarr_0_330[13] = "next-node<?t>";
char constantarr_0_331[22] = "fut-state-resolved<?t>";
char constantarr_0_332[16] = "value<exception>";
char constantarr_0_333[24] = "forward-to<?out>.lambda0";
char constantarr_0_334[20] = "subscript<?out, ?in>";
char constantarr_0_335[10] = "get-island";
char constantarr_0_336[17] = "subscript<island>";
char constantarr_0_337[7] = "islands";
char constantarr_0_338[29] = "island-and-exclusion<?r, ?p0>";
char constantarr_0_339[8] = "add-task";
char constantarr_0_340[19] = "new-task-queue-node";
char constantarr_0_341[15] = "task-queue-node";
char constantarr_0_342[4] = "task";
char constantarr_0_343[10] = "tasks-lock";
char constantarr_0_344[11] = "insert-task";
char constantarr_0_345[4] = "size";
char constantarr_0_346[10] = "size-recur";
char constantarr_0_347[4] = "next";
char constantarr_0_348[22] = "value<task-queue-node>";
char constantarr_0_349[4] = "head";
char constantarr_0_350[8] = "set-head";
char constantarr_0_351[21] = "some<task-queue-node>";
char constantarr_0_352[4] = "time";
char constantarr_0_353[12] = "insert-recur";
char constantarr_0_354[8] = "set-next";
char constantarr_0_355[5] = "tasks";
char constantarr_0_356[22] = "ref-of-val<task-queue>";
char constantarr_0_357[9] = "broadcast";
char constantarr_0_358[9] = "set-value";
char constantarr_0_359[21] = "ref-of-val<condition>";
char constantarr_0_360[17] = "may-be-work-to-do";
char constantarr_0_361[4] = "gctx";
char constantarr_0_362[12] = "no-timestamp";
char constantarr_0_363[9] = "exclusion";
char constantarr_0_364[11] = "catch<void>";
char constantarr_0_365[28] = "catch-with-exception-ctx<?t>";
char constantarr_0_366[16] = "thrown-exception";
char constantarr_0_367[11] = "jmp-buf-tag";
char constantarr_0_368[4] = "zero";
char constantarr_0_369[7] = "bytes64";
char constantarr_0_370[7] = "bytes32";
char constantarr_0_371[7] = "bytes16";
char constantarr_0_372[8] = "bytes128";
char constantarr_0_373[15] = "set-jmp-buf-ptr";
char constantarr_0_374[19] = "ptr-to<jmp-buf-tag>";
char constantarr_0_375[6] = "setjmp";
char constantarr_0_376[17] = "call-with-ctx<?r>";
char constantarr_0_377[24] = "subscript<?t, exception>";
char constantarr_0_378[23] = "subscript<fut<?r>, ?p0>";
char constantarr_0_379[12] = "fun<?r, ?p0>";
char constantarr_0_380[36] = "subscript<?out, ?in>.lambda0.lambda0";
char constantarr_0_381[10] = "reject<?r>";
char constantarr_0_382[36] = "subscript<?out, ?in>.lambda0.lambda1";
char constantarr_0_383[28] = "subscript<?out, ?in>.lambda0";
char constantarr_0_384[10] = "value<?in>";
char constantarr_0_385[24] = "then<?out, void>.lambda0";
char constantarr_0_386[15] = "subscript<?out>";
char constantarr_0_387[24] = "island-and-exclusion<?r>";
char constantarr_0_388[18] = "subscript<fut<?r>>";
char constantarr_0_389[7] = "fun<?r>";
char constantarr_0_390[31] = "subscript<?out>.lambda0.lambda0";
char constantarr_0_391[31] = "subscript<?out>.lambda0.lambda1";
char constantarr_0_392[23] = "subscript<?out>.lambda0";
char constantarr_0_393[18] = "then2<nat>.lambda0";
char constantarr_0_394[24] = "cur-island-and-exclusion";
char constantarr_0_395[20] = "island-and-exclusion";
char constantarr_0_396[9] = "island-id";
char constantarr_0_397[5] = "delay";
char constantarr_0_398[14] = "resolved<void>";
char constantarr_0_399[15] = "tail<ptr<char>>";
char constantarr_0_400[10] = "empty?<?t>";
char constantarr_0_401[40] = "subscript<fut<nat>, ctx, arr<arr<char>>>";
char constantarr_0_402[25] = "map<arr<char>, ptr<char>>";
char constantarr_0_403[14] = "make-arr<?out>";
char constantarr_0_404[18] = "fill-ptr-range<?t>";
char constantarr_0_405[24] = "fill-ptr-range-recur<?t>";
char constantarr_0_406[18] = "subscript<?t, nat>";
char constantarr_0_407[14] = "subscript<?in>";
char constantarr_0_408[33] = "map<arr<char>, ptr<char>>.lambda0";
char constantarr_0_409[24] = "arr-from-begin-end<char>";
char constantarr_0_410[5] = "-<?t>";
char constantarr_0_411[13] = "find-cstr-end";
char constantarr_0_412[17] = "find-char-in-cstr";
char constantarr_0_413[8] = "==<char>";
char constantarr_0_414[11] = "deref<char>";
char constantarr_0_415[15] = "todo<ptr<char>>";
char constantarr_0_416[10] = "incr<char>";
char constantarr_0_417[30] = "add-first-task.lambda0.lambda0";
char constantarr_0_418[22] = "add-first-task.lambda0";
char constantarr_0_419[22] = "handle-exceptions<nat>";
char constantarr_0_420[26] = "subscript<void, exception>";
char constantarr_0_421[17] = "exception-handler";
char constantarr_0_422[14] = "get-cur-island";
char constantarr_0_423[30] = "handle-exceptions<nat>.lambda0";
char constantarr_0_424[15] = "do-main.lambda0";
char constantarr_0_425[80] = "call-with-ctx<fut<nat>, arr<ptr<char>>, fun-ptr2<fut<nat>, ctx, arr<arr<char>>>>";
char constantarr_0_426[11] = "run-threads";
char constantarr_0_427[45] = "unmanaged-alloc-elements<by-val<thread-args>>";
char constantarr_0_428[19] = "start-threads-recur";
char constantarr_0_429[22] = "+<by-val<thread-args>>";
char constantarr_0_430[24] = "set<by-val<thread-args>>";
char constantarr_0_431[11] = "thread-args";
char constantarr_0_432[17] = "create-one-thread";
char constantarr_0_433[14] = "pthread-create";
char constantarr_0_434[9] = "!=<int32>";
char constantarr_0_435[6] = "eagain";
char constantarr_0_436[12] = "as-cell<nat>";
char constantarr_0_437[16] = "as-ref<cell<?t>>";
char constantarr_0_438[36] = "as-any-ptr<ptr<by-val<thread-args>>>";
char constantarr_0_439[10] = "thread-fun";
char constantarr_0_440[19] = "as-ref<thread-args>";
char constantarr_0_441[15] = "thread-function";
char constantarr_0_442[21] = "thread-function-recur";
char constantarr_0_443[10] = "shut-down?";
char constantarr_0_444[18] = "set-n-live-threads";
char constantarr_0_445[14] = "n-live-threads";
char constantarr_0_446[28] = "assert-islands-are-shut-down";
char constantarr_0_447[9] = "needs-gc?";
char constantarr_0_448[17] = "n-threads-running";
char constantarr_0_449[6] = "empty?";
char constantarr_0_450[21] = "has?<task-queue-node>";
char constantarr_0_451[16] = "get-last-checked";
char constantarr_0_452[11] = "choose-task";
char constantarr_0_453[17] = "get-monotime-nsec";
char constantarr_0_454[26] = "as<by-val<cell<timespec>>>";
char constantarr_0_455[14] = "cell<timespec>";
char constantarr_0_456[8] = "timespec";
char constantarr_0_457[13] = "clock-gettime";
char constantarr_0_458[15] = "clock-monotonic";
char constantarr_0_459[26] = "ref-of-val<cell<timespec>>";
char constantarr_0_460[13] = "get<timespec>";
char constantarr_0_461[6] = "tv-sec";
char constantarr_0_462[7] = "tv-nsec";
char constantarr_0_463[9] = "todo<nat>";
char constantarr_0_464[22] = "as<choose-task-result>";
char constantarr_0_465[17] = "choose-task-recur";
char constantarr_0_466[14] = "no-chosen-task";
char constantarr_0_467[21] = "choose-task-in-island";
char constantarr_0_468[32] = "as<choose-task-in-island-result>";
char constantarr_0_469[7] = "do-a-gc";
char constantarr_0_470[7] = "no-task";
char constantarr_0_471[8] = "pop-task";
char constantarr_0_472[25] = "ref-of-val<mut-list<nat>>";
char constantarr_0_473[28] = "currently-running-exclusions";
char constantarr_0_474[19] = "as<pop-task-result>";
char constantarr_0_475[14] = "contains?<nat>";
char constantarr_0_476[13] = "contains?<?t>";
char constantarr_0_477[19] = "contains-recur?<?t>";
char constantarr_0_478[15] = "temp-as-arr<?t>";
char constantarr_0_479[9] = "inner<?t>";
char constantarr_0_480[19] = "temp-as-mut-arr<?t>";
char constantarr_0_481[11] = "backing<?t>";
char constantarr_0_482[9] = "pop-recur";
char constantarr_0_483[11] = "to-opt-time";
char constantarr_0_484[9] = "some<nat>";
char constantarr_0_485[38] = "push-capacity-must-be-sufficient!<nat>";
char constantarr_0_486[12] = "capacity<?t>";
char constantarr_0_487[12] = "set-size<?t>";
char constantarr_0_488[17] = "noctx-set-at!<?t>";
char constantarr_0_489[7] = "set<?t>";
char constantarr_0_490[11] = "is-no-task?";
char constantarr_0_491[21] = "set-n-threads-running";
char constantarr_0_492[11] = "chosen-task";
char constantarr_0_493[10] = "any-tasks?";
char constantarr_0_494[8] = "min-time";
char constantarr_0_495[8] = "min<nat>";
char constantarr_0_496[5] = "?<?t>";
char constantarr_0_497[10] = "value<nat>";
char constantarr_0_498[15] = "first-task-time";
char constantarr_0_499[29] = "no-tasks-and-last-thread-out?";
char constantarr_0_500[7] = "do-task";
char constantarr_0_501[11] = "task-island";
char constantarr_0_502[10] = "task-or-gc";
char constantarr_0_503[6] = "action";
char constantarr_0_504[11] = "return-task";
char constantarr_0_505[33] = "noctx-must-remove-unordered!<nat>";
char constantarr_0_506[38] = "noctx-must-remove-unordered-recur!<?t>";
char constantarr_0_507[8] = "drop<?t>";
char constantarr_0_508[30] = "noctx-remove-unordered-at!<?t>";
char constantarr_0_509[14] = "noctx-last<?t>";
char constantarr_0_510[10] = "return-ctx";
char constantarr_0_511[13] = "return-gc-ctx";
char constantarr_0_512[12] = "some<gc-ctx>";
char constantarr_0_513[46] = "run-garbage-collection<by-val<island-gc-root>>";
char constantarr_0_514[13] = "set-needs-gc?";
char constantarr_0_515[12] = "set-gc-count";
char constantarr_0_516[8] = "gc-count";
char constantarr_0_517[20] = "as<by-val<mark-ctx>>";
char constantarr_0_518[8] = "mark-ctx";
char constantarr_0_519[14] = "mark-visit<?a>";
char constantarr_0_520[20] = "ref-of-val<mark-ctx>";
char constantarr_0_521[14] = "clear-free-mem";
char constantarr_0_522[14] = "set-shut-down?";
char constantarr_0_523[7] = "wait-on";
char constantarr_0_524[12] = "before-time?";
char constantarr_0_525[9] = "thread-id";
char constantarr_0_526[18] = "join-threads-recur";
char constantarr_0_527[15] = "join-one-thread";
char constantarr_0_528[27] = "as<by-val<cell<ptr<nat8>>>>";
char constantarr_0_529[15] = "cell<ptr<nat8>>";
char constantarr_0_530[12] = "pthread-join";
char constantarr_0_531[27] = "ref-of-val<cell<ptr<nat8>>>";
char constantarr_0_532[6] = "einval";
char constantarr_0_533[5] = "esrch";
char constantarr_0_534[14] = "get<ptr<nat8>>";
char constantarr_0_535[19] = "unmanaged-free<nat>";
char constantarr_0_536[4] = "free";
char constantarr_0_537[35] = "unmanaged-free<by-val<thread-args>>";
char constantarr_0_538[18] = "ptr-cast<nat8, ?t>";
char constantarr_0_539[8] = "?<int32>";
char constantarr_0_540[25] = "any-unhandled-exceptions?";
char constantarr_0_541[4] = "main";
char constantarr_0_542[15] = "sort-unique<?t>";
char constantarr_0_543[11] = "unique!<?t>";
char constantarr_0_544[8] = "each<?t>";
char constantarr_0_545[19] = "subscript<void, ?t>";
char constantarr_0_546[9] = "first<?t>";
char constantarr_0_547[6] = "!=<?t>";
char constantarr_0_548[8] = "last<?t>";
char constantarr_0_549[6] = "~=<?t>";
char constantarr_0_550[18] = "incr-capacity!<?t>";
char constantarr_0_551[19] = "ensure-capacity<?t>";
char constantarr_0_552[25] = "increase-capacity-to!<?t>";
char constantarr_0_553[15] = "set-backing<?t>";
char constantarr_0_554[21] = "set-zero-elements<?t>";
char constantarr_0_555[24] = "round-up-to-power-of-two";
char constantarr_0_556[30] = "round-up-to-power-of-two-recur";
char constantarr_0_557[1] = "*";
char constantarr_0_558[1] = "/";
char constantarr_0_559[4] = "incr";
char constantarr_0_560[7] = "max-nat";
char constantarr_0_561[19] = "unique!<?t>.lambda0";
char constantarr_0_562[16] = "move-to-arr!<?t>";
char constantarr_0_563[8] = "sort<?t>";
char constantarr_0_564[16] = "make-mut-arr<?t>";
char constantarr_0_565[29] = "new-uninitialized-mut-arr<?t>";
char constantarr_0_566[19] = "mut-arr<?t>.lambda0";
char constantarr_0_567[9] = "sort!<?t>";
char constantarr_0_568[8] = "swap<?t>";
char constantarr_0_569[17] = "set-subscript<?t>";
char constantarr_0_570[16] = "noctx-set-at<?t>";
char constantarr_0_571[19] = "partition-recur<?t>";
char constantarr_0_572[5] = "<<?t>";
char constantarr_0_573[18] = "cast-immutable<?t>";
char constantarr_0_574[3] = "mod";
char constantarr_0_575[10] = "unsafe-mod";
char constantarr_0_576[15] = "size<arr<char>>";
char constantarr_0_577[10] = "values<?t>";
char constantarr_0_578[20] = "subscript<arr<char>>";
char constantarr_0_579[8] = "has?<?t>";
char constantarr_0_580[12] = "~<arr<char>>";
char constantarr_0_581[10] = "union!<?t>";
char constantarr_0_582[20] = "intersect<arr<char>>";
char constantarr_0_583[14] = "intersect!<?t>";
char constantarr_0_584[12] = "-<arr<char>>";
char constantarr_0_585[13] = "subtract!<?t>";
char constantarr_0_586[14] = "~=<?t>.lambda0";
char constantarr_0_587[18] = "mut-set<arr<char>>";
char constantarr_0_588[11] = "mut-set<?t>";
char constantarr_0_589[18] = "remove!<arr<char>>";
char constantarr_0_590[11] = "remove!<?t>";
char constantarr_0_591[14] = "remove-at!<?t>";
char constantarr_0_592[7] = "memmove";
char constantarr_0_593[13] = "~=<arr<char>>";
char constantarr_0_594[10] = "drop<bool>";
char constantarr_0_595[8] = "add!<?t>";
char constantarr_0_596[14] = "insert-at!<?t>";
char constantarr_0_597[21] = "~=<arr<char>>.lambda0";
char constantarr_0_598[23] = "move-to-set!<arr<char>>";
char constantarr_0_599[13] = "resolved<nat>";
struct arr_0 constantarr_1_0[4] = {{5, constantarr_0_10}, {6, constantarr_0_11}, {5, constantarr_0_12}, {5, constantarr_0_10}};
struct arr_0 constantarr_1_1[3] = {{6, constantarr_0_11}, {5, constantarr_0_12}, {12, constantarr_0_29}};
struct arr_0 constantarr_1_2[3] = {{5, constantarr_0_10}, {6, constantarr_0_11}, {5, constantarr_0_12}};
struct arr_0 constantarr_1_3[2] = {{12, constantarr_0_29}, {5, constantarr_0_36}};
uint8_t mark(struct mark_ctx* ctx, uint8_t* ptr_any, uint64_t size_bytes);
uint64_t words_of_bytes(uint64_t size_bytes);
uint64_t round_up_to_multiple_of_8(uint64_t n);
struct void_ hard_assert(uint8_t condition);
uint8_t not(uint8_t a);
extern void abort(void);
uint8_t _equal_0(uint64_t a, uint64_t b);
struct comparison compare_7(uint64_t a, uint64_t b);
uint64_t _minus_0(uint64_t* a, uint64_t* b);
uint8_t _less_0(uint64_t a, uint64_t b);
uint8_t _lessOrEqual(uint64_t a, uint64_t b);
uint8_t mark_range_recur(uint8_t marked_anything__q, uint8_t* cur, uint8_t* end);
uint8_t* incr_0(uint8_t* p);
uint8_t _greater(uint64_t a, uint64_t b);
int32_t rt_main(int32_t argc, char** argv, fun_ptr2 main_ptr);
extern uint64_t get_nprocs(void);
struct lock new_lock(void);
struct _atomic_bool new_atomic_bool(void);
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
uint8_t _notEqual_0(int64_t a, int64_t b);
uint8_t _equal_1(int64_t a, int64_t b);
struct comparison compare_37(int64_t a, int64_t b);
struct void_ todo_0(void);
int32_t stderr(void);
struct void_ print_err(struct arr_0 s);
struct arr_0 show_exception(struct ctx* ctx, struct exception a);
uint8_t empty__q_0(struct arr_0 a);
struct arr_0 join(struct ctx* ctx, struct arr_1 a, struct arr_0 joiner);
uint8_t empty__q_1(struct arr_1 a);
struct arr_0 subscript_0(struct ctx* ctx, struct arr_1 a, uint64_t index);
struct void_ assert(struct ctx* ctx, uint8_t condition);
struct void_ fail(struct ctx* ctx, struct arr_0 reason);
struct void_ throw(struct ctx* ctx, struct exception e);
struct exception_ctx* get_exception_ctx(struct ctx* ctx);
uint8_t null__q_1(struct jmp_buf_tag* a);
extern void longjmp(struct jmp_buf_tag* env, int32_t val);
int32_t number_to_throw(struct ctx* ctx);
struct backtrace get_backtrace(struct ctx* ctx);
struct opt_3 try_alloc_backtrace_arrs(struct ctx* ctx);
struct opt_4 try_alloc_uninitialized_0(struct ctx* ctx, uint64_t size);
struct opt_5 try_alloc(struct ctx* ctx, uint64_t size_bytes);
struct opt_5 try_gc_alloc(struct gc* gc, uint64_t size_bytes);
struct void_ validate_gc(struct gc* gc);
uint8_t ptr_less_eq__q_0(uint8_t* a, uint8_t* b);
uint8_t ptr_less_eq__q_1(uint64_t* a, uint64_t* b);
uint64_t _minus_1(uint8_t* a, uint8_t* b);
uint8_t range_free__q(uint8_t* mark, uint8_t* end);
uint64_t* incr_1(uint64_t* p);
struct gc* get_gc(struct ctx* ctx);
struct gc_ctx* get_gc_ctx_0(struct ctx* ctx);
struct opt_6 try_alloc_uninitialized_1(struct ctx* ctx, uint64_t size);
uint64_t funs_count_67(void);
extern int32_t backtrace(uint8_t** array, int32_t size);
uint64_t code_ptrs_size(struct ctx* ctx);
struct void_ fill_fun_ptrs_names_recur(struct ctx* ctx, uint64_t i, uint8_t** fun_ptrs, struct arr_0* fun_names);
uint8_t _notEqual_1(uint64_t a, uint64_t b);
uint8_t* get_fun_ptr_72(uint64_t fun_id);
struct arr_0 get_fun_name_73(uint64_t fun_id);
uint64_t noctx_incr(uint64_t n);
struct void_ sort_together(struct ctx* ctx, uint8_t** a, struct arr_0* b, uint64_t size);
struct void_ swap_0(struct ctx* ctx, uint8_t** a, uint64_t lo, uint64_t hi);
struct void_ swap_1(struct ctx* ctx, struct arr_0* a, uint64_t lo, uint64_t hi);
uint64_t partition_recur_together(struct ctx* ctx, uint8_t** a, struct arr_0* b, uint8_t* pivot, uint64_t l, uint64_t r);
uint64_t noctx_decr(uint64_t n);
struct void_ fill_code_names_recur(struct ctx* ctx, struct arr_0* code_names, struct arr_0* end_code_names, uint8_t** code_ptrs, uint8_t** fun_ptrs, struct arr_0* fun_names);
struct arr_0 get_fun_name(struct ctx* ctx, uint8_t* code_ptr, uint8_t** fun_ptrs, struct arr_0* fun_names, uint64_t size);
uint8_t** incr_2(uint8_t** p);
struct arr_0* incr_3(struct arr_0* p);
struct arr_0 noctx_at_0(struct arr_1 a, uint64_t index);
struct arr_0 _concat_0(struct ctx* ctx, struct arr_0 a, struct arr_0 b);
uint64_t _plus(struct ctx* ctx, uint64_t a, uint64_t b);
uint8_t _greaterOrEqual(uint64_t a, uint64_t b);
char* alloc_uninitialized_0(struct ctx* ctx, uint64_t size);
uint8_t* alloc(struct ctx* ctx, uint64_t size_bytes);
uint8_t* gc_alloc(struct ctx* ctx, struct gc* gc, uint64_t size);
uint8_t* todo_1(void);
struct void_ copy_data_from_0(struct ctx* ctx, char* to, char* from, uint64_t len);
extern void memcpy(uint8_t* dest, uint8_t* src, uint64_t size);
struct arr_1 tail_0(struct ctx* ctx, struct arr_1 a);
struct void_ forbid_0(struct ctx* ctx, uint8_t condition);
struct void_ forbid_1(struct ctx* ctx, uint8_t condition, struct arr_0 message);
struct arr_1 subscript_1(struct ctx* ctx, struct arr_1 a, struct arrow range);
uint64_t _minus_2(struct ctx* ctx, uint64_t a, uint64_t b);
struct arrow _arrow(struct ctx* ctx, uint64_t from, uint64_t to);
struct global_ctx* get_global_ctx(struct ctx* ctx);
struct void_ new_island__lambda0(struct ctx* ctx, struct void_ _closure, struct exception it);
struct void_ default_log_handler(struct ctx* ctx, struct logged* a);
struct void_ print(struct arr_0 a);
struct void_ print_no_newline(struct arr_0 a);
int32_t stdout(void);
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
uint8_t _equal_2(int32_t a, int32_t b);
struct comparison compare_124(int32_t a, int32_t b);
struct void_ release_lock(struct lock* l);
struct void_ must_unset(struct _atomic_bool* a);
uint8_t try_unset(struct _atomic_bool* a);
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb);
struct fut_0* then(struct ctx* ctx, struct fut_1* f, struct fun_ref1 cb);
struct fut_0* new_unresolved_fut(struct ctx* ctx);
struct void_ then_void_0(struct ctx* ctx, struct fut_1* f, struct fun_act1_1 cb);
struct void_ subscript_2(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0);
struct void_ call_w_ctx_134(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0);
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to);
struct void_ then_void_1(struct ctx* ctx, struct fut_0* f, struct fun_act1_0 cb);
struct void_ subscript_3(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0);
struct void_ call_w_ctx_138(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0);
struct void_ resolve_or_reject(struct ctx* ctx, struct fut_0* f, struct result_0 result);
struct void_ resolve_or_reject_recur(struct ctx* ctx, struct opt_0 node, struct result_0 value);
struct void_ drop_0(struct void_ _p0);
struct void_ forward_to__lambda0(struct ctx* ctx, struct forward_to__lambda0* _closure, struct result_0 it);
struct fut_0* subscript_4(struct ctx* ctx, struct fun_ref1 f, struct void_ p0);
struct island* get_island(struct ctx* ctx, uint64_t island_id);
struct island* subscript_5(struct ctx* ctx, struct arr_3 a, uint64_t index);
struct island* noctx_at_1(struct arr_3 a, uint64_t index);
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
struct void_ subscript_6(struct ctx* ctx, struct fun_act0_0 a);
struct void_ call_w_ctx_165(struct fun_act0_0 a, struct ctx* ctx);
struct void_ subscript_7(struct ctx* ctx, struct fun_act1_3 a, struct exception p0);
struct void_ call_w_ctx_167(struct fun_act1_3 a, struct ctx* ctx, struct exception p0);
struct fut_0* subscript_8(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0);
struct fut_0* call_w_ctx_169(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0);
struct void_ subscript_4__lambda0__lambda0(struct ctx* ctx, struct subscript_4__lambda0__lambda0* _closure);
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e);
struct void_ subscript_4__lambda0__lambda1(struct ctx* ctx, struct subscript_4__lambda0__lambda1* _closure, struct exception it);
struct void_ subscript_4__lambda0(struct ctx* ctx, struct subscript_4__lambda0* _closure);
struct void_ then__lambda0(struct ctx* ctx, struct then__lambda0* _closure, struct result_1 result);
struct fut_0* subscript_9(struct ctx* ctx, struct fun_ref0 f);
struct fut_0* subscript_10(struct ctx* ctx, struct fun_act0_1 a);
struct fut_0* call_w_ctx_177(struct fun_act0_1 a, struct ctx* ctx);
struct void_ subscript_9__lambda0__lambda0(struct ctx* ctx, struct subscript_9__lambda0__lambda0* _closure);
struct void_ subscript_9__lambda0__lambda1(struct ctx* ctx, struct subscript_9__lambda0__lambda1* _closure, struct exception it);
struct void_ subscript_9__lambda0(struct ctx* ctx, struct subscript_9__lambda0* _closure);
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore);
struct island_and_exclusion cur_island_and_exclusion(struct ctx* ctx);
struct fut_1* delay(struct ctx* ctx);
struct fut_1* resolved_0(struct ctx* ctx, struct void_ value);
struct arr_4 tail_1(struct ctx* ctx, struct arr_4 a);
uint8_t empty__q_2(struct arr_4 a);
struct arr_4 subscript_11(struct ctx* ctx, struct arr_4 a, struct arrow range);
struct arr_1 map(struct ctx* ctx, struct arr_4 a, struct fun_act1_4 mapper);
struct arr_1 make_arr(struct ctx* ctx, uint64_t size, struct fun_act1_5 f);
struct arr_0* alloc_uninitialized_1(struct ctx* ctx, uint64_t size);
struct void_ fill_ptr_range(struct ctx* ctx, struct arr_0* begin, uint64_t size, struct fun_act1_5 f);
struct void_ fill_ptr_range_recur(struct ctx* ctx, struct arr_0* begin, uint64_t i, uint64_t size, struct fun_act1_5 f);
struct arr_0 subscript_12(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0);
struct arr_0 call_w_ctx_194(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0);
struct arr_0 subscript_13(struct ctx* ctx, struct fun_act1_4 a, char* p0);
struct arr_0 call_w_ctx_196(struct fun_act1_4 a, struct ctx* ctx, char* p0);
char* subscript_14(struct ctx* ctx, struct arr_4 a, uint64_t index);
char* noctx_at_2(struct arr_4 a, uint64_t index);
struct arr_0 map__lambda0(struct ctx* ctx, struct map__lambda0* _closure, uint64_t i);
struct arr_0 to_str_1(char* a);
struct arr_0 arr_from_begin_end(char* begin, char* end);
uint64_t _minus_3(char* a, char* b);
char* find_cstr_end(char* a);
char* find_char_in_cstr(char* a, char c);
uint8_t _equal_3(char a, char b);
struct comparison compare_206(char a, char b);
char* todo_2(void);
char* incr_4(char* p);
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it);
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure);
struct void_ handle_exceptions(struct ctx* ctx, struct fut_0* a);
struct void_ subscript_15(struct ctx* ctx, struct fun1_0 a, struct exception p0);
struct void_ call_w_ctx_213(struct fun1_0 a, struct ctx* ctx, struct exception p0);
struct fun1_0 exception_handler(struct ctx* ctx, struct island* a);
struct island* get_cur_island(struct ctx* ctx);
struct void_ handle_exceptions__lambda0(struct ctx* ctx, struct void_ _closure, struct result_0 result);
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* call_w_ctx_218(struct fun_act2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1);
struct void_ run_threads(uint64_t n_threads, struct global_ctx* gctx);
struct thread_args* unmanaged_alloc_elements_1(uint64_t size_elements);
struct void_ start_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads, struct thread_args* thread_args_begin, struct global_ctx* gctx);
struct void_ create_one_thread(struct cell_0* tid, uint8_t* thread_arg, fun_ptr1 thread_fun);
extern int32_t pthread_create(struct cell_0* thread, uint8_t* attr, fun_ptr1 start_routine, uint8_t* arg);
uint8_t _notEqual_2(int32_t a, int32_t b);
int32_t eagain(void);
struct cell_0* as_cell(uint64_t* p);
uint8_t* thread_fun(uint8_t* args_ptr);
struct void_ thread_function(uint64_t thread_id, struct global_ctx* gctx);
struct void_ thread_function_recur(uint64_t thread_id, struct global_ctx* gctx, struct thread_local_stuff* tls);
struct void_ assert_islands_are_shut_down(uint64_t i, struct arr_3 islands);
uint8_t empty__q_3(struct task_queue* a);
uint8_t has__q_0(struct opt_2 a);
uint8_t empty__q_4(struct opt_2 a);
uint64_t get_last_checked(struct condition* c);
struct choose_task_result choose_task(struct global_ctx* gctx);
uint64_t get_monotime_nsec(void);
extern int32_t clock_gettime(int32_t clock_id, struct cell_1* timespec);
int32_t clock_monotonic(void);
struct timespec get_0(struct cell_1* c);
uint64_t todo_3(void);
struct choose_task_result choose_task_recur(struct arr_3 islands, uint64_t i, uint64_t cur_time, uint8_t any_tasks__q, struct opt_8 first_task_time);
struct choose_task_in_island_result choose_task_in_island(struct island* island, uint64_t cur_time);
struct pop_task_result pop_task(struct task_queue* a, uint64_t cur_time);
uint8_t contains__q_0(struct mut_list_0* a, uint64_t value);
uint8_t contains__q_1(struct arr_2 a, uint64_t value);
uint8_t contains_recur__q(struct arr_2 a, uint64_t value, uint64_t i);
uint64_t noctx_at_3(struct arr_2 a, uint64_t index);
struct arr_2 temp_as_arr_0(struct mut_list_0* a);
struct arr_2 temp_as_arr_1(struct mut_arr_0 a);
struct mut_arr_0 temp_as_mut_arr(struct mut_list_0* a);
uint64_t* data_0(struct mut_list_0* a);
uint64_t* data_1(struct mut_arr_0 a);
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list_0* exclusions, uint64_t cur_time, struct opt_8 first_task_time);
struct opt_8 to_opt_time(uint64_t a);
struct void_ push_capacity_must_be_sufficient__e(struct mut_list_0* a, uint64_t value);
uint64_t capacity_0(struct mut_list_0* a);
uint64_t size_1(struct mut_arr_0 a);
struct void_ noctx_set_at__e_0(struct mut_list_0* a, uint64_t index, uint64_t value);
uint8_t is_no_task__q(struct choose_task_in_island_result a);
struct opt_8 min_time(struct opt_8 a, struct opt_8 b);
uint64_t min(uint64_t a, uint64_t b);
struct void_ do_task(struct global_ctx* gctx, struct thread_local_stuff* tls, struct chosen_task chosen_task);
struct void_ return_task(struct task_queue* a, struct task task);
struct void_ noctx_must_remove_unordered__e(struct mut_list_0* a, uint64_t value);
struct void_ noctx_must_remove_unordered_recur__e(struct mut_list_0* a, uint64_t index, uint64_t value);
uint64_t noctx_at_4(struct mut_list_0* a, uint64_t index);
struct void_ drop_1(uint64_t _p0);
uint64_t noctx_remove_unordered_at__e(struct mut_list_0* a, uint64_t index);
uint64_t noctx_last(struct mut_list_0* a);
uint8_t empty__q_5(struct mut_list_0* a);
struct void_ return_ctx(struct ctx* c);
struct void_ return_gc_ctx(struct gc_ctx* gc_ctx);
struct void_ run_garbage_collection(struct gc* gc, struct island_gc_root gc_root);
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct island_gc_root value);
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct task_queue value);
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct opt_2 value);
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct some_2 value);
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct task_queue_node value);
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct task value);
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct fun_act0_0 value);
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct subscript_4__lambda0__lambda0 value);
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct fun_ref1 value);
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct fun_act1_2 value);
struct void_ mark_visit_284(struct mark_ctx* mark_ctx, struct then2__lambda0 value);
struct void_ mark_visit_285(struct mark_ctx* mark_ctx, struct fun_ref0 value);
struct void_ mark_visit_286(struct mark_ctx* mark_ctx, struct fun_act0_1 value);
struct void_ mark_visit_287(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value);
struct void_ mark_arr_288(struct mark_ctx* mark_ctx, struct arr_4 a);
struct void_ mark_visit_289(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value);
struct void_ mark_visit_290(struct mark_ctx* mark_ctx, struct then2__lambda0* value);
struct void_ mark_visit_291(struct mark_ctx* mark_ctx, struct fut_0 value);
struct void_ mark_visit_292(struct mark_ctx* mark_ctx, struct fut_state_0 value);
struct void_ mark_visit_293(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value);
struct void_ mark_visit_294(struct mark_ctx* mark_ctx, struct opt_0 value);
struct void_ mark_visit_295(struct mark_ctx* mark_ctx, struct some_0 value);
struct void_ mark_visit_296(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value);
struct void_ mark_visit_297(struct mark_ctx* mark_ctx, struct fun_act1_0 value);
struct void_ mark_visit_298(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value);
struct void_ mark_visit_299(struct mark_ctx* mark_ctx, struct fut_0* value);
struct void_ mark_visit_300(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value);
struct void_ mark_visit_301(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value);
struct void_ mark_visit_302(struct mark_ctx* mark_ctx, struct exception value);
struct void_ mark_arr_303(struct mark_ctx* mark_ctx, struct arr_0 a);
struct void_ mark_visit_304(struct mark_ctx* mark_ctx, struct backtrace value);
struct void_ mark_elems_305(struct mark_ctx* mark_ctx, struct arr_0* cur, struct arr_0* end);
struct void_ mark_arr_306(struct mark_ctx* mark_ctx, struct arr_1 a);
struct void_ mark_visit_307(struct mark_ctx* mark_ctx, struct subscript_4__lambda0__lambda0* value);
struct void_ mark_visit_308(struct mark_ctx* mark_ctx, struct subscript_4__lambda0 value);
struct void_ mark_visit_309(struct mark_ctx* mark_ctx, struct subscript_4__lambda0* value);
struct void_ mark_visit_310(struct mark_ctx* mark_ctx, struct subscript_9__lambda0__lambda0 value);
struct void_ mark_visit_311(struct mark_ctx* mark_ctx, struct subscript_9__lambda0__lambda0* value);
struct void_ mark_visit_312(struct mark_ctx* mark_ctx, struct subscript_9__lambda0 value);
struct void_ mark_visit_313(struct mark_ctx* mark_ctx, struct subscript_9__lambda0* value);
struct void_ mark_visit_314(struct mark_ctx* mark_ctx, struct task_queue_node* value);
struct void_ mark_visit_315(struct mark_ctx* mark_ctx, struct mut_list_0 value);
struct void_ mark_visit_316(struct mark_ctx* mark_ctx, struct mut_arr_0 value);
struct void_ mark_arr_317(struct mark_ctx* mark_ctx, struct arr_2 a);
struct void_ clear_free_mem(uint8_t* mark_ptr, uint8_t* mark_end, uint64_t* data_ptr);
struct void_ wait_on(struct condition* cond, struct opt_8 until_time, uint64_t last_checked);
uint8_t before_time__q(struct opt_8 until_time);
struct void_ join_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads);
struct void_ join_one_thread(uint64_t tid);
extern int32_t pthread_join(uint64_t thread, struct cell_2* thread_return);
int32_t einval(void);
int32_t esrch(void);
uint8_t* get_1(struct cell_2* c);
struct void_ unmanaged_free_0(uint64_t* p);
extern void free(uint8_t* p);
struct void_ unmanaged_free_1(struct thread_args* p);
struct fut_0* main_0(struct ctx* ctx, struct arr_1 _p0);
struct set* set(struct ctx* ctx, struct arr_1 a);
struct arr_1 sort_unique(struct ctx* ctx, struct arr_1 a);
struct arr_1 unique__e(struct ctx* ctx, struct arr_1 a);
struct mut_list_1* mut_list_0(struct ctx* ctx);
struct mut_arr_1 mut_arr_1(void);
struct void_ each(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 f);
struct void_ subscript_16(struct ctx* ctx, struct fun_act1_6 a, struct arr_0 p0);
struct void_ call_w_ctx_338(struct fun_act1_6 a, struct ctx* ctx, struct arr_0 p0);
struct arr_0 first(struct ctx* ctx, struct arr_1 a);
uint8_t empty__q_6(struct mut_list_1* a);
uint8_t _notEqual_3(struct arr_0 a, struct arr_0 b);
uint8_t _equal_4(struct arr_0 a, struct arr_0 b);
struct comparison compare_343(struct arr_0 a, struct arr_0 b);
struct arr_0 last(struct ctx* ctx, struct mut_list_1* a);
struct arr_0 subscript_17(struct ctx* ctx, struct mut_list_1* a, uint64_t index);
struct arr_0 noctx_at_5(struct mut_list_1* a, uint64_t index);
struct arr_0* data_2(struct mut_list_1* a);
struct arr_0* data_3(struct mut_arr_1 a);
struct void_ _concatEquals_0(struct ctx* ctx, struct mut_list_1* a, struct arr_0 value);
struct void_ incr_capacity__e(struct ctx* ctx, struct mut_list_1* a);
struct void_ ensure_capacity(struct ctx* ctx, struct mut_list_1* a, uint64_t min_capacity);
uint64_t capacity_1(struct mut_list_1* a);
uint64_t size_2(struct mut_arr_1 a);
struct void_ increase_capacity_to__e(struct ctx* ctx, struct mut_list_1* a, uint64_t new_capacity);
struct mut_arr_1 mut_arr_2(uint64_t size, struct arr_0* data);
struct void_ copy_data_from_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len);
struct void_ set_zero_elements(struct mut_arr_1 a);
struct void_ set_zero_range_1(struct arr_0* begin, uint64_t size);
struct mut_arr_1 subscript_18(struct ctx* ctx, struct mut_arr_1 a, struct arrow range);
uint64_t round_up_to_power_of_two(struct ctx* ctx, uint64_t n);
uint64_t round_up_to_power_of_two_recur(struct ctx* ctx, uint64_t acc, uint64_t n);
uint64_t _times(struct ctx* ctx, uint64_t a, uint64_t b);
uint64_t _divide(struct ctx* ctx, uint64_t a, uint64_t b);
uint64_t incr_5(struct ctx* ctx, uint64_t n);
uint64_t max_nat(void);
struct void_ unique__e__lambda0(struct ctx* ctx, struct unique__e__lambda0* _closure, struct arr_0 x);
struct arr_1 move_to_arr__e(struct mut_list_1* a);
struct arr_1 sort(struct ctx* ctx, struct arr_1 a);
struct mut_arr_1 mut_arr_3(struct ctx* ctx, struct arr_1 a);
struct mut_arr_1 make_mut_arr(struct ctx* ctx, uint64_t size, struct fun_act1_5 f);
struct mut_arr_1 new_uninitialized_mut_arr(struct ctx* ctx, uint64_t size);
struct arr_0 mut_arr_3__lambda0(struct ctx* ctx, struct mut_arr_3__lambda0* _closure, uint64_t it);
struct void_ sort__e(struct ctx* ctx, struct mut_arr_1 a);
struct void_ swap_2(struct ctx* ctx, struct mut_arr_1 a, uint64_t x, uint64_t y);
struct arr_0 subscript_19(struct ctx* ctx, struct mut_arr_1 a, uint64_t index);
struct void_ set_subscript_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t index, struct arr_0 value);
struct void_ noctx_set_at(struct mut_arr_1 a, uint64_t index, struct arr_0 value);
uint64_t partition_recur(struct ctx* ctx, struct mut_arr_1 a, struct arr_0 pivot, uint64_t l, uint64_t r);
uint8_t _less_1(struct arr_0 a, struct arr_0 b);
struct arr_1 cast_immutable(struct mut_arr_1 a);
struct arr_0 to_str_2(struct ctx* ctx, uint64_t n);
uint64_t mod(struct ctx* ctx, uint64_t a, uint64_t b);
uint64_t size_3(struct ctx* ctx, struct set* a);
struct arr_0 to_str_3(uint8_t b);
uint8_t subscript_20(struct ctx* ctx, struct set* a, struct arr_0 value);
uint8_t has__q_1(struct ctx* ctx, struct arr_1 a, struct arr_0 value);
struct arr_1 arr(struct ctx* ctx, struct set* a);
struct set* _concat_1(struct ctx* ctx, struct set* a, struct set* b);
struct void_ union__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b);
struct set* intersect(struct ctx* ctx, struct set* a, struct set* b);
struct void_ intersect__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b);
struct set* _minus_4(struct ctx* ctx, struct set* a, struct set* b);
struct void_ subtract__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b);
struct void_ _concatEquals_1(struct ctx* ctx, struct mut_list_1* a, struct arr_1 values);
struct void_ _concatEquals_1__lambda0(struct ctx* ctx, struct _concatEquals_1__lambda0* _closure, struct arr_0 it);
struct mut_set mut_set(struct ctx* ctx, struct arr_1 a);
struct mut_list_1* mut_list_1(struct ctx* ctx, struct arr_1 a);
uint8_t subscript_21(struct ctx* ctx, struct mut_set a, struct arr_0 value);
uint8_t has__q_2(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value);
uint8_t remove__e_0(struct ctx* ctx, struct mut_set a, struct arr_0 value);
uint8_t remove__e_1(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value);
struct void_ drop_2(struct arr_0 _p0);
struct arr_0 remove_at__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index);
extern void memmove(uint8_t* dest, uint8_t* src, uint64_t size);
struct void_ _concatEquals_2(struct ctx* ctx, struct mut_set a, struct arr_1 values);
struct void_ _concatEquals_3(struct ctx* ctx, struct mut_set a, struct arr_0 value);
struct void_ drop_3(uint8_t _p0);
uint8_t add__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value);
struct void_ insert_at__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value);
struct void_ set_subscript_1(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value);
struct void_ noctx_set_at__e_1(struct mut_list_1* a, uint64_t index, struct arr_0 value);
struct void_ _concatEquals_2__lambda0(struct ctx* ctx, struct _concatEquals_2__lambda0* _closure, struct arr_0 value);
struct set* move_to_set__e(struct ctx* ctx, struct mut_set a);
struct fut_0* resolved_1(struct ctx* ctx, uint64_t value);
int32_t main(int32_t argc, char** argv);
/* mark bool(ctx mark-ctx, ptr-any ptr<nat8>, size-bytes nat) */
uint8_t mark(struct mark_ctx* ctx, uint8_t* ptr_any, uint64_t size_bytes) {
	uint64_t size_words0;
	size_words0 = words_of_bytes(size_bytes);
	
	uint64_t* ptr1;
	ptr1 = (uint64_t*) ptr_any;
	
	uint8_t _0 = _equal_0(((uint64_t) ptr1 & 7u), 0u);
	hard_assert(_0);
	uint64_t index2;
	index2 = _minus_0(ptr1, ctx->memory_start);
	
	uint8_t gc_memory__q3;
	gc_memory__q3 = _less_0(index2, ctx->memory_size_words);
	
	uint8_t _1 = gc_memory__q3;
	if (_1) {
		uint8_t _2 = _lessOrEqual((index2 + size_words0), ctx->memory_size_words);
		hard_assert(_2);
		uint8_t* mark_start4;
		mark_start4 = (ctx->marks + index2);
		
		uint8_t* mark_end5;
		mark_end5 = (mark_start4 + size_words0);
		
		return mark_range_recur(0, mark_start4, mark_end5);
	} else {
		uint8_t _3 = _greater((index2 + size_words0), ctx->memory_size_words);
		hard_assert(_3);
		return 0;
	}
}
/* words-of-bytes nat(size-bytes nat) */
uint64_t words_of_bytes(uint64_t size_bytes) {
	uint64_t _0 = round_up_to_multiple_of_8(size_bytes);
	return (_0 / 8u);
}
/* round-up-to-multiple-of-8 nat(n nat) */
uint64_t round_up_to_multiple_of_8(uint64_t n) {
	return ((n + 7u) & ~7u);
}
/* hard-assert void(condition bool) */
struct void_ hard_assert(uint8_t condition) {
	uint8_t _0 = not(condition);
	if (_0) {
		return (abort(), (struct void_) {});
	} else {
		return (struct void_) {};
	}
}
/* not bool(a bool) */
uint8_t not(uint8_t a) {
	uint8_t _0 = a;
	if (_0) {
		return 0;
	} else {
		return 1;
	}
}
/* ==<nat> bool(a nat, b nat) */
uint8_t _equal_0(uint64_t a, uint64_t b) {
	struct comparison _0 = compare_7(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* compare<nat-64> (generated) (generated) */
struct comparison compare_7(uint64_t a, uint64_t b) {
	uint8_t _0 = (a < b);
	if (_0) {
		return (struct comparison) {0, .as0 = (struct less) {}};
	} else {
		uint8_t _1 = (b < a);
		if (_1) {
			return (struct comparison) {2, .as2 = (struct greater) {}};
		} else {
			return (struct comparison) {1, .as1 = (struct equal) {}};
		}
	}
}
/* -<nat> nat(a ptr<nat>, b ptr<nat>) */
uint64_t _minus_0(uint64_t* a, uint64_t* b) {
	return (((uint64_t) a - (uint64_t) b) / sizeof(uint64_t));
}
/* <<nat> bool(a nat, b nat) */
uint8_t _less_0(uint64_t a, uint64_t b) {
	struct comparison _0 = compare_7(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* <=<nat> bool(a nat, b nat) */
uint8_t _lessOrEqual(uint64_t a, uint64_t b) {
	uint8_t _0 = _less_0(b, a);
	return not(_0);
}
/* mark-range-recur bool(marked-anything? bool, cur ptr<bool>, end ptr<bool>) */
uint8_t mark_range_recur(uint8_t marked_anything__q, uint8_t* cur, uint8_t* end) {
	top:;
	uint8_t _0 = (cur == end);
	if (_0) {
		return marked_anything__q;
	} else {
		uint8_t new_marked_anything__q0;
		if (marked_anything__q) {
			new_marked_anything__q0 = 1;
		} else {
			new_marked_anything__q0 = not(*cur);
		}
		
		*cur = 1;
		uint8_t* _1 = incr_0(cur);
		marked_anything__q = new_marked_anything__q0;
		cur = _1;
		end = end;
		goto top;
	}
}
/* incr<bool> ptr<bool>(p ptr<bool>) */
uint8_t* incr_0(uint8_t* p) {
	return (p + 1u);
}
/* ><nat> bool(a nat, b nat) */
uint8_t _greater(uint64_t a, uint64_t b) {
	return _less_0(b, a);
}
/* rt-main int32(argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<nat>, ctx, arr<arr<char>>>) */
int32_t rt_main(int32_t argc, char** argv, fun_ptr2 main_ptr) {
	uint64_t n_threads0;
	n_threads0 = get_nprocs();
	
	struct global_ctx gctx_by_val1;
	struct lock _0 = new_lock();
	struct condition _1 = new_condition();
	gctx_by_val1 = (struct global_ctx) {_0, (struct arr_3) {0u, NULL}, n_threads0, _1, 0, 0};
	
	struct global_ctx* gctx2;
	gctx2 = (&gctx_by_val1);
	
	struct island island_by_val3;
	island_by_val3 = new_island(gctx2, 0u, n_threads0);
	
	struct island* island4;
	island4 = (&island_by_val3);
	
	gctx2->islands = (struct arr_3) {1u, (&island4)};
	struct fut_0* main_fut5;
	main_fut5 = do_main(gctx2, island4, argc, argv, main_ptr);
	
	run_threads(n_threads0, gctx2);
	struct fut_state_0 _2 = main_fut5->state;
	switch (_2.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			struct fut_state_resolved_0 r6 = _2.as1;
			
			uint8_t _3 = gctx2->any_unhandled_exceptions__q;
			if (_3) {
				return 1;
			} else {
				return (int32_t) (int64_t) r6.value;
			}
		}
		case 2: {
			return 1;
		}
		default:
			return 0;
	}
}
/* new-lock lock() */
struct lock new_lock(void) {
	struct _atomic_bool _0 = new_atomic_bool();
	return (struct lock) {_0};
}
/* new-atomic-bool atomic-bool() */
struct _atomic_bool new_atomic_bool(void) {
	return (struct _atomic_bool) {0};
}
/* new-condition condition() */
struct condition new_condition(void) {
	struct lock _0 = new_lock();
	return (struct condition) {_0, 0u};
}
/* new-island island(gctx global-ctx, id nat, max-threads nat) */
struct island new_island(struct global_ctx* gctx, uint64_t id, uint64_t max_threads) {
	struct task_queue q0;
	q0 = new_task_queue(max_threads);
	
	struct island_gc_root gc_root1;
	gc_root1 = (struct island_gc_root) {q0, (struct fun1_0) {0, .as0 = (struct void_) {}}, (struct fun1_1) {0, .as0 = (struct void_) {}}};
	
	struct gc _0 = new_gc();
	struct lock _1 = new_lock();
	struct thread_safe_counter _2 = new_thread_safe_counter_0();
	return (struct island) {gctx, id, _0, gc_root1, _1, 0u, _2};
}
/* new-task-queue task-queue(max-threads nat) */
struct task_queue new_task_queue(uint64_t max_threads) {
	struct mut_list_0 _0 = new_mut_list_by_val_with_capacity_from_unmanaged_memory(max_threads);
	return (struct task_queue) {(struct opt_2) {0, .as0 = (struct none) {}}, _0};
}
/* new-mut-list-by-val-with-capacity-from-unmanaged-memory<nat> mut-list<nat>(capacity nat) */
struct mut_list_0 new_mut_list_by_val_with_capacity_from_unmanaged_memory(uint64_t capacity) {
	struct mut_arr_0 backing0;
	uint64_t* _0 = unmanaged_alloc_zeroed_elements(capacity);
	backing0 = mut_arr_0(capacity, _0);
	
	return (struct mut_list_0) {backing0, 0u};
}
/* mut-arr<?t> mut-arr<nat>(size nat, data ptr<nat>) */
struct mut_arr_0 mut_arr_0(uint64_t size, uint64_t* data) {
	return (struct mut_arr_0) {(struct void_) {}, (struct arr_2) {size, data}};
}
/* unmanaged-alloc-zeroed-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_zeroed_elements(uint64_t size_elements) {
	uint64_t* res0;
	res0 = unmanaged_alloc_elements_0(size_elements);
	
	set_zero_range_0(res0, size_elements);
	return res0;
}
/* unmanaged-alloc-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_elements_0(uint64_t size_elements) {
	uint8_t* _0 = unmanaged_alloc_bytes((size_elements * sizeof(uint64_t)));
	return (uint64_t*) _0;
}
/* unmanaged-alloc-bytes ptr<nat8>(size nat) */
uint8_t* unmanaged_alloc_bytes(uint64_t size) {
	uint8_t* res0;
	res0 = malloc(size);
	
	uint8_t _0 = null__q_0(res0);
	hard_forbid(_0);
	return res0;
}
/* hard-forbid void(condition bool) */
struct void_ hard_forbid(uint8_t condition) {
	uint8_t _0 = not(condition);
	return hard_assert(_0);
}
/* null?<nat8> bool(a ptr<nat8>) */
uint8_t null__q_0(uint8_t* a) {
	return _equal_0((uint64_t) a, (uint64_t) NULL);
}
/* set-zero-range<?t> void(begin ptr<nat>, size nat) */
struct void_ set_zero_range_0(uint64_t* begin, uint64_t size) {
	return (memset((uint8_t*) begin, 0u, (size * sizeof(uint64_t))), (struct void_) {});
}
/* default-exception-handler void(e exception) */
struct void_ default_exception_handler(struct ctx* ctx, struct exception e) {
	print_err_no_newline((struct arr_0) {20, constantarr_0_0});
	struct arr_0 _0 = show_exception(ctx, e);
	print_err(_0);
	struct global_ctx* _1 = get_global_ctx(ctx);
	return (_1->any_unhandled_exceptions__q = 1, (struct void_) {});
}
/* print-err-no-newline void(s arr<char>) */
struct void_ print_err_no_newline(struct arr_0 s) {
	int32_t _0 = stderr();
	return write_no_newline(_0, s);
}
/* write-no-newline void(fd int32, a arr<char>) */
struct void_ write_no_newline(int32_t fd, struct arr_0 a) {
	uint8_t _0 = _equal_0(sizeof(char), sizeof(uint8_t));
	hard_assert(_0);
	int64_t res0;
	res0 = write(fd, (uint8_t*) a.data, a.size);
	
	uint8_t _1 = _notEqual_0(res0, (int64_t) a.size);
	if (_1) {
		return todo_0();
	} else {
		return (struct void_) {};
	}
}
/* !=<int> bool(a int, b int) */
uint8_t _notEqual_0(int64_t a, int64_t b) {
	uint8_t _0 = _equal_1(a, b);
	return not(_0);
}
/* ==<?t> bool(a int, b int) */
uint8_t _equal_1(int64_t a, int64_t b) {
	struct comparison _0 = compare_37(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* compare<int-64> (generated) (generated) */
struct comparison compare_37(int64_t a, int64_t b) {
	uint8_t _0 = (a < b);
	if (_0) {
		return (struct comparison) {0, .as0 = (struct less) {}};
	} else {
		uint8_t _1 = (b < a);
		if (_1) {
			return (struct comparison) {2, .as2 = (struct greater) {}};
		} else {
			return (struct comparison) {1, .as1 = (struct equal) {}};
		}
	}
}
/* todo<void> void() */
struct void_ todo_0(void) {
	(abort(), (struct void_) {});
	return (struct void_) {};
}
/* stderr int32() */
int32_t stderr(void) {
	return 2;
}
/* print-err void(s arr<char>) */
struct void_ print_err(struct arr_0 s) {
	print_err_no_newline(s);
	return print_err_no_newline((struct arr_0) {1, constantarr_0_1});
}
/* show-exception arr<char>(a exception) */
struct arr_0 show_exception(struct ctx* ctx, struct exception a) {
	struct arr_0 msg0;
	uint8_t _0 = empty__q_0(a.message);
	if (_0) {
		msg0 = (struct arr_0) {17, constantarr_0_2};
	} else {
		msg0 = a.message;
	}
	
	struct arr_0 bt1;
	bt1 = join(ctx, a.backtrace.return_stack, (struct arr_0) {5, constantarr_0_6});
	
	struct arr_0 _1 = _concat_0(ctx, msg0, (struct arr_0) {5, constantarr_0_6});
	return _concat_0(ctx, _1, bt1);
}
/* empty?<char> bool(a arr<char>) */
uint8_t empty__q_0(struct arr_0 a) {
	return _equal_0(a.size, 0u);
}
/* join<char> arr<char>(a arr<arr<char>>, joiner arr<char>) */
struct arr_0 join(struct ctx* ctx, struct arr_1 a, struct arr_0 joiner) {
	uint8_t _0 = empty__q_1(a);
	if (_0) {
		return (struct arr_0) {0u, NULL};
	} else {
		uint8_t _1 = _equal_0(a.size, 1u);
		if (_1) {
			return subscript_0(ctx, a, 0u);
		} else {
			struct arr_0 _2 = subscript_0(ctx, a, 0u);
			struct arr_0 _3 = _concat_0(ctx, _2, joiner);
			struct arr_1 _4 = tail_0(ctx, a);
			struct arr_0 _5 = join(ctx, _4, joiner);
			return _concat_0(ctx, _3, _5);
		}
	}
}
/* empty?<arr<?t>> bool(a arr<arr<char>>) */
uint8_t empty__q_1(struct arr_1 a) {
	return _equal_0(a.size, 0u);
}
/* subscript<arr<?t>> arr<char>(a arr<arr<char>>, index nat) */
struct arr_0 subscript_0(struct ctx* ctx, struct arr_1 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	assert(ctx, _0);
	return noctx_at_0(a, index);
}
/* assert void(condition bool) */
struct void_ assert(struct ctx* ctx, uint8_t condition) {
	uint8_t _0 = not(condition);
	if (_0) {
		return fail(ctx, (struct arr_0) {13, constantarr_0_4});
	} else {
		return (struct void_) {};
	}
}
/* fail<void> void(reason arr<char>) */
struct void_ fail(struct ctx* ctx, struct arr_0 reason) {
	struct backtrace _0 = get_backtrace(ctx);
	return throw(ctx, (struct exception) {reason, _0});
}
/* throw<?t> void(e exception) */
struct void_ throw(struct ctx* ctx, struct exception e) {
	struct exception_ctx* exn_ctx0;
	exn_ctx0 = get_exception_ctx(ctx);
	
	uint8_t _0 = null__q_1(exn_ctx0->jmp_buf_ptr);
	hard_forbid(_0);
	exn_ctx0->thrown_exception = e;
	int32_t _1 = number_to_throw(ctx);
	(longjmp(exn_ctx0->jmp_buf_ptr, _1), (struct void_) {});
	return todo_0();
}
/* get-exception-ctx exception-ctx() */
struct exception_ctx* get_exception_ctx(struct ctx* ctx) {
	return (struct exception_ctx*) ctx->exception_ctx_ptr;
}
/* null?<jmp-buf-tag> bool(a ptr<jmp-buf-tag>) */
uint8_t null__q_1(struct jmp_buf_tag* a) {
	return _equal_0((uint64_t) a, (uint64_t) NULL);
}
/* number-to-throw int32() */
int32_t number_to_throw(struct ctx* ctx) {
	return 7;
}
/* get-backtrace backtrace() */
struct backtrace get_backtrace(struct ctx* ctx) {
	struct opt_3 _0 = try_alloc_backtrace_arrs(ctx);
	switch (_0.kind) {
		case 0: {
			return (struct backtrace) {(struct arr_1) {0u, NULL}};
		}
		case 1: {
			struct some_3 s0 = _0.as1;
			
			struct backtrace_arrs* arrs1;
			arrs1 = s0.value;
			
			uint64_t n_code_ptrs2;
			uint64_t _1 = code_ptrs_size(ctx);
			int32_t _2 = backtrace(arrs1->code_ptrs, (int32_t) (int64_t) _1);
			n_code_ptrs2 = (uint64_t) (int64_t) _2;
			
			uint64_t _3 = code_ptrs_size(ctx);
			uint8_t _4 = _lessOrEqual(n_code_ptrs2, _3);
			hard_assert(_4);
			fill_fun_ptrs_names_recur(ctx, 0u, arrs1->fun_ptrs, arrs1->fun_names);
			uint64_t _5 = funs_count_67();
			sort_together(ctx, arrs1->fun_ptrs, arrs1->fun_names, _5);
			struct arr_0* end_code_names3;
			end_code_names3 = (arrs1->code_names + n_code_ptrs2);
			
			fill_code_names_recur(ctx, arrs1->code_names, end_code_names3, arrs1->code_ptrs, arrs1->fun_ptrs, arrs1->fun_names);
			return (struct backtrace) {(struct arr_1) {n_code_ptrs2, arrs1->code_names}};
		}
		default:
			return (struct backtrace) {(struct arr_1) {0, NULL}};
	}
}
/* try-alloc-backtrace-arrs opt<backtrace-arrs>() */
struct opt_3 try_alloc_backtrace_arrs(struct ctx* ctx) {
	struct opt_4 _0 = try_alloc_uninitialized_0(ctx, 8u);
	switch (_0.kind) {
		case 0: {
			return (struct opt_3) {0, .as0 = (struct none) {}};
		}
		case 1: {
			struct some_4 code_ptrs0 = _0.as1;
			
			struct opt_6 _1 = try_alloc_uninitialized_1(ctx, 8u);
			switch (_1.kind) {
				case 0: {
					return (struct opt_3) {0, .as0 = (struct none) {}};
				}
				case 1: {
					struct some_6 code_names1 = _1.as1;
					
					uint64_t _2 = funs_count_67();
					struct opt_4 _3 = try_alloc_uninitialized_0(ctx, _2);
					switch (_3.kind) {
						case 0: {
							return (struct opt_3) {0, .as0 = (struct none) {}};
						}
						case 1: {
							struct some_4 fun_ptrs2 = _3.as1;
							
							uint64_t _4 = funs_count_67();
							struct opt_6 _5 = try_alloc_uninitialized_1(ctx, _4);
							switch (_5.kind) {
								case 0: {
									return (struct opt_3) {0, .as0 = (struct none) {}};
								}
								case 1: {
									struct some_6 fun_names3 = _5.as1;
									
									struct backtrace_arrs* temp0;
									uint8_t* _6 = alloc(ctx, sizeof(struct backtrace_arrs));
									temp0 = (struct backtrace_arrs*) _6;
									
									*temp0 = (struct backtrace_arrs) {code_ptrs0.value, code_names1.value, fun_ptrs2.value, fun_names3.value};
									return (struct opt_3) {1, .as1 = (struct some_3) {temp0}};
								}
								default:
									return (struct opt_3) {0};
							}
						}
						default:
							return (struct opt_3) {0};
					}
				}
				default:
					return (struct opt_3) {0};
			}
		}
		default:
			return (struct opt_3) {0};
	}
}
/* try-alloc-uninitialized<ptr<nat8>> opt<ptr<ptr<nat8>>>(size nat) */
struct opt_4 try_alloc_uninitialized_0(struct ctx* ctx, uint64_t size) {
	struct opt_5 _0 = try_alloc(ctx, (size * sizeof(uint8_t*)));
	switch (_0.kind) {
		case 0: {
			return (struct opt_4) {0, .as0 = (struct none) {}};
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			return (struct opt_4) {1, .as1 = (struct some_4) {(uint8_t**) s0.value}};
		}
		default:
			return (struct opt_4) {0};
	}
}
/* try-alloc opt<ptr<nat8>>(size-bytes nat) */
struct opt_5 try_alloc(struct ctx* ctx, uint64_t size_bytes) {
	struct gc* _0 = get_gc(ctx);
	return try_gc_alloc(_0, size_bytes);
}
/* try-gc-alloc opt<ptr<nat8>>(gc gc, size-bytes nat) */
struct opt_5 try_gc_alloc(struct gc* gc, uint64_t size_bytes) {
	top:;
	validate_gc(gc);
	uint64_t size_words0;
	size_words0 = words_of_bytes(size_bytes);
	
	uint64_t* cur1;
	cur1 = gc->data_cur;
	
	uint64_t* next2;
	next2 = (cur1 + size_words0);
	
	uint8_t _0 = (next2 < gc->data_end);
	if (_0) {
		uint8_t _1 = range_free__q(gc->mark_cur, (gc->mark_cur + size_words0));
		if (_1) {
			gc->mark_cur = (gc->mark_cur + size_words0);
			gc->data_cur = next2;
			return (struct opt_5) {1, .as1 = (struct some_5) {(uint8_t*) cur1}};
		} else {
			uint8_t* _2 = incr_0(gc->mark_cur);
			gc->mark_cur = _2;
			uint64_t* _3 = incr_1(gc->data_cur);
			gc->data_cur = _3;
			gc = gc;
			size_bytes = size_bytes;
			goto top;
		}
	} else {
		return (struct opt_5) {0, .as0 = (struct none) {}};
	}
}
/* validate-gc void(gc gc) */
struct void_ validate_gc(struct gc* gc) {
	uint8_t _0 = ptr_less_eq__q_0(gc->mark_begin, gc->mark_cur);
	hard_assert(_0);
	uint8_t _1 = ptr_less_eq__q_0(gc->mark_cur, gc->mark_end);
	hard_assert(_1);
	uint8_t _2 = ptr_less_eq__q_1(gc->data_begin, gc->data_cur);
	hard_assert(_2);
	uint8_t _3 = ptr_less_eq__q_1(gc->data_cur, gc->data_end);
	hard_assert(_3);
	uint64_t mark_idx0;
	mark_idx0 = _minus_1(gc->mark_cur, gc->mark_begin);
	
	uint64_t data_idx1;
	data_idx1 = _minus_0(gc->data_cur, gc->data_begin);
	
	uint64_t _4 = _minus_1(gc->mark_end, gc->mark_begin);
	uint8_t _5 = _equal_0(_4, gc->size_words);
	hard_assert(_5);
	uint64_t _6 = _minus_0(gc->data_end, gc->data_begin);
	uint8_t _7 = _equal_0(_6, gc->size_words);
	hard_assert(_7);
	uint8_t _8 = _equal_0(mark_idx0, data_idx1);
	return hard_assert(_8);
}
/* ptr-less-eq?<bool> bool(a ptr<bool>, b ptr<bool>) */
uint8_t ptr_less_eq__q_0(uint8_t* a, uint8_t* b) {
	if ((a < b)) {
		return 1;
	} else {
		return (a == b);
	}
}
/* ptr-less-eq?<nat> bool(a ptr<nat>, b ptr<nat>) */
uint8_t ptr_less_eq__q_1(uint64_t* a, uint64_t* b) {
	if ((a < b)) {
		return 1;
	} else {
		return (a == b);
	}
}
/* -<bool> nat(a ptr<bool>, b ptr<bool>) */
uint64_t _minus_1(uint8_t* a, uint8_t* b) {
	return (((uint64_t) a - (uint64_t) b) / sizeof(uint8_t));
}
/* range-free? bool(mark ptr<bool>, end ptr<bool>) */
uint8_t range_free__q(uint8_t* mark, uint8_t* end) {
	top:;
	uint8_t _0 = (mark == end);
	if (_0) {
		return 1;
	} else {
		uint8_t _1 = *mark;
		if (_1) {
			return 0;
		} else {
			uint8_t* _2 = incr_0(mark);
			mark = _2;
			end = end;
			goto top;
		}
	}
}
/* incr<nat> ptr<nat>(p ptr<nat>) */
uint64_t* incr_1(uint64_t* p) {
	return (p + 1u);
}
/* get-gc gc() */
struct gc* get_gc(struct ctx* ctx) {
	struct gc_ctx* _0 = get_gc_ctx_0(ctx);
	return _0->gc;
}
/* get-gc-ctx gc-ctx() */
struct gc_ctx* get_gc_ctx_0(struct ctx* ctx) {
	return (struct gc_ctx*) ctx->gc_ctx_ptr;
}
/* try-alloc-uninitialized<arr<char>> opt<ptr<arr<char>>>(size nat) */
struct opt_6 try_alloc_uninitialized_1(struct ctx* ctx, uint64_t size) {
	struct opt_5 _0 = try_alloc(ctx, (size * sizeof(struct arr_0)));
	switch (_0.kind) {
		case 0: {
			return (struct opt_6) {0, .as0 = (struct none) {}};
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			return (struct opt_6) {1, .as1 = (struct some_6) {(struct arr_0*) s0.value}};
		}
		default:
			return (struct opt_6) {0};
	}
}
/* funs-count (generated) (generated) */
uint64_t funs_count_67(void) {
	return 415u;
}
/* code-ptrs-size nat() */
uint64_t code_ptrs_size(struct ctx* ctx) {
	return 8u;
}
/* fill-fun-ptrs-names-recur void(i nat, fun-ptrs ptr<ptr<nat8>>, fun-names ptr<arr<char>>) */
struct void_ fill_fun_ptrs_names_recur(struct ctx* ctx, uint64_t i, uint8_t** fun_ptrs, struct arr_0* fun_names) {
	top:;
	uint64_t _0 = funs_count_67();
	uint8_t _1 = _notEqual_1(i, _0);
	if (_1) {
		uint8_t* _2 = get_fun_ptr_72(i);
		*(fun_ptrs + i) = _2;
		struct arr_0 _3 = get_fun_name_73(i);
		*(fun_names + i) = _3;
		uint64_t _4 = noctx_incr(i);
		i = _4;
		fun_ptrs = fun_ptrs;
		fun_names = fun_names;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* !=<nat> bool(a nat, b nat) */
uint8_t _notEqual_1(uint64_t a, uint64_t b) {
	uint8_t _0 = _equal_0(a, b);
	return not(_0);
}
/* get-fun-ptr (generated) (generated) */
uint8_t* get_fun_ptr_72(uint64_t fun_id) {switch (fun_id) {
		case 0: {
			return (uint8_t*) mark;
		}
		case 1: {
			return (uint8_t*) words_of_bytes;
		}
		case 2: {
			return (uint8_t*) round_up_to_multiple_of_8;
		}
		case 3: {
			return (uint8_t*) hard_assert;
		}
		case 4: {
			return (uint8_t*) not;
		}
		case 5: {
			return (uint8_t*) abort;
		}
		case 6: {
			return (uint8_t*) _equal_0;
		}
		case 7: {
			return (uint8_t*) compare_7;
		}
		case 8: {
			return (uint8_t*) _minus_0;
		}
		case 9: {
			return (uint8_t*) _less_0;
		}
		case 10: {
			return (uint8_t*) _lessOrEqual;
		}
		case 11: {
			return (uint8_t*) mark_range_recur;
		}
		case 12: {
			return (uint8_t*) incr_0;
		}
		case 13: {
			return (uint8_t*) _greater;
		}
		case 14: {
			return (uint8_t*) rt_main;
		}
		case 15: {
			return (uint8_t*) get_nprocs;
		}
		case 16: {
			return (uint8_t*) new_lock;
		}
		case 17: {
			return (uint8_t*) new_atomic_bool;
		}
		case 18: {
			return (uint8_t*) new_condition;
		}
		case 19: {
			return (uint8_t*) new_island;
		}
		case 20: {
			return (uint8_t*) new_task_queue;
		}
		case 21: {
			return (uint8_t*) new_mut_list_by_val_with_capacity_from_unmanaged_memory;
		}
		case 22: {
			return (uint8_t*) mut_arr_0;
		}
		case 23: {
			return (uint8_t*) unmanaged_alloc_zeroed_elements;
		}
		case 24: {
			return (uint8_t*) unmanaged_alloc_elements_0;
		}
		case 25: {
			return (uint8_t*) unmanaged_alloc_bytes;
		}
		case 26: {
			return (uint8_t*) malloc;
		}
		case 27: {
			return (uint8_t*) hard_forbid;
		}
		case 28: {
			return (uint8_t*) null__q_0;
		}
		case 29: {
			return (uint8_t*) set_zero_range_0;
		}
		case 30: {
			return (uint8_t*) memset;
		}
		case 31: {
			return (uint8_t*) default_exception_handler;
		}
		case 32: {
			return (uint8_t*) print_err_no_newline;
		}
		case 33: {
			return (uint8_t*) write_no_newline;
		}
		case 34: {
			return (uint8_t*) write;
		}
		case 35: {
			return (uint8_t*) _notEqual_0;
		}
		case 36: {
			return (uint8_t*) _equal_1;
		}
		case 37: {
			return (uint8_t*) compare_37;
		}
		case 38: {
			return (uint8_t*) todo_0;
		}
		case 39: {
			return (uint8_t*) stderr;
		}
		case 40: {
			return (uint8_t*) print_err;
		}
		case 41: {
			return (uint8_t*) show_exception;
		}
		case 42: {
			return (uint8_t*) empty__q_0;
		}
		case 43: {
			return (uint8_t*) join;
		}
		case 44: {
			return (uint8_t*) empty__q_1;
		}
		case 45: {
			return (uint8_t*) subscript_0;
		}
		case 46: {
			return (uint8_t*) assert;
		}
		case 47: {
			return (uint8_t*) fail;
		}
		case 48: {
			return (uint8_t*) throw;
		}
		case 49: {
			return (uint8_t*) get_exception_ctx;
		}
		case 50: {
			return (uint8_t*) null__q_1;
		}
		case 51: {
			return (uint8_t*) longjmp;
		}
		case 52: {
			return (uint8_t*) number_to_throw;
		}
		case 53: {
			return (uint8_t*) get_backtrace;
		}
		case 54: {
			return (uint8_t*) try_alloc_backtrace_arrs;
		}
		case 55: {
			return (uint8_t*) try_alloc_uninitialized_0;
		}
		case 56: {
			return (uint8_t*) try_alloc;
		}
		case 57: {
			return (uint8_t*) try_gc_alloc;
		}
		case 58: {
			return (uint8_t*) validate_gc;
		}
		case 59: {
			return (uint8_t*) ptr_less_eq__q_0;
		}
		case 60: {
			return (uint8_t*) ptr_less_eq__q_1;
		}
		case 61: {
			return (uint8_t*) _minus_1;
		}
		case 62: {
			return (uint8_t*) range_free__q;
		}
		case 63: {
			return (uint8_t*) incr_1;
		}
		case 64: {
			return (uint8_t*) get_gc;
		}
		case 65: {
			return (uint8_t*) get_gc_ctx_0;
		}
		case 66: {
			return (uint8_t*) try_alloc_uninitialized_1;
		}
		case 67: {
			return (uint8_t*) funs_count_67;
		}
		case 68: {
			return (uint8_t*) backtrace;
		}
		case 69: {
			return (uint8_t*) code_ptrs_size;
		}
		case 70: {
			return (uint8_t*) fill_fun_ptrs_names_recur;
		}
		case 71: {
			return (uint8_t*) _notEqual_1;
		}
		case 72: {
			return (uint8_t*) get_fun_ptr_72;
		}
		case 73: {
			return (uint8_t*) get_fun_name_73;
		}
		case 74: {
			return (uint8_t*) noctx_incr;
		}
		case 75: {
			return (uint8_t*) sort_together;
		}
		case 76: {
			return (uint8_t*) swap_0;
		}
		case 77: {
			return (uint8_t*) swap_1;
		}
		case 78: {
			return (uint8_t*) partition_recur_together;
		}
		case 79: {
			return (uint8_t*) noctx_decr;
		}
		case 80: {
			return (uint8_t*) fill_code_names_recur;
		}
		case 81: {
			return (uint8_t*) get_fun_name;
		}
		case 82: {
			return (uint8_t*) incr_2;
		}
		case 83: {
			return (uint8_t*) incr_3;
		}
		case 84: {
			return (uint8_t*) noctx_at_0;
		}
		case 85: {
			return (uint8_t*) _concat_0;
		}
		case 86: {
			return (uint8_t*) _plus;
		}
		case 87: {
			return (uint8_t*) _greaterOrEqual;
		}
		case 88: {
			return (uint8_t*) alloc_uninitialized_0;
		}
		case 89: {
			return (uint8_t*) alloc;
		}
		case 90: {
			return (uint8_t*) gc_alloc;
		}
		case 91: {
			return (uint8_t*) todo_1;
		}
		case 92: {
			return (uint8_t*) copy_data_from_0;
		}
		case 93: {
			return (uint8_t*) memcpy;
		}
		case 94: {
			return (uint8_t*) tail_0;
		}
		case 95: {
			return (uint8_t*) forbid_0;
		}
		case 96: {
			return (uint8_t*) forbid_1;
		}
		case 97: {
			return (uint8_t*) subscript_1;
		}
		case 98: {
			return (uint8_t*) _minus_2;
		}
		case 99: {
			return (uint8_t*) _arrow;
		}
		case 100: {
			return (uint8_t*) get_global_ctx;
		}
		case 101: {
			return (uint8_t*) new_island__lambda0;
		}
		case 102: {
			return (uint8_t*) default_log_handler;
		}
		case 103: {
			return (uint8_t*) print;
		}
		case 104: {
			return (uint8_t*) print_no_newline;
		}
		case 105: {
			return (uint8_t*) stdout;
		}
		case 106: {
			return (uint8_t*) to_str_0;
		}
		case 107: {
			return (uint8_t*) new_island__lambda1;
		}
		case 108: {
			return (uint8_t*) new_gc;
		}
		case 109: {
			return (uint8_t*) new_thread_safe_counter_0;
		}
		case 110: {
			return (uint8_t*) new_thread_safe_counter_1;
		}
		case 111: {
			return (uint8_t*) do_main;
		}
		case 112: {
			return (uint8_t*) new_exception_ctx;
		}
		case 113: {
			return (uint8_t*) new_log_ctx;
		}
		case 114: {
			return (uint8_t*) new_ctx;
		}
		case 115: {
			return (uint8_t*) get_gc_ctx_1;
		}
		case 116: {
			return (uint8_t*) acquire_lock;
		}
		case 117: {
			return (uint8_t*) acquire_lock_recur;
		}
		case 118: {
			return (uint8_t*) try_acquire_lock;
		}
		case 119: {
			return (uint8_t*) try_set;
		}
		case 120: {
			return (uint8_t*) try_change;
		}
		case 121: {
			return (uint8_t*) yield_thread;
		}
		case 122: {
			return (uint8_t*) pthread_yield;
		}
		case 123: {
			return (uint8_t*) _equal_2;
		}
		case 124: {
			return (uint8_t*) compare_124;
		}
		case 125: {
			return (uint8_t*) release_lock;
		}
		case 126: {
			return (uint8_t*) must_unset;
		}
		case 127: {
			return (uint8_t*) try_unset;
		}
		case 128: {
			return (uint8_t*) add_first_task;
		}
		case 129: {
			return (uint8_t*) then2;
		}
		case 130: {
			return (uint8_t*) then;
		}
		case 131: {
			return (uint8_t*) new_unresolved_fut;
		}
		case 132: {
			return (uint8_t*) then_void_0;
		}
		case 133: {
			return (uint8_t*) subscript_2;
		}
		case 134: {
			return (uint8_t*) call_w_ctx_134;
		}
		case 135: {
			return (uint8_t*) forward_to;
		}
		case 136: {
			return (uint8_t*) then_void_1;
		}
		case 137: {
			return (uint8_t*) subscript_3;
		}
		case 138: {
			return (uint8_t*) call_w_ctx_138;
		}
		case 139: {
			return (uint8_t*) resolve_or_reject;
		}
		case 140: {
			return (uint8_t*) resolve_or_reject_recur;
		}
		case 141: {
			return (uint8_t*) drop_0;
		}
		case 142: {
			return (uint8_t*) forward_to__lambda0;
		}
		case 143: {
			return (uint8_t*) subscript_4;
		}
		case 144: {
			return (uint8_t*) get_island;
		}
		case 145: {
			return (uint8_t*) subscript_5;
		}
		case 146: {
			return (uint8_t*) noctx_at_1;
		}
		case 147: {
			return (uint8_t*) add_task_0;
		}
		case 148: {
			return (uint8_t*) add_task_1;
		}
		case 149: {
			return (uint8_t*) new_task_queue_node;
		}
		case 150: {
			return (uint8_t*) insert_task;
		}
		case 151: {
			return (uint8_t*) size_0;
		}
		case 152: {
			return (uint8_t*) size_recur;
		}
		case 153: {
			return (uint8_t*) insert_recur;
		}
		case 154: {
			return (uint8_t*) tasks;
		}
		case 155: {
			return (uint8_t*) broadcast;
		}
		case 156: {
			return (uint8_t*) no_timestamp;
		}
		case 157: {
			return (uint8_t*) catch;
		}
		case 158: {
			return (uint8_t*) catch_with_exception_ctx;
		}
		case 159: {
			return (uint8_t*) zero_0;
		}
		case 160: {
			return (uint8_t*) zero_1;
		}
		case 161: {
			return (uint8_t*) zero_2;
		}
		case 162: {
			return (uint8_t*) zero_3;
		}
		case 163: {
			return (uint8_t*) setjmp;
		}
		case 164: {
			return (uint8_t*) subscript_6;
		}
		case 165: {
			return (uint8_t*) call_w_ctx_165;
		}
		case 166: {
			return (uint8_t*) subscript_7;
		}
		case 167: {
			return (uint8_t*) call_w_ctx_167;
		}
		case 168: {
			return (uint8_t*) subscript_8;
		}
		case 169: {
			return (uint8_t*) call_w_ctx_169;
		}
		case 170: {
			return (uint8_t*) subscript_4__lambda0__lambda0;
		}
		case 171: {
			return (uint8_t*) reject;
		}
		case 172: {
			return (uint8_t*) subscript_4__lambda0__lambda1;
		}
		case 173: {
			return (uint8_t*) subscript_4__lambda0;
		}
		case 174: {
			return (uint8_t*) then__lambda0;
		}
		case 175: {
			return (uint8_t*) subscript_9;
		}
		case 176: {
			return (uint8_t*) subscript_10;
		}
		case 177: {
			return (uint8_t*) call_w_ctx_177;
		}
		case 178: {
			return (uint8_t*) subscript_9__lambda0__lambda0;
		}
		case 179: {
			return (uint8_t*) subscript_9__lambda0__lambda1;
		}
		case 180: {
			return (uint8_t*) subscript_9__lambda0;
		}
		case 181: {
			return (uint8_t*) then2__lambda0;
		}
		case 182: {
			return (uint8_t*) cur_island_and_exclusion;
		}
		case 183: {
			return (uint8_t*) delay;
		}
		case 184: {
			return (uint8_t*) resolved_0;
		}
		case 185: {
			return (uint8_t*) tail_1;
		}
		case 186: {
			return (uint8_t*) empty__q_2;
		}
		case 187: {
			return (uint8_t*) subscript_11;
		}
		case 188: {
			return (uint8_t*) map;
		}
		case 189: {
			return (uint8_t*) make_arr;
		}
		case 190: {
			return (uint8_t*) alloc_uninitialized_1;
		}
		case 191: {
			return (uint8_t*) fill_ptr_range;
		}
		case 192: {
			return (uint8_t*) fill_ptr_range_recur;
		}
		case 193: {
			return (uint8_t*) subscript_12;
		}
		case 194: {
			return (uint8_t*) call_w_ctx_194;
		}
		case 195: {
			return (uint8_t*) subscript_13;
		}
		case 196: {
			return (uint8_t*) call_w_ctx_196;
		}
		case 197: {
			return (uint8_t*) subscript_14;
		}
		case 198: {
			return (uint8_t*) noctx_at_2;
		}
		case 199: {
			return (uint8_t*) map__lambda0;
		}
		case 200: {
			return (uint8_t*) to_str_1;
		}
		case 201: {
			return (uint8_t*) arr_from_begin_end;
		}
		case 202: {
			return (uint8_t*) _minus_3;
		}
		case 203: {
			return (uint8_t*) find_cstr_end;
		}
		case 204: {
			return (uint8_t*) find_char_in_cstr;
		}
		case 205: {
			return (uint8_t*) _equal_3;
		}
		case 206: {
			return (uint8_t*) compare_206;
		}
		case 207: {
			return (uint8_t*) todo_2;
		}
		case 208: {
			return (uint8_t*) incr_4;
		}
		case 209: {
			return (uint8_t*) add_first_task__lambda0__lambda0;
		}
		case 210: {
			return (uint8_t*) add_first_task__lambda0;
		}
		case 211: {
			return (uint8_t*) handle_exceptions;
		}
		case 212: {
			return (uint8_t*) subscript_15;
		}
		case 213: {
			return (uint8_t*) call_w_ctx_213;
		}
		case 214: {
			return (uint8_t*) exception_handler;
		}
		case 215: {
			return (uint8_t*) get_cur_island;
		}
		case 216: {
			return (uint8_t*) handle_exceptions__lambda0;
		}
		case 217: {
			return (uint8_t*) do_main__lambda0;
		}
		case 218: {
			return (uint8_t*) call_w_ctx_218;
		}
		case 219: {
			return (uint8_t*) run_threads;
		}
		case 220: {
			return (uint8_t*) unmanaged_alloc_elements_1;
		}
		case 221: {
			return (uint8_t*) start_threads_recur;
		}
		case 222: {
			return (uint8_t*) create_one_thread;
		}
		case 223: {
			return (uint8_t*) pthread_create;
		}
		case 224: {
			return (uint8_t*) _notEqual_2;
		}
		case 225: {
			return (uint8_t*) eagain;
		}
		case 226: {
			return (uint8_t*) as_cell;
		}
		case 227: {
			return (uint8_t*) thread_fun;
		}
		case 228: {
			return (uint8_t*) thread_function;
		}
		case 229: {
			return (uint8_t*) thread_function_recur;
		}
		case 230: {
			return (uint8_t*) assert_islands_are_shut_down;
		}
		case 231: {
			return (uint8_t*) empty__q_3;
		}
		case 232: {
			return (uint8_t*) has__q_0;
		}
		case 233: {
			return (uint8_t*) empty__q_4;
		}
		case 234: {
			return (uint8_t*) get_last_checked;
		}
		case 235: {
			return (uint8_t*) choose_task;
		}
		case 236: {
			return (uint8_t*) get_monotime_nsec;
		}
		case 237: {
			return (uint8_t*) clock_gettime;
		}
		case 238: {
			return (uint8_t*) clock_monotonic;
		}
		case 239: {
			return (uint8_t*) get_0;
		}
		case 240: {
			return (uint8_t*) todo_3;
		}
		case 241: {
			return (uint8_t*) choose_task_recur;
		}
		case 242: {
			return (uint8_t*) choose_task_in_island;
		}
		case 243: {
			return (uint8_t*) pop_task;
		}
		case 244: {
			return (uint8_t*) contains__q_0;
		}
		case 245: {
			return (uint8_t*) contains__q_1;
		}
		case 246: {
			return (uint8_t*) contains_recur__q;
		}
		case 247: {
			return (uint8_t*) noctx_at_3;
		}
		case 248: {
			return (uint8_t*) temp_as_arr_0;
		}
		case 249: {
			return (uint8_t*) temp_as_arr_1;
		}
		case 250: {
			return (uint8_t*) temp_as_mut_arr;
		}
		case 251: {
			return (uint8_t*) data_0;
		}
		case 252: {
			return (uint8_t*) data_1;
		}
		case 253: {
			return (uint8_t*) pop_recur;
		}
		case 254: {
			return (uint8_t*) to_opt_time;
		}
		case 255: {
			return (uint8_t*) push_capacity_must_be_sufficient__e;
		}
		case 256: {
			return (uint8_t*) capacity_0;
		}
		case 257: {
			return (uint8_t*) size_1;
		}
		case 258: {
			return (uint8_t*) noctx_set_at__e_0;
		}
		case 259: {
			return (uint8_t*) is_no_task__q;
		}
		case 260: {
			return (uint8_t*) min_time;
		}
		case 261: {
			return (uint8_t*) min;
		}
		case 262: {
			return (uint8_t*) do_task;
		}
		case 263: {
			return (uint8_t*) return_task;
		}
		case 264: {
			return (uint8_t*) noctx_must_remove_unordered__e;
		}
		case 265: {
			return (uint8_t*) noctx_must_remove_unordered_recur__e;
		}
		case 266: {
			return (uint8_t*) noctx_at_4;
		}
		case 267: {
			return (uint8_t*) drop_1;
		}
		case 268: {
			return (uint8_t*) noctx_remove_unordered_at__e;
		}
		case 269: {
			return (uint8_t*) noctx_last;
		}
		case 270: {
			return (uint8_t*) empty__q_5;
		}
		case 271: {
			return (uint8_t*) return_ctx;
		}
		case 272: {
			return (uint8_t*) return_gc_ctx;
		}
		case 273: {
			return (uint8_t*) run_garbage_collection;
		}
		case 274: {
			return (uint8_t*) mark_visit_274;
		}
		case 275: {
			return (uint8_t*) mark_visit_275;
		}
		case 276: {
			return (uint8_t*) mark_visit_276;
		}
		case 277: {
			return (uint8_t*) mark_visit_277;
		}
		case 278: {
			return (uint8_t*) mark_visit_278;
		}
		case 279: {
			return (uint8_t*) mark_visit_279;
		}
		case 280: {
			return (uint8_t*) mark_visit_280;
		}
		case 281: {
			return (uint8_t*) mark_visit_281;
		}
		case 282: {
			return (uint8_t*) mark_visit_282;
		}
		case 283: {
			return (uint8_t*) mark_visit_283;
		}
		case 284: {
			return (uint8_t*) mark_visit_284;
		}
		case 285: {
			return (uint8_t*) mark_visit_285;
		}
		case 286: {
			return (uint8_t*) mark_visit_286;
		}
		case 287: {
			return (uint8_t*) mark_visit_287;
		}
		case 288: {
			return (uint8_t*) mark_arr_288;
		}
		case 289: {
			return (uint8_t*) mark_visit_289;
		}
		case 290: {
			return (uint8_t*) mark_visit_290;
		}
		case 291: {
			return (uint8_t*) mark_visit_291;
		}
		case 292: {
			return (uint8_t*) mark_visit_292;
		}
		case 293: {
			return (uint8_t*) mark_visit_293;
		}
		case 294: {
			return (uint8_t*) mark_visit_294;
		}
		case 295: {
			return (uint8_t*) mark_visit_295;
		}
		case 296: {
			return (uint8_t*) mark_visit_296;
		}
		case 297: {
			return (uint8_t*) mark_visit_297;
		}
		case 298: {
			return (uint8_t*) mark_visit_298;
		}
		case 299: {
			return (uint8_t*) mark_visit_299;
		}
		case 300: {
			return (uint8_t*) mark_visit_300;
		}
		case 301: {
			return (uint8_t*) mark_visit_301;
		}
		case 302: {
			return (uint8_t*) mark_visit_302;
		}
		case 303: {
			return (uint8_t*) mark_arr_303;
		}
		case 304: {
			return (uint8_t*) mark_visit_304;
		}
		case 305: {
			return (uint8_t*) mark_elems_305;
		}
		case 306: {
			return (uint8_t*) mark_arr_306;
		}
		case 307: {
			return (uint8_t*) mark_visit_307;
		}
		case 308: {
			return (uint8_t*) mark_visit_308;
		}
		case 309: {
			return (uint8_t*) mark_visit_309;
		}
		case 310: {
			return (uint8_t*) mark_visit_310;
		}
		case 311: {
			return (uint8_t*) mark_visit_311;
		}
		case 312: {
			return (uint8_t*) mark_visit_312;
		}
		case 313: {
			return (uint8_t*) mark_visit_313;
		}
		case 314: {
			return (uint8_t*) mark_visit_314;
		}
		case 315: {
			return (uint8_t*) mark_visit_315;
		}
		case 316: {
			return (uint8_t*) mark_visit_316;
		}
		case 317: {
			return (uint8_t*) mark_arr_317;
		}
		case 318: {
			return (uint8_t*) clear_free_mem;
		}
		case 319: {
			return (uint8_t*) wait_on;
		}
		case 320: {
			return (uint8_t*) before_time__q;
		}
		case 321: {
			return (uint8_t*) join_threads_recur;
		}
		case 322: {
			return (uint8_t*) join_one_thread;
		}
		case 323: {
			return (uint8_t*) pthread_join;
		}
		case 324: {
			return (uint8_t*) einval;
		}
		case 325: {
			return (uint8_t*) esrch;
		}
		case 326: {
			return (uint8_t*) get_1;
		}
		case 327: {
			return (uint8_t*) unmanaged_free_0;
		}
		case 328: {
			return (uint8_t*) free;
		}
		case 329: {
			return (uint8_t*) unmanaged_free_1;
		}
		case 330: {
			return (uint8_t*) main_0;
		}
		case 331: {
			return (uint8_t*) set;
		}
		case 332: {
			return (uint8_t*) sort_unique;
		}
		case 333: {
			return (uint8_t*) unique__e;
		}
		case 334: {
			return (uint8_t*) mut_list_0;
		}
		case 335: {
			return (uint8_t*) mut_arr_1;
		}
		case 336: {
			return (uint8_t*) each;
		}
		case 337: {
			return (uint8_t*) subscript_16;
		}
		case 338: {
			return (uint8_t*) call_w_ctx_338;
		}
		case 339: {
			return (uint8_t*) first;
		}
		case 340: {
			return (uint8_t*) empty__q_6;
		}
		case 341: {
			return (uint8_t*) _notEqual_3;
		}
		case 342: {
			return (uint8_t*) _equal_4;
		}
		case 343: {
			return (uint8_t*) compare_343;
		}
		case 344: {
			return (uint8_t*) last;
		}
		case 345: {
			return (uint8_t*) subscript_17;
		}
		case 346: {
			return (uint8_t*) noctx_at_5;
		}
		case 347: {
			return (uint8_t*) data_2;
		}
		case 348: {
			return (uint8_t*) data_3;
		}
		case 349: {
			return (uint8_t*) _concatEquals_0;
		}
		case 350: {
			return (uint8_t*) incr_capacity__e;
		}
		case 351: {
			return (uint8_t*) ensure_capacity;
		}
		case 352: {
			return (uint8_t*) capacity_1;
		}
		case 353: {
			return (uint8_t*) size_2;
		}
		case 354: {
			return (uint8_t*) increase_capacity_to__e;
		}
		case 355: {
			return (uint8_t*) mut_arr_2;
		}
		case 356: {
			return (uint8_t*) copy_data_from_1;
		}
		case 357: {
			return (uint8_t*) set_zero_elements;
		}
		case 358: {
			return (uint8_t*) set_zero_range_1;
		}
		case 359: {
			return (uint8_t*) subscript_18;
		}
		case 360: {
			return (uint8_t*) round_up_to_power_of_two;
		}
		case 361: {
			return (uint8_t*) round_up_to_power_of_two_recur;
		}
		case 362: {
			return (uint8_t*) _times;
		}
		case 363: {
			return (uint8_t*) _divide;
		}
		case 364: {
			return (uint8_t*) incr_5;
		}
		case 365: {
			return (uint8_t*) max_nat;
		}
		case 366: {
			return (uint8_t*) unique__e__lambda0;
		}
		case 367: {
			return (uint8_t*) move_to_arr__e;
		}
		case 368: {
			return (uint8_t*) sort;
		}
		case 369: {
			return (uint8_t*) mut_arr_3;
		}
		case 370: {
			return (uint8_t*) make_mut_arr;
		}
		case 371: {
			return (uint8_t*) new_uninitialized_mut_arr;
		}
		case 372: {
			return (uint8_t*) mut_arr_3__lambda0;
		}
		case 373: {
			return (uint8_t*) sort__e;
		}
		case 374: {
			return (uint8_t*) swap_2;
		}
		case 375: {
			return (uint8_t*) subscript_19;
		}
		case 376: {
			return (uint8_t*) set_subscript_0;
		}
		case 377: {
			return (uint8_t*) noctx_set_at;
		}
		case 378: {
			return (uint8_t*) partition_recur;
		}
		case 379: {
			return (uint8_t*) _less_1;
		}
		case 380: {
			return (uint8_t*) cast_immutable;
		}
		case 381: {
			return (uint8_t*) to_str_2;
		}
		case 382: {
			return (uint8_t*) mod;
		}
		case 383: {
			return (uint8_t*) size_3;
		}
		case 384: {
			return (uint8_t*) to_str_3;
		}
		case 385: {
			return (uint8_t*) subscript_20;
		}
		case 386: {
			return (uint8_t*) has__q_1;
		}
		case 387: {
			return (uint8_t*) arr;
		}
		case 388: {
			return (uint8_t*) _concat_1;
		}
		case 389: {
			return (uint8_t*) union__e;
		}
		case 390: {
			return (uint8_t*) intersect;
		}
		case 391: {
			return (uint8_t*) intersect__e;
		}
		case 392: {
			return (uint8_t*) _minus_4;
		}
		case 393: {
			return (uint8_t*) subtract__e;
		}
		case 394: {
			return (uint8_t*) _concatEquals_1;
		}
		case 395: {
			return (uint8_t*) _concatEquals_1__lambda0;
		}
		case 396: {
			return (uint8_t*) mut_set;
		}
		case 397: {
			return (uint8_t*) mut_list_1;
		}
		case 398: {
			return (uint8_t*) subscript_21;
		}
		case 399: {
			return (uint8_t*) has__q_2;
		}
		case 400: {
			return (uint8_t*) remove__e_0;
		}
		case 401: {
			return (uint8_t*) remove__e_1;
		}
		case 402: {
			return (uint8_t*) drop_2;
		}
		case 403: {
			return (uint8_t*) remove_at__e;
		}
		case 404: {
			return (uint8_t*) memmove;
		}
		case 405: {
			return (uint8_t*) _concatEquals_2;
		}
		case 406: {
			return (uint8_t*) _concatEquals_3;
		}
		case 407: {
			return (uint8_t*) drop_3;
		}
		case 408: {
			return (uint8_t*) add__e;
		}
		case 409: {
			return (uint8_t*) insert_at__e;
		}
		case 410: {
			return (uint8_t*) set_subscript_1;
		}
		case 411: {
			return (uint8_t*) noctx_set_at__e_1;
		}
		case 412: {
			return (uint8_t*) _concatEquals_2__lambda0;
		}
		case 413: {
			return (uint8_t*) move_to_set__e;
		}
		case 414: {
			return (uint8_t*) resolved_1;
		}
		default:
			return NULL;
	}
}
/* get-fun-name (generated) (generated) */
struct arr_0 get_fun_name_73(uint64_t fun_id) {switch (fun_id) {
		case 0: {
			return (struct arr_0) {4, constantarr_0_38};
		}
		case 1: {
			return (struct arr_0) {14, constantarr_0_39};
		}
		case 2: {
			return (struct arr_0) {25, constantarr_0_41};
		}
		case 3: {
			return (struct arr_0) {11, constantarr_0_47};
		}
		case 4: {
			return (struct arr_0) {3, constantarr_0_48};
		}
		case 5: {
			return (struct arr_0) {5, constantarr_0_49};
		}
		case 6: {
			return (struct arr_0) {7, constantarr_0_50};
		}
		case 7: {
			return (struct arr_0) {0u, NULL};
		}
		case 8: {
			return (struct arr_0) {6, constantarr_0_53};
		}
		case 9: {
			return (struct arr_0) {6, constantarr_0_57};
		}
		case 10: {
			return (struct arr_0) {7, constantarr_0_59};
		}
		case 11: {
			return (struct arr_0) {16, constantarr_0_62};
		}
		case 12: {
			return (struct arr_0) {10, constantarr_0_67};
		}
		case 13: {
			return (struct arr_0) {6, constantarr_0_68};
		}
		case 14: {
			return (struct arr_0) {7, constantarr_0_69};
		}
		case 15: {
			return (struct arr_0) {10, constantarr_0_70};
		}
		case 16: {
			return (struct arr_0) {8, constantarr_0_73};
		}
		case 17: {
			return (struct arr_0) {15, constantarr_0_75};
		}
		case 18: {
			return (struct arr_0) {13, constantarr_0_77};
		}
		case 19: {
			return (struct arr_0) {10, constantarr_0_80};
		}
		case 20: {
			return (struct arr_0) {14, constantarr_0_81};
		}
		case 21: {
			return (struct arr_0) {60, constantarr_0_84};
		}
		case 22: {
			return (struct arr_0) {11, constantarr_0_85};
		}
		case 23: {
			return (struct arr_0) {35, constantarr_0_88};
		}
		case 24: {
			return (struct arr_0) {28, constantarr_0_89};
		}
		case 25: {
			return (struct arr_0) {21, constantarr_0_90};
		}
		case 26: {
			return (struct arr_0) {6, constantarr_0_91};
		}
		case 27: {
			return (struct arr_0) {11, constantarr_0_92};
		}
		case 28: {
			return (struct arr_0) {11, constantarr_0_93};
		}
		case 29: {
			return (struct arr_0) {18, constantarr_0_97};
		}
		case 30: {
			return (struct arr_0) {6, constantarr_0_98};
		}
		case 31: {
			return (struct arr_0) {25, constantarr_0_103};
		}
		case 32: {
			return (struct arr_0) {20, constantarr_0_104};
		}
		case 33: {
			return (struct arr_0) {16, constantarr_0_105};
		}
		case 34: {
			return (struct arr_0) {5, constantarr_0_108};
		}
		case 35: {
			return (struct arr_0) {7, constantarr_0_112};
		}
		case 36: {
			return (struct arr_0) {6, constantarr_0_113};
		}
		case 37: {
			return (struct arr_0) {0u, NULL};
		}
		case 38: {
			return (struct arr_0) {10, constantarr_0_115};
		}
		case 39: {
			return (struct arr_0) {6, constantarr_0_117};
		}
		case 40: {
			return (struct arr_0) {9, constantarr_0_118};
		}
		case 41: {
			return (struct arr_0) {14, constantarr_0_119};
		}
		case 42: {
			return (struct arr_0) {12, constantarr_0_121};
		}
		case 43: {
			return (struct arr_0) {10, constantarr_0_123};
		}
		case 44: {
			return (struct arr_0) {15, constantarr_0_124};
		}
		case 45: {
			return (struct arr_0) {18, constantarr_0_126};
		}
		case 46: {
			return (struct arr_0) {6, constantarr_0_127};
		}
		case 47: {
			return (struct arr_0) {10, constantarr_0_128};
		}
		case 48: {
			return (struct arr_0) {9, constantarr_0_129};
		}
		case 49: {
			return (struct arr_0) {17, constantarr_0_130};
		}
		case 50: {
			return (struct arr_0) {18, constantarr_0_134};
		}
		case 51: {
			return (struct arr_0) {7, constantarr_0_137};
		}
		case 52: {
			return (struct arr_0) {15, constantarr_0_138};
		}
		case 53: {
			return (struct arr_0) {13, constantarr_0_140};
		}
		case 54: {
			return (struct arr_0) {24, constantarr_0_141};
		}
		case 55: {
			return (struct arr_0) {34, constantarr_0_142};
		}
		case 56: {
			return (struct arr_0) {9, constantarr_0_143};
		}
		case 57: {
			return (struct arr_0) {12, constantarr_0_144};
		}
		case 58: {
			return (struct arr_0) {11, constantarr_0_145};
		}
		case 59: {
			return (struct arr_0) {18, constantarr_0_146};
		}
		case 60: {
			return (struct arr_0) {17, constantarr_0_151};
		}
		case 61: {
			return (struct arr_0) {7, constantarr_0_156};
		}
		case 62: {
			return (struct arr_0) {11, constantarr_0_159};
		}
		case 63: {
			return (struct arr_0) {9, constantarr_0_164};
		}
		case 64: {
			return (struct arr_0) {6, constantarr_0_165};
		}
		case 65: {
			return (struct arr_0) {10, constantarr_0_167};
		}
		case 66: {
			return (struct arr_0) {34, constantarr_0_173};
		}
		case 67: {
			return (struct arr_0) {0u, NULL};
		}
		case 68: {
			return (struct arr_0) {9, constantarr_0_179};
		}
		case 69: {
			return (struct arr_0) {14, constantarr_0_186};
		}
		case 70: {
			return (struct arr_0) {25, constantarr_0_187};
		}
		case 71: {
			return (struct arr_0) {7, constantarr_0_188};
		}
		case 72: {
			return (struct arr_0) {0u, NULL};
		}
		case 73: {
			return (struct arr_0) {0u, NULL};
		}
		case 74: {
			return (struct arr_0) {10, constantarr_0_195};
		}
		case 75: {
			return (struct arr_0) {13, constantarr_0_198};
		}
		case 76: {
			return (struct arr_0) {15, constantarr_0_199};
		}
		case 77: {
			return (struct arr_0) {15, constantarr_0_201};
		}
		case 78: {
			return (struct arr_0) {24, constantarr_0_202};
		}
		case 79: {
			return (struct arr_0) {10, constantarr_0_204};
		}
		case 80: {
			return (struct arr_0) {21, constantarr_0_206};
		}
		case 81: {
			return (struct arr_0) {12, constantarr_0_194};
		}
		case 82: {
			return (struct arr_0) {15, constantarr_0_208};
		}
		case 83: {
			return (struct arr_0) {15, constantarr_0_209};
		}
		case 84: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 85: {
			return (struct arr_0) {5, constantarr_0_213};
		}
		case 86: {
			return (struct arr_0) {1, constantarr_0_214};
		}
		case 87: {
			return (struct arr_0) {7, constantarr_0_216};
		}
		case 88: {
			return (struct arr_0) {23, constantarr_0_217};
		}
		case 89: {
			return (struct arr_0) {5, constantarr_0_218};
		}
		case 90: {
			return (struct arr_0) {8, constantarr_0_219};
		}
		case 91: {
			return (struct arr_0) {15, constantarr_0_220};
		}
		case 92: {
			return (struct arr_0) {18, constantarr_0_221};
		}
		case 93: {
			return (struct arr_0) {6, constantarr_0_222};
		}
		case 94: {
			return (struct arr_0) {13, constantarr_0_224};
		}
		case 95: {
			return (struct arr_0) {6, constantarr_0_225};
		}
		case 96: {
			return (struct arr_0) {6, constantarr_0_225};
		}
		case 97: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 98: {
			return (struct arr_0) {1, constantarr_0_229};
		}
		case 99: {
			return (struct arr_0) {12, constantarr_0_230};
		}
		case 100: {
			return (struct arr_0) {14, constantarr_0_234};
		}
		case 101: {
			return (struct arr_0) {18, constantarr_0_237};
		}
		case 102: {
			return (struct arr_0) {19, constantarr_0_238};
		}
		case 103: {
			return (struct arr_0) {5, constantarr_0_239};
		}
		case 104: {
			return (struct arr_0) {16, constantarr_0_240};
		}
		case 105: {
			return (struct arr_0) {6, constantarr_0_241};
		}
		case 106: {
			return (struct arr_0) {6, constantarr_0_242};
		}
		case 107: {
			return (struct arr_0) {18, constantarr_0_244};
		}
		case 108: {
			return (struct arr_0) {6, constantarr_0_246};
		}
		case 109: {
			return (struct arr_0) {23, constantarr_0_249};
		}
		case 110: {
			return (struct arr_0) {23, constantarr_0_249};
		}
		case 111: {
			return (struct arr_0) {7, constantarr_0_255};
		}
		case 112: {
			return (struct arr_0) {17, constantarr_0_256};
		}
		case 113: {
			return (struct arr_0) {11, constantarr_0_258};
		}
		case 114: {
			return (struct arr_0) {7, constantarr_0_265};
		}
		case 115: {
			return (struct arr_0) {10, constantarr_0_167};
		}
		case 116: {
			return (struct arr_0) {12, constantarr_0_267};
		}
		case 117: {
			return (struct arr_0) {18, constantarr_0_268};
		}
		case 118: {
			return (struct arr_0) {16, constantarr_0_269};
		}
		case 119: {
			return (struct arr_0) {7, constantarr_0_270};
		}
		case 120: {
			return (struct arr_0) {10, constantarr_0_271};
		}
		case 121: {
			return (struct arr_0) {12, constantarr_0_277};
		}
		case 122: {
			return (struct arr_0) {13, constantarr_0_278};
		}
		case 123: {
			return (struct arr_0) {9, constantarr_0_279};
		}
		case 124: {
			return (struct arr_0) {0u, NULL};
		}
		case 125: {
			return (struct arr_0) {12, constantarr_0_289};
		}
		case 126: {
			return (struct arr_0) {10, constantarr_0_290};
		}
		case 127: {
			return (struct arr_0) {9, constantarr_0_291};
		}
		case 128: {
			return (struct arr_0) {14, constantarr_0_305};
		}
		case 129: {
			return (struct arr_0) {10, constantarr_0_306};
		}
		case 130: {
			return (struct arr_0) {16, constantarr_0_307};
		}
		case 131: {
			return (struct arr_0) {24, constantarr_0_308};
		}
		case 132: {
			return (struct arr_0) {14, constantarr_0_311};
		}
		case 133: {
			return (struct arr_0) {38, constantarr_0_318};
		}
		case 134: {
			return (struct arr_0) {0u, NULL};
		}
		case 135: {
			return (struct arr_0) {16, constantarr_0_323};
		}
		case 136: {
			return (struct arr_0) {13, constantarr_0_324};
		}
		case 137: {
			return (struct arr_0) {38, constantarr_0_318};
		}
		case 138: {
			return (struct arr_0) {0u, NULL};
		}
		case 139: {
			return (struct arr_0) {21, constantarr_0_325};
		}
		case 140: {
			return (struct arr_0) {27, constantarr_0_326};
		}
		case 141: {
			return (struct arr_0) {10, constantarr_0_327};
		}
		case 142: {
			return (struct arr_0) {24, constantarr_0_333};
		}
		case 143: {
			return (struct arr_0) {20, constantarr_0_334};
		}
		case 144: {
			return (struct arr_0) {10, constantarr_0_335};
		}
		case 145: {
			return (struct arr_0) {17, constantarr_0_336};
		}
		case 146: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 147: {
			return (struct arr_0) {8, constantarr_0_339};
		}
		case 148: {
			return (struct arr_0) {8, constantarr_0_339};
		}
		case 149: {
			return (struct arr_0) {19, constantarr_0_340};
		}
		case 150: {
			return (struct arr_0) {11, constantarr_0_344};
		}
		case 151: {
			return (struct arr_0) {4, constantarr_0_345};
		}
		case 152: {
			return (struct arr_0) {10, constantarr_0_346};
		}
		case 153: {
			return (struct arr_0) {12, constantarr_0_353};
		}
		case 154: {
			return (struct arr_0) {5, constantarr_0_355};
		}
		case 155: {
			return (struct arr_0) {9, constantarr_0_357};
		}
		case 156: {
			return (struct arr_0) {12, constantarr_0_362};
		}
		case 157: {
			return (struct arr_0) {11, constantarr_0_364};
		}
		case 158: {
			return (struct arr_0) {28, constantarr_0_365};
		}
		case 159: {
			return (struct arr_0) {4, constantarr_0_368};
		}
		case 160: {
			return (struct arr_0) {4, constantarr_0_368};
		}
		case 161: {
			return (struct arr_0) {4, constantarr_0_368};
		}
		case 162: {
			return (struct arr_0) {4, constantarr_0_368};
		}
		case 163: {
			return (struct arr_0) {6, constantarr_0_375};
		}
		case 164: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 165: {
			return (struct arr_0) {0u, NULL};
		}
		case 166: {
			return (struct arr_0) {24, constantarr_0_377};
		}
		case 167: {
			return (struct arr_0) {0u, NULL};
		}
		case 168: {
			return (struct arr_0) {23, constantarr_0_378};
		}
		case 169: {
			return (struct arr_0) {0u, NULL};
		}
		case 170: {
			return (struct arr_0) {36, constantarr_0_380};
		}
		case 171: {
			return (struct arr_0) {10, constantarr_0_381};
		}
		case 172: {
			return (struct arr_0) {36, constantarr_0_382};
		}
		case 173: {
			return (struct arr_0) {28, constantarr_0_383};
		}
		case 174: {
			return (struct arr_0) {24, constantarr_0_385};
		}
		case 175: {
			return (struct arr_0) {15, constantarr_0_386};
		}
		case 176: {
			return (struct arr_0) {18, constantarr_0_388};
		}
		case 177: {
			return (struct arr_0) {0u, NULL};
		}
		case 178: {
			return (struct arr_0) {31, constantarr_0_390};
		}
		case 179: {
			return (struct arr_0) {31, constantarr_0_391};
		}
		case 180: {
			return (struct arr_0) {23, constantarr_0_392};
		}
		case 181: {
			return (struct arr_0) {18, constantarr_0_393};
		}
		case 182: {
			return (struct arr_0) {24, constantarr_0_394};
		}
		case 183: {
			return (struct arr_0) {5, constantarr_0_397};
		}
		case 184: {
			return (struct arr_0) {14, constantarr_0_398};
		}
		case 185: {
			return (struct arr_0) {15, constantarr_0_399};
		}
		case 186: {
			return (struct arr_0) {10, constantarr_0_400};
		}
		case 187: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 188: {
			return (struct arr_0) {25, constantarr_0_402};
		}
		case 189: {
			return (struct arr_0) {14, constantarr_0_403};
		}
		case 190: {
			return (struct arr_0) {23, constantarr_0_217};
		}
		case 191: {
			return (struct arr_0) {18, constantarr_0_404};
		}
		case 192: {
			return (struct arr_0) {24, constantarr_0_405};
		}
		case 193: {
			return (struct arr_0) {18, constantarr_0_406};
		}
		case 194: {
			return (struct arr_0) {0u, NULL};
		}
		case 195: {
			return (struct arr_0) {20, constantarr_0_334};
		}
		case 196: {
			return (struct arr_0) {0u, NULL};
		}
		case 197: {
			return (struct arr_0) {14, constantarr_0_407};
		}
		case 198: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 199: {
			return (struct arr_0) {33, constantarr_0_408};
		}
		case 200: {
			return (struct arr_0) {6, constantarr_0_242};
		}
		case 201: {
			return (struct arr_0) {24, constantarr_0_409};
		}
		case 202: {
			return (struct arr_0) {5, constantarr_0_410};
		}
		case 203: {
			return (struct arr_0) {13, constantarr_0_411};
		}
		case 204: {
			return (struct arr_0) {17, constantarr_0_412};
		}
		case 205: {
			return (struct arr_0) {8, constantarr_0_413};
		}
		case 206: {
			return (struct arr_0) {0u, NULL};
		}
		case 207: {
			return (struct arr_0) {15, constantarr_0_415};
		}
		case 208: {
			return (struct arr_0) {10, constantarr_0_416};
		}
		case 209: {
			return (struct arr_0) {30, constantarr_0_417};
		}
		case 210: {
			return (struct arr_0) {22, constantarr_0_418};
		}
		case 211: {
			return (struct arr_0) {22, constantarr_0_419};
		}
		case 212: {
			return (struct arr_0) {26, constantarr_0_420};
		}
		case 213: {
			return (struct arr_0) {0u, NULL};
		}
		case 214: {
			return (struct arr_0) {17, constantarr_0_421};
		}
		case 215: {
			return (struct arr_0) {14, constantarr_0_422};
		}
		case 216: {
			return (struct arr_0) {30, constantarr_0_423};
		}
		case 217: {
			return (struct arr_0) {15, constantarr_0_424};
		}
		case 218: {
			return (struct arr_0) {0u, NULL};
		}
		case 219: {
			return (struct arr_0) {11, constantarr_0_426};
		}
		case 220: {
			return (struct arr_0) {45, constantarr_0_427};
		}
		case 221: {
			return (struct arr_0) {19, constantarr_0_428};
		}
		case 222: {
			return (struct arr_0) {17, constantarr_0_432};
		}
		case 223: {
			return (struct arr_0) {14, constantarr_0_433};
		}
		case 224: {
			return (struct arr_0) {9, constantarr_0_434};
		}
		case 225: {
			return (struct arr_0) {6, constantarr_0_435};
		}
		case 226: {
			return (struct arr_0) {12, constantarr_0_436};
		}
		case 227: {
			return (struct arr_0) {10, constantarr_0_439};
		}
		case 228: {
			return (struct arr_0) {15, constantarr_0_441};
		}
		case 229: {
			return (struct arr_0) {21, constantarr_0_442};
		}
		case 230: {
			return (struct arr_0) {28, constantarr_0_446};
		}
		case 231: {
			return (struct arr_0) {6, constantarr_0_449};
		}
		case 232: {
			return (struct arr_0) {21, constantarr_0_450};
		}
		case 233: {
			return (struct arr_0) {10, constantarr_0_400};
		}
		case 234: {
			return (struct arr_0) {16, constantarr_0_451};
		}
		case 235: {
			return (struct arr_0) {11, constantarr_0_452};
		}
		case 236: {
			return (struct arr_0) {17, constantarr_0_453};
		}
		case 237: {
			return (struct arr_0) {13, constantarr_0_457};
		}
		case 238: {
			return (struct arr_0) {15, constantarr_0_458};
		}
		case 239: {
			return (struct arr_0) {13, constantarr_0_460};
		}
		case 240: {
			return (struct arr_0) {9, constantarr_0_463};
		}
		case 241: {
			return (struct arr_0) {17, constantarr_0_465};
		}
		case 242: {
			return (struct arr_0) {21, constantarr_0_467};
		}
		case 243: {
			return (struct arr_0) {8, constantarr_0_471};
		}
		case 244: {
			return (struct arr_0) {14, constantarr_0_475};
		}
		case 245: {
			return (struct arr_0) {13, constantarr_0_476};
		}
		case 246: {
			return (struct arr_0) {19, constantarr_0_477};
		}
		case 247: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 248: {
			return (struct arr_0) {15, constantarr_0_478};
		}
		case 249: {
			return (struct arr_0) {15, constantarr_0_478};
		}
		case 250: {
			return (struct arr_0) {19, constantarr_0_480};
		}
		case 251: {
			return (struct arr_0) {8, constantarr_0_212};
		}
		case 252: {
			return (struct arr_0) {8, constantarr_0_212};
		}
		case 253: {
			return (struct arr_0) {9, constantarr_0_482};
		}
		case 254: {
			return (struct arr_0) {11, constantarr_0_483};
		}
		case 255: {
			return (struct arr_0) {38, constantarr_0_485};
		}
		case 256: {
			return (struct arr_0) {12, constantarr_0_486};
		}
		case 257: {
			return (struct arr_0) {8, constantarr_0_125};
		}
		case 258: {
			return (struct arr_0) {17, constantarr_0_488};
		}
		case 259: {
			return (struct arr_0) {11, constantarr_0_490};
		}
		case 260: {
			return (struct arr_0) {8, constantarr_0_494};
		}
		case 261: {
			return (struct arr_0) {8, constantarr_0_495};
		}
		case 262: {
			return (struct arr_0) {7, constantarr_0_500};
		}
		case 263: {
			return (struct arr_0) {11, constantarr_0_504};
		}
		case 264: {
			return (struct arr_0) {33, constantarr_0_505};
		}
		case 265: {
			return (struct arr_0) {38, constantarr_0_506};
		}
		case 266: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 267: {
			return (struct arr_0) {8, constantarr_0_507};
		}
		case 268: {
			return (struct arr_0) {30, constantarr_0_508};
		}
		case 269: {
			return (struct arr_0) {14, constantarr_0_509};
		}
		case 270: {
			return (struct arr_0) {10, constantarr_0_400};
		}
		case 271: {
			return (struct arr_0) {10, constantarr_0_510};
		}
		case 272: {
			return (struct arr_0) {13, constantarr_0_511};
		}
		case 273: {
			return (struct arr_0) {46, constantarr_0_513};
		}
		case 274: {
			return (struct arr_0) {0u, NULL};
		}
		case 275: {
			return (struct arr_0) {0u, NULL};
		}
		case 276: {
			return (struct arr_0) {0u, NULL};
		}
		case 277: {
			return (struct arr_0) {0u, NULL};
		}
		case 278: {
			return (struct arr_0) {0u, NULL};
		}
		case 279: {
			return (struct arr_0) {0u, NULL};
		}
		case 280: {
			return (struct arr_0) {0u, NULL};
		}
		case 281: {
			return (struct arr_0) {0u, NULL};
		}
		case 282: {
			return (struct arr_0) {0u, NULL};
		}
		case 283: {
			return (struct arr_0) {0u, NULL};
		}
		case 284: {
			return (struct arr_0) {0u, NULL};
		}
		case 285: {
			return (struct arr_0) {0u, NULL};
		}
		case 286: {
			return (struct arr_0) {0u, NULL};
		}
		case 287: {
			return (struct arr_0) {0u, NULL};
		}
		case 288: {
			return (struct arr_0) {0u, NULL};
		}
		case 289: {
			return (struct arr_0) {0u, NULL};
		}
		case 290: {
			return (struct arr_0) {0u, NULL};
		}
		case 291: {
			return (struct arr_0) {0u, NULL};
		}
		case 292: {
			return (struct arr_0) {0u, NULL};
		}
		case 293: {
			return (struct arr_0) {0u, NULL};
		}
		case 294: {
			return (struct arr_0) {0u, NULL};
		}
		case 295: {
			return (struct arr_0) {0u, NULL};
		}
		case 296: {
			return (struct arr_0) {0u, NULL};
		}
		case 297: {
			return (struct arr_0) {0u, NULL};
		}
		case 298: {
			return (struct arr_0) {0u, NULL};
		}
		case 299: {
			return (struct arr_0) {0u, NULL};
		}
		case 300: {
			return (struct arr_0) {0u, NULL};
		}
		case 301: {
			return (struct arr_0) {0u, NULL};
		}
		case 302: {
			return (struct arr_0) {0u, NULL};
		}
		case 303: {
			return (struct arr_0) {0u, NULL};
		}
		case 304: {
			return (struct arr_0) {0u, NULL};
		}
		case 305: {
			return (struct arr_0) {0u, NULL};
		}
		case 306: {
			return (struct arr_0) {0u, NULL};
		}
		case 307: {
			return (struct arr_0) {0u, NULL};
		}
		case 308: {
			return (struct arr_0) {0u, NULL};
		}
		case 309: {
			return (struct arr_0) {0u, NULL};
		}
		case 310: {
			return (struct arr_0) {0u, NULL};
		}
		case 311: {
			return (struct arr_0) {0u, NULL};
		}
		case 312: {
			return (struct arr_0) {0u, NULL};
		}
		case 313: {
			return (struct arr_0) {0u, NULL};
		}
		case 314: {
			return (struct arr_0) {0u, NULL};
		}
		case 315: {
			return (struct arr_0) {0u, NULL};
		}
		case 316: {
			return (struct arr_0) {0u, NULL};
		}
		case 317: {
			return (struct arr_0) {0u, NULL};
		}
		case 318: {
			return (struct arr_0) {14, constantarr_0_521};
		}
		case 319: {
			return (struct arr_0) {7, constantarr_0_523};
		}
		case 320: {
			return (struct arr_0) {12, constantarr_0_524};
		}
		case 321: {
			return (struct arr_0) {18, constantarr_0_526};
		}
		case 322: {
			return (struct arr_0) {15, constantarr_0_527};
		}
		case 323: {
			return (struct arr_0) {12, constantarr_0_530};
		}
		case 324: {
			return (struct arr_0) {6, constantarr_0_532};
		}
		case 325: {
			return (struct arr_0) {5, constantarr_0_533};
		}
		case 326: {
			return (struct arr_0) {14, constantarr_0_534};
		}
		case 327: {
			return (struct arr_0) {19, constantarr_0_535};
		}
		case 328: {
			return (struct arr_0) {4, constantarr_0_536};
		}
		case 329: {
			return (struct arr_0) {35, constantarr_0_537};
		}
		case 330: {
			return (struct arr_0) {4, constantarr_0_541};
		}
		case 331: {
			return (struct arr_0) {14, constantarr_0_192};
		}
		case 332: {
			return (struct arr_0) {15, constantarr_0_542};
		}
		case 333: {
			return (struct arr_0) {11, constantarr_0_543};
		}
		case 334: {
			return (struct arr_0) {12, constantarr_0_100};
		}
		case 335: {
			return (struct arr_0) {11, constantarr_0_85};
		}
		case 336: {
			return (struct arr_0) {8, constantarr_0_544};
		}
		case 337: {
			return (struct arr_0) {19, constantarr_0_545};
		}
		case 338: {
			return (struct arr_0) {0u, NULL};
		}
		case 339: {
			return (struct arr_0) {9, constantarr_0_546};
		}
		case 340: {
			return (struct arr_0) {10, constantarr_0_400};
		}
		case 341: {
			return (struct arr_0) {6, constantarr_0_547};
		}
		case 342: {
			return (struct arr_0) {6, constantarr_0_113};
		}
		case 343: {
			return (struct arr_0) {0u, NULL};
		}
		case 344: {
			return (struct arr_0) {8, constantarr_0_548};
		}
		case 345: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 346: {
			return (struct arr_0) {12, constantarr_0_211};
		}
		case 347: {
			return (struct arr_0) {8, constantarr_0_212};
		}
		case 348: {
			return (struct arr_0) {8, constantarr_0_212};
		}
		case 349: {
			return (struct arr_0) {6, constantarr_0_549};
		}
		case 350: {
			return (struct arr_0) {18, constantarr_0_550};
		}
		case 351: {
			return (struct arr_0) {19, constantarr_0_551};
		}
		case 352: {
			return (struct arr_0) {12, constantarr_0_486};
		}
		case 353: {
			return (struct arr_0) {8, constantarr_0_125};
		}
		case 354: {
			return (struct arr_0) {25, constantarr_0_552};
		}
		case 355: {
			return (struct arr_0) {11, constantarr_0_85};
		}
		case 356: {
			return (struct arr_0) {18, constantarr_0_221};
		}
		case 357: {
			return (struct arr_0) {21, constantarr_0_554};
		}
		case 358: {
			return (struct arr_0) {18, constantarr_0_97};
		}
		case 359: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 360: {
			return (struct arr_0) {24, constantarr_0_555};
		}
		case 361: {
			return (struct arr_0) {30, constantarr_0_556};
		}
		case 362: {
			return (struct arr_0) {1, constantarr_0_557};
		}
		case 363: {
			return (struct arr_0) {1, constantarr_0_558};
		}
		case 364: {
			return (struct arr_0) {4, constantarr_0_559};
		}
		case 365: {
			return (struct arr_0) {7, constantarr_0_560};
		}
		case 366: {
			return (struct arr_0) {19, constantarr_0_561};
		}
		case 367: {
			return (struct arr_0) {16, constantarr_0_562};
		}
		case 368: {
			return (struct arr_0) {8, constantarr_0_563};
		}
		case 369: {
			return (struct arr_0) {11, constantarr_0_85};
		}
		case 370: {
			return (struct arr_0) {16, constantarr_0_564};
		}
		case 371: {
			return (struct arr_0) {29, constantarr_0_565};
		}
		case 372: {
			return (struct arr_0) {19, constantarr_0_566};
		}
		case 373: {
			return (struct arr_0) {9, constantarr_0_567};
		}
		case 374: {
			return (struct arr_0) {8, constantarr_0_568};
		}
		case 375: {
			return (struct arr_0) {13, constantarr_0_226};
		}
		case 376: {
			return (struct arr_0) {17, constantarr_0_569};
		}
		case 377: {
			return (struct arr_0) {16, constantarr_0_570};
		}
		case 378: {
			return (struct arr_0) {19, constantarr_0_571};
		}
		case 379: {
			return (struct arr_0) {5, constantarr_0_572};
		}
		case 380: {
			return (struct arr_0) {18, constantarr_0_573};
		}
		case 381: {
			return (struct arr_0) {6, constantarr_0_242};
		}
		case 382: {
			return (struct arr_0) {3, constantarr_0_574};
		}
		case 383: {
			return (struct arr_0) {15, constantarr_0_576};
		}
		case 384: {
			return (struct arr_0) {6, constantarr_0_242};
		}
		case 385: {
			return (struct arr_0) {20, constantarr_0_578};
		}
		case 386: {
			return (struct arr_0) {8, constantarr_0_579};
		}
		case 387: {
			return (struct arr_0) {14, constantarr_0_210};
		}
		case 388: {
			return (struct arr_0) {12, constantarr_0_580};
		}
		case 389: {
			return (struct arr_0) {10, constantarr_0_581};
		}
		case 390: {
			return (struct arr_0) {20, constantarr_0_582};
		}
		case 391: {
			return (struct arr_0) {14, constantarr_0_583};
		}
		case 392: {
			return (struct arr_0) {12, constantarr_0_584};
		}
		case 393: {
			return (struct arr_0) {13, constantarr_0_585};
		}
		case 394: {
			return (struct arr_0) {6, constantarr_0_549};
		}
		case 395: {
			return (struct arr_0) {14, constantarr_0_586};
		}
		case 396: {
			return (struct arr_0) {18, constantarr_0_587};
		}
		case 397: {
			return (struct arr_0) {12, constantarr_0_100};
		}
		case 398: {
			return (struct arr_0) {20, constantarr_0_578};
		}
		case 399: {
			return (struct arr_0) {8, constantarr_0_579};
		}
		case 400: {
			return (struct arr_0) {18, constantarr_0_589};
		}
		case 401: {
			return (struct arr_0) {11, constantarr_0_590};
		}
		case 402: {
			return (struct arr_0) {8, constantarr_0_507};
		}
		case 403: {
			return (struct arr_0) {14, constantarr_0_591};
		}
		case 404: {
			return (struct arr_0) {7, constantarr_0_592};
		}
		case 405: {
			return (struct arr_0) {13, constantarr_0_593};
		}
		case 406: {
			return (struct arr_0) {6, constantarr_0_549};
		}
		case 407: {
			return (struct arr_0) {10, constantarr_0_594};
		}
		case 408: {
			return (struct arr_0) {8, constantarr_0_595};
		}
		case 409: {
			return (struct arr_0) {14, constantarr_0_596};
		}
		case 410: {
			return (struct arr_0) {17, constantarr_0_569};
		}
		case 411: {
			return (struct arr_0) {17, constantarr_0_488};
		}
		case 412: {
			return (struct arr_0) {21, constantarr_0_597};
		}
		case 413: {
			return (struct arr_0) {23, constantarr_0_598};
		}
		case 414: {
			return (struct arr_0) {13, constantarr_0_599};
		}
		default:
			return (struct arr_0) {0, NULL};
	}
}
/* noctx-incr nat(n nat) */
uint64_t noctx_incr(uint64_t n) {
	uint8_t _0 = _less_0(n, 18446744073709551615u);
	hard_assert(_0);
	return (n + 1u);
}
/* sort-together void(a ptr<ptr<nat8>>, b ptr<arr<char>>, size nat) */
struct void_ sort_together(struct ctx* ctx, uint8_t** a, struct arr_0* b, uint64_t size) {
	top:;
	uint8_t _0 = _greater(size, 1u);
	if (_0) {
		swap_0(ctx, a, 0u, (size / 2u));
		swap_1(ctx, b, 0u, (size / 2u));
		uint64_t after_pivot0;
		uint64_t _1 = noctx_decr(size);
		after_pivot0 = partition_recur_together(ctx, a, b, *a, 1u, _1);
		
		uint64_t new_pivot_index1;
		new_pivot_index1 = noctx_decr(after_pivot0);
		
		swap_0(ctx, a, 0u, new_pivot_index1);
		swap_1(ctx, b, 0u, new_pivot_index1);
		sort_together(ctx, a, b, new_pivot_index1);
		a = (a + after_pivot0);
		b = (b + after_pivot0);
		size = (size - after_pivot0);
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* swap<ptr<nat8>> void(a ptr<ptr<nat8>>, lo nat, hi nat) */
struct void_ swap_0(struct ctx* ctx, uint8_t** a, uint64_t lo, uint64_t hi) {
	uint8_t* temp0;
	temp0 = *(a + lo);
	
	*(a + lo) = *(a + hi);
	return (*(a + hi) = temp0, (struct void_) {});
}
/* swap<arr<char>> void(a ptr<arr<char>>, lo nat, hi nat) */
struct void_ swap_1(struct ctx* ctx, struct arr_0* a, uint64_t lo, uint64_t hi) {
	struct arr_0 temp0;
	temp0 = *(a + lo);
	
	*(a + lo) = *(a + hi);
	return (*(a + hi) = temp0, (struct void_) {});
}
/* partition-recur-together nat(a ptr<ptr<nat8>>, b ptr<arr<char>>, pivot ptr<nat8>, l nat, r nat) */
uint64_t partition_recur_together(struct ctx* ctx, uint8_t** a, struct arr_0* b, uint8_t* pivot, uint64_t l, uint64_t r) {
	top:;
	uint8_t _0 = _lessOrEqual(l, r);
	if (_0) {
		uint8_t _1 = (*(a + l) < pivot);
		if (_1) {
			uint64_t _2 = noctx_incr(l);
			a = a;
			b = b;
			pivot = pivot;
			l = _2;
			r = r;
			goto top;
		} else {
			swap_0(ctx, a, l, r);
			swap_1(ctx, b, l, r);
			uint64_t _3 = noctx_decr(r);
			a = a;
			b = b;
			pivot = pivot;
			l = l;
			r = _3;
			goto top;
		}
	} else {
		return l;
	}
}
/* noctx-decr nat(n nat) */
uint64_t noctx_decr(uint64_t n) {
	uint8_t _0 = _equal_0(n, 0u);
	hard_forbid(_0);
	return (n - 1u);
}
/* fill-code-names-recur void(code-names ptr<arr<char>>, end-code-names ptr<arr<char>>, code-ptrs ptr<ptr<nat8>>, fun-ptrs ptr<ptr<nat8>>, fun-names ptr<arr<char>>) */
struct void_ fill_code_names_recur(struct ctx* ctx, struct arr_0* code_names, struct arr_0* end_code_names, uint8_t** code_ptrs, uint8_t** fun_ptrs, struct arr_0* fun_names) {
	top:;
	uint8_t _0 = (code_names < end_code_names);
	if (_0) {
		uint64_t _1 = funs_count_67();
		struct arr_0 _2 = get_fun_name(ctx, *code_ptrs, fun_ptrs, fun_names, _1);
		*code_names = _2;
		struct arr_0* _3 = incr_3(code_names);
		uint8_t** _4 = incr_2(code_ptrs);
		code_names = _3;
		end_code_names = end_code_names;
		code_ptrs = _4;
		fun_ptrs = fun_ptrs;
		fun_names = fun_names;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* get-fun-name arr<char>(code-ptr ptr<nat8>, fun-ptrs ptr<ptr<nat8>>, fun-names ptr<arr<char>>, size nat) */
struct arr_0 get_fun_name(struct ctx* ctx, uint8_t* code_ptr, uint8_t** fun_ptrs, struct arr_0* fun_names, uint64_t size) {
	top:;
	uint8_t _0 = _less_0(size, 2u);
	if (_0) {
		return (struct arr_0) {11, constantarr_0_3};
	} else {
		uint8_t** _1 = incr_2(fun_ptrs);
		uint8_t _2 = (code_ptr < *_1);
		if (_2) {
			return *fun_names;
		} else {
			uint8_t** _3 = incr_2(fun_ptrs);
			struct arr_0* _4 = incr_3(fun_names);
			uint64_t _5 = noctx_decr(size);
			code_ptr = code_ptr;
			fun_ptrs = _3;
			fun_names = _4;
			size = _5;
			goto top;
		}
	}
}
/* incr<ptr<nat8>> ptr<ptr<nat8>>(p ptr<ptr<nat8>>) */
uint8_t** incr_2(uint8_t** p) {
	return (p + 1u);
}
/* incr<arr<char>> ptr<arr<char>>(p ptr<arr<char>>) */
struct arr_0* incr_3(struct arr_0* p) {
	return (p + 1u);
}
/* noctx-at<?t> arr<char>(a arr<arr<char>>, index nat) */
struct arr_0 noctx_at_0(struct arr_1 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* ~<?t> arr<char>(a arr<char>, b arr<char>) */
struct arr_0 _concat_0(struct ctx* ctx, struct arr_0 a, struct arr_0 b) {
	uint64_t res_size0;
	res_size0 = _plus(ctx, a.size, b.size);
	
	char* res1;
	res1 = alloc_uninitialized_0(ctx, res_size0);
	
	copy_data_from_0(ctx, res1, a.data, a.size);
	copy_data_from_0(ctx, (res1 + a.size), b.data, b.size);
	return (struct arr_0) {res_size0, res1};
}
/* + nat(a nat, b nat) */
uint64_t _plus(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint64_t res0;
	res0 = (a + b);
	
	uint8_t _0 = _greaterOrEqual(res0, a);uint8_t _1;
	
	if (_0) {
		_1 = _greaterOrEqual(res0, b);
	} else {
		_1 = 0;
	}
	assert(ctx, _1);
	return res0;
}
/* >=<nat> bool(a nat, b nat) */
uint8_t _greaterOrEqual(uint64_t a, uint64_t b) {
	uint8_t _0 = _less_0(a, b);
	return not(_0);
}
/* alloc-uninitialized<?t> ptr<char>(size nat) */
char* alloc_uninitialized_0(struct ctx* ctx, uint64_t size) {
	uint8_t* _0 = alloc(ctx, (size * sizeof(char)));
	return (char*) _0;
}
/* alloc ptr<nat8>(size-bytes nat) */
uint8_t* alloc(struct ctx* ctx, uint64_t size_bytes) {
	struct gc* _0 = get_gc(ctx);
	return gc_alloc(ctx, _0, size_bytes);
}
/* gc-alloc ptr<nat8>(gc gc, size nat) */
uint8_t* gc_alloc(struct ctx* ctx, struct gc* gc, uint64_t size) {
	struct opt_5 _0 = try_gc_alloc(gc, size);
	switch (_0.kind) {
		case 0: {
			return todo_1();
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			return s0.value;
		}
		default:
			return NULL;
	}
}
/* todo<ptr<nat8>> ptr<nat8>() */
uint8_t* todo_1(void) {
	(abort(), (struct void_) {});
	return NULL;
}
/* copy-data-from<?t> void(to ptr<char>, from ptr<char>, len nat) */
struct void_ copy_data_from_0(struct ctx* ctx, char* to, char* from, uint64_t len) {
	return (memcpy((uint8_t*) to, (uint8_t*) from, (len * sizeof(char))), (struct void_) {});
}
/* tail<arr<?t>> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 tail_0(struct ctx* ctx, struct arr_1 a) {
	uint8_t _0 = empty__q_1(a);
	forbid_0(ctx, _0);
	struct arrow _1 = _arrow(ctx, 1u, a.size);
	return subscript_1(ctx, a, _1);
}
/* forbid void(condition bool) */
struct void_ forbid_0(struct ctx* ctx, uint8_t condition) {
	return forbid_1(ctx, condition, (struct arr_0) {13, constantarr_0_5});
}
/* forbid void(condition bool, message arr<char>) */
struct void_ forbid_1(struct ctx* ctx, uint8_t condition, struct arr_0 message) {
	uint8_t _0 = condition;
	if (_0) {
		return fail(ctx, message);
	} else {
		return (struct void_) {};
	}
}
/* subscript<?t> arr<arr<char>>(a arr<arr<char>>, range arrow<nat, nat>) */
struct arr_1 subscript_1(struct ctx* ctx, struct arr_1 a, struct arrow range) {
	uint8_t _0 = _lessOrEqual(range.from, range.to);
	assert(ctx, _0);
	uint8_t _1 = _lessOrEqual(range.to, a.size);
	assert(ctx, _1);
	uint64_t _2 = _minus_2(ctx, range.to, range.from);
	return (struct arr_1) {_2, (a.data + range.from)};
}
/* - nat(a nat, b nat) */
uint64_t _minus_2(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint8_t _0 = _greaterOrEqual(a, b);
	assert(ctx, _0);
	return (a - b);
}
/* -><nat, nat> arrow<nat, nat>(from nat, to nat) */
struct arrow _arrow(struct ctx* ctx, uint64_t from, uint64_t to) {
	return (struct arrow) {from, to};
}
/* get-global-ctx global-ctx() */
struct global_ctx* get_global_ctx(struct ctx* ctx) {
	return (struct global_ctx*) ctx->gctx_ptr;
}
/* new-island.lambda0 void(it exception) */
struct void_ new_island__lambda0(struct ctx* ctx, struct void_ _closure, struct exception it) {
	return default_exception_handler(ctx, it);
}
/* default-log-handler void(a logged) */
struct void_ default_log_handler(struct ctx* ctx, struct logged* a) {
	struct arr_0 _0 = to_str_0(ctx, a->level);
	struct arr_0 _1 = _concat_0(ctx, _0, (struct arr_0) {2, constantarr_0_9});
	struct arr_0 _2 = _concat_0(ctx, _1, a->message);
	return print(_2);
}
/* print void(a arr<char>) */
struct void_ print(struct arr_0 a) {
	print_no_newline(a);
	return print_no_newline((struct arr_0) {1, constantarr_0_1});
}
/* print-no-newline void(a arr<char>) */
struct void_ print_no_newline(struct arr_0 a) {
	int32_t _0 = stdout();
	return write_no_newline(_0, a);
}
/* stdout int32() */
int32_t stdout(void) {
	return 1;
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
			return (struct arr_0) {0, NULL};
	}
}
/* new-island.lambda1 void(log logged) */
struct void_ new_island__lambda1(struct ctx* ctx, struct void_ _closure, struct logged* log) {
	return default_log_handler(ctx, log);
}
/* new-gc gc() */
struct gc new_gc(void) {
	uint8_t* mark_begin0;
	uint8_t* _0 = malloc(16777216u);
	mark_begin0 = (uint8_t*) _0;
	
	uint8_t* mark_end1;
	mark_end1 = (mark_begin0 + 16777216u);
	
	uint64_t* data_begin2;
	uint8_t* _1 = malloc((16777216u * sizeof(uint64_t)));
	data_begin2 = (uint64_t*) _1;
	
	uint64_t* data_end3;
	data_end3 = (data_begin2 + 16777216u);
	
	(memset((uint8_t*) mark_begin0, 0u, 16777216u), (struct void_) {});
	struct lock _2 = new_lock();
	return (struct gc) {_2, 0u, (struct opt_1) {0, .as0 = (struct none) {}}, 0, 16777216u, mark_begin0, mark_begin0, mark_end1, data_begin2, data_begin2, data_end3};
}
/* new-thread-safe-counter thread-safe-counter() */
struct thread_safe_counter new_thread_safe_counter_0(void) {
	return new_thread_safe_counter_1(0u);
}
/* new-thread-safe-counter thread-safe-counter(init nat) */
struct thread_safe_counter new_thread_safe_counter_1(uint64_t init) {
	struct lock _0 = new_lock();
	return (struct thread_safe_counter) {_0, init};
}
/* do-main fut<nat>(gctx global-ctx, island island, argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<nat>, ctx, arr<arr<char>>>) */
struct fut_0* do_main(struct global_ctx* gctx, struct island* island, int32_t argc, char** argv, fun_ptr2 main_ptr) {
	struct exception_ctx ectx0;
	ectx0 = new_exception_ctx();
	
	struct log_ctx log_ctx1;
	log_ctx1 = new_log_ctx();
	
	struct thread_local_stuff tls2;
	tls2 = (struct thread_local_stuff) {(&ectx0), (&log_ctx1)};
	
	struct ctx ctx_by_val3;
	ctx_by_val3 = new_ctx(gctx, (&tls2), island, 0u);
	
	struct ctx* ctx4;
	ctx4 = (&ctx_by_val3);
	
	struct fun_act2 add5;
	add5 = (struct fun_act2) {0, .as0 = (struct void_) {}};
	
	struct arr_4 all_args6;
	all_args6 = (struct arr_4) {(uint64_t) (int64_t) argc, argv};
	
	return call_w_ctx_218(add5, ctx4, all_args6, main_ptr);
}
/* new-exception-ctx exception-ctx() */
struct exception_ctx new_exception_ctx(void) {
	return (struct exception_ctx) {NULL, (struct exception) {(struct arr_0) {0u, NULL}, (struct backtrace) {(struct arr_1) {0u, NULL}}}};
}
/* new-log-ctx log-ctx() */
struct log_ctx new_log_ctx(void) {
	return (struct log_ctx) {(struct fun1_1) {0}};
}
/* new-ctx ctx(gctx global-ctx, tls thread-local-stuff, island island, exclusion nat) */
struct ctx new_ctx(struct global_ctx* gctx, struct thread_local_stuff* tls, struct island* island, uint64_t exclusion) {
	uint8_t* gc_ctx0;
	struct gc_ctx* _0 = get_gc_ctx_1((&island->gc));
	gc_ctx0 = (uint8_t*) _0;
	
	struct exception_ctx* exception_ctx1;
	exception_ctx1 = tls->exception_ctx;
	
	struct log_ctx* log_ctx2;
	log_ctx2 = tls->log_ctx;
	
	log_ctx2->handler = (&island->gc_root)->log_handler;
	return (struct ctx) {(uint8_t*) gctx, island->id, exclusion, gc_ctx0, (uint8_t*) exception_ctx1, (uint8_t*) log_ctx2};
}
/* get-gc-ctx gc-ctx(gc gc) */
struct gc_ctx* get_gc_ctx_1(struct gc* gc) {
	acquire_lock((&gc->lk));
	struct gc_ctx* res3;
	struct opt_1 _0 = gc->context_head;
	switch (_0.kind) {
		case 0: {
			struct gc_ctx* c0;
			uint8_t* _1 = malloc(sizeof(struct gc_ctx));
			c0 = (struct gc_ctx*) _1;
			
			c0->gc = gc;
			c0->next_ctx = (struct opt_1) {0, .as0 = (struct none) {}};
			res3 = c0;
			break;
		}
		case 1: {
			struct some_1 s1 = _0.as1;
			
			struct gc_ctx* c2;
			c2 = s1.value;
			
			gc->context_head = c2->next_ctx;
			c2->next_ctx = (struct opt_1) {0, .as0 = (struct none) {}};
			res3 = c2;
			break;
		}
		default:
			NULL;
	}
	
	release_lock((&gc->lk));
	return res3;
}
/* acquire-lock void(a lock) */
struct void_ acquire_lock(struct lock* a) {
	return acquire_lock_recur(a, 0u);
}
/* acquire-lock-recur void(a lock, n-tries nat) */
struct void_ acquire_lock_recur(struct lock* a, uint64_t n_tries) {
	top:;
	uint8_t _0 = try_acquire_lock(a);
	uint8_t _1 = not(_0);
	if (_1) {
		uint8_t _2 = _equal_0(n_tries, 1000u);
		if (_2) {
			return todo_0();
		} else {
			yield_thread();
			uint64_t _3 = noctx_incr(n_tries);
			a = a;
			n_tries = _3;
			goto top;
		}
	} else {
		return (struct void_) {};
	}
}
/* try-acquire-lock bool(a lock) */
uint8_t try_acquire_lock(struct lock* a) {
	return try_set((&a->is_locked));
}
/* try-set bool(a atomic-bool) */
uint8_t try_set(struct _atomic_bool* a) {
	return try_change(a, 0);
}
/* try-change bool(a atomic-bool, old-value bool) */
uint8_t try_change(struct _atomic_bool* a, uint8_t old_value) {
	uint8_t* _0 = (&a->value);
	uint8_t* _1 = (&old_value);
	uint8_t _2 = not(old_value);
	return atomic_compare_exchange_strong(_0, _1, _2);
}
/* yield-thread void() */
struct void_ yield_thread(void) {
	int32_t err0;
	err0 = pthread_yield();
	
	uint8_t _0 = _equal_2(err0, 0);
	return hard_assert(_0);
}
/* ==<int32> bool(a int32, b int32) */
uint8_t _equal_2(int32_t a, int32_t b) {
	struct comparison _0 = compare_124(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* compare<int-32> (generated) (generated) */
struct comparison compare_124(int32_t a, int32_t b) {
	uint8_t _0 = (a < b);
	if (_0) {
		return (struct comparison) {0, .as0 = (struct less) {}};
	} else {
		uint8_t _1 = (b < a);
		if (_1) {
			return (struct comparison) {2, .as2 = (struct greater) {}};
		} else {
			return (struct comparison) {1, .as1 = (struct equal) {}};
		}
	}
}
/* release-lock void(l lock) */
struct void_ release_lock(struct lock* l) {
	return must_unset((&l->is_locked));
}
/* must-unset void(a atomic-bool) */
struct void_ must_unset(struct _atomic_bool* a) {
	uint8_t did_unset0;
	did_unset0 = try_unset(a);
	
	return hard_assert(did_unset0);
}
/* try-unset bool(a atomic-bool) */
uint8_t try_unset(struct _atomic_bool* a) {
	return try_change(a, 1);
}
/* add-first-task fut<nat>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<nat>, ctx, arr<arr<char>>>) */
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr) {
	struct fut_0* res0;
	struct fut_1* _0 = delay(ctx);
	struct island_and_exclusion _1 = cur_island_and_exclusion(ctx);
	struct add_first_task__lambda0* temp0;
	uint8_t* _2 = alloc(ctx, sizeof(struct add_first_task__lambda0));
	temp0 = (struct add_first_task__lambda0*) _2;
	
	*temp0 = (struct add_first_task__lambda0) {all_args, main_ptr};
	res0 = then2(ctx, _0, (struct fun_ref0) {_1, (struct fun_act0_1) {0, .as0 = temp0}});
	
	handle_exceptions(ctx, res0);
	return res0;
}
/* then2<nat> fut<nat>(f fut<void>, cb fun-ref0<nat>) */
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb) {
	struct island_and_exclusion _0 = cur_island_and_exclusion(ctx);
	struct then2__lambda0* temp0;
	uint8_t* _1 = alloc(ctx, sizeof(struct then2__lambda0));
	temp0 = (struct then2__lambda0*) _1;
	
	*temp0 = (struct then2__lambda0) {cb};
	return then(ctx, f, (struct fun_ref1) {_0, (struct fun_act1_2) {0, .as0 = temp0}});
}
/* then<?out, void> fut<nat>(f fut<void>, cb fun-ref1<nat, void>) */
struct fut_0* then(struct ctx* ctx, struct fut_1* f, struct fun_ref1 cb) {
	struct fut_0* res0;
	res0 = new_unresolved_fut(ctx);
	
	struct then__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct then__lambda0));
	temp0 = (struct then__lambda0*) _0;
	
	*temp0 = (struct then__lambda0) {cb, res0};
	then_void_0(ctx, f, (struct fun_act1_1) {0, .as0 = temp0});
	return res0;
}
/* new-unresolved-fut<?out> fut<nat>() */
struct fut_0* new_unresolved_fut(struct ctx* ctx) {
	struct fut_0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct fut_0));
	temp0 = (struct fut_0*) _0;
	
	struct lock _1 = new_lock();
	*temp0 = (struct fut_0) {_1, (struct fut_state_0) {0, .as0 = (struct fut_state_callbacks_0) {(struct opt_0) {0, .as0 = (struct none) {}}}}};
	return temp0;
}
/* then-void<?in> void(f fut<void>, cb fun-act1<void, result<void, exception>>) */
struct void_ then_void_0(struct ctx* ctx, struct fut_1* f, struct fun_act1_1 cb) {
	acquire_lock((&f->lk));
	struct fut_state_1 _0 = f->state;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_1 cbs0 = _0.as0;
			
			struct fut_callback_node_1* temp0;
			uint8_t* _1 = alloc(ctx, sizeof(struct fut_callback_node_1));
			temp0 = (struct fut_callback_node_1*) _1;
			
			*temp0 = (struct fut_callback_node_1) {cb, cbs0.head};
			f->state = (struct fut_state_1) {0, .as0 = (struct fut_state_callbacks_1) {(struct opt_7) {1, .as1 = (struct some_7) {temp0}}}};
			break;
		}
		case 1: {
			struct fut_state_resolved_1 r1 = _0.as1;
			
			subscript_2(ctx, cb, (struct result_1) {0, .as0 = (struct ok_1) {r1.value}});
			break;
		}
		case 2: {
			struct exception e2 = _0.as2;
			
			subscript_2(ctx, cb, (struct result_1) {1, .as1 = (struct err) {e2}});
			break;
		}
		default:
			(struct void_) {};
	}
	return release_lock((&f->lk));
}
/* subscript<void, result<?t, exception>> void(a fun-act1<void, result<void, exception>>, p0 result<void, exception>) */
struct void_ subscript_2(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0) {
	return call_w_ctx_134(a, ctx, p0);
}
/* call-w-ctx<void, result<void, exception>> (generated) (generated) */
struct void_ call_w_ctx_134(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0) {
	struct fun_act1_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then__lambda0* closure0 = _0.as0;
			
			return then__lambda0(ctx, closure0, p0);
		}
		default:
			return (struct void_) {};
	}
}
/* forward-to<?out> void(from fut<nat>, to fut<nat>) */
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to) {
	struct forward_to__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct forward_to__lambda0));
	temp0 = (struct forward_to__lambda0*) _0;
	
	*temp0 = (struct forward_to__lambda0) {to};
	return then_void_1(ctx, from, (struct fun_act1_0) {0, .as0 = temp0});
}
/* then-void<?t> void(f fut<nat>, cb fun-act1<void, result<nat, exception>>) */
struct void_ then_void_1(struct ctx* ctx, struct fut_0* f, struct fun_act1_0 cb) {
	acquire_lock((&f->lk));
	struct fut_state_0 _0 = f->state;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_0 cbs0 = _0.as0;
			
			struct fut_callback_node_0* temp0;
			uint8_t* _1 = alloc(ctx, sizeof(struct fut_callback_node_0));
			temp0 = (struct fut_callback_node_0*) _1;
			
			*temp0 = (struct fut_callback_node_0) {cb, cbs0.head};
			f->state = (struct fut_state_0) {0, .as0 = (struct fut_state_callbacks_0) {(struct opt_0) {1, .as1 = (struct some_0) {temp0}}}};
			break;
		}
		case 1: {
			struct fut_state_resolved_0 r1 = _0.as1;
			
			subscript_3(ctx, cb, (struct result_0) {0, .as0 = (struct ok_0) {r1.value}});
			break;
		}
		case 2: {
			struct exception e2 = _0.as2;
			
			subscript_3(ctx, cb, (struct result_0) {1, .as1 = (struct err) {e2}});
			break;
		}
		default:
			(struct void_) {};
	}
	return release_lock((&f->lk));
}
/* subscript<void, result<?t, exception>> void(a fun-act1<void, result<nat, exception>>, p0 result<nat, exception>) */
struct void_ subscript_3(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0) {
	return call_w_ctx_138(a, ctx, p0);
}
/* call-w-ctx<void, result<nat, exception>> (generated) (generated) */
struct void_ call_w_ctx_138(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0) {
	struct fun_act1_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* closure0 = _0.as0;
			
			return forward_to__lambda0(ctx, closure0, p0);
		}
		case 1: {
			struct void_ closure1 = _0.as1;
			
			return handle_exceptions__lambda0(ctx, closure1, p0);
		}
		default:
			return (struct void_) {};
	}
}
/* resolve-or-reject<?t> void(f fut<nat>, result result<nat, exception>) */
struct void_ resolve_or_reject(struct ctx* ctx, struct fut_0* f, struct result_0 result) {
	acquire_lock((&f->lk));
	struct fut_state_0 _0 = f->state;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_0 cbs0 = _0.as0;
			
			resolve_or_reject_recur(ctx, cbs0.head, result);
			break;
		}
		case 1: {
			todo_0();
			break;
		}
		case 2: {
			todo_0();
			break;
		}
		default:
			(struct void_) {};
	}
	struct result_0 _1 = result;struct fut_state_0 _2;
	
	switch (_1.kind) {
		case 0: {
			struct ok_0 o1 = _1.as0;
			
			_2 = (struct fut_state_0) {1, .as1 = (struct fut_state_resolved_0) {o1.value}};
			break;
		}
		case 1: {
			struct err e2 = _1.as1;
			
			struct exception ex3;
			ex3 = e2.value;
			
			_2 = (struct fut_state_0) {2, .as2 = ex3};
			break;
		}
		default:
			(struct fut_state_0) {0};
	}
	f->state = _2;
	return release_lock((&f->lk));
}
/* resolve-or-reject-recur<?t> void(node opt<fut-callback-node<nat>>, value result<nat, exception>) */
struct void_ resolve_or_reject_recur(struct ctx* ctx, struct opt_0 node, struct result_0 value) {
	top:;
	struct opt_0 _0 = node;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_0 s0 = _0.as1;
			
			struct void_ _1 = subscript_3(ctx, s0.value->cb, value);
			drop_0(_1);
			node = s0.value->next_node;
			value = value;
			goto top;
		}
		default:
			return (struct void_) {};
	}
}
/* drop<void> void(_ void) */
struct void_ drop_0(struct void_ _p0) {
	return (struct void_) {};
}
/* forward-to<?out>.lambda0 void(it result<nat, exception>) */
struct void_ forward_to__lambda0(struct ctx* ctx, struct forward_to__lambda0* _closure, struct result_0 it) {
	return resolve_or_reject(ctx, _closure->to, it);
}
/* subscript<?out, ?in> fut<nat>(f fun-ref1<nat, void>, p0 void) */
struct fut_0* subscript_4(struct ctx* ctx, struct fun_ref1 f, struct void_ p0) {
	struct island* island0;
	island0 = get_island(ctx, f.island_and_exclusion.island);
	
	struct fut_0* res1;
	res1 = new_unresolved_fut(ctx);
	
	struct subscript_4__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct subscript_4__lambda0));
	temp0 = (struct subscript_4__lambda0*) _0;
	
	*temp0 = (struct subscript_4__lambda0) {f, p0, res1};
	add_task_0(ctx, island0, f.island_and_exclusion.exclusion, (struct fun_act0_0) {1, .as1 = temp0});
	return res1;
}
/* get-island island(island-id nat) */
struct island* get_island(struct ctx* ctx, uint64_t island_id) {
	struct global_ctx* _0 = get_global_ctx(ctx);
	return subscript_5(ctx, _0->islands, island_id);
}
/* subscript<island> island(a arr<island>, index nat) */
struct island* subscript_5(struct ctx* ctx, struct arr_3 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	assert(ctx, _0);
	return noctx_at_1(a, index);
}
/* noctx-at<?t> island(a arr<island>, index nat) */
struct island* noctx_at_1(struct arr_3 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* add-task void(a island, exclusion nat, action fun-act0<void>) */
struct void_ add_task_0(struct ctx* ctx, struct island* a, uint64_t exclusion, struct fun_act0_0 action) {
	uint64_t _0 = no_timestamp();
	return add_task_1(ctx, a, _0, exclusion, action);
}
/* add-task void(a island, timestamp nat, exclusion nat, action fun-act0<void>) */
struct void_ add_task_1(struct ctx* ctx, struct island* a, uint64_t timestamp, uint64_t exclusion, struct fun_act0_0 action) {
	struct task_queue_node* node0;
	node0 = new_task_queue_node(ctx, (struct task) {timestamp, exclusion, action});
	
	acquire_lock((&a->tasks_lock));
	struct task_queue* _0 = tasks(a);
	insert_task(_0, node0);
	release_lock((&a->tasks_lock));
	return broadcast((&a->gctx->may_be_work_to_do));
}
/* new-task-queue-node task-queue-node(task task) */
struct task_queue_node* new_task_queue_node(struct ctx* ctx, struct task task) {
	struct task_queue_node* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct task_queue_node));
	temp0 = (struct task_queue_node*) _0;
	
	*temp0 = (struct task_queue_node) {task, (struct opt_2) {0, .as0 = (struct none) {}}};
	return temp0;
}
/* insert-task void(a task-queue, inserted task-queue-node) */
struct void_ insert_task(struct task_queue* a, struct task_queue_node* inserted) {
	uint64_t size_before0;
	size_before0 = size_0(a);
	
	struct opt_2 _0 = a->head;
	switch (_0.kind) {
		case 0: {
			a->head = (struct opt_2) {1, .as1 = (struct some_2) {inserted}};
			break;
		}
		case 1: {
			struct some_2 s1 = _0.as1;
			
			struct task_queue_node* head2;
			head2 = s1.value;
			
			uint8_t _1 = _lessOrEqual(head2->task.time, inserted->task.time);
			if (_1) {
				insert_recur(head2, inserted);
			} else {
				inserted->next = (struct opt_2) {1, .as1 = (struct some_2) {head2}};
				a->head = (struct opt_2) {1, .as1 = (struct some_2) {inserted}};
			}
			break;
		}
		default:
			(struct void_) {};
	}
	uint64_t size_after3;
	size_after3 = size_0(a);
	
	uint8_t _2 = _equal_0((size_before0 + 1u), size_after3);
	return hard_assert(_2);
}
/* size nat(a task-queue) */
uint64_t size_0(struct task_queue* a) {
	return size_recur(a->head, 0u);
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
			
			node = s0.value->next;
			acc = (acc + 1u);
			goto top;
		}
		default:
			return 0;
	}
}
/* insert-recur void(prev task-queue-node, inserted task-queue-node) */
struct void_ insert_recur(struct task_queue_node* prev, struct task_queue_node* inserted) {
	top:;
	struct opt_2 _0 = prev->next;
	switch (_0.kind) {
		case 0: {
			return (prev->next = (struct opt_2) {1, .as1 = (struct some_2) {inserted}}, (struct void_) {});
		}
		case 1: {
			struct some_2 s0 = _0.as1;
			
			struct task_queue_node* cur1;
			cur1 = s0.value;
			
			uint8_t _1 = _lessOrEqual(cur1->task.time, inserted->task.time);
			if (_1) {
				prev = cur1;
				inserted = inserted;
				goto top;
			} else {
				inserted->next = (struct opt_2) {1, .as1 = (struct some_2) {cur1}};
				return (prev->next = (struct opt_2) {1, .as1 = (struct some_2) {inserted}}, (struct void_) {});
			}
		}
		default:
			return (struct void_) {};
	}
}
/* tasks task-queue(a island) */
struct task_queue* tasks(struct island* a) {
	return (&(&a->gc_root)->tasks);
}
/* broadcast void(c condition) */
struct void_ broadcast(struct condition* c) {
	acquire_lock((&c->lk));
	uint64_t _0 = noctx_incr(c->value);
	c->value = _0;
	return release_lock((&c->lk));
}
/* no-timestamp nat() */
uint64_t no_timestamp(void) {
	return 0u;
}
/* catch<void> void(try fun-act0<void>, catcher fun-act1<void, exception>) */
struct void_ catch(struct ctx* ctx, struct fun_act0_0 try, struct fun_act1_3 catcher) {
	struct exception_ctx* _0 = get_exception_ctx(ctx);
	return catch_with_exception_ctx(ctx, _0, try, catcher);
}
/* catch-with-exception-ctx<?t> void(ec exception-ctx, try fun-act0<void>, catcher fun-act1<void, exception>) */
struct void_ catch_with_exception_ctx(struct ctx* ctx, struct exception_ctx* ec, struct fun_act0_0 try, struct fun_act1_3 catcher) {
	struct exception old_thrown_exception0;
	old_thrown_exception0 = ec->thrown_exception;
	
	struct jmp_buf_tag* old_jmp_buf1;
	old_jmp_buf1 = ec->jmp_buf_ptr;
	
	struct jmp_buf_tag store2;
	struct bytes64 _0 = zero_0();
	struct bytes128 _1 = zero_3();
	store2 = (struct jmp_buf_tag) {_0, 0, _1};
	
	ec->jmp_buf_ptr = (&store2);
	int32_t setjmp_result3;
	setjmp_result3 = setjmp(ec->jmp_buf_ptr);
	
	uint8_t _2 = _equal_2(setjmp_result3, 0);
	if (_2) {
		struct void_ res4;
		res4 = subscript_6(ctx, try);
		
		ec->jmp_buf_ptr = old_jmp_buf1;
		ec->thrown_exception = old_thrown_exception0;
		return res4;
	} else {
		int32_t _3 = number_to_throw(ctx);
		uint8_t _4 = _equal_2(setjmp_result3, _3);
		assert(ctx, _4);
		struct exception thrown_exception5;
		thrown_exception5 = ec->thrown_exception;
		
		ec->jmp_buf_ptr = old_jmp_buf1;
		ec->thrown_exception = old_thrown_exception0;
		return subscript_7(ctx, catcher, thrown_exception5);
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
	return (struct bytes16) {0u, 0u};
}
/* zero bytes128() */
struct bytes128 zero_3(void) {
	struct bytes64 _0 = zero_0();
	struct bytes64 _1 = zero_0();
	return (struct bytes128) {_0, _1};
}
/* subscript<?t> void(a fun-act0<void>) */
struct void_ subscript_6(struct ctx* ctx, struct fun_act0_0 a) {
	return call_w_ctx_165(a, ctx);
}
/* call-w-ctx<void> (generated) (generated) */
struct void_ call_w_ctx_165(struct fun_act0_0 a, struct ctx* ctx) {
	struct fun_act0_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct subscript_4__lambda0__lambda0* closure0 = _0.as0;
			
			return subscript_4__lambda0__lambda0(ctx, closure0);
		}
		case 1: {
			struct subscript_4__lambda0* closure1 = _0.as1;
			
			return subscript_4__lambda0(ctx, closure1);
		}
		case 2: {
			struct subscript_9__lambda0__lambda0* closure2 = _0.as2;
			
			return subscript_9__lambda0__lambda0(ctx, closure2);
		}
		case 3: {
			struct subscript_9__lambda0* closure3 = _0.as3;
			
			return subscript_9__lambda0(ctx, closure3);
		}
		default:
			return (struct void_) {};
	}
}
/* subscript<?t, exception> void(a fun-act1<void, exception>, p0 exception) */
struct void_ subscript_7(struct ctx* ctx, struct fun_act1_3 a, struct exception p0) {
	return call_w_ctx_167(a, ctx, p0);
}
/* call-w-ctx<void, exception> (generated) (generated) */
struct void_ call_w_ctx_167(struct fun_act1_3 a, struct ctx* ctx, struct exception p0) {
	struct fun_act1_3 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct subscript_4__lambda0__lambda1* closure0 = _0.as0;
			
			return subscript_4__lambda0__lambda1(ctx, closure0, p0);
		}
		case 1: {
			struct subscript_9__lambda0__lambda1* closure1 = _0.as1;
			
			return subscript_9__lambda0__lambda1(ctx, closure1, p0);
		}
		default:
			return (struct void_) {};
	}
}
/* subscript<fut<?r>, ?p0> fut<nat>(a fun-act1<fut<nat>, void>, p0 void) */
struct fut_0* subscript_8(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0) {
	return call_w_ctx_169(a, ctx, p0);
}
/* call-w-ctx<gc-ptr(fut<nat>), void> (generated) (generated) */
struct fut_0* call_w_ctx_169(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0) {
	struct fun_act1_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* closure0 = _0.as0;
			
			return then2__lambda0(ctx, closure0, p0);
		}
		default:
			return NULL;
	}
}
/* subscript<?out, ?in>.lambda0.lambda0 void() */
struct void_ subscript_4__lambda0__lambda0(struct ctx* ctx, struct subscript_4__lambda0__lambda0* _closure) {
	struct fut_0* _0 = subscript_8(ctx, _closure->f.fun, _closure->p0);
	return forward_to(ctx, _0, _closure->res);
}
/* reject<?r> void(f fut<nat>, e exception) */
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e) {
	return resolve_or_reject(ctx, f, (struct result_0) {1, .as1 = (struct err) {e}});
}
/* subscript<?out, ?in>.lambda0.lambda1 void(it exception) */
struct void_ subscript_4__lambda0__lambda1(struct ctx* ctx, struct subscript_4__lambda0__lambda1* _closure, struct exception it) {
	return reject(ctx, _closure->res, it);
}
/* subscript<?out, ?in>.lambda0 void() */
struct void_ subscript_4__lambda0(struct ctx* ctx, struct subscript_4__lambda0* _closure) {
	struct subscript_4__lambda0__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct subscript_4__lambda0__lambda0));
	temp0 = (struct subscript_4__lambda0__lambda0*) _0;
	
	*temp0 = (struct subscript_4__lambda0__lambda0) {_closure->f, _closure->p0, _closure->res};
	struct subscript_4__lambda0__lambda1* temp1;
	uint8_t* _1 = alloc(ctx, sizeof(struct subscript_4__lambda0__lambda1));
	temp1 = (struct subscript_4__lambda0__lambda1*) _1;
	
	*temp1 = (struct subscript_4__lambda0__lambda1) {_closure->res};
	return catch(ctx, (struct fun_act0_0) {0, .as0 = temp0}, (struct fun_act1_3) {0, .as0 = temp1});
}
/* then<?out, void>.lambda0 void(result result<void, exception>) */
struct void_ then__lambda0(struct ctx* ctx, struct then__lambda0* _closure, struct result_1 result) {
	struct result_1 _0 = result;
	switch (_0.kind) {
		case 0: {
			struct ok_1 o0 = _0.as0;
			
			struct fut_0* _1 = subscript_4(ctx, _closure->cb, o0.value);
			return forward_to(ctx, _1, _closure->res);
		}
		case 1: {
			struct err e1 = _0.as1;
			
			return reject(ctx, _closure->res, e1.value);
		}
		default:
			return (struct void_) {};
	}
}
/* subscript<?out> fut<nat>(f fun-ref0<nat>) */
struct fut_0* subscript_9(struct ctx* ctx, struct fun_ref0 f) {
	struct fut_0* res0;
	res0 = new_unresolved_fut(ctx);
	
	struct island* _0 = get_island(ctx, f.island_and_exclusion.island);
	struct subscript_9__lambda0* temp0;
	uint8_t* _1 = alloc(ctx, sizeof(struct subscript_9__lambda0));
	temp0 = (struct subscript_9__lambda0*) _1;
	
	*temp0 = (struct subscript_9__lambda0) {f, res0};
	add_task_0(ctx, _0, f.island_and_exclusion.exclusion, (struct fun_act0_0) {3, .as3 = temp0});
	return res0;
}
/* subscript<fut<?r>> fut<nat>(a fun-act0<fut<nat>>) */
struct fut_0* subscript_10(struct ctx* ctx, struct fun_act0_1 a) {
	return call_w_ctx_177(a, ctx);
}
/* call-w-ctx<gc-ptr(fut<nat>)> (generated) (generated) */
struct fut_0* call_w_ctx_177(struct fun_act0_1 a, struct ctx* ctx) {
	struct fun_act0_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* closure0 = _0.as0;
			
			return add_first_task__lambda0(ctx, closure0);
		}
		default:
			return NULL;
	}
}
/* subscript<?out>.lambda0.lambda0 void() */
struct void_ subscript_9__lambda0__lambda0(struct ctx* ctx, struct subscript_9__lambda0__lambda0* _closure) {
	struct fut_0* _0 = subscript_10(ctx, _closure->f.fun);
	return forward_to(ctx, _0, _closure->res);
}
/* subscript<?out>.lambda0.lambda1 void(it exception) */
struct void_ subscript_9__lambda0__lambda1(struct ctx* ctx, struct subscript_9__lambda0__lambda1* _closure, struct exception it) {
	return reject(ctx, _closure->res, it);
}
/* subscript<?out>.lambda0 void() */
struct void_ subscript_9__lambda0(struct ctx* ctx, struct subscript_9__lambda0* _closure) {
	struct subscript_9__lambda0__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct subscript_9__lambda0__lambda0));
	temp0 = (struct subscript_9__lambda0__lambda0*) _0;
	
	*temp0 = (struct subscript_9__lambda0__lambda0) {_closure->f, _closure->res};
	struct subscript_9__lambda0__lambda1* temp1;
	uint8_t* _1 = alloc(ctx, sizeof(struct subscript_9__lambda0__lambda1));
	temp1 = (struct subscript_9__lambda0__lambda1*) _1;
	
	*temp1 = (struct subscript_9__lambda0__lambda1) {_closure->res};
	return catch(ctx, (struct fun_act0_0) {2, .as2 = temp0}, (struct fun_act1_3) {1, .as1 = temp1});
}
/* then2<nat>.lambda0 fut<nat>(ignore void) */
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore) {
	return subscript_9(ctx, _closure->cb);
}
/* cur-island-and-exclusion island-and-exclusion() */
struct island_and_exclusion cur_island_and_exclusion(struct ctx* ctx) {
	struct ctx* c0;
	c0 = ctx;
	
	return (struct island_and_exclusion) {c0->island_id, c0->exclusion};
}
/* delay fut<void>() */
struct fut_1* delay(struct ctx* ctx) {
	return resolved_0(ctx, (struct void_) {});
}
/* resolved<void> fut<void>(value void) */
struct fut_1* resolved_0(struct ctx* ctx, struct void_ value) {
	struct fut_1* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct fut_1));
	temp0 = (struct fut_1*) _0;
	
	struct lock _1 = new_lock();
	*temp0 = (struct fut_1) {_1, (struct fut_state_1) {1, .as1 = (struct fut_state_resolved_1) {value}}};
	return temp0;
}
/* tail<ptr<char>> arr<ptr<char>>(a arr<ptr<char>>) */
struct arr_4 tail_1(struct ctx* ctx, struct arr_4 a) {
	uint8_t _0 = empty__q_2(a);
	forbid_0(ctx, _0);
	struct arrow _1 = _arrow(ctx, 1u, a.size);
	return subscript_11(ctx, a, _1);
}
/* empty?<?t> bool(a arr<ptr<char>>) */
uint8_t empty__q_2(struct arr_4 a) {
	return _equal_0(a.size, 0u);
}
/* subscript<?t> arr<ptr<char>>(a arr<ptr<char>>, range arrow<nat, nat>) */
struct arr_4 subscript_11(struct ctx* ctx, struct arr_4 a, struct arrow range) {
	uint8_t _0 = _lessOrEqual(range.from, range.to);
	assert(ctx, _0);
	uint8_t _1 = _lessOrEqual(range.to, a.size);
	assert(ctx, _1);
	uint64_t _2 = _minus_2(ctx, range.to, range.from);
	return (struct arr_4) {_2, (a.data + range.from)};
}
/* map<arr<char>, ptr<char>> arr<arr<char>>(a arr<ptr<char>>, mapper fun-act1<arr<char>, ptr<char>>) */
struct arr_1 map(struct ctx* ctx, struct arr_4 a, struct fun_act1_4 mapper) {
	struct map__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct map__lambda0));
	temp0 = (struct map__lambda0*) _0;
	
	*temp0 = (struct map__lambda0) {mapper, a};
	return make_arr(ctx, a.size, (struct fun_act1_5) {0, .as0 = temp0});
}
/* make-arr<?out> arr<arr<char>>(size nat, f fun-act1<arr<char>, nat>) */
struct arr_1 make_arr(struct ctx* ctx, uint64_t size, struct fun_act1_5 f) {
	struct arr_0* data0;
	data0 = alloc_uninitialized_1(ctx, size);
	
	fill_ptr_range(ctx, data0, size, f);
	return (struct arr_1) {size, data0};
}
/* alloc-uninitialized<?t> ptr<arr<char>>(size nat) */
struct arr_0* alloc_uninitialized_1(struct ctx* ctx, uint64_t size) {
	uint8_t* _0 = alloc(ctx, (size * sizeof(struct arr_0)));
	return (struct arr_0*) _0;
}
/* fill-ptr-range<?t> void(begin ptr<arr<char>>, size nat, f fun-act1<arr<char>, nat>) */
struct void_ fill_ptr_range(struct ctx* ctx, struct arr_0* begin, uint64_t size, struct fun_act1_5 f) {
	return fill_ptr_range_recur(ctx, begin, 0u, size, f);
}
/* fill-ptr-range-recur<?t> void(begin ptr<arr<char>>, i nat, size nat, f fun-act1<arr<char>, nat>) */
struct void_ fill_ptr_range_recur(struct ctx* ctx, struct arr_0* begin, uint64_t i, uint64_t size, struct fun_act1_5 f) {
	top:;
	uint8_t _0 = _notEqual_1(i, size);
	if (_0) {
		struct arr_0 _1 = subscript_12(ctx, f, i);
		*(begin + i) = _1;
		uint64_t _2 = noctx_incr(i);
		begin = begin;
		i = _2;
		size = size;
		f = f;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* subscript<?t, nat> arr<char>(a fun-act1<arr<char>, nat>, p0 nat) */
struct arr_0 subscript_12(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0) {
	return call_w_ctx_194(a, ctx, p0);
}
/* call-w-ctx<arr<char>, nat-64> (generated) (generated) */
struct arr_0 call_w_ctx_194(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0) {
	struct fun_act1_5 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct map__lambda0* closure0 = _0.as0;
			
			return map__lambda0(ctx, closure0, p0);
		}
		case 1: {
			struct mut_arr_3__lambda0* closure1 = _0.as1;
			
			return mut_arr_3__lambda0(ctx, closure1, p0);
		}
		default:
			return (struct arr_0) {0, NULL};
	}
}
/* subscript<?out, ?in> arr<char>(a fun-act1<arr<char>, ptr<char>>, p0 ptr<char>) */
struct arr_0 subscript_13(struct ctx* ctx, struct fun_act1_4 a, char* p0) {
	return call_w_ctx_196(a, ctx, p0);
}
/* call-w-ctx<arr<char>, raw-ptr(char)> (generated) (generated) */
struct arr_0 call_w_ctx_196(struct fun_act1_4 a, struct ctx* ctx, char* p0) {
	struct fun_act1_4 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			return add_first_task__lambda0__lambda0(ctx, closure0, p0);
		}
		default:
			return (struct arr_0) {0, NULL};
	}
}
/* subscript<?in> ptr<char>(a arr<ptr<char>>, index nat) */
char* subscript_14(struct ctx* ctx, struct arr_4 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	assert(ctx, _0);
	return noctx_at_2(a, index);
}
/* noctx-at<?t> ptr<char>(a arr<ptr<char>>, index nat) */
char* noctx_at_2(struct arr_4 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* map<arr<char>, ptr<char>>.lambda0 arr<char>(i nat) */
struct arr_0 map__lambda0(struct ctx* ctx, struct map__lambda0* _closure, uint64_t i) {
	char* _0 = subscript_14(ctx, _closure->a, i);
	return subscript_13(ctx, _closure->mapper, _0);
}
/* to-str arr<char>(a ptr<char>) */
struct arr_0 to_str_1(char* a) {
	char* _0 = find_cstr_end(a);
	return arr_from_begin_end(a, _0);
}
/* arr-from-begin-end<char> arr<char>(begin ptr<char>, end ptr<char>) */
struct arr_0 arr_from_begin_end(char* begin, char* end) {
	uint64_t _0 = _minus_3(end, begin);
	return (struct arr_0) {_0, begin};
}
/* -<?t> nat(a ptr<char>, b ptr<char>) */
uint64_t _minus_3(char* a, char* b) {
	return (((uint64_t) a - (uint64_t) b) / sizeof(char));
}
/* find-cstr-end ptr<char>(a ptr<char>) */
char* find_cstr_end(char* a) {
	return find_char_in_cstr(a, 0u);
}
/* find-char-in-cstr ptr<char>(a ptr<char>, c char) */
char* find_char_in_cstr(char* a, char c) {
	top:;
	uint8_t _0 = _equal_3(*a, c);
	if (_0) {
		return a;
	} else {
		uint8_t _1 = _equal_3(*a, 0u);
		if (_1) {
			return todo_2();
		} else {
			char* _2 = incr_4(a);
			a = _2;
			c = c;
			goto top;
		}
	}
}
/* ==<char> bool(a char, b char) */
uint8_t _equal_3(char a, char b) {
	struct comparison _0 = compare_206(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* compare<char> (generated) (generated) */
struct comparison compare_206(char a, char b) {
	uint8_t _0 = (a < b);
	if (_0) {
		return (struct comparison) {0, .as0 = (struct less) {}};
	} else {
		uint8_t _1 = (b < a);
		if (_1) {
			return (struct comparison) {2, .as2 = (struct greater) {}};
		} else {
			return (struct comparison) {1, .as1 = (struct equal) {}};
		}
	}
}
/* todo<ptr<char>> ptr<char>() */
char* todo_2(void) {
	(abort(), (struct void_) {});
	return NULL;
}
/* incr<char> ptr<char>(p ptr<char>) */
char* incr_4(char* p) {
	return (p + 1u);
}
/* add-first-task.lambda0.lambda0 arr<char>(it ptr<char>) */
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it) {
	return to_str_1(it);
}
/* add-first-task.lambda0 fut<nat>() */
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure) {
	struct arr_4 args0;
	args0 = tail_1(ctx, _closure->all_args);
	
	struct arr_1 _0 = map(ctx, args0, (struct fun_act1_4) {0, .as0 = (struct void_) {}});
	return _closure->main_ptr(ctx, _0);
}
/* handle-exceptions<nat> void(a fut<nat>) */
struct void_ handle_exceptions(struct ctx* ctx, struct fut_0* a) {
	return then_void_1(ctx, a, (struct fun_act1_0) {1, .as1 = (struct void_) {}});
}
/* subscript<void, exception> void(a fun1<void, exception>, p0 exception) */
struct void_ subscript_15(struct ctx* ctx, struct fun1_0 a, struct exception p0) {
	return call_w_ctx_213(a, ctx, p0);
}
/* call-w-ctx<void, exception> (generated) (generated) */
struct void_ call_w_ctx_213(struct fun1_0 a, struct ctx* ctx, struct exception p0) {
	struct fun1_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			return new_island__lambda0(ctx, closure0, p0);
		}
		default:
			return (struct void_) {};
	}
}
/* exception-handler fun1<void, exception>(a island) */
struct fun1_0 exception_handler(struct ctx* ctx, struct island* a) {
	return (&a->gc_root)->exception_handler;
}
/* get-cur-island island() */
struct island* get_cur_island(struct ctx* ctx) {
	return get_island(ctx, ctx->island_id);
}
/* handle-exceptions<nat>.lambda0 void(result result<nat, exception>) */
struct void_ handle_exceptions__lambda0(struct ctx* ctx, struct void_ _closure, struct result_0 result) {
	struct result_0 _0 = result;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct err e0 = _0.as1;
			
			struct island* _1 = get_cur_island(ctx);
			struct fun1_0 _2 = exception_handler(ctx, _1);
			return subscript_15(ctx, _2, e0.value);
		}
		default:
			return (struct void_) {};
	}
}
/* do-main.lambda0 fut<nat>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<nat>, ctx, arr<arr<char>>>) */
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr) {
	return add_first_task(ctx, all_args, main_ptr);
}
/* call-w-ctx<gc-ptr(fut<nat>), arr<ptr<char>>, some fun ptr type> (generated) (generated) */
struct fut_0* call_w_ctx_218(struct fun_act2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1) {
	struct fun_act2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			return do_main__lambda0(ctx, closure0, p0, p1);
		}
		default:
			return NULL;
	}
}
/* run-threads void(n-threads nat, gctx global-ctx) */
struct void_ run_threads(uint64_t n_threads, struct global_ctx* gctx) {
	uint64_t* threads0;
	threads0 = unmanaged_alloc_elements_0(n_threads);
	
	struct thread_args* thread_args1;
	thread_args1 = unmanaged_alloc_elements_1(n_threads);
	
	uint64_t actual_n_threads2;
	actual_n_threads2 = noctx_decr(n_threads);
	
	start_threads_recur(0u, actual_n_threads2, threads0, thread_args1, gctx);
	thread_function(actual_n_threads2, gctx);
	join_threads_recur(0u, actual_n_threads2, threads0);
	unmanaged_free_0(threads0);
	return unmanaged_free_1(thread_args1);
}
/* unmanaged-alloc-elements<by-val<thread-args>> ptr<thread-args>(size-elements nat) */
struct thread_args* unmanaged_alloc_elements_1(uint64_t size_elements) {
	uint8_t* _0 = unmanaged_alloc_bytes((size_elements * sizeof(struct thread_args)));
	return (struct thread_args*) _0;
}
/* start-threads-recur void(i nat, n-threads nat, threads ptr<nat>, thread-args-begin ptr<thread-args>, gctx global-ctx) */
struct void_ start_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads, struct thread_args* thread_args_begin, struct global_ctx* gctx) {
	top:;
	uint8_t _0 = _notEqual_1(i, n_threads);
	if (_0) {
		struct thread_args* thread_arg_ptr0;
		thread_arg_ptr0 = (thread_args_begin + i);
		
		*thread_arg_ptr0 = (struct thread_args) {i, gctx};
		uint64_t* thread_ptr1;
		thread_ptr1 = (threads + i);
		
		struct cell_0* _1 = as_cell(thread_ptr1);
		create_one_thread(_1, (uint8_t*) thread_arg_ptr0, thread_fun);
		uint64_t _2 = noctx_incr(i);
		i = _2;
		n_threads = n_threads;
		threads = threads;
		thread_args_begin = thread_args_begin;
		gctx = gctx;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* create-one-thread void(tid cell<nat>, thread-arg ptr<nat8>, thread-fun fun-ptr1<ptr<nat8>, ptr<nat8>>) */
struct void_ create_one_thread(struct cell_0* tid, uint8_t* thread_arg, fun_ptr1 thread_fun) {
	int32_t err0;
	err0 = pthread_create(tid, NULL, thread_fun, thread_arg);
	
	uint8_t _0 = _notEqual_2(err0, 0);
	if (_0) {
		int32_t _1 = eagain();
		uint8_t _2 = _equal_2(err0, _1);
		if (_2) {
			return todo_0();
		} else {
			return todo_0();
		}
	} else {
		return (struct void_) {};
	}
}
/* !=<int32> bool(a int32, b int32) */
uint8_t _notEqual_2(int32_t a, int32_t b) {
	uint8_t _0 = _equal_2(a, b);
	return not(_0);
}
/* eagain int32() */
int32_t eagain(void) {
	return 11;
}
/* as-cell<nat> cell<nat>(p ptr<nat>) */
struct cell_0* as_cell(uint64_t* p) {
	return (struct cell_0*) (uint8_t*) p;
}
/* thread-fun ptr<nat8>(args-ptr ptr<nat8>) */
uint8_t* thread_fun(uint8_t* args_ptr) {
	struct thread_args* args0;
	args0 = (struct thread_args*) args_ptr;
	
	thread_function(args0->thread_id, args0->gctx);
	return NULL;
}
/* thread-function void(thread-id nat, gctx global-ctx) */
struct void_ thread_function(uint64_t thread_id, struct global_ctx* gctx) {
	struct exception_ctx ectx0;
	ectx0 = new_exception_ctx();
	
	struct log_ctx log_ctx1;
	log_ctx1 = new_log_ctx();
	
	struct thread_local_stuff tls2;
	tls2 = (struct thread_local_stuff) {(&ectx0), (&log_ctx1)};
	
	return thread_function_recur(thread_id, gctx, (&tls2));
}
/* thread-function-recur void(thread-id nat, gctx global-ctx, tls thread-local-stuff) */
struct void_ thread_function_recur(uint64_t thread_id, struct global_ctx* gctx, struct thread_local_stuff* tls) {
	top:;
	uint8_t _0 = gctx->shut_down__q;
	if (_0) {
		acquire_lock((&gctx->lk));
		uint64_t _1 = noctx_decr(gctx->n_live_threads);
		gctx->n_live_threads = _1;
		assert_islands_are_shut_down(0u, gctx->islands);
		return release_lock((&gctx->lk));
	} else {
		uint8_t _2 = _greater(gctx->n_live_threads, 0u);
		hard_assert(_2);
		uint64_t last_checked0;
		last_checked0 = get_last_checked((&gctx->may_be_work_to_do));
		
		struct choose_task_result _3 = choose_task(gctx);
		switch (_3.kind) {
			case 0: {
				struct chosen_task t1 = _3.as0;
				
				do_task(gctx, tls, t1);
				break;
			}
			case 1: {
				struct no_chosen_task n2 = _3.as1;
				
				uint8_t _4 = n2.no_tasks_and_last_thread_out__q;
				if (_4) {
					hard_forbid(gctx->shut_down__q);
					gctx->shut_down__q = 1;
					broadcast((&gctx->may_be_work_to_do));
				} else {
					wait_on((&gctx->may_be_work_to_do), n2.first_task_time, last_checked0);
				}
				acquire_lock((&gctx->lk));
				uint64_t _5 = noctx_incr(gctx->n_live_threads);
				gctx->n_live_threads = _5;
				release_lock((&gctx->lk));
				break;
			}
			default:
				(struct void_) {};
		}
		thread_id = thread_id;
		gctx = gctx;
		tls = tls;
		goto top;
	}
}
/* assert-islands-are-shut-down void(i nat, islands arr<island>) */
struct void_ assert_islands_are_shut_down(uint64_t i, struct arr_3 islands) {
	top:;
	uint8_t _0 = _notEqual_1(i, islands.size);
	if (_0) {
		struct island* island0;
		island0 = noctx_at_1(islands, i);
		
		acquire_lock((&island0->tasks_lock));
		hard_forbid((&island0->gc)->needs_gc__q);
		uint8_t _1 = _equal_0(island0->n_threads_running, 0u);
		hard_assert(_1);
		struct task_queue* _2 = tasks(island0);
		uint8_t _3 = empty__q_3(_2);
		hard_assert(_3);
		release_lock((&island0->tasks_lock));
		uint64_t _4 = noctx_incr(i);
		i = _4;
		islands = islands;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* empty? bool(a task-queue) */
uint8_t empty__q_3(struct task_queue* a) {
	uint8_t _0 = has__q_0(a->head);
	return not(_0);
}
/* has?<task-queue-node> bool(a opt<task-queue-node>) */
uint8_t has__q_0(struct opt_2 a) {
	uint8_t _0 = empty__q_4(a);
	return not(_0);
}
/* empty?<?t> bool(a opt<task-queue-node>) */
uint8_t empty__q_4(struct opt_2 a) {
	struct opt_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			return 0;
		}
		default:
			return 0;
	}
}
/* get-last-checked nat(c condition) */
uint64_t get_last_checked(struct condition* c) {
	return c->value;
}
/* choose-task choose-task-result(gctx global-ctx) */
struct choose_task_result choose_task(struct global_ctx* gctx) {
	acquire_lock((&gctx->lk));
	uint64_t cur_time0;
	cur_time0 = get_monotime_nsec();
	
	struct choose_task_result res4;
	struct choose_task_result _0 = choose_task_recur(gctx->islands, 0u, cur_time0, 0, (struct opt_8) {0, .as0 = (struct none) {}});
	switch (_0.kind) {
		case 0: {
			struct chosen_task c1 = _0.as0;
			
			res4 = (struct choose_task_result) {0, .as0 = c1};
			break;
		}
		case 1: {
			struct no_chosen_task n2 = _0.as1;
			
			uint64_t _1 = noctx_decr(gctx->n_live_threads);
			gctx->n_live_threads = _1;
			uint8_t no_task_and_last_thread_out__q3;
			if (n2.no_tasks_and_last_thread_out__q) {
				no_task_and_last_thread_out__q3 = _equal_0(gctx->n_live_threads, 0u);
			} else {
				no_task_and_last_thread_out__q3 = 0;
			}
			
			res4 = (struct choose_task_result) {1, .as1 = (struct no_chosen_task) {no_task_and_last_thread_out__q3, n2.first_task_time}};
			break;
		}
		default:
			(struct choose_task_result) {0};
	}
	
	release_lock((&gctx->lk));
	return res4;
}
/* get-monotime-nsec nat() */
uint64_t get_monotime_nsec(void) {
	struct cell_1 time_cell0;
	time_cell0 = (struct cell_1) {(struct timespec) {0, 0}};
	
	int32_t err1;
	int32_t _0 = clock_monotonic();
	err1 = clock_gettime(_0, (&time_cell0));
	
	uint8_t _1 = _equal_2(err1, 0);
	if (_1) {
		struct timespec time2;
		time2 = get_0((&time_cell0));
		
		return (uint64_t) ((time2.tv_sec * 1000000000) + time2.tv_nsec);
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
	return c->value;
}
/* todo<nat> nat() */
uint64_t todo_3(void) {
	(abort(), (struct void_) {});
	return 0;
}
/* choose-task-recur choose-task-result(islands arr<island>, i nat, cur-time nat, any-tasks? bool, first-task-time opt<nat>) */
struct choose_task_result choose_task_recur(struct arr_3 islands, uint64_t i, uint64_t cur_time, uint8_t any_tasks__q, struct opt_8 first_task_time) {
	top:;
	uint8_t _0 = _equal_0(i, islands.size);
	if (_0) {
		uint8_t _1 = not(any_tasks__q);
		return (struct choose_task_result) {1, .as1 = (struct no_chosen_task) {_1, first_task_time}};
	} else {
		struct island* island0;
		island0 = noctx_at_1(islands, i);
		
		struct choose_task_in_island_result _2 = choose_task_in_island(island0, cur_time);
		switch (_2.kind) {
			case 0: {
				struct task t1 = _2.as0;
				
				return (struct choose_task_result) {0, .as0 = (struct chosen_task) {island0, (struct task_or_gc) {0, .as0 = t1}}};
			}
			case 1: {
				struct do_a_gc g2 = _2.as1;
				
				return (struct choose_task_result) {0, .as0 = (struct chosen_task) {island0, (struct task_or_gc) {1, .as1 = g2}}};
			}
			case 2: {
				struct no_task n3 = _2.as2;
				
				uint8_t new_any_tasks__q4;
				if (any_tasks__q) {
					new_any_tasks__q4 = 1;
				} else {
					new_any_tasks__q4 = n3.any_tasks__q;
				}
				
				struct opt_8 new_first_task_time5;
				new_first_task_time5 = min_time(first_task_time, n3.first_task_time);
				
				uint64_t _3 = noctx_incr(i);
				islands = islands;
				i = _3;
				cur_time = cur_time;
				any_tasks__q = new_any_tasks__q4;
				first_task_time = new_first_task_time5;
				goto top;
			}
			default:
				return (struct choose_task_result) {0};
		}
	}
}
/* choose-task-in-island choose-task-in-island-result(island island, cur-time nat) */
struct choose_task_in_island_result choose_task_in_island(struct island* island, uint64_t cur_time) {
	acquire_lock((&island->tasks_lock));
	struct choose_task_in_island_result res2;
	uint8_t _0 = (&island->gc)->needs_gc__q;
	if (_0) {
		uint8_t _1 = _equal_0(island->n_threads_running, 0u);
		if (_1) {
			res2 = (struct choose_task_in_island_result) {1, .as1 = (struct do_a_gc) {}};
		} else {
			res2 = (struct choose_task_in_island_result) {2, .as2 = (struct no_task) {1, (struct opt_8) {0, .as0 = (struct none) {}}}};
		}
	} else {
		struct task_queue* _2 = tasks(island);
		struct pop_task_result _3 = pop_task(_2, cur_time);
		switch (_3.kind) {
			case 0: {
				struct task t0 = _3.as0;
				
				res2 = (struct choose_task_in_island_result) {0, .as0 = t0};
				break;
			}
			case 1: {
				struct no_task n1 = _3.as1;
				
				res2 = (struct choose_task_in_island_result) {2, .as2 = n1};
				break;
			}
			default:
				(struct choose_task_in_island_result) {0};
		}
	}
	
	uint8_t _4 = is_no_task__q(res2);
	uint8_t _5 = not(_4);
	if (_5) {
		uint64_t _6 = noctx_incr(island->n_threads_running);
		island->n_threads_running = _6;
	} else {
		(struct void_) {};
	}
	release_lock((&island->tasks_lock));
	return res2;
}
/* pop-task pop-task-result(a task-queue, cur-time nat) */
struct pop_task_result pop_task(struct task_queue* a, uint64_t cur_time) {
	struct mut_list_0* exclusions0;
	exclusions0 = (&a->currently_running_exclusions);
	
	struct pop_task_result res4;
	struct opt_2 _0 = a->head;
	switch (_0.kind) {
		case 0: {
			res4 = (struct pop_task_result) {1, .as1 = (struct no_task) {0, (struct opt_8) {0, .as0 = (struct none) {}}}};
			break;
		}
		case 1: {
			struct some_2 s1 = _0.as1;
			
			struct task_queue_node* head2;
			head2 = s1.value;
			
			struct task task3;
			task3 = head2->task;
			
			uint8_t _1 = _lessOrEqual(task3.time, cur_time);
			if (_1) {
				uint8_t _2 = contains__q_0(exclusions0, task3.exclusion);
				if (_2) {
					struct opt_8 _3 = to_opt_time(task3.time);
					res4 = pop_recur(head2, exclusions0, cur_time, _3);
				} else {
					a->head = head2->next;
					res4 = (struct pop_task_result) {0, .as0 = head2->task};
				}
			} else {
				res4 = (struct pop_task_result) {1, .as1 = (struct no_task) {1, (struct opt_8) {1, .as1 = (struct some_8) {task3.time}}}};
			}
			break;
		}
		default:
			(struct pop_task_result) {0};
	}
	
	struct pop_task_result _4 = res4;
	switch (_4.kind) {
		case 0: {
			struct task t5 = _4.as0;
			
			push_capacity_must_be_sufficient__e(exclusions0, t5.exclusion);
			break;
		}
		case 1: {
			(struct void_) {};
			break;
		}
		default:
			(struct void_) {};
	}
	return res4;
}
/* contains?<nat> bool(a mut-list<nat>, value nat) */
uint8_t contains__q_0(struct mut_list_0* a, uint64_t value) {
	struct arr_2 _0 = temp_as_arr_0(a);
	return contains__q_1(_0, value);
}
/* contains?<?t> bool(a arr<nat>, value nat) */
uint8_t contains__q_1(struct arr_2 a, uint64_t value) {
	return contains_recur__q(a, value, 0u);
}
/* contains-recur?<?t> bool(a arr<nat>, value nat, i nat) */
uint8_t contains_recur__q(struct arr_2 a, uint64_t value, uint64_t i) {
	top:;
	uint8_t _0 = _equal_0(i, a.size);
	if (_0) {
		return 0;
	} else {
		uint64_t _1 = noctx_at_3(a, i);
		uint8_t _2 = _equal_0(_1, value);
		if (_2) {
			return 1;
		} else {
			uint64_t _3 = noctx_incr(i);
			a = a;
			value = value;
			i = _3;
			goto top;
		}
	}
}
/* noctx-at<?t> nat(a arr<nat>, index nat) */
uint64_t noctx_at_3(struct arr_2 a, uint64_t index) {
	uint8_t _0 = _less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* temp-as-arr<?t> arr<nat>(a mut-list<nat>) */
struct arr_2 temp_as_arr_0(struct mut_list_0* a) {
	struct mut_arr_0 _0 = temp_as_mut_arr(a);
	return temp_as_arr_1(_0);
}
/* temp-as-arr<?t> arr<nat>(a mut-arr<nat>) */
struct arr_2 temp_as_arr_1(struct mut_arr_0 a) {
	return a.inner;
}
/* temp-as-mut-arr<?t> mut-arr<nat>(a mut-list<nat>) */
struct mut_arr_0 temp_as_mut_arr(struct mut_list_0* a) {
	uint64_t* _0 = data_0(a);
	return mut_arr_0(a->size, _0);
}
/* data<?t> ptr<nat>(a mut-list<nat>) */
uint64_t* data_0(struct mut_list_0* a) {
	return data_1(a->backing);
}
/* data<?t> ptr<nat>(a mut-arr<nat>) */
uint64_t* data_1(struct mut_arr_0 a) {
	return a.inner.data;
}
/* pop-recur pop-task-result(prev task-queue-node, exclusions mut-list<nat>, cur-time nat, first-task-time opt<nat>) */
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list_0* exclusions, uint64_t cur_time, struct opt_8 first_task_time) {
	top:;
	struct opt_2 _0 = prev->next;
	switch (_0.kind) {
		case 0: {
			return (struct pop_task_result) {1, .as1 = (struct no_task) {1, first_task_time}};
		}
		case 1: {
			struct some_2 s0 = _0.as1;
			
			struct task_queue_node* cur1;
			cur1 = s0.value;
			
			struct task task2;
			task2 = cur1->task;
			
			uint8_t _1 = _lessOrEqual(task2.time, cur_time);
			if (_1) {
				uint8_t _2 = contains__q_0(exclusions, task2.exclusion);
				if (_2) {
					struct opt_8 _3 = first_task_time;struct opt_8 _4;
					
					switch (_3.kind) {
						case 0: {
							_4 = to_opt_time(task2.time);
							break;
						}
						case 1: {
							_4 = first_task_time;
							break;
						}
						default:
							(struct opt_8) {0};
					}
					prev = cur1;
					exclusions = exclusions;
					cur_time = cur_time;
					first_task_time = _4;
					goto top;
				} else {
					prev->next = cur1->next;
					push_capacity_must_be_sufficient__e(exclusions, task2.exclusion);
					return (struct pop_task_result) {0, .as0 = task2};
				}
			} else {
				return (struct pop_task_result) {1, .as1 = (struct no_task) {1, (struct opt_8) {1, .as1 = (struct some_8) {task2.time}}}};
			}
		}
		default:
			return (struct pop_task_result) {0};
	}
}
/* to-opt-time opt<nat>(a nat) */
struct opt_8 to_opt_time(uint64_t a) {
	uint64_t _0 = no_timestamp();
	uint8_t _1 = _equal_0(a, _0);
	if (_1) {
		return (struct opt_8) {0, .as0 = (struct none) {}};
	} else {
		return (struct opt_8) {1, .as1 = (struct some_8) {a}};
	}
}
/* push-capacity-must-be-sufficient!<nat> void(a mut-list<nat>, value nat) */
struct void_ push_capacity_must_be_sufficient__e(struct mut_list_0* a, uint64_t value) {
	uint64_t _0 = capacity_0(a);
	uint8_t _1 = _less_0(a->size, _0);
	hard_assert(_1);
	uint64_t old_size0;
	old_size0 = a->size;
	
	uint64_t _2 = noctx_incr(old_size0);
	a->size = _2;
	return noctx_set_at__e_0(a, old_size0, value);
}
/* capacity<?t> nat(a mut-list<nat>) */
uint64_t capacity_0(struct mut_list_0* a) {
	return size_1(a->backing);
}
/* size<?t> nat(a mut-arr<nat>) */
uint64_t size_1(struct mut_arr_0 a) {
	return a.inner.size;
}
/* noctx-set-at!<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_set_at__e_0(struct mut_list_0* a, uint64_t index, uint64_t value) {
	uint8_t _0 = _less_0(index, a->size);
	hard_assert(_0);
	uint64_t* _1 = data_0(a);
	return (*(_1 + index) = value, (struct void_) {});
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
			return 0;
	}
}
/* min-time opt<nat>(a opt<nat>, b opt<nat>) */
struct opt_8 min_time(struct opt_8 a, struct opt_8 b) {
	struct opt_8 _0 = a;
	switch (_0.kind) {
		case 0: {
			return b;
		}
		case 1: {
			struct some_8 sa0 = _0.as1;
			
			struct opt_8 _1 = b;
			switch (_1.kind) {
				case 0: {
					return a;
				}
				case 1: {
					struct some_8 sb1 = _1.as1;
					
					uint64_t _2 = min(sa0.value, sb1.value);
					return (struct opt_8) {1, .as1 = (struct some_8) {_2}};
				}
				default:
					return (struct opt_8) {0};
			}
		}
		default:
			return (struct opt_8) {0};
	}
}
/* min<nat> nat(a nat, b nat) */
uint64_t min(uint64_t a, uint64_t b) {
	uint8_t _0 = _less_0(a, b);
	if (_0) {
		return a;
	} else {
		return b;
	}
}
/* do-task void(gctx global-ctx, tls thread-local-stuff, chosen-task chosen-task) */
struct void_ do_task(struct global_ctx* gctx, struct thread_local_stuff* tls, struct chosen_task chosen_task) {
	struct island* island0;
	island0 = chosen_task.task_island;
	
	struct task_or_gc _0 = chosen_task.task_or_gc;
	switch (_0.kind) {
		case 0: {
			struct task task1 = _0.as0;
			
			struct ctx ctx2;
			ctx2 = new_ctx(gctx, tls, island0, task1.exclusion);
			
			call_w_ctx_165(task1.action, (&ctx2));
			acquire_lock((&island0->tasks_lock));
			struct task_queue* _1 = tasks(island0);
			return_task(_1, task1);
			release_lock((&island0->tasks_lock));
			return_ctx((&ctx2));
			break;
		}
		case 1: {
			run_garbage_collection((&island0->gc), island0->gc_root);
			broadcast((&gctx->may_be_work_to_do));
			break;
		}
		default:
			(struct void_) {};
	}
	acquire_lock((&island0->tasks_lock));
	uint64_t _2 = noctx_decr(island0->n_threads_running);
	island0->n_threads_running = _2;
	return release_lock((&island0->tasks_lock));
}
/* return-task void(a task-queue, task task) */
struct void_ return_task(struct task_queue* a, struct task task) {
	return noctx_must_remove_unordered__e((&a->currently_running_exclusions), task.exclusion);
}
/* noctx-must-remove-unordered!<nat> void(a mut-list<nat>, value nat) */
struct void_ noctx_must_remove_unordered__e(struct mut_list_0* a, uint64_t value) {
	return noctx_must_remove_unordered_recur__e(a, 0u, value);
}
/* noctx-must-remove-unordered-recur!<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_must_remove_unordered_recur__e(struct mut_list_0* a, uint64_t index, uint64_t value) {
	top:;
	uint8_t _0 = _equal_0(index, a->size);
	if (_0) {
		return todo_0();
	} else {
		uint64_t _1 = noctx_at_4(a, index);
		uint8_t _2 = _equal_0(_1, value);
		if (_2) {
			uint64_t _3 = noctx_remove_unordered_at__e(a, index);
			return drop_1(_3);
		} else {
			uint64_t _4 = noctx_incr(index);
			a = a;
			index = _4;
			value = value;
			goto top;
		}
	}
}
/* noctx-at<?t> nat(a mut-list<nat>, index nat) */
uint64_t noctx_at_4(struct mut_list_0* a, uint64_t index) {
	uint8_t _0 = _less_0(index, a->size);
	hard_assert(_0);
	uint64_t* _1 = data_0(a);
	return *(_1 + index);
}
/* drop<?t> void(_ nat) */
struct void_ drop_1(uint64_t _p0) {
	return (struct void_) {};
}
/* noctx-remove-unordered-at!<?t> nat(a mut-list<nat>, index nat) */
uint64_t noctx_remove_unordered_at__e(struct mut_list_0* a, uint64_t index) {
	uint64_t res0;
	res0 = noctx_at_4(a, index);
	
	uint64_t _0 = noctx_last(a);
	noctx_set_at__e_0(a, index, _0);
	uint64_t _1 = noctx_decr(a->size);
	a->size = _1;
	return res0;
}
/* noctx-last<?t> nat(a mut-list<nat>) */
uint64_t noctx_last(struct mut_list_0* a) {
	uint8_t _0 = empty__q_5(a);
	hard_forbid(_0);
	uint64_t _1 = noctx_decr(a->size);
	return noctx_at_4(a, _1);
}
/* empty?<?t> bool(a mut-list<nat>) */
uint8_t empty__q_5(struct mut_list_0* a) {
	return _equal_0(a->size, 0u);
}
/* return-ctx void(c ctx) */
struct void_ return_ctx(struct ctx* c) {
	return return_gc_ctx((struct gc_ctx*) c->gc_ctx_ptr);
}
/* return-gc-ctx void(gc-ctx gc-ctx) */
struct void_ return_gc_ctx(struct gc_ctx* gc_ctx) {
	struct gc* gc0;
	gc0 = gc_ctx->gc;
	
	acquire_lock((&gc0->lk));
	gc_ctx->next_ctx = gc0->context_head;
	gc0->context_head = (struct opt_1) {1, .as1 = (struct some_1) {gc_ctx}};
	return release_lock((&gc0->lk));
}
/* run-garbage-collection<by-val<island-gc-root>> void(gc gc, gc-root island-gc-root) */
struct void_ run_garbage_collection(struct gc* gc, struct island_gc_root gc_root) {
	hard_assert(gc->needs_gc__q);
	gc->needs_gc__q = 0;
	uint64_t _0 = noctx_incr(gc->gc_count);
	gc->gc_count = _0;
	(memset((uint8_t*) gc->mark_begin, 0u, gc->size_words), (struct void_) {});
	struct mark_ctx mark_ctx0;
	mark_ctx0 = (struct mark_ctx) {gc->size_words, gc->mark_begin, gc->data_begin};
	
	mark_visit_274((&mark_ctx0), gc_root);
	gc->mark_cur = gc->mark_begin;
	gc->data_cur = gc->data_begin;
	clear_free_mem(gc->mark_begin, gc->mark_end, gc->data_begin);
	return validate_gc(gc);
}
/* mark-visit<island-gc-root> (generated) (generated) */
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct island_gc_root value) {
	return mark_visit_275(mark_ctx, value.tasks);
}
/* mark-visit<task-queue> (generated) (generated) */
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct task_queue value) {
	mark_visit_276(mark_ctx, value.head);
	return mark_visit_315(mark_ctx, value.currently_running_exclusions);
}
/* mark-visit<opt<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct opt_2 value) {
	struct opt_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_2 value1 = _0.as1;
			
			return mark_visit_277(mark_ctx, value1);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<some<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct some_2 value) {
	return mark_visit_314(mark_ctx, value.value);
}
/* mark-visit<task-queue-node> (generated) (generated) */
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct task_queue_node value) {
	mark_visit_279(mark_ctx, value.task);
	return mark_visit_276(mark_ctx, value.next);
}
/* mark-visit<task> (generated) (generated) */
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct task value) {
	return mark_visit_280(mark_ctx, value.action);
}
/* mark-visit<fun-act0<void>> (generated) (generated) */
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct fun_act0_0 value) {
	struct fun_act0_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct subscript_4__lambda0__lambda0* value0 = _0.as0;
			
			return mark_visit_307(mark_ctx, value0);
		}
		case 1: {
			struct subscript_4__lambda0* value1 = _0.as1;
			
			return mark_visit_309(mark_ctx, value1);
		}
		case 2: {
			struct subscript_9__lambda0__lambda0* value2 = _0.as2;
			
			return mark_visit_311(mark_ctx, value2);
		}
		case 3: {
			struct subscript_9__lambda0* value3 = _0.as3;
			
			return mark_visit_313(mark_ctx, value3);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<subscript<?out, ?in>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct subscript_4__lambda0__lambda0 value) {
	mark_visit_282(mark_ctx, value.f);
	return mark_visit_299(mark_ctx, value.res);
}
/* mark-visit<fun-ref1<nat, void>> (generated) (generated) */
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct fun_ref1 value) {
	return mark_visit_283(mark_ctx, value.fun);
}
/* mark-visit<fun-act1<fut<nat>, void>> (generated) (generated) */
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct fun_act1_2 value) {
	struct fun_act1_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* value0 = _0.as0;
			
			return mark_visit_290(mark_ctx, value0);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<then2<nat>.lambda0> (generated) (generated) */
struct void_ mark_visit_284(struct mark_ctx* mark_ctx, struct then2__lambda0 value) {
	return mark_visit_285(mark_ctx, value.cb);
}
/* mark-visit<fun-ref0<nat>> (generated) (generated) */
struct void_ mark_visit_285(struct mark_ctx* mark_ctx, struct fun_ref0 value) {
	return mark_visit_286(mark_ctx, value.fun);
}
/* mark-visit<fun-act0<fut<nat>>> (generated) (generated) */
struct void_ mark_visit_286(struct mark_ctx* mark_ctx, struct fun_act0_1 value) {
	struct fun_act0_1 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* value0 = _0.as0;
			
			return mark_visit_289(mark_ctx, value0);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<add-first-task.lambda0> (generated) (generated) */
struct void_ mark_visit_287(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value) {
	return mark_arr_288(mark_ctx, value.all_args);
}
/* mark-arr<raw-ptr(char)> (generated) (generated) */
struct void_ mark_arr_288(struct mark_ctx* mark_ctx, struct arr_4 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(char*)));
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(add-first-task.lambda0)> (generated) (generated) */
struct void_ mark_visit_289(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct add_first_task__lambda0));
	if (_0) {
		return mark_visit_287(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(then2<nat>.lambda0)> (generated) (generated) */
struct void_ mark_visit_290(struct mark_ctx* mark_ctx, struct then2__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct then2__lambda0));
	if (_0) {
		return mark_visit_284(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<fut<nat>> (generated) (generated) */
struct void_ mark_visit_291(struct mark_ctx* mark_ctx, struct fut_0 value) {
	return mark_visit_292(mark_ctx, value.state);
}
/* mark-visit<fut-state<nat>> (generated) (generated) */
struct void_ mark_visit_292(struct mark_ctx* mark_ctx, struct fut_state_0 value) {
	struct fut_state_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_0 value0 = _0.as0;
			
			return mark_visit_293(mark_ctx, value0);
		}
		case 1: {
			return (struct void_) {};
		}
		case 2: {
			struct exception value2 = _0.as2;
			
			return mark_visit_302(mark_ctx, value2);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<fut-state-callbacks<nat>> (generated) (generated) */
struct void_ mark_visit_293(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value) {
	return mark_visit_294(mark_ctx, value.head);
}
/* mark-visit<opt<fut-callback-node<nat>>> (generated) (generated) */
struct void_ mark_visit_294(struct mark_ctx* mark_ctx, struct opt_0 value) {
	struct opt_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_0 value1 = _0.as1;
			
			return mark_visit_295(mark_ctx, value1);
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<some<fut-callback-node<nat>>> (generated) (generated) */
struct void_ mark_visit_295(struct mark_ctx* mark_ctx, struct some_0 value) {
	return mark_visit_301(mark_ctx, value.value);
}
/* mark-visit<fut-callback-node<nat>> (generated) (generated) */
struct void_ mark_visit_296(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value) {
	mark_visit_297(mark_ctx, value.cb);
	return mark_visit_294(mark_ctx, value.next_node);
}
/* mark-visit<fun-act1<void, result<nat, exception>>> (generated) (generated) */
struct void_ mark_visit_297(struct mark_ctx* mark_ctx, struct fun_act1_0 value) {
	struct fun_act1_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* value0 = _0.as0;
			
			return mark_visit_300(mark_ctx, value0);
		}
		case 1: {
			return (struct void_) {};
		}
		default:
			return (struct void_) {};
	}
}
/* mark-visit<forward-to<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_298(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value) {
	return mark_visit_299(mark_ctx, value.to);
}
/* mark-visit<gc-ptr(fut<nat>)> (generated) (generated) */
struct void_ mark_visit_299(struct mark_ctx* mark_ctx, struct fut_0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct fut_0));
	if (_0) {
		return mark_visit_291(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(forward-to<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_300(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct forward_to__lambda0));
	if (_0) {
		return mark_visit_298(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(fut-callback-node<nat>)> (generated) (generated) */
struct void_ mark_visit_301(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct fut_callback_node_0));
	if (_0) {
		return mark_visit_296(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<exception> (generated) (generated) */
struct void_ mark_visit_302(struct mark_ctx* mark_ctx, struct exception value) {
	mark_arr_303(mark_ctx, value.message);
	return mark_visit_304(mark_ctx, value.backtrace);
}
/* mark-arr<char> (generated) (generated) */
struct void_ mark_arr_303(struct mark_ctx* mark_ctx, struct arr_0 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(char)));
	
	return (struct void_) {};
}
/* mark-visit<backtrace> (generated) (generated) */
struct void_ mark_visit_304(struct mark_ctx* mark_ctx, struct backtrace value) {
	return mark_arr_306(mark_ctx, value.return_stack);
}
/* mark-elems<arr<char>> (generated) (generated) */
struct void_ mark_elems_305(struct mark_ctx* mark_ctx, struct arr_0* cur, struct arr_0* end) {
	top:;
	uint8_t _0 = (cur == end);
	if (_0) {
		return (struct void_) {};
	} else {
		mark_arr_303(mark_ctx, *cur);
		mark_ctx = mark_ctx;
		cur = (cur + 1u);
		end = end;
		goto top;
	}
}
/* mark-arr<arr<char>> (generated) (generated) */
struct void_ mark_arr_306(struct mark_ctx* mark_ctx, struct arr_1 a) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(struct arr_0)));
	if (_0) {
		return mark_elems_305(mark_ctx, a.data, (a.data + a.size));
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(subscript<?out, ?in>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_307(struct mark_ctx* mark_ctx, struct subscript_4__lambda0__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct subscript_4__lambda0__lambda0));
	if (_0) {
		return mark_visit_281(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<subscript<?out, ?in>.lambda0> (generated) (generated) */
struct void_ mark_visit_308(struct mark_ctx* mark_ctx, struct subscript_4__lambda0 value) {
	mark_visit_282(mark_ctx, value.f);
	return mark_visit_299(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(subscript<?out, ?in>.lambda0)> (generated) (generated) */
struct void_ mark_visit_309(struct mark_ctx* mark_ctx, struct subscript_4__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct subscript_4__lambda0));
	if (_0) {
		return mark_visit_308(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<subscript<?out>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_310(struct mark_ctx* mark_ctx, struct subscript_9__lambda0__lambda0 value) {
	mark_visit_285(mark_ctx, value.f);
	return mark_visit_299(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(subscript<?out>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_311(struct mark_ctx* mark_ctx, struct subscript_9__lambda0__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct subscript_9__lambda0__lambda0));
	if (_0) {
		return mark_visit_310(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<subscript<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_312(struct mark_ctx* mark_ctx, struct subscript_9__lambda0 value) {
	mark_visit_285(mark_ctx, value.f);
	return mark_visit_299(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(subscript<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_313(struct mark_ctx* mark_ctx, struct subscript_9__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct subscript_9__lambda0));
	if (_0) {
		return mark_visit_312(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(task-queue-node)> (generated) (generated) */
struct void_ mark_visit_314(struct mark_ctx* mark_ctx, struct task_queue_node* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct task_queue_node));
	if (_0) {
		return mark_visit_278(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<mut-list<nat>> (generated) (generated) */
struct void_ mark_visit_315(struct mark_ctx* mark_ctx, struct mut_list_0 value) {
	return mark_visit_316(mark_ctx, value.backing);
}
/* mark-visit<mut-arr<nat>> (generated) (generated) */
struct void_ mark_visit_316(struct mark_ctx* mark_ctx, struct mut_arr_0 value) {
	return mark_arr_317(mark_ctx, value.inner);
}
/* mark-arr<nat-64> (generated) (generated) */
struct void_ mark_arr_317(struct mark_ctx* mark_ctx, struct arr_2 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(uint64_t)));
	
	return (struct void_) {};
}
/* clear-free-mem void(mark-ptr ptr<bool>, mark-end ptr<bool>, data-ptr ptr<nat>) */
struct void_ clear_free_mem(uint8_t* mark_ptr, uint8_t* mark_end, uint64_t* data_ptr) {
	top:;
	uint8_t _0 = not((mark_ptr == mark_end));
	if (_0) {
		uint8_t _1 = not(*mark_ptr);
		if (_1) {
			*data_ptr = 18077161789910350558u;
		} else {
			(struct void_) {};
		}
		uint8_t* _2 = incr_0(mark_ptr);
		mark_ptr = _2;
		mark_end = mark_end;
		data_ptr = data_ptr;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* wait-on void(cond condition, until-time opt<nat>, last-checked nat) */
struct void_ wait_on(struct condition* cond, struct opt_8 until_time, uint64_t last_checked) {
	top:;
	uint8_t _0 = _equal_0(cond->value, last_checked);
	if (_0) {
		yield_thread();
		uint8_t _1 = before_time__q(until_time);
		if (_1) {
			cond = cond;
			until_time = until_time;
			last_checked = last_checked;
			goto top;
		} else {
			return (struct void_) {};
		}
	} else {
		return (struct void_) {};
	}
}
/* before-time? bool(until-time opt<nat>) */
uint8_t before_time__q(struct opt_8 until_time) {
	struct opt_8 _0 = until_time;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			struct some_8 s0 = _0.as1;
			
			uint64_t _1 = get_monotime_nsec();
			return _less_0(_1, s0.value);
		}
		default:
			return 0;
	}
}
/* join-threads-recur void(i nat, n-threads nat, threads ptr<nat>) */
struct void_ join_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads) {
	top:;
	uint8_t _0 = _notEqual_1(i, n_threads);
	if (_0) {
		join_one_thread(*(threads + i));
		uint64_t _1 = noctx_incr(i);
		i = _1;
		n_threads = n_threads;
		threads = threads;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* join-one-thread void(tid nat) */
struct void_ join_one_thread(uint64_t tid) {
	struct cell_2 thread_return0;
	thread_return0 = (struct cell_2) {NULL};
	
	int32_t err1;
	err1 = pthread_join(tid, (&thread_return0));
	
	uint8_t _0 = _notEqual_2(err1, 0);
	if (_0) {
		int32_t _1 = einval();
		uint8_t _2 = _equal_2(err1, _1);
		if (_2) {
			todo_0();
		} else {
			int32_t _3 = esrch();
			uint8_t _4 = _equal_2(err1, _3);
			if (_4) {
				todo_0();
			} else {
				todo_0();
			}
		}
	} else {
		(struct void_) {};
	}
	uint8_t* _5 = get_1((&thread_return0));
	uint8_t _6 = null__q_0(_5);
	return hard_assert(_6);
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
	return c->value;
}
/* unmanaged-free<nat> void(p ptr<nat>) */
struct void_ unmanaged_free_0(uint64_t* p) {
	return (free((uint8_t*) p), (struct void_) {});
}
/* unmanaged-free<by-val<thread-args>> void(p ptr<thread-args>) */
struct void_ unmanaged_free_1(struct thread_args* p) {
	return (free((uint8_t*) p), (struct void_) {});
}
/* main fut<nat>(_ arr<arr<char>>) */
struct fut_0* main_0(struct ctx* ctx, struct arr_1 _p0) {
	struct set* chili0;
	chili0 = set(ctx, (struct arr_1) {4, constantarr_1_0});
	
	uint64_t _0 = size_3(ctx, chili0);
	struct arr_0 _1 = to_str_2(ctx, _0);
	struct arr_0 _2 = _concat_0(ctx, (struct arr_0) {6, constantarr_0_13}, _1);
	print(_2);
	uint8_t _3 = subscript_20(ctx, chili0, (struct arr_0) {6, constantarr_0_11});
	struct arr_0 _4 = to_str_3(_3);
	struct arr_0 _5 = _concat_0(ctx, (struct arr_0) {12, constantarr_0_24}, _4);
	print(_5);
	uint8_t _6 = subscript_20(ctx, chili0, (struct arr_0) {6, constantarr_0_28});
	struct arr_0 _7 = to_str_3(_6);
	struct arr_0 _8 = _concat_0(ctx, (struct arr_0) {12, constantarr_0_27}, _7);
	print(_8);
	struct set* pepper_spray1;
	pepper_spray1 = set(ctx, (struct arr_1) {3, constantarr_1_1});
	
	struct set* _9 = _concat_1(ctx, chili0, pepper_spray1);
	struct arr_1 _10 = arr(ctx, _9);
	struct arr_0 _11 = join(ctx, _10, (struct arr_0) {2, constantarr_0_31});
	struct arr_0 _12 = _concat_0(ctx, (struct arr_0) {7, constantarr_0_30}, _11);
	print(_12);
	struct set* _13 = intersect(ctx, chili0, pepper_spray1);
	struct arr_1 _14 = arr(ctx, _13);
	struct arr_0 _15 = join(ctx, _14, (struct arr_0) {2, constantarr_0_31});
	struct arr_0 _16 = _concat_0(ctx, (struct arr_0) {14, constantarr_0_32}, _15);
	print(_16);
	struct set* _17 = _minus_4(ctx, chili0, pepper_spray1);
	struct arr_1 _18 = arr(ctx, _17);
	struct arr_0 _19 = join(ctx, _18, (struct arr_0) {2, constantarr_0_31});
	struct arr_0 _20 = _concat_0(ctx, (struct arr_0) {12, constantarr_0_33}, _19);
	print(_20);
	struct mut_set m2;
	m2 = mut_set(ctx, (struct arr_1) {3, constantarr_1_2});
	
	uint8_t _21 = subscript_21(ctx, m2, (struct arr_0) {6, constantarr_0_11});
	struct arr_0 _22 = to_str_3(_21);
	struct arr_0 _23 = _concat_0(ctx, (struct arr_0) {12, constantarr_0_24}, _22);
	print(_23);
	uint8_t _24 = remove__e_0(ctx, m2, (struct arr_0) {6, constantarr_0_11});
	struct arr_0 _25 = to_str_3(_24);
	struct arr_0 _26 = _concat_0(ctx, (struct arr_0) {15, constantarr_0_34}, _25);
	print(_26);
	uint8_t _27 = remove__e_0(ctx, m2, (struct arr_0) {6, constantarr_0_11});
	struct arr_0 _28 = to_str_3(_27);
	struct arr_0 _29 = _concat_0(ctx, (struct arr_0) {21, constantarr_0_35}, _28);
	print(_29);
	_concatEquals_2(ctx, m2, (struct arr_1) {2, constantarr_1_3});
	struct set* _30 = move_to_set__e(ctx, m2);
	struct arr_1 _31 = arr(ctx, _30);
	struct arr_0 _32 = join(ctx, _31, (struct arr_0) {2, constantarr_0_31});
	struct arr_0 _33 = _concat_0(ctx, (struct arr_0) {14, constantarr_0_37}, _32);
	print(_33);
	return resolved_1(ctx, 0u);
}
/* set<arr<char>> set<arr<char>>(a arr<arr<char>>) */
struct set* set(struct ctx* ctx, struct arr_1 a) {
	struct set* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct set));
	temp0 = (struct set*) _0;
	
	struct arr_1 _1 = sort_unique(ctx, a);
	*temp0 = (struct set) {(struct void_) {}, _1};
	return temp0;
}
/* sort-unique<?t> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 sort_unique(struct ctx* ctx, struct arr_1 a) {
	struct arr_1 _0 = sort(ctx, a);
	return unique__e(ctx, _0);
}
/* unique!<?t> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 unique__e(struct ctx* ctx, struct arr_1 a) {
	struct mut_list_1* res0;
	res0 = mut_list_0(ctx);
	
	struct unique__e__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct unique__e__lambda0));
	temp0 = (struct unique__e__lambda0*) _0;
	
	*temp0 = (struct unique__e__lambda0) {res0};
	each(ctx, a, (struct fun_act1_6) {0, .as0 = temp0});
	return move_to_arr__e(res0);
}
/* mut-list<?t> mut-list<arr<char>>() */
struct mut_list_1* mut_list_0(struct ctx* ctx) {
	struct mut_list_1* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct mut_list_1));
	temp0 = (struct mut_list_1*) _0;
	
	struct mut_arr_1 _1 = mut_arr_1();
	*temp0 = (struct mut_list_1) {_1, 0u};
	return temp0;
}
/* mut-arr<?t> mut-arr<arr<char>>() */
struct mut_arr_1 mut_arr_1(void) {
	return (struct mut_arr_1) {(struct void_) {}, (struct arr_1) {0u, NULL}};
}
/* each<?t> void(a arr<arr<char>>, f fun-act1<void, arr<char>>) */
struct void_ each(struct ctx* ctx, struct arr_1 a, struct fun_act1_6 f) {
	top:;
	uint8_t _0 = empty__q_1(a);
	uint8_t _1 = not(_0);
	if (_1) {
		struct arr_0 _2 = first(ctx, a);
		subscript_16(ctx, f, _2);
		struct arr_1 _3 = tail_0(ctx, a);
		a = _3;
		f = f;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* subscript<void, ?t> void(a fun-act1<void, arr<char>>, p0 arr<char>) */
struct void_ subscript_16(struct ctx* ctx, struct fun_act1_6 a, struct arr_0 p0) {
	return call_w_ctx_338(a, ctx, p0);
}
/* call-w-ctx<void, arr<char>> (generated) (generated) */
struct void_ call_w_ctx_338(struct fun_act1_6 a, struct ctx* ctx, struct arr_0 p0) {
	struct fun_act1_6 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct unique__e__lambda0* closure0 = _0.as0;
			
			return unique__e__lambda0(ctx, closure0, p0);
		}
		case 1: {
			struct _concatEquals_1__lambda0* closure1 = _0.as1;
			
			return _concatEquals_1__lambda0(ctx, closure1, p0);
		}
		case 2: {
			struct _concatEquals_2__lambda0* closure2 = _0.as2;
			
			return _concatEquals_2__lambda0(ctx, closure2, p0);
		}
		default:
			return (struct void_) {};
	}
}
/* first<?t> arr<char>(a arr<arr<char>>) */
struct arr_0 first(struct ctx* ctx, struct arr_1 a) {
	uint8_t _0 = empty__q_1(a);
	forbid_0(ctx, _0);
	return subscript_0(ctx, a, 0u);
}
/* empty?<?t> bool(a mut-list<arr<char>>) */
uint8_t empty__q_6(struct mut_list_1* a) {
	return _equal_0(a->size, 0u);
}
/* !=<?t> bool(a arr<char>, b arr<char>) */
uint8_t _notEqual_3(struct arr_0 a, struct arr_0 b) {
	uint8_t _0 = _equal_4(a, b);
	return not(_0);
}
/* ==<?t> bool(a arr<char>, b arr<char>) */
uint8_t _equal_4(struct arr_0 a, struct arr_0 b) {
	struct comparison _0 = compare_343(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* compare<arr<char>> (generated) (generated) */
struct comparison compare_343(struct arr_0 a, struct arr_0 b) {
	top:;
	uint8_t _0 = (a.size == 0u);
	if (_0) {
		uint8_t _1 = (b.size == 0u);
		if (_1) {
			return (struct comparison) {1, .as1 = (struct equal) {}};
		} else {
			return (struct comparison) {0, .as0 = (struct less) {}};
		}
	} else {
		uint8_t _2 = (b.size == 0u);
		if (_2) {
			return (struct comparison) {2, .as2 = (struct greater) {}};
		} else {
			struct comparison _3 = compare_206(*a.data, *b.data);
			switch (_3.kind) {
				case 0: {
					return (struct comparison) {0, .as0 = (struct less) {}};
				}
				case 1: {
					a = (struct arr_0) {(a.size - 1u), (a.data + 1u)};
					b = (struct arr_0) {(b.size - 1u), (b.data + 1u)};
					goto top;
				}
				case 2: {
					return (struct comparison) {2, .as2 = (struct greater) {}};
				}
				default:
					return (struct comparison) {0};
			}
		}
	}
}
/* last<?t> arr<char>(a mut-list<arr<char>>) */
struct arr_0 last(struct ctx* ctx, struct mut_list_1* a) {
	uint64_t _0 = _minus_2(ctx, a->size, 1u);
	return subscript_17(ctx, a, _0);
}
/* subscript<?t> arr<char>(a mut-list<arr<char>>, index nat) */
struct arr_0 subscript_17(struct ctx* ctx, struct mut_list_1* a, uint64_t index) {
	uint8_t _0 = _less_0(index, a->size);
	assert(ctx, _0);
	return noctx_at_5(a, index);
}
/* noctx-at<?t> arr<char>(a mut-list<arr<char>>, index nat) */
struct arr_0 noctx_at_5(struct mut_list_1* a, uint64_t index) {
	uint8_t _0 = _less_0(index, a->size);
	hard_assert(_0);
	struct arr_0* _1 = data_2(a);
	return *(_1 + index);
}
/* data<?t> ptr<arr<char>>(a mut-list<arr<char>>) */
struct arr_0* data_2(struct mut_list_1* a) {
	return data_3(a->backing);
}
/* data<?t> ptr<arr<char>>(a mut-arr<arr<char>>) */
struct arr_0* data_3(struct mut_arr_1 a) {
	return a.inner.data;
}
/* ~=<?t> void(a mut-list<arr<char>>, value arr<char>) */
struct void_ _concatEquals_0(struct ctx* ctx, struct mut_list_1* a, struct arr_0 value) {
	incr_capacity__e(ctx, a);
	uint64_t _0 = capacity_1(a);
	uint8_t _1 = _less_0(a->size, _0);
	assert(ctx, _1);
	struct arr_0* _2 = data_2(a);
	*(_2 + a->size) = value;
	uint64_t _3 = incr_5(ctx, a->size);
	return (a->size = _3, (struct void_) {});
}
/* incr-capacity!<?t> void(a mut-list<arr<char>>) */
struct void_ incr_capacity__e(struct ctx* ctx, struct mut_list_1* a) {
	uint64_t _0 = incr_5(ctx, a->size);
	uint64_t _1 = round_up_to_power_of_two(ctx, _0);
	return ensure_capacity(ctx, a, _1);
}
/* ensure-capacity<?t> void(a mut-list<arr<char>>, min-capacity nat) */
struct void_ ensure_capacity(struct ctx* ctx, struct mut_list_1* a, uint64_t min_capacity) {
	uint64_t _0 = capacity_1(a);
	uint8_t _1 = _less_0(_0, min_capacity);
	if (_1) {
		return increase_capacity_to__e(ctx, a, min_capacity);
	} else {
		return (struct void_) {};
	}
}
/* capacity<?t> nat(a mut-list<arr<char>>) */
uint64_t capacity_1(struct mut_list_1* a) {
	return size_2(a->backing);
}
/* size<?t> nat(a mut-arr<arr<char>>) */
uint64_t size_2(struct mut_arr_1 a) {
	return a.inner.size;
}
/* increase-capacity-to!<?t> void(a mut-list<arr<char>>, new-capacity nat) */
struct void_ increase_capacity_to__e(struct ctx* ctx, struct mut_list_1* a, uint64_t new_capacity) {
	uint64_t _0 = capacity_1(a);
	uint8_t _1 = _greater(new_capacity, _0);
	assert(ctx, _1);
	struct arr_0* old_data0;
	old_data0 = data_2(a);
	
	struct arr_0* _2 = alloc_uninitialized_1(ctx, new_capacity);
	struct mut_arr_1 _3 = mut_arr_2(new_capacity, _2);
	a->backing = _3;
	struct arr_0* _4 = data_2(a);
	copy_data_from_1(ctx, _4, old_data0, a->size);
	uint64_t _5 = _plus(ctx, a->size, 1u);
	uint64_t _6 = size_2(a->backing);
	struct arrow _7 = _arrow(ctx, _5, _6);
	struct mut_arr_1 _8 = subscript_18(ctx, a->backing, _7);
	return set_zero_elements(_8);
}
/* mut-arr<?t> mut-arr<arr<char>>(size nat, data ptr<arr<char>>) */
struct mut_arr_1 mut_arr_2(uint64_t size, struct arr_0* data) {
	return (struct mut_arr_1) {(struct void_) {}, (struct arr_1) {size, data}};
}
/* copy-data-from<?t> void(to ptr<arr<char>>, from ptr<arr<char>>, len nat) */
struct void_ copy_data_from_1(struct ctx* ctx, struct arr_0* to, struct arr_0* from, uint64_t len) {
	return (memcpy((uint8_t*) to, (uint8_t*) from, (len * sizeof(struct arr_0))), (struct void_) {});
}
/* set-zero-elements<?t> void(a mut-arr<arr<char>>) */
struct void_ set_zero_elements(struct mut_arr_1 a) {
	struct arr_0* _0 = data_3(a);
	uint64_t _1 = size_2(a);
	return set_zero_range_1(_0, _1);
}
/* set-zero-range<?t> void(begin ptr<arr<char>>, size nat) */
struct void_ set_zero_range_1(struct arr_0* begin, uint64_t size) {
	return (memset((uint8_t*) begin, 0u, (size * sizeof(struct arr_0))), (struct void_) {});
}
/* subscript<?t> mut-arr<arr<char>>(a mut-arr<arr<char>>, range arrow<nat, nat>) */
struct mut_arr_1 subscript_18(struct ctx* ctx, struct mut_arr_1 a, struct arrow range) {
	struct arr_1 _0 = subscript_1(ctx, a.inner, range);
	return (struct mut_arr_1) {(struct void_) {}, _0};
}
/* round-up-to-power-of-two nat(n nat) */
uint64_t round_up_to_power_of_two(struct ctx* ctx, uint64_t n) {
	return round_up_to_power_of_two_recur(ctx, 1u, n);
}
/* round-up-to-power-of-two-recur nat(acc nat, n nat) */
uint64_t round_up_to_power_of_two_recur(struct ctx* ctx, uint64_t acc, uint64_t n) {
	top:;
	uint8_t _0 = _greaterOrEqual(acc, n);
	if (_0) {
		return acc;
	} else {
		uint64_t _1 = _times(ctx, acc, 2u);
		acc = _1;
		n = n;
		goto top;
	}
}
/* * nat(a nat, b nat) */
uint64_t _times(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint8_t _0 = _equal_0(a, 0u);uint8_t _1;
	
	if (_0) {
		_1 = 1;
	} else {
		_1 = _equal_0(b, 0u);
	}
	if (_1) {
		return 0u;
	} else {
		uint64_t res0;
		res0 = (a * b);
		
		uint64_t _2 = _divide(ctx, res0, b);
		uint8_t _3 = _equal_0(_2, a);
		assert(ctx, _3);
		uint64_t _4 = _divide(ctx, res0, a);
		uint8_t _5 = _equal_0(_4, b);
		assert(ctx, _5);
		return res0;
	}
}
/* / nat(a nat, b nat) */
uint64_t _divide(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint8_t _0 = _equal_0(b, 0u);
	forbid_0(ctx, _0);
	return (a / b);
}
/* incr nat(n nat) */
uint64_t incr_5(struct ctx* ctx, uint64_t n) {
	uint64_t _0 = max_nat();
	uint8_t _1 = _equal_0(n, _0);
	forbid_0(ctx, _1);
	return (n + 1u);
}
/* max-nat nat() */
uint64_t max_nat(void) {
	return 18446744073709551615u;
}
/* unique!<?t>.lambda0 void(x arr<char>) */
struct void_ unique__e__lambda0(struct ctx* ctx, struct unique__e__lambda0* _closure, struct arr_0 x) {
	uint8_t _0 = empty__q_6(_closure->res);uint8_t _1;
	
	if (_0) {
		_1 = 1;
	} else {
		struct arr_0 _2 = last(ctx, _closure->res);
		_1 = _notEqual_3(x, _2);
	}
	if (_1) {
		return _concatEquals_0(ctx, _closure->res, x);
	} else {
		return (struct void_) {};
	}
}
/* move-to-arr!<?t> arr<arr<char>>(a mut-list<arr<char>>) */
struct arr_1 move_to_arr__e(struct mut_list_1* a) {
	struct arr_1 res0;
	struct arr_0* _0 = data_2(a);
	res0 = (struct arr_1) {a->size, _0};
	
	struct mut_arr_1 _1 = mut_arr_1();
	a->backing = _1;
	a->size = 0u;
	return res0;
}
/* sort<?t> arr<arr<char>>(a arr<arr<char>>) */
struct arr_1 sort(struct ctx* ctx, struct arr_1 a) {
	struct mut_arr_1 res0;
	res0 = mut_arr_3(ctx, a);
	
	sort__e(ctx, res0);
	return cast_immutable(res0);
}
/* mut-arr<?t> mut-arr<arr<char>>(a arr<arr<char>>) */
struct mut_arr_1 mut_arr_3(struct ctx* ctx, struct arr_1 a) {
	struct mut_arr_3__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct mut_arr_3__lambda0));
	temp0 = (struct mut_arr_3__lambda0*) _0;
	
	*temp0 = (struct mut_arr_3__lambda0) {a};
	return make_mut_arr(ctx, a.size, (struct fun_act1_5) {1, .as1 = temp0});
}
/* make-mut-arr<?t> mut-arr<arr<char>>(size nat, f fun-act1<arr<char>, nat>) */
struct mut_arr_1 make_mut_arr(struct ctx* ctx, uint64_t size, struct fun_act1_5 f) {
	struct mut_arr_1 res0;
	res0 = new_uninitialized_mut_arr(ctx, size);
	
	struct arr_0* _0 = data_3(res0);
	fill_ptr_range(ctx, _0, size, f);
	return res0;
}
/* new-uninitialized-mut-arr<?t> mut-arr<arr<char>>(size nat) */
struct mut_arr_1 new_uninitialized_mut_arr(struct ctx* ctx, uint64_t size) {
	struct arr_0* _0 = alloc_uninitialized_1(ctx, size);
	return mut_arr_2(size, _0);
}
/* mut-arr<?t>.lambda0 arr<char>(it nat) */
struct arr_0 mut_arr_3__lambda0(struct ctx* ctx, struct mut_arr_3__lambda0* _closure, uint64_t it) {
	return subscript_0(ctx, _closure->a, it);
}
/* sort!<?t> void(a mut-arr<arr<char>>) */
struct void_ sort__e(struct ctx* ctx, struct mut_arr_1 a) {
	top:;
	uint64_t _0 = size_2(a);
	uint8_t _1 = _greater(_0, 1u);
	if (_1) {
		uint64_t _2 = size_2(a);
		uint64_t _3 = _divide(ctx, _2, 2u);
		swap_2(ctx, a, 0u, _3);
		struct arr_0 pivot0;
		pivot0 = subscript_19(ctx, a, 0u);
		
		uint64_t index_of_first_value_gt_pivot1;
		uint64_t _4 = size_2(a);
		uint64_t _5 = _minus_2(ctx, _4, 1u);
		index_of_first_value_gt_pivot1 = partition_recur(ctx, a, pivot0, 1u, _5);
		
		uint64_t new_pivot_index2;
		new_pivot_index2 = _minus_2(ctx, index_of_first_value_gt_pivot1, 1u);
		
		swap_2(ctx, a, 0u, new_pivot_index2);
		struct arrow _6 = _arrow(ctx, 0u, new_pivot_index2);
		struct mut_arr_1 _7 = subscript_18(ctx, a, _6);
		sort__e(ctx, _7);
		uint64_t _8 = _plus(ctx, new_pivot_index2, 1u);
		uint64_t _9 = size_2(a);
		struct arrow _10 = _arrow(ctx, _8, _9);
		struct mut_arr_1 _11 = subscript_18(ctx, a, _10);
		a = _11;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* swap<?t> void(a mut-arr<arr<char>>, x nat, y nat) */
struct void_ swap_2(struct ctx* ctx, struct mut_arr_1 a, uint64_t x, uint64_t y) {
	struct arr_0 old_x0;
	old_x0 = subscript_19(ctx, a, x);
	
	struct arr_0 _0 = subscript_19(ctx, a, y);
	set_subscript_0(ctx, a, x, _0);
	return set_subscript_0(ctx, a, y, old_x0);
}
/* subscript<?t> arr<char>(a mut-arr<arr<char>>, index nat) */
struct arr_0 subscript_19(struct ctx* ctx, struct mut_arr_1 a, uint64_t index) {
	return subscript_0(ctx, a.inner, index);
}
/* set-subscript<?t> void(a mut-arr<arr<char>>, index nat, value arr<char>) */
struct void_ set_subscript_0(struct ctx* ctx, struct mut_arr_1 a, uint64_t index, struct arr_0 value) {
	uint64_t _0 = size_2(a);
	uint8_t _1 = _less_0(index, _0);
	assert(ctx, _1);
	return noctx_set_at(a, index, value);
}
/* noctx-set-at<?t> void(a mut-arr<arr<char>>, index nat, value arr<char>) */
struct void_ noctx_set_at(struct mut_arr_1 a, uint64_t index, struct arr_0 value) {
	uint64_t _0 = size_2(a);
	uint8_t _1 = _less_0(index, _0);
	hard_assert(_1);
	struct arr_0* _2 = data_3(a);
	return (*(_2 + index) = value, (struct void_) {});
}
/* partition-recur<?t> nat(a mut-arr<arr<char>>, pivot arr<char>, l nat, r nat) */
uint64_t partition_recur(struct ctx* ctx, struct mut_arr_1 a, struct arr_0 pivot, uint64_t l, uint64_t r) {
	top:;
	uint64_t _0 = size_2(a);
	uint8_t _1 = _lessOrEqual(l, _0);
	assert(ctx, _1);
	uint64_t _2 = size_2(a);
	uint8_t _3 = _less_0(r, _2);
	assert(ctx, _3);
	uint8_t _4 = _lessOrEqual(l, r);
	if (_4) {
		struct arr_0 em0;
		em0 = subscript_19(ctx, a, l);
		
		uint8_t _5 = _less_1(em0, pivot);
		if (_5) {
			uint64_t _6 = _plus(ctx, l, 1u);
			a = a;
			pivot = pivot;
			l = _6;
			r = r;
			goto top;
		} else {
			swap_2(ctx, a, l, r);
			uint64_t _7 = _minus_2(ctx, r, 1u);
			a = a;
			pivot = pivot;
			l = l;
			r = _7;
			goto top;
		}
	} else {
		return l;
	}
}
/* <<?t> bool(a arr<char>, b arr<char>) */
uint8_t _less_1(struct arr_0 a, struct arr_0 b) {
	struct comparison _0 = compare_343(a, b);
	switch (_0.kind) {
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
			return 0;
	}
}
/* cast-immutable<?t> arr<arr<char>>(a mut-arr<arr<char>>) */
struct arr_1 cast_immutable(struct mut_arr_1 a) {
	return a.inner;
}
/* to-str arr<char>(n nat) */
struct arr_0 to_str_2(struct ctx* ctx, uint64_t n) {
	uint8_t _0 = _equal_0(n, 0u);
	if (_0) {
		return (struct arr_0) {1, constantarr_0_14};
	} else {
		uint8_t _1 = _equal_0(n, 1u);
		if (_1) {
			return (struct arr_0) {1, constantarr_0_15};
		} else {
			uint8_t _2 = _equal_0(n, 2u);
			if (_2) {
				return (struct arr_0) {1, constantarr_0_16};
			} else {
				uint8_t _3 = _equal_0(n, 3u);
				if (_3) {
					return (struct arr_0) {1, constantarr_0_17};
				} else {
					uint8_t _4 = _equal_0(n, 4u);
					if (_4) {
						return (struct arr_0) {1, constantarr_0_18};
					} else {
						uint8_t _5 = _equal_0(n, 5u);
						if (_5) {
							return (struct arr_0) {1, constantarr_0_19};
						} else {
							uint8_t _6 = _equal_0(n, 6u);
							if (_6) {
								return (struct arr_0) {1, constantarr_0_20};
							} else {
								uint8_t _7 = _equal_0(n, 7u);
								if (_7) {
									return (struct arr_0) {1, constantarr_0_21};
								} else {
									uint8_t _8 = _equal_0(n, 8u);
									if (_8) {
										return (struct arr_0) {1, constantarr_0_22};
									} else {
										uint8_t _9 = _equal_0(n, 9u);
										if (_9) {
											return (struct arr_0) {1, constantarr_0_23};
										} else {
											struct arr_0 hi0;
											uint64_t _10 = _divide(ctx, n, 10u);
											hi0 = to_str_2(ctx, _10);
											
											struct arr_0 lo1;
											uint64_t _11 = mod(ctx, n, 10u);
											lo1 = to_str_2(ctx, _11);
											
											return _concat_0(ctx, hi0, lo1);
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
	uint8_t _0 = _equal_0(b, 0u);
	forbid_0(ctx, _0);
	return (a % b);
}
/* size<arr<char>> nat(a set<arr<char>>) */
uint64_t size_3(struct ctx* ctx, struct set* a) {
	return a->values.size;
}
/* to-str arr<char>(b bool) */
struct arr_0 to_str_3(uint8_t b) {
	uint8_t _0 = b;
	if (_0) {
		return (struct arr_0) {4, constantarr_0_25};
	} else {
		return (struct arr_0) {5, constantarr_0_26};
	}
}
/* subscript<arr<char>> bool(a set<arr<char>>, value arr<char>) */
uint8_t subscript_20(struct ctx* ctx, struct set* a, struct arr_0 value) {
	return has__q_1(ctx, a->values, value);
}
/* has?<?t> bool(a arr<arr<char>>, value arr<char>) */
uint8_t has__q_1(struct ctx* ctx, struct arr_1 a, struct arr_0 value) {
	top:;
	uint8_t _0 = empty__q_1(a);
	if (_0) {
		return 0;
	} else {
		struct arr_0 _1 = subscript_0(ctx, a, 0u);
		struct comparison _2 = compare_343(value, _1);
		switch (_2.kind) {
			case 0: {
				return 0;
			}
			case 1: {
				return 1;
			}
			case 2: {
				struct arr_1 _3 = tail_0(ctx, a);
				a = _3;
				value = value;
				goto top;
			}
			default:
				return 0;
		}
	}
}
/* arr<arr<char>> arr<arr<char>>(a set<arr<char>>) */
struct arr_1 arr(struct ctx* ctx, struct set* a) {
	return a->values;
}
/* ~<arr<char>> set<arr<char>>(a set<arr<char>>, b set<arr<char>>) */
struct set* _concat_1(struct ctx* ctx, struct set* a, struct set* b) {
	struct mut_list_1* res0;
	res0 = mut_list_0(ctx);
	
	union__e(ctx, res0, a->values, b->values);
	struct set* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct set));
	temp0 = (struct set*) _0;
	
	struct arr_1 _1 = move_to_arr__e(res0);
	*temp0 = (struct set) {(struct void_) {}, _1};
	return temp0;
}
/* union!<?t> void(res mut-list<arr<char>>, a arr<arr<char>>, b arr<arr<char>>) */
struct void_ union__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b) {
	top:;
	uint8_t _0 = empty__q_1(a);
	if (_0) {
		uint8_t _1 = empty__q_1(b);
		uint8_t _2 = not(_1);
		if (_2) {
			struct arr_0 _3 = subscript_0(ctx, b, 0u);
			_concatEquals_0(ctx, res, _3);
			struct arr_1 _4 = tail_0(ctx, b);
			res = res;
			a = a;
			b = _4;
			goto top;
		} else {
			return (struct void_) {};
		}
	} else {
		uint8_t _5 = empty__q_1(b);
		if (_5) {
			struct arr_0 _6 = subscript_0(ctx, a, 0u);
			_concatEquals_0(ctx, res, _6);
			struct arr_1 _7 = tail_0(ctx, a);
			res = res;
			a = _7;
			b = b;
			goto top;
		} else {
			struct arr_0 _8 = subscript_0(ctx, a, 0u);
			struct arr_0 _9 = subscript_0(ctx, b, 0u);
			struct comparison _10 = compare_343(_8, _9);
			switch (_10.kind) {
				case 0: {
					struct arr_0 _11 = subscript_0(ctx, a, 0u);
					_concatEquals_0(ctx, res, _11);
					struct arr_1 _12 = tail_0(ctx, a);
					res = res;
					a = _12;
					b = b;
					goto top;
				}
				case 1: {
					struct arr_0 _13 = subscript_0(ctx, a, 0u);
					_concatEquals_0(ctx, res, _13);
					struct arr_1 _14 = tail_0(ctx, a);
					struct arr_1 _15 = tail_0(ctx, b);
					res = res;
					a = _14;
					b = _15;
					goto top;
				}
				case 2: {
					struct arr_0 _16 = subscript_0(ctx, b, 0u);
					_concatEquals_0(ctx, res, _16);
					struct arr_1 _17 = tail_0(ctx, b);
					res = res;
					a = a;
					b = _17;
					goto top;
				}
				default:
					return (struct void_) {};
			}
		}
	}
}
/* intersect<arr<char>> set<arr<char>>(a set<arr<char>>, b set<arr<char>>) */
struct set* intersect(struct ctx* ctx, struct set* a, struct set* b) {
	struct mut_list_1* res0;
	res0 = mut_list_0(ctx);
	
	intersect__e(ctx, res0, a->values, b->values);
	struct set* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct set));
	temp0 = (struct set*) _0;
	
	struct arr_1 _1 = move_to_arr__e(res0);
	*temp0 = (struct set) {(struct void_) {}, _1};
	return temp0;
}
/* intersect!<?t> void(res mut-list<arr<char>>, a arr<arr<char>>, b arr<arr<char>>) */
struct void_ intersect__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b) {
	top:;
	uint8_t _0 = empty__q_1(a);
	uint8_t _1 = not(_0);uint8_t _2;
	
	if (_1) {
		uint8_t _3 = empty__q_1(b);
		_2 = not(_3);
	} else {
		_2 = 0;
	}
	if (_2) {
		struct arr_0 _4 = subscript_0(ctx, a, 0u);
		struct arr_0 _5 = subscript_0(ctx, b, 0u);
		struct comparison _6 = compare_343(_4, _5);
		switch (_6.kind) {
			case 0: {
				struct arr_1 _7 = tail_0(ctx, a);
				res = res;
				a = _7;
				b = b;
				goto top;
			}
			case 1: {
				struct arr_0 _8 = subscript_0(ctx, a, 0u);
				_concatEquals_0(ctx, res, _8);
				struct arr_1 _9 = tail_0(ctx, a);
				struct arr_1 _10 = tail_0(ctx, b);
				res = res;
				a = _9;
				b = _10;
				goto top;
			}
			case 2: {
				struct arr_1 _11 = tail_0(ctx, b);
				res = res;
				a = a;
				b = _11;
				goto top;
			}
			default:
				return (struct void_) {};
		}
	} else {
		return (struct void_) {};
	}
}
/* -<arr<char>> set<arr<char>>(a set<arr<char>>, b set<arr<char>>) */
struct set* _minus_4(struct ctx* ctx, struct set* a, struct set* b) {
	struct mut_list_1* res0;
	res0 = mut_list_0(ctx);
	
	subtract__e(ctx, res0, a->values, b->values);
	struct set* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct set));
	temp0 = (struct set*) _0;
	
	struct arr_1 _1 = move_to_arr__e(res0);
	*temp0 = (struct set) {(struct void_) {}, _1};
	return temp0;
}
/* subtract!<?t> void(res mut-list<arr<char>>, a arr<arr<char>>, b arr<arr<char>>) */
struct void_ subtract__e(struct ctx* ctx, struct mut_list_1* res, struct arr_1 a, struct arr_1 b) {
	top:;
	uint8_t _0 = empty__q_1(a);
	uint8_t _1 = not(_0);
	if (_1) {
		uint8_t _2 = empty__q_1(b);
		if (_2) {
			return _concatEquals_1(ctx, res, a);
		} else {
			struct arr_0 _3 = subscript_0(ctx, a, 0u);
			struct arr_0 _4 = subscript_0(ctx, b, 0u);
			struct comparison _5 = compare_343(_3, _4);
			switch (_5.kind) {
				case 0: {
					struct arr_0 _6 = subscript_0(ctx, a, 0u);
					_concatEquals_0(ctx, res, _6);
					struct arr_1 _7 = tail_0(ctx, a);
					res = res;
					a = _7;
					b = b;
					goto top;
				}
				case 1: {
					struct arr_1 _8 = tail_0(ctx, a);
					struct arr_1 _9 = tail_0(ctx, b);
					res = res;
					a = _8;
					b = _9;
					goto top;
				}
				case 2: {
					struct arr_1 _10 = tail_0(ctx, b);
					res = res;
					a = a;
					b = _10;
					goto top;
				}
				default:
					return (struct void_) {};
			}
		}
	} else {
		return (struct void_) {};
	}
}
/* ~=<?t> void(a mut-list<arr<char>>, values arr<arr<char>>) */
struct void_ _concatEquals_1(struct ctx* ctx, struct mut_list_1* a, struct arr_1 values) {
	struct _concatEquals_1__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct _concatEquals_1__lambda0));
	temp0 = (struct _concatEquals_1__lambda0*) _0;
	
	*temp0 = (struct _concatEquals_1__lambda0) {a};
	return each(ctx, values, (struct fun_act1_6) {1, .as1 = temp0});
}
/* ~=<?t>.lambda0 void(it arr<char>) */
struct void_ _concatEquals_1__lambda0(struct ctx* ctx, struct _concatEquals_1__lambda0* _closure, struct arr_0 it) {
	return _concatEquals_0(ctx, _closure->a, it);
}
/* mut-set<arr<char>> mut-set<arr<char>>(a arr<arr<char>>) */
struct mut_set mut_set(struct ctx* ctx, struct arr_1 a) {
	struct arr_1 _0 = sort(ctx, a);
	struct mut_list_1* _1 = mut_list_1(ctx, _0);
	return (struct mut_set) {(struct void_) {}, _1};
}
/* mut-list<?t> mut-list<arr<char>>(a arr<arr<char>>) */
struct mut_list_1* mut_list_1(struct ctx* ctx, struct arr_1 a) {
	struct mut_list_1* res0;
	res0 = mut_list_0(ctx);
	
	_concatEquals_1(ctx, res0, a);
	return res0;
}
/* subscript<arr<char>> bool(a mut-set<arr<char>>, value arr<char>) */
uint8_t subscript_21(struct ctx* ctx, struct mut_set a, struct arr_0 value) {
	return has__q_2(ctx, a.inner, 0u, value);
}
/* has?<?t> bool(a mut-list<arr<char>>, index nat, value arr<char>) */
uint8_t has__q_2(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	top:;
	uint8_t _0 = _equal_0(index, a->size);
	if (_0) {
		return 0;
	} else {
		struct arr_0 _1 = subscript_17(ctx, a, index);
		struct comparison _2 = compare_343(value, _1);
		switch (_2.kind) {
			case 0: {
				return 0;
			}
			case 1: {
				return 1;
			}
			case 2: {
				uint64_t _3 = _plus(ctx, index, 1u);
				a = a;
				index = _3;
				value = value;
				goto top;
			}
			default:
				return 0;
		}
	}
}
/* remove!<arr<char>> bool(a mut-set<arr<char>>, value arr<char>) */
uint8_t remove__e_0(struct ctx* ctx, struct mut_set a, struct arr_0 value) {
	return remove__e_1(ctx, a.inner, 0u, value);
}
/* remove!<?t> bool(a mut-list<arr<char>>, index nat, value arr<char>) */
uint8_t remove__e_1(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	top:;
	uint8_t _0 = _equal_0(index, a->size);
	if (_0) {
		return 0;
	} else {
		struct arr_0 _1 = subscript_17(ctx, a, index);
		struct comparison _2 = compare_343(value, _1);
		switch (_2.kind) {
			case 0: {
				return 0;
			}
			case 1: {
				struct arr_0 _3 = remove_at__e(ctx, a, index);
				drop_2(_3);
				return 1;
			}
			case 2: {
				uint64_t _4 = _plus(ctx, index, 1u);
				a = a;
				index = _4;
				value = value;
				goto top;
			}
			default:
				return 0;
		}
	}
}
/* drop<?t> void(_ arr<char>) */
struct void_ drop_2(struct arr_0 _p0) {
	return (struct void_) {};
}
/* remove-at!<?t> arr<char>(a mut-list<arr<char>>, index nat) */
struct arr_0 remove_at__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index) {
	uint8_t _0 = _less_0(index, a->size);
	assert(ctx, _0);
	struct arr_0 res0;
	res0 = subscript_17(ctx, a, index);
	
	struct arr_0* dest1;
	struct arr_0* _1 = data_2(a);
	dest1 = (_1 + index);
	
	struct arr_0* src2;
	struct arr_0* _2 = data_2(a);
	src2 = ((_2 + index) + 1u);
	
	uint64_t n3;
	uint64_t _3 = _minus_2(ctx, a->size, index);
	n3 = _minus_2(ctx, _3, 1u);
	
	uint64_t _4 = _times(ctx, n3, sizeof(struct arr_0));
	(memmove((uint8_t*) dest1, (uint8_t*) src2, _4), (struct void_) {});
	uint64_t _5 = _minus_2(ctx, a->size, 1u);
	a->size = _5;
	return res0;
}
/* ~=<arr<char>> void(a mut-set<arr<char>>, values arr<arr<char>>) */
struct void_ _concatEquals_2(struct ctx* ctx, struct mut_set a, struct arr_1 values) {
	struct _concatEquals_2__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct _concatEquals_2__lambda0));
	temp0 = (struct _concatEquals_2__lambda0*) _0;
	
	*temp0 = (struct _concatEquals_2__lambda0) {a};
	return each(ctx, values, (struct fun_act1_6) {2, .as2 = temp0});
}
/* ~=<?t> void(a mut-set<arr<char>>, value arr<char>) */
struct void_ _concatEquals_3(struct ctx* ctx, struct mut_set a, struct arr_0 value) {
	uint8_t _0 = add__e(ctx, a.inner, 0u, value);
	return drop_3(_0);
}
/* drop<bool> void(_ bool) */
struct void_ drop_3(uint8_t _p0) {
	return (struct void_) {};
}
/* add!<?t> bool(a mut-list<arr<char>>, index nat, value arr<char>) */
uint8_t add__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	top:;
	uint8_t _0 = _equal_0(index, a->size);
	if (_0) {
		_concatEquals_0(ctx, a, value);
		return 1;
	} else {
		struct arr_0 _1 = subscript_17(ctx, a, index);
		struct comparison _2 = compare_343(value, _1);
		switch (_2.kind) {
			case 0: {
				insert_at__e(ctx, a, index, value);
				return 1;
			}
			case 1: {
				return 0;
			}
			case 2: {
				uint64_t _3 = _plus(ctx, index, 1u);
				a = a;
				index = _3;
				value = value;
				goto top;
			}
			default:
				return 0;
		}
	}
}
/* insert-at!<?t> void(a mut-list<arr<char>>, index nat, value arr<char>) */
struct void_ insert_at__e(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	uint8_t _0 = _lessOrEqual(index, a->size);
	assert(ctx, _0);
	incr_capacity__e(ctx, a);
	struct arr_0* dest0;
	struct arr_0* _1 = data_2(a);
	dest0 = ((_1 + index) + 1u);
	
	struct arr_0* src1;
	struct arr_0* _2 = data_2(a);
	src1 = (_2 + index);
	
	uint64_t n2;
	n2 = _minus_2(ctx, a->size, index);
	
	uint64_t _3 = _times(ctx, n2, sizeof(struct arr_0));
	(memmove((uint8_t*) dest0, (uint8_t*) src1, _3), (struct void_) {});
	set_subscript_1(ctx, a, index, value);
	uint64_t _4 = _plus(ctx, a->size, 1u);
	a->size = _4;
	uint64_t _5 = capacity_1(a);
	uint8_t _6 = _lessOrEqual(a->size, _5);
	return assert(ctx, _6);
}
/* set-subscript<?t> void(a mut-list<arr<char>>, index nat, value arr<char>) */
struct void_ set_subscript_1(struct ctx* ctx, struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	uint8_t _0 = _less_0(index, a->size);
	assert(ctx, _0);
	return noctx_set_at__e_1(a, index, value);
}
/* noctx-set-at!<?t> void(a mut-list<arr<char>>, index nat, value arr<char>) */
struct void_ noctx_set_at__e_1(struct mut_list_1* a, uint64_t index, struct arr_0 value) {
	uint8_t _0 = _less_0(index, a->size);
	hard_assert(_0);
	struct arr_0* _1 = data_2(a);
	return (*(_1 + index) = value, (struct void_) {});
}
/* ~=<arr<char>>.lambda0 void(value arr<char>) */
struct void_ _concatEquals_2__lambda0(struct ctx* ctx, struct _concatEquals_2__lambda0* _closure, struct arr_0 value) {
	return _concatEquals_3(ctx, _closure->a, value);
}
/* move-to-set!<arr<char>> set<arr<char>>(a mut-set<arr<char>>) */
struct set* move_to_set__e(struct ctx* ctx, struct mut_set a) {
	struct set* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct set));
	temp0 = (struct set*) _0;
	
	struct arr_1 _1 = move_to_arr__e(a.inner);
	*temp0 = (struct set) {(struct void_) {}, _1};
	return temp0;
}
/* resolved<nat> fut<nat>(value nat) */
struct fut_0* resolved_1(struct ctx* ctx, uint64_t value) {
	struct fut_0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct fut_0));
	temp0 = (struct fut_0*) _0;
	
	struct lock _1 = new_lock();
	*temp0 = (struct fut_0) {_1, (struct fut_state_0) {1, .as1 = (struct fut_state_resolved_0) {value}}};
	return temp0;
}
/* main (generated) (generated) */
int32_t main(int32_t argc, char** argv) {
	return rt_main(argc, argv, main_0);
}
