#include <assert.h>
#include <errno.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdint.h>

struct void_ {};
struct sdl_window;
struct sdl_renderer;
struct sdl_texture;
struct sdl_surface;
struct sdl_rwops;
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
struct err {
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
struct mut_list;
struct mut_arr;
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
struct then__lambda0;
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
struct main_0__lambda0 {
	struct sdl_renderer* renderer;
	struct sdl_texture* texture;
};
struct arr_5 {
	uint64_t size;
	uint8_t* data;
};
struct sdl_rect {
	int64_t x;
	int64_t y;
	int64_t w;
	int64_t h;
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
		struct err as1;
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
		struct main_0__lambda0* as4;
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
		struct err as1;
	};
};
struct fun_act1_1 {
	uint64_t kind;
	union {
		struct then__lambda0* as0;
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
		struct map__lambda0* as0;
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
struct mut_list;
struct mut_arr {
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
struct then__lambda0 {
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
struct map__lambda0 {
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
struct mut_list {
	struct mut_arr backing;
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
	struct mut_list currently_running_exclusions;
};
struct jmp_buf_tag {
	struct bytes64 jmp_buf;
	int32_t mask_was_saved;
	struct bytes128 saved_mask;
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
_Static_assert(sizeof(struct err) == 16, "");
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
_Static_assert(sizeof(struct mut_list) == 24, "");
_Static_assert(sizeof(struct mut_arr) == 16, "");
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
_Static_assert(sizeof(struct then__lambda0) == 40, "");
_Static_assert(sizeof(struct forward_to__lambda0) == 8, "");
_Static_assert(sizeof(struct call_ref_0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_0__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_0__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct then2__lambda0) == 32, "");
_Static_assert(sizeof(struct call_ref_1__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_1__lambda0__lambda0) == 40, "");
_Static_assert(sizeof(struct call_ref_1__lambda0__lambda1) == 8, "");
_Static_assert(sizeof(struct add_first_task__lambda0) == 24, "");
_Static_assert(sizeof(struct map__lambda0) == 24, "");
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
_Static_assert(sizeof(struct main_0__lambda0) == 16, "");
_Static_assert(sizeof(struct arr_5) == 16, "");
_Static_assert(sizeof(struct sdl_rect) == 32, "");
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
char constantarr_0_0[17];
char constantarr_0_1[4];
char constantarr_0_2[20];
char constantarr_0_3[1];
char constantarr_0_4[17];
char constantarr_0_5[13];
char constantarr_0_6[4];
char constantarr_0_7[4];
char constantarr_0_8[2];
char constantarr_0_9[38];
char constantarr_0_10[33];
char constantarr_0_11[13];
char constantarr_0_12[40];
char constantarr_0_13[11];
char constantarr_0_14[13];
char constantarr_0_15[13];
char constantarr_0_16[1];
char constantarr_0_17[14];
char constantarr_0_18[1];
char constantarr_0_19[12];
char constantarr_0_20[17];
char constantarr_0_21[19];
char constantarr_0_22[14];
char constantarr_0_23[2];
char constantarr_0_24[17];
char constantarr_0_25[31];
char constantarr_0_26[9];
char constantarr_0_27[17];
char constantarr_0_28[16];
char constantarr_0_29[15];
char constantarr_0_30[7];
char constantarr_0_31[4];
char constantarr_0_32[14];
char constantarr_0_33[10];
char constantarr_0_34[25];
char constantarr_0_35[8];
char constantarr_0_36[8];
char constantarr_0_37[8];
char constantarr_0_38[12];
char constantarr_0_39[19];
char constantarr_0_40[11];
char constantarr_0_41[3];
char constantarr_0_42[15];
char constantarr_0_43[7];
char constantarr_0_44[7];
char constantarr_0_45[5];
char constantarr_0_46[4];
char constantarr_0_47[11];
char constantarr_0_48[6];
char constantarr_0_49[8];
char constantarr_0_50[11];
char constantarr_0_51[12];
char constantarr_0_52[6];
char constantarr_0_53[17];
char constantarr_0_54[7];
char constantarr_0_55[7];
char constantarr_0_56[5];
char constantarr_0_57[16];
char constantarr_0_58[13];
char constantarr_0_59[2];
char constantarr_0_60[11];
char constantarr_0_61[9];
char constantarr_0_62[10];
char constantarr_0_63[6];
char constantarr_0_64[7];
char constantarr_0_65[10];
char constantarr_0_66[22];
char constantarr_0_67[10];
char constantarr_0_68[8];
char constantarr_0_69[4];
char constantarr_0_70[15];
char constantarr_0_71[11];
char constantarr_0_72[17];
char constantarr_0_73[7];
char constantarr_0_74[8];
char constantarr_0_75[13];
char constantarr_0_76[9];
char constantarr_0_77[22];
char constantarr_0_78[10];
char constantarr_0_79[14];
char constantarr_0_80[10];
char constantarr_0_81[4];
char constantarr_0_82[60];
char constantarr_0_83[11];
char constantarr_0_84[35];
char constantarr_0_85[28];
char constantarr_0_86[21];
char constantarr_0_87[6];
char constantarr_0_88[11];
char constantarr_0_89[11];
char constantarr_0_90[10];
char constantarr_0_91[8];
char constantarr_0_92[18];
char constantarr_0_93[6];
char constantarr_0_94[19];
char constantarr_0_95[12];
char constantarr_0_96[26];
char constantarr_0_97[14];
char constantarr_0_98[25];
char constantarr_0_99[20];
char constantarr_0_100[16];
char constantarr_0_101[13];
char constantarr_0_102[13];
char constantarr_0_103[5];
char constantarr_0_104[21];
char constantarr_0_105[10];
char constantarr_0_106[10];
char constantarr_0_107[7];
char constantarr_0_108[6];
char constantarr_0_109[13];
char constantarr_0_110[10];
char constantarr_0_111[6];
char constantarr_0_112[9];
char constantarr_0_113[12];
char constantarr_0_114[12];
char constantarr_0_115[7];
char constantarr_0_116[29];
char constantarr_0_117[14];
char constantarr_0_118[18];
char constantarr_0_119[8];
char constantarr_0_120[7];
char constantarr_0_121[18];
char constantarr_0_122[19];
char constantarr_0_123[5];
char constantarr_0_124[16];
char constantarr_0_125[6];
char constantarr_0_126[7];
char constantarr_0_127[1];
char constantarr_0_128[6];
char constantarr_0_129[10];
char constantarr_0_130[9];
char constantarr_0_131[17];
char constantarr_0_132[21];
char constantarr_0_133[17];
char constantarr_0_134[18];
char constantarr_0_135[11];
char constantarr_0_136[20];
char constantarr_0_137[7];
char constantarr_0_138[15];
char constantarr_0_139[9];
char constantarr_0_140[3];
char constantarr_0_141[7];
char constantarr_0_142[22];
char constantarr_0_143[5];
char constantarr_0_144[8];
char constantarr_0_145[12];
char constantarr_0_146[11];
char constantarr_0_147[18];
char constantarr_0_148[13];
char constantarr_0_149[10];
char constantarr_0_150[8];
char constantarr_0_151[8];
char constantarr_0_152[17];
char constantarr_0_153[11];
char constantarr_0_154[10];
char constantarr_0_155[8];
char constantarr_0_156[8];
char constantarr_0_157[7];
char constantarr_0_158[10];
char constantarr_0_159[6];
char constantarr_0_160[11];
char constantarr_0_161[12];
char constantarr_0_162[12];
char constantarr_0_163[15];
char constantarr_0_164[19];
char constantarr_0_165[9];
char constantarr_0_166[15];
char constantarr_0_167[13];
char constantarr_0_168[16];
char constantarr_0_169[6];
char constantarr_0_170[2];
char constantarr_0_171[10];
char constantarr_0_172[14];
char constantarr_0_173[10];
char constantarr_0_174[18];
char constantarr_0_175[18];
char constantarr_0_176[6];
char constantarr_0_177[5];
char constantarr_0_178[6];
char constantarr_0_179[5];
char constantarr_0_180[18];
char constantarr_0_181[6];
char constantarr_0_182[6];
char constantarr_0_183[20];
char constantarr_0_184[21];
char constantarr_0_185[23];
char constantarr_0_186[19];
char constantarr_0_187[18];
char constantarr_0_188[11];
char constantarr_0_189[14];
char constantarr_0_190[7];
char constantarr_0_191[17];
char constantarr_0_192[13];
char constantarr_0_193[11];
char constantarr_0_194[7];
char constantarr_0_195[26];
char constantarr_0_196[30];
char constantarr_0_197[18];
char constantarr_0_198[25];
char constantarr_0_199[19];
char constantarr_0_200[7];
char constantarr_0_201[18];
char constantarr_0_202[12];
char constantarr_0_203[18];
char constantarr_0_204[16];
char constantarr_0_205[7];
char constantarr_0_206[10];
char constantarr_0_207[23];
char constantarr_0_208[12];
char constantarr_0_209[5];
char constantarr_0_210[23];
char constantarr_0_211[9];
char constantarr_0_212[12];
char constantarr_0_213[13];
char constantarr_0_214[9];
char constantarr_0_215[10];
char constantarr_0_216[7];
char constantarr_0_217[9];
char constantarr_0_218[16];
char constantarr_0_219[2];
char constantarr_0_220[12];
char constantarr_0_221[23];
char constantarr_0_222[6];
char constantarr_0_223[12];
char constantarr_0_224[13];
char constantarr_0_225[16];
char constantarr_0_226[8];
char constantarr_0_227[12];
char constantarr_0_228[10];
char constantarr_0_229[9];
char constantarr_0_230[14];
char constantarr_0_231[11];
char constantarr_0_232[11];
char constantarr_0_233[26];
char constantarr_0_234[7];
char constantarr_0_235[3];
char constantarr_0_236[22];
char constantarr_0_237[2];
char constantarr_0_238[25];
char constantarr_0_239[19];
char constantarr_0_240[30];
char constantarr_0_241[15];
char constantarr_0_242[79];
char constantarr_0_243[14];
char constantarr_0_244[12];
char constantarr_0_245[16];
char constantarr_0_246[24];
char constantarr_0_247[7];
char constantarr_0_248[23];
char constantarr_0_249[14];
char constantarr_0_250[6];
char constantarr_0_251[9];
char constantarr_0_252[13];
char constantarr_0_253[27];
char constantarr_0_254[21];
char constantarr_0_255[8];
char constantarr_0_256[33];
char constantarr_0_257[22];
char constantarr_0_258[6];
char constantarr_0_259[9];
char constantarr_0_260[14];
char constantarr_0_261[16];
char constantarr_0_262[13];
char constantarr_0_263[21];
char constantarr_0_264[27];
char constantarr_0_265[4];
char constantarr_0_266[10];
char constantarr_0_267[6];
char constantarr_0_268[28];
char constantarr_0_269[13];
char constantarr_0_270[22];
char constantarr_0_271[16];
char constantarr_0_272[24];
char constantarr_0_273[19];
char constantarr_0_274[10];
char constantarr_0_275[10];
char constantarr_0_276[8];
char constantarr_0_277[12];
char constantarr_0_278[9];
char constantarr_0_279[8];
char constantarr_0_280[7];
char constantarr_0_281[29];
char constantarr_0_282[8];
char constantarr_0_283[19];
char constantarr_0_284[15];
char constantarr_0_285[4];
char constantarr_0_286[10];
char constantarr_0_287[11];
char constantarr_0_288[4];
char constantarr_0_289[10];
char constantarr_0_290[4];
char constantarr_0_291[22];
char constantarr_0_292[4];
char constantarr_0_293[8];
char constantarr_0_294[21];
char constantarr_0_295[4];
char constantarr_0_296[12];
char constantarr_0_297[8];
char constantarr_0_298[5];
char constantarr_0_299[22];
char constantarr_0_300[9];
char constantarr_0_301[9];
char constantarr_0_302[21];
char constantarr_0_303[17];
char constantarr_0_304[4];
char constantarr_0_305[12];
char constantarr_0_306[9];
char constantarr_0_307[11];
char constantarr_0_308[28];
char constantarr_0_309[16];
char constantarr_0_310[11];
char constantarr_0_311[4];
char constantarr_0_312[7];
char constantarr_0_313[7];
char constantarr_0_314[7];
char constantarr_0_315[8];
char constantarr_0_316[15];
char constantarr_0_317[19];
char constantarr_0_318[6];
char constantarr_0_319[8];
char constantarr_0_320[17];
char constantarr_0_321[19];
char constantarr_0_322[18];
char constantarr_0_323[12];
char constantarr_0_324[35];
char constantarr_0_325[10];
char constantarr_0_326[35];
char constantarr_0_327[27];
char constantarr_0_328[10];
char constantarr_0_329[24];
char constantarr_0_330[14];
char constantarr_0_331[24];
char constantarr_0_332[13];
char constantarr_0_333[7];
char constantarr_0_334[30];
char constantarr_0_335[30];
char constantarr_0_336[22];
char constantarr_0_337[20];
char constantarr_0_338[24];
char constantarr_0_339[20];
char constantarr_0_340[9];
char constantarr_0_341[5];
char constantarr_0_342[14];
char constantarr_0_343[15];
char constantarr_0_344[6];
char constantarr_0_345[10];
char constantarr_0_346[21];
char constantarr_0_347[9];
char constantarr_0_348[1];
char constantarr_0_349[37];
char constantarr_0_350[25];
char constantarr_0_351[14];
char constantarr_0_352[18];
char constantarr_0_353[24];
char constantarr_0_354[7];
char constantarr_0_355[7];
char constantarr_0_356[13];
char constantarr_0_357[15];
char constantarr_0_358[7];
char constantarr_0_359[33];
char constantarr_0_360[24];
char constantarr_0_361[5];
char constantarr_0_362[13];
char constantarr_0_363[17];
char constantarr_0_364[8];
char constantarr_0_365[11];
char constantarr_0_366[15];
char constantarr_0_367[10];
char constantarr_0_368[30];
char constantarr_0_369[22];
char constantarr_0_370[15];
char constantarr_0_371[13];
char constantarr_0_372[6];
char constantarr_0_373[84];
char constantarr_0_374[11];
char constantarr_0_375[45];
char constantarr_0_376[10];
char constantarr_0_377[19];
char constantarr_0_378[22];
char constantarr_0_379[24];
char constantarr_0_380[11];
char constantarr_0_381[17];
char constantarr_0_382[14];
char constantarr_0_383[9];
char constantarr_0_384[6];
char constantarr_0_385[12];
char constantarr_0_386[16];
char constantarr_0_387[36];
char constantarr_0_388[10];
char constantarr_0_389[19];
char constantarr_0_390[15];
char constantarr_0_391[21];
char constantarr_0_392[10];
char constantarr_0_393[18];
char constantarr_0_394[14];
char constantarr_0_395[28];
char constantarr_0_396[9];
char constantarr_0_397[17];
char constantarr_0_398[6];
char constantarr_0_399[21];
char constantarr_0_400[16];
char constantarr_0_401[11];
char constantarr_0_402[17];
char constantarr_0_403[26];
char constantarr_0_404[14];
char constantarr_0_405[8];
char constantarr_0_406[13];
char constantarr_0_407[15];
char constantarr_0_408[26];
char constantarr_0_409[13];
char constantarr_0_410[6];
char constantarr_0_411[7];
char constantarr_0_412[9];
char constantarr_0_413[22];
char constantarr_0_414[17];
char constantarr_0_415[14];
char constantarr_0_416[21];
char constantarr_0_417[32];
char constantarr_0_418[7];
char constantarr_0_419[7];
char constantarr_0_420[8];
char constantarr_0_421[25];
char constantarr_0_422[28];
char constantarr_0_423[19];
char constantarr_0_424[14];
char constantarr_0_425[13];
char constantarr_0_426[19];
char constantarr_0_427[15];
char constantarr_0_428[19];
char constantarr_0_429[11];
char constantarr_0_430[9];
char constantarr_0_431[11];
char constantarr_0_432[9];
char constantarr_0_433[37];
char constantarr_0_434[12];
char constantarr_0_435[12];
char constantarr_0_436[16];
char constantarr_0_437[11];
char constantarr_0_438[21];
char constantarr_0_439[11];
char constantarr_0_440[10];
char constantarr_0_441[8];
char constantarr_0_442[8];
char constantarr_0_443[5];
char constantarr_0_444[10];
char constantarr_0_445[15];
char constantarr_0_446[29];
char constantarr_0_447[7];
char constantarr_0_448[11];
char constantarr_0_449[10];
char constantarr_0_450[6];
char constantarr_0_451[11];
char constantarr_0_452[32];
char constantarr_0_453[37];
char constantarr_0_454[8];
char constantarr_0_455[35];
char constantarr_0_456[14];
char constantarr_0_457[10];
char constantarr_0_458[13];
char constantarr_0_459[12];
char constantarr_0_460[46];
char constantarr_0_461[13];
char constantarr_0_462[12];
char constantarr_0_463[8];
char constantarr_0_464[20];
char constantarr_0_465[8];
char constantarr_0_466[14];
char constantarr_0_467[20];
char constantarr_0_468[14];
char constantarr_0_469[14];
char constantarr_0_470[7];
char constantarr_0_471[12];
char constantarr_0_472[9];
char constantarr_0_473[18];
char constantarr_0_474[15];
char constantarr_0_475[27];
char constantarr_0_476[15];
char constantarr_0_477[12];
char constantarr_0_478[27];
char constantarr_0_479[6];
char constantarr_0_480[5];
char constantarr_0_481[14];
char constantarr_0_482[19];
char constantarr_0_483[4];
char constantarr_0_484[35];
char constantarr_0_485[18];
char constantarr_0_486[23];
char constantarr_0_487[39];
char constantarr_0_488[8];
char constantarr_0_489[25];
char constantarr_0_490[4];
char constantarr_0_491[16];
char constantarr_0_492[14];
char constantarr_0_493[13];
char constantarr_0_494[8];
char constantarr_0_495[8];
char constantarr_0_496[14];
char constantarr_0_497[8];
char constantarr_0_498[15];
char constantarr_0_499[21];
char constantarr_0_500[6];
char constantarr_0_501[8];
char constantarr_0_502[16];
char constantarr_0_503[22];
char constantarr_0_504[12];
char constantarr_0_505[7];
char constantarr_0_506[24];
char constantarr_0_507[26];
char constantarr_0_508[24];
char constantarr_0_509[14];
char constantarr_0_510[12];
char constantarr_0_511[15];
char constantarr_0_512[16];
char constantarr_0_513[23];
char constantarr_0_514[16];
char constantarr_0_515[23];
char constantarr_0_516[6];
char constantarr_0_517[4];
char constantarr_0_518[9];
char constantarr_0_519[9];
char constantarr_0_520[15];
char constantarr_0_521[22];
char constantarr_0_522[9];
char constantarr_0_523[16];
char constantarr_0_524[17];
char constantarr_0_525[8];
char constantarr_0_526[8];
char constantarr_0_527[19];
char constantarr_0_528[14];
char constantarr_0_529[18];
char constantarr_0_530[13];
char constantarr_0_531[6];
char constantarr_0_532[12];
char constantarr_0_533[19];
char constantarr_0_534[20];
char constantarr_0_535[18];
char constantarr_0_536[15];
char constantarr_0_0[17] = "Assertion failed!";
char constantarr_0_1[4] = "TODO";
char constantarr_0_2[20] = "uncaught exception: ";
char constantarr_0_3[1] = "\n";
char constantarr_0_4[17] = "<<empty message>>";
char constantarr_0_5[13] = "assert failed";
char constantarr_0_6[4] = "info";
char constantarr_0_7[4] = "warn";
char constantarr_0_8[2] = ": ";
char constantarr_0_9[38] = "Couldn't acquire lock after 1000 tries";
char constantarr_0_10[33] = "resolving an already-resolved fut";
char constantarr_0_11[13] = "forbid failed";
char constantarr_0_12[40] = "Did not find the element in the mut-list";
char constantarr_0_13[11] = "unreachable";
char constantarr_0_14[13] = "main failed: ";
char constantarr_0_15[13] = "sdl error in ";
char constantarr_0_16[1] = " ";
char constantarr_0_17[14] = "sdl-init-video";
char constantarr_0_18[1] = "\0";
char constantarr_0_19[12] = "Hello World!";
char constantarr_0_20[17] = "sdl-create-window";
char constantarr_0_21[19] = "sdl-create-renderer";
char constantarr_0_22[14] = "demo/hello.bmp";
char constantarr_0_23[2] = "rb";
char constantarr_0_24[17] = "sdl-loadbmp-error";
char constantarr_0_25[31] = "sdl-create-texture-from-surface";
char constantarr_0_26[9] = "no return";
char constantarr_0_27[17] = "return is pressed";
char constantarr_0_28[16] = "sdl-render-clear";
char constantarr_0_29[15] = "sdl-render-copy";
char constantarr_0_30[7] = "Bye bye";
char constantarr_0_31[4] = "mark";
char constantarr_0_32[14] = "words-of-bytes";
char constantarr_0_33[10] = "unsafe-div";
char constantarr_0_34[25] = "round-up-to-multiple-of-8";
char constantarr_0_35[8] = "bits-and";
char constantarr_0_36[8] = "wrap-add";
char constantarr_0_37[8] = "bits-not";
char constantarr_0_38[12] = "as<ptr<nat>>";
char constantarr_0_39[19] = "ptr-cast<nat, nat8>";
char constantarr_0_40[11] = "hard-assert";
char constantarr_0_41[3] = "not";
char constantarr_0_42[15] = "hard-fail<void>";
char constantarr_0_43[7] = "==<nat>";
char constantarr_0_44[7] = "<=><?t>";
char constantarr_0_45[5] = "false";
char constantarr_0_46[4] = "true";
char constantarr_0_47[11] = "to-nat<nat>";
char constantarr_0_48[6] = "-<nat>";
char constantarr_0_49[8] = "wrap-sub";
char constantarr_0_50[11] = "size-of<?t>";
char constantarr_0_51[12] = "memory-start";
char constantarr_0_52[6] = "<<nat>";
char constantarr_0_53[17] = "memory-size-words";
char constantarr_0_54[7] = "<=<nat>";
char constantarr_0_55[7] = "+<bool>";
char constantarr_0_56[5] = "marks";
char constantarr_0_57[16] = "mark-range-recur";
char constantarr_0_58[13] = "ptr-eq?<bool>";
char constantarr_0_59[2] = "or";
char constantarr_0_60[11] = "deref<bool>";
char constantarr_0_61[9] = "set<bool>";
char constantarr_0_62[10] = "incr<bool>";
char constantarr_0_63[6] = "><nat>";
char constantarr_0_64[7] = "rt-main";
char constantarr_0_65[10] = "get-nprocs";
char constantarr_0_66[22] = "as<by-val<global-ctx>>";
char constantarr_0_67[10] = "global-ctx";
char constantarr_0_68[8] = "new-lock";
char constantarr_0_69[4] = "lock";
char constantarr_0_70[15] = "new-atomic-bool";
char constantarr_0_71[11] = "atomic-bool";
char constantarr_0_72[17] = "empty-arr<island>";
char constantarr_0_73[7] = "arr<?t>";
char constantarr_0_74[8] = "null<?t>";
char constantarr_0_75[13] = "new-condition";
char constantarr_0_76[9] = "condition";
char constantarr_0_77[22] = "ref-of-val<global-ctx>";
char constantarr_0_78[10] = "new-island";
char constantarr_0_79[14] = "new-task-queue";
char constantarr_0_80[10] = "task-queue";
char constantarr_0_81[4] = "none";
char constantarr_0_82[60] = "new-mut-list-by-val-with-capacity-from-unmanaged-memory<nat>";
char constantarr_0_83[11] = "mut-arr<?t>";
char constantarr_0_84[35] = "unmanaged-alloc-zeroed-elements<?t>";
char constantarr_0_85[28] = "unmanaged-alloc-elements<?t>";
char constantarr_0_86[21] = "unmanaged-alloc-bytes";
char constantarr_0_87[6] = "malloc";
char constantarr_0_88[11] = "hard-forbid";
char constantarr_0_89[11] = "null?<nat8>";
char constantarr_0_90[10] = "to-nat<?t>";
char constantarr_0_91[8] = "wrap-mul";
char constantarr_0_92[18] = "set-zero-range<?t>";
char constantarr_0_93[6] = "memset";
char constantarr_0_94[19] = "as-any-ptr<ptr<?t>>";
char constantarr_0_95[12] = "mut-list<?t>";
char constantarr_0_96[26] = "as<by-val<island-gc-root>>";
char constantarr_0_97[14] = "island-gc-root";
char constantarr_0_98[25] = "default-exception-handler";
char constantarr_0_99[20] = "print-err-no-newline";
char constantarr_0_100[16] = "write-no-newline";
char constantarr_0_101[13] = "size-of<char>";
char constantarr_0_102[13] = "size-of<nat8>";
char constantarr_0_103[5] = "write";
char constantarr_0_104[21] = "as-any-ptr<ptr<char>>";
char constantarr_0_105[10] = "data<char>";
char constantarr_0_106[10] = "size<char>";
char constantarr_0_107[7] = "!=<int>";
char constantarr_0_108[6] = "==<?t>";
char constantarr_0_109[13] = "unsafe-to-int";
char constantarr_0_110[10] = "todo<void>";
char constantarr_0_111[6] = "stderr";
char constantarr_0_112[9] = "print-err";
char constantarr_0_113[12] = "?<arr<char>>";
char constantarr_0_114[12] = "empty?<char>";
char constantarr_0_115[7] = "message";
char constantarr_0_116[29] = "set-any-unhandled-exceptions?";
char constantarr_0_117[14] = "get-global-ctx";
char constantarr_0_118[18] = "as-ref<global-ctx>";
char constantarr_0_119[8] = "gctx-ptr";
char constantarr_0_120[7] = "get-ctx";
char constantarr_0_121[18] = "new-island.lambda0";
char constantarr_0_122[19] = "default-log-handler";
char constantarr_0_123[5] = "print";
char constantarr_0_124[16] = "print-no-newline";
char constantarr_0_125[6] = "stdout";
char constantarr_0_126[7] = "+<char>";
char constantarr_0_127[1] = "+";
char constantarr_0_128[6] = "assert";
char constantarr_0_129[10] = "fail<void>";
char constantarr_0_130[9] = "throw<?t>";
char constantarr_0_131[17] = "get-exception-ctx";
char constantarr_0_132[21] = "as-ref<exception-ctx>";
char constantarr_0_133[17] = "exception-ctx-ptr";
char constantarr_0_134[18] = "null?<jmp-buf-tag>";
char constantarr_0_135[11] = "jmp-buf-ptr";
char constantarr_0_136[20] = "set-thrown-exception";
char constantarr_0_137[7] = "longjmp";
char constantarr_0_138[15] = "number-to-throw";
char constantarr_0_139[9] = "exception";
char constantarr_0_140[3] = "and";
char constantarr_0_141[7] = ">=<nat>";
char constantarr_0_142[22] = "uninitialized-data<?t>";
char constantarr_0_143[5] = "alloc";
char constantarr_0_144[8] = "gc-alloc";
char constantarr_0_145[12] = "try-gc-alloc";
char constantarr_0_146[11] = "validate-gc";
char constantarr_0_147[18] = "ptr-less-eq?<bool>";
char constantarr_0_148[13] = "ptr-less?<?t>";
char constantarr_0_149[10] = "mark-begin";
char constantarr_0_150[8] = "mark-cur";
char constantarr_0_151[8] = "mark-end";
char constantarr_0_152[17] = "ptr-less-eq?<nat>";
char constantarr_0_153[11] = "ptr-eq?<?t>";
char constantarr_0_154[10] = "data-begin";
char constantarr_0_155[8] = "data-cur";
char constantarr_0_156[8] = "data-end";
char constantarr_0_157[7] = "-<bool>";
char constantarr_0_158[10] = "size-words";
char constantarr_0_159[6] = "+<nat>";
char constantarr_0_160[11] = "range-free?";
char constantarr_0_161[12] = "set-mark-cur";
char constantarr_0_162[12] = "set-data-cur";
char constantarr_0_163[15] = "some<ptr<nat8>>";
char constantarr_0_164[19] = "ptr-cast<nat8, nat>";
char constantarr_0_165[9] = "incr<nat>";
char constantarr_0_166[15] = "todo<ptr<nat8>>";
char constantarr_0_167[13] = "hard-fail<?t>";
char constantarr_0_168[16] = "value<ptr<nat8>>";
char constantarr_0_169[6] = "get-gc";
char constantarr_0_170[2] = "gc";
char constantarr_0_171[10] = "get-gc-ctx";
char constantarr_0_172[14] = "as-ref<gc-ctx>";
char constantarr_0_173[10] = "gc-ctx-ptr";
char constantarr_0_174[18] = "ptr-cast<?t, nat8>";
char constantarr_0_175[18] = "copy-data-from<?t>";
char constantarr_0_176[6] = "memcpy";
char constantarr_0_177[5] = "+<?t>";
char constantarr_0_178[6] = "to-str";
char constantarr_0_179[5] = "level";
char constantarr_0_180[18] = "new-island.lambda1";
char constantarr_0_181[6] = "island";
char constantarr_0_182[6] = "new-gc";
char constantarr_0_183[20] = "ptr-cast<bool, nat8>";
char constantarr_0_184[21] = "as-any-ptr<ptr<bool>>";
char constantarr_0_185[23] = "new-thread-safe-counter";
char constantarr_0_186[19] = "thread-safe-counter";
char constantarr_0_187[18] = "ref-of-val<island>";
char constantarr_0_188[11] = "set-islands";
char constantarr_0_189[14] = "ptr-to<island>";
char constantarr_0_190[7] = "do-main";
char constantarr_0_191[17] = "new-exception-ctx";
char constantarr_0_192[13] = "exception-ctx";
char constantarr_0_193[11] = "new-log-ctx";
char constantarr_0_194[7] = "log-ctx";
char constantarr_0_195[26] = "zeroed<fun1<void, logged>>";
char constantarr_0_196[30] = "as<by-val<thread-local-stuff>>";
char constantarr_0_197[18] = "thread-local-stuff";
char constantarr_0_198[25] = "ref-of-val<exception-ctx>";
char constantarr_0_199[19] = "ref-of-val<log-ctx>";
char constantarr_0_200[7] = "new-ctx";
char constantarr_0_201[18] = "as-any-ptr<gc-ctx>";
char constantarr_0_202[12] = "acquire-lock";
char constantarr_0_203[18] = "acquire-lock-recur";
char constantarr_0_204[16] = "try-acquire-lock";
char constantarr_0_205[7] = "try-set";
char constantarr_0_206[10] = "try-change";
char constantarr_0_207[23] = "compare-exchange-strong";
char constantarr_0_208[12] = "ptr-to<bool>";
char constantarr_0_209[5] = "value";
char constantarr_0_210[23] = "ref-of-val<atomic-bool>";
char constantarr_0_211[9] = "is-locked";
char constantarr_0_212[12] = "yield-thread";
char constantarr_0_213[13] = "pthread-yield";
char constantarr_0_214[9] = "==<int32>";
char constantarr_0_215[10] = "noctx-incr";
char constantarr_0_216[7] = "max-nat";
char constantarr_0_217[9] = "wrap-incr";
char constantarr_0_218[16] = "ref-of-val<lock>";
char constantarr_0_219[2] = "lk";
char constantarr_0_220[12] = "context-head";
char constantarr_0_221[23] = "size-of<by-val<gc-ctx>>";
char constantarr_0_222[6] = "set-gc";
char constantarr_0_223[12] = "set-next-ctx";
char constantarr_0_224[13] = "value<gc-ctx>";
char constantarr_0_225[16] = "set-context-head";
char constantarr_0_226[8] = "next-ctx";
char constantarr_0_227[12] = "release-lock";
char constantarr_0_228[10] = "must-unset";
char constantarr_0_229[9] = "try-unset";
char constantarr_0_230[14] = "ref-of-val<gc>";
char constantarr_0_231[11] = "set-handler";
char constantarr_0_232[11] = "log-handler";
char constantarr_0_233[26] = "ref-of-val<island-gc-root>";
char constantarr_0_234[7] = "gc-root";
char constantarr_0_235[3] = "ctx";
char constantarr_0_236[22] = "as-any-ptr<global-ctx>";
char constantarr_0_237[2] = "id";
char constantarr_0_238[25] = "as-any-ptr<exception-ctx>";
char constantarr_0_239[19] = "as-any-ptr<log-ctx>";
char constantarr_0_240[30] = "ref-of-val<thread-local-stuff>";
char constantarr_0_241[15] = "ref-of-val<ctx>";
char constantarr_0_242[79] = "as<fun2<fut<int32>, arr<ptr<char>>, fun-ptr2<fut<int32>, ctx, arr<arr<char>>>>>";
char constantarr_0_243[14] = "add-first-task";
char constantarr_0_244[12] = "then2<int32>";
char constantarr_0_245[16] = "then<?out, void>";
char constantarr_0_246[24] = "new-unresolved-fut<?out>";
char constantarr_0_247[7] = "fut<?t>";
char constantarr_0_248[23] = "fut-state-callbacks<?t>";
char constantarr_0_249[14] = "then-void<?in>";
char constantarr_0_250[6] = "lk<?t>";
char constantarr_0_251[9] = "state<?t>";
char constantarr_0_252[13] = "set-state<?t>";
char constantarr_0_253[27] = "some<fut-callback-node<?t>>";
char constantarr_0_254[21] = "fut-callback-node<?t>";
char constantarr_0_255[8] = "head<?t>";
char constantarr_0_256[33] = "call<void, result<?t, exception>>";
char constantarr_0_257[22] = "call-with-ctx<?r, ?p0>";
char constantarr_0_258[6] = "ok<?t>";
char constantarr_0_259[9] = "value<?t>";
char constantarr_0_260[14] = "err<exception>";
char constantarr_0_261[16] = "forward-to<?out>";
char constantarr_0_262[13] = "then-void<?t>";
char constantarr_0_263[21] = "resolve-or-reject<?t>";
char constantarr_0_264[27] = "resolve-or-reject-recur<?t>";
char constantarr_0_265[4] = "void";
char constantarr_0_266[10] = "drop<void>";
char constantarr_0_267[6] = "cb<?t>";
char constantarr_0_268[28] = "value<fut-callback-node<?t>>";
char constantarr_0_269[13] = "next-node<?t>";
char constantarr_0_270[22] = "fut-state-resolved<?t>";
char constantarr_0_271[16] = "value<exception>";
char constantarr_0_272[24] = "forward-to<?out>.lambda0";
char constantarr_0_273[19] = "call-ref<?out, ?in>";
char constantarr_0_274[10] = "get-island";
char constantarr_0_275[10] = "at<island>";
char constantarr_0_276[8] = "size<?t>";
char constantarr_0_277[12] = "noctx-at<?t>";
char constantarr_0_278[9] = "deref<?t>";
char constantarr_0_279[8] = "data<?t>";
char constantarr_0_280[7] = "islands";
char constantarr_0_281[29] = "island-and-exclusion<?r, ?p0>";
char constantarr_0_282[8] = "add-task";
char constantarr_0_283[19] = "new-task-queue-node";
char constantarr_0_284[15] = "task-queue-node";
char constantarr_0_285[4] = "task";
char constantarr_0_286[10] = "tasks-lock";
char constantarr_0_287[11] = "insert-task";
char constantarr_0_288[4] = "size";
char constantarr_0_289[10] = "size-recur";
char constantarr_0_290[4] = "next";
char constantarr_0_291[22] = "value<task-queue-node>";
char constantarr_0_292[4] = "head";
char constantarr_0_293[8] = "set-head";
char constantarr_0_294[21] = "some<task-queue-node>";
char constantarr_0_295[4] = "time";
char constantarr_0_296[12] = "insert-recur";
char constantarr_0_297[8] = "set-next";
char constantarr_0_298[5] = "tasks";
char constantarr_0_299[22] = "ref-of-val<task-queue>";
char constantarr_0_300[9] = "broadcast";
char constantarr_0_301[9] = "set-value";
char constantarr_0_302[21] = "ref-of-val<condition>";
char constantarr_0_303[17] = "may-be-work-to-do";
char constantarr_0_304[4] = "gctx";
char constantarr_0_305[12] = "no-timestamp";
char constantarr_0_306[9] = "exclusion";
char constantarr_0_307[11] = "catch<void>";
char constantarr_0_308[28] = "catch-with-exception-ctx<?t>";
char constantarr_0_309[16] = "thrown-exception";
char constantarr_0_310[11] = "jmp-buf-tag";
char constantarr_0_311[4] = "zero";
char constantarr_0_312[7] = "bytes64";
char constantarr_0_313[7] = "bytes32";
char constantarr_0_314[7] = "bytes16";
char constantarr_0_315[8] = "bytes128";
char constantarr_0_316[15] = "set-jmp-buf-ptr";
char constantarr_0_317[19] = "ptr-to<jmp-buf-tag>";
char constantarr_0_318[6] = "setjmp";
char constantarr_0_319[8] = "call<?t>";
char constantarr_0_320[17] = "call-with-ctx<?r>";
char constantarr_0_321[19] = "call<?t, exception>";
char constantarr_0_322[18] = "call<fut<?r>, ?p0>";
char constantarr_0_323[12] = "fun<?r, ?p0>";
char constantarr_0_324[35] = "call-ref<?out, ?in>.lambda0.lambda0";
char constantarr_0_325[10] = "reject<?r>";
char constantarr_0_326[35] = "call-ref<?out, ?in>.lambda0.lambda1";
char constantarr_0_327[27] = "call-ref<?out, ?in>.lambda0";
char constantarr_0_328[10] = "value<?in>";
char constantarr_0_329[24] = "then<?out, void>.lambda0";
char constantarr_0_330[14] = "call-ref<?out>";
char constantarr_0_331[24] = "island-and-exclusion<?r>";
char constantarr_0_332[13] = "call<fut<?r>>";
char constantarr_0_333[7] = "fun<?r>";
char constantarr_0_334[30] = "call-ref<?out>.lambda0.lambda0";
char constantarr_0_335[30] = "call-ref<?out>.lambda0.lambda1";
char constantarr_0_336[22] = "call-ref<?out>.lambda0";
char constantarr_0_337[20] = "then2<int32>.lambda0";
char constantarr_0_338[24] = "cur-island-and-exclusion";
char constantarr_0_339[20] = "island-and-exclusion";
char constantarr_0_340[9] = "island-id";
char constantarr_0_341[5] = "delay";
char constantarr_0_342[14] = "resolved<void>";
char constantarr_0_343[15] = "tail<ptr<char>>";
char constantarr_0_344[6] = "forbid";
char constantarr_0_345[10] = "empty?<?t>";
char constantarr_0_346[21] = "slice-starting-at<?t>";
char constantarr_0_347[9] = "slice<?t>";
char constantarr_0_348[1] = "-";
char constantarr_0_349[37] = "call<fut<int32>, ctx, arr<arr<char>>>";
char constantarr_0_350[25] = "map<arr<char>, ptr<char>>";
char constantarr_0_351[14] = "make-arr<?out>";
char constantarr_0_352[18] = "fill-ptr-range<?t>";
char constantarr_0_353[24] = "fill-ptr-range-recur<?t>";
char constantarr_0_354[7] = "!=<nat>";
char constantarr_0_355[7] = "set<?t>";
char constantarr_0_356[13] = "call<?t, nat>";
char constantarr_0_357[15] = "call<?out, ?in>";
char constantarr_0_358[7] = "at<?in>";
char constantarr_0_359[33] = "map<arr<char>, ptr<char>>.lambda0";
char constantarr_0_360[24] = "arr-from-begin-end<char>";
char constantarr_0_361[5] = "-<?t>";
char constantarr_0_362[13] = "find-cstr-end";
char constantarr_0_363[17] = "find-char-in-cstr";
char constantarr_0_364[8] = "==<char>";
char constantarr_0_365[11] = "deref<char>";
char constantarr_0_366[15] = "todo<ptr<char>>";
char constantarr_0_367[10] = "incr<char>";
char constantarr_0_368[30] = "add-first-task.lambda0.lambda0";
char constantarr_0_369[22] = "add-first-task.lambda0";
char constantarr_0_370[15] = "do-main.lambda0";
char constantarr_0_371[13] = "unsafe-to-nat";
char constantarr_0_372[6] = "to-int";
char constantarr_0_373[84] = "call-with-ctx<fut<int32>, arr<ptr<char>>, fun-ptr2<fut<int32>, ctx, arr<arr<char>>>>";
char constantarr_0_374[11] = "run-threads";
char constantarr_0_375[45] = "unmanaged-alloc-elements<by-val<thread-args>>";
char constantarr_0_376[10] = "noctx-decr";
char constantarr_0_377[19] = "start-threads-recur";
char constantarr_0_378[22] = "+<by-val<thread-args>>";
char constantarr_0_379[24] = "set<by-val<thread-args>>";
char constantarr_0_380[11] = "thread-args";
char constantarr_0_381[17] = "create-one-thread";
char constantarr_0_382[14] = "pthread-create";
char constantarr_0_383[9] = "!=<int32>";
char constantarr_0_384[6] = "eagain";
char constantarr_0_385[12] = "as-cell<nat>";
char constantarr_0_386[16] = "as-ref<cell<?t>>";
char constantarr_0_387[36] = "as-any-ptr<ptr<by-val<thread-args>>>";
char constantarr_0_388[10] = "thread-fun";
char constantarr_0_389[19] = "as-ref<thread-args>";
char constantarr_0_390[15] = "thread-function";
char constantarr_0_391[21] = "thread-function-recur";
char constantarr_0_392[10] = "shut-down?";
char constantarr_0_393[18] = "set-n-live-threads";
char constantarr_0_394[14] = "n-live-threads";
char constantarr_0_395[28] = "assert-islands-are-shut-down";
char constantarr_0_396[9] = "needs-gc?";
char constantarr_0_397[17] = "n-threads-running";
char constantarr_0_398[6] = "empty?";
char constantarr_0_399[21] = "has?<task-queue-node>";
char constantarr_0_400[16] = "get-last-checked";
char constantarr_0_401[11] = "choose-task";
char constantarr_0_402[17] = "get-monotime-nsec";
char constantarr_0_403[26] = "as<by-val<cell<timespec>>>";
char constantarr_0_404[14] = "cell<timespec>";
char constantarr_0_405[8] = "timespec";
char constantarr_0_406[13] = "clock-gettime";
char constantarr_0_407[15] = "clock-monotonic";
char constantarr_0_408[26] = "ref-of-val<cell<timespec>>";
char constantarr_0_409[13] = "get<timespec>";
char constantarr_0_410[6] = "tv-sec";
char constantarr_0_411[7] = "tv-nsec";
char constantarr_0_412[9] = "todo<nat>";
char constantarr_0_413[22] = "as<choose-task-result>";
char constantarr_0_414[17] = "choose-task-recur";
char constantarr_0_415[14] = "no-chosen-task";
char constantarr_0_416[21] = "choose-task-in-island";
char constantarr_0_417[32] = "as<choose-task-in-island-result>";
char constantarr_0_418[7] = "do-a-gc";
char constantarr_0_419[7] = "no-task";
char constantarr_0_420[8] = "pop-task";
char constantarr_0_421[25] = "ref-of-val<mut-list<nat>>";
char constantarr_0_422[28] = "currently-running-exclusions";
char constantarr_0_423[19] = "as<pop-task-result>";
char constantarr_0_424[14] = "contains?<nat>";
char constantarr_0_425[13] = "contains?<?t>";
char constantarr_0_426[19] = "contains-recur?<?t>";
char constantarr_0_427[15] = "temp-as-arr<?t>";
char constantarr_0_428[19] = "temp-as-mut-arr<?t>";
char constantarr_0_429[11] = "backing<?t>";
char constantarr_0_430[9] = "pop-recur";
char constantarr_0_431[11] = "to-opt-time";
char constantarr_0_432[9] = "some<nat>";
char constantarr_0_433[37] = "push-capacity-must-be-sufficient<nat>";
char constantarr_0_434[12] = "capacity<?t>";
char constantarr_0_435[12] = "set-size<?t>";
char constantarr_0_436[16] = "noctx-set-at<?t>";
char constantarr_0_437[11] = "is-no-task?";
char constantarr_0_438[21] = "set-n-threads-running";
char constantarr_0_439[11] = "chosen-task";
char constantarr_0_440[10] = "any-tasks?";
char constantarr_0_441[8] = "min-time";
char constantarr_0_442[8] = "min<nat>";
char constantarr_0_443[5] = "?<?t>";
char constantarr_0_444[10] = "value<nat>";
char constantarr_0_445[15] = "first-task-time";
char constantarr_0_446[29] = "no-tasks-and-last-thread-out?";
char constantarr_0_447[7] = "do-task";
char constantarr_0_448[11] = "task-island";
char constantarr_0_449[10] = "task-or-gc";
char constantarr_0_450[6] = "action";
char constantarr_0_451[11] = "return-task";
char constantarr_0_452[32] = "noctx-must-remove-unordered<nat>";
char constantarr_0_453[37] = "noctx-must-remove-unordered-recur<?t>";
char constantarr_0_454[8] = "drop<?t>";
char constantarr_0_455[35] = "noctx-remove-unordered-at-index<?t>";
char constantarr_0_456[14] = "noctx-last<?t>";
char constantarr_0_457[10] = "return-ctx";
char constantarr_0_458[13] = "return-gc-ctx";
char constantarr_0_459[12] = "some<gc-ctx>";
char constantarr_0_460[46] = "run-garbage-collection<by-val<island-gc-root>>";
char constantarr_0_461[13] = "set-needs-gc?";
char constantarr_0_462[12] = "set-gc-count";
char constantarr_0_463[8] = "gc-count";
char constantarr_0_464[20] = "as<by-val<mark-ctx>>";
char constantarr_0_465[8] = "mark-ctx";
char constantarr_0_466[14] = "mark-visit<?a>";
char constantarr_0_467[20] = "ref-of-val<mark-ctx>";
char constantarr_0_468[14] = "clear-free-mem";
char constantarr_0_469[14] = "set-shut-down?";
char constantarr_0_470[7] = "wait-on";
char constantarr_0_471[12] = "before-time?";
char constantarr_0_472[9] = "thread-id";
char constantarr_0_473[18] = "join-threads-recur";
char constantarr_0_474[15] = "join-one-thread";
char constantarr_0_475[27] = "as<by-val<cell<ptr<nat8>>>>";
char constantarr_0_476[15] = "cell<ptr<nat8>>";
char constantarr_0_477[12] = "pthread-join";
char constantarr_0_478[27] = "ref-of-val<cell<ptr<nat8>>>";
char constantarr_0_479[6] = "einval";
char constantarr_0_480[5] = "esrch";
char constantarr_0_481[14] = "get<ptr<nat8>>";
char constantarr_0_482[19] = "unmanaged-free<nat>";
char constantarr_0_483[4] = "free";
char constantarr_0_484[35] = "unmanaged-free<by-val<thread-args>>";
char constantarr_0_485[18] = "ptr-cast<nat8, ?t>";
char constantarr_0_486[23] = "must-be-resolved<int32>";
char constantarr_0_487[39] = "hard-unreachable<result<?t, exception>>";
char constantarr_0_488[8] = "?<int32>";
char constantarr_0_489[25] = "any-unhandled-exceptions?";
char constantarr_0_490[4] = "main";
char constantarr_0_491[16] = "handle-sdl-error";
char constantarr_0_492[14] = "fail-sdl-error";
char constantarr_0_493[13] = "sdl-get-error";
char constantarr_0_494[8] = "sdl-quit";
char constantarr_0_495[8] = "sdl-init";
char constantarr_0_496[14] = "bit-shift-left";
char constantarr_0_497[8] = "<<nat32>";
char constantarr_0_498[15] = "unsafe-to-nat32";
char constantarr_0_499[21] = "unsafe-bit-shift-left";
char constantarr_0_500[6] = "to-nat";
char constantarr_0_501[8] = "to-c-str";
char constantarr_0_502[16] = "sdl-window-shown";
char constantarr_0_503[22] = "as-any-ptr<sdl-window>";
char constantarr_0_504[12] = "new-renderer";
char constantarr_0_505[7] = "bits-or";
char constantarr_0_506[24] = "sdl-renderer-accelerated";
char constantarr_0_507[26] = "sdl-renderer-present-vsync";
char constantarr_0_508[24] = "as-any-ptr<sdl-renderer>";
char constantarr_0_509[14] = "create-texture";
char constantarr_0_510[12] = "sdl-load-bmp";
char constantarr_0_511[15] = "sdl-load-bmp-rw";
char constantarr_0_512[16] = "sdl-rw-from-file";
char constantarr_0_513[23] = "as-any-ptr<sdl-surface>";
char constantarr_0_514[16] = "sdl-free-surface";
char constantarr_0_515[23] = "as-any-ptr<sdl-texture>";
char constantarr_0_516[6] = "repeat";
char constantarr_0_517[4] = "decr";
char constantarr_0_518[9] = "wrap-decr";
char constantarr_0_519[9] = "main-loop";
char constantarr_0_520[15] = "sdl-pump-events";
char constantarr_0_521[22] = "sdl-get-keyboard-state";
char constantarr_0_522[9] = "null<int>";
char constantarr_0_523[16] = "ptr-as-arr<nat8>";
char constantarr_0_524[17] = "sdl-num-scancodes";
char constantarr_0_525[8] = "==<nat8>";
char constantarr_0_526[8] = "at<nat8>";
char constantarr_0_527[19] = "sdl-scancode-return";
char constantarr_0_528[14] = "null<sdl-rect>";
char constantarr_0_529[18] = "sdl-render-present";
char constantarr_0_530[13] = "sleep-ms-sync";
char constantarr_0_531[6] = "usleep";
char constantarr_0_532[12] = "main.lambda0";
char constantarr_0_533[19] = "sdl-destroy-texture";
char constantarr_0_534[20] = "sdl-destroy-renderer";
char constantarr_0_535[18] = "sdl-destroy-window";
char constantarr_0_536[15] = "resolved<int32>";
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
struct arr_3 empty_arr(void);
struct condition new_condition(void);
struct island new_island(struct global_ctx* gctx, uint64_t id, uint64_t max_threads);
struct task_queue new_task_queue(uint64_t max_threads);
struct mut_list new_mut_list_by_val_with_capacity_from_unmanaged_memory(uint64_t capacity);
struct mut_arr mut_arr(uint64_t size, uint64_t* data);
uint64_t* unmanaged_alloc_zeroed_elements(uint64_t size_elements);
uint64_t* unmanaged_alloc_elements_0(uint64_t size_elements);
uint8_t* unmanaged_alloc_bytes(uint64_t size);
extern uint8_t* malloc(uint64_t size);
struct void_ hard_forbid(uint8_t condition);
uint8_t null__q_0(uint8_t* a);
struct void_ set_zero_range(uint64_t* begin, uint64_t size);
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
struct void_ fail(struct ctx* ctx, struct arr_0 reason);
struct void_ throw(struct ctx* ctx, struct exception e);
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
struct void_ copy_data_from(struct ctx* ctx, char* to, char* from, uint64_t len);
extern void memcpy(uint8_t* dest, uint8_t* src, uint64_t size);
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
struct comparison compare_91(int32_t a, int32_t b);
uint64_t noctx_incr(uint64_t n);
uint64_t max_nat(void);
uint64_t wrap_incr(uint64_t a);
struct void_ release_lock(struct lock* l);
struct void_ must_unset(struct _atomic_bool* a);
uint8_t try_unset(struct _atomic_bool* a);
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb);
struct fut_0* then(struct ctx* ctx, struct fut_1* f, struct fun_ref1 cb);
struct fut_0* new_unresolved_fut(struct ctx* ctx);
struct void_ then_void_0(struct ctx* ctx, struct fut_1* f, struct fun_act1_1 cb);
struct void_ call_0(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0);
struct void_ call_w_ctx_104(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0);
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to);
struct void_ then_void_1(struct ctx* ctx, struct fut_0* f, struct fun_act1_0 cb);
struct void_ call_1(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0);
struct void_ call_w_ctx_108(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0);
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
struct void_ call_w_ctx_135(struct fun_act0_0 a, struct ctx* ctx);
struct void_ call_3(struct ctx* ctx, struct fun_act1_3 a, struct exception p0);
struct void_ call_w_ctx_137(struct fun_act1_3 a, struct ctx* ctx, struct exception p0);
struct fut_0* call_4(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0);
struct fut_0* call_w_ctx_139(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0);
struct void_ call_ref_0__lambda0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0__lambda0* _closure);
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e);
struct void_ call_ref_0__lambda0__lambda1(struct ctx* ctx, struct call_ref_0__lambda0__lambda1* _closure, struct exception it);
struct void_ call_ref_0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0* _closure);
struct void_ then__lambda0(struct ctx* ctx, struct then__lambda0* _closure, struct result_1 result);
struct fut_0* call_ref_1(struct ctx* ctx, struct fun_ref0 f);
struct fut_0* call_5(struct ctx* ctx, struct fun_act0_1 a);
struct fut_0* call_w_ctx_147(struct fun_act0_1 a, struct ctx* ctx);
struct void_ call_ref_1__lambda0__lambda0(struct ctx* ctx, struct call_ref_1__lambda0__lambda0* _closure);
struct void_ call_ref_1__lambda0__lambda1(struct ctx* ctx, struct call_ref_1__lambda0__lambda1* _closure, struct exception it);
struct void_ call_ref_1__lambda0(struct ctx* ctx, struct call_ref_1__lambda0* _closure);
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore);
struct island_and_exclusion cur_island_and_exclusion(struct ctx* ctx);
struct fut_1* delay(struct ctx* ctx);
struct fut_1* resolved_0(struct ctx* ctx, struct void_ value);
struct arr_4 tail(struct ctx* ctx, struct arr_4 a);
struct void_ forbid_0(struct ctx* ctx, uint8_t condition);
struct void_ forbid_1(struct ctx* ctx, uint8_t condition, struct arr_0 message);
uint8_t empty__q_1(struct arr_4 a);
struct arr_4 slice_starting_at(struct ctx* ctx, struct arr_4 a, uint64_t begin);
struct arr_4 slice(struct ctx* ctx, struct arr_4 a, uint64_t begin, uint64_t size);
uint64_t _op_minus_2(struct ctx* ctx, uint64_t a, uint64_t b);
struct arr_1 map(struct ctx* ctx, struct arr_4 a, struct fun_act1_4 mapper);
struct arr_1 make_arr(struct ctx* ctx, uint64_t size, struct fun_act1_5 f);
struct arr_0* uninitialized_data_1(struct ctx* ctx, uint64_t size);
struct void_ fill_ptr_range(struct ctx* ctx, struct arr_0* begin, uint64_t size, struct fun_act1_5 f);
struct void_ fill_ptr_range_recur(struct ctx* ctx, struct arr_0* begin, uint64_t i, uint64_t size, struct fun_act1_5 f);
uint8_t _op_bang_equal_1(uint64_t a, uint64_t b);
struct arr_0 call_6(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0);
struct arr_0 call_w_ctx_169(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0);
struct arr_0 call_7(struct ctx* ctx, struct fun_act1_4 a, char* p0);
struct arr_0 call_w_ctx_171(struct fun_act1_4 a, struct ctx* ctx, char* p0);
char* at_1(struct ctx* ctx, struct arr_4 a, uint64_t index);
char* noctx_at_1(struct arr_4 a, uint64_t index);
struct arr_0 map__lambda0(struct ctx* ctx, struct map__lambda0* _closure, uint64_t i);
struct arr_0 to_str_1(char* a);
struct arr_0 arr_from_begin_end(char* begin, char* end);
uint64_t _op_minus_3(char* a, char* b);
char* find_cstr_end(char* a);
char* find_char_in_cstr(char* a, char c);
uint8_t _op_equal_equal_3(char a, char b);
struct comparison compare_181(char a, char b);
char* todo_2(void);
char* incr_2(char* p);
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it);
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure);
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr);
struct fut_0* call_w_ctx_187(struct fun2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1);
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
uint8_t has__q(struct opt_2 a);
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
uint8_t contains__q_0(struct mut_list* a, uint64_t value);
uint8_t contains__q_1(struct arr_2 a, uint64_t value);
uint8_t contains_recur__q(struct arr_2 a, uint64_t value, uint64_t i);
uint64_t noctx_at_2(struct arr_2 a, uint64_t index);
struct arr_2 temp_as_arr_0(struct mut_list* a);
struct arr_2 temp_as_arr_1(struct mut_arr a);
struct mut_arr temp_as_mut_arr(struct mut_list* a);
uint64_t* data_0(struct mut_list* a);
uint64_t* data_1(struct mut_arr a);
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list* exclusions, uint64_t cur_time, struct opt_5 first_task_time);
struct opt_5 to_opt_time(uint64_t a);
struct void_ push_capacity_must_be_sufficient(struct mut_list* a, uint64_t value);
uint64_t capacity(struct mut_list* a);
uint64_t size_1(struct mut_arr a);
struct void_ noctx_set_at(struct mut_list* a, uint64_t index, uint64_t value);
uint8_t is_no_task__q(struct choose_task_in_island_result a);
struct opt_5 min_time(struct opt_5 a, struct opt_5 b);
uint64_t min(uint64_t a, uint64_t b);
struct void_ do_task(struct global_ctx* gctx, struct thread_local_stuff* tls, struct chosen_task chosen_task);
struct void_ return_task(struct task_queue* a, struct task task);
struct void_ noctx_must_remove_unordered(struct mut_list* a, uint64_t value);
struct void_ noctx_must_remove_unordered_recur(struct mut_list* a, uint64_t index, uint64_t value);
uint64_t noctx_at_3(struct mut_list* a, uint64_t index);
struct void_ drop_1(uint64_t _p0);
uint64_t noctx_remove_unordered_at_index(struct mut_list* a, uint64_t index);
uint64_t noctx_last(struct mut_list* a);
uint8_t empty__q_4(struct mut_list* a);
struct void_ return_ctx(struct ctx* c);
struct void_ return_gc_ctx(struct gc_ctx* gc_ctx);
struct void_ run_garbage_collection(struct gc* gc, struct island_gc_root gc_root);
struct void_ mark_visit_244(struct mark_ctx* mark_ctx, struct island_gc_root value);
struct void_ mark_visit_245(struct mark_ctx* mark_ctx, struct task_queue value);
struct void_ mark_visit_246(struct mark_ctx* mark_ctx, struct opt_2 value);
struct void_ mark_visit_247(struct mark_ctx* mark_ctx, struct some_2 value);
struct void_ mark_visit_248(struct mark_ctx* mark_ctx, struct task_queue_node value);
struct void_ mark_visit_249(struct mark_ctx* mark_ctx, struct task value);
struct void_ mark_visit_250(struct mark_ctx* mark_ctx, struct fun_act0_0 value);
struct void_ mark_visit_251(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0 value);
struct void_ mark_visit_252(struct mark_ctx* mark_ctx, struct fun_ref1 value);
struct void_ mark_visit_253(struct mark_ctx* mark_ctx, struct fun_act1_2 value);
struct void_ mark_visit_254(struct mark_ctx* mark_ctx, struct then2__lambda0 value);
struct void_ mark_visit_255(struct mark_ctx* mark_ctx, struct fun_ref0 value);
struct void_ mark_visit_256(struct mark_ctx* mark_ctx, struct fun_act0_1 value);
struct void_ mark_visit_257(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value);
struct void_ mark_arr_258(struct mark_ctx* mark_ctx, struct arr_4 a);
struct void_ mark_visit_259(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value);
struct void_ mark_visit_260(struct mark_ctx* mark_ctx, struct then2__lambda0* value);
struct void_ mark_visit_261(struct mark_ctx* mark_ctx, struct fut_0 value);
struct void_ mark_visit_262(struct mark_ctx* mark_ctx, struct fut_state_0 value);
struct void_ mark_visit_263(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value);
struct void_ mark_visit_264(struct mark_ctx* mark_ctx, struct opt_0 value);
struct void_ mark_visit_265(struct mark_ctx* mark_ctx, struct some_0 value);
struct void_ mark_visit_266(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value);
struct void_ mark_visit_267(struct mark_ctx* mark_ctx, struct fun_act1_0 value);
struct void_ mark_visit_268(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value);
struct void_ mark_visit_269(struct mark_ctx* mark_ctx, struct fut_0* value);
struct void_ mark_visit_270(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value);
struct void_ mark_visit_271(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value);
struct void_ mark_visit_272(struct mark_ctx* mark_ctx, struct exception value);
struct void_ mark_arr_273(struct mark_ctx* mark_ctx, struct arr_0 a);
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0* value);
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0 value);
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0* value);
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0 value);
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0* value);
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0 value);
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0* value);
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct main_0__lambda0* value);
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct task_queue_node* value);
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct mut_list value);
struct void_ mark_visit_284(struct mark_ctx* mark_ctx, struct mut_arr value);
struct void_ mark_arr_285(struct mark_ctx* mark_ctx, struct arr_2 a);
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
struct result_0 hard_unreachable(void);
struct fut_0* main_0(struct ctx* ctx, struct arr_1 _p0);
struct void_ handle_sdl_error(struct ctx* ctx, struct arr_0 operation, int64_t err);
struct void_ fail_sdl_error(struct ctx* ctx, struct arr_0 operation);
extern char* SDL_GetError(void);
extern void SDL_Quit(void);
extern int64_t SDL_Init(uint32_t flags);
uint32_t sdl_init_video(struct ctx* ctx);
uint32_t bit_shift_left(uint32_t a, uint32_t b);
uint8_t _op_less_1(uint32_t a, uint32_t b);
struct comparison compare_309(uint32_t a, uint32_t b);
extern struct sdl_window* SDL_CreateWindow(char* title, int64_t x, int64_t y, int64_t w, int64_t h, uint32_t flags);
char* to_c_str(struct ctx* ctx, struct arr_0 a);
uint32_t sdl_window_shown(struct ctx* ctx);
struct sdl_renderer* new_renderer(struct ctx* ctx, struct sdl_window* window);
extern struct sdl_renderer* SDL_CreateRenderer(struct sdl_window* window, int64_t index, uint32_t flags);
uint32_t sdl_renderer_accelerated(struct ctx* ctx);
uint32_t sdl_renderer_present_vsync(struct ctx* ctx);
struct sdl_texture* create_texture(struct ctx* ctx, struct sdl_renderer* renderer);
struct sdl_surface* sdl_load_bmp(struct ctx* ctx, struct arr_0 file);
extern struct sdl_surface* SDL_LoadBMP_RW(struct sdl_rwops* src, int64_t freesrc);
extern struct sdl_rwops* SDL_RWFromFile(char* file, char* mode);
extern struct sdl_texture* SDL_CreateTextureFromSurface(struct sdl_renderer* renderer, struct sdl_surface* surface);
extern void SDL_FreeSurface(struct sdl_surface* surface);
struct void_ repeat(struct ctx* ctx, uint64_t times, struct fun_act0_0 action);
uint64_t decr(struct ctx* ctx, uint64_t a);
uint64_t wrap_decr(uint64_t a);
struct void_ main_loop(struct ctx* ctx, struct sdl_renderer* renderer, struct sdl_texture* texture);
extern void SDL_PumpEvents(void);
extern uint8_t* SDL_GetKeyboardState(int64_t* num_keys);
struct arr_5 ptr_as_arr(struct ctx* ctx, uint64_t size, uint8_t* data);
uint64_t sdl_num_scancodes(struct ctx* ctx);
uint8_t _op_equal_equal_4(uint8_t a, uint8_t b);
struct comparison compare_332(uint8_t a, uint8_t b);
uint8_t at_2(struct ctx* ctx, struct arr_5 a, uint64_t index);
uint8_t noctx_at_4(struct arr_5 a, uint64_t index);
uint64_t sdl_scancode_return(struct ctx* ctx);
extern int64_t SDL_RenderClear(struct sdl_renderer* renderer);
extern int64_t SDL_RenderCopy(struct sdl_renderer* renderer, struct sdl_texture* texture, struct sdl_rect** src_rect, struct sdl_rect** dest_rect);
extern void SDL_RenderPresent(struct sdl_renderer* renderer);
struct void_ sleep_ms_sync(uint64_t ms);
extern void usleep(uint64_t micro_seconds);
struct void_ main_0__lambda0(struct ctx* ctx, struct main_0__lambda0* _closure);
extern void SDL_DestroyTexture(struct sdl_texture* texture);
extern void SDL_DestroyRenderer(struct sdl_renderer* renderer);
extern void SDL_DestroyWindow(struct sdl_window* window);
struct fut_0* resolved_1(struct ctx* ctx, int32_t value);
int32_t main(int32_t argc, char** argv);
/* mark bool(ctx mark-ctx, ptr-any ptr<nat8>, size-bytes nat) */
uint8_t mark(struct mark_ctx* ctx, uint8_t* ptr_any, uint64_t size_bytes) {
	uint64_t size_words0;
	size_words0 = words_of_bytes(size_bytes);
	
	uint64_t* ptr1;
	ptr1 = (uint64_t*) ptr_any;
	
	uint8_t _0 = _op_equal_equal_0(((uint64_t) ptr1 & 7u), 0u);
	hard_assert(_0);
	uint64_t index2;
	index2 = _op_minus_0(ptr1, ctx->memory_start);
	
	uint8_t gc_memory__q3;
	gc_memory__q3 = _op_less_0(index2, ctx->memory_size_words);
	
	uint8_t _1 = gc_memory__q3;
	if (_1) {
		uint8_t _2 = _op_less_equal((index2 + size_words0), ctx->memory_size_words);
		hard_assert(_2);
		uint8_t* mark_start4;
		mark_start4 = (ctx->marks + index2);
		
		uint8_t* mark_end5;
		mark_end5 = (mark_start4 + size_words0);
		
		return mark_range_recur(0, mark_start4, mark_end5);
	} else {
		uint8_t _3 = _op_greater((index2 + size_words0), ctx->memory_size_words);
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
	uint8_t _0 = !condition;
	if (_0) {
		return (assert(0),(struct void_) {});
	} else {
		return (struct void_) {};
	}
}
/* ==<nat> bool(a nat, b nat) */
uint8_t _op_equal_equal_0(uint64_t a, uint64_t b) {
	struct comparison _0 = compare_5(a, b);
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
			return (assert(0),0);
	}
}
/* compare<nat-64> (generated) (generated) */
struct comparison compare_5(uint64_t a, uint64_t b) {
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
uint64_t _op_minus_0(uint64_t* a, uint64_t* b) {
	return (((uint64_t) a - (uint64_t) b) / sizeof(uint64_t));
}
/* <<nat> bool(a nat, b nat) */
uint8_t _op_less_0(uint64_t a, uint64_t b) {
	struct comparison _0 = compare_5(a, b);
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
			return (assert(0),0);
	}
}
/* <=<nat> bool(a nat, b nat) */
uint8_t _op_less_equal(uint64_t a, uint64_t b) {
	uint8_t _0 = _op_less_0(b, a);
	return !_0;
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
			new_marked_anything__q0 = !*cur;
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
uint8_t _op_greater(uint64_t a, uint64_t b) {
	uint8_t _0 = _op_less_equal(a, b);
	return !_0;
}
/* rt-main int32(argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
int32_t rt_main(int32_t argc, char** argv, fun_ptr2 main_ptr) {
	uint64_t n_threads0;
	n_threads0 = get_nprocs();
	
	struct global_ctx gctx_by_val1;
	struct lock _0 = new_lock();
	struct arr_3 _1 = empty_arr();
	struct condition _2 = new_condition();
	gctx_by_val1 = (struct global_ctx) {_0, _1, n_threads0, _2, 0, 0};
	
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
	struct result_0 _3 = must_be_resolved(main_fut5);
	switch (_3.kind) {
		case 0: {
			struct ok_0 o6 = _3.as0;
			
			uint8_t _4 = gctx2->any_unhandled_exceptions__q;
			if (_4) {
				return 1;
			} else {
				return o6.value;
			}
		}
		case 1: {
			struct err e7 = _3.as1;
			
			print_err_no_newline((struct arr_0) {13, constantarr_0_14});
			print_err(e7.value.message);
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
	return (struct _atomic_bool) {0};
}
/* empty-arr<island> arr<island>() */
struct arr_3 empty_arr(void) {
	return (struct arr_3) {0u, NULL};
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
	struct mut_list _0 = new_mut_list_by_val_with_capacity_from_unmanaged_memory(max_threads);
	return (struct task_queue) {(struct opt_2) {0, .as0 = (struct none) {}}, _0};
}
/* new-mut-list-by-val-with-capacity-from-unmanaged-memory<nat> mut-list<nat>(capacity nat) */
struct mut_list new_mut_list_by_val_with_capacity_from_unmanaged_memory(uint64_t capacity) {
	struct mut_arr backing0;
	uint64_t* _0 = unmanaged_alloc_zeroed_elements(capacity);
	backing0 = mut_arr(capacity, _0);
	
	return (struct mut_list) {backing0, 0u};
}
/* mut-arr<?t> mut-arr<nat>(size nat, data ptr<nat>) */
struct mut_arr mut_arr(uint64_t size, uint64_t* data) {
	return (struct mut_arr) {(struct arr_2) {size, data}};
}
/* unmanaged-alloc-zeroed-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_zeroed_elements(uint64_t size_elements) {
	uint64_t* res0;
	res0 = unmanaged_alloc_elements_0(size_elements);
	
	set_zero_range(res0, size_elements);
	return res0;
}
/* unmanaged-alloc-elements<?t> ptr<nat>(size-elements nat) */
uint64_t* unmanaged_alloc_elements_0(uint64_t size_elements) {
	uint8_t* bytes0;
	bytes0 = unmanaged_alloc_bytes((size_elements * sizeof(uint64_t)));
	
	return (uint64_t*) bytes0;
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
	return hard_assert(!condition);
}
/* null?<nat8> bool(a ptr<nat8>) */
uint8_t null__q_0(uint8_t* a) {
	return _op_equal_equal_0((uint64_t) a, (uint64_t) NULL);
}
/* set-zero-range<?t> void(begin ptr<nat>, size nat) */
struct void_ set_zero_range(uint64_t* begin, uint64_t size) {
	return (memset((uint8_t*) begin, 0u, (size * sizeof(uint64_t))), (struct void_) {});
}
/* default-exception-handler void(e exception) */
struct void_ default_exception_handler(struct ctx* ctx, struct exception e) {
	print_err_no_newline((struct arr_0) {20, constantarr_0_2});
	uint8_t _0 = empty__q_0(e.message);struct arr_0 _1;
	
	if (_0) {
		_1 = (struct arr_0) {17, constantarr_0_4};
	} else {
		_1 = e.message;
	}
	print_err(_1);
	struct global_ctx* _2 = get_global_ctx(ctx);
	return (_2->any_unhandled_exceptions__q = 1, (struct void_) {});
}
/* print-err-no-newline void(s arr<char>) */
struct void_ print_err_no_newline(struct arr_0 s) {
	int32_t _0 = stderr();
	return write_no_newline(_0, s);
}
/* write-no-newline void(fd int32, a arr<char>) */
struct void_ write_no_newline(int32_t fd, struct arr_0 a) {
	uint8_t _0 = _op_equal_equal_0(sizeof(char), sizeof(uint8_t));
	hard_assert(_0);
	int64_t res0;
	res0 = write(fd, (uint8_t*) a.data, a.size);
	
	uint8_t _1 = _op_bang_equal_0(res0, (int64_t) a.size);
	if (_1) {
		return todo_0();
	} else {
		return (struct void_) {};
	}
}
/* !=<int> bool(a int, b int) */
uint8_t _op_bang_equal_0(int64_t a, int64_t b) {
	uint8_t _0 = _op_equal_equal_1(a, b);
	return !_0;
}
/* ==<?t> bool(a int, b int) */
uint8_t _op_equal_equal_1(int64_t a, int64_t b) {
	struct comparison _0 = compare_36(a, b);
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
			return (assert(0),0);
	}
}
/* compare<int-64> (generated) (generated) */
struct comparison compare_36(int64_t a, int64_t b) {
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
	return (assert(0),(struct void_) {});
}
/* stderr int32() */
int32_t stderr(void) {
	return 2;
}
/* print-err void(s arr<char>) */
struct void_ print_err(struct arr_0 s) {
	print_err_no_newline(s);
	return print_err_no_newline((struct arr_0) {1, constantarr_0_3});
}
/* empty?<char> bool(a arr<char>) */
uint8_t empty__q_0(struct arr_0 a) {
	return _op_equal_equal_0(a.size, 0u);
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
	struct arr_0 _1 = _op_plus_0(ctx, _0, (struct arr_0) {2, constantarr_0_8});
	struct arr_0 _2 = _op_plus_0(ctx, _1, a->message);
	return print(_2);
}
/* print void(a arr<char>) */
struct void_ print(struct arr_0 a) {
	print_no_newline(a);
	return print_no_newline((struct arr_0) {1, constantarr_0_3});
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
/* +<char> arr<char>(a arr<char>, b arr<char>) */
struct arr_0 _op_plus_0(struct ctx* ctx, struct arr_0 a, struct arr_0 b) {
	uint64_t res_size0;
	res_size0 = _op_plus_1(ctx, a.size, b.size);
	
	char* res1;
	res1 = uninitialized_data_0(ctx, res_size0);
	
	copy_data_from(ctx, res1, a.data, a.size);
	copy_data_from(ctx, (res1 + a.size), b.data, b.size);
	return (struct arr_0) {res_size0, res1};
}
/* + nat(a nat, b nat) */
uint64_t _op_plus_1(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint64_t res0;
	res0 = (a + b);
	
	uint8_t _0 = _op_greater_equal(res0, a);uint8_t _1;
	
	if (_0) {
		_1 = _op_greater_equal(res0, b);
	} else {
		_1 = 0;
	}
	assert_0(ctx, _1);
	return res0;
}
/* assert void(condition bool) */
struct void_ assert_0(struct ctx* ctx, uint8_t condition) {
	return assert_1(ctx, condition, (struct arr_0) {13, constantarr_0_5});
}
/* assert void(condition bool, message arr<char>) */
struct void_ assert_1(struct ctx* ctx, uint8_t condition, struct arr_0 message) {
	uint8_t _0 = !condition;
	if (_0) {
		return fail(ctx, message);
	} else {
		return (struct void_) {};
	}
}
/* fail<void> void(reason arr<char>) */
struct void_ fail(struct ctx* ctx, struct arr_0 reason) {
	return throw(ctx, (struct exception) {reason});
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
	return _op_equal_equal_0((uint64_t) a, (uint64_t) NULL);
}
/* number-to-throw int32() */
int32_t number_to_throw(struct ctx* ctx) {
	return 7;
}
/* >=<nat> bool(a nat, b nat) */
uint8_t _op_greater_equal(uint64_t a, uint64_t b) {
	uint8_t _0 = _op_less_0(a, b);
	return !_0;
}
/* uninitialized-data<?t> ptr<char>(size nat) */
char* uninitialized_data_0(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	bptr0 = alloc(ctx, (size * sizeof(char)));
	
	return (char*) bptr0;
}
/* alloc ptr<nat8>(size nat) */
uint8_t* alloc(struct ctx* ctx, uint64_t size) {
	struct gc* _0 = get_gc(ctx);
	return gc_alloc(ctx, _0, size);
}
/* gc-alloc ptr<nat8>(gc gc, size nat) */
uint8_t* gc_alloc(struct ctx* ctx, struct gc* gc, uint64_t size) {
	struct opt_3 _0 = try_gc_alloc(gc, size);
	switch (_0.kind) {
		case 0: {
			return todo_1();
		}
		case 1: {
			struct some_3 s0 = _0.as1;
			
			return s0.value;
		}
		default:
			return (assert(0),NULL);
	}
}
/* try-gc-alloc opt<ptr<nat8>>(gc gc, size-bytes nat) */
struct opt_3 try_gc_alloc(struct gc* gc, uint64_t size_bytes) {
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
			return (struct opt_3) {1, .as1 = (struct some_3) {(uint8_t*) cur1}};
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
		return (struct opt_3) {0, .as0 = (struct none) {}};
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
	mark_idx0 = _op_minus_1(gc->mark_cur, gc->mark_begin);
	
	uint64_t data_idx1;
	data_idx1 = _op_minus_0(gc->data_cur, gc->data_begin);
	
	uint64_t _4 = _op_minus_1(gc->mark_end, gc->mark_begin);
	uint8_t _5 = _op_equal_equal_0(_4, gc->size_words);
	hard_assert(_5);
	uint64_t _6 = _op_minus_0(gc->data_end, gc->data_begin);
	uint8_t _7 = _op_equal_equal_0(_6, gc->size_words);
	hard_assert(_7);
	uint8_t _8 = _op_equal_equal_0(mark_idx0, data_idx1);
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
uint64_t _op_minus_1(uint8_t* a, uint8_t* b) {
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
/* todo<ptr<nat8>> ptr<nat8>() */
uint8_t* todo_1(void) {
	return (assert(0),NULL);
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
/* copy-data-from<?t> void(to ptr<char>, from ptr<char>, len nat) */
struct void_ copy_data_from(struct ctx* ctx, char* to, char* from, uint64_t len) {
	return (memcpy((uint8_t*) to, (uint8_t*) from, (len * sizeof(char))), (struct void_) {});
}
/* to-str arr<char>(a log-level) */
struct arr_0 to_str_0(struct ctx* ctx, struct log_level a) {
	struct log_level _0 = a;
	switch (_0.kind) {
		case 0: {
			return (struct arr_0) {4, constantarr_0_6};
		}
		case 1: {
			return (struct arr_0) {4, constantarr_0_7};
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
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
/* do-main fut<int32>(gctx global-ctx, island island, argc int32, argv ptr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
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
	
	struct fun2 add5;
	add5 = (struct fun2) {0, .as0 = (struct void_) {}};
	
	struct arr_4 all_args6;
	all_args6 = (struct arr_4) {(uint64_t) (int64_t) argc, argv};
	
	return call_w_ctx_187(add5, ctx4, all_args6, main_ptr);
}
/* new-exception-ctx exception-ctx() */
struct exception_ctx new_exception_ctx(void) {
	return (struct exception_ctx) {NULL, (struct exception) {(struct arr_0) {0u, NULL}}};
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
			(assert(0),NULL);
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
	uint8_t _1 = !_0;
	if (_1) {
		uint8_t _2 = _op_equal_equal_0(n_tries, 1000u);
		if (_2) {
			return (assert(0),(struct void_) {});
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
	uint8_t _2 = !old_value;
	return atomic_compare_exchange_strong(_0, _1, _2);
}
/* yield-thread void() */
struct void_ yield_thread(void) {
	int32_t err0;
	err0 = pthread_yield();
	
	uint8_t _0 = _op_equal_equal_2(err0, 0);
	return hard_assert(_0);
}
/* ==<int32> bool(a int32, b int32) */
uint8_t _op_equal_equal_2(int32_t a, int32_t b) {
	struct comparison _0 = compare_91(a, b);
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
			return (assert(0),0);
	}
}
/* compare<int-32> (generated) (generated) */
struct comparison compare_91(int32_t a, int32_t b) {
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
/* noctx-incr nat(n nat) */
uint64_t noctx_incr(uint64_t n) {
	uint64_t _0 = max_nat();
	uint8_t _1 = _op_less_0(n, _0);
	hard_assert(_1);
	return wrap_incr(n);
}
/* max-nat nat() */
uint64_t max_nat(void) {
	return 18446744073709551615u;
}
/* wrap-incr nat(a nat) */
uint64_t wrap_incr(uint64_t a) {
	return (a + 1u);
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
/* add-first-task fut<int32>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
struct fut_0* add_first_task(struct ctx* ctx, struct arr_4 all_args, fun_ptr2 main_ptr) {
	struct fut_1* _0 = delay(ctx);
	struct island_and_exclusion _1 = cur_island_and_exclusion(ctx);
	struct add_first_task__lambda0* temp0;
	uint8_t* _2 = alloc(ctx, sizeof(struct add_first_task__lambda0));
	temp0 = (struct add_first_task__lambda0*) _2;
	
	*temp0 = (struct add_first_task__lambda0) {all_args, main_ptr};
	return then2(ctx, _0, (struct fun_ref0) {_1, (struct fun_act0_1) {0, .as0 = temp0}});
}
/* then2<int32> fut<int32>(f fut<void>, cb fun-ref0<int32>) */
struct fut_0* then2(struct ctx* ctx, struct fut_1* f, struct fun_ref0 cb) {
	struct island_and_exclusion _0 = cur_island_and_exclusion(ctx);
	struct then2__lambda0* temp0;
	uint8_t* _1 = alloc(ctx, sizeof(struct then2__lambda0));
	temp0 = (struct then2__lambda0*) _1;
	
	*temp0 = (struct then2__lambda0) {cb};
	return then(ctx, f, (struct fun_ref1) {_0, (struct fun_act1_2) {0, .as0 = temp0}});
}
/* then<?out, void> fut<int32>(f fut<void>, cb fun-ref1<int32, void>) */
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
/* new-unresolved-fut<?out> fut<int32>() */
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
			f->state = (struct fut_state_1) {0, .as0 = (struct fut_state_callbacks_1) {(struct opt_4) {1, .as1 = (struct some_4) {temp0}}}};
			break;
		}
		case 1: {
			struct fut_state_resolved_1 r1 = _0.as1;
			
			call_0(ctx, cb, (struct result_1) {0, .as0 = (struct ok_1) {r1.value}});
			break;
		}
		case 2: {
			struct exception e2 = _0.as2;
			
			call_0(ctx, cb, (struct result_1) {1, .as1 = (struct err) {e2}});
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	return release_lock((&f->lk));
}
/* call<void, result<?t, exception>> void(a fun-act1<void, result<void, exception>>, p0 result<void, exception>) */
struct void_ call_0(struct ctx* ctx, struct fun_act1_1 a, struct result_1 p0) {
	return call_w_ctx_104(a, ctx, p0);
}
/* call-w-ctx<void, result<void, exception>> (generated) (generated) */
struct void_ call_w_ctx_104(struct fun_act1_1 a, struct ctx* ctx, struct result_1 p0) {
	struct fun_act1_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then__lambda0* closure0 = _0.as0;
			
			return then__lambda0(ctx, closure0, p0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* forward-to<?out> void(from fut<int32>, to fut<int32>) */
struct void_ forward_to(struct ctx* ctx, struct fut_0* from, struct fut_0* to) {
	struct forward_to__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct forward_to__lambda0));
	temp0 = (struct forward_to__lambda0*) _0;
	
	*temp0 = (struct forward_to__lambda0) {to};
	return then_void_1(ctx, from, (struct fun_act1_0) {0, .as0 = temp0});
}
/* then-void<?t> void(f fut<int32>, cb fun-act1<void, result<int32, exception>>) */
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
			
			call_1(ctx, cb, (struct result_0) {0, .as0 = (struct ok_0) {r1.value}});
			break;
		}
		case 2: {
			struct exception e2 = _0.as2;
			
			call_1(ctx, cb, (struct result_0) {1, .as1 = (struct err) {e2}});
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	return release_lock((&f->lk));
}
/* call<void, result<?t, exception>> void(a fun-act1<void, result<int32, exception>>, p0 result<int32, exception>) */
struct void_ call_1(struct ctx* ctx, struct fun_act1_0 a, struct result_0 p0) {
	return call_w_ctx_108(a, ctx, p0);
}
/* call-w-ctx<void, result<int32, exception>> (generated) (generated) */
struct void_ call_w_ctx_108(struct fun_act1_0 a, struct ctx* ctx, struct result_0 p0) {
	struct fun_act1_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* closure0 = _0.as0;
			
			return forward_to__lambda0(ctx, closure0, p0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* resolve-or-reject<?t> void(f fut<int32>, result result<int32, exception>) */
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
			(assert(0),(struct fut_state_0) {0});
	}
	f->state = _2;
	return release_lock((&f->lk));
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
			
			struct void_ _1 = call_1(ctx, s0.value->cb, value);
			drop_0(_1);
			node = s0.value->next_node;
			value = value;
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
	return resolve_or_reject(ctx, _closure->to, it);
}
/* call-ref<?out, ?in> fut<int32>(f fun-ref1<int32, void>, p0 void) */
struct fut_0* call_ref_0(struct ctx* ctx, struct fun_ref1 f, struct void_ p0) {
	struct island* island0;
	island0 = get_island(ctx, f.island_and_exclusion.island);
	
	struct fut_0* res1;
	res1 = new_unresolved_fut(ctx);
	
	struct call_ref_0__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct call_ref_0__lambda0));
	temp0 = (struct call_ref_0__lambda0*) _0;
	
	*temp0 = (struct call_ref_0__lambda0) {f, p0, res1};
	add_task_0(ctx, island0, f.island_and_exclusion.exclusion, (struct fun_act0_0) {1, .as1 = temp0});
	return res1;
}
/* get-island island(island-id nat) */
struct island* get_island(struct ctx* ctx, uint64_t island_id) {
	struct global_ctx* _0 = get_global_ctx(ctx);
	return at_0(ctx, _0->islands, island_id);
}
/* at<island> island(a arr<island>, index nat) */
struct island* at_0(struct ctx* ctx, struct arr_3 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	assert_0(ctx, _0);
	return noctx_at_0(a, index);
}
/* noctx-at<?t> island(a arr<island>, index nat) */
struct island* noctx_at_0(struct arr_3 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
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
			
			uint8_t _1 = _op_less_equal(head2->task.time, inserted->task.time);
			if (_1) {
				insert_recur(head2, inserted);
			} else {
				inserted->next = (struct opt_2) {1, .as1 = (struct some_2) {head2}};
				a->head = (struct opt_2) {1, .as1 = (struct some_2) {inserted}};
			}
			break;
		}
		default:
			(assert(0),(struct void_) {});
	}
	uint64_t size_after3;
	size_after3 = size_0(a);
	
	uint8_t _2 = _op_equal_equal_0((size_before0 + 1u), size_after3);
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
			return (assert(0),0);
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
			
			uint8_t _1 = _op_less_equal(cur1->task.time, inserted->task.time);
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
			return (assert(0),(struct void_) {});
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
	
	uint8_t _2 = _op_equal_equal_2(setjmp_result3, 0);
	if (_2) {
		struct void_ res4;
		res4 = call_2(ctx, try);
		
		ec->jmp_buf_ptr = old_jmp_buf1;
		ec->thrown_exception = old_thrown_exception0;
		return res4;
	} else {
		int32_t _3 = number_to_throw(ctx);
		uint8_t _4 = _op_equal_equal_2(setjmp_result3, _3);
		assert_0(ctx, _4);
		struct exception thrown_exception5;
		thrown_exception5 = ec->thrown_exception;
		
		ec->jmp_buf_ptr = old_jmp_buf1;
		ec->thrown_exception = old_thrown_exception0;
		return call_3(ctx, catcher, thrown_exception5);
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
/* call<?t> void(a fun-act0<void>) */
struct void_ call_2(struct ctx* ctx, struct fun_act0_0 a) {
	return call_w_ctx_135(a, ctx);
}
/* call-w-ctx<void> (generated) (generated) */
struct void_ call_w_ctx_135(struct fun_act0_0 a, struct ctx* ctx) {
	struct fun_act0_0 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda0* closure0 = _0.as0;
			
			return call_ref_0__lambda0__lambda0(ctx, closure0);
		}
		case 1: {
			struct call_ref_0__lambda0* closure1 = _0.as1;
			
			return call_ref_0__lambda0(ctx, closure1);
		}
		case 2: {
			struct call_ref_1__lambda0__lambda0* closure2 = _0.as2;
			
			return call_ref_1__lambda0__lambda0(ctx, closure2);
		}
		case 3: {
			struct call_ref_1__lambda0* closure3 = _0.as3;
			
			return call_ref_1__lambda0(ctx, closure3);
		}
		case 4: {
			struct main_0__lambda0* closure4 = _0.as4;
			
			return main_0__lambda0(ctx, closure4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call<?t, exception> void(a fun-act1<void, exception>, p0 exception) */
struct void_ call_3(struct ctx* ctx, struct fun_act1_3 a, struct exception p0) {
	return call_w_ctx_137(a, ctx, p0);
}
/* call-w-ctx<void, exception> (generated) (generated) */
struct void_ call_w_ctx_137(struct fun_act1_3 a, struct ctx* ctx, struct exception p0) {
	struct fun_act1_3 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda1* closure0 = _0.as0;
			
			return call_ref_0__lambda0__lambda1(ctx, closure0, p0);
		}
		case 1: {
			struct call_ref_1__lambda0__lambda1* closure1 = _0.as1;
			
			return call_ref_1__lambda0__lambda1(ctx, closure1, p0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call<fut<?r>, ?p0> fut<int32>(a fun-act1<fut<int32>, void>, p0 void) */
struct fut_0* call_4(struct ctx* ctx, struct fun_act1_2 a, struct void_ p0) {
	return call_w_ctx_139(a, ctx, p0);
}
/* call-w-ctx<gc-ptr(fut<int32>), void> (generated) (generated) */
struct fut_0* call_w_ctx_139(struct fun_act1_2 a, struct ctx* ctx, struct void_ p0) {
	struct fun_act1_2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* closure0 = _0.as0;
			
			return then2__lambda0(ctx, closure0, p0);
		}
		default:
			return (assert(0),NULL);
	}
}
/* call-ref<?out, ?in>.lambda0.lambda0 void() */
struct void_ call_ref_0__lambda0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0__lambda0* _closure) {
	struct fut_0* _0 = call_4(ctx, _closure->f.fun, _closure->p0);
	return forward_to(ctx, _0, _closure->res);
}
/* reject<?r> void(f fut<int32>, e exception) */
struct void_ reject(struct ctx* ctx, struct fut_0* f, struct exception e) {
	return resolve_or_reject(ctx, f, (struct result_0) {1, .as1 = (struct err) {e}});
}
/* call-ref<?out, ?in>.lambda0.lambda1 void(it exception) */
struct void_ call_ref_0__lambda0__lambda1(struct ctx* ctx, struct call_ref_0__lambda0__lambda1* _closure, struct exception it) {
	return reject(ctx, _closure->res, it);
}
/* call-ref<?out, ?in>.lambda0 void() */
struct void_ call_ref_0__lambda0(struct ctx* ctx, struct call_ref_0__lambda0* _closure) {
	struct call_ref_0__lambda0__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct call_ref_0__lambda0__lambda0));
	temp0 = (struct call_ref_0__lambda0__lambda0*) _0;
	
	*temp0 = (struct call_ref_0__lambda0__lambda0) {_closure->f, _closure->p0, _closure->res};
	struct call_ref_0__lambda0__lambda1* temp1;
	uint8_t* _1 = alloc(ctx, sizeof(struct call_ref_0__lambda0__lambda1));
	temp1 = (struct call_ref_0__lambda0__lambda1*) _1;
	
	*temp1 = (struct call_ref_0__lambda0__lambda1) {_closure->res};
	return catch(ctx, (struct fun_act0_0) {0, .as0 = temp0}, (struct fun_act1_3) {0, .as0 = temp1});
}
/* then<?out, void>.lambda0 void(result result<void, exception>) */
struct void_ then__lambda0(struct ctx* ctx, struct then__lambda0* _closure, struct result_1 result) {
	struct result_1 _0 = result;
	switch (_0.kind) {
		case 0: {
			struct ok_1 o0 = _0.as0;
			
			struct fut_0* _1 = call_ref_0(ctx, _closure->cb, o0.value);
			return forward_to(ctx, _1, _closure->res);
		}
		case 1: {
			struct err e1 = _0.as1;
			
			return reject(ctx, _closure->res, e1.value);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* call-ref<?out> fut<int32>(f fun-ref0<int32>) */
struct fut_0* call_ref_1(struct ctx* ctx, struct fun_ref0 f) {
	struct fut_0* res0;
	res0 = new_unresolved_fut(ctx);
	
	struct island* _0 = get_island(ctx, f.island_and_exclusion.island);
	struct call_ref_1__lambda0* temp0;
	uint8_t* _1 = alloc(ctx, sizeof(struct call_ref_1__lambda0));
	temp0 = (struct call_ref_1__lambda0*) _1;
	
	*temp0 = (struct call_ref_1__lambda0) {f, res0};
	add_task_0(ctx, _0, f.island_and_exclusion.exclusion, (struct fun_act0_0) {3, .as3 = temp0});
	return res0;
}
/* call<fut<?r>> fut<int32>(a fun-act0<fut<int32>>) */
struct fut_0* call_5(struct ctx* ctx, struct fun_act0_1 a) {
	return call_w_ctx_147(a, ctx);
}
/* call-w-ctx<gc-ptr(fut<int32>)> (generated) (generated) */
struct fut_0* call_w_ctx_147(struct fun_act0_1 a, struct ctx* ctx) {
	struct fun_act0_1 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* closure0 = _0.as0;
			
			return add_first_task__lambda0(ctx, closure0);
		}
		default:
			return (assert(0),NULL);
	}
}
/* call-ref<?out>.lambda0.lambda0 void() */
struct void_ call_ref_1__lambda0__lambda0(struct ctx* ctx, struct call_ref_1__lambda0__lambda0* _closure) {
	struct fut_0* _0 = call_5(ctx, _closure->f.fun);
	return forward_to(ctx, _0, _closure->res);
}
/* call-ref<?out>.lambda0.lambda1 void(it exception) */
struct void_ call_ref_1__lambda0__lambda1(struct ctx* ctx, struct call_ref_1__lambda0__lambda1* _closure, struct exception it) {
	return reject(ctx, _closure->res, it);
}
/* call-ref<?out>.lambda0 void() */
struct void_ call_ref_1__lambda0(struct ctx* ctx, struct call_ref_1__lambda0* _closure) {
	struct call_ref_1__lambda0__lambda0* temp0;
	uint8_t* _0 = alloc(ctx, sizeof(struct call_ref_1__lambda0__lambda0));
	temp0 = (struct call_ref_1__lambda0__lambda0*) _0;
	
	*temp0 = (struct call_ref_1__lambda0__lambda0) {_closure->f, _closure->res};
	struct call_ref_1__lambda0__lambda1* temp1;
	uint8_t* _1 = alloc(ctx, sizeof(struct call_ref_1__lambda0__lambda1));
	temp1 = (struct call_ref_1__lambda0__lambda1*) _1;
	
	*temp1 = (struct call_ref_1__lambda0__lambda1) {_closure->res};
	return catch(ctx, (struct fun_act0_0) {2, .as2 = temp0}, (struct fun_act1_3) {1, .as1 = temp1});
}
/* then2<int32>.lambda0 fut<int32>(ignore void) */
struct fut_0* then2__lambda0(struct ctx* ctx, struct then2__lambda0* _closure, struct void_ ignore) {
	return call_ref_1(ctx, _closure->cb);
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
struct arr_4 tail(struct ctx* ctx, struct arr_4 a) {
	uint8_t _0 = empty__q_1(a);
	forbid_0(ctx, _0);
	return slice_starting_at(ctx, a, 1u);
}
/* forbid void(condition bool) */
struct void_ forbid_0(struct ctx* ctx, uint8_t condition) {
	return forbid_1(ctx, condition, (struct arr_0) {13, constantarr_0_11});
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
/* empty?<?t> bool(a arr<ptr<char>>) */
uint8_t empty__q_1(struct arr_4 a) {
	return _op_equal_equal_0(a.size, 0u);
}
/* slice-starting-at<?t> arr<ptr<char>>(a arr<ptr<char>>, begin nat) */
struct arr_4 slice_starting_at(struct ctx* ctx, struct arr_4 a, uint64_t begin) {
	uint8_t _0 = _op_less_equal(begin, a.size);
	assert_0(ctx, _0);
	uint64_t _1 = _op_minus_2(ctx, a.size, begin);
	return slice(ctx, a, begin, _1);
}
/* slice<?t> arr<ptr<char>>(a arr<ptr<char>>, begin nat, size nat) */
struct arr_4 slice(struct ctx* ctx, struct arr_4 a, uint64_t begin, uint64_t size) {
	uint64_t _0 = _op_plus_1(ctx, begin, size);
	uint8_t _1 = _op_less_equal(_0, a.size);
	assert_0(ctx, _1);
	return (struct arr_4) {size, (a.data + begin)};
}
/* - nat(a nat, b nat) */
uint64_t _op_minus_2(struct ctx* ctx, uint64_t a, uint64_t b) {
	uint8_t _0 = _op_greater_equal(a, b);
	assert_0(ctx, _0);
	return (a - b);
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
	data0 = uninitialized_data_1(ctx, size);
	
	fill_ptr_range(ctx, data0, size, f);
	return (struct arr_1) {size, data0};
}
/* uninitialized-data<?t> ptr<arr<char>>(size nat) */
struct arr_0* uninitialized_data_1(struct ctx* ctx, uint64_t size) {
	uint8_t* bptr0;
	bptr0 = alloc(ctx, (size * sizeof(struct arr_0)));
	
	return (struct arr_0*) bptr0;
}
/* fill-ptr-range<?t> void(begin ptr<arr<char>>, size nat, f fun-act1<arr<char>, nat>) */
struct void_ fill_ptr_range(struct ctx* ctx, struct arr_0* begin, uint64_t size, struct fun_act1_5 f) {
	return fill_ptr_range_recur(ctx, begin, 0u, size, f);
}
/* fill-ptr-range-recur<?t> void(begin ptr<arr<char>>, i nat, size nat, f fun-act1<arr<char>, nat>) */
struct void_ fill_ptr_range_recur(struct ctx* ctx, struct arr_0* begin, uint64_t i, uint64_t size, struct fun_act1_5 f) {
	top:;
	uint8_t _0 = _op_bang_equal_1(i, size);
	if (_0) {
		struct arr_0 _1 = call_6(ctx, f, i);
		*(begin + i) = _1;
		uint64_t _2 = wrap_incr(i);
		begin = begin;
		i = _2;
		size = size;
		f = f;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* !=<nat> bool(a nat, b nat) */
uint8_t _op_bang_equal_1(uint64_t a, uint64_t b) {
	uint8_t _0 = _op_equal_equal_0(a, b);
	return !_0;
}
/* call<?t, nat> arr<char>(a fun-act1<arr<char>, nat>, p0 nat) */
struct arr_0 call_6(struct ctx* ctx, struct fun_act1_5 a, uint64_t p0) {
	return call_w_ctx_169(a, ctx, p0);
}
/* call-w-ctx<arr<char>, nat-64> (generated) (generated) */
struct arr_0 call_w_ctx_169(struct fun_act1_5 a, struct ctx* ctx, uint64_t p0) {
	struct fun_act1_5 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct map__lambda0* closure0 = _0.as0;
			
			return map__lambda0(ctx, closure0, p0);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* call<?out, ?in> arr<char>(a fun-act1<arr<char>, ptr<char>>, p0 ptr<char>) */
struct arr_0 call_7(struct ctx* ctx, struct fun_act1_4 a, char* p0) {
	return call_w_ctx_171(a, ctx, p0);
}
/* call-w-ctx<arr<char>, raw-ptr(char)> (generated) (generated) */
struct arr_0 call_w_ctx_171(struct fun_act1_4 a, struct ctx* ctx, char* p0) {
	struct fun_act1_4 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			return add_first_task__lambda0__lambda0(ctx, closure0, p0);
		}
		default:
			return (assert(0),(struct arr_0) {0, NULL});
	}
}
/* at<?in> ptr<char>(a arr<ptr<char>>, index nat) */
char* at_1(struct ctx* ctx, struct arr_4 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	assert_0(ctx, _0);
	return noctx_at_1(a, index);
}
/* noctx-at<?t> ptr<char>(a arr<ptr<char>>, index nat) */
char* noctx_at_1(struct arr_4 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* map<arr<char>, ptr<char>>.lambda0 arr<char>(i nat) */
struct arr_0 map__lambda0(struct ctx* ctx, struct map__lambda0* _closure, uint64_t i) {
	char* _0 = at_1(ctx, _closure->a, i);
	return call_7(ctx, _closure->mapper, _0);
}
/* to-str arr<char>(a ptr<char>) */
struct arr_0 to_str_1(char* a) {
	char* _0 = find_cstr_end(a);
	return arr_from_begin_end(a, _0);
}
/* arr-from-begin-end<char> arr<char>(begin ptr<char>, end ptr<char>) */
struct arr_0 arr_from_begin_end(char* begin, char* end) {
	uint64_t _0 = _op_minus_3(end, begin);
	return (struct arr_0) {_0, begin};
}
/* -<?t> nat(a ptr<char>, b ptr<char>) */
uint64_t _op_minus_3(char* a, char* b) {
	return (((uint64_t) a - (uint64_t) b) / sizeof(char));
}
/* find-cstr-end ptr<char>(a ptr<char>) */
char* find_cstr_end(char* a) {
	return find_char_in_cstr(a, 0u);
}
/* find-char-in-cstr ptr<char>(a ptr<char>, c char) */
char* find_char_in_cstr(char* a, char c) {
	top:;
	uint8_t _0 = _op_equal_equal_3(*a, c);
	if (_0) {
		return a;
	} else {
		uint8_t _1 = _op_equal_equal_3(*a, 0u);
		if (_1) {
			return todo_2();
		} else {
			char* _2 = incr_2(a);
			a = _2;
			c = c;
			goto top;
		}
	}
}
/* ==<char> bool(a char, b char) */
uint8_t _op_equal_equal_3(char a, char b) {
	struct comparison _0 = compare_181(a, b);
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
			return (assert(0),0);
	}
}
/* compare<char> (generated) (generated) */
struct comparison compare_181(char a, char b) {
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
	return (assert(0),NULL);
}
/* incr<char> ptr<char>(p ptr<char>) */
char* incr_2(char* p) {
	return (p + 1u);
}
/* add-first-task.lambda0.lambda0 arr<char>(it ptr<char>) */
struct arr_0 add_first_task__lambda0__lambda0(struct ctx* ctx, struct void_ _closure, char* it) {
	return to_str_1(it);
}
/* add-first-task.lambda0 fut<int32>() */
struct fut_0* add_first_task__lambda0(struct ctx* ctx, struct add_first_task__lambda0* _closure) {
	struct arr_4 args0;
	args0 = tail(ctx, _closure->all_args);
	
	struct arr_1 _0 = map(ctx, args0, (struct fun_act1_4) {0, .as0 = (struct void_) {}});
	return _closure->main_ptr(ctx, _0);
}
/* do-main.lambda0 fut<int32>(all-args arr<ptr<char>>, main-ptr fun-ptr2<fut<int32>, ctx, arr<arr<char>>>) */
struct fut_0* do_main__lambda0(struct ctx* ctx, struct void_ _closure, struct arr_4 all_args, fun_ptr2 main_ptr) {
	return add_first_task(ctx, all_args, main_ptr);
}
/* call-w-ctx<gc-ptr(fut<int32>), arr<ptr<char>>, some fun ptr type> (generated) (generated) */
struct fut_0* call_w_ctx_187(struct fun2 a, struct ctx* ctx, struct arr_4 p0, fun_ptr2 p1) {
	struct fun2 _0 = a;
	switch (_0.kind) {
		case 0: {
			struct void_ closure0 = _0.as0;
			
			return do_main__lambda0(ctx, closure0, p0, p1);
		}
		default:
			return (assert(0),NULL);
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
	uint8_t* bytes0;
	bytes0 = unmanaged_alloc_bytes((size_elements * sizeof(struct thread_args)));
	
	return (struct thread_args*) bytes0;
}
/* noctx-decr nat(n nat) */
uint64_t noctx_decr(uint64_t n) {
	uint8_t _0 = _op_equal_equal_0(n, 0u);
	hard_forbid(_0);
	return (n - 1u);
}
/* start-threads-recur void(i nat, n-threads nat, threads ptr<nat>, thread-args-begin ptr<thread-args>, gctx global-ctx) */
struct void_ start_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads, struct thread_args* thread_args_begin, struct global_ctx* gctx) {
	top:;
	uint8_t _0 = _op_bang_equal_1(i, n_threads);
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
	
	uint8_t _0 = _op_bang_equal_2(err0, 0);
	if (_0) {
		int32_t _1 = eagain();
		uint8_t _2 = _op_equal_equal_2(err0, _1);
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
uint8_t _op_bang_equal_2(int32_t a, int32_t b) {
	uint8_t _0 = _op_equal_equal_2(a, b);
	return !_0;
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
		uint8_t _2 = _op_greater(gctx->n_live_threads, 0u);
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
				(assert(0),(struct void_) {});
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
	uint8_t _0 = _op_bang_equal_1(i, islands.size);
	if (_0) {
		struct island* island0;
		island0 = noctx_at_0(islands, i);
		
		acquire_lock((&island0->tasks_lock));
		hard_forbid((&island0->gc)->needs_gc__q);
		uint8_t _1 = _op_equal_equal_0(island0->n_threads_running, 0u);
		hard_assert(_1);
		struct task_queue* _2 = tasks(island0);
		uint8_t _3 = empty__q_2(_2);
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
uint8_t empty__q_2(struct task_queue* a) {
	uint8_t _0 = has__q(a->head);
	return !_0;
}
/* has?<task-queue-node> bool(a opt<task-queue-node>) */
uint8_t has__q(struct opt_2 a) {
	uint8_t _0 = empty__q_3(a);
	return !_0;
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
	return c->value;
}
/* choose-task choose-task-result(gctx global-ctx) */
struct choose_task_result choose_task(struct global_ctx* gctx) {
	acquire_lock((&gctx->lk));
	uint64_t cur_time0;
	cur_time0 = get_monotime_nsec();
	
	struct choose_task_result res4;
	struct choose_task_result _0 = choose_task_recur(gctx->islands, 0u, cur_time0, 0, (struct opt_5) {0, .as0 = (struct none) {}});
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
				no_task_and_last_thread_out__q3 = _op_equal_equal_0(gctx->n_live_threads, 0u);
			} else {
				no_task_and_last_thread_out__q3 = 0;
			}
			
			res4 = (struct choose_task_result) {1, .as1 = (struct no_chosen_task) {no_task_and_last_thread_out__q3, n2.first_task_time}};
			break;
		}
		default:
			(assert(0),(struct choose_task_result) {0});
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
	
	uint8_t _1 = _op_equal_equal_2(err1, 0);
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
	return (assert(0),0);
}
/* choose-task-recur choose-task-result(islands arr<island>, i nat, cur-time nat, any-tasks? bool, first-task-time opt<nat>) */
struct choose_task_result choose_task_recur(struct arr_3 islands, uint64_t i, uint64_t cur_time, uint8_t any_tasks__q, struct opt_5 first_task_time) {
	top:;
	uint8_t _0 = _op_equal_equal_0(i, islands.size);
	if (_0) {
		return (struct choose_task_result) {1, .as1 = (struct no_chosen_task) {!any_tasks__q, first_task_time}};
	} else {
		struct island* island0;
		island0 = noctx_at_0(islands, i);
		
		struct choose_task_in_island_result _1 = choose_task_in_island(island0, cur_time);
		switch (_1.kind) {
			case 0: {
				struct task t1 = _1.as0;
				
				return (struct choose_task_result) {0, .as0 = (struct chosen_task) {island0, (struct task_or_gc) {0, .as0 = t1}}};
			}
			case 1: {
				struct do_a_gc g2 = _1.as1;
				
				return (struct choose_task_result) {0, .as0 = (struct chosen_task) {island0, (struct task_or_gc) {1, .as1 = g2}}};
			}
			case 2: {
				struct no_task n3 = _1.as2;
				
				uint8_t new_any_tasks__q4;
				if (any_tasks__q) {
					new_any_tasks__q4 = 1;
				} else {
					new_any_tasks__q4 = n3.any_tasks__q;
				}
				
				struct opt_5 new_first_task_time5;
				new_first_task_time5 = min_time(first_task_time, n3.first_task_time);
				
				uint64_t _2 = noctx_incr(i);
				islands = islands;
				i = _2;
				cur_time = cur_time;
				any_tasks__q = new_any_tasks__q4;
				first_task_time = new_first_task_time5;
				goto top;
			}
			default:
				return (assert(0),(struct choose_task_result) {0});
		}
	}
}
/* choose-task-in-island choose-task-in-island-result(island island, cur-time nat) */
struct choose_task_in_island_result choose_task_in_island(struct island* island, uint64_t cur_time) {
	acquire_lock((&island->tasks_lock));
	struct choose_task_in_island_result res2;
	uint8_t _0 = (&island->gc)->needs_gc__q;
	if (_0) {
		uint8_t _1 = _op_equal_equal_0(island->n_threads_running, 0u);
		if (_1) {
			res2 = (struct choose_task_in_island_result) {1, .as1 = (struct do_a_gc) {}};
		} else {
			res2 = (struct choose_task_in_island_result) {2, .as2 = (struct no_task) {1, (struct opt_5) {0, .as0 = (struct none) {}}}};
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
				(assert(0),(struct choose_task_in_island_result) {0});
		}
	}
	
	uint8_t _4 = is_no_task__q(res2);
	uint8_t _5 = !_4;
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
	struct mut_list* exclusions0;
	exclusions0 = (&a->currently_running_exclusions);
	
	struct pop_task_result res4;
	struct opt_2 _0 = a->head;
	switch (_0.kind) {
		case 0: {
			res4 = (struct pop_task_result) {1, .as1 = (struct no_task) {0, (struct opt_5) {0, .as0 = (struct none) {}}}};
			break;
		}
		case 1: {
			struct some_2 s1 = _0.as1;
			
			struct task_queue_node* head2;
			head2 = s1.value;
			
			struct task task3;
			task3 = head2->task;
			
			uint8_t _1 = _op_less_equal(task3.time, cur_time);
			if (_1) {
				uint8_t _2 = contains__q_0(exclusions0, task3.exclusion);
				if (_2) {
					struct opt_5 _3 = to_opt_time(task3.time);
					res4 = pop_recur(head2, exclusions0, cur_time, _3);
				} else {
					a->head = head2->next;
					res4 = (struct pop_task_result) {0, .as0 = head2->task};
				}
			} else {
				res4 = (struct pop_task_result) {1, .as1 = (struct no_task) {1, (struct opt_5) {1, .as1 = (struct some_5) {task3.time}}}};
			}
			break;
		}
		default:
			(assert(0),(struct pop_task_result) {0});
	}
	
	struct pop_task_result _4 = res4;
	switch (_4.kind) {
		case 0: {
			struct task t5 = _4.as0;
			
			push_capacity_must_be_sufficient(exclusions0, t5.exclusion);
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
uint8_t contains__q_0(struct mut_list* a, uint64_t value) {
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
	uint8_t _0 = _op_equal_equal_0(i, a.size);
	if (_0) {
		return 0;
	} else {
		uint64_t _1 = noctx_at_2(a, i);
		uint8_t _2 = _op_equal_equal_0(_1, value);
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
uint64_t noctx_at_2(struct arr_2 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* temp-as-arr<?t> arr<nat>(a mut-list<nat>) */
struct arr_2 temp_as_arr_0(struct mut_list* a) {
	struct mut_arr _0 = temp_as_mut_arr(a);
	return temp_as_arr_1(_0);
}
/* temp-as-arr<?t> arr<nat>(a mut-arr<nat>) */
struct arr_2 temp_as_arr_1(struct mut_arr a) {
	return a.arr;
}
/* temp-as-mut-arr<?t> mut-arr<nat>(a mut-list<nat>) */
struct mut_arr temp_as_mut_arr(struct mut_list* a) {
	uint64_t* _0 = data_0(a);
	return (struct mut_arr) {(struct arr_2) {a->size, _0}};
}
/* data<?t> ptr<nat>(a mut-list<nat>) */
uint64_t* data_0(struct mut_list* a) {
	return data_1(a->backing);
}
/* data<?t> ptr<nat>(a mut-arr<nat>) */
uint64_t* data_1(struct mut_arr a) {
	return a.arr.data;
}
/* pop-recur pop-task-result(prev task-queue-node, exclusions mut-list<nat>, cur-time nat, first-task-time opt<nat>) */
struct pop_task_result pop_recur(struct task_queue_node* prev, struct mut_list* exclusions, uint64_t cur_time, struct opt_5 first_task_time) {
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
			
			uint8_t _1 = _op_less_equal(task2.time, cur_time);
			if (_1) {
				uint8_t _2 = contains__q_0(exclusions, task2.exclusion);
				if (_2) {
					struct opt_5 _3 = first_task_time;struct opt_5 _4;
					
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
							(assert(0),(struct opt_5) {0});
					}
					prev = cur1;
					exclusions = exclusions;
					cur_time = cur_time;
					first_task_time = _4;
					goto top;
				} else {
					prev->next = cur1->next;
					push_capacity_must_be_sufficient(exclusions, task2.exclusion);
					return (struct pop_task_result) {0, .as0 = task2};
				}
			} else {
				return (struct pop_task_result) {1, .as1 = (struct no_task) {1, (struct opt_5) {1, .as1 = (struct some_5) {task2.time}}}};
			}
		}
		default:
			return (assert(0),(struct pop_task_result) {0});
	}
}
/* to-opt-time opt<nat>(a nat) */
struct opt_5 to_opt_time(uint64_t a) {
	uint64_t _0 = no_timestamp();
	uint8_t _1 = _op_equal_equal_0(a, _0);
	if (_1) {
		return (struct opt_5) {0, .as0 = (struct none) {}};
	} else {
		return (struct opt_5) {1, .as1 = (struct some_5) {a}};
	}
}
/* push-capacity-must-be-sufficient<nat> void(a mut-list<nat>, value nat) */
struct void_ push_capacity_must_be_sufficient(struct mut_list* a, uint64_t value) {
	uint64_t _0 = capacity(a);
	uint8_t _1 = _op_less_0(a->size, _0);
	hard_assert(_1);
	uint64_t old_size0;
	old_size0 = a->size;
	
	uint64_t _2 = noctx_incr(old_size0);
	a->size = _2;
	return noctx_set_at(a, old_size0, value);
}
/* capacity<?t> nat(a mut-list<nat>) */
uint64_t capacity(struct mut_list* a) {
	return size_1(a->backing);
}
/* size<?t> nat(a mut-arr<nat>) */
uint64_t size_1(struct mut_arr a) {
	return a.arr.size;
}
/* noctx-set-at<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_set_at(struct mut_list* a, uint64_t index, uint64_t value) {
	uint8_t _0 = _op_less_0(index, a->size);
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
					
					uint64_t _2 = min(sa0.value, sb1.value);
					return (struct opt_5) {1, .as1 = (struct some_5) {_2}};
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
	uint8_t _0 = _op_less_0(a, b);
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
			
			call_w_ctx_135(task1.action, (&ctx2));
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
			(assert(0),(struct void_) {});
	}
	acquire_lock((&island0->tasks_lock));
	uint64_t _2 = noctx_decr(island0->n_threads_running);
	island0->n_threads_running = _2;
	return release_lock((&island0->tasks_lock));
}
/* return-task void(a task-queue, task task) */
struct void_ return_task(struct task_queue* a, struct task task) {
	return noctx_must_remove_unordered((&a->currently_running_exclusions), task.exclusion);
}
/* noctx-must-remove-unordered<nat> void(a mut-list<nat>, value nat) */
struct void_ noctx_must_remove_unordered(struct mut_list* a, uint64_t value) {
	return noctx_must_remove_unordered_recur(a, 0u, value);
}
/* noctx-must-remove-unordered-recur<?t> void(a mut-list<nat>, index nat, value nat) */
struct void_ noctx_must_remove_unordered_recur(struct mut_list* a, uint64_t index, uint64_t value) {
	top:;
	uint8_t _0 = _op_equal_equal_0(index, a->size);
	if (_0) {
		return (assert(0),(struct void_) {});
	} else {
		uint64_t _1 = noctx_at_3(a, index);
		uint8_t _2 = _op_equal_equal_0(_1, value);
		if (_2) {
			uint64_t _3 = noctx_remove_unordered_at_index(a, index);
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
uint64_t noctx_at_3(struct mut_list* a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a->size);
	hard_assert(_0);
	uint64_t* _1 = data_0(a);
	return *(_1 + index);
}
/* drop<?t> void(_ nat) */
struct void_ drop_1(uint64_t _p0) {
	return (struct void_) {};
}
/* noctx-remove-unordered-at-index<?t> nat(a mut-list<nat>, index nat) */
uint64_t noctx_remove_unordered_at_index(struct mut_list* a, uint64_t index) {
	uint64_t res0;
	res0 = noctx_at_3(a, index);
	
	uint64_t _0 = noctx_last(a);
	noctx_set_at(a, index, _0);
	uint64_t _1 = noctx_decr(a->size);
	a->size = _1;
	return res0;
}
/* noctx-last<?t> nat(a mut-list<nat>) */
uint64_t noctx_last(struct mut_list* a) {
	uint8_t _0 = empty__q_4(a);
	hard_forbid(_0);
	uint64_t _1 = noctx_decr(a->size);
	return noctx_at_3(a, _1);
}
/* empty?<?t> bool(a mut-list<nat>) */
uint8_t empty__q_4(struct mut_list* a) {
	return _op_equal_equal_0(a->size, 0u);
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
	uint64_t _0 = wrap_incr(gc->gc_count);
	gc->gc_count = _0;
	(memset((uint8_t*) gc->mark_begin, 0u, gc->size_words), (struct void_) {});
	struct mark_ctx mark_ctx0;
	mark_ctx0 = (struct mark_ctx) {gc->size_words, gc->mark_begin, gc->data_begin};
	
	mark_visit_244((&mark_ctx0), gc_root);
	gc->mark_cur = gc->mark_begin;
	gc->data_cur = gc->data_begin;
	clear_free_mem(gc->mark_begin, gc->mark_end, gc->data_begin);
	return validate_gc(gc);
}
/* mark-visit<island-gc-root> (generated) (generated) */
struct void_ mark_visit_244(struct mark_ctx* mark_ctx, struct island_gc_root value) {
	return mark_visit_245(mark_ctx, value.tasks);
}
/* mark-visit<task-queue> (generated) (generated) */
struct void_ mark_visit_245(struct mark_ctx* mark_ctx, struct task_queue value) {
	mark_visit_246(mark_ctx, value.head);
	return mark_visit_283(mark_ctx, value.currently_running_exclusions);
}
/* mark-visit<opt<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_246(struct mark_ctx* mark_ctx, struct opt_2 value) {
	struct opt_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_2 value1 = _0.as1;
			
			return mark_visit_247(mark_ctx, value1);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<some<task-queue-node>> (generated) (generated) */
struct void_ mark_visit_247(struct mark_ctx* mark_ctx, struct some_2 value) {
	return mark_visit_282(mark_ctx, value.value);
}
/* mark-visit<task-queue-node> (generated) (generated) */
struct void_ mark_visit_248(struct mark_ctx* mark_ctx, struct task_queue_node value) {
	mark_visit_249(mark_ctx, value.task);
	return mark_visit_246(mark_ctx, value.next);
}
/* mark-visit<task> (generated) (generated) */
struct void_ mark_visit_249(struct mark_ctx* mark_ctx, struct task value) {
	return mark_visit_250(mark_ctx, value.action);
}
/* mark-visit<fun-act0<void>> (generated) (generated) */
struct void_ mark_visit_250(struct mark_ctx* mark_ctx, struct fun_act0_0 value) {
	struct fun_act0_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct call_ref_0__lambda0__lambda0* value0 = _0.as0;
			
			return mark_visit_274(mark_ctx, value0);
		}
		case 1: {
			struct call_ref_0__lambda0* value1 = _0.as1;
			
			return mark_visit_276(mark_ctx, value1);
		}
		case 2: {
			struct call_ref_1__lambda0__lambda0* value2 = _0.as2;
			
			return mark_visit_278(mark_ctx, value2);
		}
		case 3: {
			struct call_ref_1__lambda0* value3 = _0.as3;
			
			return mark_visit_280(mark_ctx, value3);
		}
		case 4: {
			struct main_0__lambda0* value4 = _0.as4;
			
			return mark_visit_281(mark_ctx, value4);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<call-ref<?out, ?in>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_251(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0 value) {
	mark_visit_252(mark_ctx, value.f);
	return mark_visit_269(mark_ctx, value.res);
}
/* mark-visit<fun-ref1<int32, void>> (generated) (generated) */
struct void_ mark_visit_252(struct mark_ctx* mark_ctx, struct fun_ref1 value) {
	return mark_visit_253(mark_ctx, value.fun);
}
/* mark-visit<fun-act1<fut<int32>, void>> (generated) (generated) */
struct void_ mark_visit_253(struct mark_ctx* mark_ctx, struct fun_act1_2 value) {
	struct fun_act1_2 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct then2__lambda0* value0 = _0.as0;
			
			return mark_visit_260(mark_ctx, value0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<then2<int32>.lambda0> (generated) (generated) */
struct void_ mark_visit_254(struct mark_ctx* mark_ctx, struct then2__lambda0 value) {
	return mark_visit_255(mark_ctx, value.cb);
}
/* mark-visit<fun-ref0<int32>> (generated) (generated) */
struct void_ mark_visit_255(struct mark_ctx* mark_ctx, struct fun_ref0 value) {
	return mark_visit_256(mark_ctx, value.fun);
}
/* mark-visit<fun-act0<fut<int32>>> (generated) (generated) */
struct void_ mark_visit_256(struct mark_ctx* mark_ctx, struct fun_act0_1 value) {
	struct fun_act0_1 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct add_first_task__lambda0* value0 = _0.as0;
			
			return mark_visit_259(mark_ctx, value0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<add-first-task.lambda0> (generated) (generated) */
struct void_ mark_visit_257(struct mark_ctx* mark_ctx, struct add_first_task__lambda0 value) {
	return mark_arr_258(mark_ctx, value.all_args);
}
/* mark-arr<raw-ptr(char)> (generated) (generated) */
struct void_ mark_arr_258(struct mark_ctx* mark_ctx, struct arr_4 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(char*)));
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(add-first-task.lambda0)> (generated) (generated) */
struct void_ mark_visit_259(struct mark_ctx* mark_ctx, struct add_first_task__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct add_first_task__lambda0));
	if (_0) {
		return mark_visit_257(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(then2<int32>.lambda0)> (generated) (generated) */
struct void_ mark_visit_260(struct mark_ctx* mark_ctx, struct then2__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct then2__lambda0));
	if (_0) {
		return mark_visit_254(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<fut<int32>> (generated) (generated) */
struct void_ mark_visit_261(struct mark_ctx* mark_ctx, struct fut_0 value) {
	return mark_visit_262(mark_ctx, value.state);
}
/* mark-visit<fut-state<int32>> (generated) (generated) */
struct void_ mark_visit_262(struct mark_ctx* mark_ctx, struct fut_state_0 value) {
	struct fut_state_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct fut_state_callbacks_0 value0 = _0.as0;
			
			return mark_visit_263(mark_ctx, value0);
		}
		case 1: {
			return (struct void_) {};
		}
		case 2: {
			struct exception value2 = _0.as2;
			
			return mark_visit_272(mark_ctx, value2);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<fut-state-callbacks<int32>> (generated) (generated) */
struct void_ mark_visit_263(struct mark_ctx* mark_ctx, struct fut_state_callbacks_0 value) {
	return mark_visit_264(mark_ctx, value.head);
}
/* mark-visit<opt<fut-callback-node<int32>>> (generated) (generated) */
struct void_ mark_visit_264(struct mark_ctx* mark_ctx, struct opt_0 value) {
	struct opt_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			return (struct void_) {};
		}
		case 1: {
			struct some_0 value1 = _0.as1;
			
			return mark_visit_265(mark_ctx, value1);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<some<fut-callback-node<int32>>> (generated) (generated) */
struct void_ mark_visit_265(struct mark_ctx* mark_ctx, struct some_0 value) {
	return mark_visit_271(mark_ctx, value.value);
}
/* mark-visit<fut-callback-node<int32>> (generated) (generated) */
struct void_ mark_visit_266(struct mark_ctx* mark_ctx, struct fut_callback_node_0 value) {
	mark_visit_267(mark_ctx, value.cb);
	return mark_visit_264(mark_ctx, value.next_node);
}
/* mark-visit<fun-act1<void, result<int32, exception>>> (generated) (generated) */
struct void_ mark_visit_267(struct mark_ctx* mark_ctx, struct fun_act1_0 value) {
	struct fun_act1_0 _0 = value;
	switch (_0.kind) {
		case 0: {
			struct forward_to__lambda0* value0 = _0.as0;
			
			return mark_visit_270(mark_ctx, value0);
		}
		default:
			return (assert(0),(struct void_) {});
	}
}
/* mark-visit<forward-to<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_268(struct mark_ctx* mark_ctx, struct forward_to__lambda0 value) {
	return mark_visit_269(mark_ctx, value.to);
}
/* mark-visit<gc-ptr(fut<int32>)> (generated) (generated) */
struct void_ mark_visit_269(struct mark_ctx* mark_ctx, struct fut_0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct fut_0));
	if (_0) {
		return mark_visit_261(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(forward-to<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_270(struct mark_ctx* mark_ctx, struct forward_to__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct forward_to__lambda0));
	if (_0) {
		return mark_visit_268(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(fut-callback-node<int32>)> (generated) (generated) */
struct void_ mark_visit_271(struct mark_ctx* mark_ctx, struct fut_callback_node_0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct fut_callback_node_0));
	if (_0) {
		return mark_visit_266(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<exception> (generated) (generated) */
struct void_ mark_visit_272(struct mark_ctx* mark_ctx, struct exception value) {
	return mark_arr_273(mark_ctx, value.message);
}
/* mark-arr<char> (generated) (generated) */
struct void_ mark_arr_273(struct mark_ctx* mark_ctx, struct arr_0 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(char)));
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(call-ref<?out, ?in>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_274(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct call_ref_0__lambda0__lambda0));
	if (_0) {
		return mark_visit_251(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out, ?in>.lambda0> (generated) (generated) */
struct void_ mark_visit_275(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0 value) {
	mark_visit_252(mark_ctx, value.f);
	return mark_visit_269(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(call-ref<?out, ?in>.lambda0)> (generated) (generated) */
struct void_ mark_visit_276(struct mark_ctx* mark_ctx, struct call_ref_0__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct call_ref_0__lambda0));
	if (_0) {
		return mark_visit_275(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out>.lambda0.lambda0> (generated) (generated) */
struct void_ mark_visit_277(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0 value) {
	mark_visit_255(mark_ctx, value.f);
	return mark_visit_269(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(call-ref<?out>.lambda0.lambda0)> (generated) (generated) */
struct void_ mark_visit_278(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct call_ref_1__lambda0__lambda0));
	if (_0) {
		return mark_visit_277(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<call-ref<?out>.lambda0> (generated) (generated) */
struct void_ mark_visit_279(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0 value) {
	mark_visit_255(mark_ctx, value.f);
	return mark_visit_269(mark_ctx, value.res);
}
/* mark-visit<gc-ptr(call-ref<?out>.lambda0)> (generated) (generated) */
struct void_ mark_visit_280(struct mark_ctx* mark_ctx, struct call_ref_1__lambda0* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct call_ref_1__lambda0));
	if (_0) {
		return mark_visit_279(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<gc-ptr(main.lambda0)> (generated) (generated) */
struct void_ mark_visit_281(struct mark_ctx* mark_ctx, struct main_0__lambda0* value) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct main_0__lambda0));
	
	return (struct void_) {};
}
/* mark-visit<gc-ptr(task-queue-node)> (generated) (generated) */
struct void_ mark_visit_282(struct mark_ctx* mark_ctx, struct task_queue_node* value) {
	uint8_t _0 = mark(mark_ctx, (uint8_t*) value, sizeof(struct task_queue_node));
	if (_0) {
		return mark_visit_248(mark_ctx, *value);
	} else {
		return (struct void_) {};
	}
}
/* mark-visit<mut-list<nat>> (generated) (generated) */
struct void_ mark_visit_283(struct mark_ctx* mark_ctx, struct mut_list value) {
	return mark_visit_284(mark_ctx, value.backing);
}
/* mark-visit<mut-arr<nat>> (generated) (generated) */
struct void_ mark_visit_284(struct mark_ctx* mark_ctx, struct mut_arr value) {
	return mark_arr_285(mark_ctx, value.arr);
}
/* mark-arr<nat-64> (generated) (generated) */
struct void_ mark_arr_285(struct mark_ctx* mark_ctx, struct arr_2 a) {
	uint8_t dropped0;
	dropped0 = mark(mark_ctx, (uint8_t*) a.data, (a.size * sizeof(uint64_t)));
	
	return (struct void_) {};
}
/* clear-free-mem void(mark-ptr ptr<bool>, mark-end ptr<bool>, data-ptr ptr<nat>) */
struct void_ clear_free_mem(uint8_t* mark_ptr, uint8_t* mark_end, uint64_t* data_ptr) {
	top:;
	uint8_t _0 = !(mark_ptr == mark_end);
	if (_0) {
		uint8_t _1 = !*mark_ptr;
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
struct void_ wait_on(struct condition* cond, struct opt_5 until_time, uint64_t last_checked) {
	top:;
	uint8_t _0 = _op_equal_equal_0(cond->value, last_checked);
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
uint8_t before_time__q(struct opt_5 until_time) {
	struct opt_5 _0 = until_time;
	switch (_0.kind) {
		case 0: {
			return 1;
		}
		case 1: {
			struct some_5 s0 = _0.as1;
			
			uint64_t _1 = get_monotime_nsec();
			return _op_less_0(_1, s0.value);
		}
		default:
			return (assert(0),0);
	}
}
/* join-threads-recur void(i nat, n-threads nat, threads ptr<nat>) */
struct void_ join_threads_recur(uint64_t i, uint64_t n_threads, uint64_t* threads) {
	top:;
	uint8_t _0 = _op_bang_equal_1(i, n_threads);
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
	
	uint8_t _0 = _op_bang_equal_2(err1, 0);
	if (_0) {
		int32_t _1 = einval();
		uint8_t _2 = _op_equal_equal_2(err1, _1);
		if (_2) {
			todo_0();
		} else {
			int32_t _3 = esrch();
			uint8_t _4 = _op_equal_equal_2(err1, _3);
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
/* must-be-resolved<int32> result<int32, exception>(f fut<int32>) */
struct result_0 must_be_resolved(struct fut_0* f) {
	struct fut_state_0 _0 = f->state;
	switch (_0.kind) {
		case 0: {
			return hard_unreachable();
		}
		case 1: {
			struct fut_state_resolved_0 r0 = _0.as1;
			
			return (struct result_0) {0, .as0 = (struct ok_0) {r0.value}};
		}
		case 2: {
			struct exception e1 = _0.as2;
			
			return (struct result_0) {1, .as1 = (struct err) {e1}};
		}
		default:
			return (assert(0),(struct result_0) {0});
	}
}
/* hard-unreachable<result<?t, exception>> result<int32, exception>() */
struct result_0 hard_unreachable(void) {
	return (assert(0),(struct result_0) {0});
}
/* main fut<int32>(_ arr<arr<char>>) */
struct fut_0* main_0(struct ctx* ctx, struct arr_1 _p0) {
	uint32_t _0 = sdl_init_video(ctx);
	int64_t _1 = SDL_Init(_0);
	handle_sdl_error(ctx, (struct arr_0) {14, constantarr_0_17}, _1);
	struct sdl_window* window0;
	char* _2 = to_c_str(ctx, (struct arr_0) {12, constantarr_0_19});
	uint32_t _3 = sdl_window_shown(ctx);
	window0 = SDL_CreateWindow(_2, 100, 100, 640, 480, _3);
	
	uint8_t _4 = null__q_0((uint8_t*) window0);
	if (_4) {
		fail_sdl_error(ctx, (struct arr_0) {17, constantarr_0_20});
	} else {
		(struct void_) {};
	}
	struct sdl_renderer* renderer1;
	renderer1 = new_renderer(ctx, window0);
	
	struct sdl_texture* texture2;
	texture2 = create_texture(ctx, renderer1);
	
	struct main_0__lambda0* temp0;
	uint8_t* _5 = alloc(ctx, sizeof(struct main_0__lambda0));
	temp0 = (struct main_0__lambda0*) _5;
	
	*temp0 = (struct main_0__lambda0) {renderer1, texture2};
	repeat(ctx, 20u, (struct fun_act0_0) {4, .as4 = temp0});
	(SDL_DestroyTexture(texture2), (struct void_) {});
	(SDL_DestroyRenderer(renderer1), (struct void_) {});
	(SDL_DestroyWindow(window0), (struct void_) {});
	(SDL_Quit(), (struct void_) {});
	print((struct arr_0) {7, constantarr_0_30});
	return resolved_1(ctx, 0);
}
/* handle-sdl-error void(operation arr<char>, err int) */
struct void_ handle_sdl_error(struct ctx* ctx, struct arr_0 operation, int64_t err) {
	uint8_t _0 = _op_bang_equal_0(err, 0);
	if (_0) {
		return fail_sdl_error(ctx, operation);
	} else {
		return (struct void_) {};
	}
}
/* fail-sdl-error void(operation arr<char>) */
struct void_ fail_sdl_error(struct ctx* ctx, struct arr_0 operation) {
	struct arr_0 _0 = _op_plus_0(ctx, (struct arr_0) {13, constantarr_0_15}, operation);
	struct arr_0 _1 = _op_plus_0(ctx, _0, (struct arr_0) {1, constantarr_0_16});
	char* _2 = SDL_GetError();
	struct arr_0 _3 = to_str_1(_2);
	struct arr_0 _4 = _op_plus_0(ctx, _1, _3);
	fail(ctx, _4);
	return (SDL_Quit(), (struct void_) {});
}
/* sdl-init-video nat32() */
uint32_t sdl_init_video(struct ctx* ctx) {
	return bit_shift_left(1u, 5u);
}
/* bit-shift-left nat32(a nat32, b nat32) */
uint32_t bit_shift_left(uint32_t a, uint32_t b) {
	uint8_t _0 = _op_less_1(b, 32u);
	if (_0) {
		return (uint32_t) ((uint64_t) a << (uint64_t) b);
	} else {
		return 0u;
	}
}
/* <<nat32> bool(a nat32, b nat32) */
uint8_t _op_less_1(uint32_t a, uint32_t b) {
	struct comparison _0 = compare_309(a, b);
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
			return (assert(0),0);
	}
}
/* compare<nat-32> (generated) (generated) */
struct comparison compare_309(uint32_t a, uint32_t b) {
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
/* to-c-str ptr<char>(a arr<char>) */
char* to_c_str(struct ctx* ctx, struct arr_0 a) {
	struct arr_0 _0 = _op_plus_0(ctx, a, (struct arr_0) {1, constantarr_0_18});
	return _0.data;
}
/* sdl-window-shown nat32() */
uint32_t sdl_window_shown(struct ctx* ctx) {
	return 4u;
}
/* new-renderer sdl-renderer(window sdl-window) */
struct sdl_renderer* new_renderer(struct ctx* ctx, struct sdl_window* window) {
	struct sdl_renderer* renderer0;
	uint32_t _0 = sdl_renderer_accelerated(ctx);
	uint32_t _1 = sdl_renderer_present_vsync(ctx);
	renderer0 = SDL_CreateRenderer(window, -1, (_0 | _1));
	
	uint8_t _2 = null__q_0((uint8_t*) renderer0);
	if (_2) {
		fail_sdl_error(ctx, (struct arr_0) {19, constantarr_0_21});
	} else {
		(struct void_) {};
	}
	return renderer0;
}
/* sdl-renderer-accelerated nat32() */
uint32_t sdl_renderer_accelerated(struct ctx* ctx) {
	return 2u;
}
/* sdl-renderer-present-vsync nat32() */
uint32_t sdl_renderer_present_vsync(struct ctx* ctx) {
	return 4u;
}
/* create-texture sdl-texture(renderer sdl-renderer) */
struct sdl_texture* create_texture(struct ctx* ctx, struct sdl_renderer* renderer) {
	struct sdl_surface* bmp0;
	bmp0 = sdl_load_bmp(ctx, (struct arr_0) {14, constantarr_0_22});
	
	uint8_t _0 = null__q_0((uint8_t*) bmp0);
	if (_0) {
		fail_sdl_error(ctx, (struct arr_0) {17, constantarr_0_24});
	} else {
		(struct void_) {};
	}
	struct sdl_texture* texture1;
	texture1 = SDL_CreateTextureFromSurface(renderer, bmp0);
	
	(SDL_FreeSurface(bmp0), (struct void_) {});
	uint8_t _1 = null__q_0((uint8_t*) texture1);
	if (_1) {
		fail_sdl_error(ctx, (struct arr_0) {31, constantarr_0_25});
	} else {
		(struct void_) {};
	}
	return texture1;
}
/* sdl-load-bmp sdl-surface(file arr<char>) */
struct sdl_surface* sdl_load_bmp(struct ctx* ctx, struct arr_0 file) {
	char* _0 = to_c_str(ctx, file);
	char* _1 = to_c_str(ctx, (struct arr_0) {2, constantarr_0_23});
	struct sdl_rwops* _2 = SDL_RWFromFile(_0, _1);
	return SDL_LoadBMP_RW(_2, 1);
}
/* repeat void(times nat, action fun-act0<void>) */
struct void_ repeat(struct ctx* ctx, uint64_t times, struct fun_act0_0 action) {
	top:;
	uint8_t _0 = _op_bang_equal_1(times, 0u);
	if (_0) {
		call_2(ctx, action);
		uint64_t _1 = decr(ctx, times);
		times = _1;
		action = action;
		goto top;
	} else {
		return (struct void_) {};
	}
}
/* decr nat(a nat) */
uint64_t decr(struct ctx* ctx, uint64_t a) {
	uint8_t _0 = _op_equal_equal_0(a, 0u);
	forbid_0(ctx, _0);
	return wrap_decr(a);
}
/* wrap-decr nat(a nat) */
uint64_t wrap_decr(uint64_t a) {
	return (a - 1u);
}
/* main-loop void(renderer sdl-renderer, texture sdl-texture) */
struct void_ main_loop(struct ctx* ctx, struct sdl_renderer* renderer, struct sdl_texture* texture) {
	(SDL_PumpEvents(), (struct void_) {});
	uint8_t* key_states_ptr0;
	key_states_ptr0 = SDL_GetKeyboardState(NULL);
	
	struct arr_5 key_states1;
	uint64_t _0 = sdl_num_scancodes(ctx);
	key_states1 = ptr_as_arr(ctx, _0, key_states_ptr0);
	
	uint64_t _1 = sdl_scancode_return(ctx);
	uint8_t _2 = at_2(ctx, key_states1, _1);
	uint8_t _3 = _op_equal_equal_4(_2, 0u);struct arr_0 _4;
	
	if (_3) {
		_4 = (struct arr_0) {9, constantarr_0_26};
	} else {
		_4 = (struct arr_0) {17, constantarr_0_27};
	}
	print(_4);
	int64_t _5 = SDL_RenderClear(renderer);
	handle_sdl_error(ctx, (struct arr_0) {16, constantarr_0_28}, _5);
	int64_t _6 = SDL_RenderCopy(renderer, texture, NULL, NULL);
	handle_sdl_error(ctx, (struct arr_0) {15, constantarr_0_29}, _6);
	(SDL_RenderPresent(renderer), (struct void_) {});
	return sleep_ms_sync(100u);
}
/* ptr-as-arr<nat8> arr<nat8>(size nat, data ptr<nat8>) */
struct arr_5 ptr_as_arr(struct ctx* ctx, uint64_t size, uint8_t* data) {
	return (struct arr_5) {size, data};
}
/* sdl-num-scancodes nat() */
uint64_t sdl_num_scancodes(struct ctx* ctx) {
	return 512u;
}
/* ==<nat8> bool(a nat8, b nat8) */
uint8_t _op_equal_equal_4(uint8_t a, uint8_t b) {
	struct comparison _0 = compare_332(a, b);
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
			return (assert(0),0);
	}
}
/* compare<nat-8> (generated) (generated) */
struct comparison compare_332(uint8_t a, uint8_t b) {
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
/* at<nat8> nat8(a arr<nat8>, index nat) */
uint8_t at_2(struct ctx* ctx, struct arr_5 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	assert_0(ctx, _0);
	return noctx_at_4(a, index);
}
/* noctx-at<?t> nat8(a arr<nat8>, index nat) */
uint8_t noctx_at_4(struct arr_5 a, uint64_t index) {
	uint8_t _0 = _op_less_0(index, a.size);
	hard_assert(_0);
	return *(a.data + index);
}
/* sdl-scancode-return nat() */
uint64_t sdl_scancode_return(struct ctx* ctx) {
	return 40u;
}
/* sleep-ms-sync void(ms nat) */
struct void_ sleep_ms_sync(uint64_t ms) {
	return (usleep((ms * 1000u)), (struct void_) {});
}
/* main.lambda0 void() */
struct void_ main_0__lambda0(struct ctx* ctx, struct main_0__lambda0* _closure) {
	return main_loop(ctx, _closure->renderer, _closure->texture);
}
/* resolved<int32> fut<int32>(value int32) */
struct fut_0* resolved_1(struct ctx* ctx, int32_t value) {
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
