/*
 * Copyright 2014 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "bson-glib.h"

GType
bson_get_type (void)
{
   static gsize initialized;
   static GType type_id;

   if (g_once_init_enter (&initialized)) {
      type_id = g_boxed_type_register_static ("bson_t",
                                              (GBoxedCopyFunc)bson_copy,
                                              (GBoxedFreeFunc)bson_free);
      g_once_init_leave (&initialized, TRUE);
   }

   return type_id;
}
